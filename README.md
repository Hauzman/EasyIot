# BH OnOfre
 
* [Intro](#id1)
* [BH ONOFRE BOARD](https://github.com/brunohorta82/BH_OnOfre)
* [BH PZEM BOARD](https://github.com/brunohorta82/BH_PZEM_ESP8266)
* [Binários](https://github.com/brunohorta82/EasyIot/tree/master/FIRMWARE_VERSIONS)
* [Video Tutoriais - YouTube](https://www.youtube.com/watch?v=OZenBfHWtak&list=PLxDLawCWayzDqAgOpIDJ-DHFAXYd_S-pr)
* [Donativos](#id6)
* [Site Oficial](http://bhonofre.pt/)

## AP Password
EasyIot@

## Intro <a name="id1"></a>
O projeto BH Easy Iot, é o firmware oficial para todas as boards BH, no entanto tambem é compativel com todas as boards baseadas em ESP8266 tem  o objetivo de tornar a automação domiciliar muito mais simples, de forma aberta e sem restrições. Todo o código fonte é aberto.


## Painel de Controlo <a name="id3"></a>

![dash](https://github.com/brunohorta82/BH-Easy-Iot/blob/master/screenshots/node.png)
![devices](https://github.com/brunohorta82/BH-Easy-Iot/blob/master/screenshots/devices.png)
![wifi](https://github.com/brunohorta82/BH-Easy-Iot/blob/master/screenshots/wifi.png)
![mqtt](https://github.com/brunohorta82/BH-Easy-Iot/blob/master/screenshots/mqtt.png)
![update](https://github.com/brunohorta82/BH-Easy-Iot/blob/master/screenshots/update.png)

## Hardware <a name="id2"></a>
* BH OnOfre Dev Board 3.4
![dev_board_3.4](https://github.com/brunohorta82/BH_OnOfre/blob/master/docs/onofre_dev_board_v3.4.png)


## Software necessário <a name="id3"></a>

- Arduino Ide (caso seja para alterar o codigo fonte)
- Upload do Firmware para o ESP8266 (dentro de cada projeto o firmware está dentro da pasta binarios)
- Aceder ao AP `SSID:BH_ONFFRE_NODE_ID` e configurar a Rede Wi-Fi
- Navegar até  `http://<bh-onofre name>.local` ou `http://<bh-onofre IP address>` ou `http://192.168.4.1` ligado directamente ao módulo
- Configurar o `Wi-Fi broker`, `MQTT broker` entre outras coisas como integração automática com `Home Assistant`
- E tá feito, agora é só curtir :) 


## Donativos <a name="id6"></a>

Se gostaste do projeto podes fazer o teu donativo :).

[![Donativo](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://www.paypal.me/bhonofre)

## API
h1. EasyIot Api This api allows you to control all your devices that have the EasyIot Firmware installed.

*Version:* 1.0.0
