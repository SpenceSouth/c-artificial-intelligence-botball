#define numChannels 4

/*	
Channel 0: Black
Channel 1: Green
Channel 2: Purple
Channel 3: Red
*/

int main() {
    //Starting camera at low-resolution (higher framerate)
	camera_open(LOW_RES);
	while(1){
		camera_update();
		int maxCount = 0;
		int maxIndex = 0;
		int colors[numChannels];
		for(int i = 0; i < numChannels; i++){
			colors[i] = get_object_count(i);
		}
		
		for(int j = 0; j < numChannels; j++){
			if(colors[j] > maxCount){
				maxCount = colors[j];
				maxIndex = j;
			}
		}
		
		switch(maxIndex){
			case 0:	printf("I see black.\n");
					break;
			case 1:	printf("I see green.\n");
					break;
			case 2:	printf("I see purple.\n");
					break;
			case 3:	printf("I see red.\n");
					break;
		}
		
		msleep(500);
	}
}
