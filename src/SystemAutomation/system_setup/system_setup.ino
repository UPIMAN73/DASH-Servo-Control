/*
 * @author Joshua Calzadillas
 * @date December 1, 2019
 * 
 * @desc
 * Main System code for running the DASH System
 */

// Included Libraries
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "digitaldevice.h"
#include "analogdevice.h"
#include "time.h"

// Predefined values
#define STEPS_PER_ROTATION 200
#define MOVEMENT_MODE SINGLE
#define MOVEMENT_SPEED 20.0
#define DURATION 60

// Define Pins
#define LDR_RT_PIN A0
#define LDR_LT_PIN A1
#define LDR_RB_PIN A2
#define LDR_LB_PIN A3

// Digital Pins
#define RELAY_1_PIN 7
#define RELAY_2_PIN 6

// Pin 1 is M1 & M2
// Pin 2 is M3 & M4
#define SMV_MOTOR_PIN 1
#define SMH_MOTOR_PIN 2

// Device Initialization

// Digital Devices
DigitalDevice r1 = DigitalDevice("Relay 1", RELAY_1_PIN, true);
DigitalDevice r2 = DigitalDevice("Relay 2", RELAY_2_PIN, true);

// Analog Devices
AnalogDevice ldr_rt = AnalogDevice("LDR Right Top", LDR_RT_PIN);
AnalogDevice ldr_lt = AnalogDevice("LDR Left Top", LDR_LT_PIN);
AnalogDevice ldr_lb = AnalogDevice("LDR Left Bottom", LDR_LB_PIN);
AnalogDevice ldr_rb = AnalogDevice("LDR Right Bottom", LDR_RB_PIN);

// Adafruit Motor Shield
Adafruit_MotorShield AMS = Adafruit_MotorShield();;
Adafruit_StepperMotor *smv = AMS.getStepper(STEPS_PER_ROTATION, SMV_MOTOR_PIN);
Adafruit_StepperMotor *smh = AMS.getStepper(STEPS_PER_ROTATION, SMH_MOTOR_PIN);


/*
 * Updated Variable List
 */

// auto shutoff functionality
long initialTime = 0L;
long finalTime = 0L;

// threshold and tollorance value definition
double threshold = 550.0d;
double tol = 3.0d;

// All analog device values
int ldrlt, ldrrt, ldrrb, ldrlb; //ldr values
int avt = 0;
int avb = 0;
int avl = 0;
int avr = 0; // averages

// Control Boolean
bool runAuthentication = true;
bool shutoffInit = false;


/*
 * SETUP
 */
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting System\nPlease wait for 3 seconds before seeing any results...");
  delay(3000);

  // Begin the initialization of the Adafruit Motorshield
  AMS.begin();

  // movement speed
  smv->setSpeed(MOVEMENT_SPEED);
  smh->setSpeed(MOVEMENT_SPEED);

  // TODO HOTWIRE CODE HERE

  // set teh initial time to the current runtime
  initialTime = ATime().currentTime();
}


void horizontalForward();
void horizontalBackward();
void verticalForward();
void verticalBackward();
void shutOff();

void loop() 
{
  // Auto Shutoff Functionality
  //if ((ATime().deltaTime(initialTime, finalTime) >= DURATION * 1000))
  if (Serial.readString().equals("kill"))
  {
    Serial.println();
    Serial.print(DURATION);
    Serial.println(" Seconds have already reached...");
    runAuthentication = false;
  }

  // put your main code here, to run repeatedly:
  if (runAuthentication)
  {
      //Serial.println(analogRead(A0));
      finalTime = ATime().currentTime();
      
      // getting analog input values
      ldrlt = ldr_lt.getValue();
      ldrrt = ldr_rt.getValue();
      ldrrb = ldr_rb.getValue();
      ldrlb = ldr_lb.getValue();

      // calculating averages
      avt = (ldrlt + ldrrt) / 2; // average value up
      avb = (ldrlb + ldrrb) / 2; // average value down
      avl = (ldrlt + ldrlb) / 2; // average value left
      avr = (ldrrt + ldrrb) / 2; // average value right
      
      //Stop Movement when no  light detected      
      if((avt < threshold) && (avb < threshold) && (avl < threshold) && (avr < threshold)) 
      {
        // Do Nothing
      }

      //Horizontal Movement
      if(avr > avl + tol)
      {
        Serial.println("Horizontal Forward");
        horizontalForward();
      }

//      else if(avl > avr + tol)
//      {
//        horizontalBackward();
//      }
//
//      else {} // Do Nothing
//
//      //Vertical Movement
//      if(avt > avb + tol)  
//      {
//        verticalForward(); 
//      }
//
//      else if(avb > avt + tol)  
//      {
//        verticalBackward();
//      }

      else{}  // do nothing
  }

  // Shutoff initialized
  else
  {
    if (!shutoffInit)
    {
      shutOff();
      shutoffInit = true;
    }
  }
 }

/*
 * Vertical Motor Movement
 */

void verticalForward()
{
    //Serial.println("Moving VERTICAL motor backward");
    smv->step(100, FORWARD, MOVEMENT_MODE);
}

void verticalBackward()
{
    //Serial.println("Moving VERTICAL motor backward");
    smv->step(100, BACKWARD, MOVEMENT_MODE);
}

/*
 * Horizontal Motor Movement
 */
void horizontalForward()
{
    //Serial.println("Moving horizontal motor forward");
    smh->step(100, FORWARD, MOVEMENT_MODE);
}

void horizontalBackward()
{
    //Serial.println("Moving horizontal motor backward");
    smh->step(100, BACKWARD, MOVEMENT_MODE);
}

// This is the shut-off process of the entire board
void shutOff()
{
    Serial.println("Initiating Auto-Shutoff");
    r1.setValue(false);
    r2.setValue(false);
    // Make sure the step process if nullified
    //smh->step(0, FORWARD, MOVEMENT_MODE);
    //smv->step(0, FORWARD, MOVEMENT_MODE);
    
    // Release all of the motors
    smh->release();
    smv->release();
    Serial.println("Auto-Shutoff Engaged");
}
