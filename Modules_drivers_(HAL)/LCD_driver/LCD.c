/*
 * LCD.c
 *
 * Created: 5/19/2022 1:03:48 AM
 *  Author: Mohamed Yasser
 */ 

#include "LCD.h"

static void LCD_send_pulse(void)
{
	GPIO_pin_write(EN_PORT,EN,1);
	_delay_ms(2);
	GPIO_pin_write(EN_PORT,EN,0);
	_delay_ms(1);	
}


static void LCD_send_command(uint8 command)
{
	#if defined four_bits_mode
	
	GPIO_port_write_low_nibble(LCD_PORT,command>>4); //write_low_nipple because LCD is connected to low_nipple pins
	GPIO_pin_write(RS_PORT,RS,0); //select command register
	LCD_send_pulse();
	GPIO_port_write_low_nibble(LCD_PORT,command); //write_low_nipple because LCD is connected to low_nipple pins
	GPIO_pin_write(RS_PORT,RS,0); //select command register
	LCD_send_pulse();
	
	#elif defined eight_bits_mode
	
	GPIO_port_write(LCD_PORT,command);
	GPIO_pin_write(RS_PORT,RS,0);
	LCD_send_pulse();
	
	#endif
}

void LCD_init(void)
{
	_delay_ms(40);
	
	#if defined four_bits_mode
	//set connection pins:
	GPIO_pin_direction(LCD_PORT,0,1);
	GPIO_pin_direction(LCD_PORT,1,1);
	GPIO_pin_direction(LCD_PORT,2,1);
	GPIO_pin_direction(LCD_PORT,3,1);
	GPIO_pin_direction(EN_PORT,EN,1);//set EN pin to output pin
	GPIO_pin_direction(RS_PORT,RS,1);//set RS pin to output pin
	//send command to inti LCD:
	LCD_send_command(FOUR_BITS);
	#elif defined eight_bits_mode
	//set connection pins:
	GPIO_port_direction(LCD_PORT,1);
	GPIO_pin_direction(EN_PORT,EN,1);//set EN pin to output pin
	GPIO_pin_direction(RS_PORT,RS,1);//set RS pin to output pin
	//send command to init LCD:
	LCD_send_command(EIGHT_BITS);
	#endif
	LCD_return_home();
	LCD_send_command(DISPLAY_ON_CURSOR_OFF);
	LCD_clear_screen();
	LCD_send_command(ENGLISH_ENTRY);
}



void LCD_clear_screen(void)
{
	GPIO_pin_write(RS_PORT,RS,0);
	GPIO_port_write(LCD_PORT,CLEAR_SCREEN);
	_delay_ms(2);
}

void LCD_return_home(void)
{
	LCD_send_command(RETURN_HOME);
	_delay_ms(2);
}

void LCD_send_character(char character)
{
	#if defined four_bits_mode
	
	GPIO_pin_write(RS_PORT,RS,1);
	GPIO_port_write_low_nibble(LCD_PORT,character>>4);
	LCD_send_pulse();
	GPIO_pin_write(RS_PORT,RS,1);
	GPIO_port_write_low_nibble(LCD_PORT,character);
	LCD_send_pulse();
	
	#elif defined eight_bits_mode
	
	GPIO_pin_write(RS_PORT,RS,1);
	GPIO_port_write(LCD_PORT,character);
	LCD_send_pulse();
	
	#endif
	
}

void LCD_send_string(char* character)
{
	while ('\0' != *character)
	{
		LCD_send_character(*character);
		character += 1;
	}
}

void LCD_move_cursor(uint8 row, uint8 column)
{
	uint8 r = 0;
	uint8 c = 0;
	
	if( (row>0) && (row<5) && (column>0) && (column<21) )
	{
		if (1 == row)
		{
			c = (0x80 + column - 1);
		}
		else if (2 == row)
		{
			c = (0xC0 + column - 1);
		}
		else if (3 == row)
		{
			c = (0x90 + column - 1);
		}
		else
		{
			c = (0xD0 + column - 1);
		}
	}
	else
	{
		c = 0x80;
	}
	LCD_send_command(c);
}