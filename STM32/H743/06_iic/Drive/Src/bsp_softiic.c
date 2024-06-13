#include "bsp_softiic.h"

void SoftIIC_Init(void)
{

	
    GPIO_InitTypeDef SoftIICStruct;
    __HAL_RCC_GPIOE_CLK_ENABLE();
    SoftIICStruct.Pin = SoftIIC_SCL_Pin | SoftIIC_SDA_Pin;
    SoftIICStruct.Mode = GPIO_MODE_OUTPUT_OD;
    SoftIICStruct.Pull = GPIO_NOPULL;
    SoftIICStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(SoftIIC_PORT, &SoftIICStruct);
    __GPIO_SET_BIT(SoftIIC_PORT, SoftIIC_SCL_Pin | SoftIIC_SDA_Pin);
	
	  
}
void SoftIIC_Start(void)
{
    SoftIIC_SDA(1);
    SoftIIC_SCL(1);
    delayus(4);
    SoftIIC_SDA(0);
    delayus(5);
    SoftIIC_SCL(0);
    delayus(4);
}

void SoftIIC_Stop(void)
{
    SoftIIC_SDA(0);
    delayus(4);
    SoftIIC_SCL(1);
    delayus(5);
    SoftIIC_SDA(1);
    delayus(4);
}

void SoftIIC_SendByte(uint8_t txdata)
{
    uint8_t i;
    for(i=0;i<8;i++){
        SoftIIC_SDA(txdata & 0x80);
        delayus(4);
        SoftIIC_SCL(1);
        delayus(4);
        SoftIIC_SCL(0);
        delayus(4);
        txdata<<=1;
    }
}
uint8_t SoftIIC_ReceiveByte(void)
{
    SoftIIC_SDA_Mode(0);
    uint8_t i,rxdata=0;
    for (i = 0; i <8; i++)
    {
        SoftIIC_SCL(1);
        rxdata |= (SoftIIC_READ_SDA<<i);
        delayus(4);
        SoftIIC_SCL(0);
        delayus(4);
    }
    SoftIIC_SDA_Mode(1);
    return rxdata;
}
void SoftIIC_SendACK(bool ack)
{
    SoftIIC_SDA(ack);
    delayus(4);
    SoftIIC_SCL(1);
    delayus(4);
    SoftIIC_SCL(0);
    delayus(4);
}
uint8_t SoftIIC_ReceiveACK(void)
{
    SoftIIC_SDA_Mode(0);
    uint8_t ACK=0;
    SoftIIC_SCL(1);
    delayus(4);
    ACK=SoftIIC_READ_SDA;
    delayus(4);
    SoftIIC_SCL(0);
    delayus(4);
    SoftIIC_SDA_Mode(1);
    return ACK;
}
// /**
//  * @brief 以阻塞模式发送大量数据
//  *
//  * @param pTxData 指向传输数据缓冲区的指针
//  * @param Size 要发送的数据量
//  */
// void SoftIIC_SendByte(uint8_t *pTxData, uint16_t Size)
// {
//     uint8_t i, j;
//     for (i = 0; i <Size; i++)
//     {
//         for (j = 0; j < 8; j++)
//         {
//             SoftIIC_MOSI((pTxData[i]<<j) & 0x80 );
//             SoftIIC_SCLK(1);
//             SoftIIC_SCLK(0);
//         }
//     }
// }
// /**
//  * @brief 以阻塞模式接收大量数据
//  *
//  * @param pRxdata 指向接收数据缓冲区的指针
//  * @param Size 要接收的数据量
//  */
// void SoftIIC_ReceiveByte(uint8_t *pRxData, uint16_t Size)
// {
//     uint8_t i, j;
//     for (i = 0; i < Size; i++)
//     {
//         for (j = 0; j < 8; j++)
//         {
//             SoftIIC_SCLK(1);
//             pRxData[i] |= (SoftIIC_MISO<<(7-j));
//             SoftIIC_SCLK(0);
//         }
//     }
// }
// /**
//  * @brief 以阻塞模式发送和接收大量数据
//  *
//  * @param pTxData 指向传输数据缓冲区的指针
//  * @param pRxData 指向接收数据缓冲区的指针
//  * @param Size 要发送和接收的数据量
//  */
// void SoftIIC_SendReceiveByte(uint8_t *pTxData, uint8_t *pRxData, uint16_t Size)
// {
//     uint8_t i,j;
//     for (i = 0; i < Size; i++)
//     {
//         pRxData[i]=0;
//         for (j = 0; j < 8; j++)
//         {
//             SoftIIC_MOSI((pTxData[i]<<j) & 0x80);
//             SoftIIC_SCLK(1);
//             pRxData[i] |= (SoftIIC_MISO<<(7-j));
//             SoftIIC_SCLK(0);
//         }
//     }
// }

// uint8_t SoftIIC_SendReceive(uint8_t TxData){
//     uint8_t i;
//     for (i = 0; i <8; i++)
//     {
//         SoftIIC_MOSI(TxData & 0x80);
//         SoftIIC_SCLK(1);
//         TxData<<=1;
//         TxData |=SoftIIC_MISO;
//         SoftIIC_SCLK(0);
//     }
//     return TxData;
// }
