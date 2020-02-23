// Default Arduino include
#include <Arduino.h>

// Custom Library Includes
#include "systems/motorsys.h"

// Define all items
MotorSys ms;

void setup()
{
    Serial.begin(9600);
    delay(500);

    // Define Device Systems
    ms = MotorSys(LDR_RT_PIN, LDR_RB_PIN, LDR_LT_PIN, LDR_LB_PIN, 650);

    delay(1000);

    //
}

void loop()
{
    // 
    ms.run();
    delay(1000);
}