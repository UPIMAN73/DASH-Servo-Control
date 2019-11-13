#include "time.h"

/*
 * @author Joshua Calzadillas
 * @version November 10, 2019
 * 
 * @description 
 * 
 * 
 */ 

class TestMode
{
    public:
        /* Constructor */
        /*
         * Arguments: 
         * name : get the name of the test mode
         * initial_threshold : get the initial threshold value for the run loop
         * final_threshold : get the final final threshold value for the run loop
         * duration : how long you want the run loop to operate for
         */
        TestMode(String name, double initial_threshold, double final_threshold, long duration)
        {
            m_name = name;
            m_it = initial_threshold;
            m_ft = final_threshold;
            m_startT = ATime().currentTime();
            m_duration = duration;
        }

        virtual void run()
        {
            Serial.println("Test Mode Parent Function");
            Serial.println("Needs to be inherited in order to have it operate correctly.");
        } // Write your own run function

    
    protected:
        String m_name;
        double m_it;
        double m_ft;
        long m_startT;
        long m_endT;
        long m_duration;
};
