#include <Arduino.h>
#include "config_mqtt/mqtt_client.h"
#include "config_sensor/sensor_light.h"
#include "config_sensor/sensor_fire.h"
#include "config_sensor/sensor_ir.h"
#include "config_sensor/sensor_dht11.h"

SensorLight lightSensor(34, 33, 13);
SensorFire  fireSensor(32, 19, 18, 15, 14, 4);
SensorIR    irSensor(27, 26);
SensorDHT11 dht11(25);

void setup() {
    Serial.begin(9600);
    delay(100);
    mqtt_setup();

    lightSensor.begin();
    fireSensor.begin();
    irSensor.begin();
    dht11.begin();
}

void loop() {
    mqtt_loop();

    lightSensor.update();
    fireSensor.update();
    irSensor.update();
    dht11.update();

    delay(300); 
}