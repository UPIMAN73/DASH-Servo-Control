#ifndef MOTORSYSTEMS_H_
#define MOTORSYSTEMS_H_

#include "devices/AFMotorShield.h"

class MotorSystems
{
    public:
        void constructSystem(AFMotorShield a, LDRSystem ldr);
    
    private:
        MotorSystems();

        StepperMotor * smvM;
        StepperMotor * smhM;
        AFMotorShield * AFM;
        LDRSystem * LDR;
};

#endif