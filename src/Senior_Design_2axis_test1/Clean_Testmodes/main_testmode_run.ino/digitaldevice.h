/*
 * @author Joshua Calzadillas
 * @version November 12, 2019
 * 
 * @description 
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
}