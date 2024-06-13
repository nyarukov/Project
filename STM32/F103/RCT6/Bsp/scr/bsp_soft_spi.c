#include "bsp_soft_spi.h"

void Soft_SPI_Init(void)
{

    GPIO_InitTypeDef SpiStruct;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    SpiStruct.GPIO_Pin = Soft_SPI_CS_Pin | Soft_SPI_MOSI_Pin | Soft_SPI_SCLK_Pin;
    SpiStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    SpiStruct.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(GPIOA, &SpiStruct);
    Soft_SPI_CS(1);
}
/**
 * @brief 使用软件 SPI 发送一个字节。
 *
 * @param _Byte 要发送的字节。
 */
void Soft_SPI_Transmit(uint8_t _Byte)
{
    uint8_t i;
    Soft_SPI_CS(0);
    for (i = 0; i < 8; i++)
    {
        Soft_SPI_MOSI(_Byte & 0x80);
        _Byte <<= 1;
        Soft_SPI_SCLK(1);
        Soft_SPI_SCLK(0);
    }
    Soft_SPI_CS(1);
}
