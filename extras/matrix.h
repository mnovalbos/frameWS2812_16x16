#include "image.h"
#include <Adafruit_NeoPixel.h>

#ifndef _IMAGE_MATRIX_H_
#define _IMAGE_MATRIX_H_


#define PIN 6
#define MATRIX_W 16
#define MATRIX_H 16


class matrix_led{
  public:
    //Adafruit_NeoPixel strip; 
    char brightness;
    image_leds image;

    
    matrix_led();
    void showImage();
    void nextImage();
    void loadImage(char* mg_file);
    ~matrix_led();
};


#endif
