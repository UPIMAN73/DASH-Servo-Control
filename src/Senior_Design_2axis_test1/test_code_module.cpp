/*
 * @author Joshua Calzadillas
 * @description This program is meant to test out the threshold value
 * for the motor rotoation. This will help decide how often the motors move,
 * and to what position do they move to.
 */


// Libraries
#include <iostream>
#include <stdio.h>
#include <cmath>


// This part is the function precalls
double valueScore(double t);

// binary search like function
double val1;


// global variables

// int dtime = analogRead(4)/20; // read potentiometers  
// int tol = analogRead(5)/4;

// setting variables that can be changed through the arduino console
int dtime = 10;          // difference in time
double tollerance = 5.0; // tollerance value
int threshold = 550;     // threshold for the position of the solar array

// servo motor control variables
const double maxSpeed = 600.0d;
double acceleration = 300.0d;
int movePos = 240;

int avt = (lt + rt) / 2; // average value top
int avd = (ld + rd) / 2; // average value down
int avl = (lt + ld) / 2; // average value left
int avr = (rt + rd) / 2; // average value right

int dvert = avt - avd; // check the diffirence of up and down
int dhoriz = avl - avr;// check the diffirence og left and rigt




/*
 * Movement based functions
 */

// Move solar panels to the Left
void moveLeft()
{
    stepperh1.setMaxSpeed(maxSpeed);
    stepperh1.setAcceleration(acceleration);
    stepperh1.moveTo(-movePos);
    stepperh1.run();
}

// move solar panels to the right
void moveRight()
{
    stepperh1.setMaxSpeed(maxSpeed);
    stepperh1.setAcceleration(acceleration);
    stepperh1.moveTo(movePos);
    stepperh1.run();
}

// move solar panels upwards
void moveUp()
{
    stepperv1.setMaxSpeed(maxSpeed);
    stepperv1.setAcceleration(acceleration);
    stepperv1.moveTo(movePos);
    stepperv1.run();
}

// move solar panels downwards
void moveDown()
{
    stepperv1.setMaxSpeed(maxSpeed);
    stepperv1.setAcceleration(acceleration);
    stepperv1.moveTo(-movePos);
    stepperv1.run();
}


// print out the averages of the 
void printAverageMsg()
{
    Serial.print(avt);
    Serial.print(" ");
    Serial.print(avd);
    Serial.print(" ");
    Serial.print(avl);
    Serial.print(" ");
    Serial.print(avr);
    Serial.println("");
}


// print out the voltage from the solar panels
void printVoltage()
{
    Serial.print("Voltage: ");
    Serial.print(getVoltage());
    Serial.println("");
}


/*
 * Getters and Print Functions
 */

// get the voltage from the solar panel
float getVoltage()
{
    return (analogRead(solar) / 1023) * 5;
}

// Top left Sensor
int getTopLeft()
{
    return analogRead(ldrlt);
}

// Top right sensor
int getTopRight()
{
    return analogRead(ldrrt);
}

// Bottom left sensor
int getBottomLeft()
{
    return analogRead(ldrld);
}

// Bottom right sensor
int getBottomRight()
{
    return analogRead(ldrrd);
}


/*
 * The Test Environment will be setup with a console input
 * 
 */