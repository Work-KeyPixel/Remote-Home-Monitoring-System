#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

#include <PubSubClient.h>  

extern PubSubClient mqttClient;

void mqtt_setup();
void mqtt_loop();

#endif
