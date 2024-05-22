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
    sendbuff[0] = _pBuf[0];                // Modbus �豸��ַ
    sendbuff[1] = 0x80 | _pBuf[1];         // ���������Ӧ��
    sendbuff[2] = 0;                       // �쳣��
    crc = Check_Modbus_CRC16(sendbuff, 3); // ���� CRC У��ֵ
    sendbuff[3] = (uint8_t)(crc >> 8);     // CRC У��ֵ��λ
    sendbuff[4] = (uint8_t)crc;            // CRC У��ֵ��λ
    Uart_SendArr(sendbuff, 5);             // �����쳣��Ӧ����
}

static void Modbus_AnalyzeApp(uint8_t *_pBuf)
{
    switch (_pBuf[1])
    {
    case 0x01: // ��ȡ��Ȧ״̬����ȡ����������״̬��
        Modbus_01H(_pBuf);
        break;
    case 0x02: // ��ȡ��ɢ����״̬����ȡ���������״̬��
        Modbus_02H(_pBuf);
        break;
    case 0x03: // ��ȡ���ּĴ�������ȡ�洢�����ݣ�
        Modbus_03H(_pBuf);
        break;
    case 0x04: // ��ȡ����Ĵ�������ȡ�洢�����ݣ�
        Modbus_04H(_pBuf);
        break;
    case 0x05: // д���������Ȧ�����ƿ����������
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
                01 �ӻ���ַ
                01 ������
                00 �Ĵ�����ʼ��ַ���ֽ�
                13 �Ĵ�����ʼ��ַ���ֽ�
                00 �Ĵ����������ֽ�
                25 �Ĵ����������ֽ�
                0E CRCУ����ֽ�
                84 CRCУ����ֽ�

            �ӻ�Ӧ��: 	1����ON��0����OFF�������ص���Ȧ����Ϊ8�ı�����������������ֽ�δβʹ��0����. BIT0��Ӧ��1��
                01 �ӻ���ַ
                01 ������
                05 �����ֽ���
                CD ����1(��Ȧ0013H-��Ȧ001AH)
                6B ����2(��Ȧ001BH-��Ȧ0022H)
                B2 ����3(��Ȧ0023H-��Ȧ002AH)
                0E ����4(��Ȧ0032H-��Ȧ002BH)
                1B ����5(��Ȧ0037H-��Ȧ0033H)
                45 CRCУ����ֽ�
                E6 CRCУ����ֽ�

            ����:
                01 01 10 01 00 03   29 0B	--- ��ѯD01��ʼ��3���̵���״̬
                01 01 10 03 00 01   09 0A   --- ��ѯD03�̵�����״̬
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

// ��ȡ��ɢ����״̬����ȡ���������״̬��
void Modbus_02H(uint8_t *_pBuf)
{
    /*
            ��������:
                01 �ӻ���ַ
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
                01 �ӻ���ַ
                02 ������
                03 �����ֽ���
                AC ����1(00C4H-00CBH)
                DB ����2(00CCH-00D3H)
                35 ����3(00D4H-00D9H)
                20 CRCУ����ֽ�
                18 CRCУ����ֽ�

            ����:
            01 02 20 01 00 08  23CC  ---- ��ȡT01-08��״̬
            01 02 20 04 00 02  B3CA  ---- ��ȡT04-05��״̬
            01 02 20 01 00 12  A207   ---- �� T01-18
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

// ��ȡ���ּĴ�������ȡ�洢�����ݣ�
void Modbus_03H(uint8_t *_pBuf)
{
    /*
        ��������:
            01 �ӻ���ַ
            03 ������
            00 �Ĵ�����ʼ��ַ���ֽ�
            13 �Ĵ�����ʼ��ַ���ֽ�
            00 �Ĵ����������ֽ�
            25 �Ĵ����������ֽ�
            0E CRCУ����ֽ�
            84 CRCУ����ֽ�
            
        �ӻ�Ӧ��: ��������ı��ּĴ����е����ݡ�ÿ���Ĵ���ռ�����ֽڣ��Դ��ģʽ���͡�
            01 �ӻ���ַ
            03 ������
            05 �����ֽ���
            ����1(�Ĵ���0013H)
            ����2(�Ĵ���0014H)
            ...
            ����n(�Ĵ���0025H)
            CRCУ����ֽ�
            CRCУ����ֽ�

        ����:
            01 03 10 01 00 03 29 0B   --- ��ѯ�Ĵ���0013H��ʼ��3���Ĵ�������
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

// ��ȡ����Ĵ�������ȡ�洢�����ݣ�
void Modbus_04H(uint8_t *_pBuf)
{
    /*
        ��������:
            01 �ӻ���ַ
            04 ������
            00 �Ĵ�����ʼ��ַ���ֽ�
            C4 �Ĵ�����ʼ��ַ���ֽ�
            00 �Ĵ����������ֽ�
            16 �Ĵ����������ֽ�
            BA CRCУ����ֽ�
            A9 CRCУ����ֽ�

        �ӻ�Ӧ��: �������������Ĵ����е����ݡ�ÿ���Ĵ���ռ�����ֽڣ��Դ��ģʽ���͡�
            01 �ӻ���ַ
            04 ������
            32 �����ֽ���
            ����1(�Ĵ���00C4H)
            ����2(�Ĵ���00C5H)
            ...
            ����n(�Ĵ���00D9H)
            CRCУ����ֽ�
            CRCУ����ֽ�

        ����:
            01 04 20 01 00 08 23CC   ---- ��ȡ����Ĵ���T01-08������
            01 04 20 04 00 02 B3CA   ---- ��ȡ����Ĵ���T04-05������
    */
}

// д���������Ȧ�����ƿ����������
void Modbus_05H(uint8_t *_pBuf)
{
    /*
        ��������:
            01 �ӻ���ַ
            05 ������
            00 �����ַ���ֽ�
            13 �����ַ���ֽ�
            FF00 ������ݸ��ֽ�
            0000 ������ݵ��ֽ�
            0E CRCУ����ֽ�
            84 CRCУ����ֽ�

        �ӻ�Ӧ��: �������õĵ�������Ĵ�����״̬��
            01 �ӻ���ַ
            05 ������
            �����ַ���ֽ�
            �����ַ���ֽ�
            ������ݸ��ֽ�
            ������ݵ��ֽ�
            CRCУ����ֽ�
            CRCУ����ֽ�

        ����:
            01 05 10 01 FF 00 29 0B   --- ���õ�������Ĵ���0013H��״̬ΪON
    */
}

// д�������ּĴ��������ƴ洢�����ݣ�
void Modbus_06H(uint8_t *_pBuf)
{
    /*
        ��������:
            01 �ӻ���ַ
            06 ������
            00 �Ĵ�����ַ���ֽ�
            C4 �Ĵ�����ַ���ֽ�
            00 �Ĵ���ֵ���ֽ�
            64 �Ĵ���ֵ���ֽ�
            BA CRCУ����ֽ�
            A9 CRCУ����ֽ�

        �ӻ�Ӧ��: �������õĵ������ּĴ�����״̬��
            01 �ӻ���ַ
            06 ������
            �Ĵ�����ַ���ֽ�
            �Ĵ�����ַ���ֽ�
            �Ĵ���ֵ���ֽ�
            �Ĵ���ֵ���ֽ�
            CRCУ����ֽ�
            CRCУ����ֽ�

        ����:
            01 06 20 01 00 64 23CC   --- ���õ������ּĴ���00C4H��ֵΪ100
    */
}

// д������ּĴ��������ƴ洢�����ݣ�
void Modbus_10H(uint8_t *_pBuf)
{
    /*
        ��������:
            01 �ӻ���ַ
            10 ������
            00 ��ʼ��ַ���ֽ�
            13 ��ʼ��ַ���ֽ�
            00 �Ĵ����������ֽ�
            19 �Ĵ����������ֽ�
            32 �����ֽ���
            04 ����1(�Ĵ���0013H)
            00 ����2(�Ĵ���0014H)
            ...
            ����n(�Ĵ���002BH)
            BA CRCУ����ֽ�
            A9 CRCУ����ֽ�

        �ӻ�Ӧ��: �������õĶ�����ּĴ�����״̬��
            01 �ӻ���ַ
            10 ������
            ��ʼ��ַ���ֽ�
            ��ʼ��ַ���ֽ�
            �Ĵ����������ֽ�
            �Ĵ����������ֽ�
            CRCУ����ֽ�
            CRCУ����ֽ�

        ����:
            01 10 10 01 00 19 32 04 00 23CC  ---- ���ö�����ּĴ���0013H-002BH��ֵ
    */
}
