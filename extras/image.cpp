#include "image.h"
//#include <SPI.h>
//#include <SD.h>

//#define NULL 0x00



image_leds::image_leds()
{
    numFrames=0;
    selectedFrame=0;
    w=0;
    h=0;
    //memset(&palette,0,sizeof(palette_led_t));
//    colors=NULL;
}

void image_leds::loadImage(char* image)
{
 /* File myFile;
  char i=0;
  
  myFile = SD.open(image, FILE_READ);
  myFile.read(&w,1);
  myFile.read(&h,1);
  myFile.read(&numFrames,1);
  myFile.read(&(palette.numColors),1);
  palette.colors=(color3_led_t*)malloc(sizeof(color3_led_t)*palette.numColors);
  myFile.read(palette.colors,sizeof(color3_led_t)*palette.numColors);
  colors=(char**)malloc(sizeof(char*)*numFrames);
  for(i=0;i<numFrames;i++)
  {
     colors[i]=(char*)malloc(sizeof(char)*w*h);
     myFile.read(colors[i],sizeof(char)*w*h);
  }
  */
  
  w=16;
  h=16;
  numFrames=4;
  
}
void image_leds::nextFrame()
{
  selectedFrame=(selectedFrame++)%numFrames;
}

color3_led image_leds::getColor(char idx_pixel){
  return palette.colors[colors[selectedFrame][idx_pixel]];
}

void image_leds::resetImage()
{
  numFrames=0;
  selectedFrame=0;
  w=0;
  h=0;
  //memset(&palette,0,sizeof(palette_led_t));
//  colors=NULL;
}

image_leds::~image_leds()
{
  resetImage();
}

