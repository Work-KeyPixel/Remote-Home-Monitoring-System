## Include Directory Overview

This directory contains configuration files, sensor, and secret credentials used in the IoT project. It is organized into three main subdirectories:

## config_mqtt
Contains files for **MQTT communication and Wi-Fi setup**:
- `MQTT.h` – Wrapper for MQTT client functions (only test mqtt before coding)
- `wifi_connect.h` – Functions to connect ESP32 to Wi-Fi (only test wifi before coding)
- `ca_cert_emqx.h` – Certificate authority for secure MQTT connection
- `mqtt_client.h` – Handles MQTT publishing and subscribing

## config_sensor
Contains **sensor driver files** for reading environmental data:
- `sensor_dht11.h` – Driver for DHT11 temperature and humidity sensor
- `sensor_fire.h` – Driver for flame detection sensor
- `sensor_ir.h` – Driver for IR proximity sensor
- `sensor_light.h` – Driver for ambient light sensor

## secrets
Stores **private credentials**, separated from the main code for security:
- `mqtt.h` – MQTT broker username and password
- `wifi.h` – Wi-Fi SSID and password

## Usage
Include the relevant headers in your main project code to configure sensors and MQTT communication:
- `#include "config_mqtt"`
- `#include "config_sensor"`
- `#include "secrets"`

> **Note:** Do not share the `secrets` folder publicly to avoid exposing sensitive credentials
