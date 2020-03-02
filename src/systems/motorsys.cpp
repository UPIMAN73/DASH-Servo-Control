#include "systems/motorsys.h"

// Default Constructor
MotorSys::MotorSys()
{
    //DO Nothing
}

// Preferred Constructor
MotorSys::MotorSys(uint8 prt, uint8 prb, uint8 plt, uint8 plb, uint8 plls, uint8 plrs, uint16 t, uint16 at)
{
    // LDR definition
    ldrt = LDR("Right Top LDR", prt);
    ldrb = LDR("Right Bottom LDR", prb);
    ldlt = LDR("Left Top LDR", plt);
    ldlb = LDR("Left Bottom LDR", plb);

    // Limit Switches
    ls = LimitSwitch("Left Limit Switch", plls);
    rs = LimitSwitch("Right Limit Switch", plrs);

    // threshold set
    threshold = t;
    athresh = at;
    init = true;

    motorSetup();
}

// Destructor
MotorSys::~MotorSys()
{
    // LDR Clean
    ldrt.clean();
    ldrb.clean();
    ldlt.clean();
    ldlb.clean();

    // Stop Motors
    MotorCleanUp();
}


// Main Run Loop
void MotorSys::run()
{
    if (init)
    {
        // Find the values of the LDR
        ldrtv = ldrt.getDevice();
        ldrbv = ldrb.getDevice();
        ldltv = ldlt.getDevice();
        ldlbv = ldlb.getDevice();

        // Values of the ldr
        topval = ldrtv + ldltv;
        botval = ldrbv + ldlbv;
        rightval = ldrtv + ldrbv;
        leftval = ldltv + ldlbv;

        // Break the movement by limi switches
        // if (ls.getState() || rs.getState())
        // {
        //     return;
        // }

        // Vertical Movement
        if (abs(topval) - abs(botval) > athresh || abs(botval) - abs(topval) > athresh)
        {
            if (topval > botval + threshold)
            {
                //vForward();
                // Serial.println("Up");
            }

            else if (botval > topval + threshold)
            {
                // vBackward();
                // Serial.println("Down");
            }
            Serial.print("Top\t");
            Serial.println(topval);
            Serial.print("Bottom\t");
            Serial.println(botval);
        }

        // Horizontal Movement
        if (abs(rightval) - abs(leftval) > athresh || abs(leftval) - abs(rightval) > athresh)
        {
            
            if (rightval > leftval + threshold)
            {
                // hForward();
                // Serial.println("Right");
            }

            else if (leftval > rightval + threshold)
            {
                // hBackward();
                // Serial.println("Left");
            }
            Serial.print("Right\t");
            Serial.println(rightval);
            Serial.print("Left\t");
            Serial.println(leftval);
        }
    }
}

// Getter
bool MotorSys::getInit()
{
    return init;
}