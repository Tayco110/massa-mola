#include <Arduino.h>

#include <Wire.h>
#include <VL53L0X.h>
#include <Stepper.h>

/**
 * @brief PINOS DO MOTOR DE PASSO
 * 
 */
#define StepX 2
#define DirX 5

#define END_CURSE_1 11
#define END_CURSE_2 10
#define init_trying 5
#define home_force 85
#define STEPS 100

VL53L0X sensor;
int force = 0;
Stepper stepper(STEPS, 8, 9, 10, 11);

static int scanSerial(int safety);
static void motor(int velocity);
static void set_home();
static void mov_motor();



 /**
  * @brief Setup do Arduino
  * 
  */
void setup()
{
  Serial.begin(9600);
  Wire.begin();
  //stepper.setSpeed()

  if(sensor.init() != true){
    Serial.println("Não foi possível iniciar o sensor");
    //TODO handle init
  }

  pinMode(StepX, OUTPUT);
  pinMode(DirX, OUTPUT);

  pinMode(END_CURSE_1, INPUT_PULLUP);
  pinMode(END_CURSE_2, INPUT_PULLUP);

  set_home();
  motor(0);
}

/**
 * @brief func main do arduino
 * 
 */
void loop()
{
  Serial.print(sensor.readRangeSingleMillimeters());
  Serial.println(" mm");

  delay(500);

  force = scanSerial(force);
  motor(force);
}

/**
 * @brief Escaneia a entrada da serial
 * 
 * @param safety 
 * @return int 
 */
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


/**
 * @brief Controle do motor
 * 
 * @param velocity Velocidade de entrada
 */
static void motor(int velocity)
{
  int _velocity = constrain(velocity, -100, 100);

  digitalWrite(DirX, (_velocity > 0));

  int temp = map(abs(_velocity), 0, 100, 1000, 50);
  if (temp < 1000)
  {
    digitalWrite(StepX, 1);
    delayMicroseconds(temp);
    digitalWrite(StepX, 0);
    delayMicroseconds(temp);
  }
}

/**
 * @brief Set the home object
 * 
 */
static void set_home(){
 
  while (digitalRead(END_CURSE_1) != 1)
  {
    motor(-home_force);
  }
  motor(0);
}
