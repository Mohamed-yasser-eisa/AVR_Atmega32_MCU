/*
 * keypad.c
 *
 * Created: 5/20/2022 2:00:02 PM
 *  Author: Mohamed Yasser
 */ 

#include "keypad.h"


void keypad_init(void)
{
	GPIO_pin_direction(KEYPAD_PORT,0,1);
	GPIO_pin_direction(KEYPAD_PORT,1,1);
	GPIO_pin_direction(KEYPAD_PORT,2,1);
	
	GPIO_pin_pull_up(KEYPAD_PORT,3);
	GPIO_pin_pull_up(KEYPAD_PORT,4);
	GPIO_pin_pull_up(KEYPAD_PORT,5);
	GPIO_pin_pull_up(KEYPAD_PORT,6);
}

char keypad_check_press(void)
{
	char button[4][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'} };
	uint8 row = 0, column = 0, pressed = 1;
	char val = NOTPRESSED;
	
	for (column=0; column<3; ++column)
	{
		GPIO_pin_write(KEYPAD_PORT,0,1);
		GPIO_pin_write(KEYPAD_PORT,1,1);
		GPIO_pin_write(KEYPAD_PORT,2,1);
		GPIO_pin_write(KEYPAD_PORT,column,0);
		for (row=0; row<4; ++row)
		{
			pressed = GPIO_pin_read(KEYPAD_PORT,(row+3));
			if (0 == pressed)
			{
				val = button[row][column];
				break;
			}
		}
		if (0 == pressed)
		{
			break;
		}
	}
	return val;
}