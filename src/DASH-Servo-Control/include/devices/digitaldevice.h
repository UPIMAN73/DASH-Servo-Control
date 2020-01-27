#ifndef DIGITALDEVICE_H_
#define DIGITALDEVICE_H_

/*
 * @author Joshua Calzadillas
 * @version November 12, 2019
 * 
 * @description 
 * Digital Devices are all components that are connected to the digital pins
 * on the arduino.
 * 
 */ 

#include <Arduino.h>

class DigitalDevice
{
    public:
        DigitalDevice(String name, int pin, bool outmode)
        {
            m_pin = pin;
            m_name = name;
            m_mode = outmode;

            // GPIO Board setup
            if (outmode)
            {
                pinMode(pin, OUTPUT);
            }

            else
            {
                pinMode(pin, INPUT);
            }
            
        }

        virtual int getValue()
        {
            if (!m_mode)
                return digitalRead(m_pin);
            else
            {
                return -1;
                Serial.println("This device does not support Input mode");
            }
            
        }

        virtual void setValue(bool val)
        {
            if (m_mode)
                if (val)
                    digitalWrite(m_pin, HIGH);
                else
                    digitalWrite(m_pin, LOW);
            else
            {
                Serial.println("This device does not support Output mode");
            }
        }

        virtual String getName()
        {
            return m_name;
        }

        virtual int getPin()
        {
            return m_pin;
        }

        bool getMode()
        {
            return m_mode;
        }
    
    private:
        String m_name;
        int m_pin;
        bool m_mode;
};

#endif