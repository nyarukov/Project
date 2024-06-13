/*
 * drive_iic.h
 *
 *  Created on: 2023��11��22��
 *      Author: Yusaka
 */

#ifndef DRIVE_DRIVE_IIC_H_
#define DRIVE_DRIVE_IIC_H_

#include "stm32l1xx.h"

#define SCL_Pin     GPIO_Pin_10
#define SDA_Pin     GPIO_Pin_11

#define IIC_SCL(n)  ((n)? (GPIOB->BSRRL|=(1<<10)):(GPIOB->BSRRH|=(1<<10)))
#define IIC_SDA(n)  ((n)? (GPIOB->BSRRL|=(1<<11)):(GPIOB->BSRRH|=(1<<11)))
#define SDA_IN()    do{GPIOB->CFGHR &=~(3<<3*4);GPIOB->CFGHR |=(1<<(3*4+2));}while(0)
#define SDA_OUT()   do{GPIOB->CFGHR |=(3<<3*4);GPIOB->CFGHR |=(1<<(3*4+2));}while(0)
#define SDA_RED     ((GPIOB->ODR)>>11 &(0x1))

void IIC_GPIO(void);
void IIC_Start(void);
void IIC_Stop(void);
void IIC_SendByte(uint8_t data);
uint8_t IIC_ReadByte(void);
void IIC_SendACK(uint8_t ACK);
uint8_t IIC_ReadACK(void);

#endif /* DRIVE_DRIVE_IIC_H_ */
