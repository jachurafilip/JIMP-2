//
// Created by filip on 12.04.18.
//

#ifndef JIMP_EXERCISES_WORD_H
#define JIMP_EXERCISES_WORD_H

#include <string>
namespace datastructures {
    class Word {
    public:
    Word(std::string word);
    std::string Get()const;

    bool operator<(const Word other)const;
    bool operator==(const Word other)const;
    private:
        std::string slowo_;

    };
}

#endif //JIMP_EXERCISES_WORD_H
