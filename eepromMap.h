
#include <EEPROM.h>

#ifndef _EEPROM_MAP_H_
#define _EEPROM_MAP_H_
//magic number (3 bytes)
#define EEPROM_MGK       0
//file number (1byte)
#define EEPROM_LAST_FILE 3
//infra red button config (16 bytes) 
#define EEPROM_IR_CONFIG 4
//color palette (48 bytes)
#define EEPROM_PAL       20
//number of frames loaded in eeprom (1byte)
#define EEPROM_NUMFRAMES 68
//pixels
#define EEPROM_IMAGE 69

extern char EEPROM_MGK_KEY[3];
int isEEPROMFormatted();
void formatEEPROM();
#endif
