#ifndef MOTORTEST_H_
#define MOTORTEST_H_

#include "testmode.h"
#include "../../devices/AFMotorShieldV1.h"

#define MOVEMENT_STEPS_TEST 100
#define DELAY 50

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
        MotorTest(String name, float id, float fd, long duration) : TestMode(name, id, fd, duration)
        {
            // DO NOTHING
        }
};

#endif