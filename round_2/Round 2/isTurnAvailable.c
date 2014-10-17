#include "header.h"

int isTurnAvailable()
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
		printf("Turn available on left\n");
		return 2;
	}
	
	
	if(analog10(right_sensor) > dark)
	{
		printf("Turn available on right\n");
		return 1;
	}
	
	
	return 0;
}
