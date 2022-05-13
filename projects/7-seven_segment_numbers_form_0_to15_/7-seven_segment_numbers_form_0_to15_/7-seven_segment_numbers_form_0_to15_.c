/*
 * _7_seven_segment_numbers_form_0_to15_.c
 *
 * Created: 5/12/2022 9:15:28 AM
 *  Author: Mohamed Yasser
 */ 


/*************************************
*display numbers from 0 to 15 on seven segment display connected on port 'D'
*with delay 1 second between each number.
*************************************/

/*------------------- macros section: -------------------------*/
#define F_CPU 8000000UL
/*============================ end ==============================*/

/*------------------- includes section: -------------------------*/
#include "seven_segment.h"
#include <util/delay.h>
/*============================ end ==============================*/

int main(void)
{
	uint8 num = 0;
	Seven_segment_init('A', 1); //initialize common anode 7-segments
	Seven_segment_init('c', 1); //initialize common cathode 7-segments
	while(1)
	{
		for(num=0; num<16; num++)
		{
			Seven_segment_write('A', num, 1,1); //write number on common anode
			Seven_segment_write('c', num, 1,0); //write number on common cathode
			_delay_ms(1000);
		}
	}//end of while(1)
}//end of main