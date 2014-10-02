int main()
{
	int rport=0;
	int cport=1; 
	int lport=2;
	int leftmtr=0; 
	int rghtmtr=1; 			// identify port and motors
	int threshold=450; 									// set threshold for light conditions
	int high=60,low=-20; 								// set wheel powers for arc radius
	bool flag=false;
	
	/*if (analog10(cport)<500)
		threshold=400;
	*/
	printf("Line following: position robot on tape\n");
	printf("Press B button when ready\n\nPress side button to stop\n");
	while(b_button()==0&&!flag) {} 						// wait for button press
		while(side_button()==0){ 						// stop if button is pressed
			while (analog10(cport) > threshold) 
			{ 		// continue until not dark
				motor(leftmtr,low); 
				motor(rghtmtr,-1*(high+11)); 			// arc left
				
				printf( "Left: C: %d L: %d R: %D  T: %d \n",  analog10(cport), analog10(lport), analog10(rport),  threshold);
				if (analog10(lport)>threshold)
					{
						flag=true;
						break;
					}				
				if (side_button()!=0) 
					{
						flag=true;
						break;
					}	
			} 							// or button pressed
			while (analog10(cport) <= threshold)
			{ 				// continue until dark
				motor(leftmtr,high); 
				motor(rghtmtr,-1*(low+11)); 			// arc right
				printf( "Left: C: %d L: %d R: %D  T: %d \n",  analog10(cport), analog10(lport), analog10(rport), threshold);
				if (analog10(lport)>threshold)
					{
						flag=true;
						break;
					}
						
				if (side_button()!=0) 
					break; 
			} 							// or button pressed
	}
	
	
//switch sides of the line
	
while(b_button()==0) {} 						// wait for button press
		while(side_button()==0){ 						// stop if button is pressed
			while (analog10(cport) < threshold) 
			{ 		// continue until not dark
				motor(leftmtr,low); 
				motor(rghtmtr,-1*(high+11)); 			// arc left
				
				printf( "Left: C: %d L: %d R: %D  T: %d \n",  analog10(cport), analog10(lport), analog10(rport),  threshold);
										
				if (side_button()!=0) 
					break; 
			} 							// or button pressed
			while (analog10(cport) >= threshold)
			{ 				// continue until dark
				motor(leftmtr,high); 
				motor(rghtmtr,-1*(low+11)); 			// arc right
				printf( "Left: C: %d L: %d R: %D  T: %d \n",  analog10(cport), analog10(lport), analog10(rport), threshold);
							
				if (side_button()!=0) 
					break; 
			} 							// or button pressed
	}
	
	
	ao(); 															// stop because button pressed
	printf("done\n");
	return 0;
}
