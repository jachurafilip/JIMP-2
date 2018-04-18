//
// Created by filip on 06.04.18.
//
#include <string>
#include <vector>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#ifndef JIMP_EXERCISES_STUDYYEAR_H
#define JIMP_EXERCISES_STUDYYEAR_H

namespace academia {

    int ReadNumber(std::istream* is);
    void CheckNextChar(char c, std::istream* is);


    class StudyYear{
    public:
        StudyYear();
        StudyYear(int year);
        int getYear() const;
        void setYear(int year);

        StudyYear &operator++();
        StudyYear &operator--();

        operator int() const;

    private:
        int year_;
    };

    bool operator<(const StudyYear &a, const StudyYear &b);
    bool operator==(const StudyYear &a, const int b);
    bool operator==(const int b, const StudyYear &a);
    std::ostream &operator <<(std::ostream &os, const StudyYear &year);
    std::istream &operator>>(std::istream &is, StudyYear &year);
}

#endif //JIMP_EXERCISES_STUDYYEAR_H
