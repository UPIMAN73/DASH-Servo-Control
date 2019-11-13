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

        // TODO 
        // Needs to be done
    
    private:
        String m_name;
        int m_pin;
};
