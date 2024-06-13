#include "bsp_modbus.h"

static void Modbus_AnalyzeApp(uint8_t *_pBuf);

static void Modbus_Error(uint8_t *_pBuf);

static void Modbus_01H(uint8_t *_pBuf);
static void Modbus_02H(uint8_t *_pBuf);
static void Modbus_03H(uint8_t *_pBuf);
static void Modbus_04H(uint8_t *_pBuf);
static void Modbus_05H(uint8_t *_pBuf);
static void Modbus_06H(uint8_t *_pBuf);
static void Modbus_10H(uint8_t *_pBuf);

void Modbus_check(uint8_t *_pBuf, uint8_t _len)
{
    uint16_t crc;
    uint16_t receivecrc;
    if (_pBuf[0] != MODBUS_ADDRESS)
    {
        return;
    }
    crc = Check_Modbus_CRC16(_pBuf, _len - 2);
    receivecrc = (_pBuf[_len - 1] << 8) | (_pBuf[_len - 2]);
    if (crc == receivecrc)
        Modbus_AnalyzeApp(_pBuf);
    else
        Modbus_Error(_pBuf);
    mem_set((char *)_pBuf, 0, _len);
    Uart1.Cnt = 0;
    Uart1.Flag = 0;
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
    Uart_SendArr(sendbuff, 5);             // 发送异常响应数据
}

static void Modbus_AnalyzeApp(uint8_t *_pBuf)
{
    switch (_pBuf[1])
    {
    case 0x01: // 读取线圈状态（读取开关量输入状态）
        Modbus_01H(_pBuf);
        break;
    case 0x02: // 读取离散输入状态（读取开关量输出状态）
        Modbus_02H(_pBuf);
        break;
    case 0x03: // 读取保持寄存器（读取存储的数据）
        Modbus_03H(_pBuf);
        break;
    case 0x04: // 读取输入寄存器（读取存储的数据）
        Modbus_04H(_pBuf);
        break;
    case 0x05: // 写单个输出线圈（控制开关量输出）
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
                01 从机地址
                01 功能码
                00 寄存器起始地址高字节
                13 寄存器起始地址低字节
                00 寄存器数量高字节
                25 寄存器数量低字节
                0E CRC校验高字节
                84 CRC校验低字节

            从机应答: 	1代表ON，0代表OFF。若返回的线圈数不为8的倍数，则在最后数据字节未尾使用0代替. BIT0对应第1个
                01 从机地址
                01 功能码
                05 返回字节数
                CD 数据1(线圈0013H-线圈001AH)
                6B 数据2(线圈001BH-线圈0022H)
                B2 数据3(线圈0023H-线圈002AH)
                0E 数据4(线圈0032H-线圈002BH)
                1B 数据5(线圈0037H-线圈0033H)
                45 CRC校验高字节
                E6 CRC校验低字节

            例子:
                01 01 10 01 00 03   29 0B	--- 查询D01开始的3个继电器状态
                01 01 10 03 00 01   09 0A   --- 查询D03继电器的状态
        */
    uint16_t register_add = LEBufToUint16(_pBuf[2], _pBuf[3]);
    uint16_t register_count = LEBufToUint16(_pBuf[4], _pBuf[5]);

    uint8_t response_length  = (register_count + 7) / 8;

    uint8_t response[3 + response_length ];
    mem_set((char *)response, 0, 3 + response_length );
    response[0] = _pBuf[0];
    response[1] = _pBuf[1];
    response[2] = response_length ;

    uint16_t i;
    for (i = 0; i < register_count; i++)
    {
        uint8_t led_state = NULL;
        switch (register_add + i)
        {
        case LED1_ADDR:
            led_state = (__GPIO_OUT_READ(GPIOA, 11) ? 0 : 1);
            break;
        case LED2_ADDR:
            led_state = (__GPIO_OUT_READ(GPIOA, 12) ? 0 : 1);
            break;
        case LED3_ADDR:
            led_state = (__GPIO_OUT_READ(GPIOA, 15) ? 0 : 1);
            break;
        }
        response[3 + (i / 8)] |= (led_state << (i % 8));
    }
    uint16_t crc = Check_Modbus_CRC16(response, 3 + response_length );
    response[3 + response_length ] = crc >> 8;
    response[4 + response_length ] = crc & 0xFF;

    Uart_SendArr(response, 5 + response_length );
}

// 读取离散输入状态（读取开关量输出状态）
void Modbus_02H(uint8_t *_pBuf)
{
    /*
            主机发送:
                01 从机地址
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
                01 从机地址
                02 功能码
                03 返回字节数
                AC 数据1(00C4H-00CBH)
                DB 数据2(00CCH-00D3H)
                35 数据3(00D4H-00D9H)
                20 CRC校验高字节
                18 CRC校验低字节

            例子:
            01 02 20 01 00 08  23CC  ---- 读取T01-08的状态
            01 02 20 04 00 02  B3CA  ---- 读取T04-05的状态
            01 02 20 01 00 12  A207   ---- 读 T01-18
        */
    uint16_t register_add = LEBufToUint16(_pBuf[2], _pBuf[3]);
    uint16_t register_count = LEBufToUint16(_pBuf[4], _pBuf[5]);

    uint8_t response_length  = (register_count + 7) / 8;

    uint8_t response[3 + response_length ];
    mem_set((char *)response, 0, 3 + response_length );
    response[0] = _pBuf[0];
    response[1] = _pBuf[1];
    response[2] = response_length ;
    
    uint16_t i;
    for (i = 0; i < register_count; i++)
    {
        uint8_t key_start = NULL;
        switch (register_add + i)
        {
        case KEY1_ADDR:
            key_start = __GPIO_IN_READ(GPIOB, 3);
            break;
        case KEY2_ADDR:
            key_start = __GPIO_IN_READ(GPIOB, 4);
            break;
        case KEY3_ADDR:
            key_start = __GPIO_IN_READ(GPIOB, 5);
            break;
        }
        response[3 + (i / 8)] |= (key_start << (i % 8));
    }
    uint16_t crc = Check_Modbus_CRC16(response, 3 + response_length );
    response[3 + response_length ]=(crc >> 8);
    response[4 + response_length ]=(crc & 0xFF);

    Uart_SendArr(response, 5 + response_length );
}

// 读取保持寄存器（读取存储的数据）
void Modbus_03H(uint8_t *_pBuf)
{
    /*
        主机发送:
            01 从机地址
            03 功能码
            00 寄存器起始地址高字节
            13 寄存器起始地址低字节
            00 寄存器数量高字节
            25 寄存器数量低字节
            0E CRC校验高字节
            84 CRC校验低字节
            
        从机应答: 返回请求的保持寄存器中的内容。每个寄存器占两个字节，以大端模式发送。
            01 从机地址
            03 功能码
            05 返回字节数
            数据1(寄存器0013H)
            数据2(寄存器0014H)
            ...
            数据n(寄存器0025H)
            CRC校验高字节
            CRC校验低字节

        例子:
            01 03 10 01 00 03 29 0B   --- 查询寄存器0013H开始的3个寄存器内容
    */
    // uint16_t register_add = LEBufToUint16(_pBuf[2], _pBuf[3]);
    // uint16_t register_count = LEBufToUint16(_pBuf[4], _pBuf[5]);

    // uint8_t response_length  = register_count*2;
    // uint8_t response[3 + response_length ];
    // mem_set((char *)response, 0, 3 + response_length );
    // response[0] = _pBuf[0];
    // response[1] = _pBuf[1];
    // response[2] = response_length ;
    // uint16_t i;
    // for ( i = 0; i < register_count; i++)
    // {
    //     uint8_t register_val=NULL;
    //     switch (register_add+i)
    //     {
    //     case /* constant-expression */:
    //         /* code */
    //         break;
        
    //     default:
    //         break;
    //     }
    // }
    

}

// 读取输入寄存器（读取存储的数据）
void Modbus_04H(uint8_t *_pBuf)
{
    /*
        主机发送:
            01 从机地址
            04 功能码
            00 寄存器起始地址高字节
            C4 寄存器起始地址低字节
            00 寄存器数量高字节
            16 寄存器数量低字节
            BA CRC校验高字节
            A9 CRC校验低字节

        从机应答: 返回请求的输入寄存器中的内容。每个寄存器占两个字节，以大端模式发送。
            01 从机地址
            04 功能码
            32 返回字节数
            数据1(寄存器00C4H)
            数据2(寄存器00C5H)
            ...
            数据n(寄存器00D9H)
            CRC校验高字节
            CRC校验低字节

        例子:
            01 04 20 01 00 08 23CC   ---- 读取输入寄存器T01-08的内容
            01 04 20 04 00 02 B3CA   ---- 读取输入寄存器T04-05的内容
    */
}

// 写单个输出线圈（控制开关量输出）
void Modbus_05H(uint8_t *_pBuf)
{
    /*
        主机发送:
            01 从机地址
            05 功能码
            00 输出地址高字节
            13 输出地址低字节
            FF00 输出数据高字节
            0000 输出数据低字节
            0E CRC校验高字节
            84 CRC校验低字节

        从机应答: 返回设置的单个输出寄存器的状态。
            01 从机地址
            05 功能码
            输出地址高字节
            输出地址低字节
            输出数据高字节
            输出数据低字节
            CRC校验高字节
            CRC校验低字节

        例子:
            01 05 10 01 FF 00 29 0B   --- 设置单个输出寄存器0013H的状态为ON
    */
}

// 写单个保持寄存器（控制存储的数据）
void Modbus_06H(uint8_t *_pBuf)
{
    /*
        主机发送:
            01 从机地址
            06 功能码
            00 寄存器地址高字节
            C4 寄存器地址低字节
            00 寄存器值高字节
            64 寄存器值低字节
            BA CRC校验高字节
            A9 CRC校验低字节

        从机应答: 返回设置的单个保持寄存器的状态。
            01 从机地址
            06 功能码
            寄存器地址高字节
            寄存器地址低字节
            寄存器值高字节
            寄存器值低字节
            CRC校验高字节
            CRC校验低字节

        例子:
            01 06 20 01 00 64 23CC   --- 设置单个保持寄存器00C4H的值为100
    */
}

// 写多个保持寄存器（控制存储的数据）
void Modbus_10H(uint8_t *_pBuf)
{
    /*
        主机发送:
            01 从机地址
            10 功能码
            00 起始地址高字节
            13 起始地址低字节
            00 寄存器数量高字节
            19 寄存器数量低字节
            32 数据字节数
            04 数据1(寄存器0013H)
            00 数据2(寄存器0014H)
            ...
            数据n(寄存器002BH)
            BA CRC校验高字节
            A9 CRC校验低字节

        从机应答: 返回设置的多个保持寄存器的状态。
            01 从机地址
            10 功能码
            起始地址高字节
            起始地址低字节
            寄存器数量高字节
            寄存器数量低字节
            CRC校验高字节
            CRC校验低字节

        例子:
            01 10 10 01 00 19 32 04 00 23CC  ---- 设置多个保持寄存器0013H-002BH的值
    */
}
