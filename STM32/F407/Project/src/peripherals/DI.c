/*
 * 项目名称: DI
 * 版本:1.0
 * 作者: Yusaka
 * 创建日期: 2024-06-03 23:10:38
 * 最后修改日期: 2024-06-03 23:10:38
 * 描述: DI驱动
 */

#include "DI.h"
// C 文件内容...

// clang-format off

#if  DI_NUM > 0
#define INIT_DI_PIN(pin)    IO_Init(pin, DI_MODE, DI_OTYP, DI_PUPD, GPIO_Speed_2MHz)
#define READ_DI_PIN(pin)    IO_Read(pin)

DI_PARA DI;

void Init_DI(void)
{
    /***********************************************/
    #if defined(DI1)
        INIT_DI_PIN(DI1);
    #endif
    #if defined(DI2)
        INIT_DI_PIN(DI2);
    #endif
    #if defined(DI3)
        INIT_DI_PIN(DI3);
    #endif
    #if defined(DI4)
        INIT_DI_PIN(DI4);
    #endif
    #if defined(DI5)
        INIT_DI_PIN(DI5);
    #endif
    #if defined(DI6)
        INIT_DI_PIN(DI6);
    #endif
    #if defined(DI7)
        INIT_DI_PIN(DI7);
    #endif
    #if defined(DI8)
        INIT_DI_PIN(DI8);
    #endif
    /***********************************************/
    #if defined(DI9)
        INIT_DI_PIN(DI9);
    #endif
    #if defined(DI10)
        INIT_DI_PIN(DI10);
    #endif
    #if defined(DI11)
        INIT_DI_PIN(DI11);
    #endif
    #if defined(DI12)
        INIT_DI_PIN(DI12);
    #endif
    #if defined(DI13)
        INIT_DI_PIN(DI13);
    #endif
    #if defined(DI14)
        INIT_DI_PIN(DI14);
    #endif
    #if defined(DI15)
        INIT_DI_PIN(DI15);
    #endif
    #if defined(DI16)
        INIT_DI_PIN(DI16);
    #endif
    /***********************************************/
    #if defined(DI17)
        INIT_DI_PIN(DI17);
    #endif
    #if defined(DI18)
        INIT_DI_PIN(DI18);
    #endif
    #if defined(DI19)
        INIT_DI_PIN(DI19);
    #endif
    #if defined(DI20)
        INIT_DI_PIN(DI20);
    #endif
    #if defined(DI21)
        INIT_DI_PIN(DI21);
    #endif
    #if defined(DI22)
        INIT_DI_PIN(DI22);
    #endif
    #if defined(DI23)
        INIT_DI_PIN(DI23);
    #endif
    #if defined(DI24)
        INIT_DI_PIN(DI24);
    #endif
    /***********************************************/
    #if defined(DI25)
        INIT_DI_PIN(DI25);
    #endif
    #if defined(DI26)
        INIT_DI_PIN(DI26);
    #endif
    #if defined(DI27)
        INIT_DI_PIN(DI27);
    #endif
    #if defined(DI28)
        INIT_DI_PIN(DI28);
    #endif
    #if defined(DI29)
        INIT_DI_PIN(DI29);
    #endif
    #if defined(DI30)
        INIT_DI_PIN(DI30);
    #endif
    #if defined(DI31)
        INIT_DI_PIN(DI31);
    #endif
    #if defined(DI32)
        INIT_DI_PIN(DI32);
    #endif
    /***********************************************/
    #if defined(DI33)
        INIT_DI_PIN(DI33);
    #endif
    #if defined(DI34)
        INIT_DI_PIN(DI34);
    #endif
    #if defined(DI35)
        INIT_DI_PIN(DI35);
    #endif
    #if defined(DI36)
        INIT_DI_PIN(DI36);
    #endif
    #if defined(DI37)
        INIT_DI_PIN(DI37);
    #endif
    #if defined(DI38)
        INIT_DI_PIN(DI38);
    #endif
    #if defined(DI39)
        INIT_DI_PIN(DI39);
    #endif
    #if defined(DI40)
        INIT_DI_PIN(DI40);
    #endif
    /***********************************************/
    #if defined(DI41)
        INIT_DI_PIN(DI41);
    #endif
    #if defined(DI42)
        INIT_DI_PIN(DI42);
    #endif
    #if defined(DI43)
        INIT_DI_PIN(DI43);
    #endif
    #if defined(DI44)
        INIT_DI_PIN(DI44);
    #endif
    #if defined(DI45)
        INIT_DI_PIN(DI45);
    #endif
    #if defined(DI46)
        INIT_DI_PIN(DI46);
    #endif
    #if defined(DI47)
        INIT_DI_PIN(DI47);
    #endif
    #if defined(DI48)
        INIT_DI_PIN(DI48);
    #endif
    /***********************************************/
    #if defined(DI49)
        INIT_DI_PIN(DI49);
    #endif
    #if defined(DI50)
        INIT_DI_PIN(DI50);
    #endif
    #if defined(DI51)
        INIT_DI_PIN(DI51);
    #endif
    #if defined(DI52)
        INIT_DI_PIN(DI52);
    #endif
    #if defined(DI53)
        INIT_DI_PIN(DI53);
    #endif
    #if defined(DI54)
        INIT_DI_PIN(DI54);
    #endif
    #if defined(DI55)
        INIT_DI_PIN(DI55);
    #endif
    #if defined(DI56)
        INIT_DI_PIN(DI56);
    #endif
    /***********************************************/
    #if defined(DI57)
        INIT_DI_PIN(DI57);
    #endif
    #if defined(DI58)
        INIT_DI_PIN(DI58);
    #endif
    #if defined(DI59)
        INIT_DI_PIN(DI59);
    #endif
    #if defined(DI60)
        INIT_DI_PIN(DI60);
    #endif
    #if defined(DI61)
        INIT_DI_PIN(DI61);
    #endif
    #if defined(DI62)
        INIT_DI_PIN(DI62);
    #endif
    #if defined(DI63)
        INIT_DI_PIN(DI63);
    #endif
    #if defined(DI64)
        INIT_DI_PIN(DI64);
    #endif
}

void DI_Read(void)
{
    uint8_t *_DI_States = DI.DI_This;
    for (size_t i = 0; i < DI_GROUP; i++)
    {
        _DI_States[i] = 0;
    }
    /***********************************************/
    #if defined(DI1)
        _DI_States[0] ^= READ_DI_PIN(DI1) << 0;
    #endif
    #if defined(DI2)
        _DI_States[0] ^= READ_DI_PIN(DI2) << 1;
    #endif
    #if defined(DI3)
        _DI_States[0] ^= READ_DI_PIN(DI3) << 2;
    #endif
    #if defined(DI4)
        _DI_States[0] |= READ_DI_PIN(DI4) << 3;
    #endif
    #if defined(DI5)
        _DI_States[0] |= READ_DI_PIN(DI5) << 4;
    #endif
    #if defined(DI6)
        _DI_States[0] |= READ_DI_PIN(DI6) << 5;
    #endif
    #if defined(DI7)
        _DI_States[0] |= READ_DI_PIN(DI7) << 6;
    #endif
    #if defined(DI8)
        _DI_States[0] |= READ_DI_PIN(DI8) << 7;
    #endif
    /***********************************************/
    #if defined(DI9)
        _DI_States[0] |= READ_DI_PIN(DI9) << 0;
    #endif
    #if defined(DI10)
        _DI_States[0] |= READ_DI_PIN(DI10) << 1;
    #endif
    #if defined(DI11)
        _DI_States[0] |= READ_DI_PIN(DI11) << 2;
    #endif
    #if defined(DI12)
        _DI_States[0] |= READ_DI_PIN(DI12) << 3;
    #endif
    #if defined(DI13)
        _DI_States[0] |= READ_DI_PIN(DI13) << 4;
    #endif
    #if defined(DI14)
        _DI_States[0] |= READ_DI_PIN(DI14) << 5;
    #endif
    #if defined(DI15)
        _DI_States[0] |= READ_DI_PIN(DI15) << 6;
    #endif
    #if defined(DI16)
        _DI_States[0] |= READ_DI_PIN(DI16) << 7;
    #endif
    /***********************************************/
    #if defined(DI17)
        _DI_States[1]  |= READ_DI_PIN(DI17) << 0;
    #endif
    #if defined(DI18)
        _DI_States[1]  |= READ_DI_PIN(DI18) << 1;
    #endif
    #if defined(DI19)
        _DI_States[1]  |= READ_DI_PIN(DI19) << 2;
    #endif
    #if defined(DI20)
        _DI_States[1]  |= READ_DI_PIN(DI20) << 3;
    #endif
    #if defined(DI21)
        _DI_States[1]  |= READ_DI_PIN(DI21) << 4;
    #endif
    #if defined(DI22)
        _DI_States[1]  |= READ_DI_PIN(DI22) << 5;
    #endif
    #if defined(DI23)
        _DI_States[1]  |= READ_DI_PIN(DI23) << 6;
    #endif
    #if defined(DI24)
        _DI_States[1]  |= READ_DI_PIN(DI24) << 7;
    #endif
    /***********************************************/
    #if defined(DI25)
        _DI_States[1]  |= READ_DI_PIN(DI25) << 0;
    #endif
    #if defined(DI26)
        _DI_States[1]  |= READ_DI_PIN(DI26) << 1;
    #endif
    #if defined(DI27)
        _DI_States[1]  |= READ_DI_PIN(DI27) << 2;
    #endif
    #if defined(DI28)
        _DI_States[1]  |= READ_DI_PIN(DI28) << 3;
    #endif
    #if defined(DI29)
        _DI_States[1]  |= READ_DI_PIN(DI29) << 4;
    #endif
    #if defined(DI30)
        _DI_States[1]  |= READ_DI_PIN(DI30) << 5;
    #endif
    #if defined(DI31)
        _DI_States[1]  |= READ_DI_PIN(DI31) << 6;
    #endif
    #if defined(DI32)
        _DI_States[1]  |= READ_DI_PIN(DI32) << 7;
    #endif
    /***********************************************/
    #if defined(DI33)
        _DI_States[2] |= READ_DI_PIN(DI33) << 0;
    #endif
    #if defined(DI34)
        _DI_States[2]  |= READ_DI_PIN(DI34) << 1;
    #endif
    #if defined(DI35)
        _DI_States[2] |= READ_DI_PIN(DI35) << 2;
    #endif
    #if defined(DI36)
        _DI_States[2] |= READ_DI_PIN(DI36) << 3;
    #endif
    #if defined(DI37)
        _DI_States[2] |= READ_DI_PIN(DI37) << 4;
    #endif
    #if defined(DI38)
        _DI_States[2] |= READ_DI_PIN(DI38) << 5;
    #endif
    #if defined(DI39)
        _DI_States[2] |= READ_DI_PIN(DI39) << 6;
    #endif
    #if defined(DI40)
        _DI_States[2] |= READ_DI_PIN(DI40) << 7;
    #endif
    /***********************************************/
    #if defined(DI41)
        _DI_States[2]  |= READ_DI_PIN(DI41) << 0;
    #endif
    #if defined(DI42)
        _DI_States[2]  |= READ_DI_PIN(DI42) << 1;
    #endif
    #if defined(DI43)
        _DI_States[2]  |= READ_DI_PIN(DI43) << 2;
    #endif
    #if defined(DI44)
        _DI_States[2]  |= READ_DI_PIN(DI44) << 3;
    #endif
    #if defined(DI45)
        _DI_States[2]  |= READ_DI_PIN(DI45) << 4;
    #endif
    #if defined(DI46)
        _DI_States[2]  |= READ_DI_PIN(DI46) << 5;
    #endif
    #if defined(DI47)
        _DI_States[2]  |= READ_DI_PIN(DI47) << 6;
    #endif
    #if defined(DI48)
        _DI_States[2]  |= READ_DI_PIN(DI48) << 7;
    #endif
    /***********************************************/
    #if defined(DI49)
        _DI_States[3]  |= READ_DI_PIN(DI49) << 0;
    #endif
    #if defined(DI50)
        _DI_States[3]  |= READ_DI_PIN(DI50) << 1;
    #endif
    #if defined(DI51)
        _DI_States[3]  |= READ_DI_PIN(DI51) << 2;
    #endif
    #if defined(DI52)
        _DI_States[3]  |= READ_DI_PIN(DI52) << 3;
    #endif
    #if defined(DI53)
        _DI_States[3]  |= READ_DI_PIN(DI53) << 4;
    #endif
    #if defined(DI54)
        _DI_States[3]  |= READ_DI_PIN(DI54) << 5;
    #endif
    #if defined(DI55)
        _DI_States[3]  |= READ_DI_PIN(DI55) << 6;
    #endif
    #if defined(DI56)
        _DI_States[3]  |= READ_DI_PIN(DI56) << 7;
    #endif
    /***********************************************/
    #if defined(DI57)
        _DI_States[3]   |= READ_DI_PIN(DI57) << 0;
    #endif
    #if defined(DI58)
        _DI_States[3]   |= READ_DI_PIN(DI58) << 1;
    #endif
    #if defined(DI59)
        _DI_States[3]   |= READ_DI_PIN(DI59) << 2;
    #endif
    #if defined(DI60)
        _DI_States[3]   |= READ_DI_PIN(DI60) << 3;
    #endif
    #if defined(DI61)
        _DI_States[3]   |= READ_DI_PIN(DI61) << 4;
    #endif
    #if defined(DI62)
        _DI_States[3]   |= READ_DI_PIN(DI62) << 5;
    #endif
    #if defined(DI63)
        _DI_States[3]   |= READ_DI_PIN(DI63) << 6;
    #endif
    #if defined(DI64)
        _DI_States[3]   |= READ_DI_PIN(DI64) << 7;
    #endif
    for (size_t i = 0; i < DI_GROUP; i++)
    {
        if(_DI_States[i] ^ DI.DI_Last[i])
        {
            //DI._DI_Callbacks(_DI_States[i]);
            DI.DI_Last[i] = _DI_States[i];
        }
    }
}
#endif
// clang-format on
