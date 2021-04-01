
/*#include <boarddefs.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

*/
#include <IRremote.h>
#include <IRremoteInt.h>
#include "eepromMap.h"
#include "image.h"
#include "buttonsIR.h"



#define SHOW_IMAGE  0
#define PROGRAM_IR  1

Adafruit_NeoPixel strip=Adafruit_NeoPixel();
unsigned long ticLeds,ticIR, tac ;
IRrecv recv= IRrecv(IR_PIN);
decode_results button;

File myFile;
char mode=0;

void setup() {

  ticLeds=millis();
  ticIR=0;
  SD.begin(4);
 // if(!isEEPROMFormatted())
  //{
   // formatEEPROM();
    loadImage("default1.led");
    //saveButtonsIR();
    
  //}else
  //{
    //loadImageEEPROM();
  //}

  strip.updateType(NEO_GRB + NEO_KHZ800);
  strip.updateLength(MATRIX_W*MATRIX_H/2);
  strip.setPin(MTX_PIN_UP);

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setPin(MTX_PIN_DOWN);
  strip.show();
  
  //loadButtonsIR();
  resetInterruptsButtonIR();
  //mode=PROGRAM_IR;
  mode=SHOW_IMAGE;

}

/*
*/

void checkRefreshImage(char pos)
{
  unsigned long interval=500;
  if((unsigned long)(tac-ticLeds)>=interval)
    {
      switch(mode)
      {
        case SHOW_IMAGE:
            showImage();
            break;
        case PROGRAM_IR:
            showImageProgramIR(pos);
            break;
        default:
            break;
      }      
      ticLeds=tac;
    }
}

void checkButtons()
{
  //unsigned long button;
  if(recv.decode(&button))
  {
    if(button.value!=0xFFFFFFFF){
      if(button.value==buttonsIR_Id[B_BRIGHTUP]){
            nextBrightness();
      }else if(button.value==buttonsIR_Id[B_BRIGHTDOWN]){
            nextBrightness();
      }else if(button.value==34467855){
            loadNextFile();
      }else if(button.value==buttonsIR_Id[B_PREVIMG]){
            loadPrevFile();
      }
      ticIR=0;
    }else{ //pressed a button for long time
      
      if(ticIR==0) //first loop
      {
        ticIR=tac;
      }
      else{
        if(((unsigned long)(tac-ticIR))>=1000) //5 seconds
        {
          mode=PROGRAM_IR;       
        }
      }
    }
    
    recv.resume();
    recv.enableIRIn();
   }
   resetInterruptsButtonIR();
}




void loop() {
  // put your main code here, to run repeatedly:

  tac=millis();

  //switch(mode)
    //{
    //  case SHOW_IMAGE:
    //      {
            checkRefreshImage(0);
            checkButtons();
      /*    }break;
      case PROGRAM_IR:
          {
            char posButton=programButtonsIR();
            checkRefreshImage(posButton);
            if(posButton==4)
            {
              mode=SHOW_IMAGE;
              saveButtonsIR();
              ticIR=0;
            }
          }break;
      default: 
          break;
    }*/
}
