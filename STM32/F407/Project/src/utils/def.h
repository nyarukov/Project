#ifndef __DEF_H
#define __DEF_H

#include "middle.h"

// clang-format off
/************************************************内存访问属性宏定义*******************************************************/
#define __I                                                 volatile const          /* 只读属性 */
#define __O                                                 volatile                /* 只写属性 */
#define __IO                                                volatile                /* 读写属性 */

/* Memory attributes for peripherals accessible through AXI or AHB interfaces */
#define __IM                                                volatile const          /* 只读属性 */
#define __OM                                                volatile                /* 只写属性 */
#define __IOM                                               volatile                /* 读写属性 */

#define BF_NULL                                             ((void *)0)


#define SIZE_8						                        8
#define SIZE_16						                        16
#define SIZE_32						                        32
#define SIZE_64						                        64
#define SIZE_128					                        128
#define SIZE_256					                        256
#define SIZE_1K						                        1024
#define SIZE_4K						                        4096
#define SIZE_8K						                        8192
#define SIZE_16K						                    16384
/************************************************计算数组元素个数*******************************************************/
#define ARRAY_SIZE(x)                                       (sizeof(x) / (sizeof((x)[0])))

/************************************************字符串操作*******************************************************/

#define STR(s)                                              #s   /* 将参数转换为字符串 */

/*******************************************************************************************************/
#define BYTE_COUNT(bits)                                    (((bits) + 7) >> 3)         // 定义一个宏，用于将位数转换为字节数，向上取整
#define INT_COUNT(bits)                                     (((bits) + 15) >> 4)        // 定义一个宏，用于将位数转换为短整型数，向上取整

/************************************************值转换*******************************************************/
#define BMIN(a, b)                                          ((a) < (b) ? (a) : (b))             /* 最小值宏定义 */
#define BMAX(a, b)                                          ((a) > (b) ? (a) : (b))             /* 最大值宏定义 */
#define BABS(x)                                             ((x) < 0 ? -(x) : (x))              /* 绝对值宏定义 */

/************************************************字节操作*******************************************************/
#define SWAP_BYTE(x)                                        (((x) << 4) | ((x) >> 4))                                       /*字节交换*/
#define SWAP_UINT16(x)                                      (((x) << 8) | ((x) >> 8))                                       /*16位整数字节交换*/
#define BEBufToUint16(byte1, byte2)                         ((((byte1) & 0xFF) | ((uint16_t)byte2) << 8))                   /*大端模式字节转换为16位整数*/
#define LEBufToUint16(byte1, byte2)                         ((((uint16_t)byte1) << 8) | ((byte2) & 0xFF))                   /*小端模式字节转换为16位整数*/
#define HIGH_BYTE(x)                                        ((x) >> 8)                                                      /*保留16位高字节*/
#define LOW_BYTE(x)                                         ((x) & 0xFF)                                                    /*保留16位低字节*/

/************************************************操作寄存器位宏定义*******************************************************/
#define __SET_BIT(REG, MASK)                                ((REG) |= (MASK))               /* 设置寄存器指定位 */
#define __CLEAR_BIT(REG, MASK)                              ((REG) &= ~(MASK))              /* 清除寄存器指定位 */
#define __READ_BIT(REG, MASK)                               ((REG) & (MASK))                /* 读取寄存器指定位 */
#define __CLEAR_REG(REG)                                    ((REG) = (0x0))                 /* 清除寄存器所有位 */
#define __WRITE_REG(REG, MASK)                              ((REG) = (MASK))                /* 向寄存器写入值 */
#define __CMP_REG(REG, MASK)                                ((REG) == (MASK))               /* 比较寄存器值 */
#define __MASK_BIT(DATA, MASK)                              ((DATA) & ((1 << MASK)))        /*保留指定位*/


// 内存分配宏
#define BFmalloc(type, size)                                (type *)malloc(sizeof(type) * size);
#define BFfree(prt)                                         free(prt)

// clang-format on

// 空指针检查宏
#define Check_NULL(ptr)             \
    do                              \
    {                               \
        if ((ptr) == NULL)          \
        {                           \
            return BF_NULL_POINTER; \
        }                           \
    } while (0)

// CRC校验宏
#define Check_CRC(buf, len, crc)                                 \
    do                                                           \
    {                                                            \
        *(crc) = Check_Modbus_CRC16(buf, len - 2);               \
        if (LEBufToUint16(buf[len - 1], buf[len - 2]) != *(crc)) \
        {                                                        \
            return BF_CRC_ERROR;                                 \
        }                                                        \
    } while (0);

#include <stdio.h>

typedef enum
{
    BF_SUCCESS = 0,             // 成功
    BF_ERROR_LENGTH = -1,       // 长度错误
    BF_ERROR_MEMORY = -2,       // 拷贝错误
    BF_FAILURE = -3,            // 失败
    BF_ERROR = -4,              // 错误
    BF_INTI = 1,                // 初始化
    BF_CONNECT = 2,             // 链接
    BF_ADDR_ERROR = -5,         // 地址错误
    BF_CRC_ERROR = -6,          // CRC错误
    BF_ACK = 3,                 // 应答
    BF_NACK = -7,               // 未应答
    BF_FULL = 4,                // 满
    BF_EMPTY = 5,               // 空
    BF_INVALID_PARAM = -8,      // 无效的参数
    BF_NULL_POINTER = -9,       // 空指针
    BF_INVALID_LENGTH = -10,    // 无效长度
    BF_TOO_SMALL = -11,         // 过小
    BF_TOO_LARGE = -12,         // 过大
    BF_NOT_FOUND = -13,         // 未找到
    BF_PERMISSION_DENIED = -14, // 权限被拒绝
    BF_TIMEOUT = -15,           // 超时
    BF_NOT_SUPPORTED = -16,     // 不支持的操作
    BF_INTERRUPTED = -17,       // 被中断
    BF_OUT_OF_MEMORY = -18,     // 内存不足
    BF_NETWORK_ERROR = -19,     // 网络错误
    BF_FILE_NOT_FOUND = -20,    // 文件未找到
    BF_CORRUPT_DATA = -21,      // 数据损坏
    BF_DUPLICATE_ENTRY = -22    // 重复的条目
} Status;

#endif
