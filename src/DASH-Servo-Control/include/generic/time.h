#ifndef TIME_H_
#define TIME_H_

/*
 * @author Joshua Calzadillas
 * @version November 10, 2019
 * 
 * @description 
 * Basic Arduino Time Library which can take the millisecond -
 * input and convert that into seconds and minutes.
 * However, there is a major key component with this library.
 * The deltatime function and the current time function.
 * Delta time returns the change in time (in milliseconds) along with -
 * currentTime() which returns the current running time in miliseconds.
 * 
 */ 


#include <Arduino.h>

class ATime
{
    public:
        // Get the current Running time in Miliseconds
        long currentTime()
        {
            return millis();
        }

        // Convert the current time to seconds
        long getCurrentSeconds()
        {
            return millis() / 1000;
        }

        // get current timestamp in minutes
        long getCurrentMinutes()
        {
            return (millis() / 60000);
        }

        // Find the delta time between two time stamps
        long deltaTime(long ti, long tf)
        {
            return tf - ti;
        }
};


#endif