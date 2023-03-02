#include "header.h"

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


void moto(int velocity)
{
  int _velocity = constrain(velocity, -100, 100);
  digitalWrite(DIR, (_velocity > 0));

  int temp = map(abs(_velocity), 0, 100, 1000, 50);

  if (temp < 1000)
  {
    digitalWrite(PULSE, 1);
    delayMicroseconds(temp);
    digitalWrite(PULSE, 0);
    delayMicroseconds(temp);
  }
}

void read_sensor(Adafruit_VL53L0X sensor){
  VL53L0X_RangingMeasurementData_t measure;

  sensor.rangingTest(&measure, false);
  if (measure.RangeStatus != 4) {
    Serial.print("Distance (mm): "); Serial.println(measure.RangeMilliMeter);
  } 
  else {
    Serial.println(" out of range ");
  }
}

void set_home(){
  while (digitalRead(END_CURSE_1) != 1)
  {
    moto(-10);
  }
  // for (size_t i = 0; i < 100; i++)
  // {
  //   moto(10);
  // }
  // while (digitalRead(END_CURSE_1) != 1)
  // {
  //   moto(-1);
  // }
  moto(0);
  delay(500);
}