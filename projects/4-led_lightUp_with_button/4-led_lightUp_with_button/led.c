#include "led.h"

void LED_init(char port_name, uint8 pin_number)
{
    GPIO_pin_direction(port_name, pin_number, 1);
}


void LED_turn_on(char port_name, uint8 pin_number)
{
    GPIO_pin_write(port_name, pin_number, 1);
}


void LED_turn_off(char port_name, uint8 pin_number)
{
    GPIO_pin_write(port_name, pin_number, 0);
}


void LED_toggle(char port_name, uint8 pin_number)
{
    GPIO_pin_toggle(port_name, pin_number);
}


uint8 LED_status(char port_name, uint8 pin_number)
{
    return (GPIO_pin_read(port_name, pin_number));
}