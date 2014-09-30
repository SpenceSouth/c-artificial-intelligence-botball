#include "header.h"

void move(int power, int time){
	
	int leftPower = power;
	int rightPower = (power + 10)*-1;
	int count = 0;
	
	while(count < time){
		motor(0, leftPower);
		motor(1, rightPower);
		count++;
	}
	
}
