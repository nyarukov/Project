#include "bsp_soft_i2c.h"

//I2C_Status SoftI2C_Init(SoftI2C *si2c,
//                        uint8_t device_address,
//                        I2C_HardwareControl hw_control)
//{
//    if (si2c == NULL)
//    {
//        return I2C_ERROR;
//    }
//    si2c->address = device_address;
//    si2c->hw = hw_control;

//    si2c->hw.init();
//    return I2C_SUCCESS;
//}

///**
// * @brief 发送软件I2C起始信号
// */
//void Soft_I2C_Start(SoftI2C *_si2c)
//{
//    _si2c->hw.set_sda(1);
//    _si2c->hw.set_scl(1);
//    _si2c->hw.delay_us();
//    _si2c->hw.set_sda(0);
//    _si2c->hw.delay_us();
//    _si2c->hw.set_scl(0);
//    _si2c->hw.delay_us();
//}

///**
// * @brief 发送软件I2C停止信号
// */
//void Soft_I2C_Stop(SoftI2C *_si2c)
//{
//    _si2c->hw.set_sda(0);
//    _si2c->hw.delay_us();
//    _si2c->hw.set_scl(1);
//    _si2c->hw.delay_us();
//    _si2c->hw.set_sda(1);
//    _si2c->hw.delay_us();
//}
///**
// * @brief 发送I2C ACK信号
// *
// * @param ack 是否发送ACK，1表示发送ACK，0表示发送NACK
// */
//void Soft_I2C_SendACK(SoftI2C *_si2c, bool ack)
//{
//    _si2c->hw.set_sda(ack);
//    _si2c->hw.delay_us();
//    _si2c->hw.set_scl(1);
//    _si2c->hw.delay_us();
//    _si2c->hw.set_scl(0);
//    _si2c->hw.delay_us();
//}

///**
// * @brief 接收I2C ACK信号
// *
// * @return uint8_t 接收到的ACK信号，1表示收到ACK，0表示收到NACK
// */
//uint8_t Soft_I2C_ReceiveACK(SoftI2C *_si2c)
//{
//    _si2c->hw.set_sda_mode(0);
//    uint8_t ACK = 0;
//    _si2c->hw.set_scl(1);
//    _si2c->hw.delay_us();
//    ACK = _si2c->hw.read_sda();
//    _si2c->hw.delay_us();
//    _si2c->hw.set_scl(0);
//    _si2c->hw.delay_us();
//    _si2c->hw.set_sda_mode(1);
//    return ACK;
//}

///**
// * @brief 向I2C总线发送一个字节
// *
// * @param txdata 要发送的字节数据
// */
//void Soft_I2C_SendByte(SoftI2C *_si2c, uint8_t txdata)
//{
//    uint8_t i;
//    for (i = 0; i < 8; i++)
//    {
//        _si2c->hw.set_sda(txdata & 0x80);
//        _si2c->hw.delay_us();
//        _si2c->hw.set_scl(1);
//        _si2c->hw.delay_us();
//        _si2c->hw.set_scl(0);
//        _si2c->hw.delay_us();
//        txdata <<= 1;
//    }
//}
///**
// * @brief 向 I2C 总线发送多个字节
// *
// * @param _si2c I2C 设备结构体
// * @param pData 要发送的数据缓冲区
// * @param len 发送长度
// * @return I2C_Status 操作状态
// */
//I2C_Status Soft_I2C_SendBytes(SoftI2C *_si2c, const uint8_t *pData, uint8_t len)
//{
//    // 循环发送数据
//    for (uint8_t i = 0; i < len; i++)
//    {
//        Soft_I2C_SendByte(_si2c, pData[i]);
//        // 检查接收到的 ACK 信号
//        if (!Soft_I2C_ReceiveACK(_si2c))
//        {
//            // 如果没有收到 ACK，返回 I2C_NACK
//            return I2C_NACK;
//        }
//    }
//    // 数据发送成功，返回 I2C_SUCCESS
//    return I2C_SUCCESS;
//}

/**
 * @brief 从I2C总线接收一个字节
 *
 * @return uint8_t 接收到的字节数据
 */
//uint8_t Soft_I2C_ReceiveByte(SoftI2C *_si2c)
//{
//    _si2c->hw.set_sda_mode(0);
//    uint8_t i, rxdata = 0;
//    for (i = 0; i < 8; i++)
//    {
//        _si2c->hw.set_scl(1);
//        rxdata <<= 1;
//        rxdata |= _si2c->hw.read_sda();
//        _si2c->hw.delay_us();
//        _si2c->hw.set_scl(0);
//        _si2c->hw.delay_us();
//    }
//    _si2c->hw.set_sda_mode(1);
//    return rxdata;
//}

///**
// * @brief 从 I2C 总线接收多个字节
// *
// * @param _si2c I2C 设备结构体
// * @param pData 接收数据缓冲区
// * @param len 接收长度
// * @return I2C_Status 操作状态
// */
//I2C_Status Soft_I2C_ReceiveBytes(SoftI2C *_si2c, uint8_t *pData, uint8_t len)
//{
//    _si2c->hw.set_sda_mode(0);
//    uint8_t i, j;
//    for (i = 0; i < len; i++)
//    {
//        uint8_t rxdata = 0;
//        for (j = 0; j < 8; j++)
//        {
//            _si2c->hw.set_scl(1);
//            rxdata <<= 1;
//            rxdata |= _si2c->hw.read_sda();
//            _si2c->hw.delay_us();
//            _si2c->hw.set_scl(0);
//            _si2c->hw.delay_us();
//        }
//        pData[i] = rxdata;
//        _si2c->hw.set_sda_mode(1);
//        if (i == len - 1)
//        {
//            Soft_I2C_SendACK(_si2c, 1);
//        }
//        else
//        {
//            Soft_I2C_SendACK(_si2c, 0);
//            _si2c->hw.set_sda_mode(0);
//        }
//    }
//    _si2c->hw.set_sda_mode(1);
//    // 数据接收成功，返回 I2C_SUCCESS
//    return I2C_SUCCESS;
//}

///**
// * @brief 检测 I2C 设备是否应答给定地址
// *
// * @param _si2c I2C 结构体指针
// * @param _Addr I2C 设备地址
// * @return I2C_Status I2C 操作状态
// */
//I2C_Status Soft_I2C_AddrCheck(SoftI2C *_si2c, uint8_t _Addr)
//{
//    Soft_I2C_Start(_si2c);
//    Soft_I2C_SendByte(_si2c, _Addr);
//    _si2c->hw.set_sda_mode(0);
//    bool ack_received = Soft_I2C_ReceiveACK(_si2c);
//    _si2c->hw.set_sda_mode(1);
//    Soft_I2C_Stop(_si2c);
//    if (ack_received)
//    {
//        return I2C_SUCCESS;
//    }
//    else
//    {
//        return I2C_NACK;
//    }
//}

///**
// * @brief 在 I2C 总线上连续写入数据
// *
// * @param si2c I2C 结构体指针
// * @param device_address 设备地址
// * @param data 要写入的数据
// * @param length 数据长度
// * @return I2C_Status 操作状态
// */
//I2C_Status Soft_I2C_Write(SoftI2C *si2c, uint8_t _Addr, uint8_t _Reg_Addr, uint8_t *_pBuf, uint16_t _Size)
//{

//    return I2C_SUCCESS;
//}

///**
// * @brief 从 I2C 总线连续读取数据
// *
// * @param _si2c
// * @param device_address
// * @param buffer
// * @param length
// * @return I2C_Status 操作状态
// */
//I2C_Status Soft_I2C_Read(SoftI2C *_si2c, uint8_t device_address, uint8_t *buffer, uint16_t length)
//{

//    return I2C_SUCCESS;
//}
