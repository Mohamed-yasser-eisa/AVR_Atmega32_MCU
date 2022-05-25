/*
 * timer0_CTC_mode.h
 *
 * Created: 5/23/2022 7:03:30 PM
 *  Author: Mohamed Yasser
 */ 


#ifndef TIMER0_CTC_MODE_H_
#define TIMER0_CTC_MODE_H_

#include "Atmega_GPIO.h"
#include <avr/interrupt.h>


/*
function name: timer0_ctc_init
function arguments: (uint8 OCR0_val)
function return: void
function description: It initiate timer0 in CTC mode with the given value for OCR0 register
*/
void timer0_ctc_init(void);



#endif /* TIMER0_CTC_MODE_H_ */