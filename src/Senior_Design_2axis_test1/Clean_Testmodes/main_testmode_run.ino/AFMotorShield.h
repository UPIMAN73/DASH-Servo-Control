/*
 * @author Joshua Calzadillas
 * @date December 1, 2019
 * 
 * @desc
 * 
 */

#include <Adafruit_MotorShield.h>
#include "StepperMotor.h"

// Predefined values
#define STEPS_PER_ROTATION 200
#define MOVEMENT_MODE SINGLE
#define MOVEMENT_SPEED 600.0


/*
 * Adafruit Motor Shield Class
 */
class AFMotorShield
{
    // public values of the class
    public:
        // Adafruit motor shield constructor
        AFMotorShield(StepperMotor a, StepperMotor b)
        {
            if (!initialized)
            {
                // Adafruit Motor Shield
                AMS = Adafruit_MotorShield();

                // Stepper Motor A is the vertical motor
                // Stepper Motor B is the horizontal motor
                smv = AMS.getStepper(STEPS_PER_ROTATION, a.getPin());
                smh = AMS.getStepper(STEPS_PER_ROTATION, b.getPin());

                // movement speed
                smv->setSpeed(MOVEMENT_SPEED);
                smh->setSpeed(MOVEMENT_SPEED);
                initialized = true;
            }
        }

        /*
         * Vertical Motor Movement
         */

        void verticalForward()
        {
            smv->onestep(FORWARD, MOVEMENT_MODE);
        }

        void verticalBackward()
        {
            smv->onestep(BACKWARD, MOVEMENT_MODE);
        }


        /*
         * Horizontal Motor Movement
         */
        void horizontalForward()
        {
            smh->onestep(FORWARD, MOVEMENT_MODE);
        }

        void horizontalBackward()
        {
            smh->onestep(BACKWARD, MOVEMENT_MODE);
        }

        // This is the shut-off process of the entire board
        void shutOff()
        {
            // Make sure the step process if nullified
            smh->step(0, FORWARD, SINGLE);
            smv->step(0, FORWARD, SINGLE);
            
            // Release all of the motors
            smh->release();
            smv->release();
        }

        // clean all of the values of the stored class
        void clean()
        {
            shutOff(); // shut off the motors

            // Setting values inside of pointer to null
            smv->clean();
            smh->clean();

            // setting pointers to null
            smv = NULL;
            smh = NULL;
            AMS = NULL;
            initialized = NULL;
        }
    
    private:
        // control variable
        bool initialized = false;

        // Adafruit motor Shield and Motors declaration
        Adafruit_MotorShield AMS;
        Adafruit_StepperMotor *smv;
        Adafruit_StepperMotor *smh;

};
