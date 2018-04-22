//
// Created by filip on 22.04.18.
//

#include "Iterable.h"

namespace utility {
   Zipper::Zipper(std::vector<int> vi, std::vector<std::string> vs) {
       if (vi.size()>vs.size()){
           for (auto i=vs.size(); i<vi.size(); ++i){
               vs.emplace_back(vs.back());
           }
       }else{
           for (auto i = vi.size(); i < vs.size(); ++i) {
               vi.emplace_back(vi.back());
           }
       }
       pair_ = std::make_pair(vi,vs);

    }

    std::unique_ptr<IterableIterator> Zipper::ConstBegin()const {
        auto zip = ZipperIterator(pair_.first.begin(),pair_.second.begin());

        return std::make_unique<ZipperIterator>(zip);

    }

    std::unique_ptr<IterableIterator> Zipper::ConstEnd()const {
        auto zip = ZipperIterator(pair_.first.end(),pair_.second.end());

        return std::make_unique<ZipperIterator>(zip);
    }

    IterableIteratorWrapper Iterable::begin() const {
        return IterableIteratorWrapper{ConstBegin()};
    }

    IterableIteratorWrapper Iterable::end() const {
        return IterableIteratorWrapper{ConstEnd()};
    }

    Enumerate::Enumerate(std::vector<std::string> vs) {
       auto vi = std::vector<int>();
       for(int i=0; i<vs.size();i++)
       {
           vi.push_back(i+1);
       }
       pair_ = std::make_pair(vi,vs);


    }

    std::unique_ptr<IterableIterator> Enumerate::ConstBegin() const {
        auto zip = ZipperIterator(pair_.first.begin(),pair_.second.begin());

        return std::make_unique<ZipperIterator>(zip);
    }

    std::unique_ptr<IterableIterator> Enumerate::ConstEnd() const {
        auto zip = ZipperIterator(pair_.first.end(),pair_.second.end());

        return std::make_unique<ZipperIterator>(zip);
    }

    Product::Product(std::vector<int> vi, std::vector<std::string> vs)
    {
        auto vi_ = std::vector<int>();
        auto vs_ = std::vector<std::string>();

        for (auto v: vi)
        {
            for (auto u: vs)
            {
                vi_.emplace_back(v);
                vs_.emplace_back(u);
            }
        }

        pair_ = std::make_pair(vi_,vs_);

    }

    std::unique_ptr<IterableIterator> Product::ConstBegin() const {
        auto zip = ZipperIterator(pair_.first.begin(),pair_.second.begin());

        return std::make_unique<ZipperIterator>(zip);
    }

    std::unique_ptr<IterableIterator> Product::ConstEnd() const {
        auto zip = ZipperIterator(pair_.first.end(),pair_.second.end());

        return std::make_unique<ZipperIterator>(zip);
    }
}
