//
// Created by filip on 05.04.18.
//

#include "StudentRepository.h"

using std::tuple;
namespace academia {

    int StudyYear::getYear() const {
        return year_;
    }

    StudyYear::StudyYear() {
    year_ =1;
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
        if(year_<1) year_ = 1;
        return *this;
    }


    Student::Student() {}

    Student::Student(std::string id, std::string first_name, std::string last_name, std::string program,
                     StudyYear year) {
        id_ = id;
        first_name_ = first_name;
        last_name_ = last_name;
        program_ = program;
        year_ = year.getYear();
    }

    std::string Student::Id() const {
        return id_;
    }

    std::string Student::FirstName() const {
        return first_name_;
    }

    std::string Student::LastName() const {
        return last_name_;
    }

    std::string Student::Program() const {
        return program_;
    }

    int Student::Year() const {
        return year_.getYear();
    }


    void Student::ChangeId(std::string id) {
        id_ = id;
    }

    void Student::ChangeFirstName(std::string first_name) {
        first_name_ = first_name;
    }

    void Student::ChangeLastName(std::string last_name) {
        last_name_ = last_name;
    }

    void Student::ChangeProgram(std::string program) {
        program_ = program;
    }

    void Student::ChangeYear(StudyYear year) {
        year_ = year;
    }




    bool operator==(const Student &a, const Student &b) {
        if (a.Id() == b.Id())
            return true;
        return false;
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

    bool operator==(const StudentRepository &a, const StudentRepository &b) {
        if(a.StudentCount() != b.StudentCount())
            return false;
        for(auto v: a.get())
        { int i =0;
            //todo
        }

    }

    Student StudentRepository::operator[](std::string id) {
        for(auto v: get())
        {
            if(v.Id()==id)
                return v;
        }
        return Student();
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
