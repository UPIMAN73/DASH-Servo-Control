#ifndef LIMITSWITCH_H_
#define LIMITSWITCH_H_

#include "digital.h"

class LimitSwitch : DigitalDevice
{
    public:
        LimitSwitch();
        LimitSwitch(String name, uint8 pin);

        // Getters
        String getName();
        bool getState(); // Get the state of the device by getting the device input

    private:
    String m_name;
};

#endif