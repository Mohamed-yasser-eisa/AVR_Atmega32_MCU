/*
 * keypad.h
 *
 * Created: 5/20/2022 2:00:20 PM
 *  Author: Mohamed Yasser
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "Atmega_GPIO.h"
#define NOTPRESSED 0xFF
#define KEYPAD_PORT 'C'


/*
function name: keypad_init
function arguments: (void)
function return: void
function description: It configure keypad port connection
*/
void keypad_init(void);

/*
function name: keypad_check_press
function arguments: (void)
function return: char
function description: It returns the pressed button
*/
char keypad_check_press(void);


#endif /* KEYPAD_H_ */