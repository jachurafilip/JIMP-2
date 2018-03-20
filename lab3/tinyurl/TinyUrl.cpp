//
// Created by filip on 20.03.18.
//

#include "TinyUrl.h"
#include <algorithm>

using std::string;
using std::array;
using std::unique_ptr;

namespace tinyurl
{

    const string alphabet_ = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    unique_ptr<TinyUrlCodec> Init()
    {
        TinyUrlCodec start;
        start.url="";
        for(int i=0;i<6;i++)
        {
            start.hash[i]='0';
        }
        auto p = std::make_unique<TinyUrlCodec>(start);
        return p;

    }
    void NextHash(array <char, 6> *state)
    {
        MoveHash(state,5);

    }
    void MoveHash(array<char,6> *state, int i)
    {
        if ((*state)[i]=='9')
        {
            (*state)[i]='A';
        }
        else if((*state)[i]=='Z')
        {
            (*state)[i]='a';
        }
        else if((*state)[i]=='z')
        {
            (*state)[i]='0';
            if(i>0) MoveHash(state, i-1);
        }
        else
        {
            (*state)[i]++;
        }
    }
    string Encode(const string &url, unique_ptr<TinyUrlCodec> *codec)
    {
        (*codec) -> url = url;
        array<char,6> hash = (*codec)->hash;
        string wynik;
        for (int i =0; i<6;i++)
        {
            wynik.push_back(hash[i]);
        }
        NextHash(&(*codec)->hash);

        return wynik;
    }
    string Decode(const unique_ptr<TinyUrlCodec> &codec, const string &hash)
    {
        string url = codec -> url;
        return url;
    }
}
