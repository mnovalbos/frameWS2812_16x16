#include "eepromMap.h"

char EEPROM_MGK_KEY[3]={'M','T','X'};
int isEEPROMFormatted()
{
  for(char i=0;i<3;i++)
  {
    if(EEPROM[i]!=EEPROM_MGK_KEY[i])
       return 0;
  }
  return 1;
}

void formatEEPROM()
{
  for(char i=0;i<3;i++)
  {
    EEPROM[i]=EEPROM_MGK_KEY[i];
  }
  for(char i=0;i<3;i++)
  {
    EEPROM[i]=EEPROM_MGK_KEY[i];
  }
  
}

