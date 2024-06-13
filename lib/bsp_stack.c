#include "bsp_stack.h"

void stack_init(stack *_ps)
{
    assert(_ps);
    _ps->data = NULL;
    _ps->top = _ps->capacity = 0;
}

void stack_push(stack *_ps, DataType _data)
{
    assert(_ps);
    if (_ps->top == _ps->capacity)
    {
        int newcapaity = (_ps->capacity == 0) ? 4 : _ps->capacity * 2;
        DataType *newdata = realloc(_ps->data, sizeof(DataType) * newcapaity);
        if (newdata == NULL)
        {
            exit(-1);
        }
        _ps->data = newdata;
        _ps->capacity = newcapaity;
    }
    _ps->data[_ps->top] = _data;
    _ps->top++;
}
void stack_pop(stack *_ps)
{
    assert(_ps);
    assert(_ps->top > 0);
    _ps->top--;
}

void stack_delete(stack *_ps)
{
    assert(_ps->data);
    free(_ps->data);
    _ps->data = NULL;
}

DataType stack_top(stack *_ps){
    assert(_ps);
    assert(_ps->top>0);
    return _ps->data[_ps->top]-1;
}

void print_stack(stack *_ps)
{
    if(_ps->top==0){
        printf("stack null");
        exit(-1);
    }
    int top =_ps->top-1;
    do
    {
         printf("%d\t", _ps->data[top]);
    } while (top--);
}
