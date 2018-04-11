

#include <iostream>
#include "StudentRepository.h"
using namespace academia;
int main()
{
    StudentRepository repository
            {{"20390", "Michał", "Karak", "architektura", 5}, {"2031", "Katarzyna", "Bach", "informatyka", 3},
             {"2035", "Orson", "Sabach", "górnictwo", 2}};

    std::cin>>repository;
    std::cout<<repository;





}