/**
 * @file main.cpp
 * @author Tayco Murilo (murilo.rodrigues@edge.ufal.br)
 * @brief Fluxo principal de execução do programa
 * @version 0.1
 * @date 2023-03-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "motor_driver.h"
#include "sensor_driver.h"
#include "serial_driver.h"

#include "utils.h"

#define SENSOR_TASK_STACKSIZE (1024)
#define SENSOR_TASK_PRIORITY (tskIDLE_PRIORITY + 1)

#define MOTOR_TASK_STACKSIZE (1024)
#define MOTOR_TASK_PRIORITY (tskIDLE_PRIORITY + 1)

static TaskHandle_t sensor_task_handle                  = NULL;
static uint8_t sensor_task_stack[SENSOR_TASK_STACKSIZE] = {0U};
static StaticTask_t sensor_task_metadata                = {0};

static TaskHandle_t motor_task_handle                 = NULL;
static uint8_t motor_task_stack[MOTOR_TASK_STACKSIZE] = {0U};
static StaticTask_t motor_task_metadata               = {0};

// static BaseType_t sensor_tsk;
// static TaskHandle_t sensor_task_handler = NULL;

// static BaseType_t motor_tsk;
// static TaskHandle_t motor_task_handler = NULL;

/**
 * @brief Inicia os pinos da esp32
 */
static void pin_setup();

extern "C" void app_main()
{
    Serial.begin(115200);

    pin_setup();

    /*Criando as tarefas*/
    sensor_task_handle = xTaskCreateStatic(sensor_task, "sensor_task", SENSOR_TASK_STACKSIZE, NULL, SENSOR_TASK_PRIORITY, sensor_task_stack, &sensor_task_metadata);

    motor_task_handle  = xTaskCreateStatic(motor_task, "motor_task", MOTOR_TASK_STACKSIZE, NULL, MOTOR_TASK_PRIORITY, motor_task_stack, &motor_task_metadata);
}

static void pin_setup(){

    gpio_set_direction(PULSE_PIN, GPIO_MODE_OUTPUT);
    gpio_set_direction(DIRECTION_PIN, GPIO_MODE_OUTPUT);

    gpio_set_direction(L_END_CURSE, GPIO_MODE_INPUT);
    gpio_set_direction(R_END_CURSE, GPIO_MODE_INPUT);

    gpio_pullup_en(L_END_CURSE);
    gpio_pullup_en(R_END_CURSE);
}