#ifndef buzzer_included
#define buzzer_included

void buzzer_init();
void buzzer_set_period(short cycles);
void buzzer_off();
void play_jingle_bells(void);
void play_note(int frequency, int duration);

#endif
