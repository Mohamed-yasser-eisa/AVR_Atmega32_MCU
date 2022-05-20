/*
 * safe.c
 *
 * Created: 5/20/2022 3:15:41 PM
 *  Author: Mohamed Yasser
 */ 

#include "safe.h"

uint32 safe_read_pass(uint16* address)
{
	uint32 pass_value = 0;
	/*read the password from EEPROM*/
	pass_value = (uint8)EEPROM_read(*(address+0));
	pass_value <<= 8;
	pass_value |= (uint8)EEPROM_read(*(address+1));
	pass_value <<= 8;
	pass_value |= (uint8)EEPROM_read(*(address+2));
	pass_value <<= 8;
	pass_value |= (uint8)EEPROM_read(*(address+3));
	/*now return password*/
	return pass_value;
}

uint32 safe_set_pass(uint16* address)
{
	uint32 password = 0;
	char pass = '\0', pass_arr[33] = {'\0'};
	uint8 factor = 1;
	
	LCD_move_cursor(1,1);
	LCD_send_string("Set a password");
	LCD_move_cursor(2,1);
	LCD_send_string("Then enter '#' ");
	LCD_move_cursor(3,1);
	
	while( (char)pass!=(char)'#' )
	{
		pass = keypad_check_press();
		if ( (0xff != pass) && ( (char)pass!=(char)'#') ) 
		{
			LCD_send_character(pass);
			password *= factor;
			password += (pass - 48);
			factor = 10;
			_delay_ms(250);
		}
	}
	LCD_send_character('#');
	LCD_clear_screen();
	LCD_send_string("Your password is");
	LCD_move_cursor(2,1);
	sprintf(pass_arr, "%lu", password); //convert number to string
	LCD_send_string(pass_arr);
	/*save password to EEPROM*/
	EEPROM_write(*(address+0),(uint8)(password>>24));
	EEPROM_write(*(address+1),(uint8)(password>>16));
	EEPROM_write(*(address+2),(uint8)(password>>8));
	EEPROM_write(*(address+3),(uint8)(password));
	
	return password;
}

uint8 safe_check_pass(uint16* address)
{
	uint8 flag = 0;
	uint32 password1 = 0, password2 = 0;
	uint8 i=0;
	char pass = '\0', pass_arr[33] = {'\0'};
	uint8 factor = 1;

	LCD_move_cursor(1,1);
	LCD_send_string("Enter password");
	LCD_move_cursor(2,1);
	LCD_send_string("Then enter '#' ");
	LCD_move_cursor(3,1);
	
	while( (char)pass!=(char)'#' )
	{
		pass = keypad_check_press();
		if ( (0xff != pass) && ( (char)pass!=(char)'#') )
		{
			LCD_send_character(pass);
			password1 *= factor;
			password1 += (pass - 48);
			factor = 10;
			_delay_ms(250);
		}
	}
	LCD_send_character('#');
	password2 = safe_read_pass(address);
	if (password1 == password2)
	{
		flag = 1;
		LCD_clear_screen();
		LCD_send_string("Password correct");
	}
	else
	{
		flag = 0;
		LCD_clear_screen();
		LCD_send_string("Pass incorrect");	
	}
	return flag;
}