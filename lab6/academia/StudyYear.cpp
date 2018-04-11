//
// Created by filip on 06.04.18.
//

#include "StudyYear.h"
namespace academia {
    int ReadNumber(std::istream* is) {
        int d;
        (*is) >> d;
        return d;
    }

    void CheckNextChar(char c, std::istream* is) {
        int next_char = is->peek();
        if (next_char != c) {
            throw std::runtime_error("invalid character");

        }
        is->ignore();
    }

    int StudyYear::getYear() const {
        return year_;
    }

    StudyYear::StudyYear() {
        year_ = 1;
    }

    StudyYear::StudyYear(int year) {
        year_ = year;
    }

    StudyYear &StudyYear::operator++() {
        year_++;
        return *this;
    }

    StudyYear &StudyYear::operator--() {
        year_--;
        if (year_ < 1) year_ = 1;
        return *this;
    }

    void StudyYear::setYear(int year) {

        year_ = year;

    }

    StudyYear::operator int() const {
        return year_;
    }


    bool operator<(const StudyYear &a, const StudyYear &b) {
        if (a.getYear() < b.getYear())
            return 1;
        return 0;
    }

    bool operator==(const StudyYear &a, const int b) {
        if (a.getYear() == b)
            return true;
        return false;
    }

    bool operator==(const int b, const StudyYear &a) {
        if (a.getYear() == b)
            return true;
        return false;
    }

    std::ostream& operator<<(std::ostream &os, const StudyYear &year) {
        int rok = year.getYear();
        return os<<rok;
    }

    std::istream &operator>>(std::istream &is, StudyYear &year) {
        year.setYear(ReadNumber(&is));
        return is;
    }
}