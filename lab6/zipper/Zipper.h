//
// Created by jachfili on 11.04.18.
//

#ifndef JIMP_EXERCISES_ZIPPER_H
#define JIMP_EXERCISES_ZIPPER_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>

namespace datastructures
{
    class ZipperIterator {
    public:
        ZipperIterator(std::vector<std::string>::iterator it1,std::vector<int>::iterator it2 );

        std::pair<std::string,int> operator*() const; //wmagane w linii 74
        ZipperIterator &operator++(); //wymagane w linii 73 for(_;_;TU)
        bool operator!=(const ZipperIterator &other) const; //wymagane w linii 73 for(_;TU;_)
    private:
        std::pair<std::vector<std::string>::iterator,std::vector<int>::iterator> it_;
    };
    
    //umożliwia przeglądanie dwóch wektorów na raz, w jednej pętli range-for
    class Zipper {
    public:
        static Zipper zip(const std::vector<std::string> &vs, const std::vector<int> &vi);
    
        ZipperIterator begin(); //wymagane w linii 73 for(TU;_;_)
        ZipperIterator end(); //wymagane w linii 73 for(_;TU;_)
    private:
        std::pair<std::vector<std::string>,std::vector<int>> pair_;
    };
}


#endif //JIMP_EXERCISES_ZIPPER_H
