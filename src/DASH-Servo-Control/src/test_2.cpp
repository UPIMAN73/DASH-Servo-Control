// /*
//  * @author Joshua Calzadillas
//  * @date December 1, 2019
//  * 
//  * @desc
//  * Main System code for running the DASH System for Showcase
//  */

// // Included Libraries
// #include <Arduino.h>
// #include <Wire.h>
// #include <AccelStepper.h>
// #include <AFMotor.h>
// #include "../include/devices/digitaldevice.h"
// #include "../include/devices/analogdevice.h"
// #include "../include/generic/time.h"
// #include "../include/systems/ldrsystem.h"

// // Predefined values
// #define STEPS_PER_ROTATION 200
// #define MOVEMENT_MODE SINGLE
// #define MOVEMENT_SPEED 200.0

// // Hotwire Values
// #define DURATION 3
// #define TIMES_RUN_HOTWIRE 3

// // Digital Pins
// #define RELAY_1_PIN 7
// #define RELAY_2_PIN 6

// // Pin 1 is M1 & M2
// // Pin 2 is M3 & M4
// #define SMV_MOTOR_PIN 1
// #define SMH_MOTOR_PIN 2

// // Device Initialization

// // Digital Devices
// DigitalDevice r1 = DigitalDevice("Relay 1", RELAY_1_PIN, true);
// DigitalDevice r2 = DigitalDevice("Relay 2", RELAY_2_PIN, true);

// // Analog Devices
// AnalogDevice ldr_rt = AnalogDevice("LDR Right Top", LDR_RT_PIN);
// AnalogDevice ldr_lt = AnalogDevice("LDR Left Top", LDR_LT_PIN);
// AnalogDevice ldr_lb = AnalogDevice("LDR Left Bottom", LDR_LB_PIN);
// AnalogDevice ldr_rb = AnalogDevice("LDR Right Bottom", LDR_RB_PIN);

// // movement check setup
// long movements[4] = {0, 0, 0, 0};

// void shutOff();

// // Adafruit Motor Shield
// // two stepper motors one on each port
// AF_Stepper smv(MOVEMENT_SPEED, SMV_MOTOR_PIN);
// AF_Stepper smh(MOVEMENT_SPEED, SMH_MOTOR_PIN);

// /*
//  * Vertical Motor Movement
//  */

// void verticalForward()
// {
//     movements[0] += 1;
//     smv.onestep(FORWARD, SINGLE);
// }

// void verticalBackward()
// {
//     movements[1] += 1;
//     smv.onestep(BACKWARD, SINGLE);
// }

// /*
//  * Horizontal Motor Movement
//  */
// void horizontalForward()
// {
//     movements[2] += 1;
//     smh.onestep(FORWARD, SINGLE);
// }

// void horizontalBackward()
// {
//     movements[3] += 1;
//     smh.onestep(BACKWARD, SINGLE);
// }

// // Motor shield has two motor ports, now we'll wrap them in an AccelStepper object
// AccelStepper smvs(verticalForward, verticalBackward);
// AccelStepper smhs(horizontalForward, horizontalBackward);

// /*
//  * Updated Variable List
//  */

// // threshold and tollorance value definition
// double threshold = 550.0d;
// double tol = 3.0d;

// // All analog device values
// int ldrlt, ldrrt, ldrrb, ldrlb; //ldr values
// int avt = 0;
// int avb = 0;
// int avl = 0;
// int avr = 0; // averages

// // Control Boolean
// bool runAuthentication = true;


// /*
//  * SETUP
//  */
// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);
//   Serial.println("Starting System\nPlease wait for 3 seconds before seeing any results...");
//   delay(3000);

//   smvs.moveTo(1);
//   smvs.setSpeed(MOVEMENT_SPEED);
//   smvs.setMaxSpeed(MOVEMENT_SPEED);
  
//   smhs.moveTo(1);
//   smhs.setSpeed(MOVEMENT_SPEED);
//   smhs.setMaxSpeed(MOVEMENT_SPEED);
  
//   // HOTWIRE RUN LOOP
//   Serial.print("\nTurning on the device: ");
//   Serial.print(r1.getName());
//   Serial.print("  and   ");
//   Serial.println(r2.getName());

//   // turning the hotwire on and off
//   for (int i = 1; i < TIMES_RUN_HOTWIRE; i++)
//   {
//     r1.setValue(true);
//     r2.setValue(true);
//     delay(DURATION * 1000);
//     r1.setValue(false);
//     r2.setValue(false);
//     delay(500);
//   }

//   Serial.println("Hotwire release mechanism complete...");

//   // set the initial time to the current runtime
// }

// String cmdString = "";

// // test mode
// bool testMode = false;
// bool leftMode = false;
// bool topMode = false;
// bool rightMode = false;
// bool bottomMode = false;

// void loop() 
// {
//   // Auto Shutoff Functionality
//   if (Serial.available() > 0)
//   {
//     Serial.println("Recieved a signal from the host computer.");
//     cmdString = Serial.readString();
//     Serial.println(cmdString);

//     // killswitch
//     if (cmdString.equals("kill\n") || cmdString.equals("kill") || cmdString.equals("q") || cmdString.equals("q\n"))
//     {
//       runAuthentication = false;
//       shutOff();
//       Serial.println("\n\nPrinting out the amount of times each were called.");
//       Serial.print("Vertical Forward: ");
//       Serial.print(movements[0]);
//       Serial.println();

//       Serial.print("Vertical Backward: ");
//       Serial.print(movements[1]);
//       Serial.println();

//       Serial.print("Horizontal Forward: ");
//       Serial.print(movements[2]);
//       Serial.println();

//       Serial.print("Horizontal Backward: ");
//       Serial.print(movements[3]);
//       Serial.println();
//     }

//     else if (cmdString.equals("test\n") || cmdString.equals("test"))
//     {
//       if (runAuthentication)
//       {
//         runAuthentication = false;
//       }

//       if (!testMode)
//       {
//         testMode = true;
//       }
//     }

//     // stop test mode
//     else if (cmdString.equals("stop\n") || cmdString.equals("stop"))
//     {
//       if (testMode)
//       {
//         testMode = false;
//       }

//       if (!runAuthentication)
//       {
//         runAuthentication = true;
//       }
//       delay(2000);
//       Serial.println("Stopping Test Mode");
//     }

//     // left
//     else if (cmdString.equals("left\n") || cmdString.equals("left"))
//     {
//       if (!leftMode || topMode || rightMode || bottomMode)
//       {
//         Serial.println("Left Test Mode");
//         topMode = false;
//         bottomMode = false;
//         rightMode = false;
//         leftMode = true;
//       }
//       else
//       {
//         Serial.println("Stopping Left Test Mode");
//         topMode = false;
//         bottomMode = false;
//         rightMode = false;
//         leftMode = false;
//       }
//     }

//     // top
//     else if (cmdString.equals("top\n") || cmdString.equals("top"))
//     {
//       if (leftMode || !topMode || rightMode || bottomMode)
//       {
//         Serial.println("Top Test Mode");
//         topMode = true;
//         bottomMode = false;
//         rightMode = false;
//         leftMode = false;
//       }
//       else
//       {
//         Serial.println("Stopping Top Test Mode");
//         topMode = false;
//         bottomMode = false;
//         rightMode = false;
//         leftMode = false;
//       }
//     }

//     // bottom
//     else if (cmdString.equals("bottom\n") || cmdString.equals("bottom"))
//     {
//       if (leftMode || topMode || rightMode || !bottomMode)
//       {
//         Serial.println("Bottom Test Mode");
//         topMode = false;
//         bottomMode = true;
//         rightMode = false;
//         leftMode = false;
//       }
//       else
//       {
//         Serial.println("Ending Bottom Test Mode");
//         topMode = false;
//         bottomMode = false;
//         rightMode = false;
//         leftMode = false;
//       }
//     }

//     // right
//     else if (cmdString.equals("right\n") || cmdString.equals("right"))
//     {
//       if (leftMode || topMode || !rightMode || bottomMode)
//       {
//         Serial.println("Right Test Mode");
//         topMode = false;
//         bottomMode = false;
//         rightMode = true;
//         leftMode = false;
//       }
//       else
//       {
//         Serial.println("Ending Right Test Mode");
//         topMode = false;
//         bottomMode = false;
//         rightMode = false;
//         leftMode = false;
//       }
//     }

//     else if (cmdString.equals("threshold\n") || cmdString.equals("threshold"))
//     {
//       Serial.println("Please enter a number: ");
//       while (true)
//       {
//         if (Serial.available() > 0)
//         {
//           threshold = Serial.parseFloat();
//         }

//         if (threshold >= 0.0f || threshold <= 1025.0f)
//         {
//           break;
//         }
//         else
//         {
//           Serial.println("You need to enter a number between 0-1024");
//           Serial.println("Please enter a number: ");
//           while (Serial.available() <= 0)
//           {}
//         }
        
//       }
      
//     }
      
//   }

//   // run main loop
//   else
//   {
//     // put your main code here, to run repeatedly:
//     if (runAuthentication)
//     {
//         //Serial.println(analogRead(A0));        
//         // getting analog input values
//         ldrlt = ldr_lt.getValue();
//         ldrrt = ldr_rt.getValue();
//         ldrrb = ldr_rb.getValue();
//         ldrlb = ldr_lb.getValue();

//         // calculating averages
//         avt = (ldrlt + ldrrt) / 2; // average value up
//         avb = (ldrlb + ldrrb) / 2; // average value down
//         avl = (ldrlt + ldrlb) / 2; // average value left
//         avr = (ldrrt + ldrrb) / 2; // average value right

//         Serial.print("Average Right: ");
//         Serial.println(avr);

//         Serial.print("Average Left: ");
//         Serial.println(avl);
        
//         Serial.print("Average Top: ");
//         Serial.println(avt);

//         Serial.print("Average Bottom: ");
//         Serial.println(avb);
//         //Stop Movement when no  light detected      
//         if((avt < threshold) && (avb < threshold) && (avl < threshold) && (avr < threshold)) 
//         {
//           // Do Nothing
//         }

//         //Horizontal Movement
//         else if(avr > avl + 100.0f)
//         {
//           horizontalForward();
//         }

//         else if(avl > avr + 100.0f)
//         {
//           horizontalBackward();
//         }

//         else{}
//         delay(1);

//         //Vertical Movement
//         if(avt > avb + tol)  
//         {
//           verticalForward(); 
//         }

//         else if(avb > avt + tol)  
//         {
//           verticalBackward();
//         }

//         else{}  // do nothing
//     }
//   }
  
//   // Test Mode
//   if (testMode)
//   {
//         // left LDR for left motors
//         if (leftMode)
//         {
//           // getting analog input values
//           ldrlt = ldr_lt.getValue();
//           ldrlb = ldr_lb.getValue();
//           // ldrrt = ldr_rt.getValue();
//           // ldrrb = ldr_rb.getValue();

//           // calculating averages
//           avl = (ldrlt + ldrlb) / 2; // average value left
//           // avr = (ldrrt + ldrrb) / 2; // average value left

//           // LDR LT
//           Serial.print("LDR LT: ");
//           Serial.println(ldrlt);

//           // LDR LB
//           Serial.print("LDR LB: ");
//           Serial.println(ldrlb);

//           // LDR Average L
//           Serial.print("LDR AVGL: ");
//           Serial.println(avl);

//           // LDR Average R
//           // Serial.print("LDR AVGR: ");
//           // Serial.println(avr);

//           if (avl > threshold)
//           {
//             horizontalForward();
//           }

//           //if (avl > avr + tol)
//           // {
//           //   horizontalForward();
//           // }
//         }

//         // Right Mode
//         // Right  LDR for Right motors
//         if (rightMode)
//         {
//           // getting analog input values
//           // ldrlt = ldr_lt.getValue();
//           // ldrlb = ldr_lb.getValue();
//           ldrrt = ldr_rt.getValue();
//           ldrrb = ldr_rb.getValue();

//           // calculating averages
//           // avl = (ldrlt + ldrlb) / 2; // average value left
//           avr = (ldrrt + ldrrb) / 2; // average value left

//           // LDR LT
//           Serial.print("LDR RT: ");
//           Serial.println(ldrrt);

//           // LDR LB
//           Serial.print("LDR RB: ");
//           Serial.println(ldrrb);

//           // LDR Average L
//           Serial.print("LDR AVGR: ");
//           Serial.println(avr);

//           // LDR Average R
//           // Serial.print("LDR AVGL: ");
//           // Serial.println(avl);

//           if (avr > threshold)
//           {
//             horizontalBackward();
//           }

//           // if (avl > avr + tol)
//           // {
//           //   horizontalBackward();
//           // }
//         }

//       // Bottom Mode
//       if (bottomMode)
//       {
//           // getting analog input values
//           // ldrlt = ldr_lt.getValue();
//           // ldrrt = ldr_rt.getValue();
//           ldrlb = ldr_lb.getValue();
//           ldrrb = ldr_rb.getValue();

//           // calculating averages
//           // avt = (ldrlt + ldrrt) / 2; // average value left
//           avb = (ldrlb + ldrrb) / 2; // average value left

//           // LDR LT
//           Serial.print("LDR LB: ");
//           Serial.println(ldrlb);

//           // LDR LB
//           Serial.print("LDR RB: ");
//           Serial.println(ldrrb);

//           // LDR Average L
//           Serial.print("LDR AVGb: ");
//           Serial.println(avb);

//           // LDR Average R
//           // Serial.print("LDR AVGT: ");
//           // Serial.println(avt);

//           if (avb > threshold)
//           {
//             verticalBackward();
//           }

//           // if (avb > avt + tol)
//           // {
//           //   horizontalBackward();
//           // }
//         }

//         // Bottom Mode
//       if (topMode)
//       {
//           // getting analog input values
//           ldrlt = ldr_lt.getValue();
//           ldrrt = ldr_rt.getValue();
//           // ldrlb = ldr_lb.getValue();
//           // ldrrb = ldr_rb.getValue();

//           // calculating averages
//           avt = (ldrlt + ldrrt) / 2; // average value left
//           // avb = (ldrlb + ldrrb) / 2; // average value left

//           // LDR LT
//           Serial.print("LDR LT: ");
//           Serial.println(ldrlt);

//           // LDR LB
//           Serial.print("LDR RT: ");
//           Serial.println(ldrrt);

//           // LDR Average L
//           Serial.print("LDR AVGT: ");
//           Serial.println(avt);

//           // LDR Average R
//           // Serial.print("LDR AVGB: ");
//           // Serial.println(avb);

//           if (avt > threshold)
//           {
//             verticalForward();
//           }

//           // if (avt > avb + tol)
//           // {
//           //   horizontalBackward();
//           // }
//         }

//         // END
//   }
//  }



// // This is the shut-off process of the entire board
// void shutOff()
// {
//     Serial.println("Initiating Auto-Shutoff");
//     r1.setValue(false);
//     r2.setValue(false);
//     // Make sure the step process if nullified
//     //smh->step(0, FORWARD, MOVEMENT_MODE);
//     //smv->step(0, FORWARD, MOVEMENT_MODE);

//     // stopping motors from rotating
//     smvs.stop();
//     smhs.stop();
    
//     // Release all of the motors
//     //smh->release();
//     //smv->release();
//     Serial.println("Auto-Shutoff Engaged");
// }
