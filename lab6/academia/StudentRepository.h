//
// Created by filip on 05.04.18.
//
#include <string>
#include <vector>
#include <initializer_list>

#include "Student.h"
#include "StudyYear.h"
#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H


namespace academia {





    class StudentRepository
    {
    public:
        StudentRepository(const std::initializer_list<Student> &list);
        int StudentCount()const;
        std::vector<Student> get() const;
        Student &operator [] (std::string id);

    private:
        std::vector<Student> student_;
    };



    bool operator==(const StudentRepository &a, const StudentRepository &b);
    std::ostream &operator<<(std::ostream &os, StudentRepository stdrep);


}
#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
