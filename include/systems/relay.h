#ifndef RELAYSYSTEM_H_
#define RELAYSYSTEM_H_

#include "devices/digital.h"
#include "general.h"

class RelaySystem
{
    public:
        RelaySystem(DigitalDevice a, DigitalDevice b, float tstamp, uint8_t run_time);

        void run(); // Run the Relay System to the defined sets
    
    private:
        DigitalDevice r1;
        DigitalDevice r2;

        // runloop variables
        uint8_t rtime;
        float timestamp;
};

#endif
