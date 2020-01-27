#ifndef SENSORSYSTEM_H_
#define SENSORSYSTEM_H_

#include <Arduino.h>
#define uint unsigned int
#define ushort unsigned short

class SensorSystem
{
    protected:
    String name;

    public:

    virtual ushort get();  // get direct sensor information 
};

#endif