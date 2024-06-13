/*
 * dirve_myspi.h
 *
 *  Created on: 2023��11��24��
 *      Author: Yusaka
 */

#ifndef DRIVE_DRIVE_MYSPI_H_
#define DRIVE_DRIVE_MYSPI_H_

#include "stm32l1xx.h"

#define MYSPI_CS_Pin              GPIO_Pin_12
#define MYSPI_SCL_Pin             GPIO_Pin_13
#define MYSPI_MISO_Pin            GPIO_Pin_14
#define MYSPI_MOSI_Pin            GPIO_Pin_15

#define MYSPI_CS(n)          ((n)? (GPIOB->BSRRL|=(1<<12)):(GPIOB->BSRRH|=(1<<12)))
#define MYSPI_SCL(n)         ((n)? (GPIOB->BSRRL|=(1<<13)):(GPIOB->BSRRH|=(1<<13)))
#define MYSPI_MOSI(n)        ((n)? (GPIOB->BSRRL|=(1<<15)):(GPIOB->BSRRH|=(1<<15)))
#define MYSPI_MISO_RED       ((GPIOB->IDR)>>14 &(0x1))

void MYSPI_Init(void);
uint8_t MYSPI_SendByte(uint8_t data);
#endif /* DRIVE_DRIVE_MYSPI_H_ */
