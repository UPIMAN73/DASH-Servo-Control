#include "systems/AFMV1.h"

SM vmo = SM("Vertical Motors",    1, STEPS_PER_ROTATION);
SM hmo  = SM("Horizontal Motors",  2, STEPS_PER_ROTATION);

AF_Stepper vmotor(vmo.getSteps(), vmo.getPin());
AF_Stepper hmotor(hmo.getSteps(), hmo.getPin());


// set the motor speed
void motorSetup()
{
    vmotor.setSpeed(MOVEMENT_SPEED);
    hmotor.setSpeed(MOVEMENT_SPEED);
}


/*
 * Motor Movement Functions
 * Vertical movements are declared first
 * Horizontal movements are declared second
 */

// Vertical Forward Function
void vForward()
{
    vmotor.onestep(FORWARD, MOVEMENT_MODE);
    delay(DELAY);
    vmotor.release();
}

// Vertical Backward Function
void vBackward()
{
    vmotor.onestep(BACKWARD, MOVEMENT_MODE);
    delay(DELAY);
    vmotor.release();
}

// Horizontal Forward Function
void hForward()
{
    hmotor.onestep(FORWARD, MOVEMENT_MODE);
    delay(DELAY);
    vmotor.release();
}

// Horizontal Backward Function
void hBackward()
{
    hmotor.onestep(BACKWARD, MOVEMENT_MODE);
    delay(DELAY);
    vmotor.release();
}

// Cleanup Functions
void MotorCleanUp()
{
    // Call a null step to clear the movement que
    vmotor.step(0, FORWARD, MOVEMENT_MODE);
    delay(500);
    hmotor.step(0, FORWARD, MOVEMENT_MODE);

    // Release the Motors
    vmotor.release();
    hmotor.release();

    // Delete the stepper motor class
    vmo.clean();
    hmo.clean();
}