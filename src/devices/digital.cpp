#include "devices/digital.h"

// Default Constructor
DigitalDevice::DigitalDevice()
{
    m_id = 0;
    m_input = false;
}


// Prefered Constructor
DigitalDevice::DigitalDevice(uint8 id, bool input)
{
    m_id = id;
    m_input = input;

    if (input)
    {
        pinMode(id, INPUT);
    }

    else
    {
        pinMode(id, OUTPUT);
    }
    
}

// Deconstructor
DigitalDevice::~DigitalDevice()
{
    m_id = 0;
    m_input = false;
}

// 
uint8 DigitalDevice::getId()
{
    return m_id;
}

// 
bool DigitalDevice::getType()
{
    return m_input;
}

/*
 * Device Methods
 */

void DigitalDevice::setDevice(uint8 value)
{
    if (!m_input)
    {
        digitalWrite(m_id, value);
    }
}


uint16 DigitalDevice::getDevice()
{
    if (m_input)
    {
        return digitalRead(m_id);
    }
}