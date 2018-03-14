//
// Created by filip on 13.03.18.
//
#include <vector>
#include <iostream>
#include "XorCypherBreaker.h"
using namespace std;
string XorCypherBreaker(const vector<char> &cryptogram,
                             int key_length,
                             const vector<string> &dictionary)
{

    for (unsigned char i = 'a'; i <= 'z'; i++)
    {
        for (unsigned char j = 'a'; j <= 'z'; j++)
        {
            for (unsigned char k = 'a'; k <= 'z'; k++)
            {
                unsigned char tab[]={i,j,k};
                if (Check(tab,cryptogram,dictionary))
                {
                    string wynik;
                    wynik.push_back(i);
                    wynik.push_back(j);
                    wynik.push_back(k);
                    return wynik;
                }

            }
        }
    }
    return "NONE";
}

bool Check(unsigned char kod[], const vector<char> &cryptogram, const vector<string> &dictionary)
{
    string cipher;
    for (auto v: cryptogram)
    {
        int i =0;
        cipher.push_back(v^(kod[i%3]));
        i++;
    }
    if(cipher.find("the")>-1)
    {
            return true;

    }
    return false;
}
