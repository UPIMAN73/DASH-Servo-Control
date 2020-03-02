// Default Arduino include
#include <Arduino.h>

// Custom Library Includes
#include "systems/motorsys.h"
#include "systems/relay.h"

// Define all items
MotorSys ms;
RelaySystem rs;
float initTime;

void setup()
{
    Serial.begin(9600);
    delay(500);

    // Define Device Systems
    ms = MotorSys(LDR_RT_PIN, LDR_RB_PIN, LDR_LT_PIN, LDR_LB_PIN, LS_LEFT_PIN, LS_RIGHT_PIN, (uint16) 250, (uint16) 40);
    rs = RelaySystem(RL1_PIN, RL2_PIN, 3.0f, 3);
    delay(500);

    Serial.println("Initiating Relay System...");
    //rs.run();
    rs.stop();

    delay(1000);
}

void loop()
{
    // run
    ms.run();
    // Serial.println("Horizontal Foward");
    // initTime = getAccurateSeconds();
    // while (timeDelta(getAccurateSeconds(), initTime) < 3.0)
    // {
    //     // Horizontal Forward
    //     hForward();
    //     delay(10);
    // }
    // delay(100);

    // Serial.println("Horizontal Backward");
    // initTime = getAccurateSeconds();
    // while (timeDelta(getAccurateSeconds(), initTime) < 3.0)
    // {
    //     // Horizontal Backward
    //     hBackward();
    //     delay(10);
    // }
    // delay(100);

    // Serial.println("Vertical Forward");
    // initTime = getAccurateSeconds();
    // while (timeDelta(getAccurateSeconds(), initTime) < 3.0)
    // {
    //     // Vertical Forward
    //     vForward();
    //     delay(10);
    // }
    // delay(100);

    // Serial.println("Vertical Backward");
    // initTime = getAccurateSeconds();
    // while (timeDelta(getAccurateSeconds(), initTime) < 3.0)
    // {
    //     // Vertical Backward
    //     vBackward();
    //     delay(10);
    // }
    // delay(1000);
}