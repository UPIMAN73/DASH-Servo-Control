/*
 * @author Joshua Calzadillas
 * @version November 11, 2019
 * 
 * @description 
 * 
 * 
 */ 

/* TODO Include the libraries necessary setting up the class */

class Motor
{
    public:
        Motor(int pin, String name)
        {
            m_name = name;
            m_pin = pin;
            //TODO Motor shield call
        }

        int getPin()
        {
          return m_pin;
        }

        String getName()
        {
          return m_name;
        }

        //  clean all of the values of the stored class
        virtual void clean()
        {
          m_name = "";
          m_pin = 0;
        }

        // TODO 
        // Needs to be done
    
    protected:
        String m_name;
        int m_pin;
};
