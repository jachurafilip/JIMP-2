//
// Created by filip on 12.04.18.
//
#include "Word.h"
#include "Counts.h"
#include <map>
#include <set>
#include <initializer_list>
#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

namespace datastructures {

    class WordCounter {
    public:
        WordCounter();
        WordCounter(std::initializer_list<Word> words);
        int DistinctWords();
        int TotalWords();
        std::set<Word>Words();

        Counts operator[](std::string slowo);

    private:
        std::map<Word, Counts> slowa_;

    };
}

#endif //JIMP_EXERCISES_WORDCOUNTER_H
