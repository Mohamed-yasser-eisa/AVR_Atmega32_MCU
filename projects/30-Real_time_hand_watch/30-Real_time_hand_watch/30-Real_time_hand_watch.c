/*
 * _30_Real_time_hand_watch.c
 *
 * Created: 5/24/2022 11:18:56 PM
 *  Author: Mohamed Yasser
 */ 

/********* Includes section start **************/
#include <avr/interrupt.h>
#include "timer2_over_flow.h"
#include "timer0_CTC_mode.h"
#include "seven_segment.h"
#include "button.h"
#include "led.h"
/*==================== end ====================*/


volatile uint8 seconds;
volatile uint8 counter;
volatile uint8 pressed;
volatile uint8 flag1;
volatile uint8 flag2;
volatile uint8 flag3;
volatile uint8 flag4;
volatile uint8 flag5;
volatile uint8 mode_select;
volatile uint8 mode = 0;


uint8 sec;
uint8 minutes = 0;
uint8 hours = 1;




void inc_hours(void)
{
	if ( 0 == Button_read('B',7) )
	{
		if ( (0 == Button_read('B',7)) && (pressed >= 6) )
		{
			if (12 == hours)
			{
				hours = 0;
			}
			hours++;
			pressed = 0;
		}
	}
}

void dec_hours(void)
{
	if ( 0 == Button_read('B',6) )
	{
		if ( (0 == Button_read('B',6)) && (pressed >= 6) )
		{
			if (1 == hours)
			{
				hours = 13;
			}
			hours--;
			pressed = 0;
		}
	}
}	

void inc_minutes(void)
{
	if ( 0 == Button_read('B',7) )
	{
		if ( (0 == Button_read('B',7)) && (pressed >= 6) )
		{
			if (59 == minutes)
			{
				minutes = 255;
			}
			minutes++;
			pressed = 0;
		}
	}
}

void dec_minutes(void)
{
	if ( 0 == Button_read('B',6) )
	{
		if ( (0 == Button_read('B',6)) && (pressed >= 6) )
		{
			if (0 == minutes)
			{
				minutes = 60;
			}
			minutes--;
			pressed = 0;
		}
	}
}


void inc_seconds(void)
{
	if ( 0 == Button_read('B',7) )
	{
		if ( (0 == Button_read('B',7)) && (pressed >= 6) )
		{
			if (59 == sec)
			{
				sec = 255;
			}
			sec++;
			pressed = 0;
		}
	}
}

void dec_seconds(void)
{
	if ( 0 == Button_read('B',6) )
	{
		if ( (0 == Button_read('B',6)) && (pressed >= 6) )
		{
			if (0 == sec)
			{
				sec = 60;
			}
			sec--;
			pressed = 0;
		}
	}
}



int main(void)
{
	Seven_segment_init('A',0);
	LED_init('B',0);
	LED_init('B',1);
	LED_init('B',2);
	LED_init('B',3);
	LED_init('B',4);
	LED_init('B',5);
	Button_init_with_internal_pull_up('B',6); //decrement button
	Button_init_with_internal_pull_up('B',7); //increment button
	Button_init_with_internal_pull_up('D',2); //select mode button
	
	timer2_overflow_init();
	timer0_ctc_init();
	SET_BIT(MCUCR,ISC01); //set interrupt mode to falling edge.
	SET_BIT(GICR,INT0); //enable interrupt on pin INT0
	
    while(1)
    {
		/* set hours, minutes, and seconds */
        if (seconds >= 60)
        {
			seconds = 0;
			minutes++;
        }
		if (minutes >= 60)
		{
			minutes = 0;
			hours++;
		}
		if (hours > 12)
		{
			hours = 1;
		}
		/*write numbers on 7-segments*/
		if ( flag1 )
		{
			Seven_seg1_write(hours/10);
		}
		else if ( flag2)
		{
			Seven_seg2_write(hours%10);
		}
		else if ( flag3)
		{
			Seven_seg3_write(minutes/10);
		}
		else if ( flag4 )
		{
			Seven_seg4_write(minutes%10);
		}
		else if ( flag5)
		{
			Seven_seg5_write(seconds/10);
		}
		else
		{
			Seven_seg6_write(seconds%10);
		}
		
		
		/*if button is pressed set time*/
		if ( mode_select )
		{
				mode_select = 0;
				//pressed = 0;
				mode = 1;
				sec = seconds;
				while(mode < 4)
				{
					switch(mode)
					{
						case 1:
							inc_hours();
							dec_hours();
							break;
						case 2:
							inc_minutes();
							dec_minutes();
							break;
						case 3:
							inc_seconds();
							dec_seconds();
							break;
						default:
							pressed = 0;
					}//end of switch
		
					if ( mode_select )
					{
						mode++;
						mode_select = 0;
					}										
					else
					{
						/*write numbers on 7-segments*/
						if ( flag1 && (mode==1) )
						{
							Seven_seg1_write(hours/10);
						}
						else if ( flag2 && (mode==1))
						{
							Seven_seg2_write(hours%10);
						}
						else if ( flag3 && (mode==2))
						{
							Seven_seg3_write(minutes/10);
						}
						else if ( flag4 && (mode==2))
						{
							Seven_seg4_write(minutes%10);
						}
						else if ( flag5 && (mode==3))
						{
							Seven_seg5_write(sec/10);
						}
						else if (mode==3)
						{
							Seven_seg6_write(sec%10);
						}
					}
	
				} // end of while
				seconds = sec;
		}
		else
		{
			pressed = 0;
		}
		
		
		
		
    }
}



ISR(INT0_vect)
{
	sei();
	mode_select = 1;
}


ISR(TIMER0_COMP_vect)
{
	sei();
	/*timer 0 overflow every 8 mSec*/
	counter++;
	switch(counter)
	{
		case 1:
			flag1 = 1;
			break;
		case 2:
			flag2 = 1;
			flag1 = 0;
			break;
		case 3:
			flag3 = 1;
			flag2 = 0;
		break;
		case 4:
			flag4 = 1;
			flag3 = 0;
		break;
		case 5:
			flag5 = 1;
			flag4 = 0;
		break;
		case 6:
			flag5 = 0;
		break;
		default:
		counter = 0;
		pressed++; // increment every 56 mSec
	}
}

ISR(TIMER2_OVF_vect)
{
	/*timer 2 overflow every 1 Sec*/
	seconds++;
}