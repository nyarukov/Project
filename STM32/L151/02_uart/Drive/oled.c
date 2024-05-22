// /*
//  * OLED.c
//  *
//  *  Created on: 2023��10��20��
//  *      Author: Yusaka
//  */

// #include "oled.h"
// #include "myspi.h"
// #include "OLEDfont.h"

// void GPIO_Config(void) {
//     RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);
//     GPIO_InitTypeDef GPIO_InitStructe;
//     GPIO_InitStructe.GPIO_Pin = OLED_RES | OLED_DC | OLED_CS;
//     GPIO_InitStructe.GPIO_Mode = GPIO_Mode_OUT;
//     GPIO_InitStructe.GPIO_OType = GPIO_OType_PP;
//     GPIO_InitStructe.GPIO_PuPd = GPIO_PuPd_UP;
//     GPIO_InitStructe.GPIO_Speed = GPIO_Speed_40MHz;
//     GPIO_Init(GPIOA, &GPIO_InitStructe);
// }
// //OLED���Դ�
// //��Ÿ�ʽ����.
// //[0]0 1 2 3 ... 127
// //[1]0 1 2 3 ... 127
// //[2]0 1 2 3 ... 127
// //[3]0 1 2 3 ... 127
// //[4]0 1 2 3 ... 127
// //[5]0 1 2 3 ... 127
// //[6]0 1 2 3 ... 127
// //[7]0 1 2 3 ... 127

// #if OLED_BUFFER_MODE

// uint8_t OLED_GRAM[Max_Row / 8][Max_Column] = {0};

// #endif

// /**************************************************************************
//  Function: Refresh the OLED screen
//  Input   : none
//  Output  : none
//  �������ܣ�ˢ��OLED��Ļ
//  ��ڲ�������
//  ����  ֵ����
//  **************************************************************************/
// void OLED_Refresh_Gram(void) {
// #if OLED_BUFFER_MODE
//     uint16_t i;
//     OLED_Set_Pos(0, 128);
//     for (i = 0; i < Max_Row / 8 * Max_Column; i++)
//     {
//         OLED_WR_Byte(OLED_GRAM[0][i], OLED_DATA);
//     }
// #endif
// }

// /**
//  * @brief ��SSD1306д��һ���ֽ�
//  * @param dat:Ҫд�������/���� cmd:����/�����־ 0,��ʾ����;1,��ʾ����;
//  * @retval None
//  */
// void OLED_WR_Byte(uint8_t dat, uint8_t cmd) {
//     OLED_CS_L;
//     if (cmd) {
//         OLED_DC_H
//         ;
//     } else {
//         OLED_DC_L
//         ;
//     }
//     SPI_SendByte(SPI1, dat);
//     OLED_DC_H
//     ;
//     OLED_CS_H
//     ;
// }

// /**************************************************************************
//  Function: Set the coordinates (position) displayed on the screen.
//  Input   : x, y: starting point coordinates
//  Output  : none
//  �������ܣ����ú�������Ļ����ʾ�����꣨λ�ã�
//  ��ڲ���: x,y :�������
//  ����  ֵ����
//  **************************************************************************/
// void OLED_Set_Pos(uint8_t x, uint8_t y) {
//     OLED_WR_Byte(0xb0 + y, OLED_CMD);
//     OLED_WR_Byte(((x & 0xf0) >> 4) | 0x10, OLED_CMD);
//     OLED_WR_Byte((x & 0x0f), OLED_CMD);
// }

// /**
//  * @brief ����OLED��ʾ
//  * @param None
//  * @retval None
//  */
// void OLED_Display_On(void) {
//     OLED_WR_Byte(0X8D, OLED_CMD);  //SET DCDC����
//     OLED_WR_Byte(0X14, OLED_CMD);  //DCDC ON
//     OLED_WR_Byte(0XAF, OLED_CMD);  //DISPLAY ON
// }

// /**
//  * @brief �ر�OLED��ʾ
//  * @param None
//  * @retval None
//  */
// void OLED_Display_Off(void) {
//     OLED_WR_Byte(0X8D, OLED_CMD);  //SET DCDC����
//     OLED_WR_Byte(0X10, OLED_CMD);  //DCDC OFF
//     OLED_WR_Byte(0XAE, OLED_CMD);  //DISPLAY OFF
// }

// /**
//  * @brief ��������,������,������Ļ�Ǻ�ɫ��!��û����һ��
//  * @param None
//  * @retval None
//  */
// void OLED_Clear(void) {
// #if OLED_BUFFER_MODE
//     uint16_t i;
//     for (i = 0; i < Max_Row / 8 * Max_Column; i++)
//     {
//         OLED_GRAM[0][i] = 0;
//     }
//     OLED_Refresh_Gram(); //Update the display //������ʾ
// #else
//     uint8_t i, n;
//     for (i = 0; i < 8; i++) {
//         OLED_WR_Byte(0xb0 + i, OLED_CMD);    //����ҳ��ַ��0~7��
//         OLED_WR_Byte(0x00, OLED_CMD);      //������ʾλ�á��е͵�ַ
//         OLED_WR_Byte(0x10, OLED_CMD);      //������ʾλ�á��иߵ�ַ
//         for (n = 0; n < Max_Column; n++)
//             OLED_WR_Byte(0, OLED_DATA);
//     }      //������ʾ
// #endif
// }

// /**
//  * @brief ��ָ��λ����ʾһ���ַ�,���������ַ�
//  * @param x:0~127   y:0~63   Is_Reverse:1,������ʾ  0,������ʾ    charSize:ѡ������ 16/6
//  * @retval None
//  */
// void OLED_ShowChar(uint8_t x, uint8_t y, uint8_t chr, uint8_t charSize,
//         uint8_t Is_Reverse) {
//     uint8_t i = 0;
//     chr -= ' '; //�õ�ƫ�ƺ��ֵ
//     if (x > Max_Column - 1) {
//         x = 0;
//         y = y + 2;
//     }
// #if OLED_BUFFER_MODE
//     if(charSize == 16)
//     {
//         for(i = 0; i < 8; i++)
//         {
//             OLED_GRAM[y][x+i] = Is_Reverse == 0?F8X16[chr][i]:~F8X16[chr][i];
//             OLED_GRAM[y+1][x+i] = Is_Reverse == 0?F8X16[chr][i+8]:~F8X16[chr][i+8];
//         }
//     }
//     else if(charSize == 6)
//     {
//         for(i=0; i<6; i++)
//         {
//             OLED_GRAM[y][x+i] = Is_Reverse == 0?F8X6[chr][i]:~F8X6[chr][i];
//         }
//     }
// #else
//     if (charSize == 16) {
//         OLED_Set_Pos(x, y);
//         for (i = 0; i < 8; i++)
//             OLED_WR_Byte(Is_Reverse == 0 ? F8X16[chr][i] : ~F8X16[chr][i],
//                     OLED_DATA);
//         OLED_Set_Pos(x, y + 1);
//         for (i = 0; i < 8; i++)
//             OLED_WR_Byte(
//                     Is_Reverse == 0 ? F8X16[chr][i + 8] : ~F8X16[chr][i + 8],
//                     OLED_DATA);
//     } else if (charSize == 6) {
//         OLED_Set_Pos(x, y);
//         for (i = 0; i < 6; i++)
//             OLED_WR_Byte(Is_Reverse == 0 ? F8X6[chr][i] : ~F8X6[chr][i],
//                     OLED_DATA);
//     }
// #endif
// }

// /**
//  * @brief m^n����
//  * @param None
//  * @retval None
//  */
// uint32_t OLED_pow(uint8_t m, uint8_t n) {
//     uint32_t result = 1;
//     while (n--)result *= m;
//     return result;
// }

// /**
//  * @brief ��ʾ2������
//  * @param x,y :�������
//  *                len :���ֵ�λ��������ʾ��λ��Ч����
//  *                Size:�����С
//  *                mode:ģʽ    0,���ģʽ;1,����ģʽ
//  *        num:��ֵ(0~4294967295);
//  * @retval None
//  */
// void OLED_ShowNum(uint8_t x, uint8_t y, uint32_t num, uint8_t len, uint8_t Size,
//         uint8_t Is_Reverse) {
//     uint8_t t, temp;
//     uint8_t enshow = 0;
//     for (t = 0; t < len; t++) {
//         temp = (num / OLED_pow(10, len - t - 1)) % 10;
//         if (enshow == 0 && t < (len - 1)) {
//             if (temp == 0) {
//                 OLED_ShowChar(x + 8 * t, y, ' ', Size, Is_Reverse);
//                 continue;
//             } else
//                 enshow = 1;

//         }
//         OLED_ShowChar(x + 8 * t, y, temp + '0', Size, Is_Reverse);
//     }
// }

// /**
//  * @brief ��ʾһ���ַ��Ŵ�
//  * @param
//  * @retval None
//  */
// void OLED_ShowString(uint8_t x, uint8_t y, char *chr, uint8_t charSize,
//         uint8_t Is_Reverse) {
//     uint8_t j = 0;
//     while (chr[j] != '\0')
//     {
//         OLED_ShowChar(x, y, chr[j], charSize, Is_Reverse);
//         x +=6;
//         if (x>120)
//         {
//             x = 0;
//             y += 2;
//         }
//         j++;
//     }
// }

// /**
//  * @brief ��ʾ����
//  * @param
//  * @retval None
//  */
// void OLED_ShowChinese(uint8_t x, uint8_t y, uint8_t no, uint8_t Is_Reverse) {
//     uint8_t i;
// #if OLED_BUFFER_MODE
//     for (i = 0; i < 16; i++)
//     {
//         OLED_GRAM[y][x+i] = Is_Reverse == 0?Hzk[2 * no][i]:~Hzk[2 * no][i];
//         OLED_GRAM[y+1][x+i] = Is_Reverse == 0?Hzk[2 * no + 1][i]:~Hzk[2 * no + 1][i];
//     }
// #else
//     OLED_Set_Pos(x, y);
//     for (i = 0; i < 16; i++) {
//         OLED_WR_Byte(Is_Reverse == 0 ? Hzk[2 * no][i] : ~Hzk[2 * no][i],
//                 OLED_DATA);
//     }
//     OLED_Set_Pos(x, y + 1);
//     for (i = 0; i < 16; i++) {
//         OLED_WR_Byte(Is_Reverse == 0 ? Hzk[2 * no + 1][i] : ~Hzk[2 * no + 1][i],
//                 OLED_DATA);
//     }
// #endif
// }

// /**
//  * @brief ��ʾ��ʾBMPͼƬ
//  * @param ��ʾ��ʾBMPͼƬ128��64��ʼ������(x,y),x�ķ�Χ0��127��yΪҳ�ķ�Χ0��7
//  * @retval None
//  */
// void OLED_DrawBMP(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t BMP[],
//         uint8_t Is_Reverse) {
//     uint16_t j = 0;
//     uint8_t x, y;

//     if (y1 % 8 == 0)
//         y = y1 / 8;
//     else
//         y = y1 / 8 + 1;
// #if OLED_BUFFER_MODE
//     for (y = y0; y<y1; y++)
//     {
//         for (x = x0; x<x1; x++)
//         {
//             OLED_GRAM[y][x] = Is_Reverse == 0?BMP[j++]:~BMP[j++];
//         }
//     }
// #else
//     for (y = y0; y < y1; y++) {
//         OLED_Set_Pos(x0, y);
//         for (x = x0; x < x1; x++) {
//             OLED_WR_Byte(Is_Reverse == 0 ? BMP[j++] : ~BMP[j++], OLED_DATA);
//         }
//     }
// #endif
// }

// /**
//  * @brief ��ʼ��SSD1306
//  * @param None
//  * @retval None
//  */
// void OLED_Init(void) {
//     SPI_Config();
//     GPIO_Config();
//     OLED_RES_H
//     ;
//     Delay_Ms(10);
//     OLED_RES_L
//     ;
//     Delay_Ms(100);
//     OLED_RES_H
//     ;

//     OLED_WR_Byte(0xAE, OLED_CMD); //--turn off OLED panel ������ʾ��

//     OLED_WR_Byte(0x00, OLED_CMD); //---set low column address    ���õ��е�ַ
//     OLED_WR_Byte(0x10, OLED_CMD); //---set high column address ���ø��е�ַ

//     OLED_WR_Byte(0x40, OLED_CMD); //--set start line address  Set Mapping RAM Display Start Line (0x40~0x7F) ������ʾ��ʼ��

//     OLED_WR_Byte(0xDA, OLED_CMD); //--set com pins hardware configuration ���� COM ����Ӳ������
//     OLED_WR_Byte(0x12, OLED_CMD);

// #if OLED_BUFFER_MODE
//     OLED_WR_Byte(0x20, OLED_CMD); //-Set Page Addressing Mode (0x00/0x01/0x02) �����ڴ��ַģʽ
//     OLED_WR_Byte(0x00, OLED_CMD);//

//     OLED_WR_Byte(0xD3, OLED_CMD);//-set display offset  Shift Mapping RAM Counter (0x00~0x3F)   ������ʾƫ��
//     OLED_WR_Byte(0x00/*��8�ı���*/,OLED_CMD);
// #else
//     OLED_WR_Byte(0x20, OLED_CMD); //-Set Page Addressing Mode (0x00/0x01/0x02) �����ڴ��ַģʽ
//     OLED_WR_Byte(0x02, OLED_CMD); //

//     OLED_WR_Byte(0xD3, OLED_CMD); //-set display offset  Shift Mapping RAM Counter (0x00~0x3F)   ������ʾƫ��
//     OLED_WR_Byte(0x00/*��8�ı���*/, OLED_CMD); //-not offset
// #endif
//     OLED_WR_Byte(0xA1, OLED_CMD); //--Set SEG/Column Mapping     0xa0���ҷ��� 0xa1����
//     OLED_WR_Byte(0xC8, OLED_CMD); //Set COM/Row Scan Direction   0xc0���·��� 0xc8����

//     OLED_WR_Byte(0xDB, OLED_CMD); //--set vcomh  ���� Vcomh ȡ��ѡ��ˮƽ
//     OLED_WR_Byte(0x30, OLED_CMD); //Set VCOM Deselect Level

//     OLED_WR_Byte(0xD8, OLED_CMD); //set area color mode off
//     OLED_WR_Byte(0x05, OLED_CMD); //

//     OLED_WR_Byte(0x81, OLED_CMD); //--set contrast control register Ϊ BANK0 ���öԱȶȿ���
//     OLED_WR_Byte(Brightness, OLED_CMD); //1~ 255; Default 0x7f (brightness Settings, the bigger the brighter) //1~255;Ĭ��0X7F (��������,Խ��Խ��)

//     OLED_WR_Byte(0xA8, OLED_CMD); //--set multiplex ratio(1 to 64)   ���ø�����
//     OLED_WR_Byte(0x3f, OLED_CMD); //--1/64 duty

//     OLED_WR_Byte(0xd5, OLED_CMD); //--set display clock divide ratio/oscillator frequency    ������ʾʱ�ӷ�Ƶ�ʡ�����Ƶ��
//     OLED_WR_Byte(0x80, OLED_CMD); //--set divide ratio, Set Clock as 100 Frames/Sec

//     OLED_WR_Byte(0xD9, OLED_CMD); //--set pre-charge period �����س������
//     OLED_WR_Byte(0xF1, OLED_CMD); //Set Pre-Charge as 15 Clocks & Discharge as 1 Clock

//     OLED_WR_Byte(0x8D, OLED_CMD); //--set Charge Pump enable/disable ��ѹ����
//     OLED_WR_Byte(0x14, OLED_CMD); //--set(0x10) disable

//     OLED_WR_Byte(0xA4, OLED_CMD); // Disable Entire Display On (0xa4/0xa5) ȫ����ʾ����
//     OLED_WR_Byte(0xA6, OLED_CMD); // Disable Inverse Display On (0xa6/a7) ����������ʾ

//     OLED_WR_Byte(0xAF, OLED_CMD); // display ON ������ʾ��

//     OLED_Clear();
//     OLED_Set_Pos(0, 0);
// }

