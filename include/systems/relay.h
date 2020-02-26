#ifndef RELAYSYSTEM_H_
#define RELAYSYSTEM_H_

#include "devices/digital.h"
#include "general.h"

class RelaySystem
{
    public:
        RelaySystem(DigitalDevice a, DigitalDevice b, float tstamp, uint8 run_time);
        ~RelaySystem();

        void run(); // Run the Relay System to the defined sets
    
    private:
        bool init = false;
        DigitalDevice r1;
        DigitalDevice r2;

        // runloop variables
        uint8 rtime;
        float timestamp;
};

#endif
