/*
 * safe.c
 *
 * Created: 5/20/2022 3:15:41 PM
 *  Author: Mohamed Yasser
 */ 

#include "safe.h"


uint8 safe_pass_status(uint16 address)
{
	uint8 password_status = 0;
	password_status = EEPROM_read(address);
	return password_status;
}


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

void safe_set_pass(uint8* pass, uint16* address, uint16 pass_status)
{
	uint8 i = 0, digit = 0;
	LCD_clear_screen();
	LCD_send_string("Set 8-b password");
	LCD_move_cursor(2,1);
	for(i=0; i<6; ++i)
	{
		do 
		{
			digit = keypad_check_press();
		} while ( digit == NOTPRESSED );
		
		LCD_send_character(digit);
		_delay_ms(500);
		LCD_move_cursor(2, 1+i);
		LCD_send_character('*');
		EEPROM_write(address[i], digit-48);
	}
	
	EEPROM_write(pass_status, 0x00); //write (0x00) to indicate that password is set
	LCD_move_cursor(3, 1);
	LCD_send_string("Password saved");
	_delay_ms(2000);
}

uint8 safe_check_pass(uint16* address)
{
	uint8 flag = 0xff, digit = NOTPRESSED;
	uint8 password1[6] = {0}, password2[6] = {0};
	uint8 i=0;

	LCD_clear_screen();
	LCD_send_string("Enter password:");
	LCD_move_cursor(2,1);
	/* read password from user and EEPROM */
	for(i=0; i<6; ++i)
	{
		do
		{
			digit = keypad_check_press();
		} while ( digit == NOTPRESSED );
		
		LCD_send_character(digit);
		_delay_ms(500);
		LCD_move_cursor(2, 1+i);
		LCD_send_character('*');
		password1[i] = EEPROM_read(address[i]);
		password2[i] = (digit - 48);
	}
	/*check if the password is correct or not:*/
	for (i=0; i<6; ++i)
	{
		if (password1[i] != password2[i])
		{
			flag = 0x00;
		}
		else
		{
			flag = 0xff;
		}
	}
	
	return flag;
}