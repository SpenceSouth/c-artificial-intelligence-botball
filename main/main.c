// Created on Mon Sep 29 2014

#include "header.h"

int main() 
{
	printf("Exterminate!\n");
	
	//move(25, 1000);
	
	//550 is 90 degrees
	//turn(-550);  //Negative values should turn to the left.
	
	//Step 1: Moves 23 spaces
	turn(80);
	move(25,1000);
	msleep(1000);
	
	//Step 2
	move(25, 1150);
	
	//Step 3
	turn(410);
	move(25, 1000);
	
	//Step 4
	//move(25, 1700);
	
	//Step 5
	//move(25, 500);
	
	
	return 0;
}
