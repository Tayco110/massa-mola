#include <Arduino.h>
#include <Wire.h>
#include <VL53L0X.h>

#define step 2
#define dirct 5
#define END_CURSE_1 11
#define END_CURSE_2 10

static int scanSerial(int safety);
static void motor(int velocity);
static void set_home();

VL53L0X sensor;
int force = 0;
int sentido = 1;
bool direction = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(step, OUTPUT);
  pinMode(dirct, OUTPUT);
  pinMode(END_CURSE_1, INPUT_PULLUP);
  pinMode(END_CURSE_2, INPUT_PULLUP);

  Wire.begin();

  if(sensor.init() != true){
    Serial.println("Não foi possível iniciar o sensor");
    //TODO handle init
  }

  set_home();
  
}

void loop()
{
  //force = scanSerial(force);
  //motor(force);
}


static int scanSerial(int safety)
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

static void motor(int velocity)
{
  if(velocity > 0){
    digitalWrite(dirct, LOW);
    direction = true;
  }
  else if(velocity < 0){
    digitalWrite(dirct, HIGH);
    direction = false;
  }

  for(int x = 0; x<200; x++) {
    if(){

    }
    if(){
      
    }
    digitalWrite(step,HIGH);
    delayMicroseconds(500);
    digitalWrite(step,LOW); 
    delayMicroseconds(500);
 }

}


static void set_home(){

  while (digitalRead(END_CURSE_2) != 1)
  {
    motor(-sentido);
  }
  //max_range = sensor.readRangeSingleMillimeters() * 0.95;

  while (digitalRead(END_CURSE_1) != 1)
  {
    motor(sentido);
  }

  //min_range = sensor.readRangeSingleMillimeters() * 1.05;
}