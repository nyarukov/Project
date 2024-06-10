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
} std;

void test_function1(void)
{

    struct bf_list *l1 = NULL;
    if (bf_list_empty(l1))
    {
        l1 = bf_malloc(bf_list);
        bf_list_init(l1);
    }

    struct bf_list *s1 = NULL;

    for (size_t i = 0; i < 10; i++)
    {
        s1 = bf_new_node(std);
        bf_get_elem(s1, std)->age = i;
        bf_list_insert_later(l1, s1);
    }

    bf_list_foreach(l1)
    {
        printf("Age: %d\n", bf_get_elem(count, std)->age);
    }
}

Status Module1_Recv(int _Src, int _Dst, void *_pBuf, int _Len)
{
    printf("--> Module1_Recv \n\t --> Src: %d \n\t --> Dst: %d \n\t --> Buf [%d] %s \r\n", _Src, _Dst, _Len, _pBuf);
}

Status Module2_Recv(int _Src, int _Dst, void *_pBuf, int _Len)
{
    printf("--> Module2_Recv \n\t --> Src: %d \n\t --> Dst: %d \n\t --> Buf [%d] %s \r\n", _Src, _Dst, _Len, _pBuf);
}

Status Module3_Recv(int _Src, int _Dst, void *_pBuf, int _Len)
{
    printf("--> Module3_Recv \n\t --> Src: %d \n\t --> Dst: %d \n\t --> Buf [%d] %s \r\n", _Src, _Dst, _Len, _pBuf);
}

Status Module4_Recv(int _Src, int _Dst, void *_pBuf, int _Len)
{
    printf("--> Module4_Recv \n\t --> Src: %d \n\t --> Dst: %d \n\t --> Buf [%d] %s \r\n", _Src, _Dst, _Len, _pBuf);
}

Status Module5_Recv(int _Src, int _Dst, void *_pBuf, int _Len)
{
    printf("--> Module5_Recv \n\t --> Src: %d \n\t --> Dst: %d \n\t --> Buf [%d] %s \r\n", _Src, _Dst, _Len, _pBuf);
}

#define _1STR1 "���ǡ�ģ��1�����͸�ģ��1������"
#define _1STR2 "���ǡ�ģ��1�����͸�ģ��2������"
#define _1STR3 "���ǡ�ģ��1�����͸�ģ��3������"
#define _1STR4 "���ǡ�ģ��1�����͸�ģ��4������"
#define _1STR5 "���ǡ�ģ��1�����͸�ģ��5������"

void test_function2(void)
{
    Routin_Register(1, Module1_Recv);
    Routin_Register(2, Module2_Recv);
    Routin_Register(3, Module3_Recv);
    Routin_Register(4, Module4_Recv);
    Routin_Register(5, Module5_Recv);
    Routin_Foreach();

    Route_Forward(1, 1, _1STR1, str_len(_1STR1) + 1);
    Route_Forward(1, 2, _1STR2, str_len(_1STR2) + 1);
    Route_Forward(1, 3, _1STR3, str_len(_1STR3) + 1);
    Route_Forward(1, 4, _1STR4, str_len(_1STR4) + 1);
    Route_Forward(1, 5, _1STR5, str_len(_1STR5) + 1);

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
    // Swap_Byte_Long(&a);
}
#define ARRAY_1(a) \
    {              \
        a          \
    }
#define ARRAY_2(a, b) \
    {                 \
        a, b          \
    }
#define ARRAY_3(a, b, c) \
    {                    \
        a, b, c          \
    }
#define ARRAY_4(a, b, c, d) \
    {                       \
        a, b, c, d          \
    }
#define ARRAY_5(a, b, c, d, e) \
    {                          \
        a, b, c, d, e          \
    }

#define GENERATE_ARRAY(...) GENERATE_ARRAY_N(__VA_ARGS__)
#define GENERATE_ARRAY_N(N, ...) GENERATE_ARRAY_##N(__VA_ARGS__)

void test_function4()
{
    int array1[] = GENERATE_ARRAY(1);
    int array2[] = GENERATE_ARRAY(1, 2);
    int array3[] = GENERATE_ARRAY(1, 2, 3);
    int array4[] = GENERATE_ARRAY(1, 2, 3, 4);
    int array5[] = GENERATE_ARRAY(1, 2, 3, 4, 5);

    // Now let's print out the arrays to see what they look like
    for (int i = 0; i < sizeof(array1) / sizeof(array1[0]); ++i)
    {
        printf("%d ", array1[i]);
    }
    printf("\n");

    for (int i = 0; i < sizeof(array2) / sizeof(array2[0]); ++i)
    {
        printf("%d ", array2[i]);
    }
    printf("\n");

    for (int i = 0; i < sizeof(array3) / sizeof(array3[0]); ++i)
    {
        printf("%d ", array3[i]);
    }
    printf("\n");

    for (int i = 0; i < sizeof(array4) / sizeof(array4[0]); ++i)
    {
        printf("%d ", array4[i]);
    }
    printf("\n");

    for (int i = 0; i < sizeof(array5) / sizeof(array5[0]); ++i)
    {
        printf("%d ", array5[i]);
    }
    printf("\n");
}

int main()
{
    // test_function1();

    // test_function2();

    // test_function3();
    test_function4();
    return 0;
}