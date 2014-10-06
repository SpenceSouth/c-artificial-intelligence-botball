#include "header.h"

void move(int power, int time){
	
	int leftPower = power;
	int rightPower = (power + 11);
	int count = 0;
	
	while(count < time){
		motor(0, leftPower);
		motor(2, rightPower);
		count++;
	}
		motor(0, 0);
		motor(2, 0);
	
	
}
