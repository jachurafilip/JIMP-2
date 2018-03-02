#include <string>
#include "ReverseString.h"

std::string reverse(std::string str)
{
    char tmp;
    int lewy = 0;
    int prawy = str.size()-1;

    while(lewy<prawy)
    {
        tmp = str[lewy];
        str[lewy]=str[prawy];
        str[prawy]=tmp;
        lewy++;
        prawy--;
    }
    return str;
}


