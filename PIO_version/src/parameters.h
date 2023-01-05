#ifndef PARAMETERS_H
#define PARAMETERS_H
#include <Arduino.h>
#include <LEDFader.h> //manage LEDs without delay() jgillick/arduino-LEDFader https://github.com/jgillick/arduino-LEDFader.git

#define LED_NUM 6
const byte interruptPin = INT0; //galvanometer input
const byte knobPin = A0; //knob analog input
const byte samplesize = 10; //set sample array size
const byte analysize = samplesize - 1;  //trim for analysis array
const byte polyphony = 5; //above 8 notes may run out of ram


extern int scaleMajor[];
extern int scaleDiaMinor[];
extern int scaleIndian[];
extern int scaleMinor[];
extern int scaleChrom[];
extern volatile unsigned long microseconds; //sampling timer
extern volatile unsigned long samples[samplesize];

extern int *scaleSelect; //initialize scaling
extern int root; //initialize for root
extern byte channel;  //setting channel to 11 or 12 often helps simply computer midi routing setups
extern int noteMin; //C2  - keyboard note minimum
extern int noteMax; //C7  - keyboard note maximum
extern byte QY8;  //sends each note out chan 1-4, for use with General MIDI like Yamaha QY8 sequencer
extern byte controlNumber; //set to mappable control, low values may interfere with other soft synth controls!!
extern byte controlVoltage; //output PWM CV on controlLED, pin 17, PB3, digital 11 *lowpass filter
extern long batteryLimit; //voltage check minimum, 3.0~2.7V under load; causes lightshow to turn off (save power)
extern byte checkBat;
extern volatile byte index;
extern float threshold;  //change threshold multiplier
extern float threshMin; //scaling threshold min
extern float threshMax; //scaling threshold max
extern float knobMin;
extern float knobMax;
extern unsigned long previousMillis;
extern long currentMillis;
extern unsigned long batteryCheck; //battery check delay timer
extern LEDFader leds[LED_NUM];
extern int ledNums[LED_NUM];
extern byte controlLED; //array index of control LED (CV out)
extern byte noteLEDs;  //performs lightshow set at noteOn event
extern int noteIndex;

typedef struct _MIDImessage { //build structure for Note and Control MIDImessages
  unsigned int type;
  int value;
  int velocity;
  int duration;
  long period;
  int channel;
} MIDImessage;


extern MIDImessage noteArray[polyphony]; //manage MIDImessage data as an array with size polyphony
extern MIDImessage controlMessage; //manage MIDImessage data for Control Message (CV out)
#endif