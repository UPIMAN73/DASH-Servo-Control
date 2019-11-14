#include "motortest.h"

#define DURATION 10

// Define Pins
#define LDR_RT_PIN A0
#define LDR_LT_PIN A1
#define LDR_RB_PIN A2
#define LDR_LB_PIN A3

void run();
MotorTest mt = MotorTest(0, "", 0, 0, 0);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(500);  
  
  // Motor Test
  mt = MotorTest(1.0, "Motor Limit Tollerance Value", 0.0, 10.0, DURATION * 1000);
  mt.setup();
}

// Analog Devices
AnalogDevice ldr_rt = AnalogDevice("LDR Right Top", LDR_RT_PIN);
AnalogDevice ldr_lt = AnalogDevice("LDR Left Top", LDR_LT_PIN);
AnalogDevice ldr_lb = AnalogDevice("LDR Left Bottom", LDR_LB_PIN);
AnalogDevice ldr_rb = AnalogDevice("LDR Right Bottom", LDR_RB_PIN);

// Run test mode for the testing environment
void run()
{
  Serial.println(mt.getName());
  // threshold and tollorance value definition
  double threshold = 0;
  double tol = 0;
  long motorValue = 0L;

  // All analog device values
  int ldrlt, ldrrt, ldrrb, ldrlb; //ldr values
  int avt = 0;
  int avb = 0;
  int avl = 0;
  int avr = 0; // averages

  // This is the run loop to offically run the test mode
  long initialTime = ATime().currentTime();
  long finalTime = 0L; 

  // Iteration aspect
  for (double i = mt.getInitialValue(); i < mt.getFinalValue(); i += mt.getSteps())
  {
    threshold = 550;
    tol = i;
    long initialTime = ATime().currentTime();
    motorValue = 0L;

    // run loop
    while (ATime().deltaTime(initialTime, finalTime) <= mt.getDuration())
    {
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
        // stepperh1.setMaxSpeed(600.0);
        // stepperh1.setAcceleration(300.0);
        // stepperh1.moveTo(240);
        // stepperh1.run();
        motorValue++;
      }
      else if(avl > avr + tol)
      {
        // stepperh1.setMaxSpeed(600.0);
        // stepperh1.setAcceleration(300.0);
        // stepperh1.moveTo(-240);
        // stepperh1.run();
        motorValue++;
      }
      else {} // Do Nothing

      //Vertical Movement
      if(avt > avb + tol)  
      {
        
        // stepperv1.setMaxSpeed(600.0);
        // stepperv1.setAcceleration(300.0);
        // stepperv1.moveTo(240);    
        // stepperv1.run();
        motorValue++;   
      }
      else if(avb > avt + tol)  
      {
        // stepperv1.setMaxSpeed(600.0);
        // stepperv1.setAcceleration(300.0);
        // stepperv1.moveTo(-240);    
        // stepperv1.run();
        motorValue++;
      }
      else{}  // do nothing
    }
    Serial.println(motorValue);
  }
}


bool running = false;
void loop() {
  // put your main code here, to run repeatedly:
  //TODO
  while (!running)
  {
    run();
    running = true;
  }
}
