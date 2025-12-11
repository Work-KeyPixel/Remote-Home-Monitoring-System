#ifndef SENSOR_IR_H
#define SENSOR_IR_H

#include <Arduino.h>
#include <Servo.h>

class SensorIR {
private:
    uint8_t _irPin;       
    uint8_t _servoPin;    
    Servo _servo;         // servo object
    bool _lastState;     

public:
    SensorIR(uint8_t irPin, uint8_t servoPin);

    void begin();         // setup pin và servo
    void update();        // đọc IR, cập nhật servo, Serial và MQTT
};

#endif
