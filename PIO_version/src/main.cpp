#include <Arduino.h>
#include "MIDISerial.h"
#include "Peripherals.h"
#include "SampleAnalysis.h"
#include "Scale.h"
#include "parameters.h"
/*------------
MIDI_PsychoGalvanometer v021
Accepts pulse inputs from a Galvanic Conductance sensor 
consisting of a 555 timer set as an astablemultivibrator and two electrodes. 
Through sampling pulse widths and identifying fluctuations, MIDI note and control messages 
are generated.  Features include Threshold, Scaling, Control Number, and Control Voltage 
using PWM through an RC Low Pass filter.
MIDIsprout.com
-------------*/


//******************************
//set scaled values, sorted array, first element scale length


void setup()
{
  pinMode(knobPin, INPUT);
  randomSeed(analogRead(0)); //seed for QY8 
  Serial.begin(31250);  //initialize at MIDI rate
  controlMessage.value = 0;  //begin CV at 0
  //MIDIpanic(); //dont panic, unless you are sure it is nessisary
  checkBattery(); // shut off lightshow if power is too low
  if(noteLEDs) bootLightshow(); //a light show to display on system boot
  attachInterrupt(interruptPin, sample, RISING);  //begin sampling from interrupt
  
}

void loop()
{
  currentMillis = millis();   //manage time
  checkBattery(); //on low power, shutoff lightShow, continue MIDI operation
  checkKnob(); //check knob value
  if(index >= samplesize)  { analyzeSample(); }  //if samples array full, also checked in analyzeSample(), call sample analysis   
  checkNote();  //turn off expired notes 
  checkControl();  //update control value
  //checkButton();  //not implemented in this build
  checkLED();  //LED management without delay()
  previousMillis = currentMillis;   //manage time
}





