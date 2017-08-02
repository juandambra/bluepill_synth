#ifndef MAIN_H_
#define MAIN_H_

#include <arm_math.h>
#include <pitches.h>

#define STEPS        512
#define AUDIO_RATE  32768
//#define AUDIO_RATE  22050
#define SEQ_TIME 4


//Frequency of output sine in Hz
#define OUT_FREQ     500

#define INTERPOLATE 0

//Constants to compute the sine waveform
//#define PI                 3.141592f
#define STEPS_RAD    (2.0f * PI / STEPS)
#define NOTES 35
float notes[NOTES] = {NOTE_C2,NOTE_D2,NOTE_E2,NOTE_F2,NOTE_G2,NOTE_A2,NOTE_B2,NOTE_C3,NOTE_D3,NOTE_E3,NOTE_F3,NOTE_G3,NOTE_A3,NOTE_B3,NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_C5,NOTE_D5,NOTE_E5,NOTE_F5,NOTE_G5,NOTE_A5,NOTE_B5,NOTE_C6,NOTE_D6,NOTE_E6,NOTE_F6,NOTE_G6,NOTE_A6,NOTE_B6};
//Frequency of Pulse Width Modulated signal in Hz
#define PWM_FREQ          125000



#endif
