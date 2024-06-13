/*
 * 项目名称: Queue
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-13 23:38:25
 * 最后修改日期: 2024-06-13 23:38:25
 * 描述: 队列
 */

#include "Queue.h"

// C 文件内容...

void queue_init(Queue *q)
{
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

bool enqueue(Queue *q, uint8_t data)
{
    if (q->count >= MAX_QUEUE_SIZE)
    {
        return false; // 队列已满
    }
    q->buffer[q->rear] = data;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->count++;
    return true;
}

bool dequeue(Queue *q, uint8_t *data)
{
    if (q->count == 0)
    {
        return false; // 队列为空
    }
    *data = q->buffer[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->count--;
    return true;
}

uint32_t queue_size(Queue *q)
{
    return q->count;
}

bool dequeue_line(Queue *q, uint8_t *data, uint32_t *len)
{
    uint32_t i = 0;
    while (queue_size(q) > 0)
    {
        dequeue(q, &data[i]);
        if (data[i] == '\n')
        {
            // 包括换行符在内的字符数
            *len = i + 1;
            return true;
        }
        i++;
    }
    return false;
}
