/*
 * @author Joshua Calzadillas
 * @date December 1, 2019
 * 
 * @desc
 * Main System code for running the DASH System for Showcase
 */

// Included Libraries
#include <Wire.h>
#include <AccelStepper.h>
#include <AFMotor.h>
#include "digitaldevice.h"
#include "analogdevice.h"
#include "time.h"

// Predefined values
#define STEPS_PER_ROTATION 200
#define MOVEMENT_MODE SINGLE
#define MOVEMENT_SPEED 200.0

// Hotwire Values
#define DURATION 3
#define TIMES_RUN_HOTWIRE 3


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


void shutOff();

// Adafruit Motor Shield
// two stepper motors one on each port
AF_Stepper smv(MOVEMENT_SPEED, SMV_MOTOR_PIN);
AF_Stepper smh(MOVEMENT_SPEED, SMH_MOTOR_PIN);

/*
 * Vertical Motor Movement
 */

void verticalForward()
{
    Serial.println("Moving VERTICAL motor backward");
    smv.onestep(FORWARD, SINGLE);
}

void verticalBackward()
{
    Serial.println("Moving VERTICAL motor backward");
    smv.onestep(BACKWARD, SINGLE);
}

/*
 * Horizontal Motor Movement
 */
void horizontalForward()
{
    Serial.println("Moving horizontal motor forward");
    smh.onestep(FORWARD, SINGLE);
}

void horizontalBackward()
{
    Serial.println("Moving horizontal motor backward");
    smh.onestep(BACKWARD, SINGLE);
}

// Motor shield has two motor ports, now we'll wrap them in an AccelStepper object
AccelStepper smvs(verticalForward, verticalBackward);
AccelStepper smhs(horizontalForward, horizontalBackward);

/*
 * Updated Variable List
 */

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


/*
 * SETUP
 */
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting System\nPlease wait for 3 seconds before seeing any results...");
  delay(3000);

  smvs.moveTo(360);
  smvs.setMaxSpeed(MOVEMENT_SPEED);
  smvs.setAcceleration(MOVEMENT_SPEED);
  
  smhs.moveTo(360);
  smhs.setMaxSpeed(MOVEMENT_SPEED);
  smhs.setAcceleration(MOVEMENT_SPEED);
  
  // HOTWIRE RUN LOOP
  Serial.print("\nTurning on the device: ");
  Serial.print(r1.getName());
  Serial.print("  and   ");
  Serial.println(r2.getName());

  // turning the hotwire on and off
  for (int i = 1; i < TIMES_RUN_HOTWIRE; i++)
  {
    r1.setValue(true);
    r2.setValue(true);
    delay(DURATION * 1000);
    r1.setValue(false);
    r2.setValue(false);
    delay(500);
  }

  Serial.println("Hotwire release mechanism complete...");

  // set the initial time to the current runtime
}

void loop() 
{
  // Auto Shutoff Functionality
  if (Serial.available() > 0)
  {
    if (Serial.readString().equals("kill\n"))
    {
      runAuthentication = false;
      shutOff();
    }
  }

  // run main loop
  else
  {
    // put your main code here, to run repeatedly:
    if (runAuthentication)
    {
        //Serial.println(analogRead(A0));        
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
          horizontalForward();
        }

        else if(avl > avr + tol)
        {
          horizontalBackward();
        }

        else {} // Do Nothing

        //Vertical Movement
        if(avt > avb + tol)  
        {
          verticalForward(); 
        }

        else if(avb > avt + tol)  
        {
          verticalBackward();
        }

        else{}  // do nothing
    }
  }
  
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

    // stopping motors from rotating
    smvs.stop();
    smhs.stop();
    
    // Release all of the motors
    //smh->release();
    //smv->release();
    Serial.println("Auto-Shutoff Engaged");
}
