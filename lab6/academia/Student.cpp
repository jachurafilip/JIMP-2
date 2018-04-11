//
// Created by filip on 06.04.18.
//

#include "Student.h"

namespace academia {
    char ReadChar(std::istream *is) {
        char d;
        (*is) >> d;
        return d;
    }

    void checkString(std::string c, std::istream &is) {
        for (int i = 0; i < c.length(); i++) {
            CheckNextChar(c[i], &is);
        }

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

    void Student::ChangeYear(const StudyYear &year) {
        year_ = year;
    }

    std::istream &operator>>(std::istream &is, Student &student) {
        checkString("Student {id: \"", is);
        std::string id, first, last, program;
        char c;
        do {
            c = ReadChar(&is);
            id.push_back(c);
        } while (c > 47 && c < 58);
        id = id.substr(0, id.length() - 1);
        student.ChangeId(id);

        checkString(", first_name: \"", is);
        do {
            c = ReadChar(&is);
            first.push_back(c);
        } while (c > 64 && c < 123);
        first = first.substr(0, first.length() - 1);
        student.ChangeFirstName(first);

        checkString(", last_name: \"", is);
        do {
            c = ReadChar(&is);
            last.push_back(c);
        } while (c > 64 && c < 123);
        last = last.substr(0, last.length() - 1);
        student.ChangeLastName(last);

        checkString(", program: \"", is);
        do {
            c = ReadChar(&is);
            program.push_back(c);
        } while ((c > 64 && c < 123) || (c > 47 && c < 58));
        program = program.substr(0, program.length() - 1);
        student.ChangeProgram(program);

        checkString(", year: ", is);

        c = ReadChar(&is);
        int a = c - 48;
        student.ChangeYear(StudyYear{a});
        CheckNextChar('}', &is);


        return is;
    }


    bool operator==(const Student &a, const Student &b) {
        if (a.Id() == b.Id())
            return true;
        return false;
    }

    std::ostream &operator<<(std::ostream &os, const Student &student) {
        return os << "Student {id: \"" << student.Id() << "\", first_name: \"" << student.FirstName()
                  << "\", last_name: \"" << student.LastName() << "\", program: \"" << student.Program() << "\", year: "
                  << student.Year() << "}";
    }
}