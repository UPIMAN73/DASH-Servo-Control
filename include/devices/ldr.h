#ifndef LDR_H_
#define LDR_H_

#include "analog.h"

class LDR : public AnalogDevice
{
    public:
        LDR();
        LDR(String name, uint8 pin);
        ~LDR();

        void clean();

        // Getters
        String getName();
    
    private:
        String m_name;
};

#endif