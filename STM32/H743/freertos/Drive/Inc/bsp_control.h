#ifndef __bsp_control_H
#define __bsp_control_H

/************************************************内存访问属性宏定义*******************************************************/
#define __I     volatile const    /* 只读属性 */
#define __O     volatile          /* 只写属性 */
#define __IO    volatile          /* 读写属性 */

/* Memory attributes for peripherals accessible through AXI or AHB interfaces */
#define __IM     volatile const   /* 只读属性 */
#define __OM     volatile         /* 只写属性 */
#define __IOM    volatile         /* 读写属性 */

/************************************************计算数组元素个数*******************************************************/
#define COUNTOF(__BUFFER__)       (sizeof(__BUFFER__) / sizeof(*(__BUFFER__)))

/************************************************字符串操作*******************************************************/
#define CONCAT(a, b)    a ## b  /* 合并两个标识符 */
#define STR(s)          #s      /* 将参数转换为字符串 */


/************************************************值转换*******************************************************/
#define BMIN(a, b) ((a) < (b) ? (a) : (b))     /* 最小值宏定义 */
#define BMAX(a, b) ((a) > (b) ? (a) : (b))     /* 最大值宏定义 */
#define BABS(x) ((x) < 0 ? -(x) : (x))         /* 绝对值宏定义 */


/************************************************操作寄存器位宏定义*******************************************************/
#define __SET_BIT(REG, MASK)         ((REG) |= (MASK))      /* 设置寄存器指定位 */
#define __CLEAR_BIT(REG, MASK)       ((REG) &= ~(MASK))     /* 清除寄存器指定位 */
#define __READ_BIT(REG, MASK)        ((REG) & (MASK))       /* 读取寄存器指定位 */
#define __CLEAR_REG(REG)             ((REG) = (0x0))        /* 清除寄存器所有位 */
#define __WRITE_REG(REG, MASK)       ((REG) = (MASK))       /* 向寄存器写入值 */
#define __CMP_REG(REG, MASK)         ((REG) == (MASK))      /* 比较寄存器值 */



/************************************************GPIO 操作宏定义*******************************************************/
/**
 * @brief 设置 GPIO 寄存器指定位
 * @param REG GPIOx
 * @param MASK 指定位
 */
#define __GPIO_SET_BIT(REG, MASK)         __SET_BIT((REG->BSRR), (1<<MASK))
/**
 * @brief 复位 GPIO 寄存器指定位
 * @param REG GPIOx
 * @param MASK 指定位
 */
#define __GPIO_RESET_BIT(REG, MASK)       __SET_BIT((REG->BSRR), ((1<<MASK)<<16UL))

/**
 * @brief 设置 GPIO 寄存器指定位为输入
 * @param REG GPIOx
 * @param MASK 指定位
 */
#define __GPIO_INPUT(REG, MASK)           __CLEAR_BIT((REG->MODER), (1<<(MASK*2)))
/**
 * @brief 设置 GPIO 寄存器指定位为输出
 * @param REG GPIOx
 * @param MASK 指定位
 */
#define __GPIO_OUTPUT(REG, MASK)          __SET_BIT((REG->MODER), (1<<(MASK*2)))

/**
 * @brief 读取 GPIO 输入寄存器指定位
 * @param REG GPIOx
 * @param MASK 指定位
 */
#define __GPIO_IN_READ(REG, MASK)        __CMP_REG(__READ_BIT((REG->IDR), (1<<MASK)), (1<<MASK))

/**
 * @brief 读取 GPIO 输出寄存器指定位
 * @param REG GPIOx
 * @param MASK 指定位
 */
#define __GPIO_OUT_READ(REG, MASK)        __CMP_REG(__READ_BIT((REG->ODR), (1<<MASK)), (1<<MASK))

/************************************************状态类型定义*******************************************************/
typedef enum
{
  START_OK          = 0x00,   /* 启动成功 */
  START_ERROR       = 0x01,   /* 启动错误 */
  START_BUSY        = 0x02,   /* 启动忙碌 */
  START_READ        = 0x03,   /* 启动读取 */
  START_WRITE       = 0x04,   /* 启动写入 */
  START_READ_WRITE  = 0x05,   /* 启动读写 */
  START_TIMEOUT     = 0x06    /* 启动超时 */
} StatusTypeDef;

#endif // !__bsp_control_H
