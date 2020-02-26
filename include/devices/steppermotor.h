#ifndef STEPPERMOTOR_H_
#define STEPPERMOTOR_H_

/*
 * @author Joshua Calzadillas
 * @version November 11, 2019
 * 
 * @description 
 * SM class stores information about the stepper motors into a class.
 */ 


#include "motor.h"

class SM : public Motor
{
    //
    public:
        SM();

        SM(String name, uint8_t pin, uint16_t steps) : Motor(pin, name)
        {
            m_steps = steps;
        }

        uint16_t getSteps()
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
        uint16_t m_steps;
};

#endif