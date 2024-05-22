#ifndef __BSP_KEY_H
#define __BSP_KEY_H

#include "stm32h7xx_hal.h"
#include "bsp_control.h"
#include "bsp_uart.h"

#if KEYMATRIX
#define ROW_PORT    GPIOG
#define ROW_PIN_1   GPIO_PIN_2
#define ROW_PIN_2   GPIO_PIN_3
#define ROW_PIN_3   GPIO_PIN_4
#define ROW_PIN_4   GPIO_PIN_5

#define COL_PORT    GPIOD
#define COL_PIN_1   GPIO_PIN_12
#define COL_PIN_2   GPIO_PIN_13
#define COL_PIN_3   GPIO_PIN_14
#define COL_PIN_4   GPIO_PIN_15

void Key_Matrix(void);
uint8_t pollKeys(void);
#endif

#define KEY_PORT    GPIOB
#define KEY1_PIN    3
#define KEY2_PIN    4
#define KEY3_PIN    5

#define KEY_FIFO_SIZE   10

typedef struct{
    uint8_t KeyFifo[KEY_FIFO_SIZE];
    uint8_t Read;
    uint8_t Write;
}KEY_FIFO_t;

void KEY_Init(void);

#endif // !__BSP_KEY_H
