/*
 * _23_Toggle_LED_every_one_sec_timer0_overflow.c
 *
 * Created: 5/23/2022 11:06:01 AM
 *  Author: Mohamed Yasser
 */ 

/***************** Icludes section start ****************/
#include "timer0_overflow_mode.h"
#include "led.h"
/*=================== end ==============================*/

volatile uint8 counter;

int main(void)
{
	LED_init('A',5);
	timer0_overflow_init();
	/*pre-load 6 in TCNT0 register to set correct timing*/
	timer0_TCNT0_value(6);
	
    while(1)
    {
        if (counter >= 32)
        {
			counter = 0;
			LED_toggle('A',5);
        }
    }
}

ISR(TIMER0_OVF_vect)
{
	timer0_TCNT0_value(6);
	counter++;
}