
// wifi and mqtt client setup

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include "secrets/wifi.h"
#include "secrets/mqtt.h"
#include "mqtt_client.h"

WiFiClientSecure espClient;
PubSubClient mqttClient(espClient);  

void mqtt_setup() {
    WiFi.begin(WiFiSecrets::ssid, WiFiSecrets::pass);
    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi connected! IP: " + WiFi.localIP().toString());

    espClient.setInsecure();
    mqttClient.setServer(EMQX::broker, EMQX::port);

    Serial.print("Connecting to MQTT...");
    while (!mqttClient.connected()) {
        if (mqttClient.connect("ESP32_Fire", EMQX::username, EMQX::password)) {
            Serial.println("connected!");
        } else {
            Serial.print("failed, rc=");
            Serial.print(mqttClient.state());
            Serial.println(" try again in 2s");
            delay(2000);
        }
    }
}

void mqtt_loop() {
    if (!mqttClient.connected()) {
        while (!mqttClient.connected()) {
            Serial.print("Reconnecting MQTT...");
            if (mqttClient.connect("ESP32_Fire", EMQX::username, EMQX::password)) {
                Serial.println("connected!");
            } else {
                Serial.print("failed, rc=");
                Serial.print(mqttClient.state());
                Serial.println(" try again in 2s");
                delay(2000);
            }
        }
    }
    mqttClient.loop();
}
