#pragma once
#ifndef AFMV1_H_
#define AFMV1_H_

/*
 * @author Joshua Calzadillas
 * @date February 16, 2020
 * 
 * @desc
 * Arduino Motor Shield V1 Setup
 * 
 */

#include <AFMotor.h>
#include "general.h"
#include "devices/steppermotor.h"

// Predefined values
#define STEPS_PER_ROTATION 20
#define MOVEMENT_MODE SINGLE
#define MOVEMENT_SPEED 20
#define DELAY 1

// Vertical and Horizontal Motor Classes
// SM vmo; // Vertical Motor Class
// SM hmo; // Horizontal Motor Class

// // Adafruit Motors
void motorSetup();
void MotorCleanUp();

// Movement
void hForward();
void hBackward();
void vForward();
void vBackward();

#endif