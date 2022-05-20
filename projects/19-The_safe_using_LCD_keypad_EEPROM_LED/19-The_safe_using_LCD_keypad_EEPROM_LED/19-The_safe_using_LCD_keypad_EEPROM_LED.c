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

uint16 address[4] = {0x7A, 0x7B, 0x7C, 0x7D};


int main(void)
{
	uint32 password = 0;
	uint8 flag = 0xff, count = 0 ;
	LCD_init();
	keypad_init();
	LED_init('D',0); //initialize red LED.
	LED_init('D',1); //initialize green LED.
	
	/*turn off LEDs*/
	LED_turn_off('D',0);
	LED_turn_off('D',1);
	
	/*read the password from EEPROM*/
	password = safe_read_pass(address);
	
	/*check if it is first time to set password or not*/
	if (0xffffffff == password)
	{
		password = safe_set_pass(address);
	}
	else
	{
		//not the first time, ask for the correct password.
		LED_turn_on('D',0); //turn on red LED, the safe is closed.
		LED_turn_off('D',1);
		flag = safe_check_pass(address);
	}
		
		
}