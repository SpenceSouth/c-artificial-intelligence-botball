
void move(int power, int time){
	
	int leftPower = power;
	int rightPower = (power + 11)*-1;
	int count = 0;
	
	while(count < time){
		motor(0, leftPower);
		motor(1, rightPower);
		count++;
	}
	
}

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
		leftPower = power * -1;
		rightPower = (power + 10) * -1;
	}
	else{
		leftPower = power;
		rightPower = (power + 10) * 1;
	}
	
	
	
	while(count < turnTime){
		motor(0, leftPower);
		motor(1, rightPower);
		count++;
	}
	
}


int main()
{
	int rport=0;
	int cport=1; 
	int lport=2;
	int leftmtr=0; 
	int rghtmtr=1; 			// identify port and motors
	int threshold=800; 									// set threshold for light conditions
	int high=50,low=-10; 								// set wheel powers for arc radius
	int flag=0;
	
	turn(90*6.1)
	
	/*if (analog10(cport)<500)
		threshold=400;
	*/
	//Step 1: Moves 23 spaces
	/*turn(90*6.1);
	move(25,1000);*/

	printf("Line following: position robot on tape\n");
	printf("Press B button when ready\n\nPress side button to stop\n");
	/*while(b_button()==0) {} 						// wait for button press
		while(side_button()==0&&flag==0)
		{ 						// stop if button is pressed
			while (analog10(cport) > threshold) 
			{ 		// continue until not dark
				motor(leftmtr,low); 
				motor(rghtmtr,-1*(high+11)); 			// arc left
				
				printf( "Left: C: %d L: %d R: %d  T: %d \n",  analog10(cport), analog10(lport), analog10(rport),  threshold);
				if (analog10(lport)>threshold)
					{
						flag=1;
						break;
					}				
				if (side_button()!=0) 
					{
						flag=1;
						break;
					}	
			} 							// or button pressed
			while (analog10(cport) <= threshold)
			{ 				// continue until dark
				motor(leftmtr,high); 
				motor(rghtmtr,-1*(low+11)); 			// arc right
				printf( "Right: C: %d L: %d R: %d  T: %d \n",  analog10(cport), analog10(lport), analog10(rport), threshold);
				if (analog10(lport)>threshold)
					{
						flag=1;
						break;
					}
						
				if (side_button()!=0) 
					break; 
			} 							// or button pressed
	}
	
	
//switch sides of the line
	
		while(side_button()==0){ 						// stop if button is pressed
			while (analog10(cport) < threshold) 
			{ 		// continue until not dark
				motor(leftmtr,low); 
				motor(rghtmtr,-1*(high+11)); 			// arc left
				
				printf( "2 Left: C: %d L: %d R: %d  T: %d \n",  analog10(cport), analog10(lport), analog10(rport),  threshold);
										
				if (side_button()!=0) 
					break; 
			} 							// or button pressed
			while (analog10(cport) >= threshold)
			{ 				// continue until dark
				motor(leftmtr,high); 
				motor(rghtmtr,-1*(low+11)); 			// arc right
				printf( "2 Right: C: %d L: %d R: %D  T: %d \n",  analog10(cport), analog10(lport), analog10(rport), threshold);
							
				if (side_button()!=0) 
					break; 
			} 							// or button pressed
	}*/
	
	
	ao(); 															// stop because button pressed
	printf("done\n");
	return 0;
}
