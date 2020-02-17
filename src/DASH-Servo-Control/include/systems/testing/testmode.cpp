#include "testmode.h"

// Init Function
void TestMode::init()
{
    Serial.println("INIT-CALLED\nTest Mode Parent Function");
    Serial.println("Needs to be inherited in order to have it operate correctly.");
}// Write your own run function

// Run function
void TestMode::run()
{
    Serial.println("RUN-CALLED\nTest Mode Parent Function");
    Serial.println("Needs to be inherited in order to have it operate correctly.");
} // Write your own run function


// Stop function
void TestMode::stop()
{
    Serial.println("Test Mode Parent Function");
    Serial.println("Needs to be inherited in order to have it operate correctly.");
}// Write your own run function

