//
// Created by filip on 06.04.18.
//

#include "StudyYear.h"
namespace academia {
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
}