#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

#define NOTE_C5 52 //523 
#define NOTE_D5 587 //587
#define NOTE_E5 65 //659
#define NOTE_F5 698 //698
#define NOTE_G5 78 //784

void buzzer_init(){
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}

void buzzer_set_period(short cycles){
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}

void buzzer_off(){
  CCR0 = 0;
  CCR1 = 0;
}
  
void play_jingle_bells() {
  int melody[] = { NOTE_E5, 0, NOTE_E5, 0, NOTE_E5, 0, NOTE_E5, 0, NOTE_E5, 0, NOTE_E5, 0, NOTE_E5, 0, NOTE_G5, 0, NOTE_C5, 0, NOTE_D5, 0, NOTE_E5, 0, NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0, NOTE_E5, 0, NOTE_E5, 0, NOTE_E5, 0, NOTE_E5, 0, NOTE_D5, 0, NOTE_D5, 0, NOTE_E5, 0, NOTE_D5, 0, NOTE_G5, 0, NOTE_E5, 0, NOTE_E5, 0, NOTE_E5, 0, NOTE_E5, 0, NOTE_E5, 0, NOTE_E5, 0, NOTE_E5, 0, NOTE_G5, 0, NOTE_C5, 0, NOTE_D5, 0, NOTE_E5, 0, NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0, NOTE_E5, 0, NOTE_E5, 0, NOTE_E5, 0, NOTE_G5, 0, NOTE_G5, 0, NOTE_F5, 0, NOTE_D5, 0, NOTE_C5 };

  for (int i = 0; i < sizeof(melody)/sizeof(*melody); i++) {
    buzzer_set_period(melody[i]);
    __delay_cycles(100);
  }
}
 
