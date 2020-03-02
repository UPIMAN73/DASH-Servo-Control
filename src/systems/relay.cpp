#include "systems/relay.h"

RelaySystem::RelaySystem()
{
    // DOTHING;
}

// Relay System
RelaySystem::RelaySystem(uint8 a, uint8 b, float tstamp, uint8 run_time)
{
    rtime = run_time;
    timestamp = tstamp;
    r1 = DigitalDevice(a, false);
    r2 = DigitalDevice(b, false);
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

// Start the Relay
void RelaySystem::start()
{
    if (init)
    {
        // Normal
        r1.setDevice(LOW);
        r2.setDevice(LOW);

        // Reversed
        // r2.setDevice(HIGH);
        // r1.setDevice(HIGH);
    }
}

    
// Relay Stop
void RelaySystem::stop()
{
    if (init)
    {
        // Normal
        r2.setDevice(HIGH);
        r1.setDevice(HIGH);

        // Reversed
        // r1.setDevice(LOW);
        // r2.setDevice(LOW);
    }
}
    

// Run Function
void RelaySystem::run()
{
    if (init)
    {
        float initTime = 0.0f;
        for (uint8 i = 1; i <= rtime; i++)
        {
            // print out the relay
            Serial.print("Relay run ");
            Serial.print(i);
            Serial.println(" times");

            // get init time
            initTime = getAccurateSeconds();
            while (timeDelta(getAccurateSeconds(), initTime) < timestamp)
            {
                // set the device to high state
                start();
                delay(10);
            }

            // relay shutoff
            stop();
            delay(100);
        }
    }
}