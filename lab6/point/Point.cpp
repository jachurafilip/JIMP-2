#include "Point.h"
#include <iomanip>
#include <iostream>

using ::std::istream;
using ::std::ws;
using ::std::ostream;

//Helper functions:
void CheckNextChar(char c, istream* is) {
    int next_char = is->peek();
    if (next_char != c) {
        throw "error";
    }
    is->ignore();
}

void IgnoreWhitespace(istream* is) {
    (*is) >> ws;
}

double ReadNumber(istream* is) {
    double d;
    (*is) >> d;
    return d;
}
ostream& operator<<(ostream &os, Point& point)
{
    return os<<"("<<point.GetX()<<", "<<point.GetY()<<")";
}


istream& operator>>(istream & input, Point& p){
    CheckNextChar('(', &input);
    p.SetX(ReadNumber(&input));
    CheckNextChar(',', &input);
    IgnoreWhitespace(&input);
    p.SetY(ReadNumber(&input));
    CheckNextChar(')', &input);
    return input;      // Umożliwia cin >> a >> b >> c;
}


void Point::SetX(double x)
{
    x_ = x;

}

void Point::SetY(double y)
{
    y_ = y;
}

double Point::GetX()
{
    return x_;
}
double Point::GetY()
{
    return y_;
}

