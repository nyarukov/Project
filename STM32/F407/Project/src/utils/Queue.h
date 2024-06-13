/*
 * 项目名称: Queue
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-13 23:38:25
 * 最后修改日期: 2024-06-13 23:38:25
 * 描述: 队列
 */

#ifndef __QUEUE_H
#define __QUEUE_H

// 头文件内容...
#include "middle.h"

#define MAX_QUEUE_SIZE 1024

typedef struct
{
    uint8_t buffer[MAX_QUEUE_SIZE];
    uint32_t front;
    uint32_t rear;
    uint32_t count;
    volatile bool mutex_lock;
} Queue;

void queue_init(Queue *q);
bool enqueue(Queue *q, uint8_t data);
bool dequeue(Queue *q, uint8_t *data);
bool dequeue_line(Queue *q, uint8_t *data, uint32_t *len);
#endif
