#include "bsp_modbus_slave.h"

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

void Modbus_check(uint8_t *_pBuf, uint8_t _len)
{
    uint16_t crc;
    uint16_t receivecrc;
    if (_pBuf[0] != MODBUS_ADDRESS)
    {
        mem_set((char *)_pBuf, 0, _len);
        Uart1.Cnt = 0;
        Uart1.Flag = 0;
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
    sendbuff[0] = _pBuf[0];                // Modbus �豸��ַ
    sendbuff[1] = 0x80 | _pBuf[1];         // ���������Ӧ��
    sendbuff[2] = 0;                       // �쳣��
    crc = Check_Modbus_CRC16(sendbuff, 3); // ���� CRC У��ֵ
    sendbuff[3] = (uint8_t)(crc >> 8);     // CRC У��ֵ��λ
    sendbuff[4] = (uint8_t)crc;            // CRC У��ֵ��λ
    Uart_SendArr(sendbuff, 5);             // �����쳣��Ӧ����
}

static void Modbus_SendData(uint16_t dataLength)
{
    Ms_Response.crc = Check_Modbus_CRC16(Ms_Response.buffer, dataLength);

    Ms_Response.buffer[dataLength] = LOW_BYTE(Ms_Response.crc);
    Ms_Response.buffer[dataLength + 1] = HIGH_BYTE(Ms_Response.crc);

    Uart_SendArr(Ms_Response.buffer, dataLength + 2);
}

static void Modbus_AnalyzeApp(uint8_t *_pBuf)
{
    switch (_pBuf[1])
    {
    case 0x01: // ��ȡ��Ȧ״̬����ȡ����������״̬��
        Modbus_01H(_pBuf);
        break;
    case 0x02: // ��ȡ����״̬����ȡ���������״̬��
        Modbus_02H(_pBuf);
        break;
    case 0x03: // ��ȡ���ּĴ�������ȡ�洢�����ݣ�
        Modbus_03H(_pBuf);
        break;
    case 0x04: // ��ȡ����Ĵ�������ȡ�洢�����ݣ�
        Modbus_04H(_pBuf);
        break;
    case 0x05: // ǿ�Ƶ���Ȧ�����ƿ����������
        Modbus_05H(_pBuf);
        break;
    case 0x06: // д�������ּĴ��������ƴ洢�����ݣ�
        Modbus_06H(_pBuf);
        break;
    case 0x10: // д������ּĴ��������ƴ洢�����ݣ�
        Modbus_10H(_pBuf);
        break;
    default:
        Modbus_Error(_pBuf);
        break;
    }
}

// ��ȡ��Ȧ״̬����ȡ����������״̬��
void Modbus_01H(uint8_t *_pBuf)
{
    /*
        ��������:
            11 �ӻ���ַ
            01 ������
            00 �Ĵ�����ʼ��ַ���ֽ�
            13 �Ĵ�����ʼ��ַ���ֽ�
            00 �Ĵ����������ֽ�
            25 �Ĵ����������ֽ�
            0E CRCУ����ֽ�
            84 CRCУ����ֽ�

        �ӻ�Ӧ��: 	1����ON��0����OFF�������ص���Ȧ����Ϊ8�ı�����������������ֽ�δβʹ��0����. BIT0��Ӧ��1��
            11 �ӻ���ַ
            01 ������
            05 �����ֽ���
            CD ����1(��Ȧ0013H-��Ȧ001AH)
            6B ����2(��Ȧ001BH-��Ȧ0022H)
            B2 ����3(��Ȧ0023H-��Ȧ002AH)
            0E ����4(��Ȧ0032H-��Ȧ002BH)
            1B ����5(��Ȧ0037H-��Ȧ0033H)
            45 CRCУ����ֽ�
            E6 CRCУ����ֽ�
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
        Ms_Response.reg_val = Modbus_01H_Callback(Ms_Response.reg_addr + i);
        Ms_Response.buffer[3 + (i >> 3)] |= (LOW_BYTE(Ms_Response.reg_val) << (i % 8));
    }

    Modbus_SendData(3 + Ms_Response.reg_length);
}

// ��ȡ��ɢ����״̬����ȡ���������״̬��
void Modbus_02H(uint8_t *_pBuf)
{
    /*
    ��������:
        11 �ӻ���ַ
        02 ������
        00 �Ĵ�����ַ���ֽ�
        C4 �Ĵ�����ַ���ֽ�
        00 �Ĵ����������ֽ�
        16 �Ĵ����������ֽ�
        BA CRCУ����ֽ�
        A9 CRCУ����ֽ�

    �ӻ�Ӧ��:  ��Ӧ����ɢ����Ĵ���״̬���ֱ��Ӧ�������е�ÿλֵ��1 ����ON��0 ����OFF��
               ��һ�������ֽڵ�LSB(����ֽ�)Ϊ��ѯ��Ѱַ��ַ����������ڰ�˳���ڸ��ֽ����ɵ��ֽ�
               ����ֽ����У�ֱ�������8λ����һ���ֽ��е�8������λҲ�Ǵӵ��ֽڵ����ֽ����С�
               �����ص�����λ������8�ı������������������ֽ��е�ʣ��λ�����ֽڵ����λʹ��0��䡣
        11 �ӻ���ַ
        02 ������
        03 �����ֽ���
        AC ����1(00C4H-00CBH)
        DB ����2(00CCH-00D3H)
        35 ����3(00D4H-00D9H)
        20 CRCУ����ֽ�
        18 CRCУ����ֽ�
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
        Ms_Response.reg_val = Modbus_02H_Callback(Ms_Response.reg_addr + i);
        Ms_Response.buffer[3 + (i >> 3)] |= (LOW_BYTE(Ms_Response.reg_val) << (i % 8));
    }
    Modbus_SendData(3 + Ms_Response.reg_length);
}

// ��ȡ���ּĴ�������ȡ�洢�����ݣ�
void Modbus_03H(uint8_t *_pBuf)
{
    /*
        ��������:
            11 �ӻ���ַ
            03 ������
            00 �Ĵ�����ַ���ֽ�
            6B �Ĵ�����ַ���ֽ�
            00 �Ĵ����������ֽ�
            03 �Ĵ����������ֽ�
            76 CRC���ֽ�
            87 CRC���ֽ�

        �ӻ�Ӧ��: 	���ּĴ����ĳ���Ϊ2���ֽڡ����ڵ������ּĴ������ԣ��Ĵ������ֽ������ȱ����䣬
                    ���ֽ����ݺ󱻴��䡣���ּĴ���֮�䣬�͵�ַ�Ĵ����ȱ����䣬�ߵ�ַ�Ĵ����󱻴��䡣
            11 �ӻ���ַ
            03 ������
            06 �ֽ���
            00 ����1���ֽ�(006BH)
            6B ����1���ֽ�(006BH)
            00 ����2���ֽ�(006CH)
            13 ����2 ���ֽ�(006CH)
            00 ����3���ֽ�(006DH)
            00 ����3���ֽ�(006DH)
            38 CRC���ֽ�
            B9 CRC���ֽ�
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
        Ms_Response.reg_val = Modbus_03H_Callback(Ms_Response.reg_addr + (i << 1));
        Ms_Response.buffer[3 + (i << 1)] = HIGH_BYTE(Ms_Response.reg_val);
        Ms_Response.buffer[4 + (i << 1)] = LOW_BYTE(Ms_Response.reg_val);
    }

    Modbus_SendData(3 + Ms_Response.reg_length);
}

// ��ȡ����Ĵ�������ȡ�洢�����ݣ�
void Modbus_04H(uint8_t *_pBuf)
{
    /*
        ��������:
            11 �ӻ���ַ
            04 ������
            00 �Ĵ�����ʼ��ַ���ֽ�
            08 �Ĵ�����ʼ��ַ���ֽ�
            00 �Ĵ����������ֽ�
            02 �Ĵ����������ֽ�
            F2 CRC���ֽ�
            99 CRC���ֽ�

        �ӻ�Ӧ��:  ����Ĵ�������Ϊ2���ֽڡ����ڵ�������Ĵ������ԣ��Ĵ������ֽ������ȱ����䣬
                ���ֽ����ݺ󱻴��䡣����Ĵ���֮�䣬�͵�ַ�Ĵ����ȱ����䣬�ߵ�ַ�Ĵ����󱻴��䡣
            11 �ӻ���ַ
            04 ������
            04 �ֽ���
            00 ����1���ֽ�(0008H)
            0A ����1���ֽ�(0008H)
            00 ����2���ֽ�(0009H)
            0B ����2���ֽ�(0009H)
            8B CRC���ֽ�
            80 CRC���ֽ�
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
        Ms_Response.reg_val = Modbus_04H_Callback(Ms_Response.reg_addr + (i << 1));
        Ms_Response.buffer[3 + (i << 1)] = HIGH_BYTE(Ms_Response.reg_val);
        Ms_Response.buffer[4 + (i << 1)] = LOW_BYTE(Ms_Response.reg_val);
    }
    Modbus_SendData(3 + Ms_Response.reg_length);
}

// д���������Ȧ�����ƿ����������
void Modbus_05H(uint8_t *_pBuf)
{
    /*
        ��������:
            11 �ӻ���ַ
            05 ������
            00 �Ĵ�����ַ���ֽ�
            AC �Ĵ�����ַ���ֽ�
            FF ����1���ֽ�
            00 ����2���ֽ�
            4E CRCУ����ֽ�
            8B CRCУ����ֽ�

        �ӻ�Ӧ��:
            11 �ӻ���ַ
            05 ������
            00 �Ĵ�����ַ���ֽ�
            AC �Ĵ�����ַ���ֽ�
            FF �Ĵ���1���ֽ�
            00 �Ĵ���1���ֽ�
            4E CRCУ����ֽ�
            8B CRCУ����ֽ�
    */
    mem_set((char *)&Ms_Response, 0, sizeof(Modbus_Slave_t));
    Ms_Response.reg_addr = LEBufToUint16(_pBuf[2], _pBuf[3]);
    Ms_Response.reg_val = LEBufToUint16(_pBuf[4], _pBuf[5]);

    mem_cpy(Ms_Response.buffer, _pBuf, 6);

    Modbus_05H_Callback(Ms_Response.reg_addr,Ms_Response.reg_val);
    Modbus_SendData(6);
}

// д�������ּĴ��������ƴ洢�����ݣ�
void Modbus_06H(uint8_t *_pBuf)
{
    /*
        ��������:
            11 �ӻ���ַ
            06 ������
            00 �Ĵ�����ַ���ֽ�
            01 �Ĵ�����ַ���ֽ�
            00 ����1���ֽ�
            01 ����1���ֽ�
            9A CRCУ����ֽ�
            9B CRCУ����ֽ�

        �ӻ���Ӧ:
            11 �ӻ���ַ
            06 ������
            00 �Ĵ�����ַ���ֽ�
            01 �Ĵ�����ַ���ֽ�
            00 ����1���ֽ�
            01 ����1���ֽ�
            1B CRCУ����ֽ�
            5A	CRCУ����ֽ�
    */
    Ms_Response.reg_addr = LEBufToUint16(_pBuf[2], _pBuf[3]);
    Ms_Response.reg_val = LEBufToUint16(_pBuf[4], _pBuf[5]);

    mem_cpy(Ms_Response.buffer, _pBuf, 6);

    Modbus_06H_Callback(Ms_Response.reg_addr,Ms_Response.reg_val);
    Modbus_SendData(6);
}

// д������ּĴ��������ƴ洢�����ݣ�
void Modbus_10H(uint8_t *_pBuf)
{
    /*
        ��������:
            11 �ӻ���ַ
            10 ������
            00 �Ĵ�����ʼ��ַ���ֽ�
            01 �Ĵ�����ʼ��ַ���ֽ�
            00 �Ĵ����������ֽ�
            02 �Ĵ����������ֽ�
            04 �ֽ���
            00 ����1���ֽ�
            0A ����1���ֽ�
            01 ����2���ֽ�
            02 ����2���ֽ�
            C6 CRCУ����ֽ�
            F0 CRCУ����ֽ�

        �ӻ���Ӧ:
            11 �ӻ���ַ
            06 ������
            00 �Ĵ�����ַ���ֽ�
            01 �Ĵ�����ַ���ֽ�
            00 ����1���ֽ�
            01 ����1���ֽ�
            1B CRCУ����ֽ�
            5A	CRCУ����ֽ�
    */

    Ms_Response.reg_addr = LEBufToUint16(_pBuf[2], _pBuf[3]);
    Ms_Response.reg_count = LEBufToUint16(_pBuf[4], _pBuf[5]);

    Ms_Response.reg_length = Ms_Response.reg_count << 1;

    mem_cpy(Ms_Response.buffer, _pBuf, 6);

    uint8_t i;
    for (i = 0; i < Ms_Response.reg_count; i++)
    {
        Ms_Response.reg_val = LEBufToUint16(_pBuf[7 + (i << 1)], _pBuf[8 + (i << 1)]);
        Modbus_10H_Callback(Ms_Response.reg_addr + (i << 1),Ms_Response.reg_val);
    }
    Modbus_SendData(6);
}

// void Modbus_0FH(uint8_t *_pBuf)
// {
//     Ms_Response.reg_addr = LEBufToUint16(_pBuf[2], _pBuf[3]);
//     Ms_Response.reg_count = LEBufToUint16(_pBuf[4], _pBuf[5]);
//     Ms_Response.reg_length = _pBuf[6];

//     mem_cpy(Ms_Response.buffer, _pBuf, 6);

//     uint8_t i;
//     uint8_t j;
//     for (i = 0; i < Ms_Response.reg_length; i++)
//     {
//         Ms_Response.reg_val = _pBuf[7 + (i / 8)];
//         for (j = 0; j < 8; j++)
//         {
//             switch (Ms_Response.reg_addr + j)
//             {
//             case LED1_ADDR:
//                 __SET_GPIO_LOW_IF_EQUAL(GPIOA, 11, __MASK_BIT(LOW_BYTE(Ms_Response.reg_val), 0), 0);
//                 break;
//             case LED2_ADDR:
//                 __SET_GPIO_LOW_IF_EQUAL(GPIOA, 12, __MASK_BIT(LOW_BYTE(Ms_Response.reg_val), 1), 0);
//                 break;
//             case LED3_ADDR:
//                 __SET_GPIO_LOW_IF_EQUAL(GPIOA, 15, __MASK_BIT(LOW_BYTE(Ms_Response.reg_val), 2), 0);
//                 break;
//             }
//         }
//     }
//     Modbus_SendData(6);
// }

__weak uint8_t Modbus_01H_Callback(uint16_t _Addr)
{
    return 0;
}

__weak uint8_t Modbus_02H_Callback(uint16_t _Addr)
{
    return 0;
}

__weak uint16_t Modbus_03H_Callback(uint16_t _Addr)
{
    return 0;
}

__weak uint16_t Modbus_04H_Callback(uint16_t _Addr)
{
    return 0;
}

__weak void Modbus_05H_Callback(uint16_t _Addr,uint16_t _Data)
{
    
}

__weak void Modbus_06H_Callback(uint16_t _Addr,uint16_t _Data)
{
   
}

__weak void Modbus_10H_Callback(uint16_t _Addr,uint16_t _Data)
{
   
}