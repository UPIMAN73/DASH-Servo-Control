#include "general.h"


long getCurrentTime() {
    return millis();
}

long getCurrentSeconds() {
    return millis() / 1000L;
}

float getAccurateSeconds() {
    return millis() / 1000.0f;
}

float getCurrentMinutes() {
    return getAccurateSeconds() / 60.0f;
}

float getCurrentHours() {
    return getCurrentMinutes() / 60.0f;
}


// Calculate Time Functions
long timeDelta(long tf, long ti)
{
    return tf - ti;
}

float timeDelta(float tf, float ti)
{
    return tf - ti;
}