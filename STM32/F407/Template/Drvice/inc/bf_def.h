#ifndef __BF_DEF_H
#define __BF_DEF_H

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "stm32f4xx.h"
#include "user_function_proc.h"

#define ENABLE_INT()    __set_PRIMASK(0)  /* ʹ��ȫ���ж� */
#define DISABLE_INT()   __set_PRIMASK(1) /* ��ֹȫ���ж� */

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

#define __RCC_GPIOX_ENABLE(VAL)         __SET_BIT((RCC->AHB1ENR), (1 << VAL))
#define __RCC_GPIOX_DISABLE(VAL)        __CLEAR_BIT((RCC->AHB1ENR), (1 << VAL))

/************************************************GPIO �����궨��*******************************************************/
/**
 * @brief ���� GPIO �˿�������ͼĴ���ָ��λ
 * @param REG GPIOx
 * @param PIN ���ź�
 * @param VAL ֵ
 */
#define __IO_WRITE_MODE(REG, PIN, VAL) __SET_BIT((REG->MODER), (VAL << ((PIN << 1))))
/**
 * @brief ���� GPIO �˿�������ͼĴ���ָ��λ
 * @param REG GPIOx
 * @param PIN ���ź�
 * @param VAL ֵ
 */
#define __IO_WRITE_OTYPE(REG, PIN, VAL) __SET_BIT((REG->OTYPER), (VAL << ((PIN << 1))))

/**
 * @brief ���� GPIO �˿�����ٶȼĴ���ָ��λ
 * @param REG GPIOx
 * @param PIN ���ź�
 * @param VAL ֵ
 */
#define __IO_WRITE_SPEED(REG, PIN, VAL) __SET_BIT((REG->OSPEEDR), (VAL << ((PIN << 1))))

/**
 * @brief ���� GPIO �˿�����/�����Ĵ���ָ��λ
 * @param REG GPIOx
 * @param PIN ���ź�
 * @param VAL ֵ
 */
#define __IO_WRITE_PUPD(REG, PIN, VAL) __SET_BIT((REG->PUPDR), (VAL << ((PIN << 1))))

/**
 * @brief ���� GPIO ���ù���
 * @param REG GPIOx
 * @param PIN ���ź�
 * @param VAL ֵ
 */
#if 0
#define __IO_WRITE_AFR(REG, PIN, VAL)   __SET_BIT((REG->AFR[1]), (VAL << ((PIN - 8) << 2)));
#else

#define __IO_WRITE_AFR(REG, PIN, VAL)                            \
    if (PIN < 7) {                                               \
        __SET_BIT((REG->AFR[0]), (VAL << (PIN << 2)));           \
    } else {                                                     \
        __SET_BIT((REG->AFR[1]), (VAL << ((PIN - 8) << 2)));     \
    }

#endif
/**
 * @brief ���� GPIO ����Ĵ���ָ��λ
 * @param REG GPIOx
 * @param PIN ���ź�
 */
#define __IO_SET_BIT(REG, PIN)     __SET_BIT((REG->BSRRL), (1 << PIN))

/**
 * @brief ��λ GPIO ����Ĵ���ָ��λ
 * @param REG GPIOx
 * @param PIN ���ź�
 */
#define __IO_RESET_BIT(REG, PIN)     __SET_BIT((REG->BSRRH), (1 << PIN))

/**
 * @brief ��ȡ GPIO ����Ĵ���ָ��λ
 * @param REG GPIOx
 * @param PIN ���ź�
 */
#define __IO_READ_IN(REG, PIN)       __CMP_REG(__READ_BIT((REG->IDR), (1 << PIN)), (1 << PIN))

/**
 * @brief ��ȡ GPIO ����Ĵ���ָ��λ
 * @param REG GPIOx
 * @param PIN ���ź�
 */
#define __IO_READ_OUT(REG, PIN)       __CMP_REG(__READ_BIT((REG->ODR), (1 << PIN)), (1 << PIN))

typedef enum
{
    BF_OK = 0,            // �ɹ�
    BF_FAILURE,           // ʧ��
    BF_ERROR,             // ����
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

#endif // !__BF_DEF_H
