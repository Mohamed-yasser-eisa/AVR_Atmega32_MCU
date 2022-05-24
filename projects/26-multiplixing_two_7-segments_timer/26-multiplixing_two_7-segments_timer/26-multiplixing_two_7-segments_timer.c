/*
 * _26_multiplixing_two_7_segments_timer.c
 *
 * Created: 5/24/2022 2:15:42 AM
 *  Author: Mohamed Yasser
 */ 


#include "timer0_CTC_mode.h"
#include "seven_segment.h"

volatile uint8 counter;
volatile uint8 seconds;



int main(void)
{
	uint8 number = 0;
	Seven_segment_init('A',0);
	timer0_ctc_init();
	
    while(1)
    {
        if (seconds >= 31)
        {
			seconds = 0;
			number ++;
        }
		if (100 == number)
		{
			number = 0;
		}
		if ( (counter % 2) == 0 )
		{
			CLR_BIT(PORTB,1);
			SET_BIT(PORTB,0);
			Seven_segment_write('A', (number/10),0,1);
		}
		else
		{
			CLR_BIT(PORTB,0);
			SET_BIT(PORTB,1);
			Seven_segment_write('A', (number%10),0,1);
		}
		if (counter >= 100)
		{
			counter = 0;
		}
    }
}

ISR(TIMER0_COMP_vect)
{
	counter++;
	seconds++;
}