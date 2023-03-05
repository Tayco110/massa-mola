/**
 * @file motor_driver.h
 * @author Tayco Murilo (murilo.rodrigues@edge.ufal.br)
 * @brief Componente responsável por agrupar as assinaturas de definições do componente
 * @version 0.1
 * @date 2023-03-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include "utils.h"

#define STEP 1.8
#define escale 80



/**
 * @brief Calcula a frequência entre os pulsos do motor para um valor desejado de rotações por minuto
 * 
 * @param rotações por minutos dsejada
 * @return Períodod entre os pulsos
 */
int get_periode(int rpm);

/**
 * @brief Seta a velocidade do motor utilizando um escalar
 * 
 * @param velocity 
 * @return void
 */
void motor(int velocity);

/**
 * @brief Task para rodar o motor
 * 
 * @param param 
 * @return void
 */
void motor_task(void* param);

#endif //MOTOR_DRIVER_H