#include "main.h"

u32 ticks = 0;
uint8_t input = 0;
uint8_t new_button_state = 1, old_button_state = 1;
uint16_t oc = 450, change = 30;

void UARTListener(const uint8_t byte)
{
	input = byte;
}

int main(){
  //initialization
  ticks_init();
  ticks_reset();
	button_init();
	servo_init(143, 10000 ,450);
	uart_init(COM3, 115200);
	uart_interrupt_init(COM3, UARTListener);
	

  while(1)
	{
    if(ticks != get_ticks())
		{
      ticks = get_ticks();

      if(ticks % 50 == 0)
			{
				new_button_state = read_button(BUTTON1);
				
				if(input == 'q' && oc < 1050)
				{
					oc += change;
					servo_control(SERVO1, oc);
				}
				
				if(input == 'e' && oc > 450)
				{
					oc -= change;
					servo_control(SERVO1, oc);
				}
				
				if(input == ' ')
				{
					servo_control(SERVO1, oc);
				}
				
				if(!new_button_state && old_button_state != new_button_state)
				{					
					uart_tx(COM3, "Duty cycle: %0.2f%%\n", (float)(oc) / 100);
				}
      }
			
			old_button_state = new_button_state;
    }
  }
}
