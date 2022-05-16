#ifndef __LED_DRIVER__
#define __LED_DRIVER__

/*******************************************************************************
*@file: led.h
*@author: Mohamed Yasser
*@brief: driver for led. (init, turnOn, turnOff, toggle, getStatus)
*How to use?
*   1- Init the led using:  LED_init(char port_name, uint8 pin_number);
*   2- Control led (on, off, toggle) using following functions.
*   3- You can get led status using: LED_status(char port_name, uint8 pin_number);
*******************************************************************************/


/*------------------- includes section: -------------------------*/
#include "Atmega_GPIO.h"
/*============================ end ==============================*/


/*------------------- functions prototypes: -------------------------*/


/*
function name: LED_init
function return: void
function arguments: (char port_name, uint8 pin_number)
function description: it initialize given pin number as output on the given port
*/
void LED_init(char port_name, uint8 pin_number);


/*
function name: LED_turn_on
function return: void
function arguments: (char port_name, uint8 pin_number)
function description: it turn on the led on the given pin and port
*/
void LED_turn_on(char port_name, uint8 pin_number);


/*
function name: LED_turn_off
function return: void
function arguments: (char port_name, uint8 pin_number)
function description: it turn off the led on the given pin and port
*/
void LED_turn_off(char port_name, uint8 pin_number);


/*
function name: LED_toggle
function return: void
function arguments: (char port_name, uint8 pin_number)
function description: it toggles the led on the given pin and port
*/
void LED_toggle(char port_name, uint8 pin_number);


/*
function name: LED_status
function return: uint8
function arguments: (char port_name, uint8 pin_number)
function description: it returns the status of LED; either on (1) of off (0)
*/
uint8 LED_status(char port_name, uint8 pin_number);


/*============================ end ==============================*/


#endif // __LED_DRIVER__