#include <Arduino.h>
#include "config_sensor/sensor_fire.h"
#include "config_mqtt/mqtt_client.h"

const char* fire_topic = "home/fire";

SensorFire::SensorFire(uint8_t flamePin, uint8_t fireLED, uint8_t buzzer,
                       uint8_t r, uint8_t g, uint8_t b)
    : _flamePin(flamePin), _fireLED(fireLED), _buzzer(buzzer),
      _r(r), _g(g), _b(b)
{
    _threshold = 500; 
}

void SensorFire::begin() {
    pinMode(_flamePin, INPUT);     
    pinMode(_fireLED, OUTPUT);     
    pinMode(_buzzer, OUTPUT);      
    pinMode(_r, OUTPUT);           
    pinMode(_g, OUTPUT);
    pinMode(_b, OUTPUT);

    Serial.println("Fire sensor initialized");
}

void SensorFire::update() {
    int flameValue = analogRead(_flamePin);
    bool fire = flameValue < _threshold; // active-low

    static unsigned long lastRgbTime = 0;
    static uint8_t rgbState = 0;

    digitalWrite(_fireLED, fire);
    digitalWrite(_buzzer, fire);

    if (fire) {
        if (millis() - lastRgbTime >= 300) {
            lastRgbTime = millis();
            rgbState = (rgbState + 1) % 3;
        }

        switch (rgbState) {
            case 0: 
                digitalWrite(_r, HIGH);
                digitalWrite(_g, LOW);
                digitalWrite(_b, LOW);
                break;

            case 1: 
                digitalWrite(_r, LOW);
                digitalWrite(_g, HIGH);
                digitalWrite(_b, LOW);
                break;

            case 2:
                digitalWrite(_r, LOW);
                digitalWrite(_g, LOW);
                digitalWrite(_b, HIGH);
                break;
        }

        mqttClient.publish(fire_topic, "1");
    } 
    else {
        digitalWrite(_r, LOW);
        digitalWrite(_g, LOW);
        digitalWrite(_b, LOW);

        rgbState = 0;
        mqttClient.publish(fire_topic, "0");
    }
    
    Serial.print("Fire Detected: ");
    Serial.println(fire ? "YES" : "NO");
}

