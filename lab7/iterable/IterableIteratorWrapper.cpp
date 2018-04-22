//
// Created by filip on 22.04.18.
//

#include "IterableIteratorWrapper.h"

namespace utility
{

    IterableIteratorWrapper::IterableIteratorWrapper(std::unique_ptr<IterableIterator> iterator)
    {
        iterator_ = move(iterator);
    }

    bool IterableIteratorWrapper::operator!=(const IterableIteratorWrapper &other) {
        return NotEquals(other.iterator_);
    }

    std::pair<int, std::string> IterableIteratorWrapper::operator*() {
        return Dereference();
    }

    IterableIteratorWrapper &IterableIteratorWrapper::operator++() {
        iterator_->Next();
        return *this;
    }
}
