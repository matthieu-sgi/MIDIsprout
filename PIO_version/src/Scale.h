#ifndef SCALE_H
#define SCALE_H
#include <Arduino.h>

#include "parameters.h"

int scaleSearch(int note, int scale[], int scalesize);
int scaleNote(int note, int scale[], int root);

#endif