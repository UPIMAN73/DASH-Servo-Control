#include "digitaldevice.h"
#include "time.h"

// Relay define pins
#define RELAY_1_PIN 2
#define RELAY_2_PIN 3
#define DURATION 3

// Command string
String cmd;
bool r = 0, t = 0;


// setup the environment
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
  Serial.println("Begin sending commands");
  
}

DigitalDevice r1 = DigitalDevice("Relay 1", RELAY_1_PIN, true);
DigitalDevice r2 = DigitalDevice("Relay 2", RELAY_2_PIN, true);


// auto shutoff functionality
long initialTime = 0L;
long finalTime = 0L;

// loop code here for burn wire
void loop() {
  //Serial.println(analogRead(A0));
  finalTime = ATime().currentTime();

  // Auto Shutoff Functionality
  if ((ATime().deltaTime(initialTime, finalTime) >= DURATION * 1000) && (r || t))
  {
    Serial.println("Auto-Shutoff Engaged");
    r = false;
    t = false;
    r1.setValue(false);
    r2.setValue(false);
  }

  // Set the relay state
  // relay 1 turn on and off
  if (r)
  {
    r1.setValue(true);
  }

  // relay 2 turn on and off
  if (t)
  {
    r2.setValue(true);
  }

  if (!r)
    r1.setValue(false);
    
  if (!t)
    r2.setValue(false);

  
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
      cmd = "";
      cmd = Serial.readString();
      if (cmd.equals("r1\n"))
      {
        initialTime = ATime().currentTime();
        Serial.print("\nTurning on the device: ");
        Serial.println(r1.getName());
        r = (!r) ? true : false;
        Serial.println(r);
      }
      
      else if (cmd.equals("r2\n"))
      {
        initialTime = ATime().currentTime();
        Serial.print("\nTurning on the device: ");
        Serial.println(r2.getName());
        t = (!t) ? true : false;
        Serial.println(t);
      }

      else if (cmd.equals("both\n"))
      {
        initialTime = ATime().currentTime();
        Serial.print("\nTurning on the device: ");
        Serial.print(r1.getName());
        Serial.print("  and   ");
        Serial.println(r2.getName());
        t = (!t) ? true : false;
        r = (!r) ? true : false;
        Serial.println(r);
        Serial.println(t);
      }
   }
}
