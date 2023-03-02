#include "Arduino.h"
#include "Wire.h"
#include "Adafruit_VL53L0X.h"

#define PULSE 2
#define DIR 5
#define END_CURSE_1 11
#define END_CURSE_2 10

int scanSerial(int safety);

void moto(int velocity);

void read_sensor(Adafruit_VL53L0X sensor);

void set_home();