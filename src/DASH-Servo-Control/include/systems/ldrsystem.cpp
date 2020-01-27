#include "ldrsystem.h"


virtual ushort LDRSystem::get()
{
    // getting analog input values
    uint ldrlt = ldr_lt->getValue();
    uint ldrrt = ldr_rt->getValue();
    uint ldrrb = ldr_rb->getValue();
    uint ldrlb = ldr_lb->getValue();

    // calculating averages
    float avt = (ldrlt + ldrrt) / 2; // average value up
    float avb = (ldrlb + ldrrb) / 2; // average value down
    float avl = (ldrlt + ldrlb) / 2; // average value left
    float avr = (ldrrt + ldrrb) / 2; // average value right

    // return no mouintvement
    if (avt < threshold && avb < threshold && avl < threshold && avr < threshold)
        return 0;

    // Move vertical motor upwards
    else if (avt > avb + local_tollerance)
        return 1;
    
    // move vertical motor downards
    else if (avb > avt + local_tollerance)
        return 2;
    
    // move horizontal motor to the left
    else if (avl > avr + local_tollerance)
            return 3;
    
    // move horizontal motor to the right
    else if (avr > avl + local_tollerance)
            return 4;

    else
    {
        // Return no movement
        return 0;
    }
}
