int main()
{
	int rport=0;
	int cport=1; 
	int lport=2;
	leftmtr=0; 
	rghtmtr=1; 			// identify port and motors
	int threshold=400; 									// set threshold for light conditions
	int high=60,low=-20; 								// set wheel powers for arc radius
	/*if (analog10(cport)<500)
		threshold=400;
	*/
	printf("Line following: position robot on tape\n");
	printf("Press B button when ready\n\nPress side button to stop\n");
	while(b_button()==0) {} 						// wait for button press
		while(side_button()==0){ 						// stop if button is pressed
			while (analog10(cport) > threshold) 
			{ 		// continue until not dark
				motor(leftmtr,low); 
				motor(rghtmtr,-1*(high+11)); 			// arc left
				
				printf( "Arcing left: Analog10 = %d  T: %d \n",  analog10(cport), threshold);
				
				if (side_button()!=0) 
					break; 
			} 							// or button pressed
			while (analog10(cport) <= threshold)
			{ 				// continue until dark
				motor(leftmtr,high); 
				motor(rghtmtr,-1*(low+11)); 			// arc right
				printf( "Arcing right: Analog10 = %d T: %d \n",  analog10(cport), threshold);
				
				if (side_button()!=0) 
					break; 
			} 							// or button pressed
	}
	ao(); 															// stop because button pressed
	printf("done\n");
	return 0;
}
