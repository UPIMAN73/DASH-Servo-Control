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


#include <Arduino.h>

class Motor
{
    public:
        Motor(uint8_t pin, String name)
        {
            m_name = name;
            m_pin = pin;
            //TODO Motor shield call
        }

        uint8_t getPin()
        {
          return m_pin;
        }

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