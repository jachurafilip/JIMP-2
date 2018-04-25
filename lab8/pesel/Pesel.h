//
// Created by jachfili on 25.04.18.
//
#include <string>
#include <stdexcept>
#include <regex>
#include <iostream>
#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

namespace academia {
    class Pesel {
    public:
        Pesel(std::string pesel);
        void Validate(const std::string &pesel);

    private:
        std::string pesel_;
    };

    class AcademiaDataValidationError: public std::runtime_error{

    public:
        AcademiaDataValidationError(const std::string &message);

    };

    class InvalidPeselLength: public AcademiaDataValidationError{
    public:
        InvalidPeselLength(const std::string &message);
        InvalidPeselLength(const std::string &message,int length);

    };

    class InvalidPeselChecksum: public AcademiaDataValidationError{

    public:
        InvalidPeselChecksum (const std::string &message);
        InvalidPeselChecksum(const std::string &message, int checksum);


    };
    class InvalidPeselCharacter: public AcademiaDataValidationError{

    public:
        InvalidPeselCharacter(const std::string &message);

    };





}


#endif //JIMP_EXERCISES_PESEL_H
