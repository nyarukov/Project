/*
 * dma.c
 *
 *  Created on: 2023Äê11ÔÂ14ÈÕ
 *      Author: Yusaka
 */

#include "dma.h"


void Dma_M2MConfig(DMA_Channel_TypeDef *DMAy_Channelx,uint32_t ReBuff,uint32_t SendBuff,uint32_t BuffSize){
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
    DMA_InitTypeDef DMA_InitStruct;
    DMA_InitStruct.DMA_PeripheralBaseAddr=ReBuff;
    DMA_InitStruct.DMA_PeripheralDataSize=DMA_PeripheralDataSize_Byte;
    DMA_InitStruct.DMA_PeripheralInc=DMA_PeripheralInc_Enable;
    DMA_InitStruct.DMA_MemoryBaseAddr=SendBuff;
    DMA_InitStruct.DMA_MemoryDataSize=DMA_MemoryDataSize_Byte;
    DMA_InitStruct.DMA_MemoryInc=DMA_MemoryInc_Enable;
    DMA_InitStruct.DMA_BufferSize=BuffSize;
    DMA_InitStruct.DMA_DIR=DMA_DIR_PeripheralSRC;
    DMA_InitStruct.DMA_M2M=DMA_M2M_Enable;
    DMA_InitStruct.DMA_Mode=DMA_Mode_Normal;
    DMA_InitStruct.DMA_Priority=DMA_Priority_VeryHigh;
    DMA_Init(DMAy_Channelx, &DMA_InitStruct);

    DMA_Cmd(DMAy_Channelx, ENABLE);
}
void Dma_M2PConfig(DMA_Channel_TypeDef *DMAy_Channelx,uint32_t ReBuff,uint32_t SendBuff,uint32_t BuffSize){
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

    DMA_InitTypeDef DMA_InitStruct;
    DMA_DeInit(DMAy_Channelx);
    DMA_InitStruct.DMA_PeripheralBaseAddr=ReBuff;
    DMA_InitStruct.DMA_PeripheralDataSize=DMA_PeripheralDataSize_Byte;
    DMA_InitStruct.DMA_PeripheralInc=DMA_PeripheralInc_Disable;

    DMA_InitStruct.DMA_MemoryBaseAddr=SendBuff;
    DMA_InitStruct.DMA_MemoryDataSize=DMA_MemoryDataSize_Byte;
    DMA_InitStruct.DMA_MemoryInc=DMA_MemoryInc_Enable;

    DMA_InitStruct.DMA_BufferSize=BuffSize;
    DMA_InitStruct.DMA_DIR=DMA_DIR_PeripheralDST;
    DMA_InitStruct.DMA_M2M=DMA_M2M_Disable;
    DMA_InitStruct.DMA_Mode=DMA_Mode_Normal;
    DMA_InitStruct.DMA_Priority=DMA_Priority_High;
    DMA_Init(DMAy_Channelx, &DMA_InitStruct);
    DMA_Cmd(DMAy_Channelx, ENABLE);

}
void DMA_Enable(DMA_Channel_TypeDef *DMAy_Channelx){
    DMA_Cmd(DMAy_Channelx, DISABLE);
    DMA_SetCurrDataCounter(DMAy_Channelx, 0);
    DMA_Cmd(DMAy_Channelx, ENABLE);
}
