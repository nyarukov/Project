/**
 * @file main.c
 * @author yusaka (luckychaoyue1@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-05-23
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "bf_middle.h"

typedef struct
{
    int age;
}std;

void test_function1(void)
{
    
    struct bf_list *l1 = NULL;
    if(bf_list_empty(l1))
    {
        l1 = bf_malloc(bf_list);
        bf_list_init(l1);
    }
    
    struct bf_list *s1 = NULL;

    for (size_t i = 0; i < 10; i++)
    {
        s1 = bf_new_node(std);
        bf_get_elem(s1, std)->age =  i;
        bf_list_insert_later(l1, s1);
    }

    
    bf_list_foreach(l1){
        printf("Age: %d\n", bf_get_elem(count, std)->age);
    }
    
}


Status Module1_Recv(int _Src, int _Dst, void * _pBuf, int _Len)
{
    printf("--> Module1_Recv \n\t --> Src: %d \n\t --> Dst: %d \n\t --> Buf [%d] %s \r\n",_Src,_Dst,_Len,_pBuf);
}

Status Module2_Recv(int _Src, int _Dst, void * _pBuf, int _Len)
{
    printf("--> Module2_Recv \n\t --> Src: %d \n\t --> Dst: %d \n\t --> Buf [%d] %s \r\n",_Src,_Dst,_Len,_pBuf);
}

Status Module3_Recv(int _Src, int _Dst, void * _pBuf, int _Len)
{
    printf("--> Module3_Recv \n\t --> Src: %d \n\t --> Dst: %d \n\t --> Buf [%d] %s \r\n",_Src,_Dst,_Len,_pBuf);
}

Status Module4_Recv(int _Src, int _Dst, void * _pBuf, int _Len)
{
    printf("--> Module4_Recv \n\t --> Src: %d \n\t --> Dst: %d \n\t --> Buf [%d] %s \r\n",_Src,_Dst,_Len,_pBuf);
}

Status Module5_Recv(int _Src, int _Dst, void * _pBuf, int _Len)
{
    printf("--> Module5_Recv \n\t --> Src: %d \n\t --> Dst: %d \n\t --> Buf [%d] %s \r\n",_Src,_Dst,_Len,_pBuf);
}

#define _1STR1 "这是【模块1】发送给模块1的数据"
#define _1STR2 "这是【模块1】发送给模块2的数据"
#define _1STR3 "这是【模块1】发送给模块3的数据"
#define _1STR4 "这是【模块1】发送给模块4的数据"
#define _1STR5 "这是【模块1】发送给模块5的数据"

void test_function2(void)
{
    Routin_Register(1,Module1_Recv);
    Routin_Register(2,Module2_Recv);
    Routin_Register(3,Module3_Recv);
    Routin_Register(4,Module4_Recv);
    Routin_Register(5,Module5_Recv);
    Routin_Foreach();

    Route_Forward(1,1,_1STR1,str_len(_1STR1)+1);
    Route_Forward(1,2,_1STR2,str_len(_1STR2)+1);
    Route_Forward(1,3,_1STR3,str_len(_1STR3)+1);
    Route_Forward(1,4,_1STR4,str_len(_1STR4)+1);
    Route_Forward(1,5,_1STR5,str_len(_1STR5)+1);

    Routin_ID_Cancle(2);
    Routin_Foreach();

    Route_Forward(1, 1, _1STR1, str_len(_1STR1) + 1);
    Route_Forward(1, 2, _1STR2, str_len(_1STR2) + 1);
    Route_Forward(1, 3, _1STR3, str_len(_1STR3) + 1);
    Route_Forward(1, 4, _1STR4, str_len(_1STR4) + 1);
    Route_Forward(1, 5, _1STR5, str_len(_1STR5) + 1);

    Routin_Foreach();

    Route_Forward(1, 1, _1STR1, str_len(_1STR1) + 1);
    Route_Forward(1, 2, _1STR2, str_len(_1STR2) + 1);
    Route_Forward(1, 3, _1STR3, str_len(_1STR3) + 1);
    Route_Forward(1, 4, _1STR4, str_len(_1STR4) + 1);
    Route_Forward(1, 5, _1STR5, str_len(_1STR5) + 1);

    Routin_ALL_Cancle();
    Routin_Foreach();
}



void test_function3(void)
{
    uint8_t a[] = {0xA7, 0x79, 0xC7, 0x29, 0x3A, 0xA2, 0x59, 0x40};
    //Swap_Byte_Long(&a);

}

int main()
{
    // test_function1();

    test_function2();

    // test_function3();

    return 0;
}