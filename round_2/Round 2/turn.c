#include "header.h"

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
