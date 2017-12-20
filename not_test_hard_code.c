//good luck
//on line == 0
//out line == 1
#include "main.h"
#include "grapper.h"
#include "grapper_controller.h"
#include "encoder.h"	

#define MAX_MOTOR1_MAG MAX_MOTOR_MAG - 14
#define MAX_MOTOR2_MAG MAX_MOTOR_MAG

int main(){
	ticks_init();
	tft_init(0, BLACK, WHITE, RED);
	grapper_init();
	grapper_controller_init();
	button_init();
	
	uint32_t ticks = 0;
	uint8_t	stage = MANUAL_MODE;
	
	while(1)
	{
		if(ticks != get_ticks())
		{
			ticks = get_ticks();
			
			if(ticks % 50 == 0)
			{
				if(read_button(BUTTON1) == 0)
				{
					stage = MANUAL_MODE;
					
				}
				
				if(read_button(BUTTON3) == 0)
				{
					stage = FORWARD_4_LINE;
					ticks_reset();
				}
			}
			
			if(stage == FORWARD_4_LINE){
				motor_control(MOTOR1, !FORWARD, MAX_MOTOR1_MAG);
				motor_control(MOTOR2, FORWARD, MAX_MOTOR2_MAG);
				
				if(ticks >= 7000)
				{
					motor_control(MOTOR1, !FORWARD, MIN_MOTOR_MAG);
					motor_control(MOTOR2, FORWARD, MIN_MOTOR_MAG);
					
					pneumatic_control(PNEUMATIC1, 1);
					pneumatic_control(PNEUMATIC2, 1);
					
					stage = FORWARD_4_LINE_2;
					
					
					continue;
				}		
				
			}else if(stage == FORWARD_4_LINE_2)
			{
				motor_control(MOTOR1, !FORWARD, MAX_MOTOR1_MAG);
				motor_control(MOTOR2, FORWARD, MAX_MOTOR2_MAG);
				
				if(ticks >= 10000)
				{
					motor_control(MOTOR1, !FORWARD, MIN_MOTOR_MAG);
					motor_control(MOTOR2, FORWARD, MIN_MOTOR_MAG);
					
					
					stage = PICK_FRISBEE;
					
					continue;
				}
			}else if(stage == PICK_FRISBEE){
				pick_frisbee();
				
				stage = TURNR_45_DEGREE;
			}else if(stage == TURNR_45_DEGREE){
				motor_control(MOTOR1, BACKWARD, MAX_MOTOR1_MAG);
				motor_control(MOTOR2, BACKWARD, MAX_MOTOR2_MAG);
				
				if(ticks >= 10500)
				{
					motor_control(MOTOR1, !FORWARD, MIN_MOTOR_MAG);
					motor_control(MOTOR2, FORWARD, MIN_MOTOR_MAG);
													
					stage = BACKWARD_45_DEGREE;
						
					continue;
				}
				
			}else if(stage == BACKWARD_45_DEGREE){
				motor_control(MOTOR1, !BACKWARD, MAX_MOTOR1_MAG);
				motor_control(MOTOR2, BACKWARD, MAX_MOTOR2_MAG);
				
				if(ticks >= 13000)
				{
					motor_control(MOTOR1, !BACKWARD, MIN_MOTOR_MAG);
					motor_control(MOTOR2, BACKWARD, MIN_MOTOR_MAG);
					
					while(read_button(BUTTON1) != 0)
					
					stage = TURNR_45_DEGREE_2;
				
						
					continue;
				}
				
			}else if(stage == TURNR_45_DEGREE_2){
				motor_control(MOTOR1, BACKWARD, MAX_MOTOR1_MAG);
				motor_control(MOTOR2, BACKWARD, MAX_MOTOR2_MAG);
				
				if(ticks >= 13500)
				{
					motor_control(MOTOR1, !FORWARD, MIN_MOTOR_MAG);
					motor_control(MOTOR2, FORWARD, MIN_MOTOR_MAG);
					
					while(read_button(BUTTON1) != 0)
					
					stage = BACKWARD_45_DEGREE;
					
					continue;
				}				
				
			}else if(stage == BACKWARD_SQUARE){
				motor_control(MOTOR1, !BACKWARD, MAX_MOTOR1_MAG);
				motor_control(MOTOR2, BACKWARD, MAX_MOTOR2_MAG);
				
				if(ticks >= 15500)
				{
					motor_control(MOTOR1, !FORWARD, MIN_MOTOR_MAG);
					motor_control(MOTOR2, FORWARD, MIN_MOTOR_MAG);
					
					while(read_button(BUTTON1) != 0)
					
					stage = PLACE_FRISBEE_1;
					
					continue;
				}			
				
			}else if(stage == PLACE_FRISBEE_1){
				place_frisbee();
				pick_frisbee();
				
				while(read_button(BUTTON1) != 0)
				
				stage = BACKWARD_2_LINE;
				
			}else if(stage == BACKWARD_2_LINE){
				motor_control(MOTOR1, !BACKWARD, MAX_MOTOR1_MAG);
				motor_control(MOTOR2, BACKWARD, MAX_MOTOR2_MAG);
				
				if(ticks >= 23000)
				{
					motor_control(MOTOR1, !FORWARD, MIN_MOTOR_MAG);
					motor_control(MOTOR2, FORWARD, MIN_MOTOR_MAG);
					
					while(read_button(BUTTON1) != 0)
					
					stage = TURNR_180_DEGREE;
					
					continue;
				}				
				
			}else if(stage == TURNR_180_DEGREE){
				motor_control(MOTOR1, BACKWARD, MAX_MOTOR1_MAG);
				motor_control(MOTOR2, BACKWARD, MAX_MOTOR2_MAG);
				
				if(ticks >= 25000)
				{
					motor_control(MOTOR1, !FORWARD, MIN_MOTOR_MAG);
					motor_control(MOTOR2, FORWARD, MIN_MOTOR_MAG);
					
					while(read_button(BUTTON1) != 0)
				
					stage = PLACE_FRISBEE_2;
				}
			}else if(stage == PLACE_FRISBEE_2){
				place_frisbee();
				pick_frisbee();
				
				while(read_button(BUTTON2) != 0){}
					
					stage = TURNR_45_DEGREE_3;
			}else if(stage == TURNR_45_DEGREE_3)
			{
				motor_control(MOTOR1, BACKWARD, MAX_MOTOR1_MAG);
				motor_control(MOTOR2, BACKWARD, MAX_MOTOR2_MAG);
				
				if(ticks >= 32500)
				{
					motor_control(MOTOR1, !FORWARD, MIN_MOTOR_MAG);
					motor_control(MOTOR2, FORWARD, MIN_MOTOR_MAG);
					
					while(read_button(BUTTON1) != 0)
					
					stage = BACKWARD_START;
					
					continue;
				}		
			}else if(stage == BACKWARD_START)
			{
				motor_control(MOTOR1, !BACKWARD, MAX_MOTOR1_MAG);
				motor_control(MOTOR2, BACKWARD, MAX_MOTOR2_MAG);
				
				if(ticks >= 25000)
				{
					motor_control(MOTOR1, !FORWARD, MIN_MOTOR_MAG);
					motor_control(MOTOR2, FORWARD, MIN_MOTOR_MAG);
					
					while(read_button(BUTTON1) != 0)
					
					stage = MANUAL_MODE;
					
					continue;
				}
			}else if(stage == MANUAL_MODE)
			{
				
			}
			
			tft_prints(0, 0, "stage: %d", stage);
			tft_update();
		}
	}

	
	

		
}
