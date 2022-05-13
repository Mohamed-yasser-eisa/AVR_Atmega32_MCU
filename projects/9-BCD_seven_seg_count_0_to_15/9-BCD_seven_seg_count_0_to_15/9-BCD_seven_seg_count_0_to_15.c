/*
 * _9_BCD_seven_seg_count_0_to_15.c
 *
 * Created: 5/12/2022 9:57:47 AM
 *  Author: Mohamed Yasser
 */ 

/*************************************
*display numbers from 0 to 9 on BCD seven segment display connected on port 'D'
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
	uint8 counter = 0;
	Seven_seg_BCD_init('c');
    while(1)
    {
         for(counter=0; counter<10; ++counter)
		 {
			 Seven_seg_BCD_write('C', counter);
			 _delay_ms(1000);
		 }			 
    }
}