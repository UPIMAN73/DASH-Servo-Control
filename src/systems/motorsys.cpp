#include "systems/motorsys.h"

MotorSys::MotorSys()
{
    //
}

MotorSys::MotorSys(uint8 prt, uint8 prb, uint8 plt, uint8 plb, uint16 t)
{
    // LDR definition
    ldrt = LDR("Right Top LDR", prt);
    ldrb = LDR("Right Bottom LDR", prb);
    ldlt = LDR("Left Top LDR", plt);
    ldlb = LDR("Left Bottom LDR", plb);

    // threshold set
    threshold = t;
    init = true;

    // motorSetup();
}

MotorSys::~MotorSys()
{
    ldrt.clean();
    ldrb.clean();
    ldlt.clean();
    ldlb.clean();
    // motorStop();
}

void MotorSys::run()
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

    // Vertical Movement
    if (abs(topval) - abs(botval) < threshold)
    {
        if (topval >= threshold)
        {
            // vForward();
            Serial.println("VForward");
        }

        else if (botval >= threshold)
        {
            // vBackSerial.println("VForward");ward();
            Serial.println("VBackward");
        }
    }

    // Horizontal Movement
    if (abs(rightval) - abs(leftval) < threshold)
    {
        if (rightval >= threshold)
        {
            // hForward();
            Serial.println("HForward");
        }

        else if (leftval >= threshold)
        {
            // hBackward();
            Serial.println("HBackward");
        }
    }
}

bool MotorSys::getInit()
{
    return init;
}