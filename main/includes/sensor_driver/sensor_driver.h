/**
 * @file sensor_driver.h
 * @author Tayco Murilo (murilo.rodrigues@edge.ufal.br)
 * @brief Componente responsável por agrupar as assinaturas de definições do componente
 * @version 0.1
 * @date 2023-03-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef SENSOR_DRIVER_H
#define SENSOR_DRIVER_H

#define SAMPPLING_TIME_MS 1

#include "Wire.h"
#include "VL53L0X.h"

#include "utils.h"

/**
 * @brief Tarefa responsável por cocletar as informações do sensor 
 * 
 * @param param 
 */
void sensor_task(void* param);

#endif //SENSOR_DRIVER_H