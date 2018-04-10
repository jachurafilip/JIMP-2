

#include <iostream>
#include "StudentRepository.h"
using namespace academia;
int main()
{
    StudyYear year = StudyYear{2};
    std::cin>>year;
    std::cout<<year<<std::endl;

    int rok = year;
    std::cout<<rok;
}