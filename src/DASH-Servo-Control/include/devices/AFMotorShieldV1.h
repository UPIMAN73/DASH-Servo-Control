#pragma once
#ifndef AFMOTORSHIELDV1_H_
#define AFMOTORSHIELDV1_H_

/*
 * @author Joshua Calzadillas
 * @date February 16, 2020
 * 
 * @desc
 * Arduino Motor Shield V1 Setup
 * 
 */

#include <Arduino.h>
#include <AFMotor.h>
#include "StepperMotor.h"

// Predefined values
#define STEPS_PER_ROTATION 200
#define MOVEMENT_MODE SINGLE
#define MOVEMENT_SPEED 100

// Vertical and Horizontal Motor Classes
StepperMotor v = StepperMotor("Vertical Motors",  1, STEPS_PER_ROTATION);
StepperMotor h = StepperMotor("Horizontal Motors",  2, STEPS_PER_ROTATION);

// Adafruit Motors
AF_Stepper vmotor(v.getSteps(), v.getPin());
AF_Stepper hmotor(h.getSteps(), h.getPin());


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
    vmotor.step(1, FORWARD, MOVEMENT_MODE);
}

// Vertical Backward Function
void vBackward()
{
    vmotor.step(1, BACKWARD, MOVEMENT_MODE);
}

// Horizontal Forward Function
void hForward()
{
    hmotor.step(1, FORWARD, MOVEMENT_MODE);
}

// Horizontal Backward Function
void hBackward()
{
    hmotor.step(1, BACKWARD, MOVEMENT_MODE);
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
    v.clean();
    h.clean();
}

#endif