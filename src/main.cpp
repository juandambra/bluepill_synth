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
#include "Line.h"

//PWM pin
FastPWM pwmOut(A2);

//Ticker to update the PWM dutycycle
Ticker pwm_ticker;
Ticker sequencer;
Ticker control;

Oscil <SIN512_NUM_CELLS, AUDIO_RATE> aOscil(SQUARE512_DATA);

#define CONTROL_RATE 64

Line <float32_t> decay (CONTROL_RATE);

float32_t nextValue = 0.5f;
float32_t amp=1.0;

void updateAudio(){
  pwmOut = nextValue;
  nextValue = aOscil.next();
  nextValue *= amp;
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
        //change_wavetable();
        amp = decay.next();
}


void setup(){
  aOscil.setFreq(440);
  decay.set(1.0,0.0,4.0f);
}



int main() {
        setup();
        pwmOut.period( 1.0f / (float32_t) PWM_FREQ);
        pwm_ticker.attach(&updateAudio, 1.0f/ AUDIO_RATE);
        //sequencer.attach(&change_note,1.0f/(SEQ_TIME));
        control.attach(&change_control, 1.0f/CONTROL_RATE);
        while(1) {
        }
}
