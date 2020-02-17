#include <Arduino.h>
#include "systems/testing/motortest.h"
 
#define DURATION 3

// Static definition calls
static MotorTest * mt;


// Setup function 
void setup() 
{
  Serial.begin(9600);           // set up Serial library at 9600 bps

  *mt = MotorTest("Stepper Motors Testing", 0.0, 1.0, DURATION);
  mt->init();
 
  delay(1000);
}

// Loop function
void loop() 
{
  // simple action motor running
  if (mt->isRunning())
  {
    mt->run();
    mt->stop();
  }
}