//
// Created by filip on 05.04.18.
//

#include "StudentRepository.h"
#include <iostream>
namespace academia {






    bool operator==(const StudentRepository &a, const StudentRepository &b) {
        if(a.StudentCount() != b.StudentCount())
            return false;
        bool flag;

            for (auto u: a.get())
            {
                flag = false;
                for(auto v: b.get())
                {
                    if (u.Id() == v.Id())
                        flag = true;
                }
            if(!flag) return false;
        }
        return true;
    }

    Student &StudentRepository::operator[](std::string id) {
        bool flag = true;
        int i = 0;

        while (i<student_.size() && flag)
        {
            if(student_[i].Id()==id)
            {
                flag = false;
                return student_[i];
            }
            i++;
        }

    }


    int StudentRepository::StudentCount() const {
        return student_.size();
    }

    StudentRepository::StudentRepository(const std::initializer_list<Student> &list) {
        for (auto v: list)
        {
            student_.push_back(v);
        }

    }

    std::vector<Student> StudentRepository::get() const {
        return student_;
    }

}
