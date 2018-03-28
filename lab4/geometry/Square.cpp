//
// Created by jachfili on 21.03.18.
//

#include "Square.h"
namespace geometry {
    Square::Square() {
        a_ = Point();
        b_ = Point();
        c_ = Point();
        d_ = Point();
    }

    Square::Square(Point a, Point b, Point c, Point d) {
        a_ = a;
        b_ = b;
        c_ = c;
        d_ = d;

       if (not(a_.Distance(b_)==b_.Distance(d_) && a_.Distance(d) == b_.Distance(c_)))
       {
           a_ = Point();
           b_ = Point();
           c_ = Point();
           d_ = Point();
       }
    }

    Square::~Square()
    {

    }

    double Square::Circumference()
    {
        double dist = 4*a_.Distance(b_);
        return dist;
    }
    double Square::Area()
    {
        double area = a_.Distance(b_)*a_.Distance(b_);
        return area;
    }

}