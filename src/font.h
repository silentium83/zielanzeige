#ifndef FONT_H
#define FONT_H

#include <avr/pgmspace.h>

#include <stdint.h>

struct LCDChar {
	uint8_t width;
	uint8_t columns[7];
};

const LCDChar font_var_width[256] PROGMEM = {
	{ 0, {} }, // 00 NUL
	{ 0, {} }, // 01 SOH
	{ 0, {} }, // 02 STX
	{ 0, {} }, // 03 ETX
	{ 0, {} }, // 04 EOT
	{ 0, {} }, // 05 ENQ
	{ 0, {} }, // 06 ACK
	{ 0, {} }, // 07 BEL
	{ 0, {} }, // 08 BS
	{ 0, {} }, // 09 HT
	{ 0, {} }, // 0A LF
	{ 0, {} }, // 0B VT
	{ 0, {} }, // 0C FF
	{ 0, {} }, // 0D CR
	{ 0, {} }, // 0E SO
	{ 0, {} }, // 0F SI
	{ 0, {} }, // 10 DLE
	{ 0, {} }, // 11 DC1
	{ 0, {} }, // 12 DC2
	{ 0, {} }, // 13 DC3
	{ 0, {} }, // 14 DC4
	{ 0, {} }, // 15 NAK
	{ 0, {} }, // 16 SYN
	{ 0, {} }, // 17 ETB
	{ 0, {} }, // 18 CAN
	{ 0, {} }, // 19 EM
	{ 0, {} }, // 1A SUB
	{ 0, {} }, // 1B ESC
	{ 0, {} }, // 1C FS
	{ 0, {} }, // 1D GS
	{ 0, {} }, // 1E RS
	{ 0, {} }, // 1F US
	{ 2, { 0x00, 0x00 } },                   // 20 SP
	{ 1, { 0x7D } },                         // 21 !
	{ 3, { 0x60, 0x00, 0x60 } },             // 22 "
	{ 5, { 0x14, 0x7F, 0x14, 0x7F, 0x14 } }, // 23 #
	{ 5, { 0x12, 0x2A, 0x7F, 0x2A, 0x24 } }, // 24 $
	{ 5, { 0x62, 0x64, 0x08, 0x13, 0x23 } }, // 25 %
	{ 5, { 0x36, 0x49, 0x35, 0x02, 0x05 } }, // 26 &
	{ 1, { 0x60 } },                         // 27 '
	{ 3, { 0x1C, 0x22, 0x41 } },             // 28 (
	{ 3, { 0x41, 0x22, 0x1C } },             // 29 )
	{ 3, { 0x28, 0x10, 0x28 } },             // 2A *
	{ 5, { 0x08, 0x08, 0x3E, 0x08, 0x08 } }, // 2B +
	{ 2, { 0x05, 0x06 } },                   // 2C ,
	{ 3, { 0x08, 0x08, 0x08 } },             // 2D -
	{ 2, { 0x03, 0x03 } },                   // 2E .
	{ 3, { 0x03, 0x1C, 0x60 } },             // 2F /
	{ 4, { 0x3E, 0x49, 0x51, 0x3E } },       // 30 0
	{ 3, { 0x21, 0x7F, 0x01 } },             // 31 1
	{ 4, { 0x23, 0x45, 0x49, 0x31 } },       // 32 2
	{ 4, { 0x33, 0x41, 0x49, 0x36 } },       // 33 3
	{ 4, { 0x71, 0x08, 0x1F, 0x08 } },       // 34 4
	{ 4, { 0x72, 0x51, 0x51, 0x4E } },       // 35 5
	{ 4, { 0x3E, 0x49, 0x49, 0x26 } },       // 36 6
	{ 4, { 0x40, 0x43, 0x4C, 0x70 } },       // 37 7
	{ 4, { 0x36, 0x49, 0x49, 0x36 } },       // 38 8
	{ 4, { 0x32, 0x49, 0x49, 0x3E } },       // 39 9
	{ 2, { 0x36, 0x36 } },                   // 3A :
	{ 2, { 0x35, 0x36 } },                   // 3B ;
	{ 3, { 0x08, 0x14, 0x22, } },            // 3C <
	{ 3, { 0x14, 0x14, 0x14 } },             // 3D =
	{ 3, { 0x22, 0x14, 0x08 } },             // 3E >
	{ 5, { 0x20, 0x40, 0x45, 0x48, 0x30 } }, // 3F ?
	{ 7, { 0x1C, 0x22, 0x3D, 0x55, 0x5C, 0x24, 0x18 } }, // 40 @
	{ 5, { 0x3F, 0x48, 0x48, 0x48, 0x3F } }, // 41 A
	{ 5, { 0x7F, 0x49, 0x49, 0x49, 0x36 } }, // 42 B
	{ 5, { 0x3E, 0x41, 0x41, 0x41, 0x22 } }, // 43 C
	{ 5, { 0x7F, 0x41, 0x41, 0x41, 0x3E } }, // 44 D
	{ 5, { 0x7F, 0x49, 0x49, 0x49, 0x41 } }, // 45 E
	{ 5, { 0x7F, 0x48, 0x48, 0x48, 0x40 } }, // 46 F
	{ 5, { 0x3E, 0x41, 0x49, 0x49, 0x2E } }, // 47 G
	{ 5, { 0x7F, 0x08, 0x08, 0x08, 0x7F } }, // 48 H
	{ 3, { 0x41, 0x7F, 0x41 } },             // 49 I
	{ 5, { 0x02, 0x01, 0x41, 0x7E, 0x40 } }, // 4A J
	{ 5, { 0x7F, 0x08, 0x14, 0x22, 0x41 } }, // 4B K
	{ 5, { 0x7F, 0x01, 0x01, 0x01, 0x01 } }, // 4C L
	{ 5, { 0x7F, 0x20, 0x18, 0x20, 0x7F } }, // 4D M
	{ 5, { 0x7F, 0x10, 0x08, 0x04, 0x7F } }, // 4E N
	{ 5, { 0x3E, 0x41, 0x41, 0x41, 0x3E } }, // 4F O
	{ 5, { 0x7F, 0x48, 0x48, 0x48, 0x30 } }, // 50 P
	{ 5, { 0x3E, 0x41, 0x45, 0x42, 0x3D } }, // 51 Q
	{ 5, { 0x7F, 0x48, 0x4C, 0x4A, 0x31 } }, // 52 R
	{ 5, { 0x31, 0x49, 0x49, 0x49, 0x46 } }, // 53 S
	{ 5, { 0x40, 0x40, 0x7F, 0x40, 0x40 } }, // 54 T
	{ 5, { 0x7E, 0x01, 0x01, 0x01, 0x7E } }, // 55 U
	{ 5, { 0x7C, 0x02, 0x01, 0x02, 0x7C } }, // 56 V
	{ 5, { 0x7E, 0x01, 0x06, 0x01, 0x7E } }, // 57 W
	{ 5, { 0x63, 0x14, 0x08, 0x14, 0x63 } }, // 58 X
	{ 5, { 0x70, 0x08, 0x07, 0x08, 0x70 } }, // 59 Y
	{ 5, { 0x43, 0x45, 0x49, 0x51, 0x61 } }, // 5A Z
	{ 3, { 0x7F, 0x41, 0x41 } },             // 5B [
	{ 3, { 0x60, 0x1C, 0x03 } },             /* 5C \ */
	{ 3, { 0x41, 0x41, 0x7F } },             // 5D ]
	{ 5, { 0x10, 0x20, 0x40, 0x20, 0x10 } }, // 5E ^
	{ 4, { 0x01, 0x01, 0x01, 0x01 } },       // 5F _
	{ 3, { 0x40, 0x20, 0x10 } },             // 60 `
	{ 5, { 0x02, 0x15, 0x15, 0x15, 0x0F } }, // 61 a
	{ 5, { 0x7F, 0x09, 0x11, 0x11, 0x0E } }, // 62 b
	{ 5, { 0x0E, 0x11, 0x11, 0x11, 0x02 } }, // 63 c
	{ 5, { 0x0E, 0x11, 0x11, 0x09, 0x7F } }, // 64 d
	{ 5, { 0x0E, 0x15, 0x15, 0x15, 0x0C } }, // 65 e
	{ 5, { 0x08, 0x3F, 0x48, 0x40, 0x20 } }, // 66 f
	{ 5, { 0x18, 0x25, 0x25, 0x25, 0x3E } }, // 67 g
	{ 5, { 0x7F, 0x08, 0x10, 0x10, 0x0F } }, // 68 h
	{ 3, { 0x11, 0x5F, 0x01 } },             // 69 i
	{ 4, { 0x02, 0x01, 0x11, 0x5E } },       // 6A j
	{ 4, { 0x7F, 0x04, 0x0A, 0x11 } },       // 6B k
	{ 3, { 0x41, 0x7F, 0x01 } },             // 6C l
	{ 5, { 0x1F, 0x10, 0x0C, 0x10, 0x0F } }, // 6D m
	{ 5, { 0x1F, 0x08, 0x10, 0x10, 0x0F } }, // 6E n
	{ 5, { 0x0E, 0x11, 0x11, 0x11, 0x0E } }, // 6F o
	{ 5, { 0x1F, 0x14, 0x14, 0x14, 0x08 } }, // 70 p
	{ 5, { 0x08, 0x14, 0x14, 0x14, 0x0F } }, // 71 q
	{ 5, { 0x1F, 0x08, 0x10, 0x10, 0x08 } }, // 72 r
	{ 5, { 0x09, 0x15, 0x15, 0x15, 0x02 } }, // 73 s
	{ 5, { 0x10, 0x7E, 0x11, 0x01, 0x02 } }, // 74 t
	{ 5, { 0x1E, 0x01, 0x01, 0x02, 0x1F } }, // 75 u
	{ 5, { 0x1C, 0x02, 0x01, 0x02, 0x1C } }, // 76 v
	{ 5, { 0x1E, 0x01, 0x02, 0x01, 0x1E } }, // 77 w
	{ 5, { 0x11, 0x0A, 0x04, 0x0A, 0x11 } }, // 78 x
	{ 5, { 0x18, 0x05, 0x05, 0x05, 0x1E } }, // 79 y
	{ 5, { 0x11, 0x13, 0x15, 0x19, 0x11 } }, // 7A z
	{ 3, { 0x08, 0x36, 0x41 } },             // 7B {
	{ 1, { 0x7F } },                         // 7C |
	{ 3, { 0x41, 0x36, 0x08 } },             // 7D }
	{ 5, { 0x08, 0x10, 0x08, 0x04, 0x08 } }, // 7E ~
	{ 0, {} }, // 7F DEL
	{ 7, { 0x08, 0x08, 0x08, 0x08, 0x2A, 0x1C, 0x08 } }, // 80 PAD: arrow right
	{ 7, { 0x08, 0x1C, 0x2A, 0x08, 0x08, 0x08, 0x08 } }, // 81 HOP: arrow left
	{ 0, {} }, // 82 BPH
	{ 0, {} }, // 83 NBH
	{ 0, {} }, // 84 IND
	{ 0, {} }, // 85 NEL
	{ 0, {} }, // 86 SSA
	{ 0, {} }, // 87 ESA
	{ 0, {} }, // 88 HTS
	{ 0, {} }, // 89 HTJ
	{ 0, {} }, // 8A VTS
	{ 0, {} }, // 8B PLD
	{ 0, {} }, // 8C PLU
	{ 0, {} }, // 8D RI
	{ 0, {} }, // 8E SS2
	{ 0, {} }, // 8F SS3
	{ 0, {} }, // 90 DCS
	{ 0, {} }, // 91 PU1
	{ 0, {} }, // 92 PU2
	{ 0, {} }, // 93 STS
	{ 0, {} }, // 94 CCH
	{ 0, {} }, // 95 MW
	{ 0, {} }, // 96 SPA
	{ 0, {} }, // 97 EPA
	{ 0, {} }, // 98 SOS
	{ 0, {} }, // 99 SGCI
	{ 0, {} }, // 9A SCI
	{ 0, {} }, // 9B CSI
	{ 0, {} }, // 9C ST
	{ 0, {} }, // 9D OSC
	{ 0, {} }, // 9E PM
	{ 0, {} }, // 9F APC
	{ 2, { 0x00, 0x00 } },                   // A0 NBSP
	{ 1, { 0x5F } },                         // A1 ¡
	{ 0, {} }, // A2 ¢
	{ 5, { 0x09, 0x3F, 0x49, 0x49, 0x21 } }, // A3 £
	{ 5, { 0x14, 0x3E, 0x55, 0x41, 0x22 } }, // A4 €
	{ 5, { 0x74, 0x0C, 0x07, 0x0C, 0x74 } }, // A5 ¥
	{ 0, {} }, // A6 Š
	{ 4, { 0x29, 0x55, 0x55, 0x4A} },        // A7 §
	{ 0, {} }, // A8 š
	{ 7, { 0x3E, 0x41, 0x5D, 0x55, 0x55, 0x41, 0x3E } }, // A9 ©
	{ 0, {} }, // AA ª
	{ 5, { 0x04, 0x0A, 0x00, 0x04, 0x0A } }, // AB «
	{ 4, { 0x08, 0x08, 0x08, 0x06 } },       // AC ¬
	{ 0, {} }, // AD SHY
	{ 7, { 0x3E, 0x41, 0x5D, 0x59, 0x55, 0x41, 0x3E } }, // AE ®
	{ 3, { 0x02, 0x02, 0x02 } },             // AF ¯
	{ 3, { 0x20, 0x50, 0x20 } },             // B0 °
	{ 3, { 0x12, 0x3A, 0x12 } },             // B1 ±
	{ 3, { 0x48, 0x58, 0x28 } },             // B2 ²
	{ 3, { 0x48, 0x68, 0x30 } },             // B3 ³
	{ 0, {} }, // B4 Ž
	{ 4, { 0x0F, 0x02, 0x02, 0x0E } },       // B5 µ
	{ 5, { 0x30, 0x78, 0x7F, 0x40, 0x7F } }, // B6 ¶
	{ 1, { 0x08 } },                         // B7 ·
	{ 0, {} }, // B8 ž
	{ 3, { 0x28, 0x78, 0x08 } },             // B9 ¹
	{ 0, {} }, // BA º
	{ 5, { 0x0A, 0x04, 0x00, 0x0A, 0x04 } }, // BB »
	{ 6, { 0x3E, 0x41, 0x41, 0x7F, 0x49, 0x49 } }, // BC Œ
	{ 7, { 0x0E, 0x11, 0x11, 0x0E, 0x15, 0x15, 0x0C } }, // BD œ
	{ 0, {} }, // BE Ÿ
	{ 5, { 0x06, 0x09, 0x51, 0x01, 0x02 } }, // BF ¿
	{ 0, {} }, // C0 À
	{ 0, {} }, // C1 Á
	{ 0, {} }, // C2 Â
	{ 0, {} }, // C3 Ã
	{ 5, { 0x1F, 0x64, 0x24, 0x64, 0x1F } }, // C4 Ä
	{ 0, {} }, // C5 Å
	{ 6, { 0x3F, 0x48, 0x48, 0x7F, 0x49, 0x49 } }, // C6 Æ
	{ 0, {} }, // C7 Ç
	{ 0, {} }, // C8 È
	{ 0, {} }, // C9 É
	{ 0, {} }, // CA Ê
	{ 0, {} }, // CB Ë
	{ 0, {} }, // CC Ì
	{ 0, {} }, // CD Í
	{ 0, {} }, // CE Î
	{ 0, {} }, // CF Ï
	{ 5, { 0x08, 0x7F, 0x49, 0x41, 0x3E } }, // D0 Ð
	{ 0, {} }, // D1 Ñ
	{ 0, {} }, // D2 Ò
	{ 0, {} }, // D3 Ó
	{ 0, {} }, // D4 Ô
	{ 0, {} }, // D5 Õ
	{ 5, { 0x1E, 0x61, 0x21, 0x61, 0x1E } }, // D6 Ö
	{ 5, { 0x0A, 0x04, 0x0A } },             // D7 ×
	{ 0, {} }, // D8 Ø
	{ 0, {} }, // D9 Ù
	{ 0, {} }, // DA Ú
	{ 0, {} }, // DB Û
	{ 5, { 0x3E, 0x41, 0x01, 0x41, 0x3E } }, // DC Ü
	{ 0, {} }, // DD Ý
	{ 4, { 0x7F, 0x28, 0x28, 0x10 } },       // DE Þ
	{ 4, { 0x3F, 0x40, 0x49, 0x36 } },       // DF ß
	{ 0, {} }, // E0 à
	{ 0, {} }, // E1 á
	{ 0, {} }, // E2 â
	{ 0, {} }, // E3 ã
	{ 5, { 0x02, 0x55, 0x15, 0x55, 0x0F } }, // E4 ä
	{ 0, {} }, // E5 å
	{ 7, { 0x02, 0x15, 0x15, 0x0E, 0x15, 0x15, 0x0C } }, // E6 æ
	{ 0, {} }, // E7 ç
	{ 0, {} }, // E8 è
	{ 0, {} }, // E9 é
	{ 0, {} }, // EA ê
	{ 0, {} }, // EB ë
	{ 0, {} }, // EC ì
	{ 0, {} }, // ED í
	{ 0, {} }, // EE î
	{ 0, {} }, // EF ï
	{ 0, {} }, // F0 ð
	{ 0, {} }, // F1 ñ
	{ 0, {} }, // F2 ò
	{ 0, {} }, // F3 ó
	{ 0, {} }, // F4 ô
	{ 0, {} }, // F5 õ
	{ 5, { 0x0E, 0x51, 0x11, 0x51, 0x0E } }, // F6 ö
	{ 5, { 0x08, 0x08, 0x2A, 0x08, 0x08 } }, // F7 ÷
	{ 0, {} }, // F8 ø
	{ 0, {} }, // F9 ù
	{ 0, {} }, // FA ú
	{ 0, {} }, // FB û
	{ 5, { 0x1E, 0x41, 0x01, 0x42, 0x1F } }, // FC ü
	{ 0, {} }, // FD ý
	{ 4, { 0x7F, 0x14, 0x14, 0x08 } },       // FE þ
	{ 5, { 0x18, 0x45, 0x05, 0x45, 0x1E } }, // FF ÿ
};

#endif
