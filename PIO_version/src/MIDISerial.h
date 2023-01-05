#ifndef MIDISERIAL_H
#define MIDISERIAL_H
#include <Arduino.h>

#include "parameters.h"
#include "Peripherals.h"

void setNote(int value, int velocity, long duration, int notechannel);
void setControl(int type, int value, int velocity, long duration);
void checkControl();
void checkNote();
void MIDIpanic();
void midiSerial(int type, int channel, int data1, int data2);
#endif