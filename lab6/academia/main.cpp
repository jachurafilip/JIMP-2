

#include <iostream>
#include "StudentRepository.h"
using namespace academia;
int main()
{
    StudentRepository repository
            {Student(), Student(), Student()};

    std::cin>>repository;
    std::cout<<repository;





}