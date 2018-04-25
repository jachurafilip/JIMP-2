//
// Created by jachfili on 18.04.18.
//

#include "Kula.h"

Kula::Kula(double x, double y, double z,double r):Kolo(x,y,r) {
    z_=z;
}

double Kula::Pole() {
    return 4*Kolo::Pole();

}
