#ifndef __BUTTON_HEADER__
#define __BUTTON_HEADER__


/*******************************************************************************
*@file: button.h
*@author: Mohamed Yasser
*@brief: driver for push button
*@How_to_use?
*   1- Init the pin which is connected to the button using init function
*   2- use read function to read status of button
*******************************************************************************/


/*------------------- includes section: -------------------------*/
#include "Atmega_GPIO.h"
/*============================ end ==============================*/


/*------------------- functions prototypes: -------------------------*/


/*
function name: Button_init
function return: void 
function arguments: (char port_name, uint8 pin_number);
function description: it initialize the pin of port as input for the button use.
*/
void Button_init(char port_name, uint8 pin_number);

/*
function name: Button_init_with_internal_pull_up
function return: void 
function arguments: (char port_name, uint8 pin_number);
function description: it initialize the pin of port as input for the button and turn on internal pull up resistor.
*/
void Button_init_with_internal_pull_up(char port_name, uint8 pin_number);


/*
function name: Button_read
function return: uint8 
function arguments: (char port_name, uint8 pin_number);
function description: it returns the value of pin in port conected to the button.
*/
uint8 Button_read(char port_name, uint8 pin_number);


/*============================ end ==============================*/



#endif //__BUTTON_HEADER__