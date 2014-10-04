/* This sample program is a demo for using the graphics API to display the camera image along as many as 5 bounding boxes for blobs on color channel 0.  If a bounding box is touched, the program reports its number.

*/

 

void show_cam_image();

int main()

  {

    int n, b, tf, row, col, rgb[3]={255,0,0}; // color for box

    rectangle bbx[5]; // array of rectangles to hold up to 5 bounding boxes

    camera_open();    // open camera

    graphics_open(160, 120);  // camera window in middle of the screen

    display_clear(); // get rid of any messages from camera_open()

    while(!side_button()){    // physical button used for exit

      camera_update();        // new camera data

      show_cam_image();       // display camera image on Link

      n=get_object_count(0);

      n=n<5 ? n : 5;          // no more than 5 blobs processed

      if (n > 0) {  // if there is a blob, locate it and show its bbox

        for(b=0;b<n;b++){

          bbx[b] = get_object_bbox(0,b);

          if (bbx[b].width < 6 || bbx[b].height < 6) {

            n=b;

            break; // rest of blobs too small to worry about

          }

          graphics_rectangle(bbx[b].ulx,bbx[b].uly,(bbx[b].ulx+bbx[b].width),

                        (bbx[b].uly+bbx[b].height), rgb[0], rgb[1], rgb[2]);

        }

      }

      graphics_update(); // update Link screen

      if (get_mouse_left_button()) { // has user tapped the screen?

        get_mouse_position(&col, &row);

        tf=0;

        for(b=0; b<n; b++) {

          if ((col>=bbx[b].ulx) && (col<=(bbx[b].ulx+bbx[b].width)) &&

              (row>=bbx[b].uly) && (row<=(bbx[b].uly+bbx[b].height))) {

            display_printf(1,0,"blob %d      ",b);

            tf=1;  // tap flag

          }

        }

        if (tf==0) {

          display_printf(1,0,"not a blob    ",b);

        }

      }

    }

    // clean things up and exit

    camera_close();

    graphics_close();

    return 0;

}

 

// display the (default) camera 160x120 pixel image in a graphics window

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

 
