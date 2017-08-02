#include "mbed.h"
#include "FastPWM.h"
#include "pitches.h"
#include <tables/sin512_float.h>
#include <tables/square512_float.h>
#include <tables/saw512_float.h>
#include <tables/cos512_float.h>
#include <tables/tri512_float.h>
#include "main.h"
#include "Oscil.h"

//PWM pin
FastPWM pwmOut(A2);

//Ticker to update the PWM dutycycle
Ticker pwm_ticker;
Ticker sequencer;
Ticker control;

float32_t triangle (int x){
        return ((float32_t)x/(STEPS/2));
}

Oscil <SIN512_NUM_CELLS, AUDIO_RATE> aOscil(SIN512_DATA);

float32_t nextValue = 0;
void updateAudio(){
  pwmOut = nextValue;
  nextValue = aOscil.next();
}

void change_note(){
        float32_t frequency = notes[(rand() % NOTES)];
        aOscil.setFreq(frequency);
}

const float32_t * tables[] = {SQUARE512_DATA,SIN512_DATA,SAW512_DATA,TRI512_DATA,COS512_DATA};

void change_wavetable(){
         uint8_t value = rand() % 5;
         aOscil.setTable(tables[value]);
}

void change_control(){
        change_wavetable();
}

void setup(){
  aOscil.setFreq(440);
}

int main() {
        setup();
        pwmOut.period( 1.0f / (float32_t) PWM_FREQ);
        pwm_ticker.attach(&updateAudio, 1.0f/ (AUDIO_RATE));
        sequencer.attach(&change_note,1.0f/(SEQ_TIME));
        control.attach(&change_control, 0.5);
        while(1) {
        }
}
