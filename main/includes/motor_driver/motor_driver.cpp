/**
 * @file motor_driver.c
 * @author Tayco Murilo (murilo.rodrigues@edge.ufal.br)
 * @brief Componente responsável por gerênciar o uso do motor de passo
 * @version 0.1
 * @date 2023-03-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "motor_driver.h"

int get_periode(int rpm){

    int per = (60 * 1000000) /(rpm * 6545);
    return per;
}

void motor(int velocity)
{
    int _velocity = constrain(velocity, -100, 100);
    digitalWrite(DIRECTION_PIN, (_velocity > 0));

    //int temp = map(abs(_velocity), 0, 100, 1000, 50);
    int temp = get_periode(80);

    digitalWrite(PULSE_PIN, 1);
    delayMicroseconds(temp);
    digitalWrite(PULSE_PIN, 0);
    delayMicroseconds(temp);
}

void motor_task(void* param){

    int force = 50;

    while(true){

        if(digitalRead(L_END_CURSE) && force < 0){
            motor(0);
            force = (-1) * force;
            delay(10);
        }
        else if(digitalRead(R_END_CURSE) && force > 0){
            motor(0);
            force = (-1) * force;
            delay(10);
        }
    motor(force);
    }
}
