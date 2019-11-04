/*
 * @author Joshua Calzadillas
 * @description This program is meant to test out the threshold value
 * for the motor rotoation. This will help decide how often the motors move,
 * and to what position do they move to.
 */


/*
 * Libraries
 */

// C Librarieswire
#include <time.h>

// Arduino Libraries
#include <Servo.h> // include Servo library 
#include <CustomStepper.h>
#include <AccelStepper.h>
#include <AFMotor.h>

/*
 * Global Variables
 */

// Motor Declatarions
AF_Stepper motor1(4075.7728395, 1);
AF_Stepper motor2(4075.7728395, 2);

void forwardstep1() {  
  motor1.onestep(FORWARD, SINGLE);
}
void backwardstep1() {  
  motor1.onestep(BACKWARD, SINGLE);
}
// wrappers for the second motor!
void forwardstep2() {  
  motor2.onestep(FORWARD, SINGLE);
}
void backwardstep2() {  
  motor2.onestep(BACKWARD, SINGLE);
}

// Stepper motor declarations
AccelStepper stepperv1(forwardstep1,backwardstep1);
AccelStepper stepperh1(forwardstep2,backwardstep2);


// Limits for potentiometers on steppers
int stepperhLimitHigh = 2037.88641975;
int stepperhLimitLow = -2037.88641975;

int steppervLimitHigh = 2037.88641975;
int steppervLimitLow = -2037.88641975;


// PINS for Arduino
int ldrlt = 2; //LDR top left - BOTTOM LEFT    <--- BDG
int ldrrt = 3; //LDR top rigt - BOTTOM RIGHT 
int ldrld = 0; //LDR down left - TOP LEFT
int ldrrd = 1; //ldr down rigt - TOP RIGHT
int solar = 5; // solar panel pin number

// int dtime = analogRead(4)/20; // read potentiometers  
// int tol = analogRead(5)/4;

const float referenceVolts = 5.0; // reference voltage

// setting variables that can be changed through the arduino console
int dtime = 10;          // difference in time
double tollerance = 5.0; // tollerance value
int threshold = 550;     // threshold for the position of the solar array

// servo motor control variables
const double maxSpeed = 600.0;
double acceleration = 300.0;
int movePos = 240;


// function calls 
void moveLeft();
void moveRight();
void moveUp();
void moveDown();

// print Function
void printAverageMsg();
void printVoltage();
void printLine();

// Get LDR Values
int getBottomLeft();
int getBottomRight();
int getTopLeft();
int getTopRight();
float getVoltage();



// TODO Make a function that consissts of these values
int avt = (getTopLeft() + getTopRight()) / 2; // average value top
int avd = (getBottomLeft() + getBottomRight()) / 2; // average value down
int avl = (getTopLeft() + getBottomLeft()) / 2; // average value left
int avr = (getTopRight() + getBottomRight()) / 2; // average value right

// differences in positions
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


//  print out a line to the serial console
void printLine(string s)
{
    Serial.pritnln(s);
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



// Main Code
double curVoltage;
int iter;

void loop()
{
    curVoltage = 0.0d;
    iter = 0;

    // threshold loop
    while (true)
    {
        // average position based calculations
        avt = (getTopLeft() + getTopRight()) / 2;
        avd = (getBottomLeft() + getBottomRight()) / 2;
        avl = (getTopLeft() + getBottomLeft()) / 2;
        avr = (getTopRight() + getBottomRight()) / 2;

        //Stop Movement when no  light detecetd
        if((avt < threshold) && (avd < threshold) && (avl < threshold) && (avr < threshold)) 
        {
            // Do Nothing
        }

        //Horizontal Movement
        if(avr > avl + tollerance)
        {
            moveRight();
        }
        else if(avl > avr + tollerance)
        {
            moveLeft();
        }
        else {} // Do Nothing

        //Vertical Movement
        if(avt > avd + tollerance)  
        {
            moveUp();
        }

        else if(avd > avt + tollerance)  
        {
            moveDown();
        }
        else{}  // do nothing

        printVoltage();

        // voltage stuff
        curVoltage = (double) getVoltage();
        maxSolarValue = (curVoltage > maxSolarValue) ? curVoltage : maxSolarValue;
        minSolarValue = (curVoltage < minSolarValue) ? curVoltage : minSolarValue;
        avgSolarValue += curVoltage;
    }
}
