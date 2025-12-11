
// test wifi connect utility before coding

#pragma once
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiMulti.h>

namespace WiFiConnect
{
    constexpr const char *ssid[]{"ssid1", "ssid2"};
    constexpr const char *pass[]{"pass1", "pass2"};
}

inline void setup_wifi_multi()
{ 
    WiFiMulti wifiMulti;

    wifiMulti.addAP(WiFiConnect::ssid[0], WiFiConnect::pass[0]);
    wifiMulti.addAP(WiFiConnect::ssid[1], WiFiConnect::pass[1]);

    Serial.println("Connecting WiFi ...");
    if (wifiMulti.run() == WL_CONNECTED)
    {
        Serial.printf("Connected to SSID: '%s'\n", WiFi.SSID().c_str());
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
    }
}

inline void setup_wifi(const uint8_t AP_index = 1)
{
    delay(10);
    Serial.printf("Connecting to %s ", WiFiConnect::ssid[AP_index]);
    WiFi.begin(WiFiConnect::ssid[AP_index], WiFiConnect::pass[AP_index]);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.printf("\nConnected to SSID: '%s'\n", WiFi.SSID().c_str());
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}

inline void setup_wifi(const char *SSID, const char *PASS)
{
    delay(10);
    Serial.printf("Connecting to %s ", SSID);
    WiFi.begin(SSID, PASS);
    while (WiFi.status() != WL_CONNECTED)
    { 
        delay(500);
        Serial.print(".");
    }
    Serial.printf("\nConnected to SSID: '%s'\n", WiFi.SSID().c_str());
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}