#include <Arduino.h>

#include "Adafruit_VL53L0X.h"

#ifndef HEADER_H
#define HEADER_H

#define pulse 2
#define dir 5

int scanSerial(int safety);
void motor(int velocity);

#endif