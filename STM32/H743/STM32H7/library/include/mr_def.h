/*
 * @copyright (c) 2023-2024, MR Development Team
 *
 * @license SPDX-License-Identifier: Apache-2.0
 *
 * @date 2023-10-18    MacRsh       First version
 */

#ifndef _MR_DEF_H_
#define _MR_DEF_H_

#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "mr_config.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @addtogroup Version
 * @{
 */
#define MR_VERSION_MAJOR                0                           /**< Major version (X.y.z) */
#define MR_VERSION_MINOR                0                           /**< Minor version (x.Y.z) */
#define MR_VERSION_PATCH                9                           /**< Patch version (x.y.Z) */

/**
 * @brief Version hex.
 *
 * @note [23:16] major version, [15:8] minor version, [7:0] patch version, [31:24] reserved.
 */
#define MR_VERSION                      (MR_VERSION_MAJOR << 16 | MR_VERSION_MINOR << 8 | MR_VERSION_PATCH)
/** @} */

/**
 * @addtogroup Compiler
 * @{
 */
#if defined(__ARMCC_VERSION)
#define MR_SECTION(x)              	    __attribute__((section(x))) /**< Section */
#define MR_USED                    	    __attribute__((used))       /**< Used */
#define MR_WEAK                    	    __attribute__((weak))       /**< Weak */
#define MR_INLINE                  	    static __inline             /**< Inline */
typedef int ssize_t;                                                /**< ssize_t type */
#elif defined (__IAR_SYSTEMS_ICC__)
#define MR_SECTION(x)               	@ x                         /**< Section */
#define MR_USED                     	__root                      /**< Used */
#define MR_WEAK                     	__weak                      /**< Weak */
#define MR_INLINE                   	static inline               /**< Inline */
#elif defined (__GNUC__)
#define MR_SECTION(x)                   __attribute__((section(x))) /**< Section */
#define MR_USED                         __attribute__((used))       /**< Used */
#define MR_WEAK                         __attribute__((weak))       /**< Weak */
#define MR_INLINE                       static __inline             /**< Inline */
#elif defined (__ADSPBLACKFIN__)
#define MR_SECTION(x)               	__attribute__((section(x))) /**< Section */
#define MR_USED                     	__attribute__((used))       /**< Used */
#define MR_WEAK                     	__attribute__((weak))       /**< Weak */
#define MR_INLINE                   	static inline               /**< Inline */
#elif defined (_MSC_VER)
#define MR_SECTION(x)                                               /**< Section */
#define MR_USED                                                     /**< Used */
#define MR_WEAK                                                     /**< Weak */
#define MR_INLINE                   	static __inline             /**< Inline */
#elif defined (__TASKING__)
#define MR_SECTION(x)               	__attribute__((section(x))) /**< Section */
#define MR_USED                         \
    __attribute__((used, protect))                                  /**< Used */
#define MR_WEAK                     	__attribute__((weak))       /**< Weak */
#define MR_INLINE                   	static inline               /**< Inline */
#else
#define MR_SECTION(x)                   __attribute__((section(x))) /**< Section */
#define MR_USED                         __attribute__((used))       /**< Used */
#define MR_WEAK                         __attribute__((weak))       /**< Weak */
#define MR_INLINE                       static __inline             /**< Inline */
#endif/*__ARMCC_版本*/
/**@}*/
/**
*@addtogroup 自动初始化
*@{
*/
typedef void (*mr_init_fn_t)(void);     /**< 自动初始化函数*/
#define MR_INIT_EXPORT(fn, level) \
    MR_USED const mr_init_fn_t _mr_auto_init_##fn MR_SECTION("mr_auto_init."level) = fn
#define MR_INIT_BOARD_EXPORT(fn)        MR_INIT_EXPORT(fn, "1")/**< 导出 Board 初始化函数*/
#define MR_INIT_DRV_EXPORT(fn)          MR_INIT_EXPORT(fn, "2")/**< 导出一个Driver初始化函数*/
#define MR_INIT_DEV_EXPORT(fn)          MR_INIT_EXPORT(fn, "3")/**< 导出设备初始化函数*/
#define MR_INIT_APP_EXPORT(fn)          MR_INIT_EXPORT(fn, "4")/**< 导出App初始化函数*/
/**@}*/
/**
*@addtogroup 基本
*@{
*/
#define MR_NULL                         ((void *)0)                 /**< Null pointer */
#define MR_DISABLE                      (0)                         /**< Disable */
#define MR_ENABLE                       (1)                         /**< Enable */
#define MR_FALSE                        (0)                         /**< False */
#define MR_TRUE                         (1)                         /**< True */
/** @} */

/**
 * @addtogroup Error
 * @{
 */
#define MR_EOK                          (0)                         /**< No error */
#define MR_ENOMEM                       (-1)                        /**< No enough memory */
#define MR_EIO                          (-2)                        /**< I/O error */
#define MR_ENOTFOUND                    (-3)/**< 未找到*/
#define MR_EBUSY                        (-4)                        /**< Resource busy */
#define MR_EEXIST                       (-5)                        /**< Exists */
#define MR_ENOTSUP                      (-6)                        /**< Operation not supported */
#define MR_EINVAL                       (-7)                        /**< Invalid argument */
#define MR_ETIMEOUT                     (-8)/**< 超时*/
/**@}*/
/**
*@addtogroup内存
*@{
*/
/**
*@brief 堆块结构。
*/
struct mr_heap_block
{
    struct mr_heap_block *next;                                     /**< Point to next block */
    uint32_t size: 31;                                              /**< Size of this block */
    uint32_t allocated: 1;                                          /**< Allocated flag */
};
/**@}*/
/**
*@addtogroup 列表
*@{
*/
/**
*@brief 列表结构。
*/
struct mr_list
{
    struct mr_list *next;                                           /**< Point to next node */
    struct mr_list *prev;                                           /**< Point to prev node */
};
/**@}*/
/**
*@addtogroup 环形缓冲区
*@{
*/
/**
*@brief 环形缓冲区结构。
*/
struct mr_ringbuf
{
    uint8_t *buffer;/**< 缓冲池*/
    size_t size;/**< 缓冲池大小*/
    uint32_t read_mirror: 1;/**< 读取镜像标志*/
    uint32_t write_mirror: 1;/**< 写入镜像标志*/
    uint32_t _reserved: 30;/**< 保留*/
    size_t read_index;/**< 读取索引*/
    size_t write_index;/**< 写入索引*/
};
/**@}*/
/**
*@addtogroup AVL 树
*@{
*/
/**
*@brief AVL 树结构。
*/
struct mr_avl
{
    int height;                                                     /**< Balance factor */
    uint32_t value;                                                 /**< Key-hold */
    struct mr_avl *left_child;                                      /**< Point to left-child node */
    struct mr_avl *right_child;                                     /**< Point to right-child node */
};
/** @} */

/**
 * @addtogroup Device
 * @{
 */
#define MR_MAGIC_NUMBER                 (0xdeadbeef)                /**< Magic number */

#define MR_SYNC                         (0)                         /**< Synchronous */
#define MR_ASYNC                        (1)                         /**< Asynchronous */

/* [31:24] are for lock, [23:0] reserved */
#define MR_LOCK_RD                      (0x01 << 24)                /**< Read lock */
#define MR_LOCK_WR                      (0x02 << 24)                /**< Write lock */
#define MR_LOCK_RDWR                    (0x03 << 24)                /**< Read/write lock */
#define MR_LOCK_NONBLOCK                (0x04 << 24)                /**< Non-blocking lock */
#define MR_LOCK_SLEEP                   (0x08 << 24)                /**< Sleep lock */

/* [31:24] are for basic flags, [23:0] can define user flags */
#define MR_O_CLOSED                     (0)                 /**< 关闭标志*/
#define MR_O_QUERY                      (0)                 /**< 查询标志*/
#define MR_O_RDONLY                     (0x01 << 24)        /**< 只读标志*/
#define MR_O_WRONLY                     (0x02 << 24)        /**< 只写标志*/
#define MR_O_RDWR                       (0x03 << 24)        /**< 读/写标志*/
#define MR_O_NONBLOCK                   (0x04 << 24)        /**< 非阻塞标志*/

/*[31:24]用于基本命令，[23:0]可以定义用户命令。 (>0)：用户 -> 设备，(<0)：用户 <-设备*/
#define MR_IOC_SPOS                     (0x01 << 24)/**< 设置位置命令*/
#define MR_IOC_SRCB                     (0x02 << 24)/**< 设置读取回调命令*/
#define MR_IOC_SWCB                     (0x03 << 24)/**< 设置写回调命令*/
#define MR_IOC_SCFG                     (0x04 << 24)/**< 设置配置命令*/
#define MR_IOC_SRBSZ                    (0x05 << 24)/**< 设置读缓冲区大小命令*/
#define MR_IOC_SWBSZ                    (0x06 << 24)/**< 设置写入缓冲区大小命令*/
#define MR_IOC_CRBD                     (0x07 << 24)/**< 清除读缓冲区数据命令*/
#define MR_IOC_CWBD                     (0x08 << 24)/**< 清除写缓冲区数据命令*/

#define MR_IOC_GPOS                     (-(0x01 << 24))/**< 获取位置命令*/
#define MR_IOC_GRCB                     (-(0x02 << 24))/**< 获取读取回调命令*/
#define MR_IOC_GWCB                     (-(0x03 << 24))/**< 获取写入回调命令*/
#define MR_IOC_GCFG                     (-(0x04 << 24))/**< 获取配置命令*/
#define MR_IOC_GRBSZ                    (-(0x05 << 24))/**< 获取读取缓冲区大小命令*/
#define MR_IOC_GWBSZ                    (-(0x06 << 24))/**< 获取写入缓冲区大小命令*/
#define MR_IOC_GRBDSZ                   (-(0x07 << 24))/**< 获取读缓冲区数据大小命令*/
#define MR_IOC_GWBDSZ                   (-(0x08 << 24))/**< 获取写入缓冲区数据大小命令*/
/*[31:24]用于中断标志，[23:0]可以定义用户标志*/
#define MR_ISR_RD                       (0x01 << 24)                /**< Read interrupt event */
#define MR_ISR_WR                       (0x02 << 24)                /**< Write interrupt event */
#define MR_ISR_MASK                     (0x7f << 24)/**< 中断事件掩码*/

/**
*@brief 驱动程序结构。
*/
struct mr_drv
{
    void *ops;/**< 操作*/
    void *data;/**< 数据*/
};

/**
 * @brief Device types.
 */
enum mr_dev_type
{
    MR_DEV_TYPE_ROOT = 0,                                           /**< Root device */
    MR_DEV_TYPE_ADC,                                                /**< ADC device */
    MR_DEV_TYPE_CAN,                                                /**< CAN device */
    MR_DEV_TYPE_DAC,                                                /**< DAC device */
    MR_DEV_TYPE_I2C,                                                /**< I2C device */
    MR_DEV_TYPE_PIN,                                                /**< PIN device */
    MR_DEV_TYPE_SERIAL,                                             /**< Serial device */
    MR_DEV_TYPE_SPI,                                                /**< SPI device */
    MR_DEV_TYPE_TIMER,                                              /**< Timer device */
    MR_DEV_TYPE_PWM,                                                /**< PWM device */
    MR_DEV_TYPE_COMPONENT,                                          /**< Component device */
};

struct mr_dev;

/**
*@brief 设备操作结构。
*/
struct mr_dev_ops
{
    int (*open)(struct mr_dev *dev);
    int (*close)(struct mr_dev *dev);
    ssize_t (*read)(struct mr_dev *dev, void *buf, size_t count);
    ssize_t (*write)(struct mr_dev *dev, const void *buf, size_t count);
    int (*ioctl)(struct mr_dev *dev, int cmd, void *args);
    ssize_t (*isr)(struct mr_dev *dev, int event, void *args);
};

/**
*@brief 设备回调结构。
*/
struct mr_dev_call
{
    struct mr_list list;/**< 回调列表*/

    void (*fn)(int desc, void *args);/**< 回调函数*/
};

/**
*@brief 设备结构。
*/
struct mr_dev
{
    uint32_t magic;                                                 /**< Magic number */
#ifndef MR_CFG_DEV_NAME_LEN
#define MR_CFG_DEV_NAME_LEN             (8)
#endif /* MR_CFG_DEV_NAME_LEN */
    char name[MR_CFG_DEV_NAME_LEN];/**< 名称*/
    uint32_t type;/**< 类型*/
    int flags;/**< 标志*/
    void *parent;/**< 父设备*/
    struct mr_list list;/**< 同级设备列表*/
    struct mr_list clist;/**< 子设备列表*/

    size_t ref_count;/**< 引用计数*/
#ifdef MR_USING_RDWR_CTL
    volatile uint32_t lock;/**< 锁定标志*/
#endif /* MR_USING_RDWR_CTL */
    int sync;/**< 同步标志*/
    int position;/**< 位置*/

    struct mr_list rd_call_list;/**< 读取回调列表*/
    struct mr_list wr_call_list;/**< 写入回调列表*/

    const struct mr_dev_ops *ops;/**< 操作*/
    const struct mr_drv *drv;/**< 驱动程序*/
};

/**
*@brief 设备描述符结构。
*/
struct mr_dev_desc
{
    struct mr_dev *dev;             /**< 设备*/
    int flags;                      /**< 打开标志*/
    int position;                   /**< 当前位置*/
    struct mr_dev_call rd_call;     /**< 读取回调*/
    struct mr_dev_call wr_call;     /**< 写入回调*/
};
/** @} */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _MR_DEF_H_ */
