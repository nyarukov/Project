/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2023  SEGGER Microcontroller GmbH                *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V6.36 - Graphical user interface for embedded applications **
emWin is protected by international copyright laws.   Knowledge of the
source code may not be used to write a similar product.  This file may
only  be used  in accordance  with  a license  and should  not be  re-
distributed in any way. We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : F16_AA4.c
Purpose     : Font file.
----------------------------------------------------------------------
*/

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

/* The following line needs to be included in any file selecting the
   font.
*/
extern GUI_CONST_STORAGE GUI_FONT GUI_Font16_AA4;

/* Start of unicode area <Basic Latin> */
GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0020[  1] = { /* code 0020, SPACE */
  0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0021[ 10] = { /* code 0021, EXCLAMATION MARK */
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0x00,
  0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0022[  6] = { /* code 0022, QUOTATION MARK */
  0xF0, 0xF0,
  0xE0, 0xF0,
  0xA0, 0xA0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0023[ 40] = { /* code 0023, NUMBER SIGN */
  0x00, 0x1D, 0x01, 0xE0,
  0x00, 0x4A, 0x04, 0xB0,
  0x00, 0x77, 0x07, 0x80,
  0xFF, 0xFF, 0xFF, 0xFF,
  0x00, 0xD1, 0x0D, 0x20,
  0x02, 0xD0, 0x1D, 0x00,
  0xFF, 0xFF, 0xFF, 0xFF,
  0x08, 0x70, 0x77, 0x00,
  0x0B, 0x40, 0xA4, 0x00,
  0x0E, 0x10, 0xD1, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0024[ 33] = { /* code 0024, DOLLAR SIGN */
  0x5F, 0xFD, 0x40,
  0xF5, 0xF4, 0xD0,
  0xF0, 0xF0, 0x00,
  0xF2, 0xF0, 0x00,
  0x8E, 0xF6, 0x00,
  0x03, 0xFA, 0xB0,
  0x00, 0xF0, 0xF0,
  0xE1, 0xF0, 0xF0,
  0xB6, 0xF5, 0xF0,
  0x2D, 0xFE, 0x50,
  0x00, 0xF0, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0025[ 50] = { /* code 0025, PERCENT SIGN */
  0x5F, 0xF5, 0x00, 0x3C, 0x00,
  0xF5, 0x5F, 0x00, 0xA5, 0x00,
  0xF0, 0x0F, 0x03, 0xC0, 0x00,
  0xF5, 0x5F, 0x0A, 0x40, 0x00,
  0x5F, 0xF5, 0x3B, 0x00, 0x00,
  0x00, 0x00, 0xB4, 0x5F, 0xF5,
  0x00, 0x04, 0xB0, 0xF5, 0x5F,
  0x00, 0x0B, 0x40, 0xF0, 0x0F,
  0x00, 0x4B, 0x00, 0xF5, 0x5F,
  0x00, 0xB4, 0x00, 0x5F, 0xF5
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0026[ 40] = { /* code 0026, AMPERSAND */
  0x03, 0xEE, 0x40, 0x00,
  0x0D, 0x44, 0xD0, 0x00,
  0x0F, 0x00, 0xF0, 0x00,
  0x0B, 0x37, 0xB0, 0x00,
  0x06, 0xEC, 0x10, 0x00,
  0x4E, 0xA7, 0x00, 0x00,
  0xD3, 0x0B, 0x44, 0xE0,
  0xF0, 0x01, 0xC8, 0x80,
  0xB7, 0x04, 0xEE, 0x60,
  0x1B, 0xFE, 0x71, 0xA8
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0027[  3] = { /* code 0027, APOSTROPHE */
  0xF0,
  0xF0,
  0xA0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0028[ 26] = { /* code 0028, LEFT PARENTHESIS */
  0x04, 0xB0,
  0x0C, 0x30,
  0x4B, 0x00,
  0x96, 0x00,
  0xC3, 0x00,
  0xF0, 0x00,
  0xF0, 0x00,
  0xE1, 0x00,
  0xC3, 0x00,
  0x96, 0x00,
  0x4B, 0x00,
  0x0C, 0x30,
  0x04, 0xB0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0029[ 26] = { /* code 0029, RIGHT PARENTHESIS */
  0xB4, 0x00,
  0x3C, 0x00,
  0x0B, 0x40,
  0x06, 0x90,
  0x03, 0xC0,
  0x00, 0xF0,
  0x00, 0xF0,
  0x01, 0xE0,
  0x03, 0xC0,
  0x06, 0x90,
  0x0B, 0x30,
  0x3C, 0x00,
  0xB4, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_002A[ 12] = { /* code 002A, ASTERISK */
  0x00, 0xF0, 0x00,
  0xB9, 0xD9, 0xB0,
  0x19, 0xE9, 0x20,
  0x2C, 0x2C, 0x20
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_002B[ 28] = { /* code 002B, PLUS SIGN */
  0x00, 0x0F, 0x00, 0x00,
  0x00, 0x0F, 0x00, 0x00,
  0x00, 0x0F, 0x00, 0x00,
  0xFF, 0xFF, 0xFF, 0xF0,
  0x00, 0x0F, 0x00, 0x00,
  0x00, 0x0F, 0x00, 0x00,
  0x00, 0x0F, 0x00, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_002C[  3] = { /* code 002C, COMMA */
  0xF0,
  0x90,
  0x80
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_002D[  2] = { /* code 002D, HYPHEN-MINUS */
  0xFF, 0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_002E[  1] = { /* code 002E, FULL STOP */
  0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_002F[ 20] = { /* code 002F, SOLIDUS */
  0x00, 0x2D,
  0x00, 0x78,
  0x00, 0xB4,
  0x01, 0xE0,
  0x05, 0xA0,
  0x0A, 0x50,
  0x0E, 0x10,
  0x4B, 0x00,
  0x87, 0x00,
  0xD2, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0030[ 30] = { /* code 0030, DIGIT ZERO */
  0x1B, 0xFE, 0xA1,
  0x88, 0x00, 0x88,
  0xC3, 0x00, 0x2B,
  0xE1, 0x00, 0x0E,
  0xF0, 0x00, 0x0F,
  0xF0, 0x00, 0x0F,
  0xE0, 0x00, 0x0E,
  0xB2, 0x00, 0x1C,
  0x88, 0x00, 0x68,
  0x1B, 0xFF, 0xB1
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0031[ 20] = { /* code 0031, DIGIT ONE */
  0x01, 0xD0,
  0x0A, 0xF0,
  0xB3, 0xF0,
  0x50, 0xF0,
  0x00, 0xF0,
  0x00, 0xF0,
  0x00, 0xF0,
  0x00, 0xF0,
  0x00, 0xF0,
  0x00, 0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0032[ 30] = { /* code 0032, DIGIT TWO */
  0x3B, 0xFF, 0xA1,
  0xD5, 0x00, 0x8A,
  0x00, 0x00, 0x0F,
  0x00, 0x00, 0x1E,
  0x00, 0x00, 0x68,
  0x00, 0x01, 0xA0,
  0x00, 0x0A, 0x10,
  0x02, 0xA2, 0x00,
  0x5C, 0x20, 0x00,
  0xEF, 0xFF, 0xFF
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0033[ 30] = { /* code 0033, DIGIT THREE */
  0x2B, 0xFF, 0xA1,
  0xC6, 0x10, 0x7B,
  0x00, 0x00, 0x0F,
  0x00, 0x01, 0x6A,
  0x00, 0xAE, 0xF4,
  0x00, 0x00, 0x8D,
  0x00, 0x00, 0x0F,
  0x00, 0x00, 0x1E,
  0xD5, 0x00, 0x88,
  0x2B, 0xFE, 0x80
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0034[ 30] = { /* code 0034, DIGIT FOUR */
  0x00, 0x04, 0xF0,
  0x00, 0x0B, 0xF0,
  0x00, 0x3A, 0xF0,
  0x00, 0xA3, 0xF0,
  0x03, 0xB0, 0xF0,
  0x0A, 0x40, 0xF0,
  0x2C, 0x00, 0xF0,
  0xAF, 0xFF, 0xFF,
  0x00, 0x00, 0xF0,
  0x00, 0x00, 0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0035[ 30] = { /* code 0035, DIGIT FIVE */
  0x1F, 0xFF, 0xFF,
  0x4B, 0x00, 0x00,
  0x68, 0x00, 0x00,
  0x96, 0x00, 0x00,
  0xBB, 0xEE, 0x91,
  0xE6, 0x00, 0x5A,
  0x00, 0x00, 0x0F,
  0x00, 0x00, 0x0F,
  0xD4, 0x00, 0x6D,
  0x2B, 0xFE, 0xA2
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0036[ 30] = { /* code 0036, DIGIT SIX */
  0x18, 0xEF, 0xC3,
  0x99, 0x20, 0x6D,
  0xC7, 0x00, 0x00,
  0xE3, 0x00, 0x00,
  0xF5, 0xDF, 0xA1,
  0xF9, 0x10, 0x6A,
  0xF1, 0x00, 0x0F,
  0xD0, 0x00, 0x0E,
  0xB5, 0x00, 0x79,
  0x3C, 0xFF, 0xA1
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0037[ 30] = { /* code 0037, DIGIT SEVEN */
  0xFF, 0xFF, 0xFF,
  0x00, 0x00, 0x66,
  0x00, 0x03, 0xA0,
  0x00, 0x0C, 0x10,
  0x00, 0x78, 0x00,
  0x00, 0xD1, 0x00,
  0x05, 0xB0, 0x00,
  0x09, 0x60, 0x00,
  0x0C, 0x30, 0x00,
  0x0F, 0x10, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0038[ 30] = { /* code 0038, DIGIT EIGHT */
  0x1B, 0xFF, 0xA1,
  0xB6, 0x00, 0x6B,
  0xF0, 0x00, 0x0F,
  0xB5, 0x00, 0x5C,
  0x3E, 0xFF, 0xE3,
  0xB7, 0x00, 0x7A,
  0xF0, 0x00, 0x0F,
  0xE0, 0x00, 0x0E,
  0x96, 0x10, 0x79,
  0x19, 0xEE, 0x91
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0039[ 30] = { /* code 0039, DIGIT NINE */
  0x1A, 0xFE, 0x91,
  0x82, 0x00, 0x7B,
  0xE0, 0x00, 0x0F,
  0xF0, 0x00, 0x1F,
  0xA6, 0x01, 0x9F,
  0x1A, 0xFD, 0x5F,
  0x00, 0x00, 0x3D,
  0x00, 0x00, 0x5A,
  0xD6, 0x02, 0xB3,
  0x3C, 0xFD, 0x50
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_003A[  7] = { /* code 003A, COLON */
  0xF0,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_003B[  9] = { /* code 003B, SEMICOLON */
  0xF0,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00,
  0xF0,
  0x90,
  0x80
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_003C[ 21] = { /* code 003C, LESS-THAN SIGN */
  0x00, 0x00, 0x4B,
  0x00, 0x4B, 0xB4,
  0x4B, 0xB4, 0x00,
  0xF7, 0x00, 0x00,
  0x4B, 0xB4, 0x00,
  0x00, 0x4B, 0xB4,
  0x00, 0x00, 0x4B
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_003D[ 16] = { /* code 003D, EQUALS SIGN */
  0xFF, 0xFF, 0xFF, 0xF0,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0xFF, 0xFF, 0xFF, 0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_003E[ 21] = { /* code 003E, GREATER-THAN SIGN */
  0xB4, 0x00, 0x00,
  0x4B, 0xB4, 0x00,
  0x00, 0x4B, 0xB4,
  0x00, 0x00, 0x7F,
  0x00, 0x4B, 0xB4,
  0x4B, 0xB4, 0x00,
  0xB4, 0x00, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_003F[ 30] = { /* code 003F, QUESTION MARK */
  0x1B, 0xFC, 0x20,
  0x95, 0x08, 0xB0,
  0xE1, 0x00, 0xF0,
  0x00, 0x03, 0xD0,
  0x00, 0x4E, 0x40,
  0x04, 0xE4, 0x00,
  0x0D, 0x40, 0x00,
  0x0F, 0x00, 0x00,
  0x00, 0x00, 0x00,
  0x0F, 0x00, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0040[ 78] = { /* code 0040, COMMERCIAL AT */
  0x00, 0x06, 0xBE, 0xFE, 0xA3, 0x00,
  0x01, 0xBA, 0x41, 0x02, 0x7E, 0x70,
  0x09, 0x50, 0x00, 0x00, 0x02, 0xE3,
  0x39, 0x02, 0xAE, 0xE7, 0xE0, 0x6B,
  0x94, 0x1D, 0x71, 0x19, 0xB0, 0x1E,
  0xD1, 0x97, 0x00, 0x00, 0x80, 0x0F,
  0xF0, 0xE1, 0x00, 0x02, 0x50, 0x3C,
  0xF0, 0xE0, 0x00, 0x08, 0x30, 0x97,
  0xC1, 0xA7, 0x12, 0x8F, 0x16, 0xC0,
  0x85, 0x1A, 0xFD, 0x5C, 0xFA, 0x10,
  0x1B, 0x10, 0x00, 0x00, 0x00, 0x7B,
  0x03, 0xB5, 0x20, 0x01, 0x4B, 0xB1,
  0x00, 0x17, 0xCF, 0xFE, 0xB6, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0041[ 60] = { /* code 0041, LATIN CAPITAL LETTER A */
  0x00, 0x00, 0x4F, 0x40, 0x00, 0x00,
  0x00, 0x00, 0xB9, 0xB0, 0x00, 0x00,
  0x00, 0x02, 0xD0, 0xD2, 0x00, 0x00,
  0x00, 0x07, 0x80, 0x87, 0x00, 0x00,
  0x00, 0x0D, 0x20, 0x2D, 0x00, 0x00,
  0x00, 0x4B, 0x00, 0x0B, 0x40, 0x00,
  0x00, 0xBF, 0xFF, 0xFF, 0xB0, 0x00,
  0x02, 0xD0, 0x00, 0x00, 0xD2, 0x00,
  0x07, 0x70, 0x00, 0x00, 0x77, 0x00,
  0x0C, 0x10, 0x00, 0x00, 0x1C, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0042[ 40] = { /* code 0042, LATIN CAPITAL LETTER B */
  0xFF, 0xFF, 0xFB, 0x20,
  0xF0, 0x00, 0x17, 0xD0,
  0xF0, 0x00, 0x00, 0xF0,
  0xF0, 0x00, 0x17, 0x70,
  0xFF, 0xFF, 0xFF, 0x60,
  0xF0, 0x00, 0x16, 0xD0,
  0xF0, 0x00, 0x00, 0xF0,
  0xF0, 0x00, 0x01, 0xE0,
  0xF0, 0x00, 0x18, 0x90,
  0xFF, 0xFF, 0xE9, 0x10
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0043[ 40] = { /* code 0043, LATIN CAPITAL LETTER C */
  0x03, 0xBF, 0xE7, 0x00,
  0x2D, 0x50, 0x2C, 0x70,
  0x97, 0x00, 0x03, 0xC0,
  0xD2, 0x00, 0x00, 0x00,
  0xF0, 0x00, 0x00, 0x00,
  0xF0, 0x00, 0x00, 0x00,
  0xD2, 0x00, 0x00, 0x50,
  0x97, 0x00, 0x04, 0xC0,
  0x2E, 0x50, 0x3D, 0x50,
  0x04, 0xCF, 0xE6, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0044[ 40] = { /* code 0044, LATIN CAPITAL LETTER D */
  0xFF, 0xFF, 0xF5, 0x00,
  0xF0, 0x00, 0x5F, 0x50,
  0xF0, 0x00, 0x05, 0xF0,
  0xF0, 0x00, 0x00, 0xF0,
  0xF0, 0x00, 0x00, 0xF0,
  0xF0, 0x00, 0x00, 0xF0,
  0xF0, 0x00, 0x00, 0xF0,
  0xF0, 0x00, 0x05, 0xF0,
  0xF0, 0x00, 0x5F, 0x50,
  0xFF, 0xFF, 0xF5, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0045[ 40] = { /* code 0045, LATIN CAPITAL LETTER E */
  0xFF, 0xFF, 0xFF, 0xF0,
  0xF0, 0x00, 0x00, 0x00,
  0xF0, 0x00, 0x00, 0x00,
  0xF0, 0x00, 0x00, 0x00,
  0xFF, 0xFF, 0xFF, 0xF0,
  0xF0, 0x00, 0x00, 0x00,
  0xF0, 0x00, 0x00, 0x00,
  0xF0, 0x00, 0x00, 0x00,
  0xF0, 0x00, 0x00, 0x00,
  0xFF, 0xFF, 0xFF, 0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0046[ 30] = { /* code 0046, LATIN CAPITAL LETTER F */
  0xFF, 0xFF, 0xFF,
  0xF0, 0x00, 0x00,
  0xF0, 0x00, 0x00,
  0xF0, 0x00, 0x00,
  0xFF, 0xFF, 0xF0,
  0xF0, 0x00, 0x00,
  0xF0, 0x00, 0x00,
  0xF0, 0x00, 0x00,
  0xF0, 0x00, 0x00,
  0xF0, 0x00, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0047[ 40] = { /* code 0047, LATIN CAPITAL LETTER G */
  0x05, 0xFF, 0xFE, 0x30,
  0x5F, 0x50, 0x05, 0xE3,
  0xF5, 0x00, 0x00, 0x5C,
  0xF0, 0x00, 0x00, 0x00,
  0xF0, 0x00, 0x00, 0x00,
  0xF0, 0x00, 0xFF, 0xFF,
  0xF0, 0x00, 0x00, 0x0F,
  0xF5, 0x00, 0x00, 0x5F,
  0x5F, 0x50, 0x05, 0xF5,
  0x05, 0xFF, 0xFF, 0x50
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0048[ 40] = { /* code 0048, LATIN CAPITAL LETTER H */
  0xF0, 0x00, 0x00, 0xF0,
  0xF0, 0x00, 0x00, 0xF0,
  0xF0, 0x00, 0x00, 0xF0,
  0xF0, 0x00, 0x00, 0xF0,
  0xFF, 0xFF, 0xFF, 0xF0,
  0xF0, 0x00, 0x00, 0xF0,
  0xF0, 0x00, 0x00, 0xF0,
  0xF0, 0x00, 0x00, 0xF0,
  0xF0, 0x00, 0x00, 0xF0,
  0xF0, 0x00, 0x00, 0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0049[ 10] = { /* code 0049, LATIN CAPITAL LETTER I */
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_004A[ 30] = { /* code 004A, LATIN CAPITAL LETTER J */
  0x00, 0x00, 0xF0,
  0x00, 0x00, 0xF0,
  0x00, 0x00, 0xF0,
  0x00, 0x00, 0xF0,
  0x00, 0x00, 0xF0,
  0x00, 0x00, 0xF0,
  0x00, 0x00, 0xF0,
  0xE1, 0x00, 0xF0,
  0xC7, 0x06, 0xB0,
  0x3D, 0xFC, 0x20
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_004B[ 40] = { /* code 004B, LATIN CAPITAL LETTER K */
  0xF0, 0x00, 0x00, 0x78,
  0xF0, 0x00, 0x07, 0x80,
  0xF0, 0x00, 0x78, 0x00,
  0xF0, 0x07, 0x80, 0x00,
  0xF0, 0x7C, 0x00, 0x00,
  0xF7, 0x89, 0x60, 0x00,
  0xF8, 0x00, 0xB3, 0x00,
  0xF0, 0x00, 0x1C, 0x10,
  0xF0, 0x00, 0x03, 0xB0,
  0xF0, 0x00, 0x00, 0x69
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_004C[ 30] = { /* code 004C, LATIN CAPITAL LETTER L */
  0xF0, 0x00, 0x00,
  0xF0, 0x00, 0x00,
  0xF0, 0x00, 0x00,
  0xF0, 0x00, 0x00,
  0xF0, 0x00, 0x00,
  0xF0, 0x00, 0x00,
  0xF0, 0x00, 0x00,
  0xF0, 0x00, 0x00,
  0xF0, 0x00, 0x00,
  0xFF, 0xFF, 0xFF
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_004D[ 50] = { /* code 004D, LATIN CAPITAL LETTER M */
  0xC6, 0x00, 0x00, 0x06, 0xC0,
  0xFC, 0x10, 0x00, 0x1C, 0xF0,
  0xF7, 0x60, 0x00, 0x68, 0xF0,
  0xF2, 0xC0, 0x00, 0xC3, 0xF0,
  0xF0, 0xC3, 0x03, 0xD0, 0xF0,
  0xF0, 0x79, 0x09, 0x70, 0xF0,
  0xF0, 0x2E, 0x1E, 0x20, 0xF0,
  0xF0, 0x0B, 0xBC, 0x00, 0xF0,
  0xF0, 0x07, 0xF7, 0x00, 0xF0,
  0xF0, 0x02, 0xF2, 0x00, 0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_004E[ 40] = { /* code 004E, LATIN CAPITAL LETTER N */
  0xF5, 0x00, 0x00, 0xF0,
  0xFC, 0x10, 0x00, 0xF0,
  0xF6, 0x80, 0x00, 0xF0,
  0xF0, 0xC2, 0x00, 0xF0,
  0xF0, 0x4A, 0x00, 0xF0,
  0xF0, 0x0A, 0x40, 0xF0,
  0xF0, 0x02, 0xC0, 0xF0,
  0xF0, 0x00, 0x86, 0xF0,
  0xF0, 0x00, 0x1C, 0xF0,
  0xF0, 0x00, 0x05, 0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_004F[ 40] = { /* code 004F, LATIN CAPITAL LETTER O */
  0x02, 0xAF, 0xFA, 0x20,
  0x1A, 0x30, 0x14, 0xA1,
  0x83, 0x00, 0x00, 0x07,
  0xC1, 0x00, 0x00, 0x0B,
  0xF0, 0x00, 0x00, 0x0F,
  0xF0, 0x00, 0x00, 0x0F,
  0xC1, 0x00, 0x00, 0x1C,
  0x83, 0x00, 0x00, 0x38,
  0x19, 0x30, 0x03, 0xA1,
  0x02, 0xAF, 0xFA, 0x20
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0050[ 40] = { /* code 0050, LATIN CAPITAL LETTER P */
  0xFF, 0xFF, 0xEA, 0x10,
  0xF0, 0x00, 0x05, 0xA0,
  0xF0, 0x00, 0x00, 0xF0,
  0xF0, 0x00, 0x00, 0xE0,
  0xF0, 0x00, 0x16, 0x90,
  0xFF, 0xFF, 0xE9, 0x10,
  0xF0, 0x00, 0x00, 0x00,
  0xF0, 0x00, 0x00, 0x00,
  0xF0, 0x00, 0x00, 0x00,
  0xF0, 0x00, 0x00, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0051[ 44] = { /* code 0051, LATIN CAPITAL LETTER Q */
  0x02, 0xAF, 0xFA, 0x20,
  0x1D, 0x50, 0x16, 0xD1,
  0x86, 0x00, 0x00, 0x68,
  0xC2, 0x00, 0x00, 0x2C,
  0xF0, 0x00, 0x00, 0x0F,
  0xF0, 0x00, 0x00, 0x0F,
  0xC2, 0x00, 0x00, 0x2D,
  0x87, 0x00, 0xB9, 0x69,
  0x1C, 0x50, 0x5D, 0xF2,
  0x02, 0xAE, 0xE8, 0x8B,
  0x00, 0x00, 0x00, 0x04
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0052[ 40] = { /* code 0052, LATIN CAPITAL LETTER R */
  0xFF, 0xFF, 0xFB, 0x10,
  0xF0, 0x00, 0x07, 0xA0,
  0xF0, 0x00, 0x00, 0xF0,
  0xF0, 0x00, 0x00, 0xF0,
  0xF0, 0x00, 0x17, 0xA0,
  0xFF, 0xFF, 0xFA, 0x10,
  0xF0, 0x04, 0xC1, 0x00,
  0xF0, 0x00, 0x6A, 0x00,
  0xF0, 0x00, 0x0B, 0x50,
  0xF0, 0x00, 0x02, 0xC0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0053[ 40] = { /* code 0053, LATIN CAPITAL LETTER S */
  0x19, 0xEF, 0xD8, 0x00,
  0xA7, 0x10, 0x18, 0x80,
  0xF0, 0x00, 0x01, 0xE0,
  0xD8, 0x00, 0x00, 0x00,
  0x3D, 0xD9, 0x53, 0x00,
  0x00, 0x37, 0xBF, 0x60,
  0x00, 0x00, 0x03, 0xE0,
  0xE0, 0x00, 0x00, 0xF0,
  0x97, 0x20, 0x17, 0x90,
  0x1B, 0xEF, 0xE8, 0x10
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0054[ 40] = { /* code 0054, LATIN CAPITAL LETTER T */
  0xFF, 0xFF, 0xFF, 0xF0,
  0x00, 0x0F, 0x00, 0x00,
  0x00, 0x0F, 0x00, 0x00,
  0x00, 0x0F, 0x00, 0x00,
  0x00, 0x0F, 0x00, 0x00,
  0x00, 0x0F, 0x00, 0x00,
  0x00, 0x0F, 0x00, 0x00,
  0x00, 0x0F, 0x00, 0x00,
  0x00, 0x0F, 0x00, 0x00,
  0x00, 0x0F, 0x00, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0055[ 40] = { /* code 0055, LATIN CAPITAL LETTER U */
  0xF0, 0x00, 0x00, 0xF0,
  0xF0, 0x00, 0x00, 0xF0,
  0xF0, 0x00, 0x00, 0xF0,
  0xF0, 0x00, 0x00, 0xF0,
  0xF0, 0x00, 0x00, 0xF0,
  0xF0, 0x00, 0x00, 0xF0,
  0xE0, 0x00, 0x00, 0xF0,
  0xB3, 0x00, 0x03, 0xB0,
  0x4B, 0x20, 0x2B, 0x40,
  0x06, 0xDF, 0xE6, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0056[ 60] = { /* code 0056, LATIN CAPITAL LETTER V */
  0x5E, 0x00, 0x00, 0x00, 0x0E, 0x50,
  0x0C, 0x60, 0x00, 0x00, 0x6C, 0x00,
  0x05, 0xD0, 0x00, 0x00, 0xC5, 0x00,
  0x00, 0xC5, 0x00, 0x04, 0xC0, 0x00,
  0x00, 0x5B, 0x00, 0x0B, 0x50, 0x00,
  0x00, 0x0C, 0x30, 0x3C, 0x00, 0x00,
  0x00, 0x05, 0xA0, 0xA5, 0x00, 0x00,
  0x00, 0x00, 0xC4, 0xC0, 0x00, 0x00,
  0x00, 0x00, 0x5E, 0x50, 0x00, 0x00,
  0x00, 0x00, 0x09, 0x00, 0x00, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0057[ 70] = { /* code 0057, LATIN CAPITAL LETTER W */
  0xD2, 0x00, 0x05, 0xF5, 0x00, 0x02, 0xD0,
  0x86, 0x00, 0x09, 0xC9, 0x00, 0x06, 0x80,
  0x3B, 0x00, 0x0D, 0x4D, 0x00, 0x0B, 0x30,
  0x0D, 0x00, 0x2D, 0x0D, 0x20, 0x1D, 0x00,
  0x09, 0x40, 0x69, 0x08, 0x60, 0x5A, 0x00,
  0x04, 0x90, 0xA4, 0x03, 0xA0, 0x95, 0x00,
  0x00, 0xC0, 0xE1, 0x00, 0xD0, 0xD1, 0x00,
  0x00, 0xAA, 0xB0, 0x00, 0xAA, 0xB0, 0x00,
  0x00, 0x5F, 0x60, 0x00, 0x5F, 0x60, 0x00,
  0x00, 0x0F, 0x20, 0x00, 0x1F, 0x20, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0058[ 40] = { /* code 0058, LATIN CAPITAL LETTER X */
  0xB4, 0x00, 0x04, 0xB0,
  0x2C, 0x00, 0x0C, 0x20,
  0x08, 0x70, 0x68, 0x00,
  0x00, 0xD4, 0xC0, 0x00,
  0x00, 0x5F, 0x50, 0x00,
  0x00, 0x5F, 0x50, 0x00,
  0x00, 0xD4, 0xD0, 0x00,
  0x08, 0x70, 0x78, 0x00,
  0x2C, 0x00, 0x0C, 0x20,
  0xB4, 0x00, 0x04, 0xB0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0059[ 40] = { /* code 0059, LATIN CAPITAL LETTER Y */
  0xB4, 0x00, 0x04, 0xB0,
  0x3B, 0x00, 0x0B, 0x30,
  0x0A, 0x50, 0x4A, 0x00,
  0x03, 0xC0, 0xC3, 0x00,
  0x00, 0xA9, 0xA0, 0x00,
  0x00, 0x2F, 0x20, 0x00,
  0x00, 0x0F, 0x00, 0x00,
  0x00, 0x0F, 0x00, 0x00,
  0x00, 0x0F, 0x00, 0x00,
  0x00, 0x0F, 0x00, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_005A[ 40] = { /* code 005A, LATIN CAPITAL LETTER Z */
  0x0F, 0xFF, 0xFF, 0x90,
  0x00, 0x00, 0x1C, 0x10,
  0x00, 0x00, 0x86, 0x00,
  0x00, 0x02, 0xC0, 0x00,
  0x00, 0x0A, 0x40, 0x00,
  0x00, 0x4B, 0x00, 0x00,
  0x00, 0xC3, 0x00, 0x00,
  0x06, 0x90, 0x00, 0x00,
  0x1C, 0x10, 0x00, 0x00,
  0xAF, 0xFF, 0xFF, 0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_005B[ 13] = { /* code 005B, LEFT SQUARE BRACKET */
  0xFF,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xFF
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_005C[ 20] = { /* code 005C, REVERSE SOLIDUS */
  0xD2, 0x00,
  0x87, 0x00,
  0x4B, 0x00,
  0x0E, 0x10,
  0x0A, 0x50,
  0x05, 0xA0,
  0x01, 0xE0,
  0x00, 0xB4,
  0x00, 0x78,
  0x00, 0x2D
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_005D[ 13] = { /* code 005D, RIGHT SQUARE BRACKET */
  0xFF,
  0x0F,
  0x0F,
  0x0F,
  0x0F,
  0x0F,
  0x0F,
  0x0F,
  0x0F,
  0x0F,
  0x0F,
  0x0F,
  0xFF
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_005E[ 15] = { /* code 005E, CIRCUMFLEX ACCENT */
  0x03, 0xF3, 0x00,
  0x09, 0x99, 0x00,
  0x1D, 0x0D, 0x10,
  0x68, 0x08, 0x60,
  0xC3, 0x03, 0xC0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_005F[  4] = { /* code 005F, LOW LINE */
  0xFF, 0xFF, 0xFF, 0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0060[  2] = { /* code 0060, GRAVE ACCENT */
  0xB4,
  0x4B
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0061[ 21] = { /* code 0061, LATIN SMALL LETTER A */
  0x3C, 0xFE, 0x60,
  0xD4, 0x05, 0xE0,
  0x00, 0x00, 0xF0,
  0x17, 0xAD, 0xF0,
  0xC8, 0x52, 0xF0,
  0xF3, 0x19, 0xF0,
  0x5D, 0xE7, 0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0062[ 30] = { /* code 0062, LATIN SMALL LETTER B */
  0xF0, 0x00, 0x00,
  0xF0, 0x00, 0x00,
  0xF0, 0x00, 0x00,
  0xF3, 0xDB, 0x10,
  0xF9, 0x04, 0x90,
  0xF1, 0x00, 0xE0,
  0xF0, 0x00, 0xF0,
  0xF1, 0x00, 0xE0,
  0xF8, 0x05, 0x90,
  0xF4, 0xDB, 0x10
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0063[ 21] = { /* code 0063, LATIN SMALL LETTER C */
  0x1B, 0xFD, 0x30,
  0x95, 0x05, 0xD0,
  0xE0, 0x00, 0x00,
  0xF0, 0x00, 0x00,
  0xE0, 0x00, 0x00,
  0x94, 0x04, 0xD0,
  0x1B, 0xFD, 0x30
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0064[ 30] = { /* code 0064, LATIN SMALL LETTER D */
  0x00, 0x00, 0xF0,
  0x00, 0x00, 0xF0,
  0x00, 0x00, 0xF0,
  0x1B, 0xE6, 0xF0,
  0x97, 0x09, 0xF0,
  0xE1, 0x01, 0xF0,
  0xF0, 0x00, 0xF0,
  0xE1, 0x01, 0xF0,
  0x97, 0x08, 0xF0,
  0x1B, 0xE5, 0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0065[ 21] = { /* code 0065, LATIN SMALL LETTER E */
  0x1B, 0xFB, 0x10,
  0x92, 0x06, 0x90,
  0xE0, 0x01, 0xD0,
  0xFF, 0xFF, 0xF0,
  0xE0, 0x00, 0x00,
  0x92, 0x06, 0xC0,
  0x1B, 0xFD, 0x20
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0066[ 20] = { /* code 0066, LATIN SMALL LETTER F */
  0x05, 0xFA,
  0x0F, 0x50,
  0x0F, 0x00,
  0xFF, 0xF0,
  0x0F, 0x00,
  0x0F, 0x00,
  0x0F, 0x00,
  0x0F, 0x00,
  0x0F, 0x00,
  0x0F, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0067[ 30] = { /* code 0067, LATIN SMALL LETTER G */
  0x1C, 0xE7, 0xF0,
  0x96, 0x09, 0xF0,
  0xE1, 0x01, 0xF0,
  0xF0, 0x00, 0xF0,
  0xE1, 0x01, 0xF0,
  0x97, 0x09, 0xF0,
  0x1B, 0xE5, 0xF0,
  0x00, 0x01, 0xE0,
  0xE4, 0x08, 0xB0,
  0x5D, 0xFB, 0x20
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0068[ 30] = { /* code 0068, LATIN SMALL LETTER H */
  0xF0, 0x00, 0x00,
  0xF0, 0x00, 0x00,
  0xF0, 0x00, 0x00,
  0xF5, 0xEF, 0x50,
  0xF8, 0x05, 0xF0,
  0xF1, 0x00, 0xF0,
  0xF0, 0x00, 0xF0,
  0xF0, 0x00, 0xF0,
  0xF0, 0x00, 0xF0,
  0xF0, 0x00, 0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0069[ 10] = { /* code 0069, LATIN SMALL LETTER I */
  0xF0,
  0x00,
  0x00,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_006A[ 26] = { /* code 006A, LATIN SMALL LETTER J */
  0x00, 0xF0,
  0x00, 0x00,
  0x00, 0x00,
  0x00, 0xF0,
  0x00, 0xF0,
  0x00, 0xF0,
  0x00, 0xF0,
  0x00, 0xF0,
  0x00, 0xF0,
  0x00, 0xF0,
  0x00, 0xF0,
  0x05, 0xF0,
  0x7F, 0x50
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_006B[ 30] = { /* code 006B, LATIN SMALL LETTER K */
  0xF0, 0x00, 0x00,
  0xF0, 0x00, 0x00,
  0xF0, 0x00, 0x00,
  0xF0, 0x07, 0x80,
  0xF0, 0x78, 0x00,
  0xF6, 0xB0, 0x00,
  0xFA, 0xC2, 0x00,
  0xF0, 0x59, 0x00,
  0xF0, 0x0C, 0x30,
  0xF0, 0x04, 0xB0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_006C[ 10] = { /* code 006C, LATIN SMALL LETTER L */
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_006D[ 35] = { /* code 006D, LATIN SMALL LETTER M */
  0xF6, 0xEE, 0x54, 0xEF, 0x50,
  0xF9, 0x04, 0xC7, 0x05, 0xF0,
  0xF1, 0x00, 0xF1, 0x00, 0xF0,
  0xF0, 0x00, 0xF0, 0x00, 0xF0,
  0xF0, 0x00, 0xF0, 0x00, 0xF0,
  0xF0, 0x00, 0xF0, 0x00, 0xF0,
  0xF0, 0x00, 0xF0, 0x00, 0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_006E[ 21] = { /* code 006E, LATIN SMALL LETTER N */
  0xF7, 0xDF, 0x50,
  0xF8, 0x05, 0xF0,
  0xF1, 0x00, 0xF0,
  0xF0, 0x00, 0xF0,
  0xF0, 0x00, 0xF0,
  0xF0, 0x00, 0xF0,
  0xF0, 0x00, 0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_006F[ 21] = { /* code 006F, LATIN SMALL LETTER O */
  0x1B, 0xFB, 0x10,
  0x96, 0x05, 0xA0,
  0xE1, 0x00, 0xE0,
  0xF0, 0x00, 0xF0,
  0xE1, 0x00, 0xE0,
  0x96, 0x05, 0xA0,
  0x1B, 0xFB, 0x10
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0070[ 30] = { /* code 0070, LATIN SMALL LETTER P */
  0xF6, 0xFC, 0x10,
  0xF9, 0x06, 0x90,
  0xF2, 0x01, 0xE0,
  0xF0, 0x00, 0xF0,
  0xF1, 0x01, 0xE0,
  0xF8, 0x06, 0x90,
  0xF7, 0xFB, 0x10,
  0xF0, 0x00, 0x00,
  0xF0, 0x00, 0x00,
  0xF0, 0x00, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0071[ 30] = { /* code 0071, LATIN SMALL LETTER Q */
  0x1C, 0xE6, 0xF0,
  0xA5, 0x09, 0xF0,
  0xE0, 0x02, 0xF0,
  0xF0, 0x00, 0xF0,
  0xE0, 0x01, 0xF0,
  0x95, 0x09, 0xF0,
  0x1B, 0xF7, 0xF0,
  0x00, 0x00, 0xF0,
  0x00, 0x00, 0xF0,
  0x00, 0x00, 0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0072[ 14] = { /* code 0072, LATIN SMALL LETTER R */
  0xF7, 0xD0,
  0xF5, 0x10,
  0xF1, 0x00,
  0xF0, 0x00,
  0xF0, 0x00,
  0xF0, 0x00,
  0xF0, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0073[ 21] = { /* code 0073, LATIN SMALL LETTER S */
  0x5F, 0xFC, 0x40,
  0xF6, 0x04, 0xD0,
  0xBB, 0x41, 0x00,
  0x1B, 0xFE, 0x30,
  0x00, 0x06, 0xE0,
  0xD5, 0x05, 0xF0,
  0x3C, 0xFF, 0x50
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0074[ 20] = { /* code 0074, LATIN SMALL LETTER T */
  0x01, 0x00,
  0x0E, 0x00,
  0x0F, 0x00,
  0xFF, 0xF0,
  0x0F, 0x00,
  0x0F, 0x00,
  0x0F, 0x00,
  0x0F, 0x00,
  0x0F, 0x10,
  0x0B, 0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0075[ 21] = { /* code 0075, LATIN SMALL LETTER U */
  0xF0, 0x00, 0xF0,
  0xF0, 0x00, 0xF0,
  0xF0, 0x00, 0xF0,
  0xF0, 0x00, 0xF0,
  0xF0, 0x01, 0xF0,
  0xF5, 0x08, 0xF0,
  0x5F, 0xE6, 0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0076[ 21] = { /* code 0076, LATIN SMALL LETTER V */
  0xD2, 0x02, 0xD0,
  0x96, 0x06, 0x90,
  0x4A, 0x0A, 0x40,
  0x0E, 0x0E, 0x10,
  0x0B, 0x9B, 0x00,
  0x06, 0xF7, 0x00,
  0x02, 0xF3, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0077[ 35] = { /* code 0077, LATIN SMALL LETTER W */
  0xD2, 0x03, 0xF3, 0x02, 0xD0,
  0x96, 0x07, 0xF7, 0x06, 0x90,
  0x4A, 0x0B, 0x8B, 0x0B, 0x40,
  0x1E, 0x1E, 0x1E, 0x1E, 0x10,
  0x0B, 0x7B, 0x0B, 0x8B, 0x00,
  0x07, 0xE7, 0x07, 0xF7, 0x00,
  0x03, 0xF3, 0x03, 0xF3, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0078[ 21] = { /* code 0078, LATIN SMALL LETTER X */
  0xB4, 0x04, 0xB0,
  0x2C, 0x0C, 0x20,
  0x09, 0xC8, 0x00,
  0x02, 0xF2, 0x00,
  0x09, 0xB8, 0x00,
  0x2C, 0x0C, 0x20,
  0xB4, 0x04, 0xB0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_0079[ 30] = { /* code 0079, LATIN SMALL LETTER Y */
  0xD2, 0x02, 0xD0,
  0x96, 0x06, 0x80,
  0x5B, 0x0B, 0x40,
  0x1E, 0x1E, 0x00,
  0x0B, 0x9B, 0x00,
  0x07, 0xF6, 0x00,
  0x03, 0xF2, 0x00,
  0x01, 0xC0, 0x00,
  0x08, 0x80, 0x00,
  0xFB, 0x10, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_007A[ 21] = { /* code 007A, LATIN SMALL LETTER Z */
  0xFF, 0xFF, 0xD0,
  0x00, 0x0B, 0x50,
  0x00, 0x6A, 0x00,
  0x02, 0xD1, 0x00,
  0x0B, 0x50, 0x00,
  0x69, 0x00, 0x00,
  0xDF, 0xFF, 0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_007B[ 26] = { /* code 007B, LEFT CURLY BRACKET */
  0x05, 0xF0,
  0x0E, 0x20,
  0x0F, 0x00,
  0x0F, 0x00,
  0x0E, 0x00,
  0x4B, 0x00,
  0xF3, 0x00,
  0x4B, 0x00,
  0x0E, 0x00,
  0x0F, 0x00,
  0x0F, 0x00,
  0x0B, 0x20,
  0x06, 0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_007C[ 12] = { /* code 007C, VERTICAL LINE */
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0,
  0xF0
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_007D[ 26] = { /* code 007D, RIGHT CURLY BRACKET */
  0xF5, 0x00,
  0x2B, 0x00,
  0x0F, 0x00,
  0x0F, 0x00,
  0x0E, 0x00,
  0x0B, 0x40,
  0x03, 0xF0,
  0x0B, 0x40,
  0x0F, 0x00,
  0x0F, 0x00,
  0x0F, 0x00,
  0x2E, 0x00,
  0xF6, 0x00
};

GUI_CONST_STORAGE unsigned char acGUI_Font16_AA4_007E[ 12] = { /* code 007E, TILDE */
  0x5E, 0xE9, 0x21, 0x80,
  0xB1, 0x28, 0xEE, 0x70,
  0x10, 0x00, 0x00, 0x00
};

GUI_CONST_STORAGE GUI_CHARINFO_EXT GUI_Font16_AA4_CharInfo[95] = {
   {   1,   1,   0,  13,   4, acGUI_Font16_AA4_0020 } /* code 0020, SPACE */
  ,{   1,  10,   1,   3,   3, acGUI_Font16_AA4_0021 } /* code 0021, EXCLAMATION MARK */
  ,{   3,   3,   1,   3,   5, acGUI_Font16_AA4_0022 } /* code 0022, QUOTATION MARK */
  ,{   8,  10,   0,   3,   7, acGUI_Font16_AA4_0023 } /* code 0023, NUMBER SIGN */
  ,{   5,  11,   1,   3,   7, acGUI_Font16_AA4_0024 } /* code 0024, DOLLAR SIGN */
  ,{  10,  10,   1,   3,  12, acGUI_Font16_AA4_0025 } /* code 0025, PERCENT SIGN */
  ,{   8,  10,   1,   3,   9, acGUI_Font16_AA4_0026 } /* code 0026, AMPERSAND */
  ,{   1,   3,   1,   3,   2, acGUI_Font16_AA4_0027 } /* code 0027, APOSTROPHE */
  ,{   3,  13,   1,   3,   4, acGUI_Font16_AA4_0028 } /* code 0028, LEFT PARENTHESIS */
  ,{   3,  13,   0,   3,   4, acGUI_Font16_AA4_0029 } /* code 0029, RIGHT PARENTHESIS */
  ,{   5,   4,   0,   3,   5, acGUI_Font16_AA4_002A } /* code 002A, ASTERISK */
  ,{   7,   7,   1,   5,   8, acGUI_Font16_AA4_002B } /* code 002B, PLUS SIGN */
  ,{   1,   3,   2,  12,   4, acGUI_Font16_AA4_002C } /* code 002C, COMMA */
  ,{   3,   1,   0,   9,   4, acGUI_Font16_AA4_002D } /* code 002D, HYPHEN-MINUS */
  ,{   1,   1,   1,  12,   4, acGUI_Font16_AA4_002E } /* code 002E, FULL STOP */
  ,{   4,  10,   0,   3,   4, acGUI_Font16_AA4_002F } /* code 002F, SOLIDUS */
  ,{   6,  10,   0,   3,   7, acGUI_Font16_AA4_0030 } /* code 0030, DIGIT ZERO */
  ,{   3,  10,   1,   3,   7, acGUI_Font16_AA4_0031 } /* code 0031, DIGIT ONE */
  ,{   6,  10,   0,   3,   7, acGUI_Font16_AA4_0032 } /* code 0032, DIGIT TWO */
  ,{   6,  10,   0,   3,   7, acGUI_Font16_AA4_0033 } /* code 0033, DIGIT THREE */
  ,{   6,  10,   0,   3,   7, acGUI_Font16_AA4_0034 } /* code 0034, DIGIT FOUR */
  ,{   6,  10,   0,   3,   7, acGUI_Font16_AA4_0035 } /* code 0035, DIGIT FIVE */
  ,{   6,  10,   0,   3,   7, acGUI_Font16_AA4_0036 } /* code 0036, DIGIT SIX */
  ,{   6,  10,   0,   3,   7, acGUI_Font16_AA4_0037 } /* code 0037, DIGIT SEVEN */
  ,{   6,  10,   0,   3,   7, acGUI_Font16_AA4_0038 } /* code 0038, DIGIT EIGHT */
  ,{   6,  10,   0,   3,   7, acGUI_Font16_AA4_0039 } /* code 0039, DIGIT NINE */
  ,{   1,   7,   1,   6,   4, acGUI_Font16_AA4_003A } /* code 003A, COLON */
  ,{   1,   9,   1,   6,   4, acGUI_Font16_AA4_003B } /* code 003B, SEMICOLON */
  ,{   6,   7,   1,   5,   8, acGUI_Font16_AA4_003C } /* code 003C, LESS-THAN SIGN */
  ,{   7,   4,   0,   6,   8, acGUI_Font16_AA4_003D } /* code 003D, EQUALS SIGN */
  ,{   6,   7,   1,   5,   8, acGUI_Font16_AA4_003E } /* code 003E, GREATER-THAN SIGN */
  ,{   5,  10,   1,   3,   7, acGUI_Font16_AA4_003F } /* code 003F, QUESTION MARK */
  ,{  12,  13,   0,   3,  13, acGUI_Font16_AA4_0040 } /* code 0040, COMMERCIAL AT */
  ,{  11,  10,  -1,   3,   9, acGUI_Font16_AA4_0041 } /* code 0041, LATIN CAPITAL LETTER A */
  ,{   7,  10,   1,   3,   9, acGUI_Font16_AA4_0042 } /* code 0042, LATIN CAPITAL LETTER B */
  ,{   7,  10,   1,   3,   9, acGUI_Font16_AA4_0043 } /* code 0043, LATIN CAPITAL LETTER C */
  ,{   7,  10,   1,   3,   9, acGUI_Font16_AA4_0044 } /* code 0044, LATIN CAPITAL LETTER D */
  ,{   7,  10,   1,   3,   9, acGUI_Font16_AA4_0045 } /* code 0045, LATIN CAPITAL LETTER E */
  ,{   6,  10,   1,   3,   8, acGUI_Font16_AA4_0046 } /* code 0046, LATIN CAPITAL LETTER F */
  ,{   8,  10,   1,   3,  10, acGUI_Font16_AA4_0047 } /* code 0047, LATIN CAPITAL LETTER G */
  ,{   7,  10,   1,   3,   9, acGUI_Font16_AA4_0048 } /* code 0048, LATIN CAPITAL LETTER H */
  ,{   1,  10,   1,   3,   3, acGUI_Font16_AA4_0049 } /* code 0049, LATIN CAPITAL LETTER I */
  ,{   5,  10,   0,   3,   6, acGUI_Font16_AA4_004A } /* code 004A, LATIN CAPITAL LETTER J */
  ,{   8,  10,   1,   3,   9, acGUI_Font16_AA4_004B } /* code 004B, LATIN CAPITAL LETTER K */
  ,{   6,  10,   1,   3,   7, acGUI_Font16_AA4_004C } /* code 004C, LATIN CAPITAL LETTER L */
  ,{   9,  10,   1,   3,  11, acGUI_Font16_AA4_004D } /* code 004D, LATIN CAPITAL LETTER M */
  ,{   7,  10,   1,   3,   9, acGUI_Font16_AA4_004E } /* code 004E, LATIN CAPITAL LETTER N */
  ,{   8,  10,   1,   3,  10, acGUI_Font16_AA4_004F } /* code 004F, LATIN CAPITAL LETTER O */
  ,{   7,  10,   1,   3,   9, acGUI_Font16_AA4_0050 } /* code 0050, LATIN CAPITAL LETTER P */
  ,{   8,  11,   1,   3,  10, acGUI_Font16_AA4_0051 } /* code 0051, LATIN CAPITAL LETTER Q */
  ,{   8,  10,   1,   3,   9, acGUI_Font16_AA4_0052 } /* code 0052, LATIN CAPITAL LETTER R */
  ,{   7,  10,   1,   3,   9, acGUI_Font16_AA4_0053 } /* code 0053, LATIN CAPITAL LETTER S */
  ,{   7,  10,   0,   3,   7, acGUI_Font16_AA4_0054 } /* code 0054, LATIN CAPITAL LETTER T */
  ,{   7,  10,   1,   3,   9, acGUI_Font16_AA4_0055 } /* code 0055, LATIN CAPITAL LETTER U */
  ,{  11,  10,  -1,   3,   9, acGUI_Font16_AA4_0056 } /* code 0056, LATIN CAPITAL LETTER V */
  ,{  13,  10,   0,   3,  13, acGUI_Font16_AA4_0057 } /* code 0057, LATIN CAPITAL LETTER W */
  ,{   7,  10,   0,   3,   7, acGUI_Font16_AA4_0058 } /* code 0058, LATIN CAPITAL LETTER X */
  ,{   7,  10,   1,   3,   9, acGUI_Font16_AA4_0059 } /* code 0059, LATIN CAPITAL LETTER Y */
  ,{   7,  10,   0,   3,   7, acGUI_Font16_AA4_005A } /* code 005A, LATIN CAPITAL LETTER Z */
  ,{   2,  13,   1,   3,   4, acGUI_Font16_AA4_005B } /* code 005B, LEFT SQUARE BRACKET */
  ,{   4,  10,   0,   3,   4, acGUI_Font16_AA4_005C } /* code 005C, REVERSE SOLIDUS */
  ,{   2,  13,   1,   3,   4, acGUI_Font16_AA4_005D } /* code 005D, RIGHT SQUARE BRACKET */
  ,{   5,   5,   0,   4,   5, acGUI_Font16_AA4_005E } /* code 005E, CIRCUMFLEX ACCENT */
  ,{   7,   1,   0,  15,   7, acGUI_Font16_AA4_005F } /* code 005F, LOW LINE */
  ,{   2,   2,   1,   3,   4, acGUI_Font16_AA4_0060 } /* code 0060, GRAVE ACCENT */
  ,{   5,   7,   1,   6,   7, acGUI_Font16_AA4_0061 } /* code 0061, LATIN SMALL LETTER A */
  ,{   5,  10,   1,   3,   7, acGUI_Font16_AA4_0062 } /* code 0062, LATIN SMALL LETTER B */
  ,{   5,   7,   1,   6,   7, acGUI_Font16_AA4_0063 } /* code 0063, LATIN SMALL LETTER C */
  ,{   5,  10,   1,   3,   7, acGUI_Font16_AA4_0064 } /* code 0064, LATIN SMALL LETTER D */
  ,{   5,   7,   1,   6,   7, acGUI_Font16_AA4_0065 } /* code 0065, LATIN SMALL LETTER E */
  ,{   4,  10,   0,   3,   3, acGUI_Font16_AA4_0066 } /* code 0066, LATIN SMALL LETTER F */
  ,{   5,  10,   1,   6,   7, acGUI_Font16_AA4_0067 } /* code 0067, LATIN SMALL LETTER G */
  ,{   5,  10,   1,   3,   7, acGUI_Font16_AA4_0068 } /* code 0068, LATIN SMALL LETTER H */
  ,{   1,  10,   1,   3,   3, acGUI_Font16_AA4_0069 } /* code 0069, LATIN SMALL LETTER I */
  ,{   3,  13,  -1,   3,   3, acGUI_Font16_AA4_006A } /* code 006A, LATIN SMALL LETTER J */
  ,{   5,  10,   1,   3,   7, acGUI_Font16_AA4_006B } /* code 006B, LATIN SMALL LETTER K */
  ,{   1,  10,   1,   3,   3, acGUI_Font16_AA4_006C } /* code 006C, LATIN SMALL LETTER L */
  ,{   9,   7,   1,   6,  11, acGUI_Font16_AA4_006D } /* code 006D, LATIN SMALL LETTER M */
  ,{   5,   7,   1,   6,   7, acGUI_Font16_AA4_006E } /* code 006E, LATIN SMALL LETTER N */
  ,{   5,   7,   1,   6,   7, acGUI_Font16_AA4_006F } /* code 006F, LATIN SMALL LETTER O */
  ,{   5,  10,   1,   6,   7, acGUI_Font16_AA4_0070 } /* code 0070, LATIN SMALL LETTER P */
  ,{   5,  10,   1,   6,   7, acGUI_Font16_AA4_0071 } /* code 0071, LATIN SMALL LETTER Q */
  ,{   3,   7,   1,   6,   4, acGUI_Font16_AA4_0072 } /* code 0072, LATIN SMALL LETTER R */
  ,{   5,   7,   1,   6,   7, acGUI_Font16_AA4_0073 } /* code 0073, LATIN SMALL LETTER S */
  ,{   3,  10,   0,   3,   4, acGUI_Font16_AA4_0074 } /* code 0074, LATIN SMALL LETTER T */
  ,{   5,   7,   1,   6,   7, acGUI_Font16_AA4_0075 } /* code 0075, LATIN SMALL LETTER U */
  ,{   5,   7,   0,   6,   5, acGUI_Font16_AA4_0076 } /* code 0076, LATIN SMALL LETTER V */
  ,{   9,   7,   0,   6,   9, acGUI_Font16_AA4_0077 } /* code 0077, LATIN SMALL LETTER W */
  ,{   5,   7,   1,   6,   7, acGUI_Font16_AA4_0078 } /* code 0078, LATIN SMALL LETTER X */
  ,{   5,  10,   1,   6,   7, acGUI_Font16_AA4_0079 } /* code 0079, LATIN SMALL LETTER Y */
  ,{   5,   7,   1,   6,   7, acGUI_Font16_AA4_007A } /* code 007A, LATIN SMALL LETTER Z */
  ,{   3,  13,   0,   3,   4, acGUI_Font16_AA4_007B } /* code 007B, LEFT CURLY BRACKET */
  ,{   1,  12,   1,   3,   3, acGUI_Font16_AA4_007C } /* code 007C, VERTICAL LINE */
  ,{   3,  13,   1,   3,   4, acGUI_Font16_AA4_007D } /* code 007D, RIGHT CURLY BRACKET */
  ,{   7,   3,   0,   7,   8, acGUI_Font16_AA4_007E } /* code 007E, TILDE */
};

GUI_CONST_STORAGE GUI_FONT_PROP_EXT GUI_Font16_AA4_Prop1 = {
   0x0020 /* first character */
  ,0x007E /* last character  */
  ,&GUI_Font16_AA4_CharInfo[  0] /* address of first character */
  ,(GUI_CONST_STORAGE GUI_FONT_PROP_EXT *)0 /* pointer to next GUI_FONT_PROP_EXT */
};

GUI_CONST_STORAGE GUI_FONT GUI_Font16_AA4 = {
   GUI_FONTTYPE_PROP_AA4_EXT /* type of font    */
  ,16 /* height of font  */
  ,16 /* space of font y */
  ,1 /* magnification x */
  ,1 /* magnification y */
  ,{&GUI_Font16_AA4_Prop1}
  ,13 /* Baseline */
  ,7 /* Height of lowercase characters */
  ,10 /* Height of capital characters */
};

