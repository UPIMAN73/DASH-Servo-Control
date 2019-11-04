/*
 * @author Joshua Calzadillas
 * @description This program is meant to test out the threshold value
 * for the motor rotoation. This will help decide how often the motors move,
 * and to what position do they move to.
 */


/*
 * Libraries
 */

// C Libraries
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
float tollerance = 5.0; // tollerance value
int threshold = 550;     // threshold for the position of the solar array

// servo motor control variables
const float maxSpeed = 600.0;
float acceleration = 300.0;
int movePos = 240;


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


void printLn(String s) 
{
    Serial.println(s);#include <String.h>

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
 * Obtain information from the arduino to then save it to a 
 * Redirect this info to a computer to then a savefile
 */

#define MAX_T    10                         // Maximum threshold value
#define MAX_LONG 4294967295L                // Maximum Long Number
#define MAX_float 1.1754942107  // Maximum float number
#define ITERSTEP 0.5                        // Iteration step size
#define trials_length  (MAX_T / ITERSTEP)   // this is used for testing setup for array obtaining information.



int n = MAX_T;                        // maximum threshold value
float tv1;                           // threshold value 1
float maxSolarValue = 0.0;           // maximum solar panel value
float avgSolarValue = 0.0;           // Average solar panel value
float minSolarValue = 1.79769e+308;  // minimum solar panel value
unsigned long motorValue = 0L;        // current motor value
int mindex = 0;                       // position of the motor index

unsigned long* motorValues = new unsigned long[trials_length];


// this counts the maximum amount of times the maximum possible number of a long can be called
int getMultiplesMotor(unsigned long *sv)
{
    int res = -1;

    for (int i = 0; i < sizeof(sv); i++)
    {
        if (sv[i] == 0)
            break;

        else
        {
            res++;
        }
    }
    
    return res;
}

// get minimum motor value index.
int getMinMotorValue(unsigned long* mv)
{
    unsigned long mnmv = MAX_LONG;
    int index = -1;

    for (int i = 0; i < sizeof(mv); i++)
    {
        // break if at end of trailing data
        if (mv[i] == 0)
            break;
        
        // check to see what the index is
        if (mv[i] < mnmv)
            index = i;
        
        // set the max value to the highest solar value
        mnmv = (mv[i] < mnmv) ? mv[i] : mnmv;
    }

    return index;
}

// check to see if motor value has reached maximum potential
void motorCheck()
{
    if (motorValue >= MAX_LONG - 1)
    {
        motorValues[mindex] = motorValue;
        mindex++;
        motorValue = motorValue % MAX_LONG-1;
    }
}

// print out the Motor Value from the Trials
void printMotorValue()
{
    Serial.print("Motor Value: ");
    Serial.print(motorValue);
    Serial.println("");
}

//  print out a line to the serial console
void printLn(String s)
{
    Serial.pritnln(s);
}


// TODO Control Loop for this project

/*
 * Time Based setup
 */

#define TIME_DELTA 30 // the number of seconds used to run each trial
time_t i; // Initial Time
time_t f; // Final Time


/*
 * Arduino Main Loop Functions
 */

int iter = 0;
float curVoltage;
float* cur_thresh = &n;
void loop()
{
    curVoltage = 0.0d;
    time(&i);
    iter = 0;

    // threshold loop
    while ((f - i) < TIME_DELTA && cur_thresh > 0.0)
    {
        time(&f);
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
            motorValue++;
            moveRight();
        }
        else if(avl > avr + tollerance)
        {
            motorValue++;
            moveLeft();
        }
        else {} // Do Nothing

        //Vertical Movement
        if(avt > avd + tollerance)  
        {
            motorValue++;
            moveUp();
        }

        else if(avd > avt + tollerance)  
        {
            motorValue++;
            moveDown();
        }
        else{}  // do nothing

        motorCheck();
        printVoltage();
        printMotorValue();

        // voltage stuff
        curVoltage = (float) getVoltage();
        maxSolarValue = (curVoltage > maxSolarValue) ? curVoltage : maxSolarValue;
        minSolarValue = (curVoltage < minSolarValue) ? curVoltage : minSolarValue;
        avgSolarValue += curVoltage;
        iter++;
    }

    // solar values and decrementing a step of the threshold
    String solarValues = "Solar Value (Max): ";
    solarValues.concat(maxSolarValue);
    solarValues.concat("   Solar Value (Min): ");
    solarValues.concat(minSolarValue);
    solarValues.concat("   Solar Value (Avg): ");
    solarValues.concat(avgSolarValue/iter);
    printLn(solarValues);
    *cur_thresh -= ITERSTEP;
}
