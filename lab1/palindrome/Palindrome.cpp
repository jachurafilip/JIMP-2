#include <string>

#include "Palindrome.h"

bool IsPalindrome(std::string str)
{
    std::string copy = str;
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

    if(copy==str) return true;
    return false;
}