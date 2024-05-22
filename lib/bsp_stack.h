#ifndef __BSP_STACK_H
#define __BSP_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;
typedef struct
{
    DataType *data;
    int top;
    int capacity;
} stack;

void stack_init(stack *_ps);
void stack_push(stack *_ps, DataType _data);
void stack_pop(stack *_ps);

void stack_delete(stack *_ps);
DataType stack_top(stack *_ps);
void print_stack(stack *_ps);

#endif // !__BSP_STACK_H