// /*
//  * spi.c
//  *
//  *  Created on: 2023��10��20��
//  *      Author: Yusaka
//  */
// #include "spi.h"
// #include "dma.h"


// void SPI_Config(void) {
//     GPIO_InitTypeDef GPIO_InitStruct;
//     SPI_InitTypeDef SPI_InitStruct;

//     RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA | RCC_APB2Periph_SPI1, ENABLE);

//     GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;
//     GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
//     GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
//     GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
//     GPIO_InitStruct.GPIO_Speed = GPIO_Speed_40MHz;
//     GPIO_Init(GPIOA, &GPIO_InitStruct);
//     GPIOA->BSRRH = 1 << 4;

//     GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
//     GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
//     GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
//     GPIO_Init(GPIOA, &GPIO_InitStruct);

//     GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
//     GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
//     GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
//     GPIO_Init(GPIOA, &GPIO_InitStruct);

//     SPI_InitStruct.SPI_CPHA = SPI_CPHA_1Edge;
//     SPI_InitStruct.SPI_CPOL = SPI_CPOL_High;
//     SPI_InitStruct.SPI_CRCPolynomial = 7;
//     SPI_InitStruct.SPI_DataSize = SPI_DataSize_8b;
//     SPI_InitStruct.SPI_Direction = SPI_Direction_1Line_Tx;
//     SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB;
//     SPI_InitStruct.SPI_Mode = SPI_Mode_Master;
//     //SPI_InitStruct.SPI_BaudRatePrescaler=SPI_BaudRatePrescaler_2;
//     SPI_InitStruct.SPI_NSS = SPI_NSS_Soft;
//     SPI_Init(SPI1, &SPI_InitStruct);

//     SPI_Cmd(SPI1, ENABLE);
// }
// void SPI_SendByte(SPI_TypeDef* SPIx, u8 ch) {
//     GPIOA->BCR = 1 << 4;
//     while(!(SPIx->STATR &(1<<1)));
//     SPIx->DATAR = ch;
//     Delay_Us(3);
//     GPIOA->BSHR = 1 << 4;
// }


// void SPI_SendDMA_Byte(void){
//     Dma_M2PConfig(DMA1_Channel3,(u32)&SPI1->DATAR,(u32)SendBuff,Buff_size);
//     GPIOA->BCR = 1 << 4;
//     SPI_I2S_DMACmd(SPI1, SPI_I2S_DMAReq_Tx, ENABLE);
//     DMA1_Channel3->MADDR=Buff_size;
//     while (DMA_GetFlagStatus(DMA1_FLAG_TC3) == RESET);
//     DMA_ClearFlag(DMA1_FLAG_TC3);
//     GPIOA->BSHR = 1 << 4;
// }

