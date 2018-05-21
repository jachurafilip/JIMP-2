//
// Created by filip on 22.05.18.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H


namespace factoryMethod
{
    template<class T>
    T Create()
    {
        return *new T();
    }

    class MyType
    {
    public:
        MyType()= default;
        const char* SayHello();
    };
}

#endif //JIMP_EXERCISES_FACTORYMETHOD_H
