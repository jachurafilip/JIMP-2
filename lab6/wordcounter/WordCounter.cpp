//
// Created by filip on 12.04.18.
//

#include <set>
#include "WordCounter.h"

namespace datastructures
{

    WordCounter::WordCounter()
    {

    }

    WordCounter::WordCounter(std::initializer_list<Word> words)
    {

    }

    int WordCounter::DistinctWords() {
        return slowa_.size();
    }

    int WordCounter::TotalWords() {
        int output =0;
        for (auto v: slowa_)
        {
            output+=v.second.get();
        }

        return output;
    }

    std::set<Word> WordCounter::Words() {
        std::set<Word> output;
        for (auto v: slowa_)
        {
            output.emplace(v.first);
        }
        return output;

    }

    Counts WordCounter::operator[](std::string slowo) {
        return slowa_[slowo];
    }
}
