
#include <IRremote.h>
#include <IRremoteInt.h>
#include "buttonsIR.h"
#include "eepromMap.h"
#include <avr/pgmspace.h>

typedef union charToUlong32
  {
  char c[4];
  unsigned long ul;
  }
  charToUlong32_t;

unsigned long buttonsIR_Id[4]={34467855,34469895,34468875,34470915};
unsigned long lastButtonIR=0;
char buttonProgramPos=0; 
extern IRrecv recv;
extern decode_results button;

void loadButtonsIR()
{  
  charToUlong32_t aux;
  for(char i=0;i<MAX_BUTTONS;i++)
  {  
     aux.c[0]=EEPROM[EEPROM_IR_CONFIG+(i*4)  ];   
     aux.c[1]=EEPROM[EEPROM_IR_CONFIG+(i*4)+1];   
     aux.c[2]=EEPROM[EEPROM_IR_CONFIG+(i*4)+2];   
     aux.c[3]=EEPROM[EEPROM_IR_CONFIG+(i*4)+3];
     buttonsIR_Id[i]=aux.ul;
  }
  buttonProgramPos=0;
  lastButtonIR=0;
}

void saveButtonsIR()
{
  charToUlong32_t aux;
  for(char i=0;i<MAX_BUTTONS;i++)
  {
     aux.ul=buttonsIR_Id[i];
     EEPROM[EEPROM_IR_CONFIG+(i*4)  ]=aux.c[0];   
     EEPROM[EEPROM_IR_CONFIG+(i*4)+1]=aux.c[1];   
     EEPROM[EEPROM_IR_CONFIG+(i*4)+2]=aux.c[2];   
     EEPROM[EEPROM_IR_CONFIG+(i*4)+3]=aux.c[3];
  }
  buttonProgramPos=0;
  lastButtonIR=0;
}


void resetInterruptsButtonIR()
{
  
     recv.enableIRIn();  
}

int recvButtonIR(unsigned long * btnValue)
{
    int success=recv.decode(&button);
    *btnValue=button.value;
    recv.resume();
    return success;
     
}

char programButtonsIR()
{
 if(recv.decode(&button))
 {  
    if((button.value!=0xFFFFFFFF)&&(button.value!=lastButtonIR))
    {
      lastButtonIR=button.value;
      buttonsIR_Id[buttonProgramPos]=lastButtonIR;
      buttonProgramPos++;
    }
 }
 resetInterruptsButtonIR();
 return buttonProgramPos;
}
