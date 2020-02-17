#ifndef ANALOGDEVICE_H_
#define ANALOGDEVICE_H_

#include <Arduino.h>

/*
 * @author Joshua Calzadillas
 * @version November 12, 2019
 * 
 * @description 
 * 
 * Analog Device are components that are connected
 * to the Arduino's analog pins.
 * 
 * 
 */ 

class AnalogDevice
{
    public:
        AnalogDevice(String name, int pin)
        {
            m_pin = pin;
            m_name = name;

            // NOTE if you need to use an analog pin for a digital device
            // then you have to make a wrapper class and add it yourself
        }

        virtual int getValue()
        {
            return analogRead(m_pin);
        }

        virtual void setValue(double val)
        {
            analogWrite(m_pin, val);
        }

        virtual String getName()
        {
            return m_name;
        }

        virtual int getPin()
        {
            return m_pin;
        }
    
    private:
        String m_name;
        int m_pin;
};

#endif