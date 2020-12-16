

/*
 *
 * Font3x5
 *
 * created with FontCreator
 * written by F. Maximilian Thiele
 *
 * http://www.apetech.de/fontCreator
 * me@apetech.de
 *
 * File Name           : Font4X6.h
 * Date                : 17.02.2012
 * Font size in bytes  : 1472
 * Font width          : 3
 * Font height         : 5
 * Font first char     : 32
 * Font last char      : 128
 * Font used chars     : 96
 *
 * The font data are defined as
 *
 * struct _FONT_ {
 *     uint16_t   font_Size_in_Bytes_over_all_included_Size_it_self;
 *     uint8_t    font_Width_in_Pixel_for_fixed_drawing;
 *     uint8_t    font_Height_in_Pixel_for_all_characters;
 *     unit8_t    font_First_Char;
 *     uint8_t    font_Char_Count;
 *
 *     uint8_t    font_Char_Widths[font_Last_Char - font_First_Char +1];
 *                  // for each character the separate width in pixels,
 *                  // characters < 128 have an implicit virtual right empty row
 *
 *     uint8_t    font_data[];
 *                  // bit field of all characters
 */

#include <inttypes.h>
#include <avr/pgmspace.h>

#ifndef FONT4x6b_H
#define FONT4x6b_H

#define FONT4x6b_WIDTH 4
#define FONT4x6b_HEIGHT 6

const static uint8_t Font4x6b[] PROGMEM = {
    0x00, 0x00, //C0, // size
    0x04, // width
    0x06, // height
    0x20, // first char
    0x60, // char count
    
		0x00, 0x00, 0x00, 0x00,                  // Code for char  
        0x00, 0x2F, 0x00, 0x00,                  // Code for char !
        0x00, 0x03, 0x00, 0x03,                  // Code for char "
        0x12, 0x3F, 0x12, 0x3F,                  // Code for char #
        0x24, 0x2A, 0x3F, 0x12,                  // Code for char $
        0x13, 0x08, 0x04, 0x32,                  // Code for char %
        0x16, 0x29, 0x16, 0x28,                  // Code for char &
        0x00, 0x00, 0x03, 0x00,                  // Code for char '
        0x1E, 0x21, 0x00, 0x00,                  // Code for char (
        0x00, 0x00, 0x21, 0x1E,                  // Code for char )
        0x02, 0x07, 0x02, 0x00,                  // Code for char *
        0x08, 0x1C, 0x08, 0x00,                  // Code for char +
        0x00, 0x28, 0x18, 0x00,                  // Code for char ,
        0x08, 0x08, 0x08, 0x08,                  // Code for char -
        0x00, 0x30, 0x00, 0x00,                  // Code for char .
        0x10, 0x08, 0x04, 0x02,                  // Code for char /
        0x3F, 0x3F, 0x21, 0x3F,                  // Code for char 0
        0x01, 0x3F, 0x3F, 0x00,                  // Code for char 1
        0x39, 0x39, 0x29, 0x2F,                  // Code for char 2
        0x29, 0x29, 0x3F, 0x3F,                  // Code for char 3
        0x0F, 0x08, 0x3F, 0x3F,                  // Code for char 4
        0x2F, 0x2F, 0x29, 0x39,                  // Code for char 5
        0x3F, 0x3F, 0x29, 0x39,                  // Code for char 6
        0x01, 0x01, 0x3F, 0x3F,                  // Code for char 7
        0x3F, 0x3F, 0x29, 0x3F,                  // Code for char 8
        0x2F, 0x29, 0x3F, 0x3F,                  // Code for char 9
        0x00, 0x12, 0x12, 0x00,                  // Code for char :
        0x00, 0x12, 0x32, 0x00,                  // Code for char ;
        0x0C, 0x12, 0x21, 0x00,                  // Code for char <
        0x12, 0x12, 0x12, 0x12,                  // Code for char =
        0x00, 0x21, 0x12, 0x0C,                  // Code for char >
        0x02, 0x29, 0x05, 0x02,                  // Code for char ?
        0x0E, 0x2D, 0x21, 0x1E,                  // Code for char @
        0x3E, 0x3F, 0x09, 0x3E,                  // Code for char A
        0x3F, 0x3F, 0x29, 0x16,                  // Code for char B
        0x1E, 0x3F, 0x21, 0x12,                  // Code for char C
        0x3F, 0x3F, 0x21, 0x1E,                  // Code for char D
        0x3F, 0x3F, 0x29, 0x29,                  // Code for char E
        0x3F, 0x3F, 0x09, 0x09,                  // Code for char F
        0x1E, 0x3F, 0x21, 0x19,                  // Code for char G
        0x3F, 0x3F, 0x08, 0x3F,                  // Code for char H
        0x21, 0x3F, 0x3F, 0x21,                  // Code for char I
        0x10, 0x20, 0x3F, 0x1F,                  // Code for char J
        0x3F, 0x3F, 0x12, 0x21,                  // Code for char K
        0x3F, 0x3F, 0x20, 0x20,                  // Code for char L
        0x3F, 0x01, 0x1F, 0x3E,                  // Code for char M
        0x3F, 0x3F, 0x01, 0x3E,                  // Code for char N
        0x1E, 0x3F, 0x21, 0x1E,                  // Code for char O
        0x3F, 0x3F, 0x09, 0x06,                  // Code for char P
        0x1E, 0x21, 0x1F, 0x2E,                  // Code for char Q
        0x3F, 0x3F, 0x19, 0x26,                  // Code for char R
        0x26, 0x2F, 0x29, 0x11,                  // Code for char S
        0x01, 0x3F, 0x3F, 0x01,                  // Code for char T
        0x1F, 0x3F, 0x20, 0x1F,                  // Code for char U
        0x0F, 0x10, 0x3F, 0x3F,                  // Code for char V
        0x1F, 0x3F, 0x18, 0x27,                  // Code for char W
        0x21, 0x32, 0x0C, 0x33,                  // Code for char X
        0x13, 0x24, 0x3F, 0x1F,                  // Code for char Y
        0x31, 0x39, 0x27, 0x23,                  // Code for char Z
        0x3F, 0x21, 0x00, 0x00,                  // Code for char [
        0x02, 0x04, 0x08, 0x10,                  // Code for char BackSlash
        0x00, 0x00, 0x21, 0x3F,                  // Code for char ]
        0x02, 0x01, 0x01, 0x02,                  // Code for char ^
        0x20, 0x20, 0x20, 0x20,                  // Code for char _
        0x00, 0x01, 0x02, 0x00,                  // Code for char `
        0x12, 0x2A, 0x3E, 0x3C,                  // Code for char a
        0x3F, 0x3F, 0x24, 0x18,                  // Code for char b
        0x1C, 0x3E, 0x22, 0x14,                  // Code for char c
        0x18, 0x24, 0x3F, 0x3F,                  // Code for char d
        0x1C, 0x3E, 0x2A, 0x2C,                  // Code for char e
        0x08, 0x3E, 0x3F, 0x09,                  // Code for char f
        0x04, 0x2A, 0x3E, 0x1E,                  // Code for char g
        0x3F, 0x3F, 0x04, 0x38,                  // Code for char h
        0x24, 0x3D, 0x3D, 0x20,                  // Code for char i
        0x10, 0x24, 0x3D, 0x1D,                  // Code for char j
        0x3F, 0x3F, 0x14, 0x22,                  // Code for char k
        0x3F, 0x3F, 0x20, 0x00,                  // Code for char l
        0x3E, 0x02, 0x1C, 0x3A,                  // Code for char m
        0x3E, 0x3E, 0x02, 0x3C,                  // Code for char n
        0x1C, 0x3E, 0x22, 0x1C,                  // Code for char o
        0x3E, 0x3E, 0x0A, 0x04,                  // Code for char p
        0x04, 0x0A, 0x3E, 0x3E,                  // Code for char q
        0x3E, 0x3E, 0x02, 0x06,                  // Code for char r
        0x24, 0x2E, 0x2A, 0x12,                  // Code for char s
        0x04, 0x1F, 0x3F, 0x24,                  // Code for char t
        0x1E, 0x20, 0x3E, 0x3E,                  // Code for char u
        0x0E, 0x10, 0x3E, 0x1E,                  // Code for char v
        0x1E, 0x20, 0x10, 0x2E,                  // Code for char w
        0x22, 0x14, 0x08, 0x14,                  // Code for char x
        0x12, 0x24, 0x3E, 0x1E,                  // Code for char y
        0x32, 0x2A, 0x2E, 0x26,                  // Code for char z
        0x00, 0x21, 0x16, 0x08,                  // Code for char {
        0x00, 0x3F, 0x00, 0x00,                  // Code for char |
        0x08, 0x26, 0x21, 0x00,                  // Code for char }
        0x20, 0x10, 0x20, 0x10                   // Code for char ~
};

#endif
