#ifndef LDRSYSTEM_H_
#define LDRSYSTEM_H_

#include "../devices/analogdevice.h"
#include "sensorsystem.h"

// Define LDR Pins
#define LDR_RT_PIN A0
#define LDR_LT_PIN A1
#define LDR_RB_PIN A2
#define LDR_LB_PIN A3


class LDRSystem : public SensorSystem
{

    public:
        LDRSystem(AnalogDevice ldr_rtC, AnalogDevice ldr_ltC, AnalogDevice ldr_rbC, AnalogDevice ldr_lbC, float tol, float thresh)
        {
            name = "Light Detecting Resistor System";
            ldr_rt = &ldr_rtC;
            ldr_rb = &ldr_rbC;
            ldr_lt = &ldr_ltC;
            ldr_lb = &ldr_lbC;
            local_tollerance = tol;
            threshold = thresh;
        }

        // Getting LDR Instances from class
        static AnalogDevice * getRightTop()    { return ldr_rt; }
        static AnalogDevice * getLeftTop()     { return ldr_lt; }
        static AnalogDevice * getLeftBottom()  { return ldr_lb; }
        static AnalogDevice * getRightBottom() { return ldr_rb; }

        // Getting LDR Values from class
        uint rightTop()     { return ldr_rt->getValue(); }
        uint rightBottom()  { return ldr_rb->getValue(); }
        uint leftTop()      { return ldr_lt->getValue(); }
        uint leftBottom()   { return ldr_lb->getValue(); }

        // Setting up the position needed to calculate for the motor system
        virtual ushort get();
        
    
    private:
        static AnalogDevice * ldr_rt;
        static AnalogDevice * ldr_lt;
        static AnalogDevice * ldr_lb;
        static AnalogDevice * ldr_rb;
        float local_tollerance = 0.0f;
        float threshold = 0.0f;
};

#endif