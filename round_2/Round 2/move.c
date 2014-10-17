#include "header.h"

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
