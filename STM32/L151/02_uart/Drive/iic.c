// /*
//  * drive_iic.c
//  *
//  *  Created on: 2023??11??22??
//  *      Author: Yusaka
//  */

// #include "iic.h"

// void IIC_GPIO(void){
//     GPIO_InitTypeDef GPIO_InitStructe;
//     RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
//     GPIO_InitStructe.GPIO_Pin=SCL_Pin|SDA_Pin;
//     GPIO_InitStructe.GPIO_Mode=GPIO_Mode_OUT;
//     GPIO_InitStructe.GPIO_OType=GPIO_OType_PP;
//     GPIO_InitStructe.GPIO_PuPd=GPIO_PuPd_NOPULL;
//     GPIO_InitStructe.GPIO_Speed=GPIO_Speed_40MHz;
//     GPIO_Init(GPIOB, &GPIO_InitStructe);
//     IIC_SCL(1);
//     IIC_SDA(1);
// }
// void IIC_Start(void){
//     IIC_SDA(1);
//     Delay_Us(4);
//     IIC_SCL(1);
//     Delay_Us(4);
//     IIC_SDA(0);
//     Delay_Us(5);
//     IIC_SCL(0);
//     Delay_Us(4);
// }
// void IIC_Stop(void){
//     IIC_SDA(0);
//     Delay_Us(4);
//     IIC_SCL(1);
//     Delay_Us(5);
//     IIC_SDA(1);
//     Delay_Us(4);
// }
// void IIC_SendByte(uint8_t data){
//     uint8_t i;
//     for (i = 0; i < 8; i++) {
//         if(data & (0x80>>i)){
//             IIC_SDA(1);
//         }else {
//             IIC_SDA(0);
//         }
//         Delay_Us(4);
//         IIC_SCL(1);
//         Delay_Us(4);
//         IIC_SCL(0);
//         Delay_Us(4);
//     }
// }
// uint8_t IIC_ReadByte(void){
//     uint8_t i;
//     uint8_t rxdata=0;
//     IIC_SDA(1);
//     for (i = 0; i < 8; i++) {
//         IIC_SCL(1);
//         Delay_Us(4);
//         if(SDA_RED){
//             rxdata|=(0x80>>i);
//         }
//         Delay_Us(4);
//         IIC_SCL(0);
//         Delay_Us(4);
//     }
//     return rxdata;
// }
// void IIC_SendACK(uint8_t ACK){
//     IIC_SDA(ACK);
//     Delay_Us(4);
//     IIC_SCL(1);
//     Delay_Us(4);
//     IIC_SCL(0);
//     Delay_Us(4);
// }
// uint8_t IIC_ReadACK(void){
//     uint8_t ACK;
//     IIC_SDA(1);
//     Delay_Us(4);
//     IIC_SCL(1);
//     Delay_Us(4);
//     ACK=SDA_RED;
//     Delay_Us(4);
//     IIC_SCL(0);
//     Delay_Us(4);
//     return ACK;
// }


