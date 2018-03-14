//
// Created by filip on 13.03.18.
//

#ifndef JIMP_EXERCISES_XORCYPHERBREAKER_H
#define JIMP_EXERCISES_XORCYPHERBREAKER_H


std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector <std::string> &dictionary);
bool Check(unsigned char kod[], const std::vector<char> &cryptogram, const std::vector<std::string> &dictionary);

#endif //JIMP_EXERCISES_XORCYPHERBREAKER_H
