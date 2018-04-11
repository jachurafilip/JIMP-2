#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "Zipper.h"
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::pair;
using std::literals::string_literals::operator""s;
using namespace datastructures;




int main()
{
    vector<int> vi = {1,2,3};
    vector<string> vs = {"one"s,"two"s,"three"s};

    Zipper tmp =  Zipper::zip(vs,vi);
    for (ZipperIterator it = tmp.begin(); it != tmp.end(); ++it)
    {
        const pair<string,int> &p = *it;
        cout << p.second << " is " << p.first<<endl;
    }
    return 0;
}