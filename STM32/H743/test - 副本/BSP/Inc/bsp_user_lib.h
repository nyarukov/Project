#ifndef __BSP_USER_LIB_H
#define __BSP_USER_LIB_H

#include <stdint.h>
#include <stdbool.h>

// 定义寄存器访问权限
#define __I     volatile const    // 只读
#define __O     volatile          // 只写
#define __IO    volatile          // 读写

// 定义外设寄存器访问权限
#define __IM     volatile const   // 只读
#define __OM     volatile         // 只写
#define __IOM    volatile         // 读写

// 计算数组元素个数
#define ARRAY_SIZE(x)                 (sizeof(x) / (sizeof((x)[0])))

// 字节交换宏
#define SWAP_BYTE(x)                  (((x) << 4) | ((x) >> 4))
// 16位整数字节交换宏
#define SWAP_UINT16(x)                (((x) << 8) | ((x) >> 8))
// 大端模式字节转换为16位整数宏
#define BEBufToUint16(byte1, byte2)   ((((byte1) & 0xFF) | ((uint16_t)byte2) << 8))
// 小端模式字节转换为16位整数宏
#define LEBufToUint16(byte1, byte2)   ((((uint16_t)byte1) << 8) | ((byte2) & 0xFF))


#define LOG(message)                  u1_printf("%s\n", message)

#define Print_FUNC_LINE() \
    u1_printf("[File: %s\tFunction: %s\tLine: %d]\n", __FILE__, __func__, __LINE__)


// 宏连接
#define CONCAT(a, b)    a ## b
// 字符串化
#define STR(s)          #s

// 最小值宏
#define BMIN(a, b)                    ((a) < (b) ? (a) : (b))
// 最大值宏   
#define BMAX(a, b)                    ((a) > (b) ? (a) : (b))
// 绝对值宏   
#define BABS(x)                       ((x) < 0 ? -(x) : (x))

// 置位宏
#define __SET_BIT(REG, MASK)          ((REG) |= (MASK))
// 清零宏 
#define __CLEAR_BIT(REG, MASK)        ((REG) &= ~(MASK))
// 读取位宏 
#define __READ_BIT(REG, MASK)         ((REG) & (MASK))
// 清空寄存器宏 
#define __CLEAR_REG(REG)              ((REG) = (0x0))
// 写入寄存器宏 
#define __WRITE_REG(REG, MASK)        ((REG) = (MASK))
// 寄存器值比较宏 
#define __CMP_REG(REG, MASK)          ((REG) == (MASK))

// GPIO设置位宏
#define __GPIO_SET_BIT(REG, MASK)         __SET_BIT((REG->BSRR), (1<<MASK))
// GPIO复位位宏
#define __GPIO_RESET_BIT(REG, MASK)       __SET_BIT((REG->BSRR), ((1<<MASK)<<16UL))
// GPIO输入模式宏
#define __GPIO_INPUT(REG, MASK)           __CLEAR_BIT((REG->MODER), (1<<(MASK*2)))
// GPIO输出模式宏
#define __GPIO_OUTPUT(REG, MASK)          __SET_BIT((REG->MODER), (1<<(MASK*2)))
// GPIO输入读取宏
#define __GPIO_IN_READ(REG, MASK)         __CMP_REG(__READ_BIT((REG->IDR), (1<<MASK)), (1<<MASK))
// GPIO输出读取宏
#define __GPIO_OUT_READ(REG, MASK)        __CMP_REG(__READ_BIT((REG->ODR), (1<<MASK)), (1<<MASK))


// 状态类型定义
typedef enum
{
  START_OK          = 0x00,  // 启动成功
  START_ERROR       = 0x01,  // 启动错误
  START_BUSY        = 0x02,  // 启动忙碌
  START_READ        = 0x03,  // 启动读取
  START_WRITE       = 0x04,  // 启动写入
  START_READ_WRITE  = 0x05,  // 启动读写
  START_TIMEOUT     = 0x06   // 启动超时
} StatusTypeDef;

// 函数声明
int  str_len(char *_str);            // 获取字符串长度
void str_cpy(char *_tar, char *_src); // 复制字符串
int  str_cmp(char * s1, char * s2);   // 比较字符串
void mem_set(char *_tar, char _data, int _len);  // 设置内存内容
uint16_t Check_CRC8(uint8_t *buf,uint16_t len);  // CRC8校验
uint16_t Check_Modbus_CRC16(uint8_t *buf,uint16_t len);  // Modbus CRC16校验
uint16_t Check_Xmodeme_CRC16(uint8_t *buf,uint16_t len);  // Xmodem CRC16校验
uint16_t Check_Ymodeme_CRC16(uint8_t *buf,uint16_t len);  // Ymodem CRC16校验

#endif // !__BSP_USER_LIB_H
