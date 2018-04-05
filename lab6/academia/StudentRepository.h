//
// Created by filip on 05.04.18.
//
#include <string>
#include <vector>
#include <initializer_list>
#include <tuple>
#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H


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

    class Student {
    public:
        Student();
        Student(std::string id, std::string first_name, std::string last_name, std::string program, StudyYear year);


        std::string Id()const;
        std::string FirstName()const;
        std::string LastName()const;
        std::string Program()const;
        int Year()const;

        void ChangeId(std::string id);
        void ChangeFirstName(std::string first_name);
        void ChangeLastName(std::string last_name);
        void ChangeProgram(std::string program);
        void ChangeYear(StudyYear year);



    private:
        std::string id_;
        std::string first_name_;
        std::string last_name_;
        std::string program_;
        StudyYear year_;



    };

    class StudentRepository
    {
    public:
        StudentRepository(const std::initializer_list<Student> &list);
        int StudentCount()const;
        std::vector<Student> get() const;
        Student operator [] (std::string id);

    private:
        std::vector<Student> student_;
    };

    bool operator==(const Student &a , const Student &b);
    bool operator<(const StudyYear &a, const StudyYear &b);
    bool operator==(const StudyYear &a, const int b);
    bool operator==(const int b, const StudyYear &a);
    bool operator==(const StudentRepository &a, const StudentRepository &b);


}
#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
