#include "header.h"

void rightTurn()
{	
	//Decs
	int right_sensor= 0;
	int center_sensor = 1;
	int left_sensor = 2;
	int dark = 500;
	int last_turn = 0;
	
	//Move forward until the right sensor is off of black
	while(analog10(right_sensor) > dark)
	{
		move(1,1);
	}
	
	//Then move some more spaces
	move(25, 100);
	
	//Turn at least 45 degrees
	turn(-225);
	
	//Then turn until the center sensor is on black again
	while(analog10(center_sensor) < dark)
	{
		turn(-5);
	}
	
	printf("Found the path again\n");
	
	
}
