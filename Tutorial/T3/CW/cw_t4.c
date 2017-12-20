#include "main.h"
#include "buzzer.h"


int main()
{
   //initialization, order matters
   ticks_init();
   led_init();
	 button_init();
   //servo_init(143, 10000 ,450);
   motor_init(71, 200, 0); 
	
   //variables
   uint32_t ticks = 0;
	 uint16_t change = 50;
	 uint16_t oc = 0;
	 uint8_t new_button1 = 1;
	 uint8_t old_button1 = 1;
	 uint8_t new_button3 = 1;
	 uint8_t old_button3 = 1;
	 uint8_t direction = 0;
   uint8_t is_reach_max = 0;	
	 
	
	
	
	
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
					 new_button3 = read_button(BUTTON3);
					 
					 if(!new_button1 && new_button1 != old_button1)
					 {
						 oc += change;
						 
						 if(is_reach_max)
						 {
							 oc = 0;
							 is_reach_max = 0;
						 }
						 
							 
						 motor_control (MOTOR1, direction, oc);
						 
						 if(oc == 200)
							 is_reach_max = 1;
							 
					 }
					 
					 if(!new_button3 && new_button3 != old_button3)
					 {
						 direction = !direction;
						 motor_control (MOTOR1, direction, oc);
					 }
				 }
				 
				 old_button1 = new_button1;
				 old_button3 = new_button3;
			}
	 }
}