#include "A.h"
#include "stdio.h"


typedef struct 
{
    unsigned char name[10];
    struct bf_Dlist list;
} MyStruct;


int main(void)
{
    printf("A\r\n");

    // 分配新节点
    MyStruct *A1 = bf_new_node(MyStruct);
    if (A1 == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    bf_Dlist_init(&A1->list);

    // 设定一些数据
    snprintf((char *)A1->name, sizeof(A1->name), "Node1");

    // 打印节点信息
    printf("Created node with name: %s\n", A1->name);

    // 释放分配的内存
    free(A1);

    return 0;
}