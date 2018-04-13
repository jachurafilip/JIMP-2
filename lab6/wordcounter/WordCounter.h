//
// Created by filip on 12.04.18.
//
#include "Word.h"
#include "Counts.h"
#include <map>
#include <set>
#include <algorithm>
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

        std::set<Word> Words();


        Counts operator[](std::string slowo);


        std::multimap<int, std::string> flip();

        friend std::ostream &operator<<(std::ostream &os, WordCounter &counter);

        friend bool less(WordCounter counter, const Word &w1, const Word &w2);

    private:
        std::map<Word, Counts> slowa_;

    };

    std::ostream &operator<<(std::ostream &os, const WordCounter &counter);

    bool less(WordCounter counter, const Word &w1, const Word &w2);

}

#endif //JIMP_EXERCISES_WORDCOUNTER_H
