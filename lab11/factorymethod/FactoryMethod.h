//
// Created by filip on 22.05.18.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H


#include <vector>
#include <numeric>
#include <iostream>
#include <sstream>

namespace factoryMethod
{
    template<typename T>
    T Create()
    {
        return T();
    }

    class MyType
    {
    public:
        const char* SayHello();
        const char* text = "hello";
    };

    template <typename T, typename T2>
    auto Add(T left, T2 right)
    {
        return left+right;
    }

    template <typename T>
    auto Value(const T & pointer)
    {
        return *pointer;
    }

    template <typename T>
    auto Mean(std::vector<T> vt)
    {
       auto sum =  std::accumulate(vt.begin(),vt.end(),0);
        return sum/vt.size();
    }

    enum LogLevel{Error,Warning,Info,Debug};

    template <typename T>
    class Logger
    {
    public:
        void Debug(const T &data)
        {
            if (level_>=LogLevel::Debug)
            {
                std::cout<<data;
            }
        }
        void Info(const T &data)
        {
            if(level_>=LogLevel::Info)
            {
                std::cout<<data;
            }
        }
        void Warning(const T &data)
        {
            if(level_>=LogLevel::Warning)
            {
                std::cout<<data;
            }
        }

        void Error(const T &data)
        {
            if(level_>=LogLevel::Error)
            {
                std::cout<<data;
            }
        }

        void SetLogLevel(LogLevel level)
        {
            level_ = level;
        }
    private:
        LogLevel level_;
    };



}

#endif //JIMP_EXERCISES_FACTORYMETHOD_H
