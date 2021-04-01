#ifndef __BUTTONS_IR__
#define __BUTTONS_IR__

#define IR_PIN        2
#define MAX_BUTTONS   4

#define B_NEXTIMG     0
#define B_PREVIMG     1
#define B_BRIGHTUP    2
#define B_BRIGHTDOWN  3

extern unsigned long buttonsIR_Id[4];
extern unsigned long lastButtonIR;

void resetInterruptsButtonIR();
void loadButtonsIR();
void saveButtonsIR();
int recvButtonIR(unsigned long * btnValue);
char programButtonsIR();

#endif
