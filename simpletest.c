// Created on Mon September 29 2014

int main()
{
	//Motor 0 is left wheel, Motor 1 is right wheel
	
	printf("Hello, World!\n");
	
	//go forward
	printf("Going forward");
	mav(0,100);
	mav(1,100);
	msleep(3);
	
	//go backwards
	printf("Going backwards");
	mav(0,-100);
	mav(1,-100);
	msleep(3);
	
	//go left
	printf("Going left");
	mav(0,-100);
	mav(1,100);
	msleep(3);
	
	//go right
	printf("Going right");
	mav(0,100);
	mav(1,-100);
	msleep(3);
	
	return 0;
}
