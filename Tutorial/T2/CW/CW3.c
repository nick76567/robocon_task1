#include "main.h"
#include "buzzer.h"


int main()
{
   //initialization, order matters
   ticks_init();
   led_init();
	 button_init();
	 buzzer_init();
	 
   
   //variables
   uint32_t ticks = 0;
	 uint8_t buzz_on = 0;
	 uint8_t current_button_on = 255;
	 uint16_t period = 0;
	
   //an infinite loop
   while(1)
   {
      //regulates time interval to every ms
      if(get_ticks() != ticks)
      {
         //get_ticks() returns the time past after ticks_init() is called, in ms
				 //updating the value stored in ticks
				 ticks = get_ticks();
				 
				 
				 //toggle led1 every 100ms
				 //ticks % PERIOD == REMAINDER
				 
				 if(ticks % 50 == 0){
					 if(current_button_on == 255)
					 {
						 if(!read_button(BUTTON1))
							 current_button_on = BUTTON1;
					 
						 else if(!read_button(BUTTON2))
							 current_button_on = BUTTON2;
						 
						 else if(!read_button(BUTTON3))
							 current_button_on = BUTTON3;
					 }
					 
					 else if(read_button(current_button_on))
					 {
						 current_button_on = 255;
						 buzzer_off();
					 }
				 }
				 
				 if(current_button_on != 255){
					 period = 1000 * (current_button_on + 1);
					 
					 if(ticks % period == 0)
						 buzzer_on();
					 
					 if(ticks % period == period / 2)
						 buzzer_off();
				 }
				 
      }
   }
}