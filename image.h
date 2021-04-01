
#include <Adafruit_NeoPixel.h>
#include <EEPROM.h>
#include <SPI.h>
#include <SD.h>

#ifndef _IMAGE_LED_H_
#define _IMAGE_LED_H_

#define MATRIX_W 16
#define MATRIX_H 16


#define MTX_PIN_UP 6
#define MTX_PIN_DOWN 7

void nextFrame();
void nextBrightness();
void prevBrightness();
void showImage();
void showImageProgramIR(char pos);

void loadImage(char* img_file);
void loadImageEEPROM();
void loadNextFile();
void loadPrevFile();
#endif
