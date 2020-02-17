#ifndef TESTMODE_H_
#define TESTMODE_H_

#include "time.h"
#include <Arduino.h>

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
        TestMode(String name, float initial_threshold, float final_threshold, long duration)
        {
            m_name = name;
            m_it = initial_threshold;
            m_ft = final_threshold;
            m_duration = duration;
        }

        // Action Control Functions
        virtual void init();
        virtual void run();
        virtual void stop();

        // Get the name of the test mode
        String getName()
        {
          return m_name;
        }

        float getInitialValue()
        {
          return m_it;
        }

        float getFinalValue()
        {
          return m_ft;
        }

        long getDuration()
        {
          return m_duration;
        }

        bool isRunning()
        {
          return m_running;
        }
    
    protected:
        String m_name;
        bool m_running = false;
        float m_it;
        float m_ft;
        long m_duration;
};

#endif