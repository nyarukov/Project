/*
 * 项目名称: buffer
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-01
 * 最后修改日期: 2024-06-01 18:09:50
 * 描述: 缓冲区
 */

#ifndef __BUFFER_H
#define __BUFFER_H

// 头文件内容...
#include "middle.h"

typedef enum
{
    BUFFER_WRITE_BIT,           // 以位为单位向缓存区写入数据
    BUFFER_READ_BIT,            // 以位为单位从缓存区读取数据
    BUFFER_WRITE_BYTE,          // 以字节为单位向缓存区写入数据
    BUFFER_READ_BYTE,           // 以字节为单位从缓存区读取数据
    BUFFER_WRITE_SHORT,         // 以短整型为单位向缓存区写入数据
    BUFFER_READ_SHORT,          // 以短整型为单位从缓存区读取数据
    BUFFER_WRITE_INT,           // 以整型为单位向缓存区写入数据
    BUFFER_READ_INT,            // 以整型为单位从缓存区读取数据
    BUFFER_WRITE_LONG,          // 以长整型为单位向缓存区写入数据
    BUFFER_READ_LONG,           // 以长整型为单位从缓存区读取数据
    BUFFER_SET_SIZE,            // 设置缓存区大小
    BUFFER_SET_ADDRESS,         // 设置缓存区地址
    BUFFER_CLEAR,               // 清空缓存区 
    BUFFER_TOTAL_SIZE,          // 获取缓存区的总大小     
    BUFFER_READ_POINTER,        // 获取缓存区的读指针位置         
    BUFFER_WRITE_POINTER,       // 获取缓存区的写指针位置         
    BUFFER_SPACE_LEFT,          // 获取缓存区中剩余空间的大小    
    BUFFER_WRITTEN_COUNT        // 获取已经写入到缓存区的数据的数量，单位字节 
} Buffer_Cmd;

typedef struct Buffer_t
{
    uint8_t *Buf;
    uint32_t BufSize;
    __IO uint32_t Write;
    __IO uint32_t Read;
    __IO uint32_t Count;
} __attribute__((packed)) Buffer_t;

Status Buffer_Config(Buffer_t *_pBuf,
                     void *_Data,
                     uint32_t _Size);

Status Buffer_Operation(Buffer_t *_pBuf,
                        void *_Data,
                        uint32_t _Len,
                        Buffer_Cmd _Cmd,
                        uint32_t *_Para);
												
												
#endif
