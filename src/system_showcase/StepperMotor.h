#include "motor.h"
#include <Wire.h>

class StepperMotor : public Motor
{
    //
    public:
        StepperMotor(String name, int pin, double steps) : Motor(pin, name)
        {
            m_steps = steps;
        }

        double getSteps()
        {
            return m_steps;
        }

        void clean()
        {
            m_pin = 0;
            m_name = "";
            m_steps = 0;   
        }
    
    private:
        double m_steps;
};
