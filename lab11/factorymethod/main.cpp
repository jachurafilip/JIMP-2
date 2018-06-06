//
// Created by filip on 22.05.18.
//
#include <iostream>
#include <vector>
#include <memory>
#include "FactoryMethod.h"
using namespace factoryMethod;
using std::cout;
using std::endl;
int main()
{
    int a=2;
    double b=3.0;

    cout<<Add(a,b)<<endl;

    double* test = new double(3.6);
    double d = Value(test);
    std::vector<std::string> vs {"abc"};
    std::string s = Value(vs.begin());
    cout<<d<<endl<<s;

    std::string test2;
    auto ptr = std::make_unique<std::string>(test2);
    std::string result = Value(ptr);
    cout<<result;


    std::vector<int> vi{1,2,3,4};
    cout<<Mean(vi)<<endl<<endl;

    Logger log;
    log.SetLogLevel(LogLevel::Info);
    log.Debug("test");
    log.Warning("test2");

}


