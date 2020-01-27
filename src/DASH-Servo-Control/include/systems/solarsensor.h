#ifndef SOLARSENSOR_H_
#define SOLARSENSOR_H_

#include <Arduino.h>
#include "sensorsystem.h"

class SolarSensor
{
    private:
    static * SensorSystem m_sys = nullptr;

    public:
    SolarSensor(SensorSystem sys)
    {
        *m_sys = sys;
    }
};

#endif