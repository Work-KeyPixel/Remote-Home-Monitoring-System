#ifndef SENSOR_DHT11_H
#define SENSOR_DHT11_H

#include <Arduino.h>

class SensorDHT11 {
public:
    SensorDHT11(uint8_t pin);
    void begin();
    void update();

private:
    uint8_t _pin;
    unsigned long _lastRead = 0;
    const unsigned long _interval = 2000;
};

#endif
