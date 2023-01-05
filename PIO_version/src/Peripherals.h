#ifndef PERIPHERALS_H
#define PERIPHERALS_H
#include <Arduino.h>

#include "parameters.h"

void checkKnob();
void knobMode();
void rampUp(int ledPin, int value, int time);
void rampDown(int ledPin, int value, int time);
void checkLED();
void checkButton();
long readVcc();
void checkBattery();
void bootLightshow();
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max);
int freeRAM();
#endif