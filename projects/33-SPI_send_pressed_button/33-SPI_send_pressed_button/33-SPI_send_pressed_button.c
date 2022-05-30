/*
 * _33_SPI_send_pressed_button.c
 *
 * Created: 5/30/2022 7:36:55 PM
 *  Author: Mohamed Yasser
 */ 

/*
Master code:
sending the pressed button throughout SPI to the slave MC.
*/

#include "SPI.h"
#include "keypad.h"

int main(void)
{
	char button;
	keypad_init();
	SPI_master_init();
	
    while(1)
    {
		button = keypad_check_press();
		
        if (NOTPRESSED != button)
        {
			SPI_master_transmit(button);
			_delay_ms(300);
        }
		else
		{
			//don't send anything
		}			
    }
}