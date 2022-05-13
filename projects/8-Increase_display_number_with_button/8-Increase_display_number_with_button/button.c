#include "button.h"

void Button_init(char port_name, uint8 pin_number)
{
    GPIO_pin_direction(port_name, pin_number, 0);
}


void Button_init_with_internal_pull_up(char port_name, uint8 pin_number)
{
    GPIO_pin_pull_up(port_name, pin_number);
}


uint8 Button_read(char port_name, uint8 pin_number)
{
    uint8 button_status;
    button_status = GPIO_pin_read(port_name, pin_number);
    return button_status;
}