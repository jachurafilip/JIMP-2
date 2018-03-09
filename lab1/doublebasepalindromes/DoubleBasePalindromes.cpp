//
// Created by filip on 06.03.18.
//
#include <cstdint>
#include <string>

#include "DoubleBasePalindromes.h"

using namespace std;
uint64_t DoubleBasePalindromes(int max_value_exculsive)
{
    if (max_value_exculsive<1) return 0;
    uint64_t suma =0;
    for (int i = 1; i < max_value_exculsive; i += 2) //liczba parzysta nie moze byc palindromem
    {
        string str = to_string(i);

        if(IsPalindrome(str))
        {
            string binary = DecToBin(i);
            if(IsPalindrome(binary)) suma+=i;
        }

    }
    return suma;
}

string DecToBin(int number)
{
    if ( number == 0 ) return "0";
    if ( number == 1 ) return "1";

    if ( number % 2 == 0 )
        return DecToBin(number / 2) + "0";
    else
        return DecToBin(number / 2) + "1";

}