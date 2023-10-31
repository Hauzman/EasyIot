#include "ConfigOnofre.h"
#include "CoreWiFi.h"
#include "Mqtt.h"
#include <esp-knx-ip.h>
#include "WebServer.h"
#include "Templates.h"
#include "LittleFS.h"
#include "Wire.h"
#include "Images.hpp"

void ConfigOnofre::generateId(String &id, const String &name, int familyCode, size_t maxSize)
{
  id.reserve(maxSize);
  id.concat(chipId);
  id.concat(name);
  id.concat(familyCode);
  id.toLowerCase();
  normalize(id);
}
ConfigOnofre &ConfigOnofre::init()
{
#ifdef ESP8266
  strlcpy(chipId, String(ESP.getChipId()).c_str(), sizeof(chipId));
#endif
#ifdef ESP32
  uint32_t chipIdHex = 0;
  for (int i = 0; i < 17; i = i + 8)
  {
    chipIdHex |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
  }
  strlcpy(chipId, String(chipIdHex).c_str(), sizeof(chipId));
#endif
  strlcpy(nodeId, chipId, sizeof(nodeId));
  mqttPort = constantsMqtt::defaultPort;
  dhcp = true;
  strlcpy(accessPointPassword, constantsConfig::apSecret, sizeof(accessPointPassword));
  strlcpy(apiUser, constantsConfig::apiUser, sizeof(apiUser));
  strlcpy(apiPassword, constantsConfig::apiPassword, sizeof(apiPassword));
#ifdef WIFI_SSID
  strlcpy(wifiSSID, WIFI_SSID, sizeof(wifiSSID));
#endif
#ifdef WIFI_SECRET
  strlcpy(wifiSecret, WIFI_SECRET, sizeof(wifiSecret));
#endif
#ifdef DEBUG_ONOFRE
  Log.notice("%s Default config loaded." CR, tags::config);
#endif
  return save();
}
bool ConfigOnofre::isSensorExists(SensorDriver driver)
{
  for (auto f : sensors)
  {
    if (f.driver == driver)
      return true;
  }
  return false;
}

void ConfigOnofre::i2cDiscovery()
{
  Wire.begin(constantsConfig::SDA, constantsConfig::SCL);
  byte error, address;
  for (address = 1; address < 127; address++)
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0)
    {
      if (address == Discovery::I2C_SHT3X_ADDRESS)
      {
        if (!isSensorExists(SensorDriver::SHT3x_SENSOR))
          templateSelect(SHT3X_CLIMATE);
      }
      if (address == Discovery::I2C_SSD1306_ADDRESS)
      {
        display = new Adafruit_SSD1306(128, 64, &Wire, -1);
        if (display->begin(SSD1306_SWITCHCAPVCC, Discovery::I2C_SSD1306_ADDRESS))
        {
          display->clearDisplay();
          display->drawBitmap(
              (display->width() - LOGO_WIDTH) / 2,
              0,
              logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
          display->setTextSize(2);
          display->setTextColor(SSD1306_WHITE);
          display->setCursor(30, LOGO_HEIGHT);
          display->println(F("ONOFRE"));
          display->display();
        }
      }
    }
  }
}
ConfigOnofre &ConfigOnofre::pauseFeatures()
{
  pauseFeaturesLoop = true;
  return *this;
}
ConfigOnofre &ConfigOnofre::load()
{

  if (!LittleFS.exists(configFilenames::config))
  {
    return init();
  }

  File file = LittleFS.open(configFilenames::config, "r+");
  StaticJsonDocument<DYNAMIC_JSON_DOCUMENT_SIZE> doc;
#ifdef DEBUG_ONOFRE
  DeserializationError error = deserializeJson(doc, file);
  if (error)
    Log.notice("%s Failed to read file, using default configuration." CR, tags::config);
#else
  deserializeJson(doc, file);
#endif

#ifdef ESP8266
  strlcpy(chipId, String(ESP.getChipId()).c_str(), sizeof(chipId));
#endif
#ifdef ESP32
  uint32_t chipIdHex = 0;
  for (int i = 0; i < 17; i = i + 8)
  {
    chipIdHex |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
  }
  templateId = doc["templateId"];
  strlcpy(chipId, String(chipIdHex).c_str(), sizeof(chipId));
#endif
  strlcpy(nodeId,
          doc["nodeId"] | chipId,
          sizeof(nodeId));
  // CLOUDIO
  strlcpy(cloudIOUsername, doc["cloudIOUsername"] | "", sizeof(cloudIOUsername));
  strlcpy(cloudIOPassword, doc["cloudIOPassword"] | "", sizeof(cloudIOPassword));
  sprintf(cloudIOhealthTopic, "%s/%s/available", cloudIOUsername, chipId);

  // MQTT
  strlcpy(mqttIpDns, doc["mqttIpDns"] | "", sizeof(mqttIpDns));
  mqttPort = doc["mqttPort"] | 1883;
  strlcpy(mqttUsername, doc["mqttUsername"] | "", sizeof(mqttUsername));
  strlcpy(mqttPassword, doc["mqttPassword"] | "", sizeof(mqttPassword));
  sprintf(healthTopic, "onofre/%s/available", chipId);

  // WIFI
  strlcpy(wifiSSID, doc["wifiSSID"] | "", sizeof(wifiSSID));
  strlcpy(wifiSecret, doc["wifiSecret"] | "", sizeof(wifiSecret));
  dhcp = doc["dhcp"] | true;
  strlcpy(wifiIp, doc["wifiIp"] | "", sizeof(wifiIp));
  strlcpy(wifiMask, doc["wifiMask"] | "", sizeof(wifiMask));
  strlcpy(wifiGw, doc["wifiGw"] | "", sizeof(wifiGw));
  // ACCESS POINT AND PANNEL ADMIN
  strlcpy(accessPointPassword, doc["accessPointPassword"] | constantsConfig::apSecret, sizeof(accessPointPassword));
  strlcpy(apiUser, doc["apiUser"] | constantsConfig::apiUser, sizeof(apiUser));
  strlcpy(apiPassword, doc["apiPassword"] | constantsConfig::apiPassword, sizeof(apiPassword));
  JsonArray features = doc["features"];
  int s = 0;
  for (auto d : features)
  {
    if (strcmp(d["group"] | "", "ACTUATOR") == 0)
    {
      Actuator actuator;
      actuator.sequence = s++;
      strlcpy(actuator.uniqueId, d["id"] | "", sizeof(actuator.uniqueId));
      strlcpy(actuator.name, d["name"] | "", sizeof(actuator.name));
      actuator.driver = d["driver"];
      actuator.typeControl = d["typeControl"];
      actuator.knxAddress[0] = d["area"] | 0;
      actuator.knxAddress[1] = d["line"] | 0;
      actuator.knxAddress[2] = d["member"] | 0;
      actuator.state = d["state"] | 0;
      String family = actuator.familyToText();
      family.toLowerCase();
      sprintf(actuator.readTopic, "onofre/%s/%s/%s/state", chipId, family, actuator.uniqueId);
      sprintf(actuator.writeTopic, "onofre/%s/%s/%s/set", chipId, family, actuator.uniqueId);
      JsonArray outputs = d["outputs"];
      for (auto out : outputs)
      {
        actuator.outputs.push_back(out);
      }
      JsonArray inputs = d["inputs"];
      for (auto in : inputs)
      {
        actuator.inputs.push_back(in);
      }
      actuator.setup();
      actuatores.push_back(actuator);
    }
    else if (strcmp(d["group"] | "", "SENSOR") == 0)
    {
      Sensor sensor;
      strlcpy(sensor.uniqueId, d["id"] | "", sizeof(sensor.uniqueId));
      strlcpy(sensor.name, d["name"] | "", sizeof(sensor.name));
      sensor.delayRead = d["delayRead"];
      sensor.driver = d["driver"];
      sprintf(sensor.readTopic, "onofre/%s/%s/%d/state", chipId, sensor.familyToText(), sensor.uniqueId);
      JsonArray inputs = d["inputs"];
      for (auto in : inputs)
      {
        sensor.inputs.push_back(in);
      }
      sensors.push_back(sensor);
    }
  }
  file.close();
#ifdef DEBUG_ONOFRE
  Log.notice("%s Stored config loaded." CR, tags::config);
#endif
  return *this;
}
void ConfigOnofre::loadTemplate(int templateId)
{
  templateSelect((Template)templateId);
  this->templateId = templateId;
}
ConfigOnofre &ConfigOnofre::save()
{
  File file = LittleFS.open(configFilenames::config, "w+");
  DynamicJsonDocument doc(DYNAMIC_JSON_DOCUMENT_SIZE);
  doc["templateId"] = templateId;
  if (!String(nodeId).isEmpty())
    doc["nodeId"] = nodeId;
  // MQTT
  if (!String(mqttIpDns).isEmpty())
    doc["mqttIpDns"] = mqttIpDns;
  doc["mqttPort"] = mqttPort;
  if (!String(mqttUsername).isEmpty())
    doc["mqttUsername"] = mqttUsername;
  if (!String(mqttPassword).isEmpty())
    doc["mqttPassword"] = mqttPassword;
  // CLOUDIO
  if (!String(cloudIOUsername).isEmpty())
    doc["cloudIOUsername"] = cloudIOUsername;
  if (!String(cloudIOPassword).isEmpty())
    doc["cloudIOPassword"] = cloudIOPassword;
  // WIFI
  if (!String(wifiSSID).isEmpty())
    doc["wifiSSID"] = wifiSSID;
  if (!String(wifiSecret).isEmpty())
    doc["wifiSecret"] = wifiSecret;
  doc["dhcp"] = dhcp | true;
  if (!String(wifiIp).isEmpty())
    doc["wifiIp"] = wifiIp;
  if (!String(wifiMask).isEmpty())
    doc["wifiMask"] = wifiMask;
  if (!String(wifiGw).isEmpty())
    doc["wifiGw"] = wifiGw;
  // ACCESS POINT AND PANNEL ADMIN
  doc["accessPointPassword"] = accessPointPassword;
  doc["apiUser"] = apiUser;
  doc["apiPassword"] = apiPassword;

  JsonArray features = doc.createNestedArray("features");
  for (auto s : actuatores)
  {
    JsonObject a = features.createNestedObject();
    a["group"] = "ACTUATOR";
    a["driver"] = s.driver;
    a["id"] = s.uniqueId;
    a["name"] = s.name;
    a["typeControl"] = s.typeControl;
    a["area"] = s.knxAddress[0];
    a["line"] = s.knxAddress[1];
    a["member"] = s.knxAddress[2];
    a["state"] = s.state;
    JsonArray outputs = a.createNestedArray("outputs");
    for (auto out : s.outputs)
    {
      outputs.add(out);
    }
    JsonArray inputs = a.createNestedArray("inputs");
    for (auto in : s.inputs)
    {
      inputs.add(in);
    }
  }
  for (auto ss : sensors)
  {
    JsonObject a = features.createNestedObject();
    a["group"] = "SENSOR";
    a["id"] = ss.uniqueId;
    a["name"] = ss.name;
    a["driver"] = ss.driver;
    a["delayRead"] = ss.delayRead;
    JsonArray inputs = a.createNestedArray("inputs");
    for (auto in : ss.inputs)
    {
      inputs.add(in);
    }
  }

  if (serializeJson(doc, file) == 0)
  {
#ifdef DEBUG_ONOFRE
    Log.notice("%s Fail to write File." CR, tags::config);
#endif
  }
  file.close();
#ifdef DEBUG_ONOFRE
  Log.notice("%s ConfigOnofre stored." CR, tags::config);
#endif
  doc.clear();
  return *this;
}
void ConfigOnofre::controlFeature(StateOrigin origin, JsonObject &action, JsonVariant &result)
{

  controlFeature(origin, action["id"] | "0", action["state"] | 0);
}
void ConfigOnofre::controlFeature(StateOrigin origin, String topic, String payload)
{
  for (auto &a : actuatores)
  {
    if (strcmp(a.writeTopic, topic.c_str()) == 0 || strcmp(a.cloudIOwriteTopic, topic.c_str()) == 0)
    {
      controlFeature(origin, a.uniqueId, payload.toInt());
      return;
    }
  }
}
void ConfigOnofre::controlFeature(StateOrigin origin, String uniqueId, int state)
{
  for (auto &a : actuatores)
  {

    if (uniqueId.equals(a.uniqueId))
    {
      if (state == ActuatorState::TOGGLE)
      {
        if (a.isLight() || a.isSwitch())
          state = a.state == ActuatorState::ON_CLOSE ? ActuatorState::OFF_OPEN : ActuatorState::ON_CLOSE;
        else if (a.isCover() || a.isGarage())
        {
          state = a.state == ActuatorState::OFF_OPEN ? ActuatorState::ON_CLOSE : ActuatorState::OFF_OPEN;
        }
      }
      a.changeState(origin, state)->state;
      this->save();
      return;
    }
  }
}

ConfigOnofre &ConfigOnofre::update(JsonObject &root)
{
  bool reloadMdns = strncmp(nodeId, root["nodeId"] | "", sizeof(nodeId)) != 0;

  char lastNodeId[32] = {};
  if (reloadMdns)
  {
    strlcpy(lastNodeId, nodeId, sizeof(lastNodeId));
  }
  bool reloadWifi = dhcp != (root["dhcp"] | true);
#ifdef DEBUG_ONOFRE
  if (reloadWifi)
    Log.notice("%sWiFi Reloaded because DHCP configuration changed." CR, tags::config);
#endif
  dhcp = root["dhcp"] | true;
  if (!dhcp && !reloadWifi)
  {
    reloadWifi = strcmp(wifiIp, root["wifiIp"] | "") != 0 || strcmp(wifiMask, root["wifiMask"] | "") != 0 || strcmp(wifiGw, root["wifiGw"] | "") != 0;
#ifdef DEBUG_ONOFRE
    if (reloadWifi)
      Log.notice("%sWiFi Reloaded because Network configuration changed." CR, tags::config);
#endif
  }
  if (!reloadWifi)
  {
    reloadWifi = strcmp(wifiSSID, root["wifiSSID"] | "") != 0 || strcmp(wifiSecret, root["wifiSecret"] | "") != 0;
#ifdef DEBUG_ONOFRE
    if (reloadWifi)
      Log.notice("%sWiFi Reloaded because SSID or Password changed." CR, tags::config);
#endif
  }

  bool reloadMqtt = strcmp(mqttIpDns, root["mqttIpDns"] | "") != 0 || strcmp(mqttUsername, root["mqttUsername"] | "") != 0 || strcmp(mqttPassword, root["mqttPassword"] | "") != 0 || mqttPort != (root["mqttPort"] | constantsMqtt::defaultPort);
  String n_name = root["nodeId"] | chipId;
  normalize(n_name);
  strlcpy(nodeId, n_name.c_str(), sizeof(nodeId));
  strlcpy(mqttIpDns, root["mqttIpDns"] | "", sizeof(mqttIpDns));
  mqttPort = root["mqttPort"] | constantsMqtt::defaultPort;
  strlcpy(mqttUsername, root["mqttUsername"] | "", sizeof(mqttUsername));
  strlcpy(mqttPassword, root["mqttPassword"] | "", sizeof(mqttPassword));
  strlcpy(wifiSSID, root["wifiSSID"] | "", sizeof(wifiSSID));
  strlcpy(wifiSecret, root["wifiSecret"] | "", sizeof(wifiSecret));
  strlcpy(wifiIp, root["wifiIp"] | "", sizeof(wifiIp));
  strlcpy(wifiMask, root["wifiMask"] | "", sizeof(wifiMask));
  strlcpy(wifiGw, root["wifiGw"] | "", sizeof(wifiGw));

  strlcpy(apiPassword, root["apiPassword"] | constantsConfig::apiPassword, sizeof(apiPassword));
  strlcpy(apiUser, root["apiUser"] | constantsConfig::apiUser, sizeof(apiUser));
  strlcpy(accessPointPassword, root["accessPointPassword"] | constantsConfig::apSecret, sizeof(accessPointPassword));

  if (reloadMdns)
    refreshMDNS(lastNodeId);
  if (reloadMqtt)
  {
    setupMQTT();
  }
  if (reloadWifi)
  {
    requestReloadWifi();
  }
  if (reloadMqtt)
  {
    setupMQTT();
  }
  JsonArray featuresToRemove = root["featuresToRemove"];
  for (String id : featuresToRemove)
  {
    auto match = std::find_if(actuatores.begin(), actuatores.end(), [id](const Actuator &item)
                              { return id.equals(item.uniqueId); });
    actuatores.erase(match);
  }
  JsonArray features = root["features"];
  for (auto feature : features)
  {
    String id = feature["id"] | "";
    for (auto &a : actuatores)
    {
      if (strcmp(a.uniqueId, id.c_str()) == 0)
      {
        strlcpy(a.name, feature["name"] | "", sizeof(a.name));
        a.driver = feature["driver"] | a.driver;
      }
    }
  }
  root.clear();
  return this->save();
}

void ConfigOnofre::json(JsonVariant &root)
{
  root["nodeId"] = nodeId;
  root["chipId"] = chipId;
  root["mqttIpDns"] = mqttIpDns;
  root["mqttPort"] = mqttPort;
  root["mqttUsername"] = mqttUsername;
  root["mqttPassword"] = mqttPassword;
  root["accessPointPassword"] = accessPointPassword;
  root["apiUser"] = apiUser;
  root["apiPassword"] = apiPassword;
  root["wifiSSID"] = wifiSSID;
  root["wifiSecret"] = wifiSecret;
  root["dhcp"] = dhcp;
  // DYNAMIC VALUES
  root["mqttConnected"] = mqttConnected();
  root["wifiIp"] = WiFi.localIP().toString();
  root["wifiMask"] = WiFi.subnetMask().toString();
  root["wifiGw"] = WiFi.gatewayIP().toString();
  root["firmware"] = String(VERSION);
  root["mac"] = WiFi.macAddress();
  root["wifiStatus"] = WiFi.isConnected();
  root["signal"] = WiFi.RSSI();
  JsonVariant outInPins = root.createNestedArray("outInPins");
  JsonVariant inPins = root.createNestedArray("inPins");
#ifdef ESP8266
  std::vector<int> outputInput = {0, 1, 2, 3, 4, 5, 12, 13, 14, 15, 16};
#endif
#ifdef ESP32
  std::vector<int> outputInput = {4, 5, 7, 8, 13, 14, 19, 20, 21, 22, 25, 26, 27, 32, 33};
  std::vector<int> intputOnly = {34, 35, 36, 37, 38};
  for (auto p : intputOnly)
  {
    inPins.add(p);
  }
#endif
  for (auto p : outputInput)
  {
    outInPins.add(p);
  }

  JsonArray features = root.createNestedArray("features");
  for (auto s : actuatores)
  {
    JsonObject a = features.createNestedObject();
    a["group"] = "ACTUATOR";
    a["id"] = s.uniqueId;
    a["name"] = s.name;
    a["driver"] = s.driverToText();
    a["family"] = s.familyToText();
    a["area"] = s.knxAddress[0];
    a["line"] = s.knxAddress[1];
    a["member"] = s.knxAddress[2];
    a["state"] = s.state;
    JsonArray outputs = a.createNestedArray("outputs");
    for (auto out : s.outputs)
    {
      outputs.add(out);
    }
    JsonArray inputs = a.createNestedArray("inputs");
    for (auto in : s.inputs)
    {
      inputs.add(in);
    }
  }
  for (auto s : sensors)
  {
    JsonObject a = features.createNestedObject();
    a["group"] = "SENSOR";
    a["id"] = s.uniqueId;
    a["name"] = s.name;
    a["family"] = s.familyToText();
    a["delayRead"] = s.delayRead;
    a["driver"] = s.driverToText();
    JsonArray inputs = a.createNestedArray("inputs");
    for (auto in : s.inputs)
    {
      inputs.add(in);
    }
  }
}

void ConfigOnofre::requestWifiScan()
{
  wifiScan = true;
}

bool ConfigOnofre::isWifiScanRequested()
{
  if (wifiScan)
  {
    wifiScan = false;
    return true;
  }
  return false;
}

void ConfigOnofre::requestCloudIOSync()
{
  cloudIOSync = true;
}

bool ConfigOnofre::isCloudIOSyncRequested()
{
  if (cloudIOSync)
  {
    cloudIOSync = false;
    return true;
  }
  return false;
}

void ConfigOnofre::requestReloadWifi()
{
  wifiReload = true;
}
bool ConfigOnofre::isReloadWifiRequested()
{
  if (wifiReload)
  {
    wifiReload = false;
    return true;
  }
  return false;
}

void ConfigOnofre::requestRestart()
{
  reboot = true;
}
bool ConfigOnofre::isRestartRequested()
{
  if (reboot)
  {
    reboot = false;
    return true;
  }
  return false;
}

void ConfigOnofre::requestAutoUpdate()
{
  autoUpdate = true;
}
bool ConfigOnofre::isAutoUpdateRequested()
{
  if (autoUpdate)
  {
    autoUpdate = false;
    return true;
  }
  return false;
}

void ConfigOnofre::requestLoadDefaults()
{
  loadDefaults = true;
}
bool ConfigOnofre::isLoadDefaultsRequested()
{
  if (loadDefaults)
  {
    loadDefaults = false;
    return true;
  }
  return false;
}
