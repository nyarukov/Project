/*
 * ��Ŀ����: modbus_rtu
 * �汾:1.0
 * ����: Yusaka
 * ��������: 2024-06-10 14:04:35
 * ����޸�����: 2024-06-10 14:04:35
 * ����: modbus_rtu
 */

#include "modbus_rtu.h"
// C �ļ�����...

// clang-format off

#define READ_COILS                          0x01    // ��ȡ��Ȧ״̬����ȡ����������״̬��
#define READ_DISCRETE_INPUTS                0x02    // ��ȡ����״̬����ȡ���������״̬��
#define READ_HOLDING_REGISTERS              0x03    // ��ȡ���ּĴ�������ȡ�洢�����ݣ�
#define READ_INPUT_REGISTERS                0x04    // ��ȡ����Ĵ�������ȡ�洢�����ݣ�
#define WRITE_SINGLE_COIL                   0x05    // ǿ�Ƶ���Ȧ�����ƿ����������
#define WRITE_MULTIPLE_COILS                0x0F    // ǿ�ƶ൥��Ȧ�����ƿ����������
#define WRITE_SINGLE_REGISTER               0x06    // д�������ּĴ��������ƴ洢�����ݣ�
#define WRITE_MULTIPLE_REGISTERS            0x10    // д������ּĴ��������ƴ洢�����ݣ�

#define ILLEGAL_FUNCTION                    0x01    // �Ƿ�������
#define ILLEGAL_DATA_ADDRESS                0x02    // �Ƿ����ݵ�ַ
#define ILLEGAL_DATA_VALUE                  0x03    // �Ƿ�����ֵ
#define SLAVE_DEVICE_FAILURE                0x04    // �ӻ�����
#define ACKNOWLEDGE                         0x05    // ȷ��
#define SLAVE_DEVICE_BUSY                   0x06    // �ӻ�æ
#define NEGATIVE_ACKNOWLEDGE                0x07    // ��ȷ��
#define PARITY_ERROR                        0x08    // �洢��ż�Բ��
// clang-format on

/**
 * @brief ����Modbus RTU����֡
 *
 * �˺������ڽ������յ���Modbus RTU����֡����ȡ��ַ����������������ݣ�������CRCУ�顣
 *
 * @param _pBuf ָ�����Modbus RTU����֡�Ļ�������ָ��
 * @param _Len �������ĳ��ȣ��ֽ�����
 * @param _Frame ָ��洢���������ModbusRTUFrame�ṹ��ָ��
 * @return Status ���ؽ���������״̬��
 * - BF_SUCCESS�������ɹ�
 * - BF_TOO_SMALL������֡����̫С
 * - BF_CRC_ERROR��CRCУ��ʧ��
 * - BF_NULL_POINTER���ڴ����ʧ�ܻ��ָ�����
 */
Status Parse_Modbus_Rtu_Frame(uint8_t *_pBuf, uint16_t _Len,
                              ModbusRTUFrame *_Frame)
{
    Check_NULL(_pBuf);

    if (_Len < MODBUS_RTU_MIN_FRAME_SIZE)
        return BF_TOO_SMALL;

    Check_CRC(_pBuf, _Len, &_Frame->crc);

    _Frame->addr = _pBuf[0];
    _Frame->function = _pBuf[1];
    _Frame->length = _Len - 4;
    Check_NULL(_Frame->buf);

    mem_cpy(_Frame->buf, &_pBuf[2], _Frame->length);
    return BF_SUCCESS;
}

/**
 * @brief �� Modbus RTU ͨ���з�������֡
 *
 * @param _Id ͨ�Ŷ˿�ID
 * @param _Addr �豸��ַ
 * @param _Function ������
 * @param _pBuf �����͵����ݻ�����ָ��
 * @param _Len ���������ݵĳ���
 * @return Status ���Ͳ�����״̬��
 * - BF_SUCCESS�����ͳɹ�
 * - BF_TOO_SMALL������֡����̫С
 */
Status Modbus_Rtu_SendBuf(COM_ID _Id, uint8_t _Addr,
                          uint8_t _Function, uint8_t *_pBuf,
                          uint32_t _Len)
{
    Check_NULL(_pBuf);

    if (_Len < MODBUS_RTU_MIN_FRAME_SIZE)
        return BF_TOO_SMALL;

    uint8_t buf[_Len + 4];
    buf[0] = _Addr;
    buf[1] = _Function;
    mem_cpy(&buf[2], _pBuf, _Len);

    uint16_t _Crc = Check_Modbus_CRC16(buf, _Len + 2);
    buf[2 + _Len] = LOW_BYTE(_Crc);
    buf[3 + _Len] = HIGH_BYTE(_Crc);

    return Uart_SendData(_Id, buf, _Len + 4);
}

Status jiexi_daying(COM_ID _Id)
{
    uint32_t size;
    if ((Buffer_Get_Written_Count(&COM_OF(_Id).RxBuf, &size) == BF_SUCCESS) && (size > 0))
    {
        ModbusRTUFrame frame;
        if (Parse_Modbus_Rtu_Frame(COM_OF(_Id).RxBuf.Buf, size, &frame) == BF_SUCCESS)
        {
            _LOG("�����ɹ�:\n");
            _LOG("��ַ: %d\n", frame.addr);
            _LOG("������: %d\n", frame.function);
            _LOG("����: ");
            for (int i = 0; i < frame.length; i++)
            {
                _LOG("%02X ", frame.buf[i]);
            }
            _LOG("\nCRC: %04X\n", frame.crc);
        }

        Buffer_Clear(&COM_OF(_Id).RxBuf, 0);
        return BF_SUCCESS;
    }
}
// ����
Status modbus_rtu_read_coils(COM_ID _Id, uint8_t _Chx,
                             uint8_t _Addr, uint8_t _Num,
                             uint8_t *_pBuf, uint32_t _TimeOut)
{
    Status flag;
    uint8_t buf[4];
    buf[0] = HIGH_BYTE(_Addr);
    buf[1] = LOW_BYTE(_Addr);
    buf[2] = HIGH_BYTE(_Num);
    buf[3] = LOW_BYTE(_Num);
    flag = Modbus_Rtu_SendBuf(_Id, _Chx, READ_COILS, buf, 4);
    if (flag != BF_SUCCESS)
    {
        return BF_ERROR;
    }
    //_LOG("��ʱ\r\n");
    TIME_OUT(_TimeOut)
    {
        if (jiexi_daying(_Id) == BF_SUCCESS)
        {
            return BF_SUCCESS;
        }
    }
    _LOG("��ʱ\r\n");
    return BF_TIMEOUT;
}
Status modbus_rtu_write_coil(COM_ID _Id, uint8_t _Addr,
                             uint8_t _Chx, uint8_t _Val,
                             uint32_t _TimeOut)
{
    Status flag;
    uint8_t buf[4];
    buf[0] = HIGH_BYTE(_Addr);
    buf[1] = LOW_BYTE(_Addr);
    // buf[2] = HIGH_BYTE(_Num);
    // buf[3] = LOW_BYTE(_Num);
    flag = Modbus_Rtu_SendBuf(_Id, _Chx, READ_COILS, buf, 4);
    if (flag != BF_SUCCESS)
    {
        return BF_ERROR;
    }
    TIME_OUT(_TimeOut)
    {
        // ModbusRTUFrame frme;
        // return Parse_Modbus_Rtu_Frame(, , &frme);
    }
    return BF_TIMEOUT;
}
Status modbus_rtu_write_coils(COM_ID _Id, uint8_t _Addr,
                              uint8_t _Chx, uint8_t _Num,
                              uint8_t *_pBuf, uint32_t _TimeOut)
{
    Status flag;
    uint8_t buf[4];
    buf[0] = HIGH_BYTE(_Addr);
    buf[1] = LOW_BYTE(_Addr);
    buf[2] = HIGH_BYTE(_Num);
    buf[3] = LOW_BYTE(_Num);
    flag = Modbus_Rtu_SendBuf(_Id, _Chx, READ_COILS, buf, 4);
    if (flag != BF_SUCCESS)
    {
        return BF_ERROR;
    }
    TIME_OUT(_TimeOut)
    {
        // ModbusRTUFrame frme;
        // return Parse_Modbus_Rtu_Frame(, , &frme);
    }
    return BF_TIMEOUT;
}
Status modbus_rtu_read_discrete_input(COM_ID _Id, uint8_t _Chx,
                                      uint8_t _Addr, uint8_t _Num,
                                      uint8_t *_pBuf, uint32_t _TimeOut)
{
    Status flag;
    uint8_t buf[4];
    buf[0] = HIGH_BYTE(_Addr);
    buf[1] = LOW_BYTE(_Addr);
    buf[2] = HIGH_BYTE(_Num);
    buf[3] = LOW_BYTE(_Num);
    flag = Modbus_Rtu_SendBuf(_Id, _Chx, READ_COILS, buf, 4);
    if (flag != BF_SUCCESS)
    {
        return BF_ERROR;
    }
    TIME_OUT(_TimeOut)
    {
        // ModbusRTUFrame frme;
        // return Parse_Modbus_Rtu_Frame(, , &frme);
    }
    return BF_TIMEOUT;
}
Status modbus_rtu_read_holding(COM_ID _Id, uint8_t _Chx,
                               uint8_t _Addr, uint8_t _Num,
                               uint16_t *_pBuf, uint32_t _TimeOut)
{
    Status flag;
    uint8_t buf[4];
    buf[0] = HIGH_BYTE(_Addr);
    buf[1] = LOW_BYTE(_Addr);
    buf[2] = HIGH_BYTE(_Num);
    buf[3] = LOW_BYTE(_Num);
    flag = Modbus_Rtu_SendBuf(_Id, _Chx, READ_COILS, buf, 4);
    if (flag != BF_SUCCESS)
    {
        return BF_ERROR;
    }
    TIME_OUT(_TimeOut)
    {
        // ModbusRTUFrame frme;
        // return Parse_Modbus_Rtu_Frame(, , &frme);
    }
    return BF_TIMEOUT;
}
Status modbus_rtu_write_holding(COM_ID _Id, uint8_t _Chx,
                                uint8_t _Addr, uint8_t _Num,
                                uint16_t Buf, uint32_t _TimeOut)
{
    Status flag;
    uint8_t buf[4];
    buf[0] = HIGH_BYTE(_Addr);
    buf[1] = LOW_BYTE(_Addr);
    buf[2] = HIGH_BYTE(_Num);
    buf[3] = LOW_BYTE(_Num);
    flag = Modbus_Rtu_SendBuf(_Id, _Chx, READ_COILS, buf, 4);
    if (flag != BF_SUCCESS)
    {
        return BF_ERROR;
    }
    TIME_OUT(_TimeOut)
    {
        // ModbusRTUFrame frme;
        // return Parse_Modbus_Rtu_Frame(, , &frme);
    }
    return BF_TIMEOUT;
}
Status modbus_rtu_write_holdings(COM_ID _Id, uint8_t _Chx,
                                 uint8_t _Addr, uint8_t _Num,
                                 uint16_t *_pBuf, uint32_t _TimeOut)
{
    Status flag;
    uint8_t buf[4];
    buf[0] = HIGH_BYTE(_Addr);
    buf[1] = LOW_BYTE(_Addr);
    buf[2] = HIGH_BYTE(_Num);
    buf[3] = LOW_BYTE(_Num);
    flag = Modbus_Rtu_SendBuf(_Id, _Chx, READ_COILS, buf, 4);
    if (flag != BF_SUCCESS)
    {
        return BF_ERROR;
    }
    TIME_OUT(_TimeOut)
    {
        // ModbusRTUFrame frme;
        // return Parse_Modbus_Rtu_Frame(, , &frme);
    }
    return BF_TIMEOUT;
}
Status modbus_rtu_read_input(COM_ID _Id, uint8_t _Chx,
                             uint8_t _Addr, uint8_t _Num,
                             uint8_t *_pBuf, uint32_t _TimeOut)
{
    Status flag;
    uint8_t buf[4];
    buf[0] = HIGH_BYTE(_Addr);
    buf[1] = LOW_BYTE(_Addr);
    buf[2] = HIGH_BYTE(_Num);
    buf[3] = LOW_BYTE(_Num);
    flag = Modbus_Rtu_SendBuf(_Id, _Chx, READ_COILS, buf, 4);
    if (flag != BF_SUCCESS)
    {
        return BF_ERROR;
    }
    TIME_OUT(_TimeOut)
    {
        // ModbusRTUFrame frme;
        // return Parse_Modbus_Rtu_Frame(, , &frme);
    }
    return BF_TIMEOUT;
}

// �ӻ�