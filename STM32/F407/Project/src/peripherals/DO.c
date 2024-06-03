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

#define INIT_DO_PIN(PIN) IO_Init(PIN, DO_MODE, DO_OTYP, GPIO_PuPd_NOPULL, DO_SPEED)

void DO_Init(void)
{
    #if DO_NUM > 0 
        // 初始化DO引脚
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
    #endif
}

// clang-format on