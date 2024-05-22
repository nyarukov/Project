/*
 * dirve_myspi.c
 *
 *  Created on: 2023��11��24��
 *      Author: Yusaka
 */
#include "myspi.h"

void MYSPI_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructe;
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB,ENABLE);
    GPIO_InitStructe.GPIO_Pin = MYSPI_CS_Pin | MYSPI_SCL_Pin | MYSPI_MOSI_Pin;
    GPIO_InitStructe.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructe.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructe.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructe.GPIO_Speed = GPIO_Speed_40MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructe);

    GPIO_InitStructe.GPIO_Pin = MYSPI_MISO_Pin;
    GPIO_InitStructe.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructe.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStructe.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructe.GPIO_Speed = GPIO_Speed_40MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructe);
    MYSPI_CS(1);
    MYSPI_SCL(0);
}

uint8_t MYSPI_SendByte(uint8_t data)
{
    uint8_t i;
    for (i = 0; i < 8; i++)
    {
        MYSPI_MOSI(data & 0x80);
        data <<= 1;
        MYSPI_SCL(1);
        if (MYSPI_MISO_RED)
            data |= 0x1;
        MYSPI_SCL(0);
    }
    return data;
}
