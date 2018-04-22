//
// Created by filip on 21.04.18.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H


#include <string>
#include <vector>
#include <memory>

namespace  utility {

    class IterableIterator {
    public:
        virtual ~IterableIterator() = default;

        virtual std::pair<int, std::string> Dereference()const=0;
        virtual IterableIterator &Next()=0;
        virtual bool NotEquals(const std::unique_ptr<IterableIterator> &other) const=0;

        std::vector<int>::const_iterator left_;
        std::vector<std::string>::const_iterator right_;
        std::vector<int>::const_iterator left_end_;
        std::vector<std::string>::const_iterator right_end_;

    };

    class ZipperIterator: public IterableIterator{
    public:
        explicit ZipperIterator(std::vector<int>::const_iterator left,
                                std::vector<std::string>::const_iterator right,
                                std::vector<int>::const_iterator left_end,
                                std::vector<std::string>::const_iterator right_end);
        ~ZipperIterator() override= default;

         std::pair<int, std::string> Dereference()const override;
         IterableIterator &Next() override;
         bool NotEquals(const std::unique_ptr<IterableIterator> &other)const override;


    };

}

#endif //JIMP_EXERCISES_ITERABLE_H
