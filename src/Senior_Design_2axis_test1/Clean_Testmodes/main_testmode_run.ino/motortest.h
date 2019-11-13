#include "testmode.h"
#include "motor.h"

/*
 * @author Joshua Calzadillas
 * @version November 11, 2019
 * 
 * @description 
 * 
 * 
 */ 

class MotorTest : public TestMode {
    public:
        // Add motors into the class
        MotorTest(Motor motor1, Motor motor2, String name, double id, double fd, long duration) : TestMode(name, id, fd, duration)
        {
          m1 = motor1;
          m2 = motor2;
        }

        // TODO
        void run()
        {
            Serial.println("Motor Test Mode");
            //TODO
        }
    
    private:
        Motor m1 = Motor(-1, "");
        Motor m2 = Motor(-1, "");
};
