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
---------------------------------------------------------------------
File        : bmSeggerLogo_60x30.c
Purpose     : 60 * 30 pixels, 16777216 colors + 8 bit Alpha
---------------------------END-OF-HEADER------------------------------
*/

#include <stdlib.h>

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

extern GUI_CONST_STORAGE GUI_BITMAP bmSeggerLogo_60x30;

static GUI_CONST_STORAGE unsigned long acSeggerLogo_60x30[] = {
  0x9F292929, 0x10292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 
        0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 
        0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x10292929, 0x9F292929,
  0x10292929, 0x00515151, 0x00AFAFAF, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 
        0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 
        0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00AFAFAF, 0x00515151, 0x10292929,
  0x00292929, 0x00AFAFAF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00AFAFAF, 0x00292929,
  0x00292929, 0x00CACACA, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00CACACA, 0x00292929,
  0x00292929, 0x00CACACA, 0x00FFFFFF, 0x00AA6661, 0x00AA6661, 0x00F8F3F3, 0x00FFFFFF, 0x00FFFFFF, 0x00CBA19E, 0x0096433D, 0x00DEC4C2, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00CACACA, 0x00292929,
  0x00292929, 0x00CACACA, 0x00FFFFFF, 0x00A35B55, 0x0096433D, 0x00B77E7A, 0x00FFFFFF, 0x00FFFFFF, 0x00CBA19E, 0x0096433D, 0x009D4F49, 0x00F2E8E7, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00CACACA, 0x00292929,
  0x00292929, 0x00CACACA, 0x00FFFFFF, 0x00EBDCDB, 0x0096433D, 0x0096433D, 0x00D1ADAA, 0x00FFFFFF, 0x00FFFFFF, 0x00AA6661, 0x0096433D, 0x00AA6661, 0x00F8F3F3, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00CACACA, 0x00292929,
  0x00292929, 0x00CACACA, 0x00FFFFFF, 0x00FFFFFF, 0x00D1ADAA, 0x0096433D, 0x0096433D, 0x00EBDCDB, 0x00FFFFFF, 0x00F8F3F3, 0x009D4F49, 0x0096433D, 0x00BD8A86, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00CACACA, 0x00292929,
  0x00292929, 0x00CACACA, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00B77E7A, 0x0096433D, 0x00A35B55, 0x00F8F3F3, 0x00FFFFFF, 0x00E5D0CF, 0x0096433D, 0x0096433D, 0x00D8B9B6, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00CACACA, 0x00292929,
  0x00292929, 0x00CACACA, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00F8F3F3, 0x00A35B55, 0x0096433D, 0x00B77E7A, 0x00FFFFFF, 0x00FFFFFF, 0x00CBA19E, 0x0096433D, 0x009D4F49, 0x00EBDCDB, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00CACACA, 0x00292929,
  0x00292929, 0x00CACACA, 0x00FFFFFF, 0x00B77E7A, 0x00FFFFFF, 0x00FFFFFF, 0x00EBDCDB, 0x0096433D, 0x0096433D, 0x00D1ADAA, 0x00FFFFFF, 0x00FFFFFF, 0x00B77E7A, 0x0096433D, 0x00A35B55, 0x00F8F3F3, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00CACACA, 0x00292929,
  0x00292929, 0x00CACACA, 0x00FFFFFF, 0x0096433D, 0x00D1ADAA, 0x00FFFFFF, 0x00FFFFFF, 0x00D1ADAA, 0x0096433D, 0x0096433D, 0x00EBDCDB, 0x00FFFFFF, 0x00F8F3F3, 0x00A35B55, 0x0096433D, 0x00B77E7A, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00CACACA, 0x00292929,
  0x00292929, 0x00CACACA, 0x00FFFFFF, 0x0096433D, 0x0096433D, 0x00EBDCDB, 0x00FFFFFF, 0x00FFFFFF, 0x00B77E7A, 0x0096433D, 0x00A35B55, 0x00F8F3F3, 0x00FFFFFF, 0x00EBDCDB, 0x0096433D, 0x0096433D, 0x00AA6661, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 
        0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 
        0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00D8B9B6, 0x00FFFFFF, 0x00CACACA, 0x00292929,
  0x00292929, 0x00CACACA, 0x00FFFFFF, 0x0096433D, 0x0096433D, 0x00A35B55, 0x00F8F3F3, 0x00FFFFFF, 0x00F8F3F3, 0x00A35B55, 0x0096433D, 0x00B77E7A, 0x00FFFFFF, 0x00FFFFFF, 0x00D1ADAA, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 
        0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 
        0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x00C49592, 0x00FFFFFF, 0x00CACACA, 0x00292929,
  0x00292929, 0x00CACACA, 0x00FFFFFF, 0x0096433D, 0x0096433D, 0x0096433D, 0x00B77E7A, 0x00FFFFFF, 0x00FFFFFF, 0x00EBDCDB, 0x0096433D, 0x0096433D, 0x00D8B9B6, 0x00FFFFFF, 0x00FFFFFF, 0x00F2E8E7, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00CACACA, 0x00292929,
  0x00292929, 0x00CACACA, 0x00FFFFFF, 0x0096433D, 0x0096433D, 0x0096433D, 0x00B77E7A, 0x00FFFFFF, 0x00FFFFFF, 0x00EBDCDB, 0x0096433D, 0x0096433D, 0x00D8B9B6, 0x00FFFFFF, 0x00FFFFFF, 0x00F2E8E7, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00CACACA, 0x00292929,
  0x00292929, 0x00CACACA, 0x00FFFFFF, 0x0096433D, 0x0096433D, 0x00A35B55, 0x00F8F3F3, 0x00FFFFFF, 0x00F8F3F3, 0x00A35B55, 0x0096433D, 0x00B77E7A, 0x00FFFFFF, 0x00FFFFFF, 0x00D1ADAA, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 
        0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 
        0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x0096433D, 0x00C49592, 0x00FFFFFF, 0x00CACACA, 0x00292929,
  0x00292929, 0x00CACACA, 0x00FFFFFF, 0x0096433D, 0x0096433D, 0x00EBDCDB, 0x00FFFFFF, 0x00FFFFFF, 0x00B77E7A, 0x0096433D, 0x00A35B55, 0x00F8F3F3, 0x00FFFFFF, 0x00EBDCDB, 0x0096433D, 0x0096433D, 0x00AA6661, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 
        0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 
        0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00B0726E, 0x00D8B9B6, 0x00FFFFFF, 0x00CACACA, 0x00292929,
  0x00292929, 0x00CACACA, 0x00FFFFFF, 0x0096433D, 0x00D1ADAA, 0x00FFFFFF, 0x00FFFFFF, 0x00D1ADAA, 0x0096433D, 0x0096433D, 0x00EBDCDB, 0x00FFFFFF, 0x00F8F3F3, 0x00A35B55, 0x0096433D, 0x00B77E7A, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00CACACA, 0x00292929,
  0x00292929, 0x00CACACA, 0x00FFFFFF, 0x00B77E7A, 0x00FFFFFF, 0x00FFFFFF, 0x00EBDCDB, 0x0096433D, 0x0096433D, 0x00D1ADAA, 0x00FFFFFF, 0x00FFFFFF, 0x00B77E7A, 0x0096433D, 0x00A35B55, 0x00F8F3F3, 0x00FFFFFF, 0x00FFFFFF, 0x00E4E4E4, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00F2F2F2, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00F2F2F2, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00CACACA, 0x00292929,
  0x00292929, 0x00CACACA, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00F8F3F3, 0x00A35B55, 0x0096433D, 0x00B77E7A, 0x00FFFFFF, 0x00FFFFFF, 0x00CBA19E, 0x0096433D, 0x009D4F49, 0x00EBDCDB, 0x00FFFFFF, 0x00A1A1A1, 0x00292929, 0x00292929, 0x00292929, 0x005F5F5F, 
        0x00F2F2F2, 0x00BCBCBC, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00363636, 0x00FFFFFF, 0x00AFAFAF, 0x00363636, 0x00292929, 0x00292929, 0x00444444, 0x00BCBCBC, 0x00FFFFFF, 0x00F2F2F2, 0x005F5F5F, 0x00292929, 0x00292929, 0x00292929, 
        0x00797979, 0x00FFFFFF, 0x00D7D7D7, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00363636, 0x00FFFFFF, 0x00363636, 0x00292929, 0x00292929, 0x00292929, 0x00444444, 0x00CACACA, 0x00FFFFFF, 0x00FFFFFF, 0x00CACACA, 0x00292929,
  0x00292929, 0x00CACACA, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00B77E7A, 0x0096433D, 0x00A35B55, 0x00F8F3F3, 0x00FFFFFF, 0x00E5D0CF, 0x0096433D, 0x0096433D, 0x00D8B9B6, 0x00FFFFFF, 0x00FFFFFF, 0x00292929, 0x00515151, 0x00E4E4E4, 0x00A1A1A1, 0x00292929, 
        0x00BCBCBC, 0x00949494, 0x00292929, 0x00A1A1A1, 0x00CACACA, 0x00CACACA, 0x00D7D7D7, 0x00E4E4E4, 0x00292929, 0x00515151, 0x00BCBCBC, 0x00BCBCBC, 0x00363636, 0x005F5F5F, 0x00FFFFFF, 0x006C6C6C, 0x00292929, 0x00A1A1A1, 0x00CACACA, 0x00797979, 
        0x00292929, 0x00CACACA, 0x00CACACA, 0x00292929, 0x00A1A1A1, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00FFFFFF, 0x00292929, 0x00797979, 0x00CACACA, 0x00BCBCBC, 0x00292929, 0x005F5F5F, 0x00FFFFFF, 0x00FFFFFF, 0x00CACACA, 0x00292929,
  0x00292929, 0x00CACACA, 0x00FFFFFF, 0x00FFFFFF, 0x00D1ADAA, 0x0096433D, 0x0096433D, 0x00EBDCDB, 0x00FFFFFF, 0x00F8F3F3, 0x009D4F49, 0x0096433D, 0x00BD8A86, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00444444, 0x00292929, 0x00515151, 0x00797979, 0x00AFAFAF, 
        0x00FFFFFF, 0x00949494, 0x00292929, 0x00515151, 0x005F5F5F, 0x005F5F5F, 0x00BCBCBC, 0x00A1A1A1, 0x00292929, 0x00AFAFAF, 0x00FFFFFF, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00FFFFFF, 0x00292929, 0x00515151, 0x00FFFFFF, 0x00E4E4E4, 0x00CACACA, 
        0x00CACACA, 0x00E4E4E4, 0x00CACACA, 0x00292929, 0x00515151, 0x005F5F5F, 0x005F5F5F, 0x00949494, 0x00FFFFFF, 0x00292929, 0x005F5F5F, 0x00949494, 0x00878787, 0x00292929, 0x00797979, 0x00FFFFFF, 0x00FFFFFF, 0x00CACACA, 0x00292929,
  0x00292929, 0x00CACACA, 0x00FFFFFF, 0x00EBDCDB, 0x0096433D, 0x0096433D, 0x00D1ADAA, 0x00FFFFFF, 0x00FFFFFF, 0x00AA6661, 0x0096433D, 0x00AA6661, 0x00F8F3F3, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00F2F2F2, 0x00A1A1A1, 0x006C6C6C, 0x00363636, 0x00292929, 
        0x00878787, 0x00949494, 0x00292929, 0x00797979, 0x00949494, 0x00949494, 0x00CACACA, 0x00949494, 0x00292929, 0x00BCBCBC, 0x00FFFFFF, 0x00363636, 0x00292929, 0x00292929, 0x00CACACA, 0x00292929, 0x005F5F5F, 0x00FFFFFF, 0x00A1A1A1, 0x00292929, 
        0x00292929, 0x00949494, 0x00CACACA, 0x00292929, 0x00797979, 0x00949494, 0x00949494, 0x00BCBCBC, 0x00FFFFFF, 0x00292929, 0x00444444, 0x005F5F5F, 0x00363636, 0x00292929, 0x00AFAFAF, 0x00FFFFFF, 0x00FFFFFF, 0x00CACACA, 0x00292929,
  0x00292929, 0x00CACACA, 0x00FFFFFF, 0x00A35B55, 0x0096433D, 0x00B77E7A, 0x00FFFFFF, 0x00FFFFFF, 0x00CBA19E, 0x0096433D, 0x009D4F49, 0x00F2E8E7, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00363636, 0x00797979, 0x00F2F2F2, 0x00E4E4E4, 0x00292929, 
        0x005F5F5F, 0x00949494, 0x00292929, 0x00A1A1A1, 0x00CACACA, 0x00CACACA, 0x00D7D7D7, 0x00D7D7D7, 0x00292929, 0x00515151, 0x00E4E4E4, 0x00E4E4E4, 0x00515151, 0x00292929, 0x00CACACA, 0x005F5F5F, 0x00292929, 0x00A1A1A1, 0x00FFFFFF, 0x00A1A1A1, 
        0x00292929, 0x00949494, 0x00CACACA, 0x00292929, 0x00A1A1A1, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00FFFFFF, 0x00292929, 0x00949494, 0x00FFFFFF, 0x00D7D7D7, 0x00292929, 0x00878787, 0x00FFFFFF, 0x00FFFFFF, 0x00CACACA, 0x00292929,
  0x00292929, 0x00CACACA, 0x00FFFFFF, 0x00AA6661, 0x00AA6661, 0x00F8F3F3, 0x00FFFFFF, 0x00FFFFFF, 0x00CBA19E, 0x0096433D, 0x00DEC4C2, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00878787, 0x00292929, 0x00292929, 0x00292929, 0x00363636, 
        0x00BCBCBC, 0x00AFAFAF, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00FFFFFF, 0x00AFAFAF, 0x00292929, 0x00292929, 0x00292929, 0x00444444, 0x00292929, 0x00CACACA, 0x00D7D7D7, 0x00444444, 0x00292929, 0x00292929, 0x00292929, 
        0x00363636, 0x00949494, 0x00CACACA, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00CACACA, 0x00292929, 0x00949494, 0x00FFFFFF, 0x00FFFFFF, 0x00292929, 0x005F5F5F, 0x00FFFFFF, 0x00FFFFFF, 0x00CACACA, 0x00292929,
  0x00292929, 0x00CACACA, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00E4E4E4, 0x00CACACA, 0x00CACACA, 0x00F2F2F2, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00F2F2F2, 0x00CACACA, 0x00CACACA, 0x00FFFFFF, 0x00CACACA, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00CACACA, 0x00CACACA, 0x00E4E4E4, 
        0x00E4E4E4, 0x00E4E4E4, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00D7D7D7, 0x00F2F2F2, 0x00FFFFFF, 0x00FFFFFF, 0x00D7D7D7, 0x00E4E4E4, 0x00FFFFFF, 0x00FFFFFF, 0x00CACACA, 0x00292929,
  0x00292929, 0x00AFAFAF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 
        0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00FFFFFF, 0x00AFAFAF, 0x00292929,
  0x10292929, 0x00515151, 0x00AFAFAF, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 
        0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 
        0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00CACACA, 0x00AFAFAF, 0x00515151, 0x10292929,
  0x9F292929, 0x10292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 
        0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 
        0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x00292929, 0x10292929, 0x9F292929
};

GUI_CONST_STORAGE GUI_BITMAP bmSeggerLogo_60x30 = {
  60, /* XSize */
  30, /* YSize */
  240, /* BytesPerLine */
  32, /* BitsPerPixel */
  (unsigned char *)acSeggerLogo_60x30,  /* Pointer to picture data */
  NULL  /* Pointer to palette */
 ,GUI_DRAW_BMP8888
};

/* *** End of file *** */
