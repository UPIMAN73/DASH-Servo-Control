enum STATE {
    OFF,
    RUNNING,
    FINISHED
};

class Command
{
    public:
        Command(String name, int id)
        {
            m_name = name;
            m_id = id;
            m_state = OFF;
        }

        String getName()
        {
            return m_name;
        }

        int getID()
        {
            return m_id;
        }

        STATE getState()
        {
            return m_state;
        }

        /*
         * These State functions are functions that must be overwritten in 
         * order for it to function properly.
         * 
         * 
         */
        virtual void start()
        {
            Serial.print("Starting Process ID ");
            Serial.println(m_id);
        }

        virtual void run()
        {
            Serial.print("Running Process ID ");
            Serial.println(m_id);
        }

        virtual void stop()
        {
            Serial.print("Stopping Process ID ");
            Serial.println(m_id);
        }
    
    private:
        STATE m_state;
        String m_name;
        int m_id;
};
