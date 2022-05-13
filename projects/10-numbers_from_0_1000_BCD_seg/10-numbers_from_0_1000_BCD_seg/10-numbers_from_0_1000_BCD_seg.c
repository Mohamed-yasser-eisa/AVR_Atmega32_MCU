/*
 * _10_numbers_from_0_1000_BCD_seg.c
 *
 * Created: 5/12/2022 11:11:15 AM
 *  Author: Mohamed Yasser
 */ 


/*************************************
*display numbers from 0 to 1000 on 4-BCD seven segment displays connected on port 'D'
*with delay 0.5 second between each number.
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
	uint16 number = 0; //the number that will be displayed on 7-segments
	uint16 counter = 0; //counter to the number that will be displayed on 7-segments
	uint8 pressed = 0;
	Seven_segment_init('C',0);
	/*define common pins of seven-segments as output*/
	GPIO_pin_direction('D', 0, 1);
	GPIO_pin_direction('D', 1, 1);
	GPIO_pin_direction('D', 2, 1);
	GPIO_pin_direction('D', 3, 1);
	/*write 1 on common cathode pins of seven-segments to turn off all segments*/
	GPIO_pin_write('D',0,1);
	GPIO_pin_write('D',1,1);
	GPIO_pin_write('D',2,1);
	GPIO_pin_write('D',3,1);
	
	
    while(1)
    {
		 number = counter;
		 pressed++;
		 GPIO_pin_write('D',3,0);//turn on first seven-segment
		 Seven_segment_write('C',(number%10), 0, 0); //write data on seven-segment
		 _delay_ms(5); //wait 5 mill second
		 number /= 10; //remove first digit
		 GPIO_pin_write('D',3,1);//turn off first seven-segment
		 GPIO_pin_write('D',0,0);//turn on second seven-segment
		 Seven_segment_write('C',(number%10), 0, 0);
		 _delay_ms(5);
		 number /= 10;
		 GPIO_pin_write('D',0,1);//turn off second seven-segment
		 GPIO_pin_write('D',1,0);//turn on third seven-segment
		 Seven_segment_write('C',(number%10), 0, 0);
		 _delay_ms(5);
		 number /= 10;
		 GPIO_pin_write('D',1,1);//turn off third seven-segment
		 GPIO_pin_write('D',2,0);//turn on forth seven-segment
		 Seven_segment_write('C',(number%10), 0, 0);
		 _delay_ms(5);
		 GPIO_pin_write('D',2,1);//turn off forth seven-segment
		 if (pressed>=5)//45
		 {
			 if (1000==counter)
			 {
				 counter=-1;
			 }
			 counter++;
			 pressed=0;
		 }
    }
}