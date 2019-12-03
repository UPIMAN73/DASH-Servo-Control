#include "command.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);

  Command c("Test Command 1", 1);
  Serial.println(c.getName());
  Serial.println(c.getID());
  Serial.println(c.getState());

  // state functions
  c.start();
  c.run();
  c.stop();
}

void loop() {
  // put your main code here, to run repeatedly:

}
