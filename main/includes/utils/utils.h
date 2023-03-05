/**
 * @file util.h
 * @author Tayco Murilo (murilo.rodrigues@edge.ufal.br)
 * @brief Macros e headers para uso geral
 * @version 0.1
 * @date 2023-03-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef UTILS_H
#define UTILS_H

#include "Arduino.h"

#include <driver/uart.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "errno.h"
#include "stdbool.h"
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


/**
 * @brief Macro para retornar o mínimo entre dois valores
 */
#ifndef MIN
#define MIN(a, b) (((a) <= (b)) ? (a) : (b))
#endif /* MIN */

/**
 * @brief Macro para argumentos não utilizados as funções
 */
#define ARG_UNUSED(arg) ((void) arg)


/**
 * @brief Macro para coletar o código de erro de uma função
 */
#define CHECK_ERROR(fn)                                                     \
    do {                                                                    \
        int __err = fn;                                                     \
        if (__err != 0) {                                                   \
            HTM_LOGE("Error at <%s:%d:%d>", __FUNCTION__, __LINE__, __err); \
            return __err;                                                   \
        }                                                                   \
    } while (false)

/**
 * @brief Definições para a UART 0
 */
#define UART0 UART_NUM_0
#define UART0_TX_PIN GPIO_NUM_1
#define UART0_RX_PIN GPIO_NUM_3
#define UART0_BAUD_RATE 115200
#define UART0_BUF_SIZE 64
#define UART0_RX_TIMEOUT 1000

/**
 * @brief Definição dos GPIOS utilizados
 */
#define PULSE_PIN GPIO_NUM_2
#define DIRECTION_PIN GPIO_NUM_5
#define L_END_CURSE GPIO_NUM_18
#define R_END_CURSE GPIO_NUM_19

#endif //UTILS_H