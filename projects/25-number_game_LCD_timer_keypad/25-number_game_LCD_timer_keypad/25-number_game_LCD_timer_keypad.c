/*
 * _25_number_game_LCD_timer_keypad.c
 *
 * Created: 5/23/2022 9:30:05 PM
 *  Author: Mohamed Yasser
 */ 
#pragma optimize("",off)

#include <stdlib.h>
#include "LCD.h"
#include "keypad.h"
#include "timer0_CTC_mode.h"

volatile uint8 counter1 =0;
volatile uint8 seconds = 10;


/*function generate random number in range of: (1:9)*/
uint8 random_number(void);

int main(void)
{
	uint8 randam_number1 = random_number();
	uint8 randam_number2 = random_number();
	uint16 result = 0;
	uint8 answer = 0;
	
	LCD_init();
	keypad_init();
	LCD_send_string("Seconds left: ");
	
	timer0_ctc_init();
	
    while(1)
    {
		if (counter1 >= 31);
		{
			seconds--;
			counter1 = 0;
		}
		
        LCD_move_cursor(1,15);
		LCD_send_character( (seconds/10) + 48 ); 
		LCD_send_character( (seconds%10) + 48 ); 
		LCD_move_cursor(2,1);
		LCD_send_character(randam_number1+48);
		LCD_send_character(' ');
		LCD_send_character('+');
		LCD_send_character(' ');
		LCD_send_character('?');
		LCD_send_character(' ');
		LCD_send_character('=');
		LCD_send_character(' ');
		result = randam_number1 + randam_number2;
		LCD_send_character( (result/10) + 48 );
		LCD_send_character( (result%10) + 48 );
			
    }
}


uint8 random_number(void)
{
	return (uint8)( 1 + (rand() % 8) );
}


/*increment counter every (32) mSec. */
ISR(TIMER0_COMP_vect)
{
	counter1++;
}