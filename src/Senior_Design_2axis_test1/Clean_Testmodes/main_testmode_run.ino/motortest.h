#include "testmode.h"
#include "analogdevice.h"

#define MAX_LEN 500

/*
 * @author Joshua Calzadillas
 * @version November 11, 2019
 * 
 * @description 
 * 
 * 
 */ 

class MotorTest : public TestMode {
    public:
        // Add motors into the class
        MotorTest(double step, String name, double id, double fd, long duration) : TestMode(name, id, fd, duration)
        {
            m_step = step;
            m_trials = (int) ((fd - id) / step);
        }

        void setup()
        {
            Serial.println("Motor Test Mode");
            Serial.print("Running ");
            Serial.print(m_trials);
            Serial.println(" Trials");

            Serial.println("Setting up the data input array");
            delay(25);
            long darray[MAX_LEN];
            for (int i = 0; i < MAX_LEN; i++)
            {
                darray[i] = 0L;
            }
            Serial.println("Setup complete...");
            delay(500);


        }


        long getTrialData()
        {
          return trial_data;
        }

        int getTrials()
        {
          return m_trials;
        }

        double getSteps()
        {
          return m_step;
        }

        void setDataValue(long num)
        {
          trial_data = num;
        }
       
    private:
        double m_step;
        long trial_data;
        int m_trials;
};
