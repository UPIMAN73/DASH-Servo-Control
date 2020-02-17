#include "motortest.h"

// init the movement
void MotorTest::TestMode::init()
{
    Serial.println("Motor Test Mode");

    motorSetup(); // Setup the motors

    Serial.println("Setup complete...");
    m_running = true;
    delay(500);
}

// Motor Test run function
void MotorTest::TestMode::run()
{
    int mvment = 1; // Movement Variable

    do 
    {   // Vertical Forward Movement
        if (mvment == 1)
        {
            for (int i = 0; i < getDuration(); i++)
            {
                for (int j = 0; j < MOVEMENT_STEPS_TEST; j ++)
                {
                    vForward();
                }
            }

            mvment++; // Move onto the next
        }

        // Vertical Forward Movement
        else if (mvment == 2)
        {
            for (int i = 0; i < getDuration(); i++)
            {
                for (int j = 0; j < MOVEMENT_STEPS_TEST; j ++)
                {
                    vBackward();
                }
            }

            mvment++; // Move onto the next
        }

        // Horizontal Forward Movement
        else if (mvment == 3)
        {
            for (int i = 0; i < getDuration(); i++)
            {
                for (int j = 0; j < MOVEMENT_STEPS_TEST; j ++)
                {
                    hForward();
                }
            }

            mvment++; // Move onto the next
        }

        // Horizontal Backward Movement
        else if (mvment == 4)
        {
            for (int i = 0; i < getDuration(); i++)
            {
                for (int j = 0; j < MOVEMENT_STEPS_TEST; j ++)
                {
                    hBackward();
                }
            }

            mvment = 0; // nullify the movment
        }

        // Completely break the loop
        else
        {
            m_running = false;
            break;
        }

        delay(DELAY); // Delay the system to allow processing of movements
        
    }
    while (m_running);

    m_running = false; // Just in Case
}


// Stop the motors from running
void MotorTest::TestMode::stop()
{
    MotorCleanUp();
}