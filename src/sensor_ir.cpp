#include "../include/config_sensor/sensor_ir.h"
#include "../include/config_mqtt/mqtt_client.h"

const char* ir_topic = "home/ir";

SensorIR::SensorIR(uint8_t irPin, uint8_t servoPin)
    : _irPin(irPin), _servoPin(servoPin), _lastState(false)
{}

void SensorIR::begin() {
    pinMode(_irPin, INPUT);       
    _servo.attach(_servoPin);    
}

void SensorIR::update() {

    bool detected = (digitalRead(_irPin) == LOW);

    _servo.write(detected ? 90 : 0);

    mqttClient.publish(ir_topic, detected ? "1" : "0");

    if (detected != _lastState) {
        Serial.print("IR Detected: ");
        Serial.println(detected ? "YES" : "NO");
        _lastState = detected;
    }
}
