#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::pair;
using std::literals::string_literals::operator""s;


class ZipperIterator {
public:
    pair<string,int> operator*() const; //wmagane w linii 74
    ZipperIterator &operator++(); //wymagane w linii 73 for(_;_;TU)
    bool operator!=(const ZipperIterator &other) const; //wymagane w linii 73 for(_;TU;_)
private:
    //TODO
};

//umożliwia przeglądanie dwóch wektorów na raz, w jednej pętli range-for
class Zipper {
public:
    static Zipper zip(const vector<string> &vs, const vector<int> &vi);

    ZipperIterator begin(); //wymagane w linii 73 for(TU;_;_)
    ZipperIterator end(); //wymagane w linii 73 for(_;TU;_)
private:
    //TODO
};



int main()
{
    vector<int> vi = {1,2,3};
    vector<string> vs = {"one"s,"two"s,"three"s};

    //PROSTY przykład
    for (const auto i : vi) {
        cout << i;
    }
    cout << endl;
    //to samo bez auto:
    for (const int i : vi) {
        cout << i;
    }
    cout << endl;
    //przetłumaczony powyższa petla mniej wiecej tak jak to kompilator
    //rozumie:
    for (vector<int>::iterator it = vi.begin(); it != vi.end(); ++it) {
        const int i = *it;
        cout << i;
    }
    cout << endl;

    //Przykład z zipperem
    for (const auto &p : Zipper::zip(vs,vi)) {
        cout << p.second << " is " << p.first;
    }
    cout << endl;
    //to samo bez auto:
    for (const pair<string,int> &p : Zipper::zip(vs,vi)) {
        cout << p.second << " is " << p.first;
    }
    cout << endl;

    //przetłumaczony powyższa petla mniej wiecej tak jak to kompilator
    //rozumie:
    Zipper tmp =  Zipper::zip(vs,vi);
    for (ZipperIterator it = tmp.begin(); it != tmp.end(); ++it) {
        const pair<string,int> &p = *it;
        cout << p.second << " is " << p.first;
    }
    cout << endl;
}