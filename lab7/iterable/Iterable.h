//
// Created by filip on 22.04.18.
//

#ifndef JIMP_EXERCISES_ITERATORS_H
#define JIMP_EXERCISES_ITERATORS_H

#include "IterableIteratorWrapper.h"
namespace utility {
    class Iterable {
    public:
        virtual std::unique_ptr<IterableIterator> ConstBegin()=0;
        virtual std::unique_ptr<IterableIterator> ConstEnd()=0;
        IterableIteratorWrapper cbegin() const;
        IterableIteratorWrapper cend() const;
        IterableIteratorWrapper begin() const;
        IterableIteratorWrapper end() const;

        std::pair <std::vector<int>,std::vector<std::string>> pair_;

    };

    class Zipper: public Iterable
    {
    public:
        virtual std::unique_ptr<IterableIterator> ConstBegin() override;
        virtual std::unique_ptr<IterableIterator> ConstEnd() override;
    };
    class Enumerate: public Iterable
    {
    public:
        virtual std::unique_ptr<IterableIterator> ConstBegin() override;
        virtual std::unique_ptr<IterableIterator> ConstEnd() override;

    };
    class Product: public Iterable
    {
    public:
        virtual std::unique_ptr<IterableIterator> ConstBegin() override;
        virtual std::unique_ptr<IterableIterator> ConstEnd() override;

    };
}

#endif //JIMP_EXERCISES_ITERATORS_H
