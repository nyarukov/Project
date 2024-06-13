/*
 * oled.h
 *
 *  Created on: 2023��10��20��
 *      Author: Yusaka
 */

#ifndef DRIVE_DRIVE_OLED_H_
#define DRIVE_DRIVE_OLED_H_

#ifndef __OLED_H
#define __OLED_H

#include "stm32l1xx.h"

#define OLED_BUFFER_MODE    0
#define Max_Column          130
#define Max_Row             64
#define Brightness          0xFF

#define OLED_CMD  0             //д����
#define OLED_DATA 1             //д����

#define OLED_RES       GPIO_Pin_2
#define OLED_DC        GPIO_Pin_3
#define OLED_CS        GPIO_Pin_4

#define OLED_RES_H        GPIOA->BSRRL=OLED_RES;
#define OLED_DC_H         GPIOA->BSRRL=OLED_DC;
#define OLED_CS_H         GPIOA->BSRRL=OLED_CS;

#define OLED_RES_L        GPIOA->BSRRH=OLED_RES;
#define OLED_DC_L         GPIOA->BSRRH=OLED_DC;
#define OLED_CS_L         GPIOA->BSRRH=OLED_CS;

/* OLED�����ú��� */
void OLED_Clear(void); /* OLED���� */
void OLED_Display_On(void); /* OLED�� */
void OLED_ShowPosture(void); /* ��ʾ��Ϣ */
void OLED_Display_Off(void); /* OLED�� */
void OLED_Init(void); /* OLED��ʼ�� */
void OLED_WR_Byte(uint8_t dat, uint8_t cmd); /* д�ֽ� */
void OLED_Set_Pos(uint8_t x, uint8_t y); /* �������� */
void OLED_ShowChar(uint8_t x, uint8_t y, uint8_t chr, uint8_t charSize,
        uint8_t Is_Reverse); /* ��ʾ�ַ� */
void OLED_ShowString(uint8_t x, uint8_t y, char *p, uint8_t charSize,
        uint8_t Is_Reverse); /* ��ʾ�ַ��� */
void OLED_ShowChinese(uint8_t x, uint8_t y, uint8_t no, uint8_t Is_Reverse); /* ��ʾ���� */
void OLED_ShowNum(uint8_t x, uint8_t y, uint32_t num, uint8_t len, uint8_t Size,
        uint8_t Is_Reverse); /* ��ʾ���� */
void OLED_DrawBMP(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t BMP[],
        uint8_t Is_Reverse); /* ��ʾͼƬ */

void OLED_Refresh_Gram(void);

#endif  /* __OLED_H */

#endif /* DRIVE_DRIVE_OLED_H_ */
