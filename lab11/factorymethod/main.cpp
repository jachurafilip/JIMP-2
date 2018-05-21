//
// Created by filip on 22.05.18.
//
#include <iostream>
#include "FactoryMethod.h"
using namespace factoryMethod;
using std::cout;
int main()
{
    auto m = MyType();

    cout<<m.SayHello();
}


