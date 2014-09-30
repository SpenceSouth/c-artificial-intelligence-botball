#include "header.h"

void turn(int angle){
	
	if(angle == 0){
		return;
	}
	
	int power = 25;
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
		printf("Allen tell spence 1");
		leftPower = power * -1;
		rightPower = (power + 10) * -1;
	}
	else{
		printf("Allen tell spence 2");
		leftPower = power;
		rightPower = (power + 10) * 1;
	}
	
	
	
	while(count < turnTime){
		motor(0, leftPower);
		motor(1, rightPower);
		count++;
	}
	
}
