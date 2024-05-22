#include "bsp_soft_spi.h"

#define Soft_SPI_PORT GPIOA
#define Soft_SPI_CS_Pin GPIO_PIN_4
#define Soft_SPI_SCLK_Pin GPIO_PIN_5
#define Soft_SPI_MISO_Pin GPIO_PIN_6
#define Soft_SPI_MOSI_Pin GPIO_PIN_7

#define Soft_SPI_SCLK(n) ((n) ? __GPIO_SET_BIT(Soft_SPI_PORT, 5) : __GPIO_RESET_BIT(Soft_SPI_PORT, 5))
#define Soft_SPI_MOSI(n) ((n) ? __GPIO_SET_BIT(Soft_SPI_PORT, 7) : __GPIO_RESET_BIT(Soft_SPI_PORT, 7))
#define Soft_SPI_MISO (__GPIO_IN_READ(Soft_SPI_PORT, 6))

void Soft_SPI_Init(void)
{

    GPIO_InitTypeDef SpiStruct;
    __HAL_RCC_GPIOA_CLK_ENABLE();
    SpiStruct.Pin = Soft_SPI_CS_Pin | Soft_SPI_SCLK_Pin | Soft_SPI_MOSI_Pin;
    SpiStruct.Mode = GPIO_MODE_OUTPUT_PP;
    SpiStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(Soft_SPI_PORT, &SpiStruct);
    __GPIO_SET_BIT(Soft_SPI_PORT, GPIO_PIN_4);

    SpiStruct.Pin = Soft_SPI_MISO_Pin;
    SpiStruct.Mode = GPIO_MODE_INPUT;
    SpiStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(Soft_SPI_PORT, &SpiStruct);
}
/**
 * @brief 使用软件 SPI 发送一个字节。
 *
 * @param _Byte 要发送的字节。
 */
void Soft_SPI_Transmit(uint8_t _Byte)
{
    uint8_t i;
    for (i = 0; i < 8; i++)
    {
        Soft_SPI_MOSI(_Byte & 0x80);
        _Byte <<= 1;
        Soft_SPI_SCLK(1);
        Soft_SPI_SCLK(0);
        
    }
}

/**
 * @brief 使用软件 SPI 接收一个字节。
 *
 * @return uint8_t 接收到的字节。
 */
uint8_t Soft_SPI_Receive(void)
{
    uint8_t i;
    uint8_t RxByte;
    for (i = 0; i < 8; i++)
    {
        RxByte <<= 1;
        Soft_SPI_SCLK(1);
        RxByte |= Soft_SPI_MISO;
        Soft_SPI_SCLK(0);
    }
    return RxByte;
}
/**
 * @brief 使用软件 SPI 同时发送和接收一个字节。
 *
 * @param _Byte 要发送的字节。
 * @return uint8_t 接收到的字节。
 */
uint8_t Soft_SPI_TransmitReceive(uint8_t _Byte)
{
    uint8_t i;
    for (i = 0; i < 8; i++)
    {
        Soft_SPI_MOSI(_Byte & 0x80);
        _Byte <<= 1;
        Soft_SPI_SCLK(1);
        _Byte |= Soft_SPI_MISO;
        Soft_SPI_SCLK(0);
        
    }
    return _Byte;
}
