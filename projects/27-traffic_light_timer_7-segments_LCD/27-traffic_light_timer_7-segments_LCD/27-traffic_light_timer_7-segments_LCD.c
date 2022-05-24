/*
 * _27_traffic_light_timer_7_segments_LCD.c
 *
 * Created: 5/24/2022 3:01:48 AM
 *  Author: Mohamed Yasser
 */ 

#include "LCD.h"
#include "led.h"
#include "seven_segment.h"
#include "timer0_CTC_mode.h"

volatile uint8 counter;
volatile uint8 seconds;



int main(void)
{
	uint8 number = 10;
	uint8 green = 1;
	uint8 yellow = 0;
	uint8 i=0, flag1 = 1, flag2 = 0, flag3 = 0;
	LED_init('D',0); //control bit of left 7-segment
	LED_init('D',1); //control bit of right 7-segment
	LED_init('D',2); //Green LED
	LED_init('D',3); //Yellow LED
	LED_init('D',4); //Red LED
	LCD_init();
	Seven_segment_init('C',0);
	LCD_send_string("Be careful (^_^)");
	timer0_ctc_init();
	
    while(1)
    {
         if (seconds >= 31)
         {
			 seconds = 0;
			 number--;
         }
		 if ( (counter % 2) == 0)
		 {
			 LED_turn_off('D',1);
			 LED_turn_on('D',0);
			 Seven_segment_write('C',(number/10),0,1);
		 }
		 else
		 {
			 LED_turn_off('D',0);
			 LED_turn_on('D',1);
			 Seven_segment_write('C',(number%10),0,1);
		 }
		 if ( 1 == green )
		 {
			 LCD_move_cursor(3,1);
			 LCD_send_string("Cars go ");
			 LCD_move_cursor(4,1);
			 if ( 1 == flag1 )
			 {
				 for (i=0; i<= number; ++i)
				 {
					 LCD_send_character(0xff);
				 }
				 flag1 = 0;
			 }
			 LCD_move_cursor(4,number+1);
			 LCD_send_character(0x20);
			 LCD_move_cursor(3,9);
			 flag2 =1;
		 }
		 else if ( 1 == yellow )
		 {
			 LCD_move_cursor(3,1);
			 LCD_send_string("Cars go ");
			 LCD_move_cursor(4,1);
			 if ( 1 == flag2 )
			 {
				 for (i=0; i<= number; ++i)
				 {
					 LCD_send_character(0xff);
				 }
				 flag2 = 0;
			 }
			 LCD_move_cursor(4,number+1);
			 LCD_send_character(0x20);
			 LCD_move_cursor(3,9);
			 flag3 =1;
		 }
		 else
		 {
			 LCD_move_cursor(3,1);
			 LCD_send_string("People go ");
			 LCD_move_cursor(4,1);
			 if (1 == flag3)
			 {
				 for (i=0; i<= number; ++i)
				 {
					 LCD_send_character(0xff);
				 }
				 flag3 = 0;
			 }
			 LCD_move_cursor(4,number+1);
			 LCD_send_character(0x20);
			 LCD_move_cursor(3,11);
			 flag1 = 1;
		 }
		 if ( (number >= 0) && (1 == green) )
		 {
			 
			 LCD_send_character((number/10)+48);
			 LCD_send_character((number%10)+48);
			 LCD_send_string(" sec");
			 LED_turn_on('D',2);
			 LED_turn_off('D',3);
			 LED_turn_off('D',4);
			 if (0 == number)
			 {
				 number = 5;
				 green = 0;
				 yellow = 1;
			 }
		 }
		 else if ( (number >= 0) && (1 == yellow) )
		 {
			 LCD_send_character((number/10)+48);
			 LCD_send_character((number%10)+48);
			 LCD_send_string(" sec");
			 LED_turn_off('D',2);
			 LED_turn_on('D',3);
			 LED_turn_off('D',4);
			 if (0 == number)
			 {
				 number = 10;
				 green = 0;
				 yellow = 0;
			 }
		 }
		 else
		 {
			 LCD_send_character((number/10)+48);
			 LCD_send_character((number%10)+48);
			 LCD_send_string(" sec");
			 LED_turn_off('D',2);
			 LED_turn_off('D',3);
			 LED_turn_on('D',4);
			 if (0 == number)
			 {
				 number = 10;
				 green = 1;
				 yellow = 0;
			 }
		 }//end of else
		 			 
    }
}

ISR(TIMER0_COMP_vect)
{
	seconds++;
	counter++;
}