/*
 * 项目名称: DO
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-03 23:11:28
 * 最后修改日期: 2024-06-03 23:11:28
 * 描述: DO驱动
 */

#include "DO.h"

// C 文件内容...

// clang-format off

#if DO_NUM > 0

#define INIT_DO_PIN(DOx)        IO_Init(DOx, DO_MODE, DO_OTYP, GPIO_PuPd_NOPULL, DO_SPEED)
#define DO_WRITE(DOx, Value)    IO_Write(DOx, Value)

DO_PARA DO;

void DO_Init(void)
{
    #if defined(DO1)
        INIT_DO_PIN(DO1);
    #endif
    #if defined(DO2)
        INIT_DO_PIN(DO2);
    #endif
    #if defined(DO3)
        INIT_DO_PIN(DO3);
    #endif
    #if defined(DO4)
        INIT_DO_PIN(DO4);
    #endif
    #if defined(DO5)
        INIT_DO_PIN(DO5);
    #endif
    #if defined(DO6)
        INIT_DO_PIN(DO6);
    #endif
    #if defined(DO7)
        INIT_DO_PIN(DO7);
    #endif
    #if defined(DO8)
        INIT_DO_PIN(DO8);
    #endif
    /***********************************************/
    #if defined(DO9)
        INIT_DO_PIN(DO9);
    #endif
    #if defined(DO10)
        INIT_DO_PIN(DO10);
    #endif
    #if defined(DO11)
        INIT_DO_PIN(DO11);
    #endif
    #if defined(DO12)
        INIT_DO_PIN(DO12);
    #endif
    #if defined(DO13)
        INIT_DO_PIN(DO13);
    #endif
    #if defined(DO14)
        INIT_DO_PIN(DO14);
    #endif
    #if defined(DO15)
        INIT_DO_PIN(DO15);
    #endif
    #if defined(DO16)
        INIT_DO_PIN(DO16);
    #endif
    /***********************************************/
    #if defined(DO17)
        INIT_DO_PIN(DO17);
    #endif
    #if defined(DO18)
        INIT_DO_PIN(DO18);
    #endif
    #if defined(DO19)
        INIT_DO_PIN(DO19);
    #endif
    #if defined(DO20)
        INIT_DO_PIN(DO20);
    #endif
    #if defined(DO21)
        INIT_DO_PIN(DO21);
    #endif
    #if defined(DO22)
        INIT_DO_PIN(DO22);
    #endif
    #if defined(DO23)
        INIT_DO_PIN(DO23);
    #endif
    #if defined(DO24)
        INIT_DO_PIN(DO24);
    #endif
    /***********************************************/
    #if defined(DO25)
        INIT_DO_PIN(DO25);
    #endif
    #if defined(DO26)
        INIT_DO_PIN(DO26);
    #endif
    #if defined(DO27)
        INIT_DO_PIN(DO27);
    #endif
    #if defined(DO28)
        INIT_DO_PIN(DO28);
    #endif
    #if defined(DO29)
        INIT_DO_PIN(DO29);
    #endif
    #if defined(DO30)
        INIT_DO_PIN(DO30);
    #endif
    #if defined(DO31)
        INIT_DO_PIN(DO31);
    #endif
    #if defined(DO32)
        INIT_DO_PIN(DO32);
    #endif
    /***********************************************/
    #if defined(DO33)
        INIT_DO_PIN(DO33);
    #endif
    #if defined(DO34)
        INIT_DO_PIN(DO34);
    #endif
    #if defined(DO35)
        INIT_DO_PIN(DO35);
    #endif
    #if defined(DO36)
        INIT_DO_PIN(DO36);
    #endif
    #if defined(DO37)
        INIT_DO_PIN(DO37);
    #endif
    #if defined(DO38)
        INIT_DO_PIN(DO38);
    #endif
    #if defined(DO39)
        INIT_DO_PIN(DO39);
    #endif
    #if defined(DO40)
        INIT_DO_PIN(DO40);
    #endif
    /***********************************************/
    #if defined(DO41)
        INIT_DO_PIN(DO41);
    #endif
    #if defined(DO42)
        INIT_DO_PIN(DO42);
    #endif
    #if defined(DO43)
        INIT_DO_PIN(DO43);
    #endif
    #if defined(DO44)
        INIT_DO_PIN(DO44);
    #endif
    #if defined(DO45)
        INIT_DO_PIN(DO45);
    #endif
    #if defined(DO46)
        INIT_DO_PIN(DO46);
    #endif
    #if defined(DO47)
        INIT_DO_PIN(DO47);
    #endif
    #if defined(DO48)
        INIT_DO_PIN(DO48);
    #endif
    /***********************************************/
    #if defined(DO49)
        INIT_DO_PIN(DO49);
    #endif
    #if defined(DO50)
        INIT_DO_PIN(DO50);
    #endif
    #if defined(DO51)
        INIT_DO_PIN(DO51);
    #endif
    #if defined(DO52)
        INIT_DO_PIN(DO52);
    #endif
    #if defined(DO53)
        INIT_DO_PIN(DO53);
    #endif
    #if defined(DO54)
        INIT_DO_PIN(DO54);
    #endif
    #if defined(DO55)
        INIT_DO_PIN(DO55);
    #endif
    #if defined(DO56)
        INIT_DO_PIN(DO56);
    #endif
    /***********************************************/
    #if defined(DO57)
        INIT_DO_PIN(DO57);
    #endif
    #if defined(DO58)
        INIT_DO_PIN(DO58);
    #endif
    #if defined(DO59)
        INIT_DO_PIN(DO59);
    #endif
    #if defined(DO60)
        INIT_DO_PIN(DO60);
    #endif
    #if defined(DO61)
        INIT_DO_PIN(DO61);
    #endif
    #if defined(DO62)
        INIT_DO_PIN(DO62);
    #endif
    #if defined(DO63)
        INIT_DO_PIN(DO63);
    #endif
    #if defined(DO64)
        INIT_DO_PIN(DO64);
    #endif
}

#endif

void DO_Proc(void)
{
    for (size_t i = 0; i < DO_GROUP; i++)
    {
        if(DO.DO_This[i] ^ DO.DO_Last[i])
        {
            DO.DO_Last[i] = DO.DO_This[i];
            
            #if defined(DO1)
                DO_WRITE(DO1, DO.DO_This[0] & 0x01);
            #endif
            #if defined(DO2)
                DO_WRITE(DO2, DO.DO_This[0] & 0x02);
            #endif
            #if defined(DO3)
                DO_WRITE(DO3, DO.DO_This[0] & 0x04);
            #endif
            #if defined(DO4)
                DO_WRITE(DO4, DO.DO_This[0] & 0x08);
            #endif
            #if defined(DO5)
                DO_WRITE(DO5, DO.DO_This[0] & 0x10);
            #endif
            #if defined(DO6)
                DO_WRITE(DO6, DO.DO_This[0] & 0x20);
            #endif
            #if defined(DO7)
                DO_WRITE(DO7, DO.DO_This[0] & 0x40);
            #endif
            #if defined(DO8)
                DO_WRITE(DO8, DO.DO_This[0] & 0x80);
            #endif
            /***********************************************/
            #if defined(DO9)
                DO_WRITE(DO9, DO.DO_This[0] & 0x01);
            #endif
            #if defined(DO10)
                DO_WRITE(DO10, DO.DO_This[0] & 0x02);
            #endif
            #if defined(DO11)
                DO_WRITE(DO11, DO.DO_This[0] & 0x04);;
            #endif
            #if defined(DO12)
                DO_WRITE(DO12, DO.DO_This[0] & 0x08);
            #endif
            #if defined(DO13)
                DO_WRITE(DO13, DO.DO_This[0] & 0x10);
            #endif
            #if defined(DO14)
                DO_WRITE(DO14, DO.DO_This[0] & 0x20);
            #endif
            #if defined(DO15)
                DO_WRITE(DO15, DO.DO_This[0] & 0x40);
            #endif
            #if defined(DO16)
                DO_WRITE(DO16, DO.DO_This[0] & 0x80);
            #endif
            /***********************************************/
            #if defined(DO17)
                DO_WRITE(DO17, DO.DO_This[1] & 0x01);
            #endif
            #if defined(DO18)
                DO_WRITE(DO18, DO.DO_This[1] & 0x02);
            #endif
            #if defined(DO19)
                DO_WRITE(DO19, DO.DO_This[1] & 0x04);
            #endif
            #if defined(DO20)
                DO_WRITE(DO20, DO.DO_This[1] & 0x08);
            #endif
            #if defined(DO21)
                DO_WRITE(DO21, DO.DO_This[1] & 0x10);
            #endif
            #if defined(DO22)
                DO_WRITE(DO22, DO.DO_This[1] & 0x20);
            #endif
            #if defined(DO23)
                DO_WRITE(DO23, DO.DO_This[1] & 0x40);
            #endif
            #if defined(DO24)
                DO_WRITE(DO24, DO.DO_This[1] & 0x80);
            #endif
            /***********************************************/
            #if defined(DO25)
                DO_WRITE(DO25, DO.DO_This[1] & 0x01);
            #endif
            #if defined(DO26)
                DO_WRITE(DO26, DO.DO_This[1] & 0x02);
            #endif
            #if defined(DO27)
                DO_WRITE(DO27, DO.DO_This[1] & 0x04);
            #endif
            #if defined(DO28)
                DO_WRITE(DO28, DO.DO_This[1] & 0x08);
            #endif
            #if defined(DO29)
                DO_WRITE(DO29, DO.DO_This[1] & 0x10);
            #endif
            #if defined(DO30)
                DO_WRITE(DO30, DO.DO_This[1] & 0x20);
            #endif
            #if defined(DO31)
                DO_WRITE(DO31, DO.DO_This[1] & 0x40);
            #endif
            #if defined(DO32)
                DO_WRITE(DO32, DO.DO_This[1] & 0x80);
            #endif
            /***********************************************/
            #if defined(DO33)
                DO_WRITE(DO33, DO.DO_This[2] & 0x01);
            #endif
            #if defined(DO34)
                DO_WRITE(DO34, DO.DO_This[2] & 0x02);
            #endif
            #if defined(DO35)
                DO_WRITE(DO35, DO.DO_This[2] & 0x04);
            #endif
            #if defined(DO36)
                DO_WRITE(DO36, DO.DO_This[2] & 0x08);
            #endif
            #if defined(DO37)
                DO_WRITE(DO37, DO.DO_This[2] & 0x10);
            #endif
            #if defined(DO38)
                DO_WRITE(DO38, DO.DO_This[2] & 0x20);
            #endif
            #if defined(DO39)
                DO_WRITE(DO39, DO.DO_This[2] & 0x40);
            #endif
            #if defined(DO40)
                DO_WRITE(DO40, DO.DO_This[2] & 0x80);
            #endif
            /***********************************************/
            #if defined(DO41)
                DO_WRITE(DO41, DO.DO_This[2] & 0x01);
            #endif
            #if defined(DO42)
                DO_WRITE(DO42, DO.DO_This[2] & 0x02);
            #endif
            #if defined(DO43)
                DO_WRITE(DO43, DO.DO_This[2] & 0x04);
            #endif
            #if defined(DO44)
                DO_WRITE(DO44, DO.DO_This[2] & 0x08);
            #endif
            #if defined(DO45)
                DO_WRITE(DO45, DO.DO_This[2] & 0x10);
            #endif
            #if defined(DO46)
                DO_WRITE(DO46, DO.DO_This[2] & 0x20);
            #endif
            #if defined(DO47)
                DO_WRITE(DO47, DO.DO_This[2] & 0x40);
            #endif
            #if defined(DO48)
                DO_WRITE(DO48, DO.DO_This[2] & 0x80);
            #endif
            /***********************************************/
            #if defined(DO49)
                DO_WRITE(DO49, DO.DO_This[3] & 0x01);
            #endif
            #if defined(DO50)
                DO_WRITE(DO50, DO.DO_This[3] & 0x02);
            #endif
            #if defined(DO51)
                DO_WRITE(DO51, DO.DO_This[3] & 0x04);
            #endif
            #if defined(DO52)
                DO_WRITE(DO52, DO.DO_This[3] & 0x08);
            #endif
            #if defined(DO53)
                DO_WRITE(DO53, DO.DO_This[3] & 0x10);
            #endif
            #if defined(DO54)
                DO_WRITE(DO54, DO.DO_This[3] & 0x20);
            #endif
            #if defined(DO55)
                DO_WRITE(DO55, DO.DO_This[3] & 0x40);
            #endif
            #if defined(DO56)
                DO_WRITE(DO56, DO.DO_This[3] & 0x80);
            #endif
            /***********************************************/
            #if defined(DO57)
                DO_WRITE(DO57, DO.DO_This[3] & 0x01);
            #endif
            #if defined(DO58)
                DO_WRITE(DO58, DO.DO_This[3] & 0x02);
            #endif
            #if defined(DO59)
                DO_WRITE(DO59, DO.DO_This[3] & 0x04);
            #endif
            #if defined(DO60)
                DO_WRITE(DO60, DO.DO_This[3] & 0x08);
            #endif
            #if defined(DO61)
                DO_WRITE(DO61, DO.DO_This[3] & 0x10);
            #endif
            #if defined(DO62)
                DO_WRITE(DO62, DO.DO_This[3] & 0x20);
            #endif
            #if defined(DO63)
                DO_WRITE(DO63, DO.DO_This[3] & 0x40);
            #endif
            #if defined(DO64)
                DO_WRITE(DO64, DO.DO_This[3] & 0x80);
            #endif
        }
    }
}
// clang-format on
