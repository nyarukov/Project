/**
 * @file lib.h
 * @author yusaka (luckychaoyue1@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2024-03-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef _LIB_H
#define _LIB_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

// 定义寄存器�?�问权限
#define __I     volatile const    // �?�?
#define __O     volatile          // �?�?
#define __IO    volatile          // 读写

// 定义外�?�寄存器访问权限
#define __IM     volatile const   // �?�?
#define __OM     volatile         // �?�?
#define __IOM    volatile         // 读写


#define SA_NAME_MAX                             (10)
#define SA_INLINE                               static __inline

#define SA_VAL(val, min, max)                   ((val) < (min) ? (min) : ((val) > (max) ? (max) : (val)))
#define SA_list_init(list)                      { &(list), &(list)}
#define SA_val(val, min, max)                   ((val) < (min) ? (min) : ((val) > (max) ? (max) : (val)))
#define SA_container_of(ptr, type, member)      (type *)((char *)(ptr) - (char *) &((type *)0)->member)


// 计算数组元素�?�?
#define ARRAY_SIZE(x)                 (sizeof(x) / (sizeof((x)[0])))

// 字节交换�?
#define SWAP_BYTE(x)                  (((x) << 4) | ((x) >> 4))
// 16位整数字节交换宏
#define SWAP_UINT16(x)                (((x) << 8) | ((x) >> 8))
// 大�??模式字节�?�?�?16位整数宏
#define BEBufToUint16(byte1, byte2)   ((((byte1) & 0xFF) | ((uint16_t)byte2) << 8))
// 小�??模式字节�?�?�?16位整数宏
#define LEBufToUint16(byte1, byte2)   ((((uint16_t)byte1) << 8) | ((byte2) & 0xFF))

// 保留16位高字节
#define HIGH_BYTE(x)                  ((x) >> 8)
// 保留16位低字节
#define LOW_BYTE(x)                   ((x) & 0xFF)

// #define LOG(message)                  u1_printf("%s\n", message)

// #define Print_FUNC_LINE() \
//     u1_printf("[File: %s\tFunction: %s\tLine: %d]\n", __FILE__, __func__, __LINE__)


// 宏连�?
#define CONCAT(a, b)    a ## b
// 字�?�串�?
#define STR(s)          #s

// 最小值宏
#define BMIN(a, b)                    ((a) < (b) ? (a) : (b))
// 最大值宏   
#define BMAX(a, b)                    ((a) > (b) ? (a) : (b))
// 绝�?�值宏   
#define BABS(x)                       ((x) < 0 ? -(x) : (x))

// �?位宏
#define __SET_BIT(REG, MASK)          ((REG) |= (MASK))
// 清零�? 
#define __CLEAR_BIT(REG, MASK)        ((REG) &= ~(MASK))
// 读取位宏 
#define __READ_BIT(REG, MASK)         ((REG) & (MASK))
// 清空寄存器宏 
#define __CLEAR_REG(REG)              ((REG) = (0x0))
// 写入寄存器宏 
#define __WRITE_REG(REG, MASK)        ((REG) = (MASK))
// 寄存器值比较宏 
#define __CMP_REG(REG, MASK)          ((REG) == (MASK))
// 保留指定�?
#define __MASK_BIT(DATA,MASK)         ((DATA) & ((1<<MASK)))

// GPIO设置位宏
#define __GPIO_SET_BIT(REG, MASK)         __SET_BIT((REG->BSRR), (1<<MASK))
// GPIO复位位宏
#define __GPIO_RESET_BIT(REG, MASK)       __SET_BIT((REG->BSRR), ((1<<MASK)<<16UL))
// GPIO输入模式�?
#define __GPIO_INPUT(REG, MASK)           __CLEAR_BIT((REG->MODER), (1<<(MASK*2)))
// GPIO输出模式�?
#define __GPIO_OUTPUT(REG, MASK)          __SET_BIT((REG->MODER), (1<<(MASK*2)))
// GPIO输入读取�?
#define __GPIO_IN_READ(REG, MASK)         __CMP_REG(__READ_BIT((REG->IDR), (1<<MASK)), (1<<MASK))
// GPIO输出读取�?
#define __GPIO_OUT_READ(REG, MASK)        __CMP_REG(__READ_BIT((REG->ODR), (1<<MASK)), (1<<MASK))

#define __GPIO_WRITE_BIS(REG, MASK,VAL)   ((VAL)?__GPIO_SET_BIT(REG, MASK):__GPIO_RESET_BIT(REG, MASK))






// 函数声明
int  str_len(char *_str);
void str_cpy(char *_tar, char *_src);
int  str_cmp(char * s1, char * s2);
void mem_set(void *_ptr, int _value, int _len);
void mem_cpy(void *_dest, const void *_src, int _len);
uint16_t Check_CRC8(uint8_t *buf,uint16_t len);
uint16_t Check_Modbus_CRC16(uint8_t *buf,uint16_t len);
uint16_t Check_Xmodeme_CRC16(uint8_t *buf,uint16_t len);
uint16_t Check_Ymodeme_CRC16(uint8_t *buf,uint16_t len);

#endif // !__BSP_USER_LIB_H
