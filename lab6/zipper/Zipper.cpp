//
// Created by jachfili on 11.04.18.
//

#include "Zipper.h"

namespace datastructures
{

    std::pair<std::string, int> ZipperIterator::operator*() const {
        return std::make_pair(*(it_.first),*(it_.second));
    }

    ZipperIterator &ZipperIterator::operator++() {
        it_.first++;
        it_.second++;
        return *this;
    }

    bool ZipperIterator::operator!=(const ZipperIterator &other) const {
        if(it_.first!=other.it_.first || it_.second!=other.it_.second)
        {
            return false;
        }
        return true;
    }

    ZipperIterator::ZipperIterator(std::vector<std::string>::iterator it1, std::vector<int>::iterator it2)
    {
        it_ = std::make_pair(it1,it2);
    }

    Zipper Zipper::zip(const std::vector<std::string> &vs, const std::vector<int> &vi)
    {
        Zipper output = Zipper();
        output.pair_=std::make_pair(vs,vi);

        return output;
    }

    ZipperIterator Zipper::begin() {
        auto it1=pair_.first.begin();
        auto it2= pair_.second.begin();
        return ZipperIterator{it1,it2};
    }

    ZipperIterator Zipper::end() {
        auto it1=pair_.first.end();
        auto it2= pair_.second.end();
        return ZipperIterator{it1,it2};
    }
}