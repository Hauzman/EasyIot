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
  /* if (autoUpdateRequested())
   {
  #ifdef DEBUG_ONOFRE
     Log.notice("%s Starting auto update make sure if this device is connected to the internet.", tags::system);
  #endif
     WiFiClient client;
     t_httpUpdate_return ret = ESPhttpUpdate.update(client, constantsConfig::updateURL, String(VERSION));
     switch (ret)
     {
     case HTTP_UPDATE_FAILED:
  #ifdef DEBUG_ONOFRE
       Log.notice("HTTP_UPDATE_FAILD Error (%d): %s\n", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str());
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
  */
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
  pinMode(1, INPUT);
  pinMode(3, INPUT);
  LittleFS.begin();
  if (digitalRead(1) && !digitalRead(3))
  {
    LittleFS.format();
    ESP.restart();
  }
#ifdef DEBUG_ONOFRE
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_VERBOSE, &Serial);
#endif

  load(getAtualConfig());
  load(getAtualSwitchesConfig());
  load(getAtualSensorsConfig());
  setupWiFi();
  setupMQTT();
  // TODOknx.physical_address_set(knx.PA_to_address(getAtualConfig().knxArea, getAtualConfig().knxLine, getAtualConfig().knxMember));
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
  // TDOD knx.loop();
}
