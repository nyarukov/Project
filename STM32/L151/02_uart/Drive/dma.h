/*
 * dma.h
 *
 *  Created on: 2023Äê11ÔÂ14ÈÕ
 *      Author: Yusaka
 */

#ifndef DRIVE_DRIVE_DMA_H_
#define DRIVE_DRIVE_DMA_H_

#include "stm32l1xx.h"

void Dma_M2MConfig(DMA_Channel_TypeDef *DMAy_Channelx,uint32_t ReBuff,uint32_t SendBuff,uint32_t BuffSize);
void Dma_M2PConfig(DMA_Channel_TypeDef *DMAy_Channelx,uint32_t ReBuff,uint32_t SendBuff,uint32_t BuffSize);
void DMA_Enable(DMA_Channel_TypeDef *DMAy_Channelx);

#endif /* DRIVE_DRIVE_DMA_H_ */
