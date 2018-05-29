//
// Created by filip on 30.05.18.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

    template <class T1, class T2>
    class SequentialIdGenerator {
    public:
        SequentialIdGenerator()
        {
            id_ = T2();
        }

        SequentialIdGenerator(T2 value)
        {
            id_=value;
        }

        T1 NextValue()
        {
            T1 object(id_);
            ++id_;
            return object;

        }

    private:
        T2 id_;
    };


#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
