#include "Sensors.h"
#include "HomeAssistantMqttDiscovery.h"
#include <ArduinoLog.h>
#include "WebServer.h"
#include "ConfigOnofre.h"
#include "Mqtt.h"
#include "CoreWiFi.h"
#include <DallasTemperature.h>
#include <dht_nonblocking.h>
#include <PZEM004T.h>
#include <PZEM004Tv30.h>
#include "CloudIO.h"
#include <DallasTemperature.h>
#include <dht_nonblocking.h>

extern ConfigOnofre config;

void Sensors::load(File &file)
{
  auto n_items = items.size();
  file.read((uint8_t *)&n_items, sizeof(n_items));
  items.clear();
  items.resize(n_items);
  for (auto &item : items)
  {
    item.load(file);
    switch (item.type)
    {
    case UNDEFINED:
#ifdef DEBUG_ONOFRE
      Log.errorln("%s Invalid type", tags::sensors);
#endif
      continue;
      break;
    case LDR:
      strlcpy(item.deviceClass, "LIGHTNESS", sizeof(item.deviceClass));
      break;
    case PIR:
    case RCWL_0516:
      strlcpy(item.deviceClass, "MOTION", sizeof(item.deviceClass));
      configPIN(item.primaryGpio, INPUT);
      break;
    case REED_SWITCH_NC:
    case REED_SWITCH_NO:
      strlcpy(item.deviceClass, "ALARM", sizeof(item.deviceClass));
      configPIN(item.primaryGpio, INPUT_PULLUP);
      break;
    case DHT_11:
    case DHT_21:
    case DHT_22:
      strlcpy(item.deviceClass, "TEMPERATURE", sizeof(item.deviceClass));
      item.dht = new DHT_nonblocking(item.primaryGpio, item.type);
      break;
    case DS18B20:
      strlcpy(item.deviceClass, "TEMPERATURE", sizeof(item.deviceClass));
      item.dallas = new DallasTemperature(new OneWire(item.primaryGpio));
      break;

    case PZEM_004T:
    {
      strlcpy(item.deviceClass, "POWER", sizeof(item.deviceClass));
#if defined(ESP8266)
      item.pzem = new PZEM004T(item.primaryGpio, item.secondaryGpio);
#endif
#if defined(ESP32)
      item.pzem = new PZEM004T(&Serial2, item.primaryGpio, item.secondaryGpio);
#endif
      IPAddress ip(192, 168, 1, item.secondaryGpio);
      item.pzem->setAddress(ip);
      configPIN(item.tertiaryGpio, INPUT);
    }
    break;
    case PZEM_004T_V03:
    {
      strlcpy(item.deviceClass, "POWER", sizeof(item.deviceClass));

#if defined(ESP8266)
      SoftwareSerial softwareSerial = SoftwareSerial(item.primaryGpio, item.secondaryGpio);
      item.pzemv03 = new PZEM004Tv30(softwareSerial);
#endif
#if defined(ESP32)
      item.pzemv03 = new PZEM004Tv30(Serial2, item.primaryGpio, item.secondaryGpio);
#endif
      configPIN(item.tertiaryGpio, INPUT);
    }
#if WITH_DISPLAY
      setupDisplay();
#endif
      break;
    }
  }
}
void Sensors::save(File &file) const
{
  auto n_items = items.size();
  file.write((uint8_t *)&n_items, sizeof(n_items));
  for (const auto &item : items)
  {
    item.save(file);
  }
}
void SensorT::load(File &file)
{
}
void SensorT::save(File &file) const
{
}

void Sensors::save()
{
}
void load(Sensors &sensors)
{
}

void saveAndRefreshServices(Sensors &sensors, SensorT &ss)
{

  sensors.save();
  if (ss.haSupport)
  {
    addToHomeAssistant(ss);
  }
}
Sensors &Sensors::updateFromJson(const String &id, JsonObject doc)
{

  SensorT newSs;
  newSs.updateFromJson(doc);
  items.push_back(newSs);
  saveAndRefreshServices(*this, newSs);
  return *this;
}
void Sensors::toJson(JsonVariant &root)
{
  for (const auto &ss : items)
  {
    JsonVariant sdoc = root.createNestedObject();
    sdoc["id"] = ss.id;
    sdoc["name"] = ss.name;
    sdoc["family"] = ss.family;
    sdoc["type"] = static_cast<int>(ss.type);
    sdoc["deviceClass"] = ss.deviceClass;
    sdoc["primaryGpio"] = ss.primaryGpio;
    sdoc["secondaryGpio"] = ss.secondaryGpio;
    sdoc["tertiaryGpio"] = ss.tertiaryGpio;
    sdoc["pullup"] = ss.pullup;
    sdoc["delayRead"] = ss.delayRead;
    sdoc["lastBinaryState"] = ss.lastBinaryState;
    sdoc["haSupport"] = ss.haSupport;
    sdoc["cloudIOSupport"] = ss.cloudIOSupport;
  }
}
Sensors &Sensors::remove(int id)
{
  auto match = std::find_if(items.begin(), items.end(), [id](const SensorT &item)
                            { return id == item.id; });

  if (match == items.end())
  {
    return *this;
  }
  removeFromHomeAssistant(*match);
  items.erase(match);
  save();
  return *this;
}
void reloadSensors()
{
  getAtualSensorsConfig().save();
}
void initSensorsHaDiscovery(Sensors &sensors)
{
  for (auto &ss : sensors.items)
  {
    addToHomeAssistant(ss);
    publishOnMqtt(ss.readTopic, ss.mqttPayload, ss.mqttRetain);
  }
}
void SensorT::updateFromJson(JsonObject doc)
{
  removeFromHomeAssistant(*this);
#ifdef DEBUG_ONOFRE
  Log.notice("%s Update Environment" CR, tags::sensors);
#endif
  type = static_cast<SensorType>(doc["type"] | static_cast<int>(UNDEFINED));
  String idStr;
  strlcpy(name, doc["name"], sizeof(name));
  id = config.nextId();
  String classDevice = doc["deviceClass"] | String(constantsSensor::powerMeterClass);
  strlcpy(deviceClass, classDevice.c_str(), sizeof(deviceClass));
  dht = NULL;
  dallas = NULL;
  primaryGpio = doc["primaryGpio"] | constantsConfig::noGPIO;
  secondaryGpio = doc["secondaryGpio"] | constantsConfig::noGPIO;
  tertiaryGpio = doc["tertiaryGpio"] | constantsConfig::noGPIO;
  delayRead = doc["delayRead"] | 0;
  mqttRetain = doc["mqttRetain"] | true;
  cloudIOSupport = doc["cloudIOSupport"] | true;
  haSupport = doc["haSupport"] | true;
  strlcpy(payloadOn, doc["payloadOn"] | "ON", sizeof(payloadOn));
  strlcpy(payloadOff, doc["payloadOff"] | "OFF", sizeof(payloadOff));
  strlcpy(mqttPayload, "", sizeof(mqttPayload));
  switch (type)
  {
  case UNDEFINED:
#ifdef DEBUG_ONOFRE
    Log.error("%s Invalid type" CR, tags::sensors);
#endif
    return;
    break;
  case LDR:
    strlcpy(deviceClass, "LIGHTNESS", sizeof(deviceClass));
    strlcpy(family, constantsSensor::familySensor, sizeof(family));
    strlcpy(mqttPayload, "{\"illuminance\":0}", sizeof(mqttPayload));
    break;
  case PIR:
  case RCWL_0516:
    strlcpy(deviceClass, "MOTION", sizeof(deviceClass));
    configPIN(primaryGpio, INPUT);
    strlcpy(family, constantsSensor::binarySensorFamily, sizeof(family));
    strlcpy(mqttPayload, "{\"binary_state\":false}", sizeof(mqttPayload));
    break;
  case REED_SWITCH_NC:
    strlcpy(deviceClass, "ALARM", sizeof(deviceClass));
    configPIN(primaryGpio, INPUT_PULLUP);
    strlcpy(family, constantsSensor::binarySensorFamily, sizeof(family));
    strlcpy(mqttPayload, "{\"binary_state\":1}", sizeof(mqttPayload));
    break;
  case REED_SWITCH_NO:
    strlcpy(deviceClass, "ALARM", sizeof(deviceClass));
    configPIN(primaryGpio, INPUT_PULLUP);
    strlcpy(family, constantsSensor::binarySensorFamily, sizeof(family));
    strlcpy(mqttPayload, "{\"binary_state\":0}", sizeof(mqttPayload));
    break;
  case DHT_11:
  case DHT_21:
  case DHT_22:
    strlcpy(deviceClass, "TEMPERATURE", sizeof(deviceClass));
    dht = new DHT_nonblocking(primaryGpio, type);
    strlcpy(family, constantsSensor::familySensor, sizeof(family));
    strlcpy(mqttPayload, "{\"humidity\":0,\"temperature\":0}", sizeof(mqttPayload));
    break;
  case DS18B20:
    strlcpy(deviceClass, "TEMPERATURE", sizeof(deviceClass));
    dallas = new DallasTemperature(new OneWire(primaryGpio));
    strlcpy(family, constantsSensor::familySensor, sizeof(family));
    break;
  case PZEM_004T:
    strlcpy(deviceClass, "POWER", sizeof(deviceClass));
#ifdef ESP8266
    pzem = new PZEM004T(primaryGpio, secondaryGpio);
#endif
#ifdef ESP32
    pzem = new PZEM004T(&Serial2, primaryGpio, secondaryGpio);
#endif
    strlcpy(family, constantsSensor::familySensor, sizeof(family));
    break;
  case PZEM_004T_V03:
  {
    strlcpy(deviceClass, "POWER", sizeof(deviceClass));
#if defined(ESP8266)
    SoftwareSerial softwareSerial = SoftwareSerial(primaryGpio, secondaryGpio);
    pzemv03 = new PZEM004Tv30(softwareSerial);
#endif
#if defined(ESP32)

    pzemv03 = new PZEM004Tv30(Serial2, primaryGpio, secondaryGpio);
#endif
    strlcpy(family, constantsSensor::familySensor, sizeof(family));
  }
  break;
  }
  doc["id"] = id;
}

void publishReadings(String &readings, SensorT &sensor)
{

  strlcpy(sensor.lastReading, readings.c_str(), sizeof(sensor.lastReading));
  String id = String(sensor.id);
  sendToServerEvents(id, readings.c_str());
  if (sensor.cloudIOSupport)
    notifyStateToCloudIO(sensor.mqttCloudStateTopic, readings.c_str());
  if (mqttConnected())
  {
    publishOnMqtt(sensor.readTopic, readings.c_str(), sensor.mqttRetain);
  }
}

void resetSensors(Sensors &sensors)
{
  for (auto &ss : sensors.items)
  {
    if (ss.pzemv03 != NULL)
    {
      ss.pzemv03->resetEnergy();
      Log.notice("%s {\"pzemv03\": %d}" CR, tags::sensors, ss.id);
    }
    else
    {
      Log.notice("%s {\"pzemv03\": null}" CR, tags::sensors);
    }
  }
}
bool initRealTimeSensors = true;
void loop(Sensors &sensors)
{

  for (auto &ss : sensors.items)
  {

    if (ss.primaryGpio == constantsConfig::noGPIO)
      continue;
    switch (ss.type)
    {
    case UNDEFINED:
      continue;
      break;
    case LDR:
    {
      if (ss.lastRead + ss.delayRead < millis())
      {
        ss.lastRead = millis();
        int ldrRaw = analogRead(ss.primaryGpio);
        String analogReadAsString = String(ldrRaw);
        auto readings = String("{\"illuminance\":" + analogReadAsString + "}");
        publishReadings(readings, ss);
#ifdef DEBUG_ONOFRE
        Log.notice("%s {\"illuminance\": %d }" CR, tags::sensors, ldrRaw);
#endif
      }
    }
    break;

    case PIR:
    case REED_SWITCH_NC:
    case RCWL_0516:
    {
      bool binaryState = readPIN(ss.primaryGpio);
      if (ss.lastBinaryState != binaryState || initRealTimeSensors)
      {
        ss.lastRead = millis();
        ss.lastBinaryState = binaryState;
        String binaryStateAsString = String(binaryState);
        auto readings = String("{\"binary_state\":" + (binaryStateAsString) + "}");
        publishReadings(readings, ss);
#ifdef DEBUG_ONOFRE
        Log.notice("%s %s" CR, tags::sensors, readings.c_str());
#endif
      }
    }
    break;
    case REED_SWITCH_NO:
    {
      bool binaryState = !readPIN(ss.primaryGpio);
      if (ss.lastBinaryState != binaryState || initRealTimeSensors)
      {
        ss.lastRead = millis();
        ss.lastBinaryState = binaryState;
        String binaryStateAsString = String(binaryState);
        auto readings = String("{\"binary_state\":" + binaryStateAsString + "}");
        publishReadings(readings, ss);
#ifdef DEBUG_ONOFRE
        Log.notice("%s %s" CR, tags::sensors, readings.c_str());
#endif
      }
    }
    break;

    case DHT_11:
    case DHT_21:
    case DHT_22:
    {

      if (ss.dht->measure(&ss.temperature, &ss.humidity) == true)
      {
        if (ss.lastRead + ss.delayRead < millis())
        {
          ss.lastRead = millis();
          String temperatureAsString = String(ss.temperature);
          String humidityAsString = String(ss.humidity);
          auto readings = String("{\"temperature\":" + temperatureAsString + ",\"humidity\":" + humidityAsString + "}");
          publishReadings(readings, ss);
#ifdef DEBUG_ONOFRE
          Log.notice("%s {\"temperature\": %F ,\"humidity\": %F}" CR, tags::sensors, ss.temperature, ss.humidity);
#endif
        }
      }
    }
    break;
    case DS18B20:
    {

      if (ss.lastRead + ss.delayRead < millis())
      {
        ss.dallas->begin();
        ss.oneWireSensorsCount = ss.dallas->getDeviceCount();
        for (int i = 0; i < ss.oneWireSensorsCount; i++)
        {
          StaticJsonDocument<256> doc;
          JsonObject obj = doc.to<JsonObject>();
          ss.dallas->requestTemperatures();
          ss.lastRead = millis();
          ss.temperature = ss.dallas->getTempCByIndex(i);
          String temperatureAsString = String("temperature_") + String(i + 1);
          obj[temperatureAsString] = ss.temperature;
          String readings = "";
          serializeJson(doc, readings);
          publishReadings(readings, ss);
#ifdef DEBUG_ONOFRE
          Log.notice("%s %s " CR, tags::sensors, readings.c_str());
#endif
        }
      }
    }

    case PZEM_004T:
      if (ss.lastRead + ss.delayRead < millis())
      {
        IPAddress ip(192, 168, 1, ss.secondaryGpio);
        ss.lastRead = millis();
        float v = ss.pzem->voltage(ip);

        float i = ss.pzem->current(ip);

        float p = ss.pzem->power(ip);

        float c = ss.pzem->energy(ip);

        if (ss.tertiaryGpio != constantsConfig::noGPIO)
        {
          if (digitalRead(ss.tertiaryGpio))
          {
            p = p * -1;
          }
        }

        if (v < 0.0)
        {
#ifdef DEBUG_ONOFRE
          Log.notice("%s PZEM ERROR" CR, tags::sensors);
#endif
        }
        else
        {
          auto readings = String("{\"voltage\":" + String(v) + ",\"current\":" + String(i) + ",\"power\":" + String(p) + ",\"energy\":" + String(c) + "}");
#if WITH_DISPLAY
          printOnDisplay(v, i, p, c);
#endif
          publishReadings(readings, ss);
#ifdef DEBUG_ONOFRE
          Log.notice("%s {\"voltage\": %F,\"current\": %F,\"power\": %F \"energy\": %F }" CR, tags::sensors, v, i, p, c);
#endif
        }
      }
      break;
    case PZEM_004T_V03:
      if (ss.lastRead + ss.delayRead < millis())
      {
        time_t rawtime;
        struct tm *timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        char buffer[80];
        strftime(buffer, 80, "%Y%m%d", timeinfo);
        File file = LittleFS.open("/lastday.log", "r");
        String lastDate = "";
        if (file.available())
        {
          lastDate = file.readString();
          file.close();
        }
        if (lastDate.compareTo(String(buffer)) != 0)
        {
          if (ss.pzemv03->resetEnergy())
          {
            file = LittleFS.open("/lastday.log", "w");
            file.print(buffer);
            file.close();
            continue;
          }
        }

        ss.lastRead = millis();
        float v = ss.pzemv03->voltage();
        float i = ss.pzemv03->current();
        float p = ss.pzemv03->power();
        float c = ss.pzemv03->energy();
        float f = ss.pzemv03->frequency();
        float pf = ss.pzemv03->pf();
        if (ss.tertiaryGpio != constantsConfig::noGPIO)
        {
          if (digitalRead(ss.tertiaryGpio))
          {
            p = p * -1;
          }
        }

        if (isnan(v))
        {
#ifdef DEBUG_ONOFRE
          Log.notice("%s PZEM ERROR" CR, tags::sensors);
#endif
        }
        else
        {
          auto readings = String("{\"lastreset\":" + String(buffer) + ",\"voltage\":" + String(v) + ",\"frequency\":" + String(f) + ",\"pf\":" + String(pf) + ",\"current\":" + String(i) + ",\"power\":" + String(p) + ",\"energy\":" + String(c) + "}");
#if WITH_DISPLAY
          printOnDisplay(v, i, p, c);
#endif
          publishReadings(readings, ss);
#ifdef DEBUG_ONOFRE
          Log.notice("%s %s" CR, tags::sensors, readings.c_str());
#endif
        }
      }
      break;
    }
  }
  initRealTimeSensors = false;
}
