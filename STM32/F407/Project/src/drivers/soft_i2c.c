/*
 * 项目名称: soft_i2c
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-01
 * 最后修改日期: 2024-06-01 18:09:50
 * 描述: 软件I2C驱动
 */

#include "soft_i2c.h"

#if (I2C_COUNT > 0)
// C 文件内容...

typedef struct I2C_Config
{
    uint8_t SCL_IO;
    uint8_t SDA_IO;
    uint8_t Mode;
    uint8_t Slave_Addr;  // 作为从机的地址
    uint8_t Slave_Count; // 作为主机时从机的数量
    uint32_t Clock_Speed;
} I2C_Config;

typedef struct I2C_Slave_Config
{
    uint8_t Addr;
    Buffer_t Rx_Buf;
} I2C_Slave_Config;

#define INIT_CONFIG(SCL, SDA, MODE, Addr,   \
                    SlaveCount, ClockSpeed) \
    {                                       \
        .SCL_IO = SCL,                      \
        .SDA_IO = SDA,                      \
        .Mode = MODE,                       \
        .Slave_Addr = Addr,                 \
        .Slave_Count = SlaveCount,          \
        .Clock_Speed = ClockSpeed           \
    }

// clang-format off
static struct I2C_Config Config[I2C_COUNT] = {
    #if I2C1_EN == 1
        INIT_CONFIG(I2C1_SCL, I2C1_SDA,
                    I2C1_SLAVE_ADDR,
                    I2C1_MODE, I2C1_SLAVE_COUNT,
                    I2C1_CLOCK_SPEED),
    #endif

    #if I2C2_EN == 1
        INIT_CONFIG(I2C2_SCL, I2C2_SDA,
                    I2C2_SLAVE_ADDR,
                    I2C2_MODE, I2C2_SLAVE_COUNT,
                    I2C2_CLOCK_SPEED),
    #endif

    #if I2C3_EN == 1
        INIT_CONFIG(I2C3_SCL, I2C3_SDA,
                    I2C3_SLAVE_ADDR,
                    I2C3_MODE, I2C3_SLAVE_COUNT,
                    I2C3_CLOCK_SPEED),
    #endif

    #if I2C4_EN == 1
        INIT_CONFIG(I2C4_SCL, I2C4_SDA,
                    I2C4_SLAVE_ADDR,
                    I2C4_MODE, I2C4_SLAVE_COUNT,
                    I2C4_CLOCK_SPEED),
    #endif
};

#define I2C_OF(i2c)     (Config[(i2c)])
// clang-format on

static void Soft_I2C_Config(I2C_Config *_Para)
{

    IO_Init(_Para->SCL_IO,
            GPIO_Mode_OUT, GPIO_OType_PP,
            GPIO_PuPd_NOPULL, GPIO_High_Speed);

    IO_Init(_Para->SDA_IO,
            GPIO_Mode_OUT, GPIO_OType_PP,
            GPIO_PuPd_NOPULL, GPIO_High_Speed);

    IO_Write(_Para->SCL_IO, 1);
    IO_Write(_Para->SDA_IO, 1);
}

void Soft_I2C_Init(void)
{
    for (uint8_t i = 0; i < I2C_COUNT; i++)
    {
        Soft_I2C_Config(&I2C_OF(i));
    }
    // clang-format off
    #if I2C1_EN == 1
        _LOG("--> I2C1_BUS_Init!\r\n", NULL);
    #endif

    #if I2C2_EN == 1
        _LOG("--> I2C2_BUS_Init!\r\n", NULL);
    #endif

    #if I2C3_EN == 1
        _LOG("--> I2C3_BUS_Init!\r\n", NULL);
    #endif

    #if I2C4_EN == 1
        _LOG("--> I2C4_BUS_Init!\r\n", NULL);
    #endif
    // clang-format on
}

/**
 * @brief 设置SDA输入/输出
 *
 * @param _ID 总线ID
 * @param _Mode   GPIO_MODE
 */
void Soft_SDA_Mode(I2C_ID _ID, uint8_t _Mode)
{
    I2C_Config *i2c = &I2C_OF(_ID);
    GPIO_TypeDef *GPIO_Tx_IO =
        (GPIO_TypeDef *)GET_PORT(i2c->SDA_IO);
    uint8_t Rx_Pin = i2c->SDA_IO & 0x0F;

    __IO_WRITE_MODE(GPIO_Tx_IO, Rx_Pin, _Mode);
}

/**
 * @brief 启动I2C通信，发送起始信号
 *
 * @param i2c 指向I2C配置结构体的指针
 */
void Soft_I2C_Start(I2C_Config *i2c)
{
    IO_Write(i2c->SDA_IO, 1);
    IO_Write(i2c->SCL_IO, 1);
    soft_delay(i2c->Clock_Speed);

    IO_Write(i2c->SDA_IO, 0);
    soft_delay(i2c->Clock_Speed);

    IO_Write(i2c->SCL_IO, 0);
    soft_delay(i2c->Clock_Speed);
}

/**
 * @brief 停止I2C通信，发送停止信号
 *
 * @param i2c 指向I2C配置结构体的指针
 */
void Soft_I2C_Stop(I2C_Config *i2c)
{
    IO_Write(i2c->SDA_IO, 0);
    IO_Write(i2c->SCL_IO, 1);
    soft_delay(i2c->Clock_Speed);

    IO_Write(i2c->SDA_IO, 1);
    soft_delay(i2c->Clock_Speed);
}

/**
 * @brief 向I2C总线发送一个字节数据
 *
 * @param i2c 指向I2C配置结构体的指针
 * @param _Data 要发送的字节数据
 */
void Soft_I2C_SendByte(I2C_Config *i2c, uint8_t _Data)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        IO_Write(i2c->SDA_IO, _Data & 0x80);
        soft_delay(i2c->Clock_Speed);

        IO_Write(i2c->SCL_IO, 1);
        soft_delay(i2c->Clock_Speed);

        IO_Write(i2c->SCL_IO, 0);
        soft_delay(i2c->Clock_Speed);
        _Data <<= 1;
    }
}

/**
 * @brief 从I2C总线接收一个字节数据
 *
 * @param i2c 指向I2C配置结构体的指针
 * @return uint8_t 接收到的字节数据
 */
uint8_t Soft_I2C_ReceiveByte(I2C_Config *i2c)
{
    uint8_t data = 0;
    for (uint8_t i = 0; i < 8; i++)
    {
        IO_Write(i2c->SCL_IO, 1);
        data <<= 1;
        data |= IO_Read(i2c->SDA_IO);
        soft_delay(i2c->Clock_Speed);

        IO_Write(i2c->SCL_IO, 0);
        soft_delay(i2c->Clock_Speed);
    }
    return data;
}

/**
 * @brief 向I2C总线发送ACK或NACK信号
 *
 * @param i2c 指向I2C配置结构体的指针
 * @param _Ack 发送的ACK信号状态, BF_ACK 或 BF_NACK
 */
void Soft_I2C_SendACK(I2C_Config *i2c, Status _Ack)
{
    IO_Write(i2c->SDA_IO, (_Ack == BF_NACK) ? 1 : 0);
    soft_delay(i2c->Clock_Speed);

    IO_Write(i2c->SCL_IO, 1);
    soft_delay(i2c->Clock_Speed);

    IO_Write(i2c->SCL_IO, 0);
    soft_delay(i2c->Clock_Speed);
}

/**
 * @brief 从I2C总线接收ACK信号
 *
 * @param i2c 指向I2C配置结构体的指针
 * @return Status 返回接收到的ACK信号状态，BF_ACK 或 BF_NACK
 */
Status Soft_I2C_ReceiveACK(I2C_Config *i2c)
{
    IO_Write(i2c->SDA_IO, 1);
    IO_Write(i2c->SCL_IO, 1);
    soft_delay(i2c->Clock_Speed);

    uint8_t ACK = IO_Read(i2c->SDA_IO);

    IO_Write(i2c->SCL_IO, 0);
    soft_delay(i2c->Clock_Speed);

    return (ACK) ? BF_NACK : BF_ACK;
}

/**
 * @brief 检查给定设备地址在I2C总线上是否存在
 *
 * @param _ID I2C总线ID
 * @param _Addr 设备地址
 * @return Status 返回设备地址的存在状态，
 *              BF_ACK 表示存在，BF_NACK 表示不存在
 */
Status Soft_I2C_AddrCheck(I2C_ID _ID, uint8_t _Addr)
{
    I2C_Config *i2c = &I2C_OF(_ID);

    Soft_I2C_Start(i2c);

    Soft_I2C_SendByte(i2c, _Addr);

    Status ACK = Soft_I2C_ReceiveACK(i2c);

    Soft_I2C_Stop(i2c);
    return ACK;
}

/**
 * @brief 扫描I2C总线上存在的设备地址并输出
 *
 * @param _ID I2C总线ID
 */
void Soft_I2C_SacnBus(I2C_ID _ID)
{
    for (size_t i = 0x10; i < 0x7F; i++)
    {
        if (Soft_I2C_AddrCheck(_ID, i << 1) == BF_ACK)
        {
            _LOG("Addr: %#X\r\n", i << 1);
        }
    }
}

/**
 * @brief 向I2C设备写入一个字节数据并检查ACK信号
 *
 * @param _ID I2C总线ID
 * @param _Addr 设备地址
 * @param _RegAddr 寄存器地址
 * @param _Data 要发送的字节数据
 * @return Status 操作状态，BF_OK表示成功，BF_NACK表示ACK失败
 */
Status Soft_I2C_WriteByteWithACK(I2C_ID _ID, uint8_t _Addr,
                                 uint8_t _RegAddr,
                                 uint8_t _Data)
{
    I2C_Config *i2c = &I2C_OF(_ID);

    DISABLE_INT();

    Soft_I2C_Start(i2c);

    Soft_I2C_SendByte(i2c, (_Addr << 1) & I2C_CMD_WRITE);
    if (Soft_I2C_ReceiveACK(i2c) == BF_NACK)
    {
        Soft_I2C_Stop(i2c);
        return BF_NACK;
    }

    Soft_I2C_SendByte(i2c, _RegAddr);
    if (Soft_I2C_ReceiveACK(i2c) == BF_NACK)
    {
        Soft_I2C_Stop(i2c);
        return BF_NACK;
    }

    Soft_I2C_SendByte(i2c, _Data);
    if (Soft_I2C_ReceiveACK(i2c) == BF_NACK)
    {
        Soft_I2C_Stop(i2c);
        return BF_NACK;
    }

    Soft_I2C_Stop(i2c);

    ENABLE_INT();

    return BF_OK;
}

/**
 * @brief 从I2C设备读取一个字节数据并检查ACK信号
 *
 * @param _ID I2C总线ID
 * @param _Addr 设备地址
 * @param _RegAddr 寄存器地址
 * @param _pData 接收数据的指针
 * @return Status 操作状态，BF_OK表示成功，BF_NACK表示ACK失败
 */
Status Soft_I2C_ReadByteWithACK(I2C_ID _ID, uint8_t _Addr,
                                uint8_t _RegAddr,
                                uint8_t *_pData)
{
    I2C_Config *i2c = &I2C_OF(_ID);

    DISABLE_INT();

    Soft_I2C_Start(i2c);

    Soft_I2C_SendByte(i2c, (_Addr << 1) & I2C_CMD_WRITE);
    if (Soft_I2C_ReceiveACK(i2c) == BF_NACK)
    {
        Soft_I2C_Stop(i2c);
        return BF_NACK;
    }

    Soft_I2C_SendByte(i2c, _RegAddr);
    if (Soft_I2C_ReceiveACK(i2c) == BF_NACK)
    {
        Soft_I2C_Stop(i2c);
        return BF_NACK;
    }

    Soft_I2C_Start(i2c);

    Soft_I2C_SendByte(i2c, (_Addr << 1) | I2C_CMD_READ);
    if (Soft_I2C_ReceiveACK(i2c) == BF_NACK)
    {
        Soft_I2C_Stop(i2c);
        return BF_NACK;
    }

    *_pData = Soft_I2C_ReceiveByte(i2c);
    Soft_I2C_SendACK(i2c, BF_NACK);

    Soft_I2C_Stop(i2c);

    ENABLE_INT();

    return BF_OK;
}

/**
 * @brief 向I2C设备写入数据
 *
 * @param _ID I2C总线ID
 * @param _Addr 设备地址
 * @param _RegAddr 寄存器地址
 * @param _pBuf 要写入的数据缓冲区指针
 * @param _Len 数据长度
 * @return Status 操作状态，BF_OK表示成功，BF_NACK表示失败
 */
Status Soft_I2C_Write(I2C_ID _ID, uint8_t _Addr,
                      uint8_t _RegAddr,
                      uint8_t *_pBuf, uint16_t _Len)
{
    I2C_Config *i2c = &I2C_OF(_ID);

    DISABLE_INT();

    Soft_I2C_Start(i2c);

    Soft_I2C_SendByte(i2c, (_Addr << 1) & I2C_CMD_WRITE);
    if (Soft_I2C_ReceiveACK(i2c) == BF_NACK)
    {
        Soft_I2C_Stop(i2c);
        return BF_NACK;
    }

    Soft_I2C_SendByte(i2c, _RegAddr);
    if (Soft_I2C_ReceiveACK(i2c) == BF_NACK)
    {
        Soft_I2C_Stop(i2c);
        return BF_NACK;
    }

    for (uint16_t i = 0; i < _Len; i++)
    {
        Soft_I2C_SendByte(i2c, _pBuf[i]);
        if (Soft_I2C_ReceiveACK(i2c) == BF_NACK)
        {
            Soft_I2C_Stop(i2c);
            return BF_NACK;
        }
    }

    Soft_I2C_Stop(i2c);

    ENABLE_INT();

    return BF_OK;
}

/**
 * @brief 从I2C设备读取数据
 *
 * @param _ID I2C总线ID
 * @param _Addr 设备地址
 * @param _RegAddr 寄存器地址
 * @param _pBuf 接收数据的缓冲区指针
 * @param _Len 要读取的数据长度
 * @return Status 操作状态，BF_OK表示成功，BF_NACK表示失败
 */
Status Soft_I2C_Read(I2C_ID _ID, uint8_t _Addr,
                     uint8_t _RegAddr,
                     uint8_t *_pBuf, uint16_t _Len)
{
    I2C_Config *i2c = &I2C_OF(_ID);

    DISABLE_INT();

    Soft_I2C_Start(i2c);

    Soft_I2C_SendByte(i2c, (_Addr << 1) & I2C_CMD_WRITE);
    if (Soft_I2C_ReceiveACK(i2c) == BF_NACK)
    {
        Soft_I2C_Stop(i2c);
        return BF_NACK;
    }

    Soft_I2C_SendByte(i2c, _RegAddr);
    if (Soft_I2C_ReceiveACK(i2c) == BF_NACK)
    {
        Soft_I2C_Stop(i2c);
        return BF_NACK;
    }

    Soft_I2C_Start(i2c);

    Soft_I2C_SendByte(i2c, (_Addr << 1) | I2C_CMD_READ);
    if (Soft_I2C_ReceiveACK(i2c) == BF_NACK)
    {
        Soft_I2C_Stop(i2c);
        return BF_NACK;
    }

    for (uint16_t i = 0; i < _Len; i++)
    {
        _pBuf[i] = Soft_I2C_ReceiveByte(i2c);
        Soft_I2C_SendACK(i2c, (i < _Len - 1) ? BF_ACK : BF_NACK);
    }

    Soft_I2C_Stop(i2c);

    ENABLE_INT();

    return BF_OK;
}

#endif