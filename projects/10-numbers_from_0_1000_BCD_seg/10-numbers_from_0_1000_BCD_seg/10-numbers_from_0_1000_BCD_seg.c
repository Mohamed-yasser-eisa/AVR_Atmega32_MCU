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
#include "button.h"
#include <util/delay.h>
/*============================ end ==============================*/

int main(void)
{
	uint16 number = 0;
	uint16 counter = 0;
	Seven_segment_init('C',0);
	Button_init_with_internal_pull_up('D',4);
	/*define common pins of seven-seg as output*/
	GPIO_pin_direction('D', 0, 1);
	GPIO_pin_direction('D', 1, 1);
	GPIO_pin_direction('D', 2, 1);
	GPIO_pin_direction('D', 3, 1);
	/*write 1 on common cathode pins of seven-seg to turn off all segments*/
	GPIO_pin_write('D',0,1);
	GPIO_pin_write('D',1,1);
	GPIO_pin_write('D',2,1);
	GPIO_pin_write('D',3,1);
	
	
    while(1)
    {
		 number = counter;
		 
		 GPIO_pin_write('D',3,0);//turn on LSB seven-segment
		 Seven_segment_write('C',(number%10), 0, 0); //write data on seven-segment
		 _delay_ms(5); //wait 35 mill second
		 number /= 10; //remove LSB
		 GPIO_pin_write('D',3,1);//turn off LSB seven-segment
		 GPIO_pin_write('D',0,0);
		 Seven_segment_write('C',(number%10), 0, 0);
		 _delay_ms(5);
		 number /= 10;
		 GPIO_pin_write('D',0,1);
		 GPIO_pin_write('D',1,0);
		 Seven_segment_write('C',(number%10), 0, 0);
		 _delay_ms(5);
		 number /= 10;
		 GPIO_pin_write('D',1,1);
		 GPIO_pin_write('D',2,0);
		 Seven_segment_write('C',(number%10), 0, 0);
		 _delay_ms(5);
		 GPIO_pin_write('D',2,1);
		 //_delay_ms(10);
		 counter++;
    }
}