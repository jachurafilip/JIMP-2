//
// Created by filip on 02.04.18.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <string>
#include <complex>
#include <vector>
#include <algorithm>
#include <regex>
#include <sstream>

namespace algebra {
    class Matrix {
    public:
        Matrix();
        ~Matrix();

        Matrix(std::string matlab);
        Matrix(int rows, int cols);
        Matrix(std::initializer_list<std::vector<std::complex<double>>> list);

        Matrix Add(const Matrix &matrix)const;
        Matrix Sub(const Matrix &matrix);
        Matrix Mul(const Matrix &matrix);
        Matrix Mul(double number);
        Matrix Pow(int power);

        std::pair<size_t, size_t > Size();
        std::string Print() const;

        void set(int x, int y, std::complex<double> el);
        std::complex<double> get(int x, int y)const;

    private:
        int n_rows_;
        int n_cols_;
        std::vector<std::vector<std::complex<double>>> matrix_;




    };
}

#endif //JIMP_EXERCISES_MATRIX_H
