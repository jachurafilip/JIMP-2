//
// Created by jachfili on 21.03.18.
//

#include "Name.h"

using std::string;
using ::std::experimental::optional;
using ::std::experimental::make_optional;

namespace model
{

    Name::Name(const string &first_names_surname) {

    }

    string Name::FirstName() const {
        return first_name_;
    }

    optional<string> Name::SecondName() const {
        if(second_name_.size()==0)
        {
        }
        else
        {
            return make_optional(second_name_);
        }
    }

    optional<string> Name::ThirdName() const {
       if(third_name_.size()==0)
       {
       }
        else
       {
           return make_optional(third_name_);
       }
    }

    string Name::Surname() const {
        return last_name_;
    }

    string Name::ToFullInitials() const {
        return std::__cxx11::string();
    }

    string Name::ToFirstNamesInitials() const {
        return std::__cxx11::string();
    }

    string Name::ToSurnameNames() const {
        return std::__cxx11::string();
    }

    string Name::ToNamesSurname() const {
        return std::__cxx11::string();
    }

    bool Name::IsBeforeBySurname(const Name &other) const {
        return false;
    }

    bool Name::IsBeforeByFirstName(const Name &other) const {
        return false;
    }
}
