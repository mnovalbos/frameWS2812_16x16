#include "matrix.h"
//#include <SPI.h>
//#include <SD.h>

Adafruit_NeoPixel strip=Adafruit_NeoPixel(MATRIX_W*MATRIX_H, PIN, NEO_GRB + NEO_KHZ800);
//image=image_leds();*/
matrix_led::matrix_led()
{
   
   strip.begin();
   strip.show(); // Initialize all pixels to 'off'
//   image=NULL;
   brightness=32;
   
}

void matrix_led::loadImage(char* img_file)
{
  //if(image!=NULL){
    image.resetImage();
    image.loadImage(img_file);
  //}
}

void matrix_led::showImage(){
  
  color3_led_t color;
  char pixlcount=0; //255 max, 16*16
  image.nextFrame();
  for(char i=0;i<MATRIX_W;i++){    
    if(i%2){
      for(char j=0;j<MATRIX_H;j++){
        color=image.getColor(i*MATRIX_H+j);
        strip.setPixelColor(pixlcount,
        color.r,color.g,color.b);
        pixlcount++;        
      }
        
    }else{
      for(char j=(MATRIX_H-1);j>=0;j--){
          color=image.getColor(i*MATRIX_H+j);
          strip.setPixelColor(pixlcount,
          color.r,color.g,color.b);
          pixlcount++;
       }
    }
  }

  strip.setBrightness(brightness);
  strip.show();
}

void matrix_led::nextImage()
{

}

matrix_led::~matrix_led()
{
  
}

