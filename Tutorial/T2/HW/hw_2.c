#include "main.h"
#include "buzzer.h"

#define BUTTON_NUMS 3

void update_new_buttons_state( uint8_t * buttons_state)
{
	uint8_t i;
	
	for(i = 0; i < BUTTON_NUMS; i++)
		buttons_state[i] = read_button(i);
}

void update_old_buttons_state(uint8_t * new_buttons_state, uint8_t *old_buttons_state)
{
	uint8_t i;
	
	for(i = 0; i < BUTTON_NUMS; i++)
		old_buttons_state[i] = new_buttons_state[i];
}

void button1_led_flash(uint8_t *current_on_led)
{
	uint8_t led = *current_on_led;
	
	led_off(led--);
	if(led == 255) led = 2;
	led_on(led);
	
	*current_on_led = led;
}

void button3_led_flash(uint8_t *current_on_led)
{
	uint8_t led = *current_on_led;
	
	led_off(led++);
	if(led == 3) led = 0;
	led_on(led);
	
	*current_on_led = led;
}

void button2_led_flash(uint8_t current_on_led, uint8_t *ledOn)
{
	if(*ledOn)
		led_off(current_on_led);
	else
		led_on(current_on_led);
	
	*ledOn = !(*ledOn);
}

void button2_off(uint8_t *current_on_led, uint8_t *ledOn)
{
	led_off(*current_on_led);
	//*current_on_led = 0;
	*ledOn = 0;
}

int main()
{
   //initialization, order matters
   ticks_init();
   led_init();
	 button_init();
	buzzer_init();
   
   //variables
   uint32_t ticks = 0;
	 uint32_t buttons_timer[] = {0, 0, 0};
   uint8_t current_on_led = 0;
	 uint8_t new_buttons_state[] = {1, 1, 1};
	 uint8_t old_buttons_state[] = {1, 1, 1};
	 uint8_t ledOn = 0;
	 uint8_t button2_on = 0;
	
	
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
					 update_new_buttons_state(new_buttons_state);
					 if(!button2_on){
						 if(!new_buttons_state[0] && new_buttons_state[2])
						 {
							 if(old_buttons_state[0] != new_buttons_state[0])
							 {
								 buttons_timer[0] = ticks;
								 button1_led_flash(&current_on_led);
							 }else if(ticks - buttons_timer[0] >= 500)
							 {
								 button1_led_flash(&current_on_led);
							
							 }
							 ledOn = 1;
						 }
						 
						 if(!new_buttons_state[2] && new_buttons_state[0]	)
						 {
							 if(old_buttons_state[2] != new_buttons_state[2])
							 {
								 buttons_timer[2] = ticks;
								 button3_led_flash(&current_on_led);
							 }else if(ticks - buttons_timer[2] >= 500)
								 button3_led_flash(&current_on_led);
							 
							 ledOn = 1;
						 }
						 
						 
					 }
					 
						 
					 
					 if(!new_buttons_state[1] && new_buttons_state[1] != old_buttons_state[1])
					 {
						 button2_on = !button2_on;
				
						 if(!button2_on)
							 button2_off(&current_on_led, &ledOn);
					 }
						 
				 }
				 
				 
				 if(!read_button(BUTTON1) && !read_button(BUTTON3))
						 {
							 led_on(current_on_led);
							 //current_on_led = 0;
							 //ledOn = 0;
						 }
				 
				 
				 
				 if(((ticks % (300 * (current_on_led + 1))) == 0) && button2_on)
					 button2_led_flash(current_on_led, &ledOn);
		
				 update_old_buttons_state(new_buttons_state, old_buttons_state);
      }
   }
}