#include "devices/ldr.h"

LDR::LDR() : AnalogDevice()
{
    m_name = "";
}

LDR::LDR(String name, uint8 id) : AnalogDevice(id, true)
{
    m_name = name;
}

LDR::~LDR()
{
    m_name = "";
    AnalogDevice::clean();
}

void LDR::clean()
{
    m_name = "";
    AnalogDevice::clean();
}

String LDR::getName()
{
    return m_name;
}