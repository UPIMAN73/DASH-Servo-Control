#include "systems/relay.h"

// Relay System
RelaySystem::RelaySystem(DigitalDevice a, DigitalDevice b, float tstamp, uint8 run_time)
{
    rtime = run_time;
    timestamp = tstamp;
    r1 = a;
    r2 = b;
    init = true;
}

RelaySystem::~RelaySystem()
{
    init = false;
    rtime = 0;
    timestamp = 0.0f;

    // First Clean the system
    r1.clean();
    r2.clean();

    // Delete the instance
}

// Run Function
void RelaySystem::run()
{
    if (init)
    {
        float initTime = 0.0f;
        for (uint8 i = 0; i < rtime; i++)
        {
            initTime = getAccurateSeconds();
            while (timeDelta(getAccurateSeconds(), initTime) < timestamp)
            {
                r1.setDevice(HIGH);
                r2.setDevice(HIGH);
                delay(10);
            }
            r2.setDevice(LOW);
            r1.setDevice(LOW);
            delay(100);
        }
    }
}