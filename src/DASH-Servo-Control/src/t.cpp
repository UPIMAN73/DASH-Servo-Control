// #include <Arduino.h>
// #include <Wire.h>
// #include <AccelStepper.h>
// #include <AFMotor.h>
// #include "../include/devices/digitaldevice.h"
// #include "../include/devices/analogdevice.h"
// #include "../include/generic/time.h"

// // Predefined values
// #define STEPS_PER_ROTATION 200
// #define MOVEMENT_MODE SINGLE
// #define MOVEMENT_SPEED 200.0

// // time constants
// #define DURATION 10

// // Pin 1 is M1 & M2
// // Pin 2 is M3 & M4
// #define SMV_MOTOR_PIN 1
// #define SMH_MOTOR_PIN 2

// // Adafruit Motor Shield
// // two stepper motors one on each port
// AF_Stepper smv(MOVEMENT_SPEED, SMV_MOTOR_PIN);
// AF_Stepper smh(MOVEMENT_SPEED, SMH_MOTOR_PIN);

// /*
//  * Vertical Motor Movement
//  */

// void verticalForward()
// {
//     smv.onestep(FORWARD, SINGLE);
// }

// void verticalBackward()
// {
//     smv.onestep(BACKWARD, SINGLE);
// }

// /*
//  * Horizontal Motor Movement
//  */
// void horizontalForward()
// {
//     smh.onestep(FORWARD, SINGLE);
// }

// void horizontalBackward()
// {
//     smh.onestep(BACKWARD, SINGLE);
// }

// // Motor shield has two motor ports, now we'll wrap them in an AccelStepper object
// AccelStepper smvs(verticalForward, verticalBackward);
// AccelStepper smhs(horizontalForward, horizontalBackward);
// static ATime * time = new ATime();

// // time variables
// unsigned long init_time = 0L;
// unsigned long final_time = 0L;

// // control setup
// void setup()
// {
//     Serial.begin(9600);
//     smvs.moveTo(1);
//     smvs.setSpeed(MOVEMENT_SPEED);
//     smvs.setMaxSpeed(MOVEMENT_SPEED);
    
//     smhs.moveTo(1);
//     smhs.setSpeed(MOVEMENT_SPEED);
//     smhs.setMaxSpeed(MOVEMENT_SPEED);
// }

// // control loop function
// void loop()
// {
//     // Horizontal Move Forwards
//     init_time = time->getCurrentSeconds();
//     Serial.println("Horizontal Move Forwards");
//     do
//     {
//         horizontalForward();
//     }
//     while ((time->getCurrentSeconds() - init_time) < DURATION);
//     delay(1000);

//     // Horizontal Move Backwards
//     init_time = time->getCurrentSeconds();
//     Serial.println("Horizontal Move Backwards");
//     do
//     {
//         horizontalBackward();
//     }
//     while ((time->getCurrentSeconds() - init_time) < DURATION);
//     delay(1000);

//     // Vertical Move Forwards
//     init_time = time->getCurrentSeconds();
//     Serial.println("Vertical Move Forwards");
//     do
//     {
//         verticalForward();
//     }
//     while ((time->getCurrentSeconds() - init_time) < DURATION);
//     delay(1000);

//     // Vertical Move Backwards
//     init_time = time->getCurrentSeconds();
//     Serial.println("Vertical Move Backwards");
//     do
//     {
//         verticalBackward();
//     }
//     while ((time->getCurrentSeconds() - init_time) < DURATION);
//     delay(3000);
// }