#include "main.h"
#include "buzzer.h"


int main()
{
   //initialization, order matters
   ticks_init();
   led_init();
	 button_init();
   servo_init(143, 10000 ,750);
   //motor_init(71, 200, 0); 
	
   //variables
   uint32_t ticks = 0;
	 uint16_t change = 15;
	 uint16_t oc = 750;
	 uint8_t new_button1 = 1;
	 uint8_t old_button1 = 1;
	 uint8_t new_button2 = 1;
	 uint8_t old_button2 = 1;
	 uint8_t new_button3 = 1;
	 uint8_t old_button3 = 1;
	 
	
	
	
	
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
				   new_button1 = read_button(BUTTON1);
					 new_button2 = read_button(BUTTON2);
					 new_button3 = read_button(BUTTON3);
					 
					 if(!new_button1 && new_button3)
					 {
						 oc -= change;
						 if(oc < 450)
							 oc = 450;
					
						 servo_control(SERVO1, oc);
					 }
					 
					 if(!new_button3 && new_button1)
					 {
					   oc += change;
						 if(oc > 1050)
							 oc = 1050;
					
						 servo_control(SERVO1, oc);
					 }
					 
					 if(!new_button2 && new_button2 != old_button2)
					 {
						 if(change == 30)
							 change = 15;
						 
						 else if(change == 15)
							 change = 30;
					 }
					 
				 }
				 
				 old_button1 = new_button1;
				 old_button2 = new_button2;
				 old_button3 = new_button3;
			}
	 }
}