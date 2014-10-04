#define numChannels 4
#include "header.h"
/*	
Channel 0: Black
Channel 1: Green
Channel 2: Purple
Channel 3: Red
*/


void show_cam_image();

int main() {
    //Starting camera at low-resolution (higher framerate)
	int i,j;
	
	graphics_open(160, 120);  // camera window in middle of the screen
	camera_open(LOW_RES);
	while(1){
		camera_update();
		int maxCount = 0;
		int maxIndex = 0;
		int colors[numChannels];
		for( i = 0; i < numChannels; i++){
			colors[i] = get_object_count(i);
		}
		
		for(j = 0; j < numChannels; j++){
			if(colors[j] > maxCount){
				maxCount = colors[j];
				maxIndex = j;
			}
		}
		show_cam_image();       // display camera image on Link

		switch(maxIndex){
			case 0:	printf("I see black. Going backwards.\n");
				move (-30, 10);	
				break;
			case 1:	printf("I see green. Turning right.\n");
				turn (-90);
					break;
			case 2:	printf("I see purple. Advancing.\n");
				move (30, 10);
					break;
			case 3:	printf("I see red. Turning left.\n");
				turn (90);
					break;
		}
		
		msleep(5000);
		printf ("Looking for another color in 5 seconds");
		msleep(1000);
		printf ("Looking for another color in 4 seconds");
		msleep(1000);
		printf ("Looking for another color in 3 seconds");
		msleep(1000);
		printf ("Looking for another color in 2 seconds");

		msleep(1000);
		printf ("Looking for another color in 1 seconds");
		
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
