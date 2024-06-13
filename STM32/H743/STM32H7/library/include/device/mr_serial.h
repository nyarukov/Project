/*
*@copyright (c) 2023-2024，MR 开发团队
*
*@license SPDX-许可证-标识符：Apache-2.0
*
*@date 2023-10-20 MacRsh 第一版
*/

#ifndef _MR_SERIAL_H_
#define _MR_SERIAL_H_

#include "include/mr_api.h"

#ifdef __cplusplus
extern "C" {
#endif/*__cplusplus*/

#define MR_USING_SERIAL
#ifdef MR_USING_SERIAL

/**
*@addtogroup 序列号
*@{
*/
/**
*@brief 串行数据位。
*/
#define MR_SERIAL_DATA_BITS_5           (5)/**< 5 位数据*/
#define MR_SERIAL_DATA_BITS_6           (6)/**< 6 位数据*/
#define MR_SERIAL_DATA_BITS_7           (7)/**< 7 位数据*/
#define MR_SERIAL_DATA_BITS_8           (8)/**< 8 位数据*/
/**
*@brief 串行停止位。
*/
#define MR_SERIAL_STOP_BITS_1           (1)/**< 1 位停止*/
#define MR_SERIAL_STOP_BITS_2           (2)/**< 2 位停止*/
#define MR_SERIAL_STOP_BITS_3           (3)/**< 3 位停止*/
#define MR_SERIAL_STOP_BITS_4           (4)/**< 4 位停止*/
/**
*@brief 串行奇偶校验。
*/
#define MR_SERIAL_PARITY_NONE           (0)/**< 无奇偶校验*/
#define MR_SERIAL_PARITY_EVEN           (1)/**< 偶校验*/
#define MR_SERIAL_PARITY_ODD            (2)/**< 奇校验*/
/**
*@brief 串行位顺序。
*/
#define MR_SERIAL_BIT_ORDER_LSB         (0)/**< LSB优先*/
#define MR_SERIAL_BIT_ORDER_MSB         (1)/**< 高位优先*/
/**
*@brief 串行极性。
*/
#define MR_SERIAL_POLARITY_NORMAL       (0)/**< 正常极性*/
#define MR_SERIAL_POLARITY_INVERTED     (1)/**< 极性反转*/
/**
*@brief 串行默认配置。
*/
#define MR_SERIAL_CONFIG_DEFAULT        \
{                                       \
    115200,                             \
    MR_SERIAL_DATA_BITS_8,              \
    MR_SERIAL_STOP_BITS_1,              \
    MR_SERIAL_PARITY_NONE,              \
    MR_SERIAL_BIT_ORDER_LSB,            \
    MR_SERIAL_POLARITY_NORMAL,          \
}

/**
*@brief 串行配置结构。
*/
struct mr_serial_config
{
    uint32_t baud_rate;/**< 波特率*/
    int data_bits;/**< 数据位*/
    int stop_bits;/**< 停止位*/
    int parity;/**< 奇偶校验*/
    int bit_order;/**< 位顺序*/
    int polarity;/**< 极性*/
};

/**
*@brief 串行控制命令。
*/
#define MR_IOC_SERIAL_SET_CONFIG        MR_IOC_SCFG/**< 设置配置命令*/
#define MR_IOC_SERIAL_SET_RD_BUFSZ      MR_IOC_SRBSZ/**< 设置读缓冲区大小命令*/
#define MR_IOC_SERIAL_SET_WR_BUFSZ      MR_IOC_SWBSZ/**< 设置写入缓冲区大小命令*/
#define MR_IOC_SERIAL_CLR_RD_BUF        MR_IOC_CRBD/**< 清除读缓冲区命令*/
#define MR_IOC_SERIAL_CLR_WR_BUF        MR_IOC_CWBD/**< 清除写缓冲区命令*/
#define MR_IOC_SERIAL_SET_RD_CALL       MR_IOC_SRCB/**< 设置读取回调命令*/
#define MR_IOC_SERIAL_SET_WR_CALL       MR_IOC_SWCB/**< 设置写回调命令*/

#define MR_IOC_SERIAL_GET_CONFIG        MR_IOC_GCFG/**< 获取配置命令*/
#define MR_IOC_SERIAL_GET_RD_BUFSZ      MR_IOC_GRBSZ/**< 获取读取缓冲区大小命令*/
#define MR_IOC_SERIAL_GET_WR_BUFSZ      MR_IOC_GWBSZ/**< 获取写入缓冲区大小命令*/
#define MR_IOC_SERIAL_GET_RD_DATASZ     MR_IOC_GRBDSZ/**< 获取读取数据大小命令*/
#define MR_IOC_SERIAL_GET_WR_DATASZ     MR_IOC_GWBDSZ/**< 获取写入数据大小命令*/
#define MR_IOC_SERIAL_GET_RD_CALL       MR_IOC_GRCB/**< 获取读取回调命令*/
#define MR_IOC_SERIAL_GET_WR_CALL       MR_IOC_GWCB/**< 获取写入回调命令*/

#ifdef MR_USING_SERIAL_DMA
#define MR_IOC_SERIAL_SET_RD_DMA_BUFSZ  (0x01)/**< 设置读取 DMA 缓冲区大小命令*/
#define MR_IOC_SERIAL_SET_WR_DMA_BUFSZ  (0x02)/**< 设置写入 DMA 缓冲区大小命令*/

#define MR_IOC_SERIAL_GET_RD_DMA_BUFSZ  (-(0x01))/**< 获取读取 DMA 缓冲区大小命令*/
#define MR_IOC_SERIAL_GET_WR_DMA_BUFSZ  (-(0x02))/**< 获取写入 DMA 缓冲区大小命令*/
#endif/*MR_USING_SERIAL_DMA*/
/**
*@brief 串行数据类型。
*/
typedef uint8_t mr_serial_data_t;/**< 串行读/写数据类型*/
/**
*@brief 系列 ISR 事件。
*/
#define MR_ISR_SERIAL_RD_INT            (MR_ISR_RD | (0x01))/**< 读取中断事件*/
#define MR_ISR_SERIAL_WR_INT            (MR_ISR_WR | (0x02))/**< 写中断事件*/
#define MR_ISR_SERIAL_RD_DMA            (MR_ISR_RD | (0x03))/**< 读取DMA中断事件*/
#define MR_ISR_SERIAL_WR_DMA            (MR_ISR_WR | (0x04))/**< 写入DMA中断事件*/
/**
*@brief 串行结构。
*/
struct mr_serial
{
    struct mr_dev dev;      /**< 设备结构*/

    struct mr_serial_config config;     /**< 配置*/
    struct mr_ringbuf rd_fifo;      /**< 读取 FIFO*/
    struct mr_ringbuf wr_fifo;/**< 写入 FIFO*/
    size_t rd_bufsz;/**< 读取缓冲区大小*/
    size_t wr_bufsz;/**< 写入缓冲区大小*/
#ifdef MR_USING_SERIAL_DMA
    uint8_t *dma_rd_buf;/**< 读取 DMA 缓冲区*/
    uint8_t *dma_wr_buf;/**< 写入 DMA 缓冲区*/
    size_t dma_rd_bufsz;/**< 读取 DMA 缓冲区大小*/
    size_t dma_wr_bufsz;/**< 写入 DMA 缓冲区大小*/
#endif/*MR_USING_SERIAL_DMA*/
    int nonblock_state;/**< 非阻塞状态*/
};

/**
*@brief 串行操作结构。
*/
struct mr_serial_ops
{
    int (*configure)(struct mr_serial *serial, struct mr_serial_config *config);
    int (*read)(struct mr_serial *serial, uint8_t *data);
    int (*write)(struct mr_serial *serial, uint8_t data);
    void (*start_tx)(struct mr_serial *serial);
    void (*stop_tx)(struct mr_serial *serial);

#ifdef MR_USING_SERIAL_DMA
    void (*start_dma_tx)(struct mr_serial *serial, uint8_t *buf, size_t count);
    void (*stop_dma_tx)(struct mr_serial *serial);
    void (*start_dma_rx)(struct mr_serial *serial, uint8_t *buf, size_t count);
    void (*stop_dma_rx)(struct mr_serial *serial);
#endif/*MR_USING_SERIAL_DMA*/
};

int mr_serial_register(struct mr_serial *serial, const char *path, struct mr_drv *drv);
/**@}*/

#endif/*MR_USING_SERIAL*/

#ifdef __cplusplus
}
#endif/* __cplusplus */

#endif/*_MR_SERIAL_H_*/
