//
// Created by jachfili on 06.06.18.
//

#include "ArabicToRoman.h"
#include <string>
#include <stdexcept>
#include <cmath>
int value(char roman)
{
    switch(roman)
    {
        case 'I':return 1;
        case 'V':return 5;
        case 'X':return 10;
        case 'L':return 50;
        case 'C':return 100;
        case 'D':return 500;
        case 'M':return 1000;
        default:
            throw std::invalid_argument("");
    }
}

void validate(std::string roman)
{
    if(roman.find("CCCC")!=-1) throw std::invalid_argument("");
    if(roman.find("IIII")!=-1) throw std::invalid_argument("");
    if(roman.find("XXXX")!=-1) throw std::invalid_argument("");
    if(roman.find("LL")!=-1) throw std::invalid_argument("");
    if(roman.find("DD")!=-1) throw std::invalid_argument("");
    if(roman.find("VV")!=-1) throw std::invalid_argument("");
}


std::string ArabicToRoman(int arabic)
{

    if(arabic<1)
    {
        throw std::invalid_argument("");
    }

    std::string to_return;

    while(arabic)
    {


            if (arabic >= 1000) {
                to_return.push_back('M');
                arabic -= 1000;
            } else if (arabic >= 900) {
                to_return.push_back('C');
                to_return.push_back('M');
                arabic -= 900;
            } else if (arabic >= 500) {
                to_return.push_back('D');
                arabic -= 500;
            } else if (arabic >= 400) {
                to_return.push_back('C');
                to_return.push_back('D');
                arabic -= 400;
            } else if (arabic >= 100) {
                to_return.push_back('C');
                arabic-=100;
            } else if(arabic>=90)
            {
                to_return.push_back('X');
                to_return.push_back('C');
                arabic-=90;
            } else if (arabic >= 50) {
                to_return.push_back('L');
                arabic -= 50;
            } else if (arabic >= 40) {
                to_return.push_back('X');
                to_return.push_back('L');
                arabic -= 40;
            } else if (arabic >= 10) {
                to_return.push_back('X');
                arabic -= 10;
            } else if (arabic >= 9) {
                to_return.push_back('I');
                to_return.push_back('X');
                arabic-=9;
            } else if(arabic>=5)
            {
                to_return.push_back('V');
                arabic-=5;
            } else if(arabic>=4)
            {
                to_return.push_back('I');
                to_return.push_back('V');
                arabic-=4;
            } else
            {
                to_return.push_back('I');
                arabic--;
            }


    }

    return to_return;

}

int RomanToARrabic (std::string roman) {
    int to_return =0;
    char prev = '%';

    validate(roman);
    for (int i = roman.length() - 1; i != -1; i--) {
        if (value(roman[i]) < to_return && (roman[i] != prev)) {
            to_return -= value(roman[i]);
            prev = roman[i];
        } else {
            to_return += value(roman[i]);
            prev = roman[i];
        }

    }
    return to_return;
}

