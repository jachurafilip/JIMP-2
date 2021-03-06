//
// Created by filip on 12.04.18.
//

#include "Counts.h"

namespace datastructures
{

    int Counts::get() const {
        return count_;
    }

    Counts::Counts()
    {
        count_=0;
    }

    Counts::Counts(int count) {
    count_ = count;
    }

    bool Counts::operator==(const Counts &other)const {
        if(count_==other.count_) return true;
        return false;
    }

    Counts &Counts::operator++() {
        count_++;
        return *this;
    }

    bool Counts::operator<(const Counts &other) const {
        if(count_<other.count_) return true;
        return false;
    }

    bool operator==(const int a, const Counts &b) {
        if(a==b.get()) return true;
        return false;
    }

    bool operator>(const Counts &a, const int b) {
        if(a.get()>b) return true;
        return false;
    }
}