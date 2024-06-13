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
* Source file: Icon_emWeb_64x64                                      *
* Dimensions:  64 * 64                                               *
* NumColors:   223                                                   *
---------------------------END-OF-HEADER------------------------------
*/

#include <stdlib.h>

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

extern GUI_CONST_STORAGE GUI_BITMAP bmIcon_emWeb_64x64;

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
static GUI_CONST_STORAGE GUI_COLOR _ColorsIcon_emWeb_64x64[] = {
#if (GUI_USE_ARGB == 0)
  0x00FFFFFF, 0x00FFFFFF, 0x00A95C00, 0x001C1718,
  0x00000000, 0x00FAFAFA, 0x00E9D5BE, 0x00AAAAAA,
  0x00B47121, 0x00DEC09C, 0x00DDBE99, 0x00B47222,
  0x00D8D8D8, 0x001F1A1B, 0x00AA5D02, 0x001E1E1E,
  0x00A95D01, 0x00AB5F05, 0x00B16C19, 0x00B3701F,
  0x00B7772B, 0x00BE843E, 0x00D5AE81, 0x00DBBA93,
  0x00ECDAC6, 0x00F3F2F2, 0x001D1414, 0x00272223,
  0x00B06915, 0x00B77629, 0x00B7772A, 0x00C28B4A,
  0x00C9985E, 0x00E0C4A3, 0x00E2C7A8, 0x00F6EEE5,
  0x00F7F0E7, 0x00F4F4F4, 0x00FEFEFD, 0x00050505,
  0x00101010, 0x001D1819, 0x00AB6007, 0x00AC6108,
  0x00AC6209, 0x00AC620A, 0x00AD630B, 0x00AD640C,
  0x00AE660F, 0x00AF6711, 0x00AF6813, 0x00B06A16,
  0x00B26D1B, 0x00B36F1E, 0x00B57324, 0x00B97B30,
  0x00BD823B, 0x00BD823C, 0x00C79458, 0x00C8965B,
  0x00C8975C, 0x00CA9B62, 0x00CB9C64, 0x00CDA06A,
  0x00CDA06B, 0x00CEA26E, 0x00D0A673, 0x00D1A978,
  0x00A2A2A2, 0x00B4B4B4, 0x00D5AF82, 0x00D9B68D,
  0x00D9B78F, 0x00DBBB94, 0x00DCBC96, 0x00DCBD98,
  0x00DEC09D, 0x00DEC19E, 0x00DFC2A0, 0x00DFC3A1,
  0x00E0C5A4, 0x00E1C6A6, 0x00E2C9AA, 0x00E5CDB1,
  0x00E5D0B5, 0x00E7D2B9, 0x00EAD6BF, 0x00EAD7C1,
  0x00EAD9C2, 0x00ECDBC6, 0x00ECDBC7, 0x00ECDCC8,
  0x00F0E3D3, 0x00F2E6D8, 0x00F3E7DA, 0x00EEEEEE,
  0x00F6EDE3, 0x00F6EEE4, 0x00F9F3ED, 0x00FAF5EF,
  0x00F1F1F1, 0x00FBF7F3, 0x00FCFCFC, 0x00FEFEFE,
  0x00FFFEFE, 0x00252021, 0x00302B2C, 0x00322D2F,
  0x00373233, 0x00383334, 0x003A313A, 0x00424242,
  0x00434343, 0x00626262, 0x00636363, 0x00AA5E03,
  0x00AD640D, 0x00AE650E, 0x00AE6610, 0x00B16B17,
  0x00B16B18, 0x00B26E1C, 0x00B36F1D, 0x00B47020,
  0x00B57425, 0x00B67426, 0x00B67527, 0x00B67628,
  0x00B9792E, 0x00B97A2F, 0x00BA7B31, 0x00BC7F37,
  0x00807D7E, 0x00BC8038, 0x00BE833D, 0x00BE843F,
  0x00BF8642, 0x00C08743, 0x00C08744, 0x00C28B49,
  0x00C28C4B, 0x00C38D4C, 0x00C48E4F, 0x00C69356,
  0x00C9995F, 0x00C99960, 0x00CB9D66, 0x00CEA26D,
  0x00CEA36F, 0x00CFA470, 0x00CFA572, 0x00D0A674,
  0x00D0A775, 0x00D2A979, 0x00D2AA7A, 0x00D3AC7D,
  0x00D3AD7E, 0x00D4AD7F, 0x00838081, 0x00858283,
  0x00868384, 0x00898989, 0x008A8A8A, 0x00D4AE80,
  0x00D5B083, 0x00D7B489, 0x00D8B48A, 0x00D8B58C,
  0x00D9B78E, 0x00DAB890, 0x00DAB991, 0x00DBBB95,
  0x00DCBB95, 0x00DCBD97, 0x00E1C4A4, 0x00E1C5A5,
  0x00E2C6A6, 0x00E2C8A9, 0x00E3CBAD, 0x00E3CBAE,
  0x00E4CAAC, 0x00E4CBAF, 0x00E4CCAF, 0x00E4CCB0,
  0x00E5CEB2, 0x00E6CFB4, 0x00E6D0B5, 0x00E7D1B7,
  0x00E7D2B8, 0x00E8D2BA, 0x00E8D3BA, 0x00E8D4BC,
  0x00E8D5BD, 0x00E9D6BE, 0x00EAD8C2, 0x00EAD8C3,
  0x00EAD9C3, 0x00EBD9C3, 0x00EBD9C4, 0x00EBDAC5,
  0x00ECD9C4, 0x00EEDECC, 0x00EEDFCC, 0x00EFE0CF,
  0x00EFE2D1, 0x00F0E4D4, 0x00F1E4D5, 0x00F1E5D5,
  0x00F1E5D7, 0x00F3E9DC, 0x00F4EADE, 0x00F5ECE1,
  0x00F7EFE6, 0x00F7EFE7, 0x00F7F0E8, 0x00F8F2EB,
  0x00F5F5F5, 0x00FAF5F0, 0x00FCF9F6, 0x00FDFBF9,
  0x00FDFCFA, 0x00FEFCFB, 0x00FEFDFC
#else
  0xFFFFFFFF, 0xFFFFFFFF, 0xFF005CA9, 0xFF18171C,
  0xFF000000, 0xFFFAFAFA, 0xFFBED5E9, 0xFFAAAAAA,
  0xFF2171B4, 0xFF9CC0DE, 0xFF99BEDD, 0xFF2272B4,
  0xFFD8D8D8, 0xFF1B1A1F, 0xFF025DAA, 0xFF1E1E1E,
  0xFF015DA9, 0xFF055FAB, 0xFF196CB1, 0xFF1F70B3,
  0xFF2B77B7, 0xFF3E84BE, 0xFF81AED5, 0xFF93BADB,
  0xFFC6DAEC, 0xFFF2F2F3, 0xFF14141D, 0xFF232227,
  0xFF1569B0, 0xFF2976B7, 0xFF2A77B7, 0xFF4A8BC2,
  0xFF5E98C9, 0xFFA3C4E0, 0xFFA8C7E2, 0xFFE5EEF6,
  0xFFE7F0F7, 0xFFF4F4F4, 0xFFFDFEFE, 0xFF050505,
  0xFF101010, 0xFF19181D, 0xFF0760AB, 0xFF0861AC,
  0xFF0962AC, 0xFF0A62AC, 0xFF0B63AD, 0xFF0C64AD,
  0xFF0F66AE, 0xFF1167AF, 0xFF1368AF, 0xFF166AB0,
  0xFF1B6DB2, 0xFF1E6FB3, 0xFF2473B5, 0xFF307BB9,
  0xFF3B82BD, 0xFF3C82BD, 0xFF5894C7, 0xFF5B96C8,
  0xFF5C97C8, 0xFF629BCA, 0xFF649CCB, 0xFF6AA0CD,
  0xFF6BA0CD, 0xFF6EA2CE, 0xFF73A6D0, 0xFF78A9D1,
  0xFFA2A2A2, 0xFFB4B4B4, 0xFF82AFD5, 0xFF8DB6D9,
  0xFF8FB7D9, 0xFF94BBDB, 0xFF96BCDC, 0xFF98BDDC,
  0xFF9DC0DE, 0xFF9EC1DE, 0xFFA0C2DF, 0xFFA1C3DF,
  0xFFA4C5E0, 0xFFA6C6E1, 0xFFAAC9E2, 0xFFB1CDE5,
  0xFFB5D0E5, 0xFFB9D2E7, 0xFFBFD6EA, 0xFFC1D7EA,
  0xFFC2D9EA, 0xFFC6DBEC, 0xFFC7DBEC, 0xFFC8DCEC,
  0xFFD3E3F0, 0xFFD8E6F2, 0xFFDAE7F3, 0xFFEEEEEE,
  0xFFE3EDF6, 0xFFE4EEF6, 0xFFEDF3F9, 0xFFEFF5FA,
  0xFFF1F1F1, 0xFFF3F7FB, 0xFFFCFCFC, 0xFFFEFEFE,
  0xFFFEFEFF, 0xFF212025, 0xFF2C2B30, 0xFF2F2D32,
  0xFF333237, 0xFF343338, 0xFF3A313A, 0xFF424242,
  0xFF434343, 0xFF626262, 0xFF636363, 0xFF035EAA,
  0xFF0D64AD, 0xFF0E65AE, 0xFF1066AE, 0xFF176BB1,
  0xFF186BB1, 0xFF1C6EB2, 0xFF1D6FB3, 0xFF2070B4,
  0xFF2574B5, 0xFF2674B6, 0xFF2775B6, 0xFF2876B6,
  0xFF2E79B9, 0xFF2F7AB9, 0xFF317BBA, 0xFF377FBC,
  0xFF7E7D80, 0xFF3880BC, 0xFF3D83BE, 0xFF3F84BE,
  0xFF4286BF, 0xFF4387C0, 0xFF4487C0, 0xFF498BC2,
  0xFF4B8CC2, 0xFF4C8DC3, 0xFF4F8EC4, 0xFF5693C6,
  0xFF5F99C9, 0xFF6099C9, 0xFF669DCB, 0xFF6DA2CE,
  0xFF6FA3CE, 0xFF70A4CF, 0xFF72A5CF, 0xFF74A6D0,
  0xFF75A7D0, 0xFF79A9D2, 0xFF7AAAD2, 0xFF7DACD3,
  0xFF7EADD3, 0xFF7FADD4, 0xFF818083, 0xFF838285,
  0xFF848386, 0xFF898989, 0xFF8A8A8A, 0xFF80AED4,
  0xFF83B0D5, 0xFF89B4D7, 0xFF8AB4D8, 0xFF8CB5D8,
  0xFF8EB7D9, 0xFF90B8DA, 0xFF91B9DA, 0xFF95BBDB,
  0xFF95BBDC, 0xFF97BDDC, 0xFFA4C4E1, 0xFFA5C5E1,
  0xFFA6C6E2, 0xFFA9C8E2, 0xFFADCBE3, 0xFFAECBE3,
  0xFFACCAE4, 0xFFAFCBE4, 0xFFAFCCE4, 0xFFB0CCE4,
  0xFFB2CEE5, 0xFFB4CFE6, 0xFFB5D0E6, 0xFFB7D1E7,
  0xFFB8D2E7, 0xFFBAD2E8, 0xFFBAD3E8, 0xFFBCD4E8,
  0xFFBDD5E8, 0xFFBED6E9, 0xFFC2D8EA, 0xFFC3D8EA,
  0xFFC3D9EA, 0xFFC3D9EB, 0xFFC4D9EB, 0xFFC5DAEB,
  0xFFC4D9EC, 0xFFCCDEEE, 0xFFCCDFEE, 0xFFCFE0EF,
  0xFFD1E2EF, 0xFFD4E4F0, 0xFFD5E4F1, 0xFFD5E5F1,
  0xFFD7E5F1, 0xFFDCE9F3, 0xFFDEEAF4, 0xFFE1ECF5,
  0xFFE6EFF7, 0xFFE7EFF7, 0xFFE8F0F7, 0xFFEBF2F8,
  0xFFF5F5F5, 0xFFF0F5FA, 0xFFF6F9FC, 0xFFF9FBFD,
  0xFFFAFCFD, 0xFFFBFCFE, 0xFFFCFDFE
#endif

};

static GUI_CONST_STORAGE GUI_LOGPALETTE _PalIcon_emWeb_64x64 = {
  223,  // Number of entries
  1,    // Has transparency
  &_ColorsIcon_emWeb_64x64[0]
};

static GUI_CONST_STORAGE unsigned char _acIcon_emWeb_64x64[] = {
  /* ABS: 003 Pixels @ 000,000 */ 0, 3, 0x6E, 0x6D, 0x0D, 
  /* RLE: 058 Pixels @ 003,000 */ 58, 0x03, 
  /* ABS: 006 Pixels @ 061,000 */ 0, 6, 0x0D, 0x6C, 0x1A, 0x6B, 0xA0, 0xD8, 
  /* RLE: 058 Pixels @ 003,001 */ 58, 0x01, 
  /* ABS: 005 Pixels @ 061,001 */ 0, 5, 0x25, 0x9F, 0x1B, 0x0D, 0x19, 
  /* RLE: 060 Pixels @ 002,002 */ 60, 0x01, 
  /* ABS: 004 Pixels @ 062,002 */ 0, 4, 0x19, 0x29, 0x03, 0x05, 
  /* RLE: 060 Pixels @ 002,003 */ 60, 0x01, 
  /* ABS: 004 Pixels @ 062,003 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 060 Pixels @ 002,004 */ 60, 0x01, 
  /* ABS: 004 Pixels @ 062,004 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 060 Pixels @ 002,005 */ 60, 0x01, 
  /* ABS: 004 Pixels @ 062,005 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 023 Pixels @ 002,006 */ 23, 0x01, 
  /* ABS: 014 Pixels @ 025,006 */ 0, 14, 0xDC, 0x55, 0x40, 0x4B, 0xCA, 0x43, 0x3C, 0xB8, 0x3A, 0xB1, 0x18, 0x3F, 0x17, 0x61, 
  /* RLE: 023 Pixels @ 039,006 */ 23, 0x01, 
  /* ABS: 004 Pixels @ 062,006 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 021 Pixels @ 002,007 */ 21, 0x01, 
  /* ABS: 018 Pixels @ 023,007 */ 0, 18, 0xD7, 0xA3, 0x33, 0x11, 0x21, 0x9B, 0x11, 0x02, 0x08, 0x09, 0x02, 0x02, 0x37, 0xC4, 0x85, 0x0E, 0x8C, 0x06, 
  /* RLE: 021 Pixels @ 041,007 */ 21, 0x01, 
  /* ABS: 004 Pixels @ 062,007 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 019 Pixels @ 002,008 */ 19, 0x01, 
  /* ABS: 022 Pixels @ 021,008 */ 0, 22, 0xDD, 0xAA, 0x76, 0x02, 0x10, 0x51, 0x8F, 0x02, 0x02, 0x02, 0x08, 0x09, 0x02, 0x02, 0x02, 0x31, 0x06, 0x82, 0x02, 0x02, 0x1F, 0x5E, 
  /* RLE: 019 Pixels @ 043,008 */ 19, 0x01, 
  /* ABS: 004 Pixels @ 062,008 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 018 Pixels @ 002,009 */ 18, 0x01, 
  /* ABS: 007 Pixels @ 020,009 */ 0, 7, 0x60, 0x39, 0x02, 0x02, 0x02, 0x96, 0x94, 
  /* RLE: 004 Pixels @ 027,009 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 031,009 */ 0, 2, 0x08, 0x09, 
  /* RLE: 004 Pixels @ 033,009 */ 4, 0x02, 
  /* ABS: 007 Pixels @ 037,009 */ 0, 7, 0x1C, 0xC6, 0x2F, 0x02, 0x02, 0x2D, 0x4C, 
  /* RLE: 018 Pixels @ 044,009 */ 18, 0x01, 
  /* ABS: 004 Pixels @ 062,009 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 017 Pixels @ 002,010 */ 17, 0x01, 
  /* ABS: 007 Pixels @ 019,010 */ 0, 7, 0xC9, 0x1C, 0x02, 0x02, 0x02, 0x13, 0xB3, 
  /* RLE: 005 Pixels @ 026,010 */ 5, 0x02, 
  /* ABS: 002 Pixels @ 031,010 */ 0, 2, 0x08, 0x09, 
  /* RLE: 005 Pixels @ 033,010 */ 5, 0x02, 
  /* ABS: 002 Pixels @ 038,010 */ 0, 2, 0x15, 0x47, 
  /* RLE: 004 Pixels @ 040,010 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 044,010 */ 0, 2, 0x40, 0x26, 
  /* RLE: 016 Pixels @ 046,010 */ 16, 0x01, 
  /* ABS: 004 Pixels @ 062,010 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 016 Pixels @ 002,011 */ 16, 0x01, 
  /* ABS: 002 Pixels @ 018,011 */ 0, 2, 0x59, 0x30, 
  /* RLE: 004 Pixels @ 020,011 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 024,011 */ 0, 2, 0xB4, 0x7B, 
  /* RLE: 005 Pixels @ 026,011 */ 5, 0x02, 
  /* ABS: 002 Pixels @ 031,011 */ 0, 2, 0x08, 0x09, 
  /* RLE: 006 Pixels @ 033,011 */ 6, 0x02, 
  /* ABS: 002 Pixels @ 039,011 */ 0, 2, 0x4C, 0x37, 
  /* RLE: 004 Pixels @ 041,011 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 045,011 */ 0, 2, 0x20, 0x26, 
  /* RLE: 015 Pixels @ 047,011 */ 15, 0x01, 
  /* ABS: 004 Pixels @ 062,011 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 015 Pixels @ 002,012 */ 15, 0x01, 
  /* ABS: 002 Pixels @ 017,012 */ 0, 2, 0xD2, 0x33, 
  /* RLE: 004 Pixels @ 019,012 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 023,012 */ 0, 2, 0x14, 0xAB, 
  /* RLE: 006 Pixels @ 025,012 */ 6, 0x02, 
  /* ABS: 002 Pixels @ 031,012 */ 0, 2, 0x08, 0x09, 
  /* RLE: 006 Pixels @ 033,012 */ 6, 0x02, 
  /* ABS: 002 Pixels @ 039,012 */ 0, 2, 0x13, 0xAE, 
  /* RLE: 005 Pixels @ 041,012 */ 5, 0x02, 
  /* RLE: 001 Pixels @ 046,012 */ 1, 0x99, 
  /* RLE: 015 Pixels @ 047,012 */ 15, 0x01, 
  /* ABS: 004 Pixels @ 062,012 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 014 Pixels @ 002,013 */ 14, 0x01, 
  /* ABS: 002 Pixels @ 016,013 */ 0, 2, 0xDB, 0x80, 
  /* RLE: 005 Pixels @ 018,013 */ 5, 0x02, 
  /* ABS: 002 Pixels @ 023,013 */ 0, 2, 0x4A, 0x36, 
  /* RLE: 006 Pixels @ 025,013 */ 6, 0x02, 
  /* ABS: 002 Pixels @ 031,013 */ 0, 2, 0x08, 0x09, 
  /* RLE: 007 Pixels @ 033,013 */ 7, 0x02, 
  /* ABS: 002 Pixels @ 040,013 */ 0, 2, 0xAF, 0x12, 
  /* RLE: 005 Pixels @ 042,013 */ 5, 0x02, 
  /* RLE: 001 Pixels @ 047,013 */ 1, 0xB2, 
  /* RLE: 014 Pixels @ 048,013 */ 14, 0x01, 
  /* ABS: 004 Pixels @ 062,013 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 014 Pixels @ 002,014 */ 14, 0x01, 
  /* RLE: 001 Pixels @ 016,014 */ 1, 0x4A, 
  /* RLE: 005 Pixels @ 017,014 */ 5, 0x0B, 
  /* ABS: 002 Pixels @ 022,014 */ 0, 2, 0x1E, 0xC5, 
  /* RLE: 007 Pixels @ 024,014 */ 7, 0x0B, 
  /* ABS: 002 Pixels @ 031,014 */ 0, 2, 0x15, 0x52, 
  /* RLE: 007 Pixels @ 033,014 */ 7, 0x0B, 
  /* ABS: 002 Pixels @ 040,014 */ 0, 2, 0x3D, 0xA5, 
  /* RLE: 005 Pixels @ 042,014 */ 5, 0x0B, 
  /* ABS: 002 Pixels @ 047,014 */ 0, 2, 0x83, 0x65, 
  /* RLE: 013 Pixels @ 049,014 */ 13, 0x01, 
  /* ABS: 004 Pixels @ 062,014 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 013 Pixels @ 002,015 */ 13, 0x01, 
  /* RLE: 001 Pixels @ 015,015 */ 1, 0x60, 
  /* RLE: 006 Pixels @ 016,015 */ 6, 0x0A, 
  /* ABS: 002 Pixels @ 022,015 */ 0, 2, 0x59, 0x55, 
  /* RLE: 007 Pixels @ 024,015 */ 7, 0x0A, 
  /* ABS: 002 Pixels @ 031,015 */ 0, 2, 0x51, 0x5D, 
  /* RLE: 008 Pixels @ 033,015 */ 8, 0x0A, 
  /* RLE: 001 Pixels @ 041,015 */ 1, 0xD4, 
  /* RLE: 006 Pixels @ 042,015 */ 6, 0x0A, 
  /* RLE: 001 Pixels @ 048,015 */ 1, 0x53, 
  /* RLE: 013 Pixels @ 049,015 */ 13, 0x01, 
  /* ABS: 004 Pixels @ 062,015 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 013 Pixels @ 002,016 */ 13, 0x01, 
  /* RLE: 001 Pixels @ 015,016 */ 1, 0x3E, 
  /* RLE: 006 Pixels @ 016,016 */ 6, 0x02, 
  /* ABS: 002 Pixels @ 022,016 */ 0, 2, 0x4F, 0x08, 
  /* RLE: 007 Pixels @ 024,016 */ 7, 0x02, 
  /* ABS: 002 Pixels @ 031,016 */ 0, 2, 0x08, 0x09, 
  /* RLE: 008 Pixels @ 033,016 */ 8, 0x02, 
  /* ABS: 002 Pixels @ 041,016 */ 0, 2, 0x50, 0x13, 
  /* RLE: 005 Pixels @ 043,016 */ 5, 0x02, 
  /* ABS: 002 Pixels @ 048,016 */ 0, 2, 0x11, 0xD3, 
  /* RLE: 012 Pixels @ 050,016 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,016 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 012 Pixels @ 002,017 */ 12, 0x01, 
  /* ABS: 002 Pixels @ 014,017 */ 0, 2, 0xD6, 0x2A, 
  /* RLE: 006 Pixels @ 016,017 */ 6, 0x02, 
  /* RLE: 001 Pixels @ 022,017 */ 1, 0xC3, 
  /* RLE: 008 Pixels @ 023,017 */ 8, 0x02, 
  /* ABS: 002 Pixels @ 031,017 */ 0, 2, 0x08, 0x09, 
  /* RLE: 008 Pixels @ 033,017 */ 8, 0x02, 
  /* ABS: 002 Pixels @ 041,017 */ 0, 2, 0x3D, 0x20, 
  /* RLE: 006 Pixels @ 043,017 */ 6, 0x02, 
  /* RLE: 001 Pixels @ 049,017 */ 1, 0x97, 
  /* RLE: 012 Pixels @ 050,017 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,017 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 012 Pixels @ 002,018 */ 12, 0x01, 
  /* RLE: 001 Pixels @ 014,018 */ 1, 0x49, 
  /* RLE: 006 Pixels @ 015,018 */ 6, 0x02, 
  /* ABS: 002 Pixels @ 021,018 */ 0, 2, 0x1C, 0x22, 
  /* RLE: 008 Pixels @ 023,018 */ 8, 0x02, 
  /* ABS: 002 Pixels @ 031,018 */ 0, 2, 0x08, 0x09, 
  /* RLE: 008 Pixels @ 033,018 */ 8, 0x02, 
  /* ABS: 002 Pixels @ 041,018 */ 0, 2, 0x81, 0xA9, 
  /* RLE: 006 Pixels @ 043,018 */ 6, 0x02, 
  /* ABS: 002 Pixels @ 049,018 */ 0, 2, 0x34, 0x68, 
  /* RLE: 011 Pixels @ 051,018 */ 11, 0x01, 
  /* ABS: 004 Pixels @ 062,018 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 012 Pixels @ 002,019 */ 12, 0x01, 
  /* RLE: 001 Pixels @ 014,019 */ 1, 0x89, 
  /* RLE: 006 Pixels @ 015,019 */ 6, 0x02, 
  /* ABS: 002 Pixels @ 021,019 */ 0, 2, 0x8A, 0x9A, 
  /* RLE: 008 Pixels @ 023,019 */ 8, 0x02, 
  /* ABS: 002 Pixels @ 031,019 */ 0, 2, 0x08, 0x09, 
  /* RLE: 008 Pixels @ 033,019 */ 8, 0x02, 
  /* ABS: 002 Pixels @ 041,019 */ 0, 2, 0x11, 0xBD, 
  /* RLE: 007 Pixels @ 043,019 */ 7, 0x02, 
  /* RLE: 001 Pixels @ 050,019 */ 1, 0x5B, 
  /* RLE: 011 Pixels @ 051,019 */ 11, 0x01, 
  /* ABS: 004 Pixels @ 062,019 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 011 Pixels @ 002,020 */ 11, 0x01, 
  /* ABS: 002 Pixels @ 013,020 */ 0, 2, 0x26, 0x2F, 
  /* RLE: 006 Pixels @ 015,020 */ 6, 0x02, 
  /* ABS: 002 Pixels @ 021,020 */ 0, 2, 0x92, 0x3A, 
  /* RLE: 008 Pixels @ 023,020 */ 8, 0x02, 
  /* ABS: 002 Pixels @ 031,020 */ 0, 2, 0x08, 0x09, 
  /* RLE: 009 Pixels @ 033,020 */ 9, 0x02, 
  /* RLE: 001 Pixels @ 042,020 */ 1, 0x58, 
  /* RLE: 007 Pixels @ 043,020 */ 7, 0x02, 
  /* RLE: 001 Pixels @ 050,020 */ 1, 0x47, 
  /* RLE: 011 Pixels @ 051,020 */ 11, 0x01, 
  /* ABS: 004 Pixels @ 062,020 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 011 Pixels @ 002,021 */ 11, 0x01, 
  /* RLE: 001 Pixels @ 013,021 */ 1, 0xCE, 
  /* RLE: 007 Pixels @ 014,021 */ 7, 0x02, 
  /* ABS: 002 Pixels @ 021,021 */ 0, 2, 0x46, 0x38, 
  /* RLE: 008 Pixels @ 023,021 */ 8, 0x02, 
  /* ABS: 002 Pixels @ 031,021 */ 0, 2, 0x08, 0x09, 
  /* RLE: 009 Pixels @ 033,021 */ 9, 0x02, 
  /* ABS: 002 Pixels @ 042,021 */ 0, 2, 0xC0, 0x0E, 
  /* RLE: 006 Pixels @ 044,021 */ 6, 0x02, 
  /* RLE: 001 Pixels @ 050,021 */ 1, 0x3B, 
  /* RLE: 011 Pixels @ 051,021 */ 11, 0x01, 
  /* ABS: 004 Pixels @ 062,021 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 011 Pixels @ 002,022 */ 11, 0x01, 
  /* RLE: 001 Pixels @ 013,022 */ 1, 0xBA, 
  /* RLE: 007 Pixels @ 014,022 */ 7, 0x02, 
  /* ABS: 002 Pixels @ 021,022 */ 0, 2, 0x17, 0x1D, 
  /* RLE: 008 Pixels @ 023,022 */ 8, 0x02, 
  /* ABS: 002 Pixels @ 031,022 */ 0, 2, 0x08, 0x09, 
  /* RLE: 009 Pixels @ 033,022 */ 9, 0x02, 
  /* ABS: 002 Pixels @ 042,022 */ 0, 2, 0xB6, 0x75, 
  /* RLE: 006 Pixels @ 044,022 */ 6, 0x02, 
  /* RLE: 001 Pixels @ 050,022 */ 1, 0x39, 
  /* RLE: 011 Pixels @ 051,022 */ 11, 0x01, 
  /* ABS: 004 Pixels @ 062,022 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 011 Pixels @ 002,023 */ 11, 0x01, 
  /* RLE: 001 Pixels @ 013,023 */ 1, 0x4F, 
  /* RLE: 007 Pixels @ 014,023 */ 7, 0x02, 
  /* ABS: 002 Pixels @ 021,023 */ 0, 2, 0x4D, 0x35, 
  /* RLE: 008 Pixels @ 023,023 */ 8, 0x02, 
  /* ABS: 002 Pixels @ 031,023 */ 0, 2, 0x08, 0x09, 
  /* RLE: 009 Pixels @ 033,023 */ 9, 0x02, 
  /* ABS: 002 Pixels @ 042,023 */ 0, 2, 0x21, 0x12, 
  /* RLE: 006 Pixels @ 044,023 */ 6, 0x02, 
  /* RLE: 001 Pixels @ 050,023 */ 1, 0x7E, 
  /* RLE: 011 Pixels @ 051,023 */ 11, 0x01, 
  /* ABS: 004 Pixels @ 062,023 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 011 Pixels @ 002,024 */ 11, 0x01, 
  /* RLE: 001 Pixels @ 013,024 */ 1, 0x61, 
  /* RLE: 007 Pixels @ 014,024 */ 7, 0x06, 
  /* ABS: 002 Pixels @ 021,024 */ 0, 2, 0xD5, 0xC7, 
  /* RLE: 008 Pixels @ 023,024 */ 8, 0x06, 
  /* ABS: 002 Pixels @ 031,024 */ 0, 2, 0x5A, 0x23, 
  /* RLE: 009 Pixels @ 033,024 */ 9, 0x06, 
  /* ABS: 002 Pixels @ 042,024 */ 0, 2, 0x23, 0x18, 
  /* RLE: 006 Pixels @ 044,024 */ 6, 0x06, 
  /* RLE: 001 Pixels @ 050,024 */ 1, 0x18, 
  /* RLE: 011 Pixels @ 051,024 */ 11, 0x01, 
  /* ABS: 004 Pixels @ 062,024 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 011 Pixels @ 002,025 */ 11, 0x01, 
  /* RLE: 001 Pixels @ 013,025 */ 1, 0x21, 
  /* RLE: 007 Pixels @ 014,025 */ 7, 0x02, 
  /* ABS: 002 Pixels @ 021,025 */ 0, 2, 0xAD, 0x13, 
  /* RLE: 008 Pixels @ 023,025 */ 8, 0x02, 
  /* ABS: 002 Pixels @ 031,025 */ 0, 2, 0x08, 0x09, 
  /* RLE: 009 Pixels @ 033,025 */ 9, 0x02, 
  /* ABS: 002 Pixels @ 042,025 */ 0, 2, 0x50, 0x12, 
  /* RLE: 006 Pixels @ 044,025 */ 6, 0x02, 
  /* RLE: 001 Pixels @ 050,025 */ 1, 0x1D, 
  /* RLE: 011 Pixels @ 051,025 */ 11, 0x01, 
  /* ABS: 004 Pixels @ 062,025 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 011 Pixels @ 002,026 */ 11, 0x01, 
  /* RLE: 001 Pixels @ 013,026 */ 1, 0xBB, 
  /* RLE: 007 Pixels @ 014,026 */ 7, 0x02, 
  /* ABS: 002 Pixels @ 021,026 */ 0, 2, 0xA4, 0x1E, 
  /* RLE: 008 Pixels @ 023,026 */ 8, 0x02, 
  /* ABS: 002 Pixels @ 031,026 */ 0, 2, 0x08, 0x09, 
  /* RLE: 009 Pixels @ 033,026 */ 9, 0x02, 
  /* ABS: 002 Pixels @ 042,026 */ 0, 2, 0xB7, 0x74, 
  /* RLE: 006 Pixels @ 044,026 */ 6, 0x02, 
  /* RLE: 001 Pixels @ 050,026 */ 1, 0x15, 
  /* RLE: 011 Pixels @ 051,026 */ 11, 0x01, 
  /* ABS: 004 Pixels @ 062,026 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 011 Pixels @ 002,027 */ 11, 0x01, 
  /* RLE: 001 Pixels @ 013,027 */ 1, 0x5D, 
  /* RLE: 007 Pixels @ 014,027 */ 7, 0x02, 
  /* ABS: 002 Pixels @ 021,027 */ 0, 2, 0x95, 0x15, 
  /* RLE: 008 Pixels @ 023,027 */ 8, 0x02, 
  /* ABS: 002 Pixels @ 031,027 */ 0, 2, 0x08, 0x09, 
  /* RLE: 009 Pixels @ 033,027 */ 9, 0x02, 
  /* ABS: 002 Pixels @ 042,027 */ 0, 2, 0xC1, 0x10, 
  /* RLE: 006 Pixels @ 044,027 */ 6, 0x02, 
  /* RLE: 001 Pixels @ 050,027 */ 1, 0x91, 
  /* RLE: 011 Pixels @ 051,027 */ 11, 0x01, 
  /* ABS: 004 Pixels @ 062,027 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 011 Pixels @ 002,028 */ 11, 0x01, 
  /* ABS: 002 Pixels @ 013,028 */ 0, 2, 0x68, 0x30, 
  /* RLE: 006 Pixels @ 015,028 */ 6, 0x02, 
  /* ABS: 002 Pixels @ 021,028 */ 0, 2, 0x3C, 0x3B, 
  /* RLE: 008 Pixels @ 023,028 */ 8, 0x02, 
  /* ABS: 002 Pixels @ 031,028 */ 0, 2, 0x08, 0x09, 
  /* RLE: 009 Pixels @ 033,028 */ 9, 0x02, 
  /* RLE: 001 Pixels @ 042,028 */ 1, 0x58, 
  /* RLE: 007 Pixels @ 043,028 */ 7, 0x02, 
  /* RLE: 001 Pixels @ 050,028 */ 1, 0x17, 
  /* RLE: 011 Pixels @ 051,028 */ 11, 0x01, 
  /* ABS: 004 Pixels @ 062,028 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 012 Pixels @ 002,029 */ 12, 0x01, 
  /* RLE: 001 Pixels @ 014,029 */ 1, 0x1F, 
  /* RLE: 006 Pixels @ 015,029 */ 6, 0x02, 
  /* ABS: 002 Pixels @ 021,029 */ 0, 2, 0x86, 0x16, 
  /* RLE: 008 Pixels @ 023,029 */ 8, 0x02, 
  /* ABS: 002 Pixels @ 031,029 */ 0, 2, 0x08, 0x09, 
  /* RLE: 008 Pixels @ 033,029 */ 8, 0x02, 
  /* ABS: 002 Pixels @ 041,029 */ 0, 2, 0x2D, 0xB9, 
  /* RLE: 007 Pixels @ 043,029 */ 7, 0x02, 
  /* RLE: 001 Pixels @ 050,029 */ 1, 0xCB, 
  /* RLE: 011 Pixels @ 051,029 */ 11, 0x01, 
  /* ABS: 004 Pixels @ 062,029 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 012 Pixels @ 002,030 */ 12, 0x01, 
  /* RLE: 001 Pixels @ 014,030 */ 1, 0x09, 
  /* RLE: 006 Pixels @ 015,030 */ 6, 0x02, 
  /* ABS: 002 Pixels @ 021,030 */ 0, 2, 0x2C, 0x54, 
  /* RLE: 008 Pixels @ 023,030 */ 8, 0x02, 
  /* ABS: 002 Pixels @ 031,030 */ 0, 2, 0x08, 0x09, 
  /* RLE: 008 Pixels @ 033,030 */ 8, 0x02, 
  /* ABS: 002 Pixels @ 041,030 */ 0, 2, 0x87, 0x9D, 
  /* RLE: 006 Pixels @ 043,030 */ 6, 0x02, 
  /* RLE: 001 Pixels @ 049,030 */ 1, 0x08, 
  /* RLE: 012 Pixels @ 050,030 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,030 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 012 Pixels @ 002,031 */ 12, 0x01, 
  /* ABS: 002 Pixels @ 014,031 */ 0, 2, 0x62, 0x2E, 
  /* RLE: 006 Pixels @ 016,031 */ 6, 0x02, 
  /* ABS: 002 Pixels @ 022,031 */ 0, 2, 0x57, 0x0E, 
  /* RLE: 007 Pixels @ 024,031 */ 7, 0x02, 
  /* ABS: 002 Pixels @ 031,031 */ 0, 2, 0x08, 0x09, 
  /* RLE: 008 Pixels @ 033,031 */ 8, 0x02, 
  /* ABS: 002 Pixels @ 041,031 */ 0, 2, 0x43, 0x8B, 
  /* RLE: 006 Pixels @ 043,031 */ 6, 0x02, 
  /* RLE: 001 Pixels @ 049,031 */ 1, 0x9C, 
  /* RLE: 012 Pixels @ 050,031 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,031 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 013 Pixels @ 002,032 */ 13, 0x01, 
  /* RLE: 001 Pixels @ 015,032 */ 1, 0x41, 
  /* RLE: 006 Pixels @ 016,032 */ 6, 0x02, 
  /* ABS: 002 Pixels @ 022,032 */ 0, 2, 0x49, 0x14, 
  /* RLE: 007 Pixels @ 024,032 */ 7, 0x02, 
  /* ABS: 002 Pixels @ 031,032 */ 0, 2, 0x08, 0x09, 
  /* RLE: 008 Pixels @ 033,032 */ 8, 0x02, 
  /* ABS: 002 Pixels @ 041,032 */ 0, 2, 0xB5, 0x32, 
  /* RLE: 005 Pixels @ 043,032 */ 5, 0x02, 
  /* ABS: 002 Pixels @ 048,032 */ 0, 2, 0x2A, 0x24, 
  /* RLE: 012 Pixels @ 050,032 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,032 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 013 Pixels @ 002,033 */ 13, 0x01, 
  /* ABS: 002 Pixels @ 015,033 */ 0, 2, 0xD9, 0x57, 
  /* RLE: 005 Pixels @ 017,033 */ 5, 0x06, 
  /* ABS: 002 Pixels @ 022,033 */ 0, 2, 0xD0, 0xCF, 
  /* RLE: 007 Pixels @ 024,033 */ 7, 0x06, 
  /* ABS: 002 Pixels @ 031,033 */ 0, 2, 0x5A, 0x23, 
  /* RLE: 007 Pixels @ 033,033 */ 7, 0x06, 
  /* ABS: 002 Pixels @ 040,033 */ 0, 2, 0x56, 0x62, 
  /* RLE: 006 Pixels @ 042,033 */ 6, 0x06, 
  /* RLE: 001 Pixels @ 048,033 */ 1, 0x5C, 
  /* RLE: 013 Pixels @ 049,033 */ 13, 0x01, 
  /* ABS: 004 Pixels @ 062,033 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 014 Pixels @ 002,034 */ 14, 0x01, 
  /* RLE: 001 Pixels @ 016,034 */ 1, 0xA6, 
  /* RLE: 005 Pixels @ 017,034 */ 5, 0x02, 
  /* ABS: 002 Pixels @ 022,034 */ 0, 2, 0x2C, 0xBC, 
  /* RLE: 007 Pixels @ 024,034 */ 7, 0x02, 
  /* ABS: 002 Pixels @ 031,034 */ 0, 2, 0x08, 0x09, 
  /* RLE: 007 Pixels @ 033,034 */ 7, 0x02, 
  /* ABS: 002 Pixels @ 040,034 */ 0, 2, 0x8D, 0x42, 
  /* RLE: 005 Pixels @ 042,034 */ 5, 0x02, 
  /* ABS: 002 Pixels @ 047,034 */ 0, 2, 0x34, 0x63, 
  /* RLE: 013 Pixels @ 049,034 */ 13, 0x01, 
  /* ABS: 004 Pixels @ 062,034 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 014 Pixels @ 002,035 */ 14, 0x01, 
  /* ABS: 002 Pixels @ 016,035 */ 0, 2, 0xDE, 0x38, 
  /* RLE: 005 Pixels @ 018,035 */ 5, 0x02, 
  /* ABS: 002 Pixels @ 023,035 */ 0, 2, 0xA8, 0x14, 
  /* RLE: 006 Pixels @ 025,035 */ 6, 0x02, 
  /* ABS: 002 Pixels @ 031,035 */ 0, 2, 0x08, 0x09, 
  /* RLE: 007 Pixels @ 033,035 */ 7, 0x02, 
  /* ABS: 002 Pixels @ 040,035 */ 0, 2, 0x52, 0x32, 
  /* RLE: 004 Pixels @ 042,035 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 046,035 */ 0, 2, 0x73, 0xBF, 
  /* RLE: 014 Pixels @ 048,035 */ 14, 0x01, 
  /* ABS: 004 Pixels @ 062,035 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 015 Pixels @ 002,036 */ 15, 0x01, 
  /* ABS: 002 Pixels @ 017,036 */ 0, 2, 0x24, 0x35, 
  /* RLE: 004 Pixels @ 019,036 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 023,036 */ 0, 2, 0x36, 0x4E, 
  /* RLE: 006 Pixels @ 025,036 */ 6, 0x02, 
  /* ABS: 002 Pixels @ 031,036 */ 0, 2, 0x08, 0x09, 
  /* RLE: 006 Pixels @ 033,036 */ 6, 0x02, 
  /* ABS: 002 Pixels @ 039,036 */ 0, 2, 0x1D, 0x4D, 
  /* RLE: 005 Pixels @ 041,036 */ 5, 0x02, 
  /* RLE: 001 Pixels @ 046,036 */ 1, 0xA7, 
  /* RLE: 015 Pixels @ 047,036 */ 15, 0x01, 
  /* ABS: 004 Pixels @ 062,036 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 016 Pixels @ 002,037 */ 16, 0x01, 
  /* ABS: 002 Pixels @ 018,037 */ 0, 2, 0xCD, 0x78, 
  /* RLE: 004 Pixels @ 020,037 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 024,037 */ 0, 2, 0x4E, 0x1E, 
  /* RLE: 005 Pixels @ 026,037 */ 5, 0x02, 
  /* ABS: 002 Pixels @ 031,037 */ 0, 2, 0x08, 0x09, 
  /* RLE: 006 Pixels @ 033,037 */ 6, 0x02, 
  /* ABS: 002 Pixels @ 039,037 */ 0, 2, 0xB0, 0x7D, 
  /* RLE: 004 Pixels @ 041,037 */ 4, 0x02, 
  /* RLE: 001 Pixels @ 045,037 */ 1, 0x42, 
  /* RLE: 016 Pixels @ 046,037 */ 16, 0x01, 
  /* ABS: 004 Pixels @ 062,037 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 017 Pixels @ 002,038 */ 17, 0x01, 
  /* ABS: 008 Pixels @ 019,038 */ 0, 8, 0x5E, 0x0B, 0x02, 0x02, 0x02, 0x77, 0x54, 0x0E, 
  /* RLE: 004 Pixels @ 027,038 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 031,038 */ 0, 2, 0x08, 0x09, 
  /* RLE: 005 Pixels @ 033,038 */ 5, 0x02, 
  /* ABS: 007 Pixels @ 038,038 */ 0, 7, 0x1F, 0x16, 0x02, 0x02, 0x02, 0x10, 0x16, 
  /* RLE: 017 Pixels @ 045,038 */ 17, 0x01, 
  /* ABS: 004 Pixels @ 062,038 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 018 Pixels @ 002,039 */ 18, 0x01, 
  /* ABS: 007 Pixels @ 020,039 */ 0, 7, 0x63, 0x8E, 0x02, 0x02, 0x02, 0x3E, 0x16, 
  /* RLE: 004 Pixels @ 027,039 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 031,039 */ 0, 2, 0x08, 0x09, 
  /* RLE: 004 Pixels @ 033,039 */ 4, 0x02, 
  /* ABS: 007 Pixels @ 037,039 */ 0, 7, 0x7A, 0xC8, 0x2B, 0x02, 0x02, 0x31, 0x53, 
  /* RLE: 018 Pixels @ 044,039 */ 18, 0x01, 
  /* ABS: 004 Pixels @ 062,039 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 020 Pixels @ 002,040 */ 20, 0x01, 
  /* ABS: 021 Pixels @ 022,040 */ 0, 21, 0x22, 0x79, 0x02, 0x02, 0xAC, 0x3F, 0x02, 0x02, 0x02, 0x08, 0x09, 0x02, 0x02, 0x02, 0x12, 0xC2, 0x7C, 0x02, 0x10, 0x20, 0x24, 
  /* RLE: 019 Pixels @ 043,040 */ 19, 0x01, 
  /* ABS: 004 Pixels @ 062,040 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 021 Pixels @ 002,041 */ 21, 0x01, 
  /* ABS: 018 Pixels @ 023,041 */ 0, 18, 0xDA, 0x4B, 0x7F, 0x0E, 0x48, 0x17, 0x2E, 0x02, 0x08, 0x09, 0x02, 0x02, 0x88, 0x18, 0x14, 0x2B, 0x90, 0x5C, 
  /* RLE: 021 Pixels @ 041,041 */ 21, 0x01, 
  /* ABS: 004 Pixels @ 062,041 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 024 Pixels @ 002,042 */ 24, 0x01, 
  /* ABS: 013 Pixels @ 026,042 */ 0, 13, 0xCC, 0x46, 0x0A, 0xD1, 0x48, 0x93, 0xBE, 0x41, 0x56, 0x5B, 0x98, 0x22, 0x65, 
  /* RLE: 023 Pixels @ 039,042 */ 23, 0x01, 
  /* ABS: 004 Pixels @ 062,042 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 028 Pixels @ 002,043 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 030,043 */ 0, 4, 0x66, 0x5F, 0x5F, 0x66, 
  /* RLE: 028 Pixels @ 034,043 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 062,043 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 028 Pixels @ 002,044 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 030,044 */ 0, 4, 0x0C, 0x04, 0x04, 0x0C, 
  /* RLE: 028 Pixels @ 034,044 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 062,044 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 028 Pixels @ 002,045 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 030,045 */ 0, 4, 0x0C, 0x04, 0x04, 0x0C, 
  /* RLE: 028 Pixels @ 034,045 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 062,045 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 028 Pixels @ 002,046 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 030,046 */ 0, 4, 0x0C, 0x04, 0x04, 0x0C, 
  /* RLE: 028 Pixels @ 034,046 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 062,046 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 028 Pixels @ 002,047 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 030,047 */ 0, 4, 0x0C, 0x04, 0x04, 0x0C, 
  /* RLE: 028 Pixels @ 034,047 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 062,047 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 028 Pixels @ 002,048 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 030,048 */ 0, 4, 0x0C, 0x04, 0x04, 0x0C, 
  /* RLE: 028 Pixels @ 034,048 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 062,048 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 028 Pixels @ 002,049 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 030,049 */ 0, 4, 0x0C, 0x04, 0x04, 0x0C, 
  /* RLE: 028 Pixels @ 034,049 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 062,049 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 028 Pixels @ 002,050 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 030,050 */ 0, 4, 0x0C, 0x04, 0x04, 0x0C, 
  /* RLE: 028 Pixels @ 034,050 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 062,050 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 028 Pixels @ 002,051 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 030,051 */ 0, 4, 0x07, 0x04, 0x04, 0x07, 
  /* RLE: 028 Pixels @ 034,051 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 062,051 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 027 Pixels @ 002,052 */ 27, 0x01, 
  /* RLE: 001 Pixels @ 029,052 */ 1, 0xA1, 
  /* RLE: 004 Pixels @ 030,052 */ 4, 0x04, 
  /* RLE: 001 Pixels @ 034,052 */ 1, 0xA2, 
  /* RLE: 027 Pixels @ 035,052 */ 27, 0x01, 
  /* ABS: 004 Pixels @ 062,052 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 004 Pixels @ 002,053 */ 4, 0x01, 
  /* RLE: 001 Pixels @ 006,053 */ 1, 0x45, 
  /* RLE: 021 Pixels @ 007,053 */ 21, 0x07, 
  /* ABS: 002 Pixels @ 028,053 */ 0, 2, 0x44, 0x27, 
  /* RLE: 004 Pixels @ 030,053 */ 4, 0x04, 
  /* ABS: 002 Pixels @ 034,053 */ 0, 2, 0x27, 0x44, 
  /* RLE: 021 Pixels @ 036,053 */ 21, 0x07, 
  /* RLE: 001 Pixels @ 057,053 */ 1, 0x45, 
  /* RLE: 004 Pixels @ 058,053 */ 4, 0x01, 
  /* ABS: 004 Pixels @ 062,053 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 004 Pixels @ 002,054 */ 4, 0x01, 
  /* RLE: 001 Pixels @ 006,054 */ 1, 0x0F, 
  /* RLE: 050 Pixels @ 007,054 */ 50, 0x04, 
  /* RLE: 001 Pixels @ 057,054 */ 1, 0x0F, 
  /* RLE: 004 Pixels @ 058,054 */ 4, 0x01, 
  /* ABS: 004 Pixels @ 062,054 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 004 Pixels @ 002,055 */ 4, 0x01, 
  /* RLE: 001 Pixels @ 006,055 */ 1, 0x0F, 
  /* RLE: 050 Pixels @ 007,055 */ 50, 0x04, 
  /* RLE: 001 Pixels @ 057,055 */ 1, 0x0F, 
  /* RLE: 004 Pixels @ 058,055 */ 4, 0x01, 
  /* ABS: 004 Pixels @ 062,055 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 026 Pixels @ 002,056 */ 26, 0x01, 
  /* ABS: 002 Pixels @ 028,056 */ 0, 2, 0x67, 0x6F, 
  /* RLE: 004 Pixels @ 030,056 */ 4, 0x04, 
  /* ABS: 002 Pixels @ 034,056 */ 0, 2, 0x70, 0x67, 
  /* RLE: 026 Pixels @ 036,056 */ 26, 0x01, 
  /* ABS: 004 Pixels @ 062,056 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 027 Pixels @ 002,057 */ 27, 0x01, 
  /* ABS: 006 Pixels @ 029,057 */ 0, 6, 0x64, 0x71, 0x28, 0x28, 0x72, 0x64, 
  /* RLE: 027 Pixels @ 035,057 */ 27, 0x01, 
  /* ABS: 004 Pixels @ 062,057 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 060 Pixels @ 002,058 */ 60, 0x01, 
  /* ABS: 004 Pixels @ 062,058 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 060 Pixels @ 002,059 */ 60, 0x01, 
  /* ABS: 004 Pixels @ 062,059 */ 0, 4, 0x05, 0x03, 0x03, 0x05, 
  /* RLE: 060 Pixels @ 002,060 */ 60, 0x01, 
  /* ABS: 004 Pixels @ 062,060 */ 0, 4, 0x05, 0x03, 0x0D, 0x19, 
  /* RLE: 060 Pixels @ 002,061 */ 60, 0x01, 
  /* ABS: 005 Pixels @ 062,061 */ 0, 5, 0x19, 0x29, 0x6A, 0x9E, 0x25, 
  /* RLE: 058 Pixels @ 003,062 */ 58, 0x01, 
  /* ABS: 006 Pixels @ 061,062 */ 0, 6, 0x25, 0x84, 0x1B, 0x1A, 0x1B, 0x0D, 
  /* RLE: 058 Pixels @ 003,063 */ 58, 0x03, 
  /* ABS: 003 Pixels @ 061,063 */ 0, 3, 0x0D, 0x69, 0x1A, 
  0
};  // 1634 bytes for 4096 pixels

GUI_CONST_STORAGE GUI_BITMAP bmIcon_emWeb_64x64 = {
  64, // xSize
  64, // ySize
  64, // BytesPerLine
  GUI_COMPRESS_RLE8, // BitsPerPixel
  _acIcon_emWeb_64x64,  // Pointer to picture data (indices)
  &_PalIcon_emWeb_64x64,  // Pointer to palette
  GUI_DRAW_RLE8
};

/*************************** End of file ****************************/
