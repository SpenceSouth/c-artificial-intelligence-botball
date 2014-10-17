#define numChannels 4
#include "header.h"
/*	
Channel 0: Black
Channel 1: Green
Channel 2: Purple
Channel 3: Red
*/


//void show_cam_image();

int main() {
    //Starting camera at low-resolution (higher framerate)
	int i,j;
	
//	graphics_open(80, 80);  // camera window in middle of the screen
	camera_open(LOW_RES);
	//printf("Awaiting optical input press B when the paper is staged. \n");
	while(1){
			//printf ("looping in da loop\n");
		
			camera_update();
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
			// This has returned maxIndex which is the color index of the 
			// color that had the most blocks
			
			
			
			//printf ("updating image\n");
			
			
			//show_cam_image();       // display camera image on Link
			//graphics_update();
					
			//printf ("Checking for button press\n");
			
			if (b_button()!=0)
				{
					//printf("Evaluating max blob count\n");
					if (maxIndex==0)
						{
							printf("I see black. Going backwards.\n");
							move (-50, 100);	
							printf("Move completed\n");
						}	
					if (maxIndex==1)
						{
							printf("I see green. Turning right.\n");
							turn (-550);
							printf("Move completed\n");
						}
					if(maxIndex==2)
						{
							printf("I see purple. Advancing.\n");
							move (50, 100);
							printf("Move completed\n");

						}
					if (maxIndex==3)
						{
							printf("I see red. Turning left.\n");
							turn (550);
							printf("Move completed\n");
						}
					printf("Awaiting optical input press B when the paper is staged.\n");
				}
		}
		

	
}
 
void show_cam_image(){

  const unsigned char *img=get_camera_frame();

  // Frame data is in BGR 888 pixel format: 3 bytes per pixel; each

  // character is the 8-bit (unsigned) integer value for each BGR color

  int row, col, rgb[3]={2,1,0}; // array used to convert BGR to RGB

  for(row=0;row<120;row++){

    for(col=0;col<160; col++){

      graphics_pixel(col,row,

      img[3*(160*row+col)+rgb[0]],img[3*(160*row+col)+rgb[1]],

      img[3*(160*row+col)+rgb[2]]);

    }

  }

}
