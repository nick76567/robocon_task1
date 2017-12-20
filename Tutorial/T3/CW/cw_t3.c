#include "main.h"
#include "buzzer.h"


int main()
{
   //initialization, order matters
   ticks_init();
   led_init();
	 button_init();
   servo_init(143, 10000 ,450);
   
   //variables
   uint32_t ticks = 0;
	 int8_t change = 30;
	 uint16_t oc = 450;
	
	
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
					 if(oc == 1050)
						 change = -30;
					 
					 if(oc == 450)
						 change = 30;
					 
					 oc += change;
					 servo_control(SERVO1, oc);
				 }
			}
	 }
}