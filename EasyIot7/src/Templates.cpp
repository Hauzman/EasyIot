#include <Arduino.h>
#include "Templates.h"
#include "Actuatores.h"
#include "Sensors.h"
#include "ConfigOnofre.h"
extern ConfigOnofre config;
void preparePzem()
{
    SensorT pzem;
    strlcpy(pzem.name, "Consumo", sizeof(pzem.name));

    strlcpy(pzem.family, constantsSensor::familySensor, sizeof(pzem.name));
    pzem.primaryGpio = constantsConfig::noGPIO;
    pzem.secondaryGpio = constantsConfig::noGPIO;
    pzem.tertiaryGpio = constantsConfig::noGPIO;
    pzem.type = PZEM_004T_V03;
    pzem.primaryGpio = 3;
    pzem.secondaryGpio = 1;
    pzem.tertiaryGpio = constantsConfig::noGPIO;
    pzem.mqttRetain = true;
    pzem.haSupport = true;
    pzem.cloudIOSupport = true;
    pzem.delayRead = 5000;
    strlcpy(pzem.deviceClass, constantsSensor::powerMeterClass, sizeof(pzem.deviceClass));
    String idStr;
    config.generateId(idStr, pzem.name, pzem.type, sizeof(pzem.uniqueId));
    strlcpy(pzem.uniqueId, idStr.c_str(), sizeof(pzem.uniqueId));
    config.sensors.push_back(pzem);
}
void prepareLight(String name, unsigned int output, unsigned int input)
{
    ActuatorT light;
    light.family = LIGHT_PUSH;
    strncpy(light.name, name.c_str(), sizeof(light.name));
    light.typeControl = SwitchControlType::GPIO_OUTPUT;
    light.outputs.push_back(output);
    light.inputs.push_back(input);
    String idStr;
    config.generateId(idStr, light.name, light.family, sizeof(light.uniqueId));
    strlcpy(light.uniqueId, idStr.c_str(), sizeof(light.uniqueId));
    config.actuatores.push_back(light);
}
void prepareCover()
{
    ActuatorT cover;
    cover.family = COVER_DUAL_PUSH;
#ifdef CONFIG_LANG_PT
    strlcpy(cover.name, "Estore", sizeof(cover.name));
#elif CONFIG_LANG_EN
    strlcpy(cover.name, "Cover", sizeof(cover.name));
#elif CONFIG_LANG_RO
    strlcpy(cover.name, "Cover"), sizeof(cover.name));
#endif
    cover.typeControl = SwitchControlType::GPIO_OUTPUT;
    cover.outputs = {4u, 5u};
#ifdef ESP8266
    cover.inputs = {12u, 13u};
#endif
#ifdef ESP32
    cover.inputs = {13u, 14u};
#endif
    String idStr;
    config.generateId(idStr, cover.name, cover.family, sizeof(cover.uniqueId));
    strlcpy(cover.uniqueId, idStr.c_str(), sizeof(cover.uniqueId));
    config.actuatores.push_back(cover);
}
void prepareGarage()
{
    ActuatorT garage;
    garage.family = GARAGE_PUSH;
#ifdef CONFIG_LANG_PT
    strlcpy(garage.name, "Garagem", sizeof(garage.name));
#elif CONFIG_LANG_EN
    strlcpy(garage.name, "Garage", sizeof(garage.name));
#elif CONFIG_LANG_RO
    strlcpy(garage.name, "Garage"), sizeof(garage.name));
#endif
    garage.typeControl = SwitchControlType::GPIO_OUTPUT;
    garage.outputs = {4u, 5u};
#ifdef ESP8266
    garage.inputs = {12u, 13u};
#endif
#ifdef ESP32
    garage.inputs = {13u, 14u};
#endif
    String idStr;
    config.generateId(idStr, garage.name, garage.family, sizeof(garage.uniqueId));
    strlcpy(garage.uniqueId, idStr.c_str(), sizeof(garage.uniqueId));
    config.actuatores.push_back(garage);
}
void templateSelect(enum Template _template)
{
    switch (_template)
    {
    case Template::NO_TEMPLATE:
        break;
    case PZEM:
        preparePzem();
        break;
    case Template::DUAL_LIGHT:
    {
#ifdef CONFIG_LANG_PT
        String name1 = "Interruptor1";
        String name2 = "Interruptor2";
#elif CONFIG_LANG_EN
        String name1 = "Switch1";
        String name2 = "Switch2";
#elif CONFIG_LANG_RO
        String name1 = "Switch1";
        String name2 = "Switch2";
#endif
#ifdef ESP8266
        prepareLight(name1, 4u, 12u);
#endif
#ifdef ESP32
        prepareLight(name1, 4u, 14u);
#endif
        prepareLight(name2, 5u, 13u);
    }
    break;
    case Template::COVER:
        prepareCover();
        break;
    case Template::GARAGE:
        prepareGarage();
        break;
    default:
        return;
        break;
    }
}
