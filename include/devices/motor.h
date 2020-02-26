#ifndef MOTOR_H_
#define MOTOR_H_

/*
 * @author Joshua Calzadillas
 * @version November 11, 2019
 * 
 * @description 
 * Motor class stores information about the motors into a class.
 * 
 */ 
#include "general.h"

class Motor
{
    public:
        Motor(uint8 pin, String name)
        {
            m_name = name;
            m_pin = pin;
            //TODO Motor shield call
        }

        // Get teh pin
        uint8 getPin()
        {
          return m_pin;
        }

        // Get Name
        String getName()
        {
          return m_name;
        }

        // clean all of the values of the stored class
        virtual void clean()
        {
          m_name = "";
          m_pin = 0;
        }
    
    protected:
        String m_name;
        int m_pin;
};

#endif