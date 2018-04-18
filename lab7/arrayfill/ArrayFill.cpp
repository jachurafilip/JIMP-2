//
// Created by jachfili on 18.04.18.
//

#include <bits/unique_ptr.h>
#include "ArrayFill.h"

namespace arrays
{

    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v)
    {
        v->clear();
        v->reserve(size);
        for (size_t i = 0; i < size; i++) {
            v->emplace_back(filler.Value(i));
        }
    }

    UniformFill::UniformFill(int number) {
        number_ = number;

    }

    int UniformFill::Value(int index) const {
        return number_;
    }

    IncrementalFill::IncrementalFill(int begin, int step) {
        begin_ = begin;
        step_ = step;

    }

    int IncrementalFill::Value(int index) const {
        return begin_+index*step_;
    }

    SquaredFill::SquaredFill(int a, int b)
    {
        a_=a;
        b_=b;
    }

    int SquaredFill::Value(int index) const {
        return a_*index*index +b_;
    }

    RandomFill::RandomFill(std::unique_ptr<std::default_random_engine> generator, std::unique_ptr<std::uniform_int_distribution<int>> distribution)
    {
        gen_ = std::move(generator);
        dist_ = std::move(distribution);

    }

    int RandomFill::Value(int index) const {
        auto v = (*dist_)(*gen_);
        return v;
    }
}
