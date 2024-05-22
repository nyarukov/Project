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
* Source file: Icon_emModbus_64x64                                   *
* Dimensions:  64 * 64                                               *
* NumColors:   256                                                   *
---------------------------END-OF-HEADER------------------------------
*/

#include <stdlib.h>

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

extern GUI_CONST_STORAGE GUI_BITMAP bmIcon_emModbus_64x64;

/*********************************************************************
*
*       Palette
*
*  Description
*    The following are the entries of the palette table.
*    The entries are stored as a 32-bit values of which 24 bits are
*    actually used according to the following bit mask: 0xBBGGRR
*
*    The lower   8 bits represent the Red   component.
*    The middle  8 bits represent the Green component.
*    The highest 8 bits represent the Blue  component.
*/
static GUI_CONST_STORAGE GUI_COLOR _ColorsIcon_emModbus_64x64[] = {
#if (GUI_USE_ARGB == 0)
  0x00FFFFFF, 0x00FFFFFF, 0x001D1817, 0x00A95C00,
  0x00FAFAFA, 0x001B1D1D, 0x00E5CDB1, 0x00C2C3C3,
  0x00F2E6D8, 0x00F6EEE5, 0x00C08744, 0x00E9D5BE,
  0x00393B3B, 0x00EEDECC, 0x00F9F4EE, 0x00201B1A,
  0x00AA5D02, 0x00C69255, 0x00F4F4F4, 0x00FFFEFE,
  0x00AF6711, 0x00CEA26E, 0x00D1A877, 0x00F2E7D9,
  0x00F8F1E9, 0x00FDFBF9, 0x001D1414, 0x00272322,
  0x002F3030, 0x00464848, 0x00AA5E03, 0x00AA5F04,
  0x00AB6006, 0x00AC6209, 0x00C38D4C, 0x00C8975D,
  0x00959696, 0x00DFC3A1, 0x00F5EBE0, 0x00F3F2F2,
  0x00FBF7F2, 0x00FBF8F4, 0x00FDFCFA, 0x00FEFDFC,
  0x00FEFEFD, 0x00FEFEFE, 0x001E1918, 0x001D1F1F,
  0x00222424, 0x00282A2A, 0x002A2B2B, 0x002A2C2C,
  0x00323434, 0x00494A4A, 0x0072634E, 0x007C7E7E,
  0x00A95D01, 0x00AB6007, 0x00AD640C, 0x00AD640D,
  0x00AE650E, 0x00AE6610, 0x00B26D1B, 0x00B47222,
  0x00B67426, 0x00B97B30, 0x00BF8642, 0x00C59153,
  0x00CB9D66, 0x00D2AA7A, 0x00D4AD7F, 0x00888989,
  0x009FA0A0, 0x00A6A6A6, 0x00AAABAB, 0x00D6B185,
  0x00D9B78F, 0x00DDBE99, 0x00C7C7C7, 0x00EAD7C1,
  0x00EDDCC9, 0x00EFE0CF, 0x00F3E7DA, 0x00E1E2E2,
  0x00EAEBEB, 0x00EBEBEB, 0x00EEEEEE, 0x00F5ECE1,
  0x00F7EFE6, 0x00F8F2EB, 0x00F9F3EC, 0x00F2F2F2,
  0x00F3F3F3, 0x00FBF7F3, 0x00FCFAF7, 0x00FBFBFB,
  0x00FDFBF8, 0x00FCFCFC, 0x001C1E1E, 0x00211B1A,
  0x001F2121, 0x00252120, 0x00282929, 0x002C2E2E,
  0x00312C2B, 0x00352C2C, 0x00342F2E, 0x0038342C,
  0x00373332, 0x00393433, 0x00363838, 0x003F3E3B,
  0x003C3E3E, 0x00404140, 0x00414242, 0x004B4D4D,
  0x004C4E4E, 0x0050504F, 0x0059534B, 0x00525454,
  0x00575858, 0x00595A5A, 0x00665C4F, 0x0060605F,
  0x00626363, 0x00636464, 0x00676868, 0x00696A6A,
  0x006D6F6F, 0x00747575, 0x007F7C7C, 0x00AB5F05,
  0x00A85F07, 0x00AC6108, 0x00AC620A, 0x00AD630B,
  0x00AC630C, 0x00AE660F, 0x00AF6812, 0x00B06915,
  0x00B06A16, 0x00B16B17, 0x00B16C19, 0x00B26E1C,
  0x00B36F1D, 0x00B36F1E, 0x009C692D, 0x00976B35,
  0x00B47020, 0x00B47121, 0x00B57324, 0x00B67527,
  0x00B77629, 0x00B7772B, 0x00B9792E, 0x00BA7B31,
  0x00BA7C32, 0x00BA7D33, 0x00BC7F37, 0x009D7B51,
  0x00877763, 0x00BC8038, 0x00BD813A, 0x00BD823B,
  0x00BE843F, 0x00BF8641, 0x0083807E, 0x00C08743,
  0x00C18947, 0x00C28B49, 0x00C28B4A, 0x00C38E4E,
  0x00C48F50, 0x00CB9C64, 0x00CB9D65, 0x00CC9F69,
  0x00CEA26D, 0x00CEA36F, 0x00D1A776, 0x00D3AB7C,
  0x00D3AC7D, 0x00858281, 0x00868483, 0x008C8882,
  0x008F8D8A, 0x00939494, 0x009E9E9E, 0x00B4A28B,
  0x00B7AC9D, 0x00A0A1A1, 0x00A4A5A5, 0x00A9AAAA,
  0x00B1B2B2, 0x00B6B6B6, 0x00D7B388, 0x00D7B489,
  0x00D8B58B, 0x00D9B68D, 0x00DAB890, 0x00DBBB95,
  0x00DEC09D, 0x00E0C4A3, 0x00E0C5A4, 0x00E1C5A5,
  0x00E1C6A6, 0x00E2C8A9, 0x00E2C9AA, 0x00E4CCAF,
  0x00E5CEB2, 0x00E6CFB4, 0x00E6D0B6, 0x00E7D2B8,
  0x00E8D4BB, 0x00E8D4BC, 0x00E9D5BD, 0x00C0C0C0,
  0x00C0C1C1, 0x00C8C8C8, 0x00CACBCB, 0x00CBCCCC,
  0x00CDCDCD, 0x00CECECE, 0x00D2D3D3, 0x00D3D4D4,
  0x00D4D4D4, 0x00D6D6D6, 0x00D9D9D9, 0x00D9DADA,
  0x00DFDFDF, 0x00EBD9C3, 0x00ECDBC7, 0x00ECDCC8,
  0x00EDDECB, 0x00EFE1D0, 0x00EFE2D1, 0x00E5E2DD,
  0x00F0E2D2, 0x00F0E3D3, 0x00F0E4D4, 0x00F2E5D7,
  0x00F4E9DD, 0x00F4EBDF, 0x00E2E3E3, 0x00E6E6E6,
  0x00E7E7E7, 0x00ECE7E1, 0x00EFEFEF, 0x00F5ECE2,
  0x00FAF5EF, 0x00F2F1F1, 0x00F6F6F6, 0x00FAF5F0,
  0x00FCF9F5, 0x00FCF9F6, 0x00F9F9F9, 0x00FEFCFB
#else
  0xFFFFFFFF, 0xFFFFFFFF, 0xFF17181D, 0xFF005CA9,
  0xFFFAFAFA, 0xFF1D1D1B, 0xFFB1CDE5, 0xFFC3C3C2,
  0xFFD8E6F2, 0xFFE5EEF6, 0xFF4487C0, 0xFFBED5E9,
  0xFF3B3B39, 0xFFCCDEEE, 0xFFEEF4F9, 0xFF1A1B20,
  0xFF025DAA, 0xFF5592C6, 0xFFF4F4F4, 0xFFFEFEFF,
  0xFF1167AF, 0xFF6EA2CE, 0xFF77A8D1, 0xFFD9E7F2,
  0xFFE9F1F8, 0xFFF9FBFD, 0xFF14141D, 0xFF222327,
  0xFF30302F, 0xFF484846, 0xFF035EAA, 0xFF045FAA,
  0xFF0660AB, 0xFF0962AC, 0xFF4C8DC3, 0xFF5D97C8,
  0xFF969695, 0xFFA1C3DF, 0xFFE0EBF5, 0xFFF2F2F3,
  0xFFF2F7FB, 0xFFF4F8FB, 0xFFFAFCFD, 0xFFFCFDFE,
  0xFFFDFEFE, 0xFFFEFEFE, 0xFF18191E, 0xFF1F1F1D,
  0xFF242422, 0xFF2A2A28, 0xFF2B2B2A, 0xFF2C2C2A,
  0xFF343432, 0xFF4A4A49, 0xFF4E6372, 0xFF7E7E7C,
  0xFF015DA9, 0xFF0760AB, 0xFF0C64AD, 0xFF0D64AD,
  0xFF0E65AE, 0xFF1066AE, 0xFF1B6DB2, 0xFF2272B4,
  0xFF2674B6, 0xFF307BB9, 0xFF4286BF, 0xFF5391C5,
  0xFF669DCB, 0xFF7AAAD2, 0xFF7FADD4, 0xFF898988,
  0xFFA0A09F, 0xFFA6A6A6, 0xFFABABAA, 0xFF85B1D6,
  0xFF8FB7D9, 0xFF99BEDD, 0xFFC7C7C7, 0xFFC1D7EA,
  0xFFC9DCED, 0xFFCFE0EF, 0xFFDAE7F3, 0xFFE2E2E1,
  0xFFEBEBEA, 0xFFEBEBEB, 0xFFEEEEEE, 0xFFE1ECF5,
  0xFFE6EFF7, 0xFFEBF2F8, 0xFFECF3F9, 0xFFF2F2F2,
  0xFFF3F3F3, 0xFFF3F7FB, 0xFFF7FAFC, 0xFFFBFBFB,
  0xFFF8FBFD, 0xFFFCFCFC, 0xFF1E1E1C, 0xFF1A1B21,
  0xFF21211F, 0xFF202125, 0xFF292928, 0xFF2E2E2C,
  0xFF2B2C31, 0xFF2C2C35, 0xFF2E2F34, 0xFF2C3438,
  0xFF323337, 0xFF333439, 0xFF383836, 0xFF3B3E3F,
  0xFF3E3E3C, 0xFF404140, 0xFF424241, 0xFF4D4D4B,
  0xFF4E4E4C, 0xFF4F5050, 0xFF4B5359, 0xFF545452,
  0xFF585857, 0xFF5A5A59, 0xFF4F5C66, 0xFF5F6060,
  0xFF636362, 0xFF646463, 0xFF686867, 0xFF6A6A69,
  0xFF6F6F6D, 0xFF757574, 0xFF7C7C7F, 0xFF055FAB,
  0xFF075FA8, 0xFF0861AC, 0xFF0A62AC, 0xFF0B63AD,
  0xFF0C63AC, 0xFF0F66AE, 0xFF1268AF, 0xFF1569B0,
  0xFF166AB0, 0xFF176BB1, 0xFF196CB1, 0xFF1C6EB2,
  0xFF1D6FB3, 0xFF1E6FB3, 0xFF2D699C, 0xFF356B97,
  0xFF2070B4, 0xFF2171B4, 0xFF2473B5, 0xFF2775B6,
  0xFF2976B7, 0xFF2B77B7, 0xFF2E79B9, 0xFF317BBA,
  0xFF327CBA, 0xFF337DBA, 0xFF377FBC, 0xFF517B9D,
  0xFF637787, 0xFF3880BC, 0xFF3A81BD, 0xFF3B82BD,
  0xFF3F84BE, 0xFF4186BF, 0xFF7E8083, 0xFF4387C0,
  0xFF4789C1, 0xFF498BC2, 0xFF4A8BC2, 0xFF4E8EC3,
  0xFF508FC4, 0xFF649CCB, 0xFF659DCB, 0xFF699FCC,
  0xFF6DA2CE, 0xFF6FA3CE, 0xFF76A7D1, 0xFF7CABD3,
  0xFF7DACD3, 0xFF818285, 0xFF838486, 0xFF82888C,
  0xFF8A8D8F, 0xFF949493, 0xFF9E9E9E, 0xFF8BA2B4,
  0xFF9DACB7, 0xFFA1A1A0, 0xFFA5A5A4, 0xFFAAAAA9,
  0xFFB2B2B1, 0xFFB6B6B6, 0xFF88B3D7, 0xFF89B4D7,
  0xFF8BB5D8, 0xFF8DB6D9, 0xFF90B8DA, 0xFF95BBDB,
  0xFF9DC0DE, 0xFFA3C4E0, 0xFFA4C5E0, 0xFFA5C5E1,
  0xFFA6C6E1, 0xFFA9C8E2, 0xFFAAC9E2, 0xFFAFCCE4,
  0xFFB2CEE5, 0xFFB4CFE6, 0xFFB6D0E6, 0xFFB8D2E7,
  0xFFBBD4E8, 0xFFBCD4E8, 0xFFBDD5E9, 0xFFC0C0C0,
  0xFFC1C1C0, 0xFFC8C8C8, 0xFFCBCBCA, 0xFFCCCCCB,
  0xFFCDCDCD, 0xFFCECECE, 0xFFD3D3D2, 0xFFD4D4D3,
  0xFFD4D4D4, 0xFFD6D6D6, 0xFFD9D9D9, 0xFFDADAD9,
  0xFFDFDFDF, 0xFFC3D9EB, 0xFFC7DBEC, 0xFFC8DCEC,
  0xFFCBDEED, 0xFFD0E1EF, 0xFFD1E2EF, 0xFFDDE2E5,
  0xFFD2E2F0, 0xFFD3E3F0, 0xFFD4E4F0, 0xFFD7E5F2,
  0xFFDDE9F4, 0xFFDFEBF4, 0xFFE3E3E2, 0xFFE6E6E6,
  0xFFE7E7E7, 0xFFE1E7EC, 0xFFEFEFEF, 0xFFE2ECF5,
  0xFFEFF5FA, 0xFFF1F1F2, 0xFFF6F6F6, 0xFFF0F5FA,
  0xFFF5F9FC, 0xFFF6F9FC, 0xFFF9F9F9, 0xFFFBFCFE
#endif

};

static GUI_CONST_STORAGE GUI_LOGPALETTE _PalIcon_emModbus_64x64 = {
  256,  // Number of entries
  1,    // Has transparency
  &_ColorsIcon_emModbus_64x64[0]
};

static GUI_CONST_STORAGE unsigned char _acIcon_emModbus_64x64[] = {
  /* ABS: 003 Pixels @ 000,000 */ 0, 3, 0x69, 0x6D, 0x0F, 
  /* RLE: 058 Pixels @ 003,000 */ 58, 0x02, 
  /* ABS: 006 Pixels @ 061,000 */ 0, 6, 0x0F, 0x6C, 0x1A, 0x6A, 0xB6, 0x12, 
  /* RLE: 058 Pixels @ 003,001 */ 58, 0x01, 
  /* ABS: 005 Pixels @ 061,001 */ 0, 5, 0x12, 0xB5, 0x1B, 0x0F, 0x27, 
  /* RLE: 060 Pixels @ 002,002 */ 60, 0x01, 
  /* ABS: 004 Pixels @ 062,002 */ 0, 4, 0x27, 0x2E, 0x02, 0x04, 
  /* RLE: 060 Pixels @ 002,003 */ 60, 0x01, 
  /* ABS: 004 Pixels @ 062,003 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 029 Pixels @ 002,004 */ 29, 0x01, 
  /* ABS: 002 Pixels @ 031,004 */ 0, 2, 0xDD, 0xE4, 
  /* RLE: 029 Pixels @ 033,004 */ 29, 0x01, 
  /* ABS: 004 Pixels @ 062,004 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 028 Pixels @ 002,005 */ 28, 0x01, 
  /* ABS: 003 Pixels @ 030,005 */ 0, 3, 0x2D, 0x73, 0x7C, 
  /* RLE: 029 Pixels @ 033,005 */ 29, 0x01, 
  /* ABS: 004 Pixels @ 062,005 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 028 Pixels @ 002,006 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 030,006 */ 0, 4, 0x4A, 0x05, 0x05, 0xD7, 
  /* RLE: 028 Pixels @ 034,006 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 062,006 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 027 Pixels @ 002,007 */ 27, 0x01, 
  /* ABS: 006 Pixels @ 029,007 */ 0, 6, 0x12, 0x34, 0x05, 0x05, 0x72, 0x5F, 
  /* RLE: 027 Pixels @ 035,007 */ 27, 0x01, 
  /* ABS: 004 Pixels @ 062,007 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 027 Pixels @ 002,008 */ 27, 0x01, 
  /* RLE: 001 Pixels @ 029,008 */ 1, 0x47, 
  /* RLE: 004 Pixels @ 030,008 */ 4, 0x05, 
  /* RLE: 001 Pixels @ 034,008 */ 1, 0x48, 
  /* RLE: 027 Pixels @ 035,008 */ 27, 0x01, 
  /* ABS: 004 Pixels @ 062,008 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 026 Pixels @ 002,009 */ 26, 0x01, 
  /* ABS: 002 Pixels @ 028,009 */ 0, 2, 0x53, 0x30, 
  /* RLE: 004 Pixels @ 030,009 */ 4, 0x05, 
  /* ABS: 002 Pixels @ 034,009 */ 0, 2, 0x33, 0x56, 
  /* RLE: 026 Pixels @ 036,009 */ 26, 0x01, 
  /* ABS: 004 Pixels @ 062,009 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 026 Pixels @ 002,010 */ 26, 0x01, 
  /* ABS: 008 Pixels @ 028,010 */ 0, 8, 0xD9, 0x24, 0xB7, 0x36, 0x36, 0xB8, 0x24, 0xDE, 
  /* RLE: 026 Pixels @ 036,010 */ 26, 0x01, 
  /* ABS: 004 Pixels @ 062,010 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 028 Pixels @ 002,011 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 030,011 */ 0, 4, 0x0B, 0x03, 0x03, 0x08, 
  /* RLE: 028 Pixels @ 034,011 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 062,011 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 028 Pixels @ 002,012 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 030,012 */ 0, 4, 0x0B, 0x03, 0x03, 0x08, 
  /* RLE: 028 Pixels @ 034,012 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 062,012 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 028 Pixels @ 002,013 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 030,013 */ 0, 4, 0x0B, 0x03, 0x03, 0x08, 
  /* RLE: 028 Pixels @ 034,013 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 062,013 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 028 Pixels @ 002,014 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 030,014 */ 0, 4, 0x0B, 0x03, 0x03, 0x08, 
  /* RLE: 028 Pixels @ 034,014 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 062,014 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 028 Pixels @ 002,015 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 030,015 */ 0, 4, 0x0B, 0x03, 0x03, 0x08, 
  /* RLE: 028 Pixels @ 034,015 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 062,015 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 028 Pixels @ 002,016 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 030,016 */ 0, 4, 0x0B, 0x03, 0x03, 0x08, 
  /* RLE: 028 Pixels @ 034,016 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 062,016 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 006 Pixels @ 002,017 */ 6, 0x01, 
  /* RLE: 001 Pixels @ 008,017 */ 1, 0xF3, 
  /* RLE: 006 Pixels @ 009,017 */ 6, 0x07, 
  /* RLE: 001 Pixels @ 015,017 */ 1, 0xE2, 
  /* RLE: 014 Pixels @ 016,017 */ 14, 0x01, 
  /* ABS: 004 Pixels @ 030,017 */ 0, 4, 0x0B, 0x03, 0x03, 0x08, 
  /* RLE: 014 Pixels @ 034,017 */ 14, 0x01, 
  /* RLE: 001 Pixels @ 048,017 */ 1, 0xE0, 
  /* RLE: 006 Pixels @ 049,017 */ 6, 0x07, 
  /* RLE: 001 Pixels @ 055,017 */ 1, 0x54, 
  /* RLE: 006 Pixels @ 056,017 */ 6, 0x01, 
  /* ABS: 004 Pixels @ 062,017 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 006 Pixels @ 002,018 */ 6, 0x01, 
  /* ABS: 002 Pixels @ 008,018 */ 0, 2, 0x54, 0x66, 
  /* RLE: 005 Pixels @ 010,018 */ 5, 0x05, 
  /* RLE: 001 Pixels @ 015,018 */ 1, 0xD8, 
  /* RLE: 014 Pixels @ 016,018 */ 14, 0x01, 
  /* ABS: 004 Pixels @ 030,018 */ 0, 4, 0x0B, 0x03, 0x03, 0x08, 
  /* RLE: 014 Pixels @ 034,018 */ 14, 0x01, 
  /* RLE: 001 Pixels @ 048,018 */ 1, 0xC0, 
  /* RLE: 005 Pixels @ 049,018 */ 5, 0x05, 
  /* ABS: 002 Pixels @ 054,018 */ 0, 2, 0x1C, 0x5B, 
  /* RLE: 006 Pixels @ 056,018 */ 6, 0x01, 
  /* ABS: 004 Pixels @ 062,018 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 007 Pixels @ 002,019 */ 7, 0x01, 
  /* RLE: 001 Pixels @ 009,019 */ 1, 0xB9, 
  /* RLE: 004 Pixels @ 010,019 */ 4, 0x05, 
  /* RLE: 001 Pixels @ 014,019 */ 1, 0x7B, 
  /* RLE: 015 Pixels @ 015,019 */ 15, 0x01, 
  /* ABS: 004 Pixels @ 030,019 */ 0, 4, 0x0B, 0x03, 0x03, 0x08, 
  /* RLE: 014 Pixels @ 034,019 */ 14, 0x01, 
  /* ABS: 002 Pixels @ 048,019 */ 0, 2, 0x2D, 0x75, 
  /* RLE: 004 Pixels @ 050,019 */ 4, 0x05, 
  /* RLE: 001 Pixels @ 054,019 */ 1, 0xBE, 
  /* RLE: 007 Pixels @ 055,019 */ 7, 0x01, 
  /* ABS: 004 Pixels @ 062,019 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 007 Pixels @ 002,020 */ 7, 0x01, 
  /* ABS: 008 Pixels @ 009,020 */ 0, 8, 0x04, 0x70, 0x05, 0x05, 0x2F, 0x92, 0x11, 0x57, 
  /* RLE: 013 Pixels @ 017,020 */ 13, 0x01, 
  /* ABS: 004 Pixels @ 030,020 */ 0, 4, 0x0B, 0x03, 0x03, 0x08, 
  /* RLE: 013 Pixels @ 034,020 */ 13, 0x01, 
  /* ABS: 008 Pixels @ 047,020 */ 0, 8, 0xF7, 0x23, 0x93, 0x05, 0x05, 0x05, 0x1D, 0x61, 
  /* RLE: 007 Pixels @ 055,020 */ 7, 0x01, 
  /* ABS: 004 Pixels @ 062,020 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 008 Pixels @ 002,021 */ 8, 0x01, 
  /* ABS: 009 Pixels @ 010,021 */ 0, 9, 0xC1, 0x05, 0x05, 0x7A, 0x03, 0x03, 0x3A, 0x4B, 0x5E, 
  /* RLE: 011 Pixels @ 019,021 */ 11, 0x01, 
  /* ABS: 004 Pixels @ 030,021 */ 0, 4, 0x0B, 0x03, 0x03, 0x08, 
  /* RLE: 011 Pixels @ 034,021 */ 11, 0x01, 
  /* ABS: 009 Pixels @ 045,021 */ 0, 9, 0x5D, 0x45, 0x85, 0x03, 0x03, 0x76, 0x05, 0x05, 0x4E, 
  /* RLE: 008 Pixels @ 054,021 */ 8, 0x01, 
  /* ABS: 004 Pixels @ 062,021 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 009 Pixels @ 002,022 */ 9, 0x01, 
  /* ABS: 009 Pixels @ 011,022 */ 0, 9, 0x79, 0x1C, 0xF5, 0x15, 0x1F, 0x03, 0x03, 0x90, 0x25, 
  /* RLE: 008 Pixels @ 020,022 */ 8, 0x01, 
  /* ABS: 008 Pixels @ 028,022 */ 0, 8, 0xCA, 0x14, 0x3B, 0x03, 0x03, 0x3C, 0x14, 0xD5, 
  /* RLE: 007 Pixels @ 036,022 */ 7, 0x01, 
  /* ABS: 010 Pixels @ 043,022 */ 0, 10, 0x13, 0xCE, 0x91, 0x03, 0x03, 0x83, 0x15, 0xEB, 0x31, 0x7E, 
  /* RLE: 009 Pixels @ 053,022 */ 9, 0x01, 
  /* ABS: 004 Pixels @ 062,022 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 009 Pixels @ 002,023 */ 9, 0x01, 
  /* ABS: 019 Pixels @ 011,023 */ 0, 19, 0xE1, 0xBF, 0x01, 0x01, 0xEA, 0xA5, 0x03, 0x03, 0x03, 0x42, 0xEC, 0x01, 0x01, 0x01, 0x17, 0x01, 0x01, 0x2C, 0x9D, 
  /* RLE: 004 Pixels @ 030,023 */ 4, 0x03, 
  /* ABS: 019 Pixels @ 034,023 */ 0, 19, 0xA7, 0x01, 0x01, 0x13, 0x52, 0x01, 0x01, 0x01, 0x50, 0xA1, 0x03, 0x03, 0x03, 0x22, 0x17, 0x01, 0x01, 0xBA, 0xF2, 
  /* RLE: 009 Pixels @ 053,023 */ 9, 0x01, 
  /* ABS: 004 Pixels @ 062,023 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 015 Pixels @ 002,024 */ 15, 0x01, 
  /* ABS: 030 Pixels @ 017,024 */ 0, 30, 0xD0, 0x3F, 0x03, 0x03, 0x10, 0x23, 0x18, 0x19, 0x40, 0xD2, 0x01, 0x01, 0xE5, 0x38, 0x03, 0x03, 0x1F, 0xED, 0x01, 0x01, 0xC9, 0x9B, 0x2C, 0x58, 0x44, 0x10, 0x03, 0x03, 0x40, 0xD1, 
  /* RLE: 015 Pixels @ 047,024 */ 15, 0x01, 
  /* ABS: 004 Pixels @ 062,024 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 016 Pixels @ 002,025 */ 16, 0x01, 
  /* ABS: 028 Pixels @ 018,025 */ 0, 28, 0x5E, 0x4B, 0x87, 0x03, 0x03, 0x14, 0xAB, 0x03, 0x98, 0x2A, 0x01, 0x01, 0x43, 0x03, 0x03, 0x15, 0x01, 0x01, 0x29, 0x8F, 0x03, 0x43, 0x3A, 0x03, 0x03, 0x3D, 0x4C, 0x2A, 
  /* RLE: 016 Pixels @ 046,025 */ 16, 0x01, 
  /* ABS: 004 Pixels @ 062,025 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 018 Pixels @ 002,026 */ 18, 0x01, 
  /* ABS: 003 Pixels @ 020,026 */ 0, 3, 0x09, 0x44, 0x10, 
  /* RLE: 004 Pixels @ 023,026 */ 4, 0x03, 
  /* ABS: 010 Pixels @ 027,026 */ 0, 10, 0x4C, 0x01, 0x01, 0x57, 0x86, 0x8A, 0x5A, 0x01, 0x01, 0xB3, 
  /* RLE: 004 Pixels @ 037,026 */ 4, 0x03, 
  /* ABS: 003 Pixels @ 041,026 */ 0, 3, 0x10, 0x23, 0x18, 
  /* RLE: 018 Pixels @ 044,026 */ 18, 0x01, 
  /* ABS: 004 Pixels @ 062,026 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 020 Pixels @ 002,027 */ 20, 0x01, 
  /* ABS: 020 Pixels @ 022,027 */ 0, 20, 0xE6, 0x8D, 0x03, 0x03, 0x03, 0x14, 0x59, 0x01, 0x01, 0x45, 0xC7, 0x01, 0x01, 0x26, 0x21, 0x03, 0x03, 0x03, 0x95, 0xE9, 
  /* RLE: 020 Pixels @ 042,027 */ 20, 0x01, 
  /* ABS: 004 Pixels @ 062,027 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 020 Pixels @ 002,028 */ 20, 0x01, 
  /* ABS: 002 Pixels @ 022,028 */ 0, 2, 0x51, 0x1E, 
  /* RLE: 004 Pixels @ 024,028 */ 4, 0x03, 
  /* ABS: 008 Pixels @ 028,028 */ 0, 8, 0xAF, 0x01, 0x01, 0x29, 0xFF, 0x01, 0x01, 0x11, 
  /* RLE: 004 Pixels @ 036,028 */ 4, 0x03, 
  /* ABS: 002 Pixels @ 040,028 */ 0, 2, 0x20, 0x52, 
  /* RLE: 020 Pixels @ 042,028 */ 20, 0x01, 
  /* ABS: 004 Pixels @ 062,028 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 020 Pixels @ 002,029 */ 20, 0x01, 
  /* RLE: 001 Pixels @ 022,029 */ 1, 0x46, 
  /* RLE: 005 Pixels @ 023,029 */ 5, 0x0A, 
  /* ABS: 002 Pixels @ 028,029 */ 0, 2, 0xA8, 0x59, 
  /* RLE: 004 Pixels @ 030,029 */ 4, 0x01, 
  /* RLE: 001 Pixels @ 034,029 */ 1, 0x26, 
  /* RLE: 006 Pixels @ 035,029 */ 6, 0x0A, 
  /* RLE: 001 Pixels @ 041,029 */ 1, 0xC5, 
  /* RLE: 020 Pixels @ 042,029 */ 20, 0x01, 
  /* ABS: 004 Pixels @ 062,029 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 060 Pixels @ 002,030 */ 60, 0x01, 
  /* ABS: 004 Pixels @ 062,030 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 060 Pixels @ 002,031 */ 60, 0x01, 
  /* ABS: 004 Pixels @ 062,031 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 020 Pixels @ 002,032 */ 20, 0x01, 
  /* RLE: 001 Pixels @ 022,032 */ 1, 0x28, 
  /* RLE: 006 Pixels @ 023,032 */ 6, 0x0E, 
  /* RLE: 001 Pixels @ 029,032 */ 1, 0x60, 
  /* RLE: 004 Pixels @ 030,032 */ 4, 0x01, 
  /* RLE: 001 Pixels @ 034,032 */ 1, 0x28, 
  /* RLE: 006 Pixels @ 035,032 */ 6, 0x0D, 
  /* RLE: 001 Pixels @ 041,032 */ 1, 0xEE, 
  /* RLE: 020 Pixels @ 042,032 */ 20, 0x01, 
  /* ABS: 004 Pixels @ 062,032 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 020 Pixels @ 002,033 */ 20, 0x01, 
  /* RLE: 001 Pixels @ 022,033 */ 1, 0xC4, 
  /* RLE: 005 Pixels @ 023,033 */ 5, 0x03, 
  /* ABS: 002 Pixels @ 028,033 */ 0, 2, 0x20, 0x17, 
  /* RLE: 004 Pixels @ 030,033 */ 4, 0x01, 
  /* ABS: 002 Pixels @ 034,033 */ 0, 2, 0xFD, 0x94, 
  /* RLE: 005 Pixels @ 036,033 */ 5, 0x03, 
  /* RLE: 001 Pixels @ 041,033 */ 1, 0x46, 
  /* RLE: 020 Pixels @ 042,033 */ 20, 0x01, 
  /* ABS: 004 Pixels @ 062,033 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 020 Pixels @ 002,034 */ 20, 0x01, 
  /* ABS: 002 Pixels @ 022,034 */ 0, 2, 0x19, 0x97, 
  /* RLE: 004 Pixels @ 024,034 */ 4, 0x03, 
  /* ABS: 008 Pixels @ 028,034 */ 0, 8, 0xB2, 0x01, 0x01, 0x28, 0xEF, 0x01, 0x01, 0xCD, 
  /* RLE: 004 Pixels @ 036,034 */ 4, 0x03, 
  /* ABS: 002 Pixels @ 040,034 */ 0, 2, 0x8E, 0xFC, 
  /* RLE: 020 Pixels @ 042,034 */ 20, 0x01, 
  /* ABS: 004 Pixels @ 062,034 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 019 Pixels @ 002,035 */ 19, 0x01, 
  /* ABS: 016 Pixels @ 021,035 */ 0, 16, 0x2A, 0xC6, 0x89, 0x03, 0x03, 0x03, 0x8C, 0xFB, 0x01, 0x01, 0x16, 0x42, 0x01, 0x01, 0x01, 0xA4, 
  /* RLE: 004 Pixels @ 037,035 */ 4, 0x03, 
  /* ABS: 002 Pixels @ 041,035 */ 0, 2, 0x22, 0xF1, 
  /* RLE: 019 Pixels @ 043,035 */ 19, 0x01, 
  /* ABS: 004 Pixels @ 062,035 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 018 Pixels @ 002,036 */ 18, 0x01, 
  /* ABS: 002 Pixels @ 020,036 */ 0, 2, 0xD4, 0x99, 
  /* RLE: 005 Pixels @ 022,036 */ 5, 0x03, 
  /* ABS: 011 Pixels @ 027,036 */ 0, 11, 0xC8, 0x01, 0x01, 0xF0, 0x39, 0x03, 0xCF, 0x01, 0x01, 0x51, 0x1E, 
  /* RLE: 004 Pixels @ 038,036 */ 4, 0x03, 
  /* ABS: 003 Pixels @ 042,036 */ 0, 3, 0x21, 0x16, 0x5D, 
  /* RLE: 017 Pixels @ 045,036 */ 17, 0x01, 
  /* ABS: 004 Pixels @ 062,036 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 016 Pixels @ 002,037 */ 16, 0x01, 
  /* ABS: 029 Pixels @ 018,037 */ 0, 29, 0x08, 0xA9, 0x03, 0x03, 0x03, 0xA2, 0xCB, 0x1F, 0x9C, 0x2C, 0x01, 0x01, 0xAC, 0x03, 0x03, 0x3F, 0x60, 0x01, 0x01, 0xAD, 0x38, 0xD3, 0x16, 0x20, 0x03, 0x03, 0x3E, 0x25, 0x13, 
  /* RLE: 015 Pixels @ 047,037 */ 15, 0x01, 
  /* ABS: 004 Pixels @ 062,037 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 010 Pixels @ 002,038 */ 10, 0x01, 
  /* ABS: 018 Pixels @ 012,038 */ 0, 18, 0x12, 0x01, 0x01, 0x01, 0xF8, 0x16, 0x39, 0x03, 0x03, 0x3E, 0x25, 0x13, 0x01, 0xB0, 0x4F, 0x01, 0x01, 0xD6, 
  /* RLE: 004 Pixels @ 030,038 */ 4, 0x03, 
  /* ABS: 019 Pixels @ 034,038 */ 0, 19, 0xC2, 0x01, 0x01, 0x18, 0xB1, 0x01, 0x01, 0x17, 0xAA, 0x03, 0x03, 0x03, 0x9E, 0xE7, 0x01, 0x01, 0x01, 0x55, 0x5F, 
  /* RLE: 009 Pixels @ 053,038 */ 9, 0x01, 
  /* ABS: 004 Pixels @ 062,038 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 009 Pixels @ 002,039 */ 9, 0x01, 
  /* ABS: 019 Pixels @ 011,039 */ 0, 19, 0xDC, 0x7D, 0x01, 0x2B, 0x4D, 0x8B, 0x03, 0x03, 0x21, 0xB4, 0x29, 0x01, 0x01, 0x01, 0x19, 0x01, 0x01, 0x2B, 0x9A, 
  /* RLE: 004 Pixels @ 030,039 */ 4, 0x03, 
  /* ABS: 005 Pixels @ 034,039 */ 0, 5, 0x3B, 0x58, 0x01, 0x01, 0x13, 
  /* RLE: 004 Pixels @ 039,039 */ 4, 0x01, 
  /* ABS: 010 Pixels @ 043,039 */ 0, 10, 0x06, 0x96, 0x03, 0x03, 0x10, 0xAE, 0x18, 0x01, 0x80, 0x48, 
  /* RLE: 009 Pixels @ 053,039 */ 9, 0x01, 
  /* ABS: 004 Pixels @ 062,039 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 008 Pixels @ 002,040 */ 8, 0x01, 
  /* ABS: 010 Pixels @ 010,040 */ 0, 10, 0x2D, 0x74, 0x05, 0xBC, 0x41, 0x03, 0x03, 0x03, 0x11, 0x26, 
  /* RLE: 008 Pixels @ 020,040 */ 8, 0x01, 
  /* ABS: 008 Pixels @ 028,040 */ 0, 8, 0x50, 0x11, 0x22, 0x03, 0x03, 0xA3, 0x11, 0xCC, 
  /* RLE: 008 Pixels @ 036,040 */ 8, 0x01, 
  /* ABS: 010 Pixels @ 044,040 */ 0, 10, 0x19, 0xC3, 0x3C, 0x03, 0x03, 0x3D, 0xBB, 0x62, 0x67, 0xF6, 
  /* RLE: 008 Pixels @ 054,040 */ 8, 0x01, 
  /* ABS: 004 Pixels @ 062,040 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 008 Pixels @ 002,041 */ 8, 0x01, 
  /* ABS: 008 Pixels @ 010,041 */ 0, 8, 0x4A, 0x05, 0x05, 0x6B, 0x88, 0x03, 0x41, 0x4F, 
  /* RLE: 012 Pixels @ 018,041 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 030,041 */ 0, 4, 0x09, 0x03, 0x03, 0x06, 
  /* RLE: 012 Pixels @ 034,041 */ 12, 0x01, 
  /* ABS: 008 Pixels @ 046,041 */ 0, 8, 0x5A, 0x15, 0x1E, 0x84, 0x6F, 0x05, 0x05, 0x37, 
  /* RLE: 008 Pixels @ 054,041 */ 8, 0x01, 
  /* ABS: 004 Pixels @ 062,041 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 007 Pixels @ 002,042 */ 7, 0x01, 
  /* ABS: 008 Pixels @ 009,042 */ 0, 8, 0x12, 0x34, 0x05, 0x05, 0x05, 0x9F, 0x4D, 0x2B, 
  /* RLE: 013 Pixels @ 017,042 */ 13, 0x01, 
  /* ABS: 004 Pixels @ 030,042 */ 0, 4, 0x09, 0x03, 0x03, 0x06, 
  /* RLE: 014 Pixels @ 034,042 */ 14, 0x01, 
  /* ABS: 007 Pixels @ 048,042 */ 0, 7, 0xE8, 0xA0, 0x05, 0x05, 0x05, 0x64, 0xE3, 
  /* RLE: 007 Pixels @ 055,042 */ 7, 0x01, 
  /* ABS: 004 Pixels @ 062,042 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 007 Pixels @ 002,043 */ 7, 0x01, 
  /* RLE: 001 Pixels @ 009,043 */ 1, 0x47, 
  /* RLE: 004 Pixels @ 010,043 */ 4, 0x05, 
  /* ABS: 002 Pixels @ 014,043 */ 0, 2, 0x33, 0x56, 
  /* RLE: 014 Pixels @ 016,043 */ 14, 0x01, 
  /* ABS: 004 Pixels @ 030,043 */ 0, 4, 0x09, 0x03, 0x03, 0x06, 
  /* RLE: 014 Pixels @ 034,043 */ 14, 0x01, 
  /* ABS: 002 Pixels @ 048,043 */ 0, 2, 0xFA, 0x6E, 
  /* RLE: 004 Pixels @ 050,043 */ 4, 0x05, 
  /* RLE: 001 Pixels @ 054,043 */ 1, 0x78, 
  /* RLE: 007 Pixels @ 055,043 */ 7, 0x01, 
  /* ABS: 004 Pixels @ 062,043 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 006 Pixels @ 002,044 */ 6, 0x01, 
  /* ABS: 002 Pixels @ 008,044 */ 0, 2, 0x53, 0x30, 
  /* RLE: 005 Pixels @ 010,044 */ 5, 0x05, 
  /* RLE: 001 Pixels @ 015,044 */ 1, 0x37, 
  /* RLE: 014 Pixels @ 016,044 */ 14, 0x01, 
  /* ABS: 004 Pixels @ 030,044 */ 0, 4, 0x09, 0x03, 0x03, 0x06, 
  /* RLE: 014 Pixels @ 034,044 */ 14, 0x01, 
  /* RLE: 001 Pixels @ 048,044 */ 1, 0xBD, 
  /* RLE: 006 Pixels @ 049,044 */ 6, 0x0C, 
  /* RLE: 001 Pixels @ 055,044 */ 1, 0xDA, 
  /* RLE: 006 Pixels @ 056,044 */ 6, 0x01, 
  /* ABS: 004 Pixels @ 062,044 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 028 Pixels @ 002,045 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 030,045 */ 0, 4, 0x09, 0x03, 0x03, 0x06, 
  /* RLE: 028 Pixels @ 034,045 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 062,045 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 028 Pixels @ 002,046 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 030,046 */ 0, 4, 0x09, 0x03, 0x03, 0x06, 
  /* RLE: 028 Pixels @ 034,046 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 062,046 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 028 Pixels @ 002,047 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 030,047 */ 0, 4, 0x09, 0x03, 0x03, 0x06, 
  /* RLE: 028 Pixels @ 034,047 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 062,047 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 028 Pixels @ 002,048 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 030,048 */ 0, 4, 0x09, 0x03, 0x03, 0x06, 
  /* RLE: 028 Pixels @ 034,048 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 062,048 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 028 Pixels @ 002,049 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 030,049 */ 0, 4, 0x09, 0x03, 0x03, 0x06, 
  /* RLE: 028 Pixels @ 034,049 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 062,049 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 028 Pixels @ 002,050 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 030,050 */ 0, 4, 0x09, 0x03, 0x03, 0x06, 
  /* RLE: 028 Pixels @ 034,050 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 062,050 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 028 Pixels @ 002,051 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 030,051 */ 0, 4, 0x09, 0x03, 0x03, 0x06, 
  /* RLE: 028 Pixels @ 034,051 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 062,051 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 026 Pixels @ 002,052 */ 26, 0x01, 
  /* ABS: 008 Pixels @ 028,052 */ 0, 8, 0xDB, 0x35, 0x1D, 0x32, 0x32, 0x71, 0x35, 0x49, 
  /* RLE: 026 Pixels @ 036,052 */ 26, 0x01, 
  /* ABS: 004 Pixels @ 062,052 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 027 Pixels @ 002,053 */ 27, 0x01, 
  /* RLE: 001 Pixels @ 029,053 */ 1, 0x77, 
  /* RLE: 004 Pixels @ 030,053 */ 4, 0x05, 
  /* ABS: 002 Pixels @ 034,053 */ 0, 2, 0x1C, 0x5B, 
  /* RLE: 026 Pixels @ 036,053 */ 26, 0x01, 
  /* ABS: 004 Pixels @ 062,053 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 027 Pixels @ 002,054 */ 27, 0x01, 
  /* ABS: 006 Pixels @ 029,054 */ 0, 6, 0xDF, 0x2F, 0x05, 0x05, 0x05, 0x49, 
  /* RLE: 027 Pixels @ 035,054 */ 27, 0x01, 
  /* ABS: 004 Pixels @ 062,054 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 028 Pixels @ 002,055 */ 28, 0x01, 
  /* ABS: 005 Pixels @ 030,055 */ 0, 5, 0x81, 0x05, 0x05, 0x1D, 0x61, 
  /* RLE: 027 Pixels @ 035,055 */ 27, 0x01, 
  /* ABS: 004 Pixels @ 062,055 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 028 Pixels @ 002,056 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 030,056 */ 0, 4, 0x55, 0x31, 0x05, 0x4E, 
  /* RLE: 028 Pixels @ 034,056 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 062,056 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 029 Pixels @ 002,057 */ 29, 0x01, 
  /* ABS: 002 Pixels @ 031,057 */ 0, 2, 0x24, 0x7F, 
  /* RLE: 029 Pixels @ 033,057 */ 29, 0x01, 
  /* ABS: 004 Pixels @ 062,057 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 029 Pixels @ 002,058 */ 29, 0x01, 
  /* ABS: 002 Pixels @ 031,058 */ 0, 2, 0xFE, 0xF4, 
  /* RLE: 029 Pixels @ 033,058 */ 29, 0x01, 
  /* ABS: 004 Pixels @ 062,058 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 060 Pixels @ 002,059 */ 60, 0x01, 
  /* ABS: 004 Pixels @ 062,059 */ 0, 4, 0x04, 0x02, 0x02, 0x04, 
  /* RLE: 060 Pixels @ 002,060 */ 60, 0x01, 
  /* ABS: 004 Pixels @ 062,060 */ 0, 4, 0x04, 0x02, 0x0F, 0x27, 
  /* RLE: 060 Pixels @ 002,061 */ 60, 0x01, 
  /* ABS: 005 Pixels @ 062,061 */ 0, 5, 0xF9, 0x2E, 0x68, 0xA6, 0x5C, 
  /* RLE: 058 Pixels @ 003,062 */ 58, 0x01, 
  /* ABS: 006 Pixels @ 061,062 */ 0, 6, 0x5C, 0x82, 0x1B, 0x1A, 0x1B, 0x0F, 
  /* RLE: 058 Pixels @ 003,063 */ 58, 0x02, 
  /* ABS: 003 Pixels @ 061,063 */ 0, 3, 0x63, 0x65, 0x1A, 
  0
};  // 1534 bytes for 4096 pixels

GUI_CONST_STORAGE GUI_BITMAP bmIcon_emModbus_64x64 = {
  64, // xSize
  64, // ySize
  64, // BytesPerLine
  GUI_COMPRESS_RLE8, // BitsPerPixel
  _acIcon_emModbus_64x64,  // Pointer to picture data (indices)
  &_PalIcon_emModbus_64x64,  // Pointer to palette
  GUI_DRAW_RLE8
};

/*************************** End of file ****************************/
