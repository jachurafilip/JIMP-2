//
// Created by filip on 10.03.18.
//
#ifndef JIMP_EXERCISES_POLYBIUS_H
#define JIMP_EXERCISES_POLYBIUS_H

#include <map>
#include <string>
std::string PolybiusCrypt(std::string message);
std::string PolybiusDecrypt(std::string crypted);
void MakeMapCrypt(std::map<char, std::string> &szyfr);
void MakeMapDecrypt(std::map< std::string,char> &szyfr);
#endif //JIMP_EXERCISES_POLYBIUS_H
