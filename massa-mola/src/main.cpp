#include "header.h"

int force = 90;
int force_ = 80;
int count;

Adafruit_VL53L0X sensor = Adafruit_VL53L0X();

void motor(int velocity, Adafruit_VL53L0X sensor)
{
  int _velocity = constrain(velocity, -100, 100);
  digitalWrite(DIR, (_velocity > 0));

  int temp = map(abs(_velocity), 0, 100, 1000, 50);

  if (temp < 1000)
  {
    digitalWrite(PULSE, 1);
    read_sensor(sensor);
    // delayMicroseconds(temp);
    digitalWrite(PULSE, 0);
    read_sensor(sensor);
    // delayMicroseconds(temp);
  }
}

void setup()
{
  Serial.begin(9600);
  pinMode(PULSE, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(END_CURSE_1, INPUT_PULLUP);
  pinMode(END_CURSE_2, INPUT_PULLUP);
  if (!sensor.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  // set_home();
}

void loop()
{
  //force = scanSerial(force);
  // Serial.println(force_);

  // if(force != force_){
  //   force_ = force;
  // }
  // Serial.print(digitalRead(END_CURSE_1));
  // Serial.print(" ");
  // Serial.print(digitalRead(END_CURSE_2));
  // Serial.print(" ");
  //Serial.println(force);
  //delay(500);

  // if(digitalRead(END_CURSE_1)){
  //     digitalWrite(PULSE, 0);
  //     motor(10);
  //     delay(1000);
  // }
  // else if(digitalRead(END_CURSE_2)){
  //     digitalWrite(PULSE, 0);
  //     motor(-10);
  //     delay(1000);
  // }
  if(digitalRead(END_CURSE_1) && force_ < 0){
    motor(0, sensor);
    force_ = (-1) * force_;
  }
  else if(digitalRead(END_CURSE_2) && force_ > 0){
    motor(0, sensor);
    force_ = (-1) * force_;
  }
  motor(force_, sensor);
}

