//
// Created by filip on 12.04.18.
//

#include <iostream>
#include "WordCounter.h"

namespace datastructures {

    WordCounter::WordCounter() {

    }

    WordCounter::WordCounter(std::initializer_list<Word> words) {
        for (auto v: words) {
            slowa_[v] = 0;
        }
        for (auto v: words) {
            ++slowa_[v];
        }

    }

    int WordCounter::DistinctWords() {
        return slowa_.size();
    }

    int WordCounter::TotalWords() {
        int output = 0;
        for (auto v: slowa_) {
            output += v.second.get();
        }

        return output;
    }

    std::set<Word> WordCounter::Words() {
        std::set<Word> output;
        for (auto v: slowa_) {
            output.emplace(v.first);
        }
        return output;

    }

    bool less(WordCounter counter, const Word &w1, const Word &w2) {
        if (counter.slowa_[w1.Get()] < counter.slowa_[w2.Get()]) return true;
        return false;
    }

    Counts WordCounter::operator[](std::string slowo) {
        auto it = slowa_.find(slowo);
        if (it != slowa_.end()) {
            return it->second;
        } else {
            return Counts();
        }
    }


    std::ostream &operator<<(std::ostream &os, WordCounter &counter) {
        std::multimap<int, std::string> reverse = counter.flip();
        for (auto v = reverse.rbegin(); v != reverse.rend(); ++v) {
            os << v->second << "->" << v->first << std::endl;
        }
    }

    std::multimap<int, std::string> WordCounter::flip() {
        std::multimap<int, std::string> output;

        for (auto v: slowa_) {
            output.insert(std::pair<int, std::string>(v.second.get(), v.first.Get()));
        }
        return output;
    }


}
