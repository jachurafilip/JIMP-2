//
// Created by filip on 12.04.18.
//

#ifndef JIMP_EXERCISES_COUNTS_H
#define JIMP_EXERCISES_COUNTS_H

namespace datastructures {
    class Counts {
    public:

        Counts();
        Counts(int count);
        int get() const;

        bool operator==(const Counts &other)const;
        bool operator<(const Counts &other)const;
        Counts &operator++();


    private:
        int count_;

    };


bool operator==(const int a, const Counts &b);
bool operator>(const Counts &a, const int  b);
}
#endif //JIMP_EXERCISES_COUNTS_H
