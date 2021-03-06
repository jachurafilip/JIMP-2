//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int Factorial(int value)
{
    if(value>12 || value<-12)
    {
        return 0;
    }
    else if(value>=0 && value<13)
    {
        if (value < 2)
        {
            return 1;
        }
        return value * Factorial(value - 1);
    }
    else
    {
        if(value>-2)
        {
            return -1;
        }
        return value* Factorial(value + 1);
    }

}
