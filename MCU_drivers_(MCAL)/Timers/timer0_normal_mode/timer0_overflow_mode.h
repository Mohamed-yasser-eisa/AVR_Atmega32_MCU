/*
 * timer0_overflow_mode.h
 *
 * Created: 5/23/2022 11:07:17 AM
 *  Author: Mohamed Yasser
 */ 


#ifndef TIMER0_OVERFLOW_MODE_H_
#define TIMER0_OVERFLOW_MODE_H_

#include <avr/interrupt.h>
#include "Atmega_GPIO.h"

/*
function name: timer0_overflow_init
function arguments: (void)
function return: void
function description: It initialize timer0 in overflow mode, and enable overflow interrupt.
*/
void timer0_overflow_init(void);

/*
function name: timer0_TCNT0_value
function arguments: (uint8 val)
function return: void
function description: Load the given value in TCNT0 register
*/
void timer0_TCNT0_value(uint8 val);


#endif /* TIMER0_OVERFLOW_MODE_H_ */