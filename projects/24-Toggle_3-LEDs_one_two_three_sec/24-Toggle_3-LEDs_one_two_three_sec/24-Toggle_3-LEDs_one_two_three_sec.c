/*
 * _24_Toggle_3_LEDs_one_two_three_sec.c
 *
 * Created: 5/23/2022 7:02:21 PM
 *  Author: Mohamed Yasser
 */ 

#include "timer0_CTC_mode.h"
#include "led.h"


volatile uint8 counter1;
volatile uint8 counter2;
volatile uint8 counter3;

int main(void)
{
	LED_init('A',3);
	LED_init('A',4);
	LED_init('A',5);
	timer0_ctc_init();

    while(1)
    {
        if (counter1 >= 31)
        {
			LED_toggle('A',3);
			counter1 = 0;
        }
		if (counter2 >= 62)
		{
			LED_toggle('A',4);
			counter2 = 0;
		}
		if (counter3 >= 93)
		{
			LED_toggle('A',5);
			counter3 = 0;
		}
    }
}

ISR(TIMER0_COMP_vect)
{
	counter1++;
	counter2++;
	counter3++;
}