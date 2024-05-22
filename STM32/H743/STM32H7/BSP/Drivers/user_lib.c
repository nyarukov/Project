#include "user_lib.h"

/**
 * @brief �����ַ�������
 * 
 * @param _str ������
 * @return int ����
 */
int str_len(char *_str)
{
	int len = 0;

	while (*_str++) len++;
	return len;
}

/**
 * @brief �����ַ���
 * 
 * @param _tar Ŀ�껺����
 * @param _src Դ������
 */
void str_cpy(char *_tar, char *_src)
{
	do
	{
		*_tar++ = *_src;
	}
	while (*_src++);
}

/**
 * @brief �ַ����Ƚ�
 * 
 * @param _s1 �ַ���1
 * @param _s2 �ַ���2
 * @return int 0 ��ʾ��� ��0��ʾ����
 */
int str_cmp(char * _s1, char * _s2)
{
	while ((*_s1!=0) && (*_s2!=0) && (*_s1==*_s2))
	{
		_s1++;
		_s2++;
	}
	return *_s1 - *_s2;
}

/**
 * @brief ���ڴ�����������Ϊָ����ֵ
 * 
 * @param _ptr Ҫ���õ��ڴ���ָ��
 * @param _value Ҫ���õ�ֵ
 * @param _len Ҫ���õ��ֽ���
 */
void mem_set(void *_ptr, int _value, int _len) {
    char *p = (char *)_ptr;
    while (_len--) {
        *p++ = (char)_value;
    }
}

/**
 * @brief ��һ���ڴ������ݸ��Ƶ���һ���ڴ��
 * 
 * @param _dest Ŀ���ڴ���ָ��
 * @param _src Դ�ڴ���ָ��
 * @param _len Ҫ���Ƶ��ֽ���
 */
void mem_cpy(void *_dest, const void *_src, int _len) {
    char *d = (char *)_dest;
    const char *s = (const char *)_src;

    while (_len--) {
        *d++ = *s++;
    }
}

/**
 * @brief CRC-8 У�麯��
 * 
 * @param buf ������
 * @param len ����
 * @return uint16_t 
 */
uint16_t Check_CRC8(uint8_t *buf, uint16_t len)
{
    uint8_t crc = 0;
    for (uint16_t i = 0; i < len; ++i)
    {
        crc ^= buf[i];
        for (uint8_t j = 0; j < 8; ++j)
        {
            if (crc & 0x01)
            {
                crc = (crc >> 1) ^ 0x8C;
            }
            else
            {
                crc >>= 1;
            }
        }
    }
    return crc;
}

/**
 * @brief Modbus CRC-16 У�麯��
 * 
 * @param data ������
 * @param length ����
 * @return uint16_t 
 */
uint16_t Check_Modbus_CRC16(uint8_t *data, uint16_t length)
{
    uint16_t crc = 0xFFFF; // ��ʼCRCֵ��Ϊ0xFFFF
    for (uint16_t i = 0; i < length; i++)
    {
        crc ^= data[i]; // �뵱ǰ�ֽڽ���XOR����
        for (uint8_t j = 0; j < 8; j++)
        {
            if (crc & 0x0001)
            {                  // ������λΪ1
                crc >>= 1;     // ����һλ
                crc ^= 0xA001; // �����ʽ0xA001�������
            }
            else
            {
                crc >>= 1; // ����һλ
            }
        }
    }

    return crc;
}

/**
 * @brief Xmodem CRC-16 У�麯��
 * 
 * @param buf ������
 * @param len ����
 * @return uint16_t 
 */
uint16_t Check_Xmodeme_CRC16(uint8_t *buf, uint16_t len)
{
    uint16_t crc = 0;
    for (uint16_t i = 0; i < len; ++i)
    {
        crc ^= ((uint16_t)buf[i] << 8);
        for (uint8_t j = 0; j < 8; ++j)
        {
            if (crc & 0x8000)
            {
                crc = (crc << 1) ^ 0x1021;
            }
            else
            {
                crc <<= 1;
            }
        }
    }
    return crc;
}

/**
 * @brief Ymodem CRC-16 У�麯��
 * 
 * @param buf ������
 * @param len ����
 * @return uint16_t 
 */
uint16_t Check_Ymodeme_CRC16(uint8_t *buf, uint16_t len)
{
    uint16_t crc = 0;
    for (uint16_t i = 0; i < len; ++i)
    {
        crc ^= (uint16_t)buf[i] << 8;
        for (uint8_t j = 0; j < 8; ++j)
        {
            if (crc & 0x8000)
            {
                crc = (crc << 1) ^ 0x8408;
            }
            else
            {
                crc <<= 1;
            }
        }
    }
    return crc;
}