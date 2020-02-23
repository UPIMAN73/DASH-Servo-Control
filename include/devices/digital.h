#ifndef Digital_H_
#define Digital_H_

#include "general.h"

class DigitalDevice
{
    public:
        // Constructors
        DigitalDevice();
        DigitalDevice(uint8 id, bool input);
        ~DigitalDevice();

        // Device Control
        virtual uint16 getDevice();             // Get Device Input Value
        virtual void setDevice(uint8 value);    // Set Device Output Value

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