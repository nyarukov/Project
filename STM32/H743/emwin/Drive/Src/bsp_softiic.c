#include "bsp_softiic.h"

void us_Delay(u32 t_us) {
    u32 t = (u32)t_us * (480000000 / 1000000);  // 计算循环次数
    while(t--);
}
/**
 * @brief 初始化软件I2C
 */
void SoftIIC_Init(void)
{
    GPIO_InitTypeDef SoftIICStruct;
    __HAL_RCC_GPIOB_CLK_ENABLE();
    SoftIICStruct.Pin = (1 << SoftIIC_SCL_Pin) | (1 << SoftIIC_SDA_Pin);
    SoftIICStruct.Mode = GPIO_MODE_OUTPUT_OD;
    SoftIICStruct.Pull = GPIO_NOPULL;
    SoftIICStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(SoftIIC_PORT, &SoftIICStruct);
    __GPIO_SET_BIT(SoftIIC_PORT, SoftIIC_SCL_Pin);
    __GPIO_SET_BIT(SoftIIC_PORT, SoftIIC_SDA_Pin);
}

/**
 * @brief 发送软件I2C起始信号
 */
void SoftIIC_Start(void)
{
    SoftIIC_SDA(1);
    SoftIIC_SCL(1);
    us_Delay(4);
    SoftIIC_SDA(0);
    us_Delay(5);
    SoftIIC_SCL(0);
    us_Delay(4);
}

/**
 * @brief 发送软件I2C停止信号
 */
void SoftIIC_Stop(void)
{
    SoftIIC_SDA(0);
    us_Delay(4);
    SoftIIC_SCL(1);
    us_Delay(5);
    SoftIIC_SDA(1);
    us_Delay(4);
}

/**
 * @brief 向I2C总线发送一个字节
 *
 * @param txdata 要发送的字节数据
 */
void SoftIIC_SendByte(uint8_t txdata)
{
    uint8_t i;
    for (i = 0; i < 8; i++)
    {
        SoftIIC_SDA(txdata & 0x80);
        us_Delay(4);
        SoftIIC_SCL(1);
        us_Delay(4);
        SoftIIC_SCL(0);
        us_Delay(4);
        txdata <<= 1;
    }
}

/**
 * @brief 从I2C总线接收一个字节
 *
 * @return uint8_t 接收到的字节数据
 */
uint8_t SoftIIC_ReceiveByte(void)
{
    SoftIIC_SDA_Mode(0);
    uint8_t i, rxdata = 0;
    for (i = 0; i < 8; i++)
    {
        SoftIIC_SCL(1);
        rxdata<<=1;
        rxdata |=SoftIIC_READ_SDA;
        us_Delay(4);
        SoftIIC_SCL(0);
        us_Delay(4);
    }
    SoftIIC_SDA_Mode(1);
    return rxdata;
}

/**
 * @brief 从I2C总线接收len个字节
 *
 * @param pData 接收数据缓冲区
 * @param len 接收长度
 */
void SoftIIC_ReceiveBytes(uint8_t *pData, u8 len)
{
    SoftIIC_SDA_Mode(0);
    uint8_t i, j;
    for (i = 0; i < len; i++)
    {
        uint8_t rxdata = 0;
        for (j = 0; j < 8; j++)
        {
            SoftIIC_SCL(1);
            rxdata<<=1;
            rxdata |= SoftIIC_READ_SDA;
            us_Delay(4);
            SoftIIC_SCL(0);
            us_Delay(4);     
        }
        pData[i] = rxdata;
        SoftIIC_SDA_Mode(1);
        if (i == len - 1)
        {
            SoftIIC_SendACK(1);
        }
        else
        {
            SoftIIC_SendACK(0);
            SoftIIC_SDA_Mode(0);
        }
    }
    SoftIIC_SDA_Mode(1);
}

/**
 * @brief 发送I2C ACK信号
 *
 * @param ack 是否发送ACK，true表示发送ACK，false表示发送NACK
 */
void SoftIIC_SendACK(bool ack)
{
    SoftIIC_SDA(ack);
    us_Delay(4);
    SoftIIC_SCL(1);
    us_Delay(4);
    SoftIIC_SCL(0);
    us_Delay(4);
}

/**
 * @brief 接收I2C ACK信号
 *
 * @return uint8_t 接收到的ACK信号，1表示收到ACK，0表示收到NACK
 */
uint8_t SoftIIC_ReceiveACK(void)
{
    SoftIIC_SDA_Mode(0);
    uint8_t ACK = 0;
    SoftIIC_SCL(1);
    us_Delay(4);
    ACK = SoftIIC_READ_SDA;
    us_Delay(4);
    SoftIIC_SCL(0);
    us_Delay(4);
    SoftIIC_SDA_Mode(1);
    return ACK;
}
