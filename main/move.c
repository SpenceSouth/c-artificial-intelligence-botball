#include "header.h"

void move(int power, int time){
	
	int leftPower = power + 12;
	int rightPower = (power + 12)*-1;
	int count = 0;
	
	while(count < time){
		motor(0, leftPower);
		motor(1, rightPower);
		count++;
	}
	
}
