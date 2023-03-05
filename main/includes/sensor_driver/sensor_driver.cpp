/**
 * @file sensor_driver.c
 * @author Tayco Murilo (murilo.rodrigues@edge.ufal.br)
 * @brief Componente responsável por gerênciar o(s) sensor(es) de distância utilizado(s)
 * @version 0.1
 * @date 2023-03-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "sensor_driver.h"

static VL53L0X sensor;

void sensor_task(void* param){

    Wire.begin();
    sensor.setTimeout(500);

    while(!sensor.init())
    {
        Serial.println("Failed to detect and initialize sensor!");
        vTaskDelay(500/portTICK_PERIOD_MS);
    }

    sensor.setTimeout(500);
    sensor.startContinuous();

    while (true)
    {
        float dist = sensor.readRangeSingleMillimeters();
        dist*= 1.02233271;
        dist+= -34.21841006482799;

        Serial.println(dist);
        delay(SAMPPLING_TIME_MS);
    } 
}