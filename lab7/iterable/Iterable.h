//
// Created by filip on 22.04.18.
//

#ifndef JIMP_EXERCISES_ITERATORS_H
#define JIMP_EXERCISES_ITERATORS_H

#include "IterableIteratorWrapper.h"
namespace utility {
    class Iterable {
    public:
        virtual std::unique_ptr<IterableIterator> ConstBegin() const =0;
        virtual std::unique_ptr<IterableIterator> ConstEnd() const =0;
        IterableIteratorWrapper cbegin() const;
        IterableIteratorWrapper cend() const;
        IterableIteratorWrapper begin() const;
        IterableIteratorWrapper end() const;

        ~Iterable() = default;

        std::pair <std::vector<int>,std::vector<std::string>> pair_;

    };

    class Zipper: public Iterable
    {
    public:
        Zipper(std::vector<int> vi, std::vector<std::string> vs);
        std::unique_ptr<IterableIterator> ConstBegin()const override;
        std::unique_ptr<IterableIterator> ConstEnd()const override;
    };
    class Enumerate: public Iterable
    {
    public:

        explicit Enumerate(std::vector<std::string> vs);
        std::unique_ptr<IterableIterator> ConstBegin() const override;
        std::unique_ptr<IterableIterator> ConstEnd()const override;

    };
    class Product: public Iterable
    {
    public:
        Product(std::vector<int> vi, std::vector<std::string> vs);
        virtual std::unique_ptr<IterableIterator> ConstBegin()const override;
        virtual std::unique_ptr<IterableIterator> ConstEnd() const override;

    };
}

#endif //JIMP_EXERCISES_ITERATORS_H
