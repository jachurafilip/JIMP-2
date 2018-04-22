//
// Created by filip on 22.04.18.
//

#ifndef JIMP_EXERCISES_ITERABLEITERATORWRAPPER_H
#define JIMP_EXERCISES_ITERABLEITERATORWRAPPER_H

#include "IterableIterators.h"
namespace utility {
    class IterableIteratorWrapper {
    public:
        explicit IterableIteratorWrapper (std::unique_ptr<IterableIterator> iterator);
        bool operator!=(const IterableIteratorWrapper &other);
        std::pair<int, std::string> operator*();
        IterableIteratorWrapper &operator++();

    private:
        std::unique_ptr<IterableIterator> iterator_;
    };
}


#endif //JIMP_EXERCISES_ITERABLEITERATORWRAPPER_H
