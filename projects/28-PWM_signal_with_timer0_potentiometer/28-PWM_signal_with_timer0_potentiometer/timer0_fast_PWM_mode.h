/*
 * timer0_fast_PWM_mode.h
 *
 * Created: 5/24/2022 5:15:43 PM
 *  Author: Mohamed Yasser
 */ 


#ifndef TIMER0_FAST_PWM_MODE_H_
#define TIMER0_FAST_PWM_MODE_H_

#include "Atmega_GPIO.h"

void timer0_fast_PWM_init(void);

void set_duty_cycle(uint16 duty_cycle);



#endif /* TIMER0_FAST_PWM_MODE_H_ */