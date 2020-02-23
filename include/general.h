#ifndef GENERAL_H_
#define GENERAL_H_

#include <Arduino.h>

#define DTIME 3


// Pin Definitions
#define LDR_RT_PIN A0
#define LDR_RB_PIN A1
#define LDR_LT_PIN A2
#define LDR_LB_PIN A3

// Typedef for unsiged integers
typedef unsigned char uint8;
typedef unsigned short uint16;

// Time Functions
long getCurrentTime();
long getCurrentSeconds();
float getAccurateSeconds();
float getCurrentMinutes();
float getCurrentHours();

// Calculate Time Functions
long timeDelta(long tf, long ti);
float timeDelta(float tf, float ti);

#endif