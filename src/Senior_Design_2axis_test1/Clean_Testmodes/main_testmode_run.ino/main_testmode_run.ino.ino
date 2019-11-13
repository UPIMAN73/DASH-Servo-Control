#include "motortest.h"
//#include "jkmotor.h"
//TODO



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
  
  // TODO
  Motor m1 = Motor(-1, "Motor 1");
  Motor m2 = Motor(-2, "Motor 2");
  Serial.println(m1.getPin());
  Serial.println(m1.getName());
  Serial.println("\n\n");
  Serial.println(m2.getPin());
  Serial.println(m2.getName());
  
  
  // Motor Test
  MotorTest mt = MotorTest(m1, m2, "Motor Limit Tollerance Value", 0.0, 10.0, 30 * 1000);
  mt.run();
}



void loop() {
  // put your main code here, to run repeatedly:
  //TODO
}
