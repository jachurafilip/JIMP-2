//
// Created by jachfili on 18.04.18.
//

#include "Kolo.h"

double Kolo::Pole() {
    return 3.14*r_*r_;
}

Kolo::Kolo(double x, double y, double r)
{
    x_=x;
    y_=y;
    r_=r;

}

Kolo::Kolo() {

}
