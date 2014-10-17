#include "header.h"

void solenoidMove(char color){

	if(returnColor == 'g'){
		enable_servos();
		set_servo_position(0, 1700);
	} // end if sees green

	else if(returnColor == 'r'){
		enable_servos();
		set_servo_position(0, 300);
	} // end elif sees red
	
	else{
		enable_servos();
		set_servo_position(0, 1024);
	} // end else

} // end solenoidMove
