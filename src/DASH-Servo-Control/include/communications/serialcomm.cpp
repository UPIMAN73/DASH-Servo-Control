#include "communications/serialcomm.h"

void SerailComm::open(unsigned long cbuad)
{
    buad = cbuad;
    Serial.begin(cbuad);
}

String SerailComm::read()
{
    return Serial.readString();
}
