//
// Created by filip on 10.03.18.
//
#include <string>
#include <map>
#include <iostream>
#include "Polybius.h"
using namespace std;
string PolybiusCrypt(string message)
{
    map<char, string> szyfr;
    MakeMapCrypt(szyfr);
    string crypted;
    for (int i=0; i< message.length(); i++)
    {
        crypted+= szyfr[tolower(message[i])];
    }
    return crypted;




}

string PolybiusDecrypt(string crypted)
{
    map<string, char> szyfr;
    MakeMapDecrypt(szyfr);
    string message,index;
    for (int i=0; i<crypted.length()/2; i++)
    {
        index = crypted.substr(2*i,2);
        message += szyfr[index];
    }
    return message;
}

void MakeMapCrypt(map<char, string> &szyfr)
{
    szyfr['a']="11";
    szyfr['b']="12";
    szyfr['c']="13";
    szyfr['d']="14";
    szyfr['e']="15";
    szyfr['f']="21";
    szyfr['g']="22";
    szyfr['h']="23";
    szyfr['i']="24";
    szyfr['j']="24";
    szyfr['k']="25";
    szyfr['l']="31";
    szyfr['m']="32";
    szyfr['n']="33";
    szyfr['o']="34";
    szyfr['p']="35";
    szyfr['q']="41";
    szyfr['r']="42";
    szyfr['s']="43";
    szyfr['t']="44";
    szyfr['u']="45";
    szyfr['v']="51";
    szyfr['w']="52";
    szyfr['x']="53";
    szyfr['y']="54";
    szyfr['z']="55";
}

void MakeMapDecrypt(map<string,char > &szyfr)
{
    szyfr["11"]='a';
    szyfr["12"]='b';
    szyfr["13"]='c';
    szyfr["14"]='d';
    szyfr["15"]='e';
    szyfr["21"]='f';
    szyfr["22"]='g';
    szyfr["23"]='h';
    szyfr["24"]='i';
    szyfr["25"]='k';
    szyfr["31"]='l';
    szyfr["32"]='m';
    szyfr["33"]='n';
    szyfr["34"]='o';
    szyfr["35"]='p';
    szyfr["41"]='q';
    szyfr["42"]='r';
    szyfr["43"]='s';
    szyfr["44"]='t';
    szyfr["45"]='u';
    szyfr["51"]='v';
    szyfr["52"]='w';
    szyfr["53"]='x';
    szyfr["54"]='y';
    szyfr["55"]='z';
}