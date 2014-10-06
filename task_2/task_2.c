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
	printf("Center the robot and calibrate the left then right sensor to begin\n\n");
	
	

	//While the B button is not pressed, wait for input
	while(analog10(left_sensor) < 600)
	{
		
	}
	
	printf("Left sensor is ready\n\n");
	
	while(analog10(right_sensor) < 600)
	{
		
	}
	
	printf("Right sensor is ready\n\n");
	
	printf("Press B to begin\n");
	
	while(b_button() == 0)
	{
		
	}
	
	printf("Running\n\n");
	
	move(25, 100);
	
	while(1==1)
	{
	
		//While there is not turn available, keep on keeping on.
		while(isTurnAvailable() == 0)
		{
			moveForward(last_turn);
		}
		
		printf("Turn is available\n");
		
		if(isTurnAvailable() == 2)
		{
			leftTurn();
			last_turn = 1;
		}
		
		if(isTurnAvailable() == 1)
		{
			rightTurn();
			last_turn = 0;
		}
		
	}//End of while loop
	
	printf("Done");
	
	
	return 0;
}
