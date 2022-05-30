/*
 * LCD.h
 *
 * Created: 5/19/2022 1:04:02 AM
 *  Author: Mohamed Yasser
 */ 


#ifndef LCD_H_
#define LCD_H_


#include "std_macros.h"
#include "typedef.h"
#include "Atmega_GPIO.h"
#include "LCD_config.h"

/************* Macros section **********************/

//LCD commands:
#define CLEAR_SCREEN 0x1  //write 0x20 in all DDRAM locations, set address counter to 0x00, set increment entry mode
#define RETURN_HOME 0x2 //set DDRAM address counter to 0x00, return display to its original position

#define CURSOR_LEFT 0x4
#define CURSOR_RIGHT 0x6

#define DISPLAY_RIGHT 0x5
#define DISPLAY_LEFT 0x7

#define ENGLISH_ENTRY 0x06 //set direction of cursor movement from left to right.

#define DISPLAY_OFF_CURSOR_OFF 0x8
#define DISPLAY_OFF_CURSOR_ON 0xA
#define DISPLAY_ON_CURSOR_OFF 0xC
#define DISPLAY_ON_CURSOR_ON 0xE
#define DISPLAY_ON_CURSOR_BLINKING 0xF

#define CURSOR_POSITION_RIGHT 0x14
#define CURSOR_POSITION_LEFT 0x10

#define ENTIRE_DISPLAY_LEFT 0x18
#define ENTIRE_DISPLAY_RIGHT 0x1C

#define CURSOR_FIRST_LINE 0x80
#define CURSOR_SECOND_LINE 0xC0

#define TWO_LINES_5x8_MATRIX 0x38
//-----------------------------------------
//set display mode and connection:
#if defined four_bits_mode

#define LCD_PORT 'A'	//define the port connected to LCD
#define EN 0	//enable pin number
#define RS 1	//register select pin number
#define RS_PORT 'B'
#define EN_PORT 'B'
#define FOUR_BITS 0x28

#elif defined eight_bits_mode

#define LCD_PORT 'A'	//define the port connected to LCD
#define EN 1	//enable pin number
#define RS 0	//register select pin number
#define RS_PORT 'B'
#define EN_PORT 'B'
#define EIGHT_BITS 0x38

#endif
/*=============== end macros ==================*/

/*
function name: LCD_init
function arguments: (void)
function return: void
function description: Initialize LCD:
*/
void LCD_init(void);

/*
function name: LCD_clear_screen
function arguments: (void)
function return: void
function description: Clears entire screen, and set cursor to start position
*/
void LCD_clear_screen(void);

/*
function name: LCD_return_home
function arguments: (void)
function return: void
function description: Returns cursor to start position
*/
void LCD_return_home(void);

/*
function name: LCD_send_character
function arguments: (char character)
function return: void
function description: Send character to data lines of LCD
*/
void LCD_send_character(char character);

/*
function name: LCD_send_string
function arguments: (char* character)
function return: void
function description: Send string to data lines of LCD
*/
void LCD_send_string(char* character);

/*
function name: LCD_move_cursor
function arguments: (uint8 row, uint8 column)
function return: void
function description: Move cursor of the LCD to the given row and column
*/
void LCD_move_cursor(uint8 row, uint8 column);


/*
function name: LCD_send_command
function arguments: (uint8 command)
function return: void
function description: Send command to LCD
*/
void LCD_send_command(uint8 command);

#endif /* LCD_H_ */