#ifndef PARAMETERS_H
#define PARAMETERS_H
#include <Arduino.h>
#include <LEDFader.h> //manage LEDs without delay() jgillick/arduino-LEDFader https://github.com/jgillick/arduino-LEDFader.git

//*******************************

const byte interruptPin = INT0; //galvanometer input
const byte knobPin = A0; //knob analog input

const byte samplesize = 10; //set sample array size
const byte analysize = samplesize - 1;  //trim for analysis array

const byte polyphony = 5; //above 8 notes may run out of ram
byte channel = 1;  //setting channel to 11 or 12 often helps simply computer midi routing setups
int noteMin = 36; //C2  - keyboard note minimum
int noteMax = 96; //C7  - keyboard note maximum
byte QY8= 0;  //sends each note out chan 1-4, for use with General MIDI like Yamaha QY8 sequencer
byte controlNumber = 80; //set to mappable control, low values may interfere with other soft synth controls!!
byte controlVoltage = 1; //output PWM CV on controlLED, pin 17, PB3, digital 11 *lowpass filter
long batteryLimit = 3000; //voltage check minimum, 3.0~2.7V under load; causes lightshow to turn off (save power)
byte checkBat = 1;



float threshold = 2.3;  //change threshold multiplier
float threshMin = 1.61; //scaling threshold min
float threshMax = 3.71; //scaling threshold max
float knobMin = 1;
float knobMax = 1023;

unsigned long previousMillis = 0;
long currentMillis = 1;
unsigned long batteryCheck = 0; //battery check delay timer
 
#define LED_NUM 6
LEDFader leds[LED_NUM] = { // 6 LEDs (perhaps 2 RGB LEDs)
  LEDFader(3),
  LEDFader(5),
  LEDFader(6),
  LEDFader(9),
  LEDFader(10),
  LEDFader(11)  //Control Voltage output or controlLED
};
int ledNums[LED_NUM] = {3,5,6,9,10,11};
byte controlLED = 5; //array index of control LED (CV out)
byte noteLEDs = 1;  //performs lightshow set at noteOn event

typedef struct _MIDImessage { //build structure for Note and Control MIDImessages
  unsigned int type;
  int value;
  int velocity;
  int duration;
  long period;
  int channel;
} 
MIDImessage;
MIDImessage noteArray[polyphony]; //manage MIDImessage data as an array with size polyphony
int noteIndex = 0;
MIDImessage controlMessage; //manage MIDImessage data for Control Message (CV out)
#endif