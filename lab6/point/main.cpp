#include "Point.h"
#include <sstream>
using namespace std;
int main()
{

    Point punkt;
    cin>> punkt;
    cout<<punkt;
    std::stringstream ss;
    ss<<punkt;
    cout<<ss.str();
}