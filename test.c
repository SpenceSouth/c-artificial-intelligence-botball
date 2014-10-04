int test()
 {
    int x, y, color;  //sets all variables to 0		
	camera_open(LOW_RES);
	while(side_button()==0) //while the a button isn't pressed
	{
		if(get_object_count(color) > 0) // If the right color is detected, run this code
		{
			x = get_object_center(color,0).x;
			y = get_object_center(color,0).y;   //x and y variables now represent x and y coordinates of the biggest color blob
 
			if(x>80)    //if the x coordinate is on the right			
			{
				printf("The biggest blob is on the right and the coordinates are (%d,%d)", x ,y);   //prints the words
			}
			else if(x<80)    //if x is on th left 			
			{
				printf("The biggest blob is on the left and the coordinates are (%d,%d)" ,  x ,y);  //print the words
			}
			else
			{
				printf("no object in sight");
			}
			camera_update();
		}
	}
}
