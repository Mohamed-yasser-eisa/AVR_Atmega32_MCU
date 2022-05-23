/*
 * _23_Toggle_LED_every_one_sec_timer0_overflow.c
 *
 * Created: 5/23/2022 11:06:01 AM
 *  Author: Mohamed Yasser
 */ 

/***************** Icludes section start ****************/
#define F_CPU 8000000UL
#include "timer0_overflow_mode.h"
#include "led.h"
/*=================== end ==============================*/

volatile uint8 counter;

int main(void)
{
	LED_init('A',5);
	timer0_overflow_init();
	/*pre-load 6 in TCNT0 register to set correct timing*/
	
    while(1)
    {
        if (counter >= 31)
        {
			counter = 0;
			LED_toggle('A',5);
        }
    }
}

ISR(TIMER0_OVF_vect)
{
	counter++;
}