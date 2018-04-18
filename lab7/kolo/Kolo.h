//
// Created by jachfili on 18.04.18.
//

#ifndef JIMP_EXERCISES_KOLO_H
#define JIMP_EXERCISES_KOLO_H


class Kolo {

public:
    Kolo();
    Kolo(double x, double y, double r);
    virtual double Pole();

protected:
    double x_,y_,r_;
};


#endif //JIMP_EXERCISES_KOLO_H
