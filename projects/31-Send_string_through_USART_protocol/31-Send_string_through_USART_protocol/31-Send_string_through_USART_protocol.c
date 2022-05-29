/*
 * _31_Send_string_through_USART_protocol.c
 *
 * Created: 5/28/2022 10:33:04 PM
 *  Author: Mohamed Yasser
 */ 


#include "USART.h"
#include "button.h"

int main(void)
{
	Button_init_with_internal_pull_up('C',0);
	USART_init();
	/*send string through USART*/
	while(1)
	{
		if (0 == Button_read('C',0))
		{
			/*It's not good to use delay. But use it here for simplicity*/
			_delay_ms(150); 
			if (0 == Button_read('C',0))
			{
				USART_send_string("Button pressed");
			}				
		}
	}
	
}