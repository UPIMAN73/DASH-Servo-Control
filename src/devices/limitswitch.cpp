#include "devices/limitswitch.h"


// Default Constructor
LimitSwitch::LimitSwitch()
{
    //
}

// Preferred constructor
LimitSwitch::LimitSwitch(String name, uint8 pin) : DigitalDevice(pin, true)
{
    m_name = name;
}


// Getter
String LimitSwitch::getName()
{
    return m_name;
}


bool LimitSwitch::getState()
{
    uint8 a = DigitalDevice::getDevice();

    if (a == HIGH)
    {
        a = 0;
        return true;
    }
    else
    {
        a = 0;
        return false;
    }
    
}