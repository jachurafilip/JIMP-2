//
// Created by filip on 21.04.18.
//

#include "IterableIterators.h"
namespace utility {

    ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left,
                                   std::vector<std::string>::const_iterator right,
                                   std::vector<int>::const_iterator left_end,
                                   std::vector<std::string>::const_iterator right_end) {

        left_ = left;
        right_ = right;

    }
    ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left,
                                   std::vector<std::string>::const_iterator right) {

        left_ = left;
        right_ = right;

    }

    std::pair<int, std::string> ZipperIterator::Dereference() const {
        return std::make_pair(*(left_), *(right_));
    }

    IterableIterator &ZipperIterator::Next() {
        left_++;
        right_++;
        return *this;
    }

    bool ZipperIterator::NotEquals(const std::unique_ptr<IterableIterator> &other) const {
        return (left_ != other->left_ || right_ != other->right_);

    }

}

