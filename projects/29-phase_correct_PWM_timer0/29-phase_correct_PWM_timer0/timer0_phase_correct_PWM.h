/*
 * timer0_phase_correct_PWM.h
 *
 * Created: 5/24/2022 9:52:35 PM
 *  Author: Mohamed Yasser
 */ 


#ifndef TIMER0_PHASE_CORRECT_PWM_H_
#define TIMER0_PHASE_CORRECT_PWM_H_

#include "Atmega_GPIO.h"

void timer0_phase_correct_PWM_init(void);

void timer0_phase_correct_PWM_set(uint16 duty_cycle);



#endif /* TIMER0_PHASE_CORRECT_PWM_H_ */