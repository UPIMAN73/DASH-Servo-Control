#pragma once
#ifndef RELAYSYSTEM_H_
#define RELAYSYSTEM_H_

#include "devices/digital.h"
#include "general.h"

class RelaySystem
{
    public:
        RelaySystem();
        RelaySystem(uint8 a, uint8 b, float tstamp, uint8 run_time);
        ~RelaySystem();

        void run();  // Run the Relay System to the defined sets
        void stop(); // Stop the relay
    
    private:
        bool init = false;
        DigitalDevice r1;
        DigitalDevice r2;
        void start(); // Start the relay

        // runloop variables
        uint8 rtime;
        float timestamp;
};

#endif
