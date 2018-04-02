//
// Created by filip on 02.04.18.
//

#include "TextPool.h"
namespace pool
{

    TextPool::TextPool() {}

    TextPool::TextPool(const std::initializer_list<std::experimental::string_view> &elements) {

        slowa_ = elements;

    }

    TextPool::TextPool(TextPool &&other) {
        std::swap(slowa_, other.slowa_);

    }

    TextPool &TextPool::operator=(TextPool &&other) {
        if(this == &other)
        {
            return *this;
        }
        std::swap(slowa_,other.slowa_);
        return *this;
    }

    TextPool::~TextPool() {}

    std::experimental::string_view TextPool::Intern(const std::string &str) {
        std::experimental::string_view text = str;
        auto address = slowa_.find(text);
        if(slowa_.count(text)==1)
            return address->begin();
        else
        {
            auto address = slowa_.emplace(text);
            return address.first->begin();
        }
    }

    size_t TextPool::StoredStringCount() const
    {
        return slowa_.size();
    }
}

