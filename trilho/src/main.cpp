#include "header.h"

Adafruit_VL53L0X lox = Adafruit_VL53L0X();
uint16_t entrada;

int force = 0;


void setup() {

  Serial.begin(115200);
  pinMode(pulse, OUTPUT);
  pinMode(dir, OUTPUT);

  while (! Serial) {
    delay(1);
  }

  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }

  lox.startRangeContinuous();
}

void loop() {
  
  if (lox.isRangeComplete()) {
    Serial.println(lox.readRange());
  }

  force = scanSerial(force);
  motor(force);
  delay(100);
}

void motor(int velocity)
{
  int _velocity = constrain(velocity, -100, 100);

  digitalWrite(dir, (_velocity > 0));

  int temp = map(abs(_velocity), 0, 100, 1000, 50);
  if (temp < 1000)
  {
    digitalWrite(pulse, 1);
    delayMicroseconds(temp);
    digitalWrite(pulse, 0);
    delayMicroseconds(temp);
  }
}

int scanSerial(int safety)
{
  while (Serial.available() > 0)
  {
    static uint8_t index;
    static char input[4];
    char character = Serial.read();

    if (character != '\n' && index < 5)
    {
      input[index++] = character;
    }
    else
    {
      input[index] = '\0';
      index = 0;
      return atoi(input);
    }
  }
  return safety;
}