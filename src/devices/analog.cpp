#include "devices/analog.h"

// Default Constructor
AnalogDevice::AnalogDevice()
{
    m_id = 0;
    m_input = false;
}

// Prefered Constructor
AnalogDevice::AnalogDevice(uint8 id, bool input)
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
AnalogDevice::~AnalogDevice()
{
    m_id = 0;
    m_input = false;
}

// 
uint8 AnalogDevice::getId()
{
    return m_id;
}

// 
bool AnalogDevice::getType()
{
    return m_input;
}

void AnalogDevice::clean()
{
    m_input = false;
    m_id = 0;
}

/*
 * Device Methods
 */

void AnalogDevice::setDevice(uint8 value)
{
    if (!m_input)
    {
        analogWrite(m_id, value);
    }
}


uint16 AnalogDevice::getDevice()
{
    if (m_input)
    {
        return analogRead(m_id);
    }
    return 0;
}