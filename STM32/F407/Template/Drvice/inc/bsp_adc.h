#ifndef __BSP_ADC_H
#define __BSP_ADC_H

#include "stm32f4xx.h"
#include "bf_lib.h"
#include "string.h"
#include "stdio.h"

void ADC1_Init(void);
uint16_t ADC_Read(void);
#endif // !__BSP_ADC_H
