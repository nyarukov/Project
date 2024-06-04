/*
 * 项目名称: modbus_slave
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-01
 * 最后修改日期: 2024-06-01 18:09:50
 * 描述: MODBUS从机协议
 */

#include "modbus_slave.h"

// C 文件内容...

Modbus_Slave_t Ms_Response;

static void Modbus_AnalyzeApp(uint8_t *_pBuf);

static void Modbus_Error(uint8_t *_pBuf);
static void Modbus_SendData(uint16_t dataLength);

static void Modbus_01H(uint8_t *_pBuf);
static void Modbus_02H(uint8_t *_pBuf);
static void Modbus_03H(uint8_t *_pBuf);
static void Modbus_04H(uint8_t *_pBuf);
static void Modbus_05H(uint8_t *_pBuf);
static void Modbus_06H(uint8_t *_pBuf);
static void Modbus_10H(uint8_t *_pBuf);

void Modbus_Slave(uint8_t *_pBuf, uint16_t _Len)
{
    uint16_t crc;
    uint16_t receivecrc;
    if (_pBuf[0] != MODBUS_ADDRESS)
    {
        return;
    }
    crc = Check_Modbus_CRC16(_pBuf, _Len - 2);
    receivecrc = (_pBuf[_Len - 1] << 8) | (_pBuf[_Len - 2]);
    if (crc == receivecrc)
        Modbus_AnalyzeApp(_pBuf);
    else
        Modbus_Error(_pBuf);
}

static void Modbus_Error(uint8_t *_pBuf)
{
    uint16_t crc;
    uint8_t sendbuff[5];
    sendbuff[0] = _pBuf[0];                // Modbus 设备地址
    sendbuff[1] = 0x80 | _pBuf[1];         // 功能码的响应码
    sendbuff[2] = 0;                       // 异常码
    crc = Check_Modbus_CRC16(sendbuff, 3); // 计算 CRC 校验值
    sendbuff[3] = (uint8_t)(crc >> 8);     // CRC 校验值高位
    sendbuff[4] = (uint8_t)crc;            // CRC 校验值低位
    Uart_SendData(COM2, sendbuff, 5);      // 发送异常响应数据
}

static void Modbus_SendData(uint16_t dataLength)
{
    Ms_Response.crc = Check_Modbus_CRC16(Ms_Response.buffer, dataLength);

    Ms_Response.buffer[dataLength] = LOW_BYTE(Ms_Response.crc);
    Ms_Response.buffer[dataLength + 1] = HIGH_BYTE(Ms_Response.crc);

    Uart_SendData(COM2, Ms_Response.buffer, dataLength + 2);
}

static void Modbus_AnalyzeApp(uint8_t *_pBuf)
{
    switch (_pBuf[1])
    {
    case 0x01: // 读取线圈状态（读取开关量输入状态）
        Modbus_01H(_pBuf);
        break;
    case 0x02: // 读取输入状态（读取开关量输出状态）
        Modbus_02H(_pBuf);
        break;
    case 0x03: // 读取保持寄存器（读取存储的数据）
        Modbus_03H(_pBuf);
        break;
    case 0x04: // 读取输入寄存器（读取存储的数据）
        Modbus_04H(_pBuf);
        break;
    case 0x05: // 强制单线圈（控制开关量输出）
        Modbus_05H(_pBuf);
        break;
    case 0x06: // 写单个保持寄存器（控制存储的数据）
        Modbus_06H(_pBuf);
        break;
    case 0x10: // 写多个保持寄存器（控制存储的数据）
        Modbus_10H(_pBuf);
        break;
    default:
        Modbus_Error(_pBuf);
        break;
    }
}

// 读取线圈状态（读取开关量输入状态）
void Modbus_01H(uint8_t *_pBuf)
{
    /*
        主机发送:
            11 从机地址
            01 功能码
            00 寄存器起始地址高字节
            13 寄存器起始地址低字节
            00 寄存器数量高字节
            25 寄存器数量低字节
            0E CRC校验高字节
            84 CRC校验低字节

        从机应答: 	1代表ON，0代表OFF。若返回的线圈数不为8的倍数，则在最后数据字节未尾使用0代替. BIT0对应第1个
            11 从机地址
            01 功能码
            05 返回字节数
            CD 数据1(线圈0013H-线圈001AH)
            6B 数据2(线圈001BH-线圈0022H)
            B2 数据3(线圈0023H-线圈002AH)
            0E 数据4(线圈0032H-线圈002BH)
            1B 数据5(线圈0037H-线圈0033H)
            45 CRC校验高字节
            E6 CRC校验低字节
    */

    mem_set((char *)&Ms_Response, 0, sizeof(Modbus_Slave_t));
    Ms_Response.reg_addr = LEBufToUint16(_pBuf[2], _pBuf[3]);
    Ms_Response.reg_count = LEBufToUint16(_pBuf[4], _pBuf[5]);

    Ms_Response.reg_length = (Ms_Response.reg_count + 7) >> 3;

    Ms_Response.buffer[0] = _pBuf[0];
    Ms_Response.buffer[1] = _pBuf[1];
    Ms_Response.buffer[2] = Ms_Response.reg_length;

    uint8_t i;
    for (i = 0; i < Ms_Response.reg_count; i++)
    {
        // Ms_Response.reg_val = Modbus_01H_Callback(Ms_Response.reg_addr + i);
        Ms_Response.reg_val = DI.DI_This[i % 8];
        Ms_Response.buffer[3 + (i >> 3)] |= (LOW_BYTE(Ms_Response.reg_val) << (i % 8));
    }

    Modbus_SendData(3 + Ms_Response.reg_length);
}

// 读取离散输入状态（读取开关量输出状态）
void Modbus_02H(uint8_t *_pBuf)
{
    /*
    主机发送:
        11 从机地址
        02 功能码
        00 寄存器地址高字节
        C4 寄存器地址低字节
        00 寄存器数量高字节
        16 寄存器数量低字节
        BA CRC校验高字节
        A9 CRC校验低字节

    从机应答:  响应各离散输入寄存器状态，分别对应数据区中的每位值，1 代表ON；0 代表OFF。
               第一个数据字节的LSB(最低字节)为查询的寻址地址，其他输入口按顺序在该字节中由低字节
               向高字节排列，直到填充满8位。下一个字节中的8个输入位也是从低字节到高字节排列。
               若返回的输入位数不是8的倍数，则在最后的数据字节中的剩余位至该字节的最高位使用0填充。
        11 从机地址
        02 功能码
        03 返回字节数
        AC 数据1(00C4H-00CBH)
        DB 数据2(00CCH-00D3H)
        35 数据3(00D4H-00D9H)
        20 CRC校验高字节
        18 CRC校验低字节
    */
    mem_set((char *)&Ms_Response, 0, sizeof(Modbus_Slave_t));
    Ms_Response.reg_addr = LEBufToUint16(_pBuf[2], _pBuf[3]);
    Ms_Response.reg_count = LEBufToUint16(_pBuf[4], _pBuf[5]);

    Ms_Response.reg_length = (Ms_Response.reg_count + 7) >> 3;

    Ms_Response.buffer[0] = _pBuf[0];
    Ms_Response.buffer[1] = _pBuf[1];
    Ms_Response.buffer[2] = Ms_Response.reg_length;

    uint8_t i;
    for (i = 0; i < Ms_Response.reg_count; i++)
    {
        // Ms_Response.reg_val = Modbus_02H_Callback(Ms_Response.reg_addr + i);
        Ms_Response.reg_val =
            Ms_Response.buffer[3 + (i >> 3)] |= (LOW_BYTE(Ms_Response.reg_val) << (i % 8));
    }
    Modbus_SendData(3 + Ms_Response.reg_length);
}

// 读取保持寄存器（读取存储的数据）
void Modbus_03H(uint8_t *_pBuf)
{
    /*
        主机发送:
            11 从机地址
            03 功能码
            00 寄存器地址高字节
            6B 寄存器地址低字节
            00 寄存器数量高字节
            03 寄存器数量低字节
            76 CRC高字节
            87 CRC低字节

        从机应答: 	保持寄存器的长度为2个字节。对于单个保持寄存器而言，寄存器高字节数据先被传输，
                    低字节数据后被传输。保持寄存器之间，低地址寄存器先被传输，高地址寄存器后被传输。
            11 从机地址
            03 功能码
            06 字节数
            00 数据1高字节(006BH)
            6B 数据1低字节(006BH)
            00 数据2高字节(006CH)
            13 数据2 低字节(006CH)
            00 数据3高字节(006DH)
            00 数据3低字节(006DH)
            38 CRC高字节
            B9 CRC低字节
    */

    mem_set((char *)&Ms_Response, 0, sizeof(Modbus_Slave_t));
    Ms_Response.reg_addr = LEBufToUint16(_pBuf[2], _pBuf[3]);
    Ms_Response.reg_count = LEBufToUint16(_pBuf[4], _pBuf[5]);
    Ms_Response.reg_length = Ms_Response.reg_count << 1;

    Ms_Response.buffer[0] = _pBuf[0];
    Ms_Response.buffer[1] = _pBuf[1];
    Ms_Response.buffer[2] = Ms_Response.reg_length;

    uint8_t i;
    for (i = 0; i < Ms_Response.reg_count; i++)
    {
        // Ms_Response.reg_val = Modbus_03H_Callback(Ms_Response.reg_addr + (i << 1));
        Ms_Response.buffer[3 + (i << 1)] = HIGH_BYTE(Ms_Response.reg_val);
        Ms_Response.buffer[4 + (i << 1)] = LOW_BYTE(Ms_Response.reg_val);
    }

    Modbus_SendData(3 + Ms_Response.reg_length);
}

// 读取输入寄存器（读取存储的数据）
void Modbus_04H(uint8_t *_pBuf)
{
    /*
        主机发送:
            11 从机地址
            04 功能码
            00 寄存器起始地址高字节
            08 寄存器起始地址低字节
            00 寄存器个数高字节
            02 寄存器个数低字节
            F2 CRC高字节
            99 CRC低字节

        从机应答:  输入寄存器长度为2个字节。对于单个输入寄存器而言，寄存器高字节数据先被传输，
                低字节数据后被传输。输入寄存器之间，低地址寄存器先被传输，高地址寄存器后被传输。
            11 从机地址
            04 功能码
            04 字节数
            00 数据1高字节(0008H)
            0A 数据1低字节(0008H)
            00 数据2高字节(0009H)
            0B 数据2低字节(0009H)
            8B CRC高字节
            80 CRC低字节
    */
    mem_set((char *)&Ms_Response, 0, sizeof(Modbus_Slave_t));
    Ms_Response.reg_addr = LEBufToUint16(_pBuf[2], _pBuf[3]);
    Ms_Response.reg_count = LEBufToUint16(_pBuf[4], _pBuf[5]);
    Ms_Response.reg_length = Ms_Response.reg_count << 1;

    Ms_Response.buffer[0] = _pBuf[0];
    Ms_Response.buffer[1] = _pBuf[1];
    Ms_Response.buffer[2] = Ms_Response.reg_length;

    uint8_t i;
    for (i = 0; i < Ms_Response.reg_count; i++)
    {
        // Ms_Response.reg_val = Modbus_04H_Callback(Ms_Response.reg_addr + (i << 1));
        Ms_Response.buffer[3 + (i << 1)] = HIGH_BYTE(Ms_Response.reg_val);
        Ms_Response.buffer[4 + (i << 1)] = LOW_BYTE(Ms_Response.reg_val);
    }
    Modbus_SendData(3 + Ms_Response.reg_length);
}

// 写单个输出线圈（控制开关量输出）
void Modbus_05H(uint8_t *_pBuf)
{
    /*
        主机发送:
            11 从机地址
            05 功能码
            00 寄存器地址高字节
            AC 寄存器地址低字节
            FF 数据1高字节
            00 数据2低字节
            4E CRC校验高字节
            8B CRC校验低字节

        从机应答:
            11 从机地址
            05 功能码
            00 寄存器地址高字节
            AC 寄存器地址低字节
            FF 寄存器1高字节
            00 寄存器1低字节
            4E CRC校验高字节
            8B CRC校验低字节
    */
    mem_set((char *)&Ms_Response, 0, sizeof(Modbus_Slave_t));
    Ms_Response.reg_addr = LEBufToUint16(_pBuf[2], _pBuf[3]);
    Ms_Response.reg_val = LEBufToUint16(_pBuf[4], _pBuf[5]);

    mem_cpy(Ms_Response.buffer, _pBuf, 6);

    // Modbus_05H_Callback(Ms_Response.reg_addr, Ms_Response.reg_val);
    Modbus_SendData(6);
}

// 写单个保持寄存器（控制存储的数据）
void Modbus_06H(uint8_t *_pBuf)
{
    /*
        主机发送:
            11 从机地址
            06 功能码
            00 寄存器地址高字节
            01 寄存器地址低字节
            00 数据1高字节
            01 数据1低字节
            9A CRC校验高字节
            9B CRC校验低字节

        从机响应:
            11 从机地址
            06 功能码
            00 寄存器地址高字节
            01 寄存器地址低字节
            00 数据1高字节
            01 数据1低字节
            1B CRC校验高字节
            5A	CRC校验低字节
    */
    Ms_Response.reg_addr = LEBufToUint16(_pBuf[2], _pBuf[3]);
    Ms_Response.reg_val = LEBufToUint16(_pBuf[4], _pBuf[5]);

    mem_cpy(Ms_Response.buffer, _pBuf, 6);

    // Modbus_06H_Callback(Ms_Response.reg_addr, Ms_Response.reg_val);
    Modbus_SendData(6);
}

// 写多个保持寄存器（控制存储的数据）
void Modbus_10H(uint8_t *_pBuf)
{
    /*
        主机发送:
            11 从机地址
            10 功能码
            00 寄存器起始地址高字节
            01 寄存器起始地址低字节
            00 寄存器数量高字节
            02 寄存器数量低字节
            04 字节数
            00 数据1高字节
            0A 数据1低字节
            01 数据2高字节
            02 数据2低字节
            C6 CRC校验高字节
            F0 CRC校验低字节

        从机响应:
            11 从机地址
            06 功能码
            00 寄存器地址高字节
            01 寄存器地址低字节
            00 数据1高字节
            01 数据1低字节
            1B CRC校验高字节
            5A	CRC校验低字节
    */

    Ms_Response.reg_addr = LEBufToUint16(_pBuf[2], _pBuf[3]);
    Ms_Response.reg_count = LEBufToUint16(_pBuf[4], _pBuf[5]);

    Ms_Response.reg_length = Ms_Response.reg_count << 1;

    mem_cpy(Ms_Response.buffer, _pBuf, 6);

    uint8_t i;
    for (i = 0; i < Ms_Response.reg_count; i++)
    {
        Ms_Response.reg_val = LEBufToUint16(_pBuf[7 + (i << 1)], _pBuf[8 + (i << 1)]);
        // Modbus_10H_Callback(Ms_Response.reg_addr + (i << 1), Ms_Response.reg_val);
    }
    Modbus_SendData(6);
}
