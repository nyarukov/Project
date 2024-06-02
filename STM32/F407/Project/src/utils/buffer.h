/*
 * ��Ŀ����: buffer
 * �汾:1.0
 * ����: Yusaka
 * ��������: 2024-06-01
 * ����޸�����: 2024-06-01 18:09:50
 * ����: ������
 */

#ifndef __BUFFER_H
#define __BUFFER_H

// ͷ�ļ�����...
#include "middle.h"

typedef enum
{
    BUFFER_WRITE_BIT,           // ��λΪ��λ�򻺴���д������
    BUFFER_READ_BIT,            // ��λΪ��λ�ӻ�������ȡ����
    BUFFER_WRITE_BYTE,          // ���ֽ�Ϊ��λ�򻺴���д������
    BUFFER_READ_BYTE,           // ���ֽ�Ϊ��λ�ӻ�������ȡ����
    BUFFER_WRITE_SHORT,         // �Զ�����Ϊ��λ�򻺴���д������
    BUFFER_READ_SHORT,          // �Զ�����Ϊ��λ�ӻ�������ȡ����
    BUFFER_WRITE_INT,           // ������Ϊ��λ�򻺴���д������
    BUFFER_READ_INT,            // ������Ϊ��λ�ӻ�������ȡ����
    BUFFER_WRITE_LONG,          // �Գ�����Ϊ��λ�򻺴���д������
    BUFFER_READ_LONG,           // �Գ�����Ϊ��λ�ӻ�������ȡ����
    BUFFER_SET_SIZE,            // ���û�������С
    BUFFER_SET_ADDRESS,         // ���û�������ַ
    BUFFER_CLEAR,               // ��ջ����� 
    BUFFER_TOTAL_SIZE,          // ��ȡ���������ܴ�С     
    BUFFER_READ_POINTER,        // ��ȡ�������Ķ�ָ��λ��         
    BUFFER_WRITE_POINTER,       // ��ȡ��������дָ��λ��         
    BUFFER_SPACE_LEFT,          // ��ȡ��������ʣ��ռ�Ĵ�С    
    BUFFER_WRITTEN_COUNT        // ��ȡ�Ѿ�д�뵽�����������ݵ���������λ�ֽ� 
} Buffer_Cmd;

typedef struct
{
    uint8_t *Buf;
    uint32_t BufSize;
    __IO uint32_t Write;
    __IO uint32_t Read;
    __IO uint32_t Count;
} Buffer_t;

Status Buffer_Config(Buffer_t *_pBuf,
                     void *_Data,
                     uint32_t _Size);

Status Buffer_Operation(Buffer_t *_pBuf,
                        void *_Data,
                        uint32_t _Len,
                        Buffer_Cmd _Cmd,
                        uint32_t *_Para);
												
												
#endif
