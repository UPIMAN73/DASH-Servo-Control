#include <Servo.h> // include Servo library 
#include <CustomStepper.h>
#include <AccelStepper.h>
#include <AFMotor.h>

// two stepper motors one on each port
AF_Stepper motor1(4075.7728395, 1);
AF_Stepper motor2(4075.7728395, 2);

// you can change these to DOUBLE or INTERLEAVE or MICROSTEP!
// wrappers for the first motor!
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

AccelStepper stepperv1(forwardstep1,backwardstep1);
//AccelStepper stepperv2(backwardstep1);
AccelStepper stepperh1(forwardstep2,backwardstep2);
//AccelStepper stepperh2(backwardstep2);



int stepperhLimitHigh = 2037.88641975;
int stepperhLimitLow = -2037.88641975;


int steppervLimitHigh = 2037.88641975;
int steppervLimitLow = -2037.88641975;

// LDR pin connections
//  name  = analogpin;
int ldrlt = 2; //LDR top left - BOTTOM LEFT    <--- BDG
int ldrrt = 3; //LDR top rigt - BOTTOM RIGHT 
int ldrld = 0; //LDR down left - TOP LEFT
int ldrrd = 1; //ldr down rigt - TOP RIGHT
int solar = 5;
const float referenceVolts = 5.0; 


void setup()
{  
  Serial.begin(9600);

  delay(3000);
}

void loop() 
{
  int lt = analogRead(ldrlt); // top left
  int rt = analogRead(ldrrt); // top right
  int ld = analogRead(ldrld); // down left
  int rd = analogRead(ldrrd); // down rigt
  
  // int dtime = analogRead(4)/20; // read potentiometers  
  // int tol = analogRead(5)/4;
  int dtime = 10;
  int tol = 5;
  int threshold = 550;
  
  int avt = (lt + rt) / 2; // average value top
  int avd = (ld + rd) / 2; // average value down
  int avl = (lt + ld) / 2; // average value left
  int avr = (rt + rd) / 2; // average value right

  int dvert = avt - avd; // check the diffirence of up and down
  int dhoriz = avl - avr;// check the diffirence og left and rigt

  int val = analogRead(solar);
  float volts = (val/1023)*5;//*referenceVolts;
  Serial.print(volts);
  Serial.print(" ");
  
  Serial.print(avt);
  Serial.print(" ");
  Serial.print(avd);
  Serial.print(" ");
  Serial.print(avl);
  Serial.print(" ");
  Serial.print(avr);
  Serial.print("   ");
  Serial.print(dtime);
  Serial.print("   ");
  Serial.print(tol);
  Serial.println(" ");

  //Stop Movement when no  light detecetd
  if((avt < threshold) && (avd < threshold) && (avl < threshold) && (avr < threshold)) {}

  //Horizontal Movement
  if(avr > avl + tol)
  {
    stepperh1.setMaxSpeed(600.0);
    stepperh1.setAcceleration(300.0);
    stepperh1.moveTo(240);
    stepperh1.run();
  }
  else if(avl > avr +tol)
  {
    stepperh1.setMaxSpeed(600.0);
    stepperh1.setAcceleration(300.0);
    stepperh1.moveTo(-240);
    stepperh1.run();
    //stepperh2.run();
  }
  else {}

  //Vertical Movement
  if(avt > avd + tol)  
  {
    
    stepperv1.setMaxSpeed(600.0);
    stepperv1.setAcceleration(300.0);
    stepperv1.moveTo(240);    
    stepperv1.run();   
  }
  else if(avd > avt + tol)  
  {
    stepperv1.setMaxSpeed(600.0);
    stepperv1.setAcceleration(300.0);
    stepperv1.moveTo(-240);    
    stepperv1.run();     
  }
  else{}  // do nothing
}
  
  
