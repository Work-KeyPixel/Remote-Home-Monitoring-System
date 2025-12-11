#ifndef SENSOR_LIGHT_H
#define SENSOR_LIGHT_H

#include <Arduino.h>

class SensorLight {
public:
    SensorLight(uint8_t pinLight, uint8_t led1, uint8_t led2, float vref = 5.0f);
    void begin();
    void update();

private:
    uint8_t _pinLight, _led1, _led2;
    float _vref;
    const float _threshold = 2.0;
};

#endif
