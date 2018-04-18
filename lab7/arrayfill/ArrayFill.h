//
// Created by jachfili on 18.04.18.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H



#include <vector>
#include <cstdlib>
#include <random>
namespace arrays {

    class ArrayFill {
    public:
        virtual int Value(int index) const =0;
    };
        void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v);

    class UniformFill: public ArrayFill
    {
    public:
        UniformFill(int number =0);
        int Value(int index) const override;

    private:
        int number_;
    };

    class IncrementalFill: public ArrayFill
    {
    public:
        IncrementalFill(int begin, int step=1);
        int Value(int index) const override ;

    private:
        int begin_,step_;
    };

    class SquaredFill: public ArrayFill
    {
    public:
        SquaredFill(int a=1, int b=0);
        int Value(int index) const override;

    private:
        int a_,b_;
    };
    class RandomFill:public ArrayFill {
    public:
        RandomFill(std::unique_ptr<std::default_random_engine> generator,
                   std::unique_ptr<std::uniform_int_distribution<int>> distribution);
        int Value(int index) const override;

    private:
        std::unique_ptr<std::default_random_engine> gen_;
        std::unique_ptr<std::uniform_int_distribution<int>> dist_;
    };






}

#endif //JIMP_EXERCISES_ARRAYFILL_H
