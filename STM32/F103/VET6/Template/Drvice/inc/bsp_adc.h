/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-05-20 14:36:21
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-05-22 16:26:24
 * @FilePath: \F10x\Template\Drvice\inc\bsp_adc.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __BSP_ADC_H
#define __BSP_ADC_H

#include "stm32f4xx.h"
#include "bf_middle.h"
#include "string.h"
#include "stdio.h"

void ADC1_Init(void);
uint16_t ADC_Read(void);
#endif // !__BSP_ADC_H
