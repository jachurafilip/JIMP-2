//
// Created by filip on 06.04.18.
//

#ifndef JIMP_EXERCISES_STUDYYEAR_H
#define JIMP_EXERCISES_STUDYYEAR_H

namespace academia {

    class StudyYear{
    public:
        StudyYear();
        StudyYear(int year);
        int getYear() const;

        StudyYear &operator++();
        StudyYear &operator--();
    private:
        int year_;
    };

    bool operator<(const StudyYear &a, const StudyYear &b);
    bool operator==(const StudyYear &a, const int b);
    bool operator==(const int b, const StudyYear &a);
}

#endif //JIMP_EXERCISES_STUDYYEAR_H
