#include <Arduino.h>

#define pulse 2
#define dir 5
#define END_CURSE_1 11
int force = 0;

void moto(int velocity);
int scanSerial(int safety);

void setup()
{
  Serial.begin(115200);
  pinMode(pulse, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(END_CURSE_1, INPUT_PULLUP);

  while (digitalRead(END_CURSE_1) != 1)
  {
    moto(-100);
  }
  for (size_t i = 0; i < 100; i++)
  {
    moto(10);
  }
  while (digitalRead(END_CURSE_1) != 1)
  {
    moto(-1);
  }
  moto(0);

}

void loop()
{
  force = scanSerial(force);
  moto(force);
}

//====================================================================================================
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
//====================================================================================================

//====================================================================================================
void moto(int velocity)
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
//====================================================================================================2