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
* Source file: Icon_emPack_64x64                                     *
* Dimensions:  64 * 64                                               *
* NumColors:   256                                                   *
---------------------------END-OF-HEADER------------------------------
*/

#include <stdlib.h>

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

extern GUI_CONST_STORAGE GUI_BITMAP bmIcon_emPack_64x64;

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
static GUI_CONST_STORAGE GUI_COLOR _ColorsIcon_emPack_64x64[] = {
#if (GUI_USE_ARGB == 0)
  0x00FFFFFF, 0x00FFFFFF, 0x00A85C00, 0x001D1817,
  0x00FAFAFA, 0x00D1A979, 0x00F1E5D7, 0x00AE6711,
  0x00CDA26D, 0x00D2AA7A, 0x00B26E1C, 0x00D1A877,
  0x00BE8540, 0x00FEFCFB, 0x00B7782C, 0x00DEC19E,
  0x00C49052, 0x00FDFCFA, 0x00B97C32, 0x00D5B185,
  0x00FEFEFD, 0x00FFFEFE, 0x00E2C9AA, 0x00CEA26E,
  0x00D6B388, 0x00D9B890, 0x00FEFDFC, 0x00CA9B63,
  0x00CDA16C, 0x00EBD9C3, 0x00A85D01, 0x00B97D33,
  0x00C28D4C, 0x00C59255, 0x00CA9C64, 0x00EBDAC5,
  0x00F2E6D8, 0x001C1817, 0x00A95D02, 0x00AA5F05,
  0x00BB8039, 0x00BC823B, 0x00BF8744, 0x00C8975D,
  0x00CB9D66, 0x00E5CEB2, 0x00F7F0E7, 0x00F7F0E8,
  0x00FBF7F2, 0x001D1414, 0x00A95F04, 0x00B3701F,
  0x00B47222, 0x00B87A2F, 0x00BC813A, 0x00C69458,
  0x00D0A674, 0x00E0C5A4, 0x00E8D4BB, 0x00F2F1F1,
  0x001E1817, 0x00A95E03, 0x00AA6006, 0x00AA6007,
  0x00B7772B, 0x00C99B62, 0x00CC9F69, 0x00D1A978,
  0x00D3AC7D, 0x00D4AF82, 0x00D5B083, 0x00D6B286,
  0x00DAB992, 0x00DBBB95, 0x00E0C5A5, 0x00E1C7A7,
  0x00E7D3BA, 0x00EAD7C1, 0x00FAF6F1, 0x00FCF9F6,
  0x005C5858, 0x00AC630B, 0x00AC640C, 0x00AD650E,
  0x00AD6610, 0x00AE6812, 0x00AE6813, 0x00B16C19,
  0x00B37121, 0x00B57425, 0x00B57527, 0x00B67628,
  0x00B6772A, 0x00BA7D34, 0x00BC823C, 0x00C18A48,
  0x00C18B4A, 0x00C38E4E, 0x00C49153, 0x00C59356,
  0x00C69457, 0x00C69559, 0x00C8985E, 0x00C8995F,
  0x00CB9E67, 0x00CDA06B, 0x00CEA470, 0x00D0A775,
  0x00D4AE81, 0x00D7B389, 0x00D8B78F, 0x00D9B991,
  0x00DBBC96, 0x00DFC4A2, 0x00E8D4BC, 0x00E9D5BE,
  0x00EBD9C4, 0x00EEDFCD, 0x00F1E5D6, 0x00F3E8DB,
  0x00F3E9DC, 0x00F4EADE, 0x00F6EEE5, 0x00F7F1E9,
  0x00F8F2EA, 0x00F9F3ED, 0x00FAF5EF, 0x00F2F2F2,
  0x00F4F4F4, 0x00FCF9F5, 0x005E5A59, 0x005E5C5A,
  0x00AB6108, 0x00AB620A, 0x00AD660F, 0x00AF6914,
  0x00AF6915, 0x00B06A16, 0x00B06B17, 0x00B16D1A,
  0x00B16D1B, 0x00B26F1D, 0x00B26F1F, 0x00B47223,
  0x00B47324, 0x00B57426, 0x00B7792E, 0x00BA7F36,
  0x00BB7F37, 0x00BD843F, 0x00BF8642, 0x00C08845,
  0x00C08946, 0x00C08947, 0x00C08A47, 0x00C18B49,
  0x00C18C4B, 0x00C28C4C, 0x00C28D4D, 0x00C59154,
  0x00C59254, 0x00C7975C, 0x00C8985D, 0x00C99961,
  0x00C99A60, 0x00C99A61, 0x00CA9D65, 0x00CB9E66,
  0x00CC9F68, 0x00CCA06A, 0x00CDA36F, 0x00CEA36E,
  0x00CEA471, 0x00CFA572, 0x00D0A978, 0x00D2A97A,
  0x00D2AB7C, 0x00D3AB7C, 0x00D3AC7E, 0x00D3AD7E,
  0x00D3AD7F, 0x00D4AD7F, 0x00D3AD80, 0x00D3AE81,
  0x00D4AE80, 0x00D5AF82, 0x00D4B084, 0x00D5B184,
  0x00D6B287, 0x00D7B489, 0x00D7B48A, 0x00D7B58B,
  0x00D8B58B, 0x00D8B68D, 0x00D8B68E, 0x00D8B78E,
  0x00DBB992, 0x00DAB993, 0x00DABA93, 0x00DBBB94,
  0x00DBBC95, 0x00DBBD97, 0x00DCBC97, 0x00DCBD97,
  0x00DCBD98, 0x00DCBE99, 0x00DCBF9A, 0x00DDC09C,
  0x00DDC09D, 0x00DEC09D, 0x00DEC19D, 0x00DEC29F,
  0x00DEC2A0, 0x00DFC2A0, 0x00DFC3A0, 0x00DEC2A1,
  0x00DEC3A1, 0x00DFC3A1, 0x00E0C3A1, 0x00E1C6A6,
  0x00E2C8A9, 0x00E2C9AB, 0x00E3C9AB, 0x00E3CAAC,
  0x00E3CBAE, 0x00E4CBAF, 0x00E4CCAF, 0x00E5CDB2,
  0x00E6D1B7, 0x00E8D5BD, 0x00E9D6BF, 0x00EAD7C0,
  0x00EAD8C2, 0x00EDDCC9, 0x00EDDECB, 0x00EEDECC,
  0x00EEE0CE, 0x00EFE0CF, 0x00EFE1D0, 0x00EFE2D1,
  0x00F0E2D2, 0x00F0E3D3, 0x00F0E4D4, 0x00F0E4D5,
  0x00F1E4D5, 0x00F2E7DA, 0x00F3E9DD, 0x00F4EBE0,
  0x00F6EEE4, 0x00F8F2EB, 0x00F9F3EC, 0x00FAF5F0,
  0x00FBF7F3, 0x00FBF8F4, 0x00FDFBF8, 0x00FDFBF9
#else
  0xFFFFFFFF, 0xFFFFFFFF, 0xFF005CA8, 0xFF17181D,
  0xFFFAFAFA, 0xFF79A9D1, 0xFFD7E5F1, 0xFF1167AE,
  0xFF6DA2CD, 0xFF7AAAD2, 0xFF1C6EB2, 0xFF77A8D1,
  0xFF4085BE, 0xFFFBFCFE, 0xFF2C78B7, 0xFF9EC1DE,
  0xFF5290C4, 0xFFFAFCFD, 0xFF327CB9, 0xFF85B1D5,
  0xFFFDFEFE, 0xFFFEFEFF, 0xFFAAC9E2, 0xFF6EA2CE,
  0xFF88B3D6, 0xFF90B8D9, 0xFFFCFDFE, 0xFF639BCA,
  0xFF6CA1CD, 0xFFC3D9EB, 0xFF015DA8, 0xFF337DB9,
  0xFF4C8DC2, 0xFF5592C5, 0xFF649CCA, 0xFFC5DAEB,
  0xFFD8E6F2, 0xFF17181C, 0xFF025DA9, 0xFF055FAA,
  0xFF3980BB, 0xFF3B82BC, 0xFF4487BF, 0xFF5D97C8,
  0xFF669DCB, 0xFFB2CEE5, 0xFFE7F0F7, 0xFFE8F0F7,
  0xFFF2F7FB, 0xFF14141D, 0xFF045FA9, 0xFF1F70B3,
  0xFF2272B4, 0xFF2F7AB8, 0xFF3A81BC, 0xFF5894C6,
  0xFF74A6D0, 0xFFA4C5E0, 0xFFBBD4E8, 0xFFF1F1F2,
  0xFF17181E, 0xFF035EA9, 0xFF0660AA, 0xFF0760AA,
  0xFF2B77B7, 0xFF629BC9, 0xFF699FCC, 0xFF78A9D1,
  0xFF7DACD3, 0xFF82AFD4, 0xFF83B0D5, 0xFF86B2D6,
  0xFF92B9DA, 0xFF95BBDB, 0xFFA5C5E0, 0xFFA7C7E1,
  0xFFBAD3E7, 0xFFC1D7EA, 0xFFF1F6FA, 0xFFF6F9FC,
  0xFF58585C, 0xFF0B63AC, 0xFF0C64AC, 0xFF0E65AD,
  0xFF1066AD, 0xFF1268AE, 0xFF1368AE, 0xFF196CB1,
  0xFF2171B3, 0xFF2574B5, 0xFF2775B5, 0xFF2876B6,
  0xFF2A77B6, 0xFF347DBA, 0xFF3C82BC, 0xFF488AC1,
  0xFF4A8BC1, 0xFF4E8EC3, 0xFF5391C4, 0xFF5693C5,
  0xFF5794C6, 0xFF5995C6, 0xFF5E98C8, 0xFF5F99C8,
  0xFF679ECB, 0xFF6BA0CD, 0xFF70A4CE, 0xFF75A7D0,
  0xFF81AED4, 0xFF89B3D7, 0xFF8FB7D8, 0xFF91B9D9,
  0xFF96BCDB, 0xFFA2C4DF, 0xFFBCD4E8, 0xFFBED5E9,
  0xFFC4D9EB, 0xFFCDDFEE, 0xFFD6E5F1, 0xFFDBE8F3,
  0xFFDCE9F3, 0xFFDEEAF4, 0xFFE5EEF6, 0xFFE9F1F7,
  0xFFEAF2F8, 0xFFEDF3F9, 0xFFEFF5FA, 0xFFF2F2F2,
  0xFFF4F4F4, 0xFFF5F9FC, 0xFF595A5E, 0xFF5A5C5E,
  0xFF0861AB, 0xFF0A62AB, 0xFF0F66AD, 0xFF1469AF,
  0xFF1569AF, 0xFF166AB0, 0xFF176BB0, 0xFF1A6DB1,
  0xFF1B6DB1, 0xFF1D6FB2, 0xFF1F6FB2, 0xFF2372B4,
  0xFF2473B4, 0xFF2674B5, 0xFF2E79B7, 0xFF367FBA,
  0xFF377FBB, 0xFF3F84BD, 0xFF4286BF, 0xFF4588C0,
  0xFF4689C0, 0xFF4789C0, 0xFF478AC0, 0xFF498BC1,
  0xFF4B8CC1, 0xFF4C8CC2, 0xFF4D8DC2, 0xFF5491C5,
  0xFF5492C5, 0xFF5C97C7, 0xFF5D98C8, 0xFF6199C9,
  0xFF609AC9, 0xFF619AC9, 0xFF659DCA, 0xFF669ECB,
  0xFF689FCC, 0xFF6AA0CC, 0xFF6FA3CD, 0xFF6EA3CE,
  0xFF71A4CE, 0xFF72A5CF, 0xFF78A9D0, 0xFF7AA9D2,
  0xFF7CABD2, 0xFF7CABD3, 0xFF7EACD3, 0xFF7EADD3,
  0xFF7FADD3, 0xFF7FADD4, 0xFF80ADD3, 0xFF81AED3,
  0xFF80AED4, 0xFF82AFD5, 0xFF84B0D4, 0xFF84B1D5,
  0xFF87B2D6, 0xFF89B4D7, 0xFF8AB4D7, 0xFF8BB5D7,
  0xFF8BB5D8, 0xFF8DB6D8, 0xFF8EB6D8, 0xFF8EB7D8,
  0xFF92B9DB, 0xFF93B9DA, 0xFF93BADA, 0xFF94BBDB,
  0xFF95BCDB, 0xFF97BDDB, 0xFF97BCDC, 0xFF97BDDC,
  0xFF98BDDC, 0xFF99BEDC, 0xFF9ABFDC, 0xFF9CC0DD,
  0xFF9DC0DD, 0xFF9DC0DE, 0xFF9DC1DE, 0xFF9FC2DE,
  0xFFA0C2DE, 0xFFA0C2DF, 0xFFA0C3DF, 0xFFA1C2DE,
  0xFFA1C3DE, 0xFFA1C3DF, 0xFFA1C3E0, 0xFFA6C6E1,
  0xFFA9C8E2, 0xFFABC9E2, 0xFFABC9E3, 0xFFACCAE3,
  0xFFAECBE3, 0xFFAFCBE4, 0xFFAFCCE4, 0xFFB2CDE5,
  0xFFB7D1E6, 0xFFBDD5E8, 0xFFBFD6E9, 0xFFC0D7EA,
  0xFFC2D8EA, 0xFFC9DCED, 0xFFCBDEED, 0xFFCCDEEE,
  0xFFCEE0EE, 0xFFCFE0EF, 0xFFD0E1EF, 0xFFD1E2EF,
  0xFFD2E2F0, 0xFFD3E3F0, 0xFFD4E4F0, 0xFFD5E4F0,
  0xFFD5E4F1, 0xFFDAE7F2, 0xFFDDE9F3, 0xFFE0EBF4,
  0xFFE4EEF6, 0xFFEBF2F8, 0xFFECF3F9, 0xFFF0F5FA,
  0xFFF3F7FB, 0xFFF4F8FB, 0xFFF8FBFD, 0xFFF9FBFD
#endif

};

static GUI_CONST_STORAGE GUI_LOGPALETTE _PalIcon_emPack_64x64 = {
  256,  // Number of entries
  1,    // Has transparency
  &_ColorsIcon_emPack_64x64[0]
};

static GUI_CONST_STORAGE unsigned char _acIcon_emPack_64x64[] = {
  /* ABS: 002 Pixels @ 000,000 */ 0, 2, 0x31, 0x3C, 
  /* RLE: 060 Pixels @ 002,000 */ 60, 0x03, 
  /* ABS: 005 Pixels @ 062,000 */ 0, 5, 0x25, 0x31, 0x3C, 0x83, 0x80, 
  /* RLE: 058 Pixels @ 003,001 */ 58, 0x01, 
  /* ABS: 005 Pixels @ 061,001 */ 0, 5, 0x80, 0x82, 0x25, 0x03, 0x3B, 
  /* RLE: 060 Pixels @ 002,002 */ 60, 0x01, 
  /* ABS: 004 Pixels @ 062,002 */ 0, 4, 0x3B, 0x03, 0x03, 0x04, 
  /* RLE: 060 Pixels @ 002,003 */ 60, 0x01, 
  /* ABS: 004 Pixels @ 062,003 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 060 Pixels @ 002,004 */ 60, 0x01, 
  /* ABS: 004 Pixels @ 062,004 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 060 Pixels @ 002,005 */ 60, 0x01, 
  /* ABS: 004 Pixels @ 062,005 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 060 Pixels @ 002,006 */ 60, 0x01, 
  /* ABS: 004 Pixels @ 062,006 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 060 Pixels @ 002,007 */ 60, 0x01, 
  /* ABS: 004 Pixels @ 062,007 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 060 Pixels @ 002,008 */ 60, 0x01, 
  /* ABS: 004 Pixels @ 062,008 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 043 Pixels @ 002,009 */ 43, 0x01, 
  /* ABS: 012 Pixels @ 045,009 */ 0, 12, 0x4E, 0xEA, 0x39, 0xB0, 0x63, 0x35, 0x86, 0x33, 0x5E, 0x43, 0x72, 0x11, 
  /* RLE: 005 Pixels @ 057,009 */ 5, 0x01, 
  /* ABS: 004 Pixels @ 062,009 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 041 Pixels @ 002,010 */ 41, 0x01, 
  /* ABS: 014 Pixels @ 043,010 */ 0, 14, 0xE1, 0xB1, 0xA5, 0x9D, 0x40, 0x33, 0x5F, 0x38, 0xC2, 0xC7, 0x6D, 0x2B, 0x1F, 0x45, 
  /* RLE: 005 Pixels @ 057,010 */ 5, 0x01, 
  /* ABS: 004 Pixels @ 062,010 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 041 Pixels @ 002,011 */ 41, 0x01, 
  /* ABS: 008 Pixels @ 043,011 */ 0, 8, 0x60, 0x02, 0x02, 0x84, 0x37, 0x0F, 0x5D, 0x85, 
  /* RLE: 005 Pixels @ 051,011 */ 5, 0x02, 
  /* RLE: 001 Pixels @ 056,011 */ 1, 0x05, 
  /* RLE: 005 Pixels @ 057,011 */ 5, 0x01, 
  /* ABS: 004 Pixels @ 062,011 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 041 Pixels @ 002,012 */ 41, 0x01, 
  /* ABS: 006 Pixels @ 043,012 */ 0, 6, 0x97, 0x02, 0x02, 0x02, 0x36, 0x08, 
  /* RLE: 007 Pixels @ 049,012 */ 7, 0x02, 
  /* RLE: 001 Pixels @ 056,012 */ 1, 0x05, 
  /* RLE: 005 Pixels @ 057,012 */ 5, 0x01, 
  /* ABS: 004 Pixels @ 062,012 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 041 Pixels @ 002,013 */ 41, 0x01, 
  /* ABS: 006 Pixels @ 043,013 */ 0, 6, 0x0C, 0x02, 0x02, 0x02, 0x36, 0x08, 
  /* RLE: 007 Pixels @ 049,013 */ 7, 0x02, 
  /* RLE: 001 Pixels @ 056,013 */ 1, 0x05, 
  /* RLE: 005 Pixels @ 057,013 */ 5, 0x01, 
  /* ABS: 004 Pixels @ 062,013 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 041 Pixels @ 002,014 */ 41, 0x01, 
  /* ABS: 006 Pixels @ 043,014 */ 0, 6, 0x5E, 0x02, 0x02, 0x02, 0x36, 0x08, 
  /* RLE: 007 Pixels @ 049,014 */ 7, 0x02, 
  /* RLE: 001 Pixels @ 056,014 */ 1, 0x05, 
  /* RLE: 005 Pixels @ 057,014 */ 5, 0x01, 
  /* ABS: 004 Pixels @ 062,014 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 025 Pixels @ 002,015 */ 25, 0x01, 
  /* ABS: 022 Pixels @ 027,015 */ 0, 22, 0x7E, 0xF2, 0xF5, 0x4F, 0x01, 0x01, 0x01, 0x7C, 0x4A, 0x41, 0x28, 0x8A, 0x90, 0x98, 0x68, 0x71, 0x12, 0x02, 0x02, 0x02, 0x29, 0x08, 
  /* RLE: 005 Pixels @ 049,015 */ 5, 0x02, 
  /* ABS: 003 Pixels @ 054,015 */ 0, 3, 0x26, 0x35, 0x16, 
  /* RLE: 005 Pixels @ 057,015 */ 5, 0x01, 
  /* ABS: 004 Pixels @ 062,015 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 016 Pixels @ 002,016 */ 16, 0x01, 
  /* ABS: 037 Pixels @ 018,016 */ 0, 37, 0x2F, 0x75, 0x2D, 0x49, 0x09, 0x66, 0x66, 0x6B, 0xAB, 0xA7, 0xA2, 0x38, 0x47, 0xBB, 0x6A, 0x65, 0x92, 0x5C, 0x9F, 0x44, 0x6D, 0xC4, 0x6E, 0x46, 0x22, 0x57, 0x32, 0x02, 0x02, 0x29, 0x08, 0x02, 0x32, 0x1F, 0x17, 
        0x16, 0x7D, 
  /* RLE: 007 Pixels @ 055,016 */ 7, 0x01, 
  /* ABS: 004 Pixels @ 062,016 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 006 Pixels @ 002,017 */ 6, 0x01, 
  /* ABS: 027 Pixels @ 008,017 */ 0, 27, 0xFE, 0x79, 0x1D, 0x4B, 0xC3, 0xD1, 0x4C, 0x4B, 0x05, 0x36, 0x35, 0x9C, 0x67, 0x42, 0x69, 0x68, 0x69, 0xA9, 0xA3, 0x20, 0x0E, 0x93, 0xA8, 0x48, 0x39, 0x47, 0x5A, 
  /* RLE: 004 Pixels @ 035,017 */ 4, 0x02, 
  /* ABS: 012 Pixels @ 039,017 */ 0, 12, 0xBA, 0x02, 0x02, 0x02, 0x07, 0x81, 0x4D, 0x18, 0x44, 0xE5, 0x73, 0x81, 
  /* RLE: 011 Pixels @ 051,017 */ 11, 0x01, 
  /* ABS: 004 Pixels @ 062,017 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,018 */ 5, 0x01, 
  /* ABS: 028 Pixels @ 007,018 */ 0, 28, 0xE9, 0xD4, 0xD6, 0xBF, 0x1B, 0x28, 0x54, 0x02, 0x02, 0x53, 0x1F, 0x37, 0xAC, 0x18, 0xC8, 0x43, 0xAD, 0xC0, 0x44, 0xAA, 0xA4, 0x96, 0x58, 0x32, 0x02, 0x88, 0x28, 0x8E, 
  /* RLE: 004 Pixels @ 035,018 */ 4, 0x02, 
  /* ABS: 005 Pixels @ 039,018 */ 0, 5, 0x46, 0x02, 0x02, 0x02, 0x07, 
  /* RLE: 018 Pixels @ 044,018 */ 18, 0x01, 
  /* ABS: 004 Pixels @ 062,018 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,019 */ 5, 0x01, 
  /* ABS: 028 Pixels @ 007,019 */ 0, 28, 0x05, 0x02, 0x02, 0x52, 0x5D, 0x2B, 0xBC, 0xD0, 0xD8, 0xCE, 0xE2, 0xDE, 0xB5, 0x61, 0x0E, 0x51, 0x87, 0x28, 0x67, 0xAE, 0x6C, 0xB9, 0xD7, 0xEB, 0xFB, 0x01, 0x01, 0x62, 
  /* RLE: 004 Pixels @ 035,019 */ 4, 0x02, 
  /* ABS: 005 Pixels @ 039,019 */ 0, 5, 0x45, 0x02, 0x02, 0x02, 0x07, 
  /* RLE: 018 Pixels @ 044,019 */ 18, 0x01, 
  /* ABS: 004 Pixels @ 062,019 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,020 */ 5, 0x01, 
  /* RLE: 001 Pixels @ 007,020 */ 1, 0x05, 
  /* RLE: 008 Pixels @ 008,020 */ 8, 0x02, 
  /* ABS: 019 Pixels @ 016,020 */ 0, 19, 0x06, 0x70, 0x21, 0xB3, 0xD2, 0xDA, 0xC9, 0x38, 0x60, 0x58, 0x26, 0x02, 0x02, 0x02, 0x8C, 0x99, 0x48, 0xF7, 0x62, 
  /* RLE: 004 Pixels @ 035,020 */ 4, 0x02, 
  /* ABS: 005 Pixels @ 039,020 */ 0, 5, 0xB7, 0x02, 0x02, 0x02, 0x07, 
  /* RLE: 018 Pixels @ 044,020 */ 18, 0x01, 
  /* ABS: 004 Pixels @ 062,020 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,021 */ 5, 0x01, 
  /* RLE: 001 Pixels @ 007,021 */ 1, 0x05, 
  /* RLE: 008 Pixels @ 008,021 */ 8, 0x02, 
  /* ABS: 002 Pixels @ 016,021 */ 0, 2, 0x06, 0x09, 
  /* RLE: 004 Pixels @ 018,021 */ 4, 0x02, 
  /* ABS: 013 Pixels @ 022,021 */ 0, 13, 0x26, 0x8F, 0x20, 0x6B, 0xCA, 0x71, 0x0F, 0xC5, 0x6E, 0xAF, 0xA0, 0x5C, 0x9A, 
  /* RLE: 004 Pixels @ 035,021 */ 4, 0x02, 
  /* ABS: 005 Pixels @ 039,021 */ 0, 5, 0xB6, 0x02, 0x02, 0x02, 0x07, 
  /* RLE: 018 Pixels @ 044,021 */ 18, 0x01, 
  /* ABS: 004 Pixels @ 062,021 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,022 */ 5, 0x01, 
  /* RLE: 001 Pixels @ 007,022 */ 1, 0x05, 
  /* RLE: 008 Pixels @ 008,022 */ 8, 0x02, 
  /* ABS: 002 Pixels @ 016,022 */ 0, 2, 0x06, 0x09, 
  /* RLE: 010 Pixels @ 018,022 */ 10, 0x02, 
  /* ABS: 002 Pixels @ 028,022 */ 0, 2, 0x13, 0x0E, 
  /* RLE: 004 Pixels @ 030,022 */ 4, 0x02, 
  /* ABS: 010 Pixels @ 034,022 */ 0, 10, 0xE3, 0xBE, 0x61, 0x56, 0x02, 0xB2, 0x02, 0x56, 0x9E, 0xC1, 
  /* RLE: 018 Pixels @ 044,022 */ 18, 0x01, 
  /* ABS: 004 Pixels @ 062,022 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,023 */ 5, 0x01, 
  /* RLE: 001 Pixels @ 007,023 */ 1, 0x05, 
  /* RLE: 008 Pixels @ 008,023 */ 8, 0x02, 
  /* ABS: 002 Pixels @ 016,023 */ 0, 2, 0x06, 0x09, 
  /* RLE: 010 Pixels @ 018,023 */ 10, 0x02, 
  /* ABS: 002 Pixels @ 028,023 */ 0, 2, 0x13, 0x0E, 
  /* RLE: 004 Pixels @ 030,023 */ 4, 0x02, 
  /* ABS: 008 Pixels @ 034,023 */ 0, 8, 0x24, 0x01, 0x01, 0x15, 0xF4, 0xF3, 0x76, 0x15, 
  /* RLE: 020 Pixels @ 042,023 */ 20, 0x01, 
  /* ABS: 004 Pixels @ 062,023 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,024 */ 5, 0x01, 
  /* ABS: 005 Pixels @ 007,024 */ 0, 5, 0x7B, 0x16, 0x6A, 0x94, 0x27, 
  /* RLE: 004 Pixels @ 012,024 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 016,024 */ 0, 2, 0x06, 0x09, 
  /* RLE: 010 Pixels @ 018,024 */ 10, 0x02, 
  /* ABS: 002 Pixels @ 028,024 */ 0, 2, 0x13, 0x0E, 
  /* RLE: 004 Pixels @ 030,024 */ 4, 0x02, 
  /* RLE: 001 Pixels @ 034,024 */ 1, 0x24, 
  /* RLE: 027 Pixels @ 035,024 */ 27, 0x01, 
  /* ABS: 004 Pixels @ 062,024 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,025 */ 5, 0x01, 
  /* ABS: 011 Pixels @ 007,025 */ 0, 11, 0xFC, 0x01, 0x01, 0x01, 0x4F, 0x40, 0x02, 0x02, 0x02, 0x06, 0x09, 
  /* RLE: 010 Pixels @ 018,025 */ 10, 0x02, 
  /* ABS: 002 Pixels @ 028,025 */ 0, 2, 0x13, 0x0E, 
  /* RLE: 004 Pixels @ 030,025 */ 4, 0x02, 
  /* RLE: 001 Pixels @ 034,025 */ 1, 0x24, 
  /* RLE: 014 Pixels @ 035,025 */ 14, 0x01, 
  /* RLE: 001 Pixels @ 049,025 */ 1, 0xFA, 
  /* RLE: 012 Pixels @ 050,025 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,025 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,026 */ 5, 0x01, 
  /* ABS: 014 Pixels @ 007,026 */ 0, 14, 0x05, 0x57, 0x37, 0x70, 0x15, 0x12, 0x02, 0x02, 0x02, 0x06, 0x23, 0xA6, 0x40, 0x26, 
  /* RLE: 007 Pixels @ 021,026 */ 7, 0x02, 
  /* ABS: 002 Pixels @ 028,026 */ 0, 2, 0x13, 0x0E, 
  /* RLE: 004 Pixels @ 030,026 */ 4, 0x02, 
  /* RLE: 001 Pixels @ 034,026 */ 1, 0x24, 
  /* RLE: 010 Pixels @ 035,026 */ 10, 0x01, 
  /* ABS: 005 Pixels @ 045,026 */ 0, 5, 0x2F, 0x16, 0x17, 0x1F, 0x8D, 
  /* RLE: 012 Pixels @ 050,026 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,026 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,027 */ 5, 0x01, 
  /* ABS: 028 Pixels @ 007,027 */ 0, 28, 0x05, 0x02, 0x02, 0x02, 0x11, 0x12, 0x02, 0x02, 0x02, 0x06, 0x01, 0x01, 0x01, 0x30, 0x1D, 0x18, 0x20, 0x07, 0x02, 0x02, 0x02, 0x13, 0x0E, 0x02, 0x02, 0x3D, 0x35, 0x7A, 
  /* RLE: 006 Pixels @ 035,027 */ 6, 0x01, 
  /* ABS: 004 Pixels @ 041,027 */ 0, 4, 0x2E, 0xDB, 0x2C, 0x5A, 
  /* RLE: 004 Pixels @ 045,027 */ 4, 0x02, 
  /* RLE: 001 Pixels @ 049,027 */ 1, 0x0A, 
  /* RLE: 012 Pixels @ 050,027 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,027 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,028 */ 5, 0x01, 
  /* ABS: 026 Pixels @ 007,028 */ 0, 26, 0x05, 0x02, 0x02, 0x02, 0x11, 0x12, 0x02, 0x02, 0x02, 0x06, 0xDF, 0x6F, 0xEF, 0x14, 0x01, 0x01, 0x01, 0x1A, 0xED, 0x49, 0xA1, 0xCF, 0x42, 0xB4, 0x4C, 0x30, 
  /* RLE: 004 Pixels @ 033,028 */ 4, 0x01, 
  /* ABS: 005 Pixels @ 037,028 */ 0, 5, 0x7A, 0x4A, 0x2C, 0x1A, 0x10, 
  /* RLE: 007 Pixels @ 042,028 */ 7, 0x02, 
  /* RLE: 001 Pixels @ 049,028 */ 1, 0x0A, 
  /* RLE: 012 Pixels @ 050,028 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,028 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,029 */ 5, 0x01, 
  /* ABS: 018 Pixels @ 007,029 */ 0, 18, 0x05, 0x02, 0x02, 0x02, 0x11, 0x12, 0x02, 0x02, 0x02, 0x06, 0x09, 0x02, 0x02, 0x55, 0x65, 0x01, 0x7C, 0x14, 
  /* RLE: 008 Pixels @ 025,029 */ 8, 0x01, 
  /* ABS: 009 Pixels @ 033,029 */ 0, 9, 0x2F, 0x16, 0x17, 0x1F, 0x1E, 0x02, 0x02, 0x0D, 0x10, 
  /* RLE: 007 Pixels @ 042,029 */ 7, 0x02, 
  /* RLE: 001 Pixels @ 049,029 */ 1, 0x0A, 
  /* RLE: 012 Pixels @ 050,029 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,029 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,030 */ 5, 0x01, 
  /* ABS: 027 Pixels @ 007,030 */ 0, 27, 0x05, 0x02, 0x02, 0x02, 0x11, 0x12, 0x02, 0x02, 0x02, 0x06, 0x09, 0x02, 0x02, 0x02, 0x07, 0x01, 0x1C, 0x52, 0x2A, 0x18, 0x1D, 0xFF, 0x2F, 0x16, 0x17, 0x1F, 0x1E, 
  /* RLE: 006 Pixels @ 034,030 */ 6, 0x02, 
  /* ABS: 002 Pixels @ 040,030 */ 0, 2, 0x0D, 0x10, 
  /* RLE: 007 Pixels @ 042,030 */ 7, 0x02, 
  /* RLE: 001 Pixels @ 049,030 */ 1, 0x0A, 
  /* RLE: 012 Pixels @ 050,030 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,030 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,031 */ 5, 0x01, 
  /* ABS: 017 Pixels @ 007,031 */ 0, 17, 0xE7, 0x9B, 0x3F, 0x02, 0x11, 0x12, 0x02, 0x02, 0x02, 0x06, 0x09, 0x02, 0x02, 0x02, 0x07, 0x01, 0x1C, 
  /* RLE: 004 Pixels @ 024,031 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 028,031 */ 0, 2, 0x47, 0x0E, 
  /* RLE: 010 Pixels @ 030,031 */ 10, 0x02, 
  /* ABS: 002 Pixels @ 040,031 */ 0, 2, 0x0D, 0x10, 
  /* RLE: 007 Pixels @ 042,031 */ 7, 0x02, 
  /* RLE: 001 Pixels @ 049,031 */ 1, 0x0A, 
  /* RLE: 012 Pixels @ 050,031 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,031 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 007 Pixels @ 002,032 */ 7, 0x01, 
  /* ABS: 015 Pixels @ 009,032 */ 0, 15, 0x30, 0xDC, 0x14, 0x28, 0x02, 0x02, 0x02, 0x06, 0x09, 0x02, 0x02, 0x02, 0x07, 0x01, 0x1C, 
  /* RLE: 004 Pixels @ 024,032 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 028,032 */ 0, 2, 0x13, 0x0E, 
  /* RLE: 010 Pixels @ 030,032 */ 10, 0x02, 
  /* ABS: 002 Pixels @ 040,032 */ 0, 2, 0x0D, 0x10, 
  /* RLE: 007 Pixels @ 042,032 */ 7, 0x02, 
  /* RLE: 001 Pixels @ 049,032 */ 1, 0x0A, 
  /* RLE: 012 Pixels @ 050,032 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,032 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,033 */ 5, 0x01, 
  /* ABS: 017 Pixels @ 007,033 */ 0, 17, 0x49, 0x43, 0x75, 0x01, 0x01, 0x1A, 0x1D, 0x17, 0x0A, 0x06, 0x09, 0x02, 0x02, 0x02, 0x07, 0x01, 0x1C, 
  /* RLE: 004 Pixels @ 024,033 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 028,033 */ 0, 2, 0x13, 0x0E, 
  /* RLE: 010 Pixels @ 030,033 */ 10, 0x02, 
  /* ABS: 002 Pixels @ 040,033 */ 0, 2, 0x0D, 0x10, 
  /* RLE: 007 Pixels @ 042,033 */ 7, 0x02, 
  /* RLE: 001 Pixels @ 049,033 */ 1, 0x0A, 
  /* RLE: 012 Pixels @ 050,033 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,033 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,034 */ 5, 0x01, 
  /* ABS: 017 Pixels @ 007,034 */ 0, 17, 0x05, 0x02, 0x02, 0x33, 0x17, 0x1D, 0x15, 0x01, 0x15, 0x1A, 0x09, 0x02, 0x02, 0x02, 0x07, 0x01, 0x1C, 
  /* RLE: 004 Pixels @ 024,034 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 028,034 */ 0, 2, 0x13, 0x0E, 
  /* RLE: 010 Pixels @ 030,034 */ 10, 0x02, 
  /* ABS: 002 Pixels @ 040,034 */ 0, 2, 0x0D, 0x10, 
  /* RLE: 007 Pixels @ 042,034 */ 7, 0x02, 
  /* RLE: 001 Pixels @ 049,034 */ 1, 0x0A, 
  /* RLE: 012 Pixels @ 050,034 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,034 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,035 */ 5, 0x01, 
  /* RLE: 001 Pixels @ 007,035 */ 1, 0x05, 
  /* RLE: 005 Pixels @ 008,035 */ 5, 0x02, 
  /* ABS: 011 Pixels @ 013,035 */ 0, 11, 0x33, 0x17, 0x1D, 0x15, 0x09, 0x02, 0x02, 0x02, 0x07, 0x01, 0x1C, 
  /* RLE: 004 Pixels @ 024,035 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 028,035 */ 0, 2, 0x13, 0x0E, 
  /* RLE: 010 Pixels @ 030,035 */ 10, 0x02, 
  /* ABS: 002 Pixels @ 040,035 */ 0, 2, 0x0D, 0x10, 
  /* RLE: 007 Pixels @ 042,035 */ 7, 0x02, 
  /* RLE: 001 Pixels @ 049,035 */ 1, 0x0A, 
  /* RLE: 012 Pixels @ 050,035 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,035 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,036 */ 5, 0x01, 
  /* RLE: 001 Pixels @ 007,036 */ 1, 0x05, 
  /* RLE: 008 Pixels @ 008,036 */ 8, 0x02, 
  /* ABS: 020 Pixels @ 016,036 */ 0, 20, 0x06, 0x09, 0x02, 0x02, 0x02, 0x07, 0x01, 0x4C, 0x5F, 0x3E, 0x02, 0x02, 0x13, 0x0E, 0x02, 0x02, 0x54, 0x63, 0xD5, 0xBD, 
  /* RLE: 004 Pixels @ 036,036 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 040,036 */ 0, 2, 0x0D, 0x10, 
  /* RLE: 007 Pixels @ 042,036 */ 7, 0x02, 
  /* RLE: 001 Pixels @ 049,036 */ 1, 0x0A, 
  /* RLE: 012 Pixels @ 050,036 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,036 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,037 */ 5, 0x01, 
  /* RLE: 001 Pixels @ 007,037 */ 1, 0x05, 
  /* RLE: 008 Pixels @ 008,037 */ 8, 0x02, 
  /* ABS: 020 Pixels @ 016,037 */ 0, 20, 0x06, 0x09, 0x02, 0x02, 0x02, 0x07, 0x01, 0x01, 0x01, 0x4E, 0x4B, 0x64, 0xC6, 0x64, 0x0B, 0x4D, 0x0D, 0x01, 0x01, 0x0F, 
  /* RLE: 004 Pixels @ 036,037 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 040,037 */ 0, 2, 0x0D, 0x10, 
  /* RLE: 007 Pixels @ 042,037 */ 7, 0x02, 
  /* RLE: 001 Pixels @ 049,037 */ 1, 0x0A, 
  /* RLE: 012 Pixels @ 050,037 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,037 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,038 */ 5, 0x01, 
  /* ABS: 002 Pixels @ 007,038 */ 0, 2, 0xCB, 0x32, 
  /* RLE: 007 Pixels @ 009,038 */ 7, 0x02, 
  /* ABS: 010 Pixels @ 016,038 */ 0, 10, 0x06, 0x09, 0x02, 0x02, 0x02, 0x07, 0xD9, 0x41, 0xE4, 0x11, 
  /* RLE: 004 Pixels @ 026,038 */ 4, 0x01, 
  /* ABS: 006 Pixels @ 030,038 */ 0, 6, 0x1A, 0x72, 0x2C, 0xB8, 0x01, 0x0F, 
  /* RLE: 004 Pixels @ 036,038 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 040,038 */ 0, 2, 0x0D, 0x10, 
  /* RLE: 007 Pixels @ 042,038 */ 7, 0x02, 
  /* RLE: 001 Pixels @ 049,038 */ 1, 0x95, 
  /* RLE: 012 Pixels @ 050,038 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,038 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 006 Pixels @ 002,039 */ 6, 0x01, 
  /* ABS: 003 Pixels @ 008,039 */ 0, 3, 0x2E, 0x18, 0x34, 
  /* RLE: 005 Pixels @ 011,039 */ 5, 0x02, 
  /* ABS: 020 Pixels @ 016,039 */ 0, 20, 0x06, 0x09, 0x02, 0x02, 0x02, 0x07, 0x19, 0x02, 0x02, 0x55, 0x1B, 0xE8, 0xF0, 0x42, 0x89, 0x02, 0x02, 0x08, 0x01, 0x0F, 
  /* RLE: 004 Pixels @ 036,039 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 040,039 */ 0, 2, 0x0D, 0x10, 
  /* RLE: 004 Pixels @ 042,039 */ 4, 0x02, 
  /* ABS: 004 Pixels @ 046,039 */ 0, 4, 0x3F, 0x21, 0x3A, 0x15, 
  /* RLE: 012 Pixels @ 050,039 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,039 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,040 */ 5, 0x01, 
  /* ABS: 016 Pixels @ 007,040 */ 0, 16, 0xE6, 0x06, 0x01, 0x14, 0x3A, 0x21, 0x27, 0x02, 0x02, 0x06, 0x09, 0x02, 0x02, 0x02, 0x07, 0x19, 
  /* RLE: 004 Pixels @ 023,040 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 027,040 */ 0, 2, 0x0C, 0x0B, 
  /* RLE: 004 Pixels @ 029,040 */ 4, 0x02, 
  /* ABS: 003 Pixels @ 033,040 */ 0, 3, 0x08, 0x01, 0x0F, 
  /* RLE: 004 Pixels @ 036,040 */ 4, 0x02, 
  /* ABS: 010 Pixels @ 040,040 */ 0, 10, 0x0D, 0x10, 0x02, 0x02, 0x91, 0x18, 0xF9, 0x01, 0x30, 0x39, 
  /* RLE: 012 Pixels @ 050,040 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,040 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,041 */ 5, 0x01, 
  /* ABS: 016 Pixels @ 007,041 */ 0, 16, 0x05, 0x1E, 0x2A, 0xE0, 0x15, 0x01, 0x2E, 0x18, 0x34, 0x06, 0x09, 0x02, 0x02, 0x02, 0x07, 0x19, 
  /* RLE: 004 Pixels @ 023,041 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 027,041 */ 0, 2, 0x0C, 0x0B, 
  /* RLE: 004 Pixels @ 029,041 */ 4, 0x02, 
  /* ABS: 003 Pixels @ 033,041 */ 0, 3, 0x08, 0x01, 0x0F, 
  /* RLE: 004 Pixels @ 036,041 */ 4, 0x02, 
  /* ABS: 010 Pixels @ 040,041 */ 0, 10, 0x0D, 0x37, 0x21, 0x3A, 0x15, 0x01, 0x77, 0x1C, 0x53, 0x0A, 
  /* RLE: 012 Pixels @ 050,041 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,041 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,042 */ 5, 0x01, 
  /* ABS: 016 Pixels @ 007,042 */ 0, 16, 0x05, 0x02, 0x02, 0x02, 0x11, 0x4A, 0x7B, 0x01, 0x14, 0x0D, 0xCC, 0x27, 0x02, 0x02, 0x07, 0x19, 
  /* RLE: 004 Pixels @ 023,042 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 027,042 */ 0, 2, 0x0C, 0x0B, 
  /* RLE: 004 Pixels @ 029,042 */ 4, 0x02, 
  /* ABS: 017 Pixels @ 033,042 */ 0, 17, 0x08, 0x01, 0x0F, 0x02, 0x02, 0x02, 0x59, 0x1A, 0x11, 0x01, 0x14, 0x2D, 0x79, 0x1B, 0x02, 0x02, 0x0A, 
  /* RLE: 012 Pixels @ 050,042 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,042 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,043 */ 5, 0x01, 
  /* ABS: 016 Pixels @ 007,043 */ 0, 16, 0x05, 0x02, 0x02, 0x02, 0x11, 0x12, 0x3E, 0x21, 0x3A, 0x01, 0x01, 0x2E, 0x18, 0x34, 0x07, 0x19, 
  /* RLE: 004 Pixels @ 023,043 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 027,043 */ 0, 2, 0x0C, 0x0B, 
  /* RLE: 004 Pixels @ 029,043 */ 4, 0x02, 
  /* ABS: 017 Pixels @ 033,043 */ 0, 17, 0x08, 0x01, 0x0F, 0x3D, 0x2A, 0x2D, 0x15, 0x01, 0x4E, 0xCD, 0x5B, 0x02, 0x23, 0x1B, 0x02, 0x02, 0x0A, 
  /* RLE: 012 Pixels @ 050,043 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,043 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,044 */ 5, 0x01, 
  /* ABS: 016 Pixels @ 007,044 */ 0, 16, 0x05, 0x02, 0x02, 0x02, 0x11, 0x12, 0x02, 0x02, 0x02, 0xD3, 0x76, 0x01, 0x01, 0x14, 0x4D, 0x19, 
  /* RLE: 004 Pixels @ 023,044 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 027,044 */ 0, 2, 0x0C, 0x0B, 
  /* RLE: 004 Pixels @ 029,044 */ 4, 0x02, 
  /* ABS: 017 Pixels @ 033,044 */ 0, 17, 0x08, 0x01, 0xF6, 0x2E, 0x01, 0x01, 0x24, 0x17, 0x51, 0x02, 0x02, 0x02, 0x23, 0x1B, 0x02, 0x02, 0x0A, 
  /* RLE: 012 Pixels @ 050,044 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,044 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,045 */ 5, 0x01, 
  /* ABS: 016 Pixels @ 007,045 */ 0, 16, 0x05, 0x02, 0x02, 0x02, 0x11, 0x12, 0x02, 0x02, 0x02, 0x22, 0x02, 0x29, 0x16, 0x1A, 0x01, 0x19, 
  /* RLE: 004 Pixels @ 023,045 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 027,045 */ 0, 2, 0x0C, 0x0B, 
  /* RLE: 004 Pixels @ 029,045 */ 4, 0x02, 
  /* ABS: 007 Pixels @ 033,045 */ 0, 7, 0x08, 0x01, 0x01, 0x14, 0x2D, 0x2A, 0x1E, 
  /* RLE: 005 Pixels @ 040,045 */ 5, 0x02, 
  /* ABS: 005 Pixels @ 045,045 */ 0, 5, 0x23, 0x1B, 0x02, 0x02, 0x0A, 
  /* RLE: 012 Pixels @ 050,045 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,045 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 005 Pixels @ 002,046 */ 5, 0x01, 
  /* ABS: 016 Pixels @ 007,046 */ 0, 16, 0xFD, 0x19, 0x8B, 0x02, 0x11, 0x12, 0x02, 0x02, 0x02, 0x22, 0x02, 0x02, 0x02, 0x59, 0x6F, 0x46, 
  /* RLE: 004 Pixels @ 023,046 */ 4, 0x02, 
  /* ABS: 002 Pixels @ 027,046 */ 0, 2, 0x0C, 0x0B, 
  /* RLE: 004 Pixels @ 029,046 */ 4, 0x02, 
  /* ABS: 004 Pixels @ 033,046 */ 0, 4, 0x08, 0x01, 0x74, 0x0A, 
  /* RLE: 008 Pixels @ 037,046 */ 8, 0x02, 
  /* ABS: 005 Pixels @ 045,046 */ 0, 5, 0x23, 0x1B, 0x26, 0x20, 0xEC, 
  /* RLE: 012 Pixels @ 050,046 */ 12, 0x01, 
  /* ABS: 004 Pixels @ 062,046 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 007 Pixels @ 002,047 */ 7, 0x01, 
  /* ABS: 008 Pixels @ 009,047 */ 0, 8, 0x4F, 0x48, 0x1A, 0x12, 0x02, 0x02, 0x02, 0x22, 
  /* RLE: 010 Pixels @ 017,047 */ 10, 0x02, 
  /* ABS: 002 Pixels @ 027,047 */ 0, 2, 0x0C, 0x0B, 
  /* RLE: 004 Pixels @ 029,047 */ 4, 0x02, 
  /* ABS: 003 Pixels @ 033,047 */ 0, 3, 0x08, 0x01, 0x0F, 
  /* RLE: 009 Pixels @ 036,047 */ 9, 0x02, 
  /* ABS: 003 Pixels @ 045,047 */ 0, 3, 0x23, 0xDD, 0x24, 
  /* RLE: 014 Pixels @ 048,047 */ 14, 0x01, 
  /* ABS: 004 Pixels @ 062,047 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 010 Pixels @ 002,048 */ 10, 0x01, 
  /* ABS: 005 Pixels @ 012,048 */ 0, 5, 0x39, 0x34, 0x02, 0x02, 0x22, 
  /* RLE: 010 Pixels @ 017,048 */ 10, 0x02, 
  /* ABS: 002 Pixels @ 027,048 */ 0, 2, 0x0C, 0x0B, 
  /* RLE: 004 Pixels @ 029,048 */ 4, 0x02, 
  /* ABS: 003 Pixels @ 033,048 */ 0, 3, 0x08, 0x01, 0x0F, 
  /* RLE: 007 Pixels @ 036,048 */ 7, 0x02, 
  /* ABS: 003 Pixels @ 043,048 */ 0, 3, 0x27, 0x41, 0x7D, 
  /* RLE: 016 Pixels @ 046,048 */ 16, 0x01, 
  /* ABS: 004 Pixels @ 062,048 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 011 Pixels @ 002,049 */ 11, 0x01, 
  /* ABS: 004 Pixels @ 013,049 */ 0, 4, 0x14, 0x16, 0x5B, 0x22, 
  /* RLE: 010 Pixels @ 017,049 */ 10, 0x02, 
  /* ABS: 002 Pixels @ 027,049 */ 0, 2, 0x0C, 0x0B, 
  /* RLE: 004 Pixels @ 029,049 */ 4, 0x02, 
  /* ABS: 003 Pixels @ 033,049 */ 0, 3, 0x08, 0x01, 0x0F, 
  /* RLE: 005 Pixels @ 036,049 */ 5, 0x02, 
  /* ABS: 003 Pixels @ 041,049 */ 0, 3, 0x27, 0x2B, 0x77, 
  /* RLE: 018 Pixels @ 044,049 */ 18, 0x01, 
  /* ABS: 004 Pixels @ 062,049 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 013 Pixels @ 002,050 */ 13, 0x01, 
  /* ABS: 002 Pixels @ 015,050 */ 0, 2, 0x14, 0x45, 
  /* RLE: 010 Pixels @ 017,050 */ 10, 0x02, 
  /* ABS: 002 Pixels @ 027,050 */ 0, 2, 0x0C, 0x0B, 
  /* RLE: 004 Pixels @ 029,050 */ 4, 0x02, 
  /* ABS: 009 Pixels @ 033,050 */ 0, 9, 0x08, 0x01, 0x0F, 0x02, 0x02, 0x02, 0x3E, 0x2B, 0x78, 
  /* RLE: 020 Pixels @ 042,050 */ 20, 0x01, 
  /* ABS: 004 Pixels @ 062,050 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 015 Pixels @ 002,051 */ 15, 0x01, 
  /* ABS: 002 Pixels @ 017,051 */ 0, 2, 0x1D, 0x20, 
  /* RLE: 008 Pixels @ 019,051 */ 8, 0x02, 
  /* ABS: 002 Pixels @ 027,051 */ 0, 2, 0x0C, 0x0B, 
  /* RLE: 004 Pixels @ 029,051 */ 4, 0x02, 
  /* ABS: 007 Pixels @ 033,051 */ 0, 7, 0x08, 0x01, 0x0F, 0x02, 0x3F, 0x2C, 0xF8, 
  /* RLE: 022 Pixels @ 040,051 */ 22, 0x01, 
  /* ABS: 004 Pixels @ 062,051 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 017 Pixels @ 002,052 */ 17, 0x01, 
  /* ABS: 003 Pixels @ 019,052 */ 0, 3, 0x74, 0x20, 0x1E, 
  /* RLE: 005 Pixels @ 022,052 */ 5, 0x02, 
  /* ABS: 002 Pixels @ 027,052 */ 0, 2, 0x0C, 0x0B, 
  /* RLE: 004 Pixels @ 029,052 */ 4, 0x02, 
  /* ABS: 005 Pixels @ 033,052 */ 0, 5, 0x08, 0x01, 0x16, 0x38, 0x2F, 
  /* RLE: 024 Pixels @ 038,052 */ 24, 0x01, 
  /* ABS: 004 Pixels @ 062,052 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 019 Pixels @ 002,053 */ 19, 0x01, 
  /* ABS: 008 Pixels @ 021,053 */ 0, 8, 0xEE, 0x21, 0x1E, 0x02, 0x02, 0x02, 0x0C, 0x0B, 
  /* RLE: 004 Pixels @ 029,053 */ 4, 0x02, 
  /* RLE: 001 Pixels @ 033,053 */ 1, 0x6C, 
  /* RLE: 028 Pixels @ 034,053 */ 28, 0x01, 
  /* ABS: 004 Pixels @ 062,053 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 021 Pixels @ 002,054 */ 21, 0x01, 
  /* ABS: 010 Pixels @ 023,054 */ 0, 10, 0xF1, 0x2B, 0x3D, 0x02, 0x0C, 0x0B, 0x02, 0x02, 0x29, 0x2D, 
  /* RLE: 029 Pixels @ 033,054 */ 29, 0x01, 
  /* ABS: 004 Pixels @ 062,054 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 023 Pixels @ 002,055 */ 23, 0x01, 
  /* ABS: 006 Pixels @ 025,055 */ 0, 6, 0x78, 0x2C, 0x2A, 0x0B, 0x29, 0x73, 
  /* RLE: 031 Pixels @ 031,055 */ 31, 0x01, 
  /* ABS: 004 Pixels @ 062,055 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 025 Pixels @ 002,056 */ 25, 0x01, 
  /* ABS: 002 Pixels @ 027,056 */ 0, 2, 0x7E, 0x30, 
  /* RLE: 033 Pixels @ 029,056 */ 33, 0x01, 
  /* ABS: 004 Pixels @ 062,056 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 060 Pixels @ 002,057 */ 60, 0x01, 
  /* ABS: 004 Pixels @ 062,057 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 060 Pixels @ 002,058 */ 60, 0x01, 
  /* ABS: 004 Pixels @ 062,058 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 060 Pixels @ 002,059 */ 60, 0x01, 
  /* ABS: 004 Pixels @ 062,059 */ 0, 4, 0x04, 0x03, 0x03, 0x04, 
  /* RLE: 060 Pixels @ 002,060 */ 60, 0x01, 
  /* ABS: 004 Pixels @ 062,060 */ 0, 4, 0x04, 0x03, 0x03, 0x3B, 
  /* RLE: 060 Pixels @ 002,061 */ 60, 0x01, 
  /* ABS: 005 Pixels @ 062,061 */ 0, 5, 0x3B, 0x03, 0x3C, 0x50, 0x7F, 
  /* RLE: 058 Pixels @ 003,062 */ 58, 0x01, 
  /* ABS: 005 Pixels @ 061,062 */ 0, 5, 0x7F, 0x50, 0x25, 0x31, 0x25, 
  /* RLE: 060 Pixels @ 002,063 */ 60, 0x03, 
  /* ABS: 002 Pixels @ 062,063 */ 0, 2, 0x25, 0x31, 
  0
};  // 2072 bytes for 4096 pixels

GUI_CONST_STORAGE GUI_BITMAP bmIcon_emPack_64x64 = {
  64, // xSize
  64, // ySize
  64, // BytesPerLine
  GUI_COMPRESS_RLE8, // BitsPerPixel
  _acIcon_emPack_64x64,  // Pointer to picture data (indices)
  &_PalIcon_emPack_64x64,  // Pointer to palette
  GUI_DRAW_RLE8
};

/*************************** End of file ****************************/
