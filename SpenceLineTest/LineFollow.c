#include "header.h"

int main(void)
{
	
	//Decs
	int right_sensor= 0;
	int center_sensor = 1;
	int left_sensor = 2;
	int dark = 500; 
	int light_dark = 500;
	int last_turn = 0;
	
	
	
	printf("Starting line following program\n");
	printf("Center the robot and then press the B button to begin\n\n");
	
	

	//While the B button is not pressed, wait for input
	while(b_button() == 0)
	{
		
	}
	
	printf("Running\n\n");
	
	//Keep running until the kill switch is activated
	while(side_button() == 0)
	{
			
		
		//Moves the robot while the center sensor is the only one with input.
		while((analog10(center_sensor) > dark) && (analog10(right_sensor) < light_dark && analog10(left_sensor)))
		{
			move(1, 1);
		}
		
		//Handle then the robot strays outside of the blackline
		if((analog10(center_sensor) <= dark) && (analog10(right_sensor) < dark && analog10(left_sensor) < dark))
		{
			if(last_turn == 0)
			{
				turn(30);
			}
			else
			{
				turn(45);
			}
		}
		if((analog10(center_sensor) <= dark) && (analog10(right_sensor) < dark && analog10(left_sensor) < dark))
		{
			if(last_turn == 0)
			{
				turn(-45);
			}
			else
			{
				turn(-30);
			}
		}
		
		//Turn right when right sensor has dark value
		if((analog10(center_sensor) > dark) && (analog10(right_sensor) > light_dark))
		{
			printf("Turning right: %d\n", analog10(right_sensor));
			last_turn = 0;
			while(analog10(right_sensor) > light_dark){
				turn(-50);
				move(20,5);
				printf("Current center sensor value: %d\n", analog10(center_sensor));
			}
		}
		
		//Turn left when left sensor has dark value
		if((analog10(center_sensor) > dark) && (analog10(left_sensor) > light_dark))
		{	
			printf("Left sensor and center sensor are black, turning left: %d\n", analog10(left_sensor));
			last_turn = 1;
			while(analog10(left_sensor) > dark)
			{
				printf("Current center sensor value: %d\n", analog10(center_sensor));
					turn(15);
					move(5,5);
				while(analog10(center_sensor) < dark)
				{
					turn(10);
					move(1,5);
				}
			}
			
			//return 1;	
		}
		
	}
	
	printf("Program finished to completion\n");

	return 0;
}
