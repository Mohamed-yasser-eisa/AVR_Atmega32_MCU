/*
 * _8_Increase_display_number_with_button.c
 *
 * Created: 5/12/2022 9:22:05 AM
 *  Author: Mohamed Yasser
 */ 


/*************************************
*display numbers from 0 to 9 on seven segment display connected on port 'D'
*with each bush button.
*************************************/

/*------------------- macros section: -------------------------*/
#define F_CPU 8000000UL
/*============================ end ==============================*/

/*------------------- includes section: -------------------------*/
#include "seven_segment.h"
#include "button.h"
#include <util/delay.h>
/*============================ end ==============================*/

int main(void)
{
	uint8 number = 0;
	Seven_segment_init('C',0);
	Button_init_with_internal_pull_up('C',7);
    while(1)
    {
        if (!Button_read('C',7))
        {
			_delay_ms(150);
			if (!Button_read('C',7))
			{
				Seven_segment_write('c',number,0,0);
				++number;
			}				
        }
		if (number>=10)
		{
			number = 0;
		}
		 
    }//end of while(1)
}//end of main()