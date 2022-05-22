/*
 * _19_The_safe_using_LCD_keypad_EEPROM_LED.c
 *
 * Created: 5/20/2022 2:44:36 PM
 *  Author: Mohamed Yasser
 */ 

/***************************************
* safe project: the user will set a password at first time.
* save password in internal EEPROM.
* ask the user to enter the password next time.
* if password is correct open the safe. (write on LCD, and turn on green LED).
* if password not correct for 3 times, lock the safe for 30 seconds. 
******************************************/

/************* Includes section *********************/
#include "safe.h"
/*================ end =============================*/

#define MAX_TRIES 3

uint16 set_pass = 0x76; //in this address will write '0' (pass set) or 0xff (pass not set)
uint16 address[4] = {0x7A, 0x7B, 0x7C, 0x7D}; //addresses where password will be stored
uint8 password[6];

int main(void)
{
	uint8 flag = 0x00, count = 0, pass_status = 0;
	
	LCD_init();
	keypad_init();
	LED_init('D',0); //initialize red LED.
	LED_init('D',1); //initialize green LED.
	
	/*turn off LEDs*/
	LED_turn_off('D',0);
	LED_turn_off('D',1);
	
	/*get password status*/
	pass_status = safe_pass_status(set_pass);
	
	/*check if it is first time to set password or not*/
	if (0xff == pass_status)
	{
		LED_turn_on('D',1); //turn on green LED, the safe is opened.
		LED_turn_off('D',0);
		safe_set_pass(password, address, set_pass);
	}
	while( (0x00 == flag) && (count < MAX_TRIES) )
	{
		count++;
		//not the first time, ask for the correct password.
		LED_turn_on('D',0); //turn on red LED, the safe is closed.
		LED_turn_off('D',1);
		/*ask user to enter password, and check if it is correct*/
		flag = safe_check_pass(address);
		if (0xff == flag)
		{
			LED_turn_off('D',0);
			LED_turn_on('D',1); //turn on green LED, the safe is opened.
			LCD_clear_screen();
			LCD_send_string("Correct password");
			LCD_move_cursor(2,1);
			LCD_send_string("Safe is opened");
			break;
		}
		else
		{
			LCD_clear_screen();
			LCD_send_string("Incorrect pass");
			LCD_move_cursor(2,1);
			LCD_send_string("Safe is closed");
			LCD_move_cursor(3,1);
			LCD_send_string("Tries left: ");
			LCD_send_character(48+(MAX_TRIES-count));
			
		}
		_delay_ms(2000);
	}
		
		
}