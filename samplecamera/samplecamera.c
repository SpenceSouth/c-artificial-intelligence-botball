#define numChannels 3
#include "header.h"
/*	
Channel 0: Purple
Channel 1: Green
Channel 2: Red
not used  Channel 3: 
*/


//void show_cam_image();

char samplecamera() {
    //Starting camera at low-resolution (higher framerate)
	int i,j;
	
//	graphics_open(80, 80);  // camera window in middle of the screen
	camera_open(LOW_RES);
	//printf("Awaiting optical input press B when the paper is staged. \n");
	while(1){
			//printf ("looping in da loop\n");
		
			camera_update();
			char returnColor;
			int maxCount = 0;
			int maxIndex = 0;
			int colors[numChannels];
			for( i = 0; i < numChannels; i++){
				colors[i] = get_object_count(i);
			}
			//printf ("Counting blobs\n");
			for(j = 0; j < numChannels; j++){
				if(colors[j] > maxCount){
					maxCount = colors[j];
					maxIndex = j;
				// need to add a limit so that if it sees red dust on a 
				//	white square we don't get red
					
				}
			}
			
			/*	
Channel 0: Purple
Channel 1: Green
Channel 2: Red
not used  Channel 3: 
*/

			
			if (maxCount<20)
			{
					maxIndex=-1;
			}
			if (maxIndex==0)
			{
				returnColor='p';
			}
			else if (maxIndex==1)
			{
				returnColor='g';
				solenoidMove(returnColor);
			}
			else if (maxIndex==2)
			{
				returnColor='r';
				solenoidMove(returnColor);
			}
			else 
			{
				returnColor='w';
			}
			
		return (returnColor);
		}
			
			// This has returned maxIndex which is the color index of the 
			// color that had the most blocks
