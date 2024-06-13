#ifndef __GPIO_H
#define __GPIO_H

#include "stm32h7xx_hal.h"
#include "user_lib.h"
#include "uart.h"

// // ���� GPIO ��ʹ����Ӧ��ʱ��
// #define GPIO_CLK_ENABLE(group)      do { \
//                                     __HAL_RCC_GPIO\##group##_CLK_ENABLE(); \
//                                     } while(0)
// // ���� GPIO ��ʧ����Ӧ��ʱ��
// #define GPIO_CLK_DISABLE(group)     do { \
//                                     __HAL_RCC_GPIO ## group ## _CLK_DISABLE(); \
//                                     } while(0)
// // �������ź�
#define GPIO_PIN_NUM(pin)           ((pin[3] != '\0') ? (((pin[2]) - '0') * 10 + ((pin[3]) - '0')) : ((pin[2]) - '0'))
// // ��������ַ
// #define GPIOx_BASE(group)           do { \
//                                     GPIO ## group \
//                                     } while(0)

// ����IOģʽö��
typedef enum {
    IO_MODE_FLOATING = 0x00UL,               // ��������ģʽ 
    IO_MODE_ANALOG = 0x01UL,                 // ģ������ģʽ
    IO_MODE_PULL_UP = 0x02UL,                // ��������ģʽ
    IO_MODE_PULL_DOWN = 0x04UL,              // ��������ģʽ
    IO_MODE_PUSH_PULL_UP = 0x08UL,           // �����������ģʽ
    IO_MODE_PUSH_PULL_DOWN = 0x10UL,         // �����������ģʽ
    IO_MODE_OPEN_DRAIN_UP = 0x20UL,          // ��©�������ģʽ
    IO_MODE_OPEN_DRAIN_DOWN = 0x40UL         // ��©�������ģʽ
} IOMode;


// ����IO�ٶ�ö��
typedef enum {
    IO_SPEED_LOW = 0x00UL,       // ����
    IO_SPEED_MEDIUM = 0x01UL,    // ����
    IO_SPEED_HIGH = 0x02UL,      // ����
    IO_SPEED_HIGH_VERY = 0x04UL  // �ǳ�����
} IOSpeed;

// ����IO��������ö��
typedef enum {
    CMD_IO_NEG,     // ��תIO״̬
    CMD_IO_ON_T,    // ��IO�����ó���ʱ��
    CMD_IO_OFF_T,   // �ر�IO�����ó���ʱ��
    CMD_IO_RST,     // ����IO״̬
    CMD_IO_CLOSE    // �ر�IO
} IOCmd;


/**
 * @brief 
 * 
 * @param _IOx 
 * @param _Mode 
 * @param _Speed 
 * @return int8_t 
 */
void IO_Init(uint8_t *_IOx, uint8_t _Mode, uint8_t _Speed);
/**
 * @brief 
 * 
 * @param _IOx 
 * @param _Para 0:���˿�����  1:��˿�����  2 ���˿����  3:��˿����
 * @return uint32_t 
 */
uint32_t IO_Read(uint32_t _IOx,uint8_t _Para);
/**
 * @brief 
 * 
 * @param _IOx 
 * @param _Val 
 * @param _Para 0:���˿�����  1:��˿�����  2 ���˿����  3:��˿����
 */
void IO_Write(uint32_t _IOx,uint32_t _Val,uint8_t _Para);
/**
 * @brief 
 * 
 * @param _IOx 
 * @param _CMD 
 * @param _Para 
 * @return uint32_t 
 */
int8_t IO_Ctrl(uint32_t _IOx, IOCmd _CMD,uint8_t _Para);

#endif // !__GPIO_H
