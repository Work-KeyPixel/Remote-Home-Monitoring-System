#include "../include/config_sensor/sensor_dht11.h"
#include "../include/config_mqtt/mqtt_client.h"
#include <DHT.h>

const char* temperature_topic = "home/temperature";
const char* humidity_topic    = "home/humidity";

#define DHT_TYPE DHT11
static DHT dht_global(0, DHT_TYPE);

SensorDHT11::SensorDHT11(uint8_t pin) : _pin(pin) {}

void SensorDHT11::begin() {
    dht_global = DHT(_pin, DHT_TYPE);
    dht_global.begin();
    Serial.begin(9600);
}

void SensorDHT11::update() {
    unsigned long now = millis();
    if (now - _lastRead < _interval) return;
    _lastRead = now;

    float t = dht_global.readTemperature();
    float h = dht_global.readHumidity();

    if (!isnan(t)) {
        mqttClient.publish(temperature_topic, String(t).c_str());
        Serial.print("Temperature: ");
        Serial.print(t);
        Serial.println(" °C");
    }

    if (!isnan(h)) {
        mqttClient.publish(humidity_topic, String(h).c_str());
        Serial.print("Humidity: ");
        Serial.print(h);
        Serial.println(" %");
    }
}
