#include "header.h"


void moveForward()
{
	
	//Decs
	int right_sensor= 0;
	int center_sensor = 1;
	int left_sensor = 2;
	int dark = 500; 
	int light_dark = 500;
	int last_turn = 0;
	
	//Moves the robot while the center sensor is the only one with input.
	while((analog10(center_sensor) > dark) && (analog10(right_sensor) < light_dark && analog10(left_sensor) < light_dark))
	{
		move(75, 1);
	}
	
	if(analog10(center_sensor) <= dark)
		{
			if(last_turn == 0)
			{
				turn(15);
			}
			else
			{
				turn(30);
			}
		}
		if(analog10(center_sensor) <= dark)
		{
			if(last_turn == 0)
			{
				turn(-30);
			}
			else
			{
				turn(-15);
			}
		}
}
