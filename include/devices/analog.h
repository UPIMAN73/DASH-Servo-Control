#ifndef ANALOG_H_
#define ANALOG_H_

#include "general.h"

class AnalogDevice
{
    public:
        // Constructors
        AnalogDevice();
        AnalogDevice(uint8 id, bool input);
        ~AnalogDevice();

        // Device Control
        uint16 getDevice();             // Get Device Input Value
        void setDevice(uint8 value);    // Set Device Output Value

        // Getters
        uint8 getId();
        bool getType();
        void clean();
    
    private:
        // Member Variables
        uint8 m_id;
        bool m_input;
};

#endif