#include "bsp_soft_i2c.h"

void Soft_I2C_W_SCL(uint8_t BitValue)
{
    GPIO_WriteBit(GPIOC, GPIO_Pin_12, (BitAction)BitValue);
    Delay_us(10);
}

void Soft_I2C_W_SDA(uint8_t BitValue)
{
    GPIO_WriteBit(GPIOC, GPIO_Pin_11, (BitAction)BitValue);
    Delay_us(10);
}

uint8_t Soft_I2C_R_SDA(void)
{
    uint8_t BitValue;
    BitValue = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_11);
    Delay_us(10);
    return BitValue;
}

void Soft_I2C_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    GPIO_SetBits(GPIOC, GPIO_Pin_12 | GPIO_Pin_11);
}

void Soft_I2C_Start(void)
{
    Soft_I2C_W_SDA(1);
    Soft_I2C_W_SCL(1);
    Soft_I2C_W_SDA(0);
    Soft_I2C_W_SCL(0);
}

void Soft_I2C_Stop(void)
{
    Soft_I2C_W_SDA(0);
    Soft_I2C_W_SCL(1);
    Soft_I2C_W_SDA(1);
}

void Soft_I2C_SendByte(uint8_t Byte)
{
    uint8_t i;
    for (i = 0; i < 8; i++)
    {
        Soft_I2C_W_SDA(Byte & (0x80 >> i));
        Soft_I2C_W_SCL(1);
        Soft_I2C_W_SCL(0);
    }
}

uint8_t Soft_I2C_ReceiveByte(void)
{
    uint8_t i, Byte = 0x00;
    Soft_I2C_W_SDA(1);
    for (i = 0; i < 8; i++)
    {
        Soft_I2C_W_SCL(1);
        if (Soft_I2C_R_SDA() == 1)
        {
            Byte |= (0x80 >> i);
        }
        Soft_I2C_W_SCL(0);
    }
    return Byte;
}

void Soft_I2C_SendAck(uint8_t AckBit)
{
    Soft_I2C_W_SDA(AckBit);
    Soft_I2C_W_SCL(1);
    Soft_I2C_W_SCL(0);
}

uint8_t Soft_I2C_ReceiveAck(void)
{
    uint8_t AckBit;
    Soft_I2C_W_SDA(1);
    Soft_I2C_W_SCL(1);
    AckBit = Soft_I2C_R_SDA();
    Soft_I2C_W_SCL(0);
    return AckBit;
}

uint8_t Soft_I2C_AddrCheck(uint8_t address)
{
    uint8_t ack;
    Soft_I2C_Start();
    Soft_I2C_SendByte(address);
    ack = Soft_I2C_ReceiveAck();
    Soft_I2C_Stop();
    return ack == 0;
}

void Soft_I2C_ScanDevices(void)
{
    for (uint8_t addr = 0x08; addr <= 0x77; addr++)
    {
        if (Soft_I2C_AddrCheck(addr))
        {
            UsartPrintf(USART1, "I2C device found at address: 0x%02X\n", addr);
        }
    }
}
