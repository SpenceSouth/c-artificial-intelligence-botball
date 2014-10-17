#include <stdio.h>

//Declare global variables array = (y,x) not (x,y)
int a[6][8] = {  
 {0, 1, 0, 0, 0, 2, 0, 2},
 {0, 0, 0, 2, 0, 0, 0, 1},
 {0, 1, 1, 0, 0, 0, 0, 2},
 {0, 0, 0, 0, 0, 2, 1, 0},
 {1, 0, 0, 0, 1, 0, 3, 0},
 {1, 0, 2, 2, 0, 0, 2, 0},
}; //white 0, red 1, green 2, purp 3

int locationX = 7;
int locationY = 3;
char facing = 'w';
char locationValue = 'w';

char getLocationColor(void)
{
	if(a[locationY][locationX] == 0)
	{
		return 'w';
	}
	else if(a[locationY][locationX] == 1)
	{
		return 'r';
	}
	else if(a[locationY][locationX] == 2)
	{
		return 'g';
	}
	else if(a[locationY][locationX] == 3)
	{
		return 'p';
	}
	else
	{
		printf("Some sort of error occured in getLocationColor");
	}
}

//returns 0 if false. 1 if true
int isCorner()
{
	if(locationX == 0 && locationY == 0)
	{
		return 1;
	}
	else if(locationX == 7 && locationY == 0)
	{
		return 1;
	}
	else if(locationX == 0 && locationY == 5)
	{
		return 1;
	}
	else if(locationX == 7 && locationY == 5)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void forward()
{
	if(facing == 'n')
	{
		locationY--;
	}
	else if(facing == 'e')
	{
		locationX++;
	}
	else if(facing == 'w')
	{
		locationX--;
	}
	else if(facing == 's')
	{
		locationY++;
	}
}

//Moves one square to the right of the relative forward facing position. Updates facing.
void right()
{
	if(facing == 'n')
	{
		locationX++;
		facing = 'e';
		return;
	}
	else if(facing == 'e')
	{
		locationY++;
		facing = 's';
		return;
	}
	else if(facing == 'w')
	{
		locationY--;
		facing = 'n';
		return;
	}
	else if(facing == 's')
	{
		locationX--;
		facing = 'w';
		return;
	}
}

//Moves one square to the left of the relative forward facing position.  Updates facing.
void left()
{
	if(facing == 'n')
	{
		locationX--;
		facing = 'w';
		return;
	}
	else if(facing == 'e')
	{
		locationY--;
		facing = 'n';
		return;
	}
	else if(facing == 'w')
	{
		locationY++;
		facing = 's';
		return;
	}
	else if(facing == 's')
	{
		locationX++;
		facing = 'e';
		return;
	}
}

void printLocation()
{
	printf("The robot is currently located at (%d,%d)\n", locationX, locationY);
	printf("The color of this space is %c\n", getLocationColor());
}

int notStraightPath()
{
	
	//Decs
	int right_sensor= 5;
	int center_sensor = 2;
	int left_sensor = 0;
	int light_dark = 500;
	int last_turn = 0;
	int dark = 500;
	
	if(analog10(left_sensor) > dark)
	{
		//printf("Black on left\n");
		return 2;
	}
	
	
	if(analog10(right_sensor) > dark)
	{
		//printf("Black on right\n");
		return 1;
	}
	
	
	return 0;
}

void turn(int angle){
	
	if(angle == 0){
		return;
	}
	
	int power = 45;
	int leftPower;
	int rightPower;
	int count = 0;
	int turnTime = angle;
	
	if(angle > 0){
		turnTime = angle;
	}
	else{
		turnTime = angle *-1;
	}
	
	if(angle > 0){
		leftPower = power * -1;
		rightPower = (power + 3) ;
	}
	else{
		leftPower = power;
		rightPower = (power + 3) * -1;
	}
	
	
	
	while(count < turnTime){
		motor(0, leftPower);
		motor(2, rightPower);
		count++;
	}
	
}

void move(int power, int time){
	
	int leftPower = power;
	int rightPower = (power + 3);
	int count = 0;
	
	while(count < time){
		motor(0, leftPower);
		motor(2, rightPower);
		count++;
	}
	
}

void solenoidMove(char color){

	if(color == 'g'){
		enable_servos();
		set_servo_position(0, 1700);
	} // end if sees green

	else if(color == 'r'){
		enable_servos();
		set_servo_position(0, 300);
	} // end elif sees red
	
	else{
		enable_servos();
		set_servo_position(0, 1024);
	} // end else

} // end solenoidMove

int main(void)
{
	
	//Decs
	int right_sensor= 5;
	int center_sensor = 2;
	int left_sensor = 0;
	int dark = 500; 
	int light_dark = 500;
	int last_turn = 0;
	
	
	printf("Starting line following program\n");
	
	printf("press b to start");
	while(b_button() == 0)
	{
		
	}
	
	printf("Running\n\n");
	
	printLocation();
	
	while(1==1)
	{
		while(notStraightPath() == 0 && analog10(center_sensor) < 600)
		{
			move(1 , 1);
		}
		
		//Center sensor has crossed the threshold for a box.  Update map.
		if(analog10(center_sensor) > 600)
		{
			forward();
			printLocation();
			solenoidMove(getLocationColor);
		}
		
		//While the center sensor is moving over the tape, keep moving forward.
		while(analog10(center_sensor) > 600)
		{
			move(1,1);
		}
		
		//Straighten out if necessary
		while( notStraightPath() ==1)
		{
				turn(10);
				move(1 , 1);
		}
		
		//Straighten out if necessary
		while( notStraightPath() == 2)
		{
				turn(-10);
				move(1 , 1);
		}
		

		
	}//End of while loop
	
	printf("Done");
	
	
	return 0;
}
