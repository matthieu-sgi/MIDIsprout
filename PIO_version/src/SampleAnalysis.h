#ifndef SAMPLEANALYSIS_H
#define SAMPLEANALYSIS_H
#include <Arduino.h>

#include "parameters.h"
#include "MIDISerial.h"
#include "Scale.h"

void sample();
void analyzeSample(volatile unsigned long samples[], volatile byte index);

int scaleMajor[]  = {7,1, 3, 5, 6, 8, 10, 12};
int scaleDiaMinor[]  = {7,1, 3, 4, 6, 8, 9, 11};
int scaleIndian[]  = {7,1, 2, 2, 5, 6, 9, 11};
int scaleMinor[]  = {7,1, 3, 4, 6, 8, 9, 11};
int scaleChrom[] = {12,1,2,3,4,5,6,7,8,9,10,11,12};
int *scaleSelect = scaleChrom; //initialize scaling
int root = 0; //initialize for root



#endif