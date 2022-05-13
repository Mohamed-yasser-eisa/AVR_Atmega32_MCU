/*
 * _2_lightOn_8_LEDs_and_off_in_reverse_order.c
 *
 * Created: 5/8/2022 1:28:11 PM
 *  Author: Mohamed Yasser
 */ 

/*------------------- macros section: -------------------------*/
#define F_CPU 8000000UL
/*============================ end ==============================*/

/*------------------- includes section: -------------------------*/
#include "led.h"
#include <util/delay.h>
/*============================ end ==============================*/


int main(void)
{
	sint8 counter = 0;
	for(counter = 0; counter<8; ++counter)
	{
		LED_init('A', counter); //Init 8 LEDs on port A
	}
	
    while(1)
    {
        for (counter = 0; counter<8; ++counter)
        {
			LED_turn_on('A', counter);
			_delay_ms(1000);
			if(7 == counter)
			{
				for (counter = 7; counter>=0; --counter)
				{
					LED_turn_off('A', counter);
					_delay_ms(1000);
				}				
			} // end of if(7 == counter);
        } // end of for (counter = 0; counter<8; ++counter);
         
    } // end of while (1);
} // end of 