//
// Created by jachfili on 25.04.18.
//

#include "Pesel.h"
namespace academia
{

    Pesel::Pesel(std::string pesel) {

        Validate(pesel);
        pesel_ = pesel;

    }

    void Pesel::Validate(const std::string &pesel)
    {
        if(pesel.length()!=11)
        {
            throw InvalidPeselLength(pesel);
        }
        std::smatch sm;
        std::regex pattern (R"(\d{11})");
        if(!std::regex_match(pesel,sm,pattern))
        {
            throw InvalidPeselCharacter(pesel);
        }

        int numbers [11];
        for (int i=0; i<11; i++){
            numbers[i]=pesel[i]-'0';
        }
        int checksum=(9*numbers[0] + 7*numbers[1] + 3*numbers[2] + 1*numbers[3] + 9*numbers[4] + 7*numbers[5] + 3*numbers[6]
                      + 1*numbers[7] + 9*numbers[8] + 7*numbers[9])%10;
        if(checksum!=numbers[10]){
            throw InvalidPeselChecksum("Invalid PESEL("+pesel+ ") checksum: "+std::to_string(numbers[10]));
        }


    }

    AcademiaDataValidationError::AcademiaDataValidationError(const std::string &message) : std::runtime_error(message){};

    InvalidPeselCharacter::InvalidPeselCharacter(const std::string &message) : AcademiaDataValidationError("Invalid PESEL("+message+") character set"){};

    InvalidPeselLength::InvalidPeselLength(const std::string &message) : AcademiaDataValidationError(message){};

    InvalidPeselLength::InvalidPeselLength(const std::string &message, int length) : AcademiaDataValidationError("Invalid PESEL("+message+") length: "+std::to_string(length)){};


    InvalidPeselChecksum::InvalidPeselChecksum(const std::string &message, int checksum) : AcademiaDataValidationError("Invalid PESEL("+message+") checksum: "+std::to_string(checksum)){}

    InvalidPeselChecksum::InvalidPeselChecksum(const std::string &message) : AcademiaDataValidationError(message){}


};

