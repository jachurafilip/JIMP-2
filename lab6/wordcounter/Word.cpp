//
// Created by filip on 12.04.18.
//

#include "Word.h"


namespace datastructures
{

    Word::Word(std::string word) {
        slowo_ = word;
    }

    bool Word::operator<(const Word other)const  {
        if (slowo_< other.slowo_)
            return true;
        return false;
    }

    bool Word::operator==(const Word other) const {
        if(slowo_==other.slowo_) return true;
        return false;
    }

    std::string Word::Get()const {
        return slowo_;
    }
}
