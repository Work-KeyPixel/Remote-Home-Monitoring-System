#ifndef SENSOR_FIRE_H
#define SENSOR_FIRE_H

#include <Arduino.h>

class SensorFire {
private:
    uint8_t _flamePin;
    uint8_t _fireLED;
    uint8_t _buzzer;
    uint8_t _r, _g, _b;
    int _threshold = 500; 
    bool _lastState;

public:
    SensorFire(uint8_t flamePin, uint8_t fireLED, uint8_t buzzer,
               uint8_t r, uint8_t g, uint8_t b);

    void begin();
    void update();
};

#endif
