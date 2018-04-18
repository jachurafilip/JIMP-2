#include "Kula.h"
#include "Kolo.h"
#include <iostream>

using namespace std;

int main(){
    Kula k(0,0,0,10);
    Kolo k2 = k;
    std::cout<<k2.Pole();
}