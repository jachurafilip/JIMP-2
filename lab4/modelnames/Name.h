//
// Created by jachfili on 21.03.18.
//

#ifndef JIMP_EXERCISES_MODELNAMES_H
#define JIMP_EXERCISES_MODELNAMES_H

#include <string>
#include <experimental/optional>

namespace model {

    using ::std::string;
    using ::std::stringstream;
    using ::std::experimental::optional;

    class Name {
    public:
        explicit Name(const string &first_names_surname);

        string FirstName() const;
        optional<string> SecondName() const;
        optional<string> ThirdName() const;
        string Surname() const;
        string ToFullInitials() const;
        string ToFirstNamesInitials() const;
        string ToSurnameNames() const;
        string ToNamesSurname() const;
        bool IsBeforeBySurname(const Name &other) const;
        bool IsBeforeByFirstName(const Name &other) const;

    private:
        string first_name_;
        string second_name_;

        string third_name_;
        string last_name_;
    };
}

#endif //JIMP_EXERCISES_MODELNAMES_H
