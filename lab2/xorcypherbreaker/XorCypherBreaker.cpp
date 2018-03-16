//
// Created by filip on 13.03.18.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include "XorCypherBreaker.h"
using namespace std;
string XorCypherBreaker(const vector<char> &cryptogram,
                             int key_length,
                             const vector<string> &dictionary)
{
    string klucz;
    int max = 0;
    int count = 0;
    pair <int, string> para;
    for (char i = 'a'; i<='z';i++)
    {
        for (char j = 'a'; j<='z';j++)
        {
            for (char k = 'a'; k<='z';k++)
            {
                klucz = "";
                klucz.push_back(i);
                klucz.push_back(j);
                klucz.push_back(k);
                count = Check(klucz,cryptogram,dictionary);
                if(count>max)
                {
                    max = count;
                    para = {count,klucz};
                }
            }
        }
    }
    return para.second;
}

int Check(string kod, const vector<char> &cryptogram, const vector<string> &dictionary)
{
    string slowo;
    char znak;
    int i = 0, slowa = 0;
    for(auto v: cryptogram)
    {
        znak = v^kod[i%kod.size()];
        i++;
        if (znak == 32)
        {
            if(find(dictionary.begin(),dictionary.end(),slowo) != dictionary.end())
            {
                slowa++;
            }
            slowo = "";
        }
        else
        {
            slowo.push_back(znak);
        }
    }
    return slowa;
}

