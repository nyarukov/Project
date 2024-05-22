#ifndef __BF_DEF_H
#define __BF_DEF_H

#include "bf_middle.h"

/************************************************�ڴ�������Ժ궨��*******************************************************/
#define __I                             volatile const /* ֻ������ */
#define __O                             volatile       /* ֻд���� */
#define __IO                            volatile      /* ��д���� */

/* Memory attributes for peripherals accessible through AXI or AHB interfaces */
#define __IM                            volatile const /* ֻ������ */
#define __OM                            volatile       /* ֻд���� */
#define __IOM                           volatile      /* ��д���� */

/************************************************��������Ԫ�ظ���*******************************************************/
#define ARRAY_SIZE(x)                   (sizeof(x) / (sizeof((x)[0])))

/************************************************�ַ�������*******************************************************/
#define CONCAT(a, b)                    a##b /* �ϲ�������ʶ�� */
#define STR(s)                          #s         /* ������ת��Ϊ�ַ��� */

/************************************************ֵת��*******************************************************/
#define BMIN(a, b)                      ((a) < (b) ? (a) : (b)) /* ��Сֵ�궨�� */
#define BMAX(a, b)                      ((a) > (b) ? (a) : (b)) /* ���ֵ�궨�� */
#define BABS(x)                         ((x) < 0 ? -(x) : (x))     /* ����ֵ�궨�� */

/************************************************�ֽڲ���*******************************************************/
#define SWAP_BYTE(x)                    (((x) << 4) | ((x) >> 4)) /*�ֽڽ���*/
#define SWAP_UINT16(x)                  (((x) << 8) | ((x) >> 8)) /*16λ�����ֽڽ���*/
#define BEBufToUint16(byte1, byte2)     ((((byte1) & 0xFF) | ((uint16_t)byte2) << 8)) /*���ģʽ�ֽ�ת��Ϊ16λ����*/
#define LEBufToUint16(byte1, byte2)     ((((uint16_t)byte1) << 8) | ((byte2) & 0xFF)) /*С��ģʽ�ֽ�ת��Ϊ16λ����*/
#define HIGH_BYTE(x)                    ((x) >> 8) /*����16λ���ֽ�*/
#define LOW_BYTE(x)                     ((x) & 0xFF) /*����16λ���ֽ�*/


/************************************************�����Ĵ���λ�궨��*******************************************************/
#define __SET_BIT(REG, MASK)            ((REG) |= (MASK))    /* ���üĴ���ָ��λ */
#define __CLEAR_BIT(REG, MASK)          ((REG) &= ~(MASK))          /* ����Ĵ���ָ��λ */
#define __READ_BIT(REG, MASK)           ((REG) & (MASK))    /* ��ȡ�Ĵ���ָ��λ */
#define __CLEAR_REG(REG)                ((REG) = (0x0))          /* ����Ĵ�������λ */
#define __WRITE_REG(REG, MASK)          ((REG) = (MASK))   /* ��Ĵ���д��ֵ */
#define __CMP_REG(REG, MASK)            ((REG) == (MASK))    /* �ȽϼĴ���ֵ */
#define __MASK_BIT(DATA, MASK)          ((DATA) & ((1 << MASK)))      /*����ָ��λ*/


typedef enum
{
    BF_ERROR = -2,             // ����
    BF_FAILURE = -1,           // ʧ��
    BF_OK = 0,            // �ɹ�
    BF_FULL,              // ��
    BF_EMPTY,             // ��
    BF_INVALID_PARAM,     // ��Ч�Ĳ���
    BF_NULL_POINTER,      // ��ָ��
    BF_INVALID_LENGTH,    // ��Ч����
    BF_TOO_SMALL,         // ��С
    BF_TOO_LARGE,         // ����
    BF_NOT_FOUND,         // δ�ҵ�
    BF_PERMISSION_DENIED, // Ȩ�ޱ��ܾ�
    BF_TIMEOUT,           // ��ʱ
    BF_NOT_SUPPORTED,     // ��֧�ֵĲ���
    BF_INTERRUPTED,       // ���ж�
    BF_OUT_OF_MEMORY,     // �ڴ治��
    BF_NETWORK_ERROR,     // �������
    BF_FILE_NOT_FOUND,    // �ļ�δ�ҵ�
    BF_CORRUPT_DATA,      // ������
    BF_DUPLICATE_ENTRY    // �ظ�����Ŀ
} Status;

#endif 
