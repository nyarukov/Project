#ifndef __BSP_ADC_H
#define __BSP_ADC_H

#include "stm32f10x.h"
#include "bsp_user_lib.h"

#define ADC_CHANNELS 1
#define ADC_BUFFER_SIZE ADC_CHANNELS

typedef enum
{
    ADC_Ch0 = 0,
    ADC_Ch1 = 1,
    ADC_Ch2 = 2,
    ADC_Ch3 = 3,
    ADC_Ch4 = 4
} ADC_Chx_ID;


uint16_t ADC_Read(ADC_Chx_ID channel);

void ADC1_Init(void);

#endif
