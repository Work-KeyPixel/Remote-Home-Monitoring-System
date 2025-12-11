#include "../include/config_sensor/sensor_light.h"
#include "../include/config_mqtt/mqtt_client.h"

const char* light_topic = "home/light";

SensorLight::SensorLight(uint8_t pinLight, uint8_t led1, uint8_t led2, float vref)
    : _pinLight(pinLight), _led1(led1), _led2(led2), _vref(vref) {}

void SensorLight::begin() {
    pinMode(_pinLight, INPUT);
    pinMode(_led1, OUTPUT);
    pinMode(_led2, OUTPUT);
}

void SensorLight::update() {
    int value = analogRead(_pinLight);
    float voltage = value * (_vref / 1023.0);
    bool dark = voltage < _threshold;

    digitalWrite(_led1, dark);
    digitalWrite(_led2, dark);

    mqttClient.publish(light_topic, String(voltage).c_str());

    if(dark) {
        Serial.print("Dark detected");
    } else {
        Serial.print("Light detected");
    }
    Serial.print(voltage);
    Serial.println(" V");
}
