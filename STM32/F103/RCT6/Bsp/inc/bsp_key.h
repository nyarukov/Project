#ifndef __BSP_KEY_H
#define __BSP_KEY_H

#include "stm32f10x.h"
#include "multi_button.h"
#include "bsp.h"

typedef enum
{
    KEY1_CLICK = 1,
    KEY1_DOUBLE,
    KEY1_PRESS,
    KEY2_CLICK,
    KEY2_DOUBLE,
    KEY2_PRESS,
    KEY3_CLICK,
    KEY3_DOUBLE,
    KEY3_PRESS
} key_start;

void Button_Init(void);

#endif // !__BSP_KEY_H
