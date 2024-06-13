#include "bsp_soft_i2c.h"

#define Soft_I2C_PORT        GPIOB
#define Soft_I2C_SCL_Pin     8
#define Soft_I2C_SDA_Pin     9

#define Soft_I2C_SCL(n)        ((n)? __GPIO_SET_BIT(Soft_I2C_PORT,Soft_I2C_SCL_Pin):__GPIO_RESET_BIT(Soft_I2C_PORT,Soft_I2C_SCL_Pin))
#define Soft_I2C_SDA(n)        ((n)? __GPIO_SET_BIT(Soft_I2C_PORT,Soft_I2C_SDA_Pin):__GPIO_RESET_BIT(Soft_I2C_PORT,Soft_I2C_SDA_Pin))
#define Soft_I2C_READ_SDA      (__GPIO_IN_READ(Soft_I2C_PORT,Soft_I2C_SDA_Pin))
#define Soft_I2C_SDA_Mode(n)   ((n)? __GPIO_OUTPUT(Soft_I2C_PORT,Soft_I2C_SDA_Pin):__GPIO_INPUT(Soft_I2C_PORT,Soft_I2C_SDA_Pin))

/**
 * @brief 初始化软件I2C
 */
void Soft_I2C_Init(void)
{
    GPIO_InitTypeDef Soft_I2CStruct;
    __HAL_RCC_GPIOB_CLK_ENABLE();
    Soft_I2CStruct.Pin = (1 << Soft_I2C_SCL_Pin) | (1 << Soft_I2C_SDA_Pin);
    Soft_I2CStruct.Mode = GPIO_MODE_OUTPUT_OD;
    Soft_I2CStruct.Pull = GPIO_NOPULL;
    Soft_I2CStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(Soft_I2C_PORT, &Soft_I2CStruct);
    __GPIO_SET_BIT(Soft_I2C_PORT, Soft_I2C_SCL_Pin);
    __GPIO_SET_BIT(Soft_I2C_PORT, Soft_I2C_SDA_Pin);
    
}

/**
 * @brief 发送软件I2C起始信号
 */
void Soft_I2C_Start(void)
{
    Soft_I2C_SDA(1);
    Soft_I2C_SCL(1);
    Delay_Us(4);
    Soft_I2C_SDA(0);
    Delay_Us(5);
    Soft_I2C_SCL(0);
    Delay_Us(4);
}

/**
 * @brief 发送软件I2C停止信号
 */
void Soft_I2C_Stop(void)
{
    Soft_I2C_SDA(0);
    Delay_Us(4);
    Soft_I2C_SCL(1);
    Delay_Us(5);
    Soft_I2C_SDA(1);
    Delay_Us(4);
}

/**
 * @brief 向I2C总线发送一个字节
 *
 * @param txdata 要发送的字节数据
 */
void Soft_I2C_SendByte(uint8_t txdata)
{
    uint8_t i;
    for (i = 0; i < 8; i++)
    {
        Soft_I2C_SDA(txdata & 0x80);
        Delay_Us(4);
        Soft_I2C_SCL(1);
        Delay_Us(4);
        Soft_I2C_SCL(0);
        Delay_Us(4);
        txdata <<= 1;
    }
}

/**
 * @brief 从I2C总线接收一个字节
 *
 * @return uint8_t 接收到的字节数据
 */
uint8_t Soft_I2C_ReceiveByte(void)
{
    Soft_I2C_SDA_Mode(0);
    uint8_t i, rxdata = 0;
    for (i = 0; i < 8; i++)
    {
        Soft_I2C_SCL(1);
        rxdata<<=1;
        rxdata |=Soft_I2C_READ_SDA;
        Delay_Us(4);
        Soft_I2C_SCL(0);
        Delay_Us(4);
    }
    Soft_I2C_SDA_Mode(1);
    return rxdata;
}

/**
 * @brief 从I2C总线接收len个字节
 *
 * @param pData 接收数据缓冲区
 * @param len 接收长度
 */
void Soft_I2C_ReceiveBytes(uint8_t *pData, uint8_t len)
{
    Soft_I2C_SDA_Mode(0);
    uint8_t i, j;
    for (i = 0; i < len; i++)
    {
        uint8_t rxdata = 0;
        for (j = 0; j < 8; j++)
        {
            Soft_I2C_SCL(1);
            rxdata<<=1;
            rxdata |= Soft_I2C_READ_SDA;
            Delay_Us(4);
            Soft_I2C_SCL(0);
            Delay_Us(4);     
        }
        pData[i] = rxdata;
        Soft_I2C_SDA_Mode(1);
        if (i == len - 1)
        {
            Soft_I2C_SendACK(1);
        }
        else
        {
            Soft_I2C_SendACK(0);
            Soft_I2C_SDA_Mode(0);
        }
    }
    Soft_I2C_SDA_Mode(1);
}

/**
 * @brief 发送I2C ACK信号
 *
 * @param ack 是否发送ACK，true表示发送ACK，false表示发送NACK
 */
void Soft_I2C_SendACK(bool ack)
{
    Soft_I2C_SDA(ack);
    Delay_Us(4);
    Soft_I2C_SCL(1);
    Delay_Us(4);
    Soft_I2C_SCL(0);
    Delay_Us(4);
}

/**
 * @brief 接收I2C ACK信号
 *
 * @return uint8_t 接收到的ACK信号，1表示收到ACK，0表示收到NACK
 */
uint8_t Soft_I2C_ReceiveACK(void)
{
    Soft_I2C_SDA_Mode(0);
    uint8_t ACK = 0;
    Soft_I2C_SCL(1);
    Delay_Us(4);
    ACK = Soft_I2C_READ_SDA;
    Delay_Us(4);
    Soft_I2C_SCL(0);
    Delay_Us(4);
    Soft_I2C_SDA_Mode(1);
    return ACK;
}

/**
 * @brief 检测I2C设备是否应答
 * 
 * @param _Addr I2C地址
 * @return uint8_t 
 */
uint8_t Soft_I2C_AddrCheck(uint8_t _Addr){
    uint8_t ACK;
    Soft_I2C_SDA_Mode(1);
    Soft_I2C_Start();
    Soft_I2C_SendByte(_Addr);
    Soft_I2C_SDA_Mode(0);
    ACK=Soft_I2C_ReceiveACK();
    Soft_I2C_SDA_Mode(1);
    Soft_I2C_Stop();
    
    return ACK;
}
