//
// Created by jachfili on 21.03.18.
//

#include "Point.h"

#include <cmath>
#include <iostream>
#include "Point.h"


using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using ::std::cout;

/* Aby wskazać, ze definicja funkcji dotyczy metody danej klasy
  stosujemy tzw. operator zasięgu - "::"
*/

//Specjalna inicjalizacja zmiennych. Zmienne są inicjowane
//nim zostanie wywołane ciało konstruktora
namespace geometry {
    Point::Point() : x_(0), y_(0) {
    }

    Point::Point(double x, double y) {
        x_ = x;
        y_ = y;
    }

    Point::~Point() {
    }

    double Point::Distance(const Point &other) const {
        return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2));
    }

    void Point::ToString(ostream *out) const {
        (*out) << "(" << GetX() << ";" << GetY() << ")";
    }
    double Point::GetX() const
    {
        return x_;
    }

    double Point::GetY() const {
        return y_;
    }

    void Point::SetX(double x)
    {
        x_ = x;
    }

    void Point::SetY(double y)
    {
        y_ = y;
    }
}