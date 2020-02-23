#ifndef MOTORSYS_H_
#define MOTORSYS_H_

#include "general.h"
#include "devices/ldr.h"
// #include "AFMV1.h"


class MotorSys
{
    public:
        MotorSys();
        MotorSys(uint8 prt, uint8 prb, uint8 plt, uint8 plb, uint16 t);
        ~MotorSys();

        void run();     // Run Function for Motor System
        bool getInit(); // Get Initialized Function 

    private:
        bool init = false;
        LDR ldrt;
        LDR ldrb;
        LDR ldlt;
        LDR ldlb;

        uint16 threshold = 0; // Threshold that will allow movment of motors

        // Values of LDR so that we don't have to redefine them and save memory
        uint16 ldrtv = 0;
        uint16 ldrbv = 0;
        uint16 ldltv = 0;
        uint16 ldlbv = 0;

        uint16 topval = ldrtv + ldltv;
        uint16 botval = ldrbv + ldlbv;
        uint16 rightval = ldrtv + ldrbv;
        uint16 leftval = ldltv + ldlbv;
};

#endif