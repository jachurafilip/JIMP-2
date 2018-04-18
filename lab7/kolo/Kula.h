//
// Created by jachfili on 18.04.18.
//
#include <Kolo.h>
#ifndef JIMP_EXERCISES_KULA_H
#define JIMP_EXERCISES_KULA_H

class Kula: public Kolo
{
public:
    Kula(double x, double y, double z, double r);
    virtual double Pole();

private:
    double z_;
};


#endif //JIMP_EXERCISES_KULA_H
