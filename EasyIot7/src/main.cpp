#include <Arduino.h>
#include "Config.h"
#include "WebServer.h"
#include "CoreWiFi.h"
#include "Mqtt.h"
#include "Switches.h"
#include "Sensors.h"
#ifdef ESP8266
#include <ESP8266httpUpdate.h>
#include <ESP8266mDNS.h>
#include <esp-knx-ip.h>
#endif
#ifdef ESP32
#include <HTTPClient.h>
#include <HTTPUpdate.h>
#endif
#include "constants.h"
#include "WebRequests.h"
#include "CloudIO.h"

void checkInternalRoutines()
{
  if (cloudIOSync())
  {
    connectoToCloudIO();
  }
  if (wifiScanRequested())
  {
    scanNewWifiNetworks();
  }
  if (restartRequested())
  {
#ifdef DEBUG_ONOFRE

    Log.notice("%s Rebooting...", tags::system);
#endif
    ESP.restart();
  }
  if (loadDefaultsRequested())
  {
#ifdef DEBUG_ONOFRE
    Log.notice("%s Loading defaults...", tags::system);
#endif
    LittleFS.format();
    requestRestart();
  }
  if (autoUpdateRequested())
  {
#ifdef DEBUG_ONOFRE
    Log.notice("%s Starting auto update make sure if this device is connected to the internet.", tags::system);
#endif
    WiFiClient client;
    t_httpUpdate_return ret;
#ifdef ESP8266
    ret = ESPhttpUpdate.update(client, constantsConfig::updateURL, String(VERSION));
#endif
#ifdef ESP32
    ret = httpUpdate.update(client, constantsConfig::updateURL, String(VERSION));
#endif
    switch (ret)
    {
    case HTTP_UPDATE_FAILED:
#ifdef DEBUG_ONOFRE
#ifdef ESP8266
      Log.notice("HTTP_UPDATE_FAILD Error (%d): %s\n", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str());
#endif
#ifdef ESP32
      Log.notice("HTTP_UPDATE_FAILD Error (%d): %s\n", httpUpdate.getLastError(), httpUpdate.getLastErrorString().c_str());
#endif
#endif
      break;
    case HTTP_UPDATE_NO_UPDATES:
#ifdef DEBUG_ONOFRE
      Log.notice("HTTP_UPDATE_NO_UPDATES");
#endif
      break;
    case HTTP_UPDATE_OK:
#ifdef DEBUG_ONOFRE
      Log.notice("HTTP_UPDATE_OK");
#endif
      break;
    }
  }

  if (reloadWifiRequested())
  {
#ifdef DEBUG_ONOFRE
    Log.notice("%s Loading wifi configuration...", tags::system);
#endif
    reloadWiFiConfig();
  }
}

void setup()
{
  LittleFS.begin();
#ifdef DEBUG_ONOFRE
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_VERBOSE, &Serial);
#endif

  load(getAtualConfig());
  load(getAtualSwitchesConfig());
  load(getAtualSensorsConfig());
  setupWiFi();
  setupMQTT();
#ifdef ESP8266
  knx.physical_address_set(knx.PA_to_address(getAtualConfig().knxArea, getAtualConfig().knxLine, getAtualConfig().knxMember));
#endif
  setupWebserverAsync();
}

void loop()
{
  checkInternalRoutines();
  webserverServicesLoop();
  loopWiFi();
  loopMqtt();
  if (!autoUpdateRequested())
  {
    loop(getAtualSwitchesConfig());
    loop(getAtualSensorsConfig());
    loopTime();
  }
#ifdef ESP8266
  knx.loop();
#endif
}
