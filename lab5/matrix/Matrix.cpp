//
// Created by filip on 02.04.18.
//


#include "Matrix.h"
using std::string;
using std::regex;
namespace algebra {

    std::complex<double> toComplex(const string &number) {
        string real = number.substr(0, number.find('i'));
        string imagine = number.substr(number.find('i') + 1, number.length());
        double real_number = std::stod(real);
        double imagine_number = std::stod(imagine);
        std::complex<double> value;
        value.real(real_number);
        value.imag(imagine_number);
        return value;


    }

    Matrix::Matrix() {
        n_rows_=0;
        n_cols_=0;
    }

    Matrix::~Matrix() {}

    Matrix::Matrix(std::string matlab) {

        n_rows_ = std::count(matlab.begin(), matlab.end(), ';') + 1;
        string row = matlab.substr(0, matlab.find(';'));
        n_cols_ = std::count(row.begin(), row.end(), ' ') + 1;

        for (int i = 0; i < n_rows_; i++) {
            matrix_.emplace_back(std::vector<std::complex<double>>());
            for (int j = 0; j < n_cols_; j++) {
                matrix_[i].push_back(std::complex<double>());
            }
        }

                regex pattern{R"([0-9]+i?[0-9]*)"};
                std::smatch match;
                string line = matlab.substr(1, matlab.length() - 2);
                while (std::regex_search(line, match, pattern)) {
                    int row = 0, col = 0;
                    for (auto v: match) {
                        string value = v.str();
                        matrix_[row].emplace_back(toComplex(value));
                        col++;
                        if (col > n_cols_ - 1) {
                            col = 0;
                            row++;
                        }

                    }
                    line = match.suffix().str();
                }


            }

            Matrix::Matrix(int rows, int cols) {
                if (rows < 1 || cols < 1) {
                    n_rows_ = 0;
                    n_cols_ = 0;
                    return;
                } else {
                    n_rows_ = rows;
                    n_cols_ = cols;

                    for (int i = 0; i < n_rows_; i++)
                    {
                        matrix_.emplace_back(std::vector<std::complex<double>>());
                        for (int j = 0; j < n_cols_; j++)
                        {
                            matrix_[i].push_back(std::complex<double>());
                        }
                    }
                }


            }

            Matrix::Matrix(std::initializer_list<std::vector<std::complex<double>>>  list)
            {


                n_rows_ = list.size();
                n_cols_ = (*list.begin()).size();
                if (n_rows_ < 1 || n_cols_ < 1) {
                    n_rows_ = 0;
                    n_cols_ = 0;
                    return;
                }
                for (int i = 0; i < n_rows_; i++)
                {
                    matrix_.emplace_back(std::vector<std::complex<double>>());
                    for (int j = 0; j < n_cols_; j++)
                    {
                        matrix_[i].push_back(std::complex<double>());
                    }
                }
                std::initializer_list<std::vector<std::complex<double>>>::iterator it;
                int i = 0;
                for (it = list.begin(); it!=list.end();it++ )
                {
                    for(int j = 0; j<n_cols_; j++)
                    {
                        matrix_[i][j]=(*it)[j];
                    }
                    i++;
                }
            }

            Matrix Matrix::Add(const Matrix &matrix) const {
                return Matrix();
            }

            Matrix Matrix::Sub(const Matrix &matrix) {
                return Matrix();
            }

            Matrix Matrix::Mul(const Matrix &matrix) {
                return Matrix();
            }


            Matrix Matrix::Pow(int power) {
                return Matrix();
            }

            std::pair<size_t,size_t> Matrix::Size() {
                return std::make_pair(n_rows_,n_cols_);
            }

            std::string Matrix::Print() const
            {
                if(n_rows_ == 0 || n_cols_ == 0 )
                {
                    return "[]";
                }
                string value = "[";
                for (int i =0; i<n_rows_;i++)
                {
                    for (int j=0; j<n_cols_;j++)
                    {



                    }
                }
            }

    void Matrix::set(int x, int y, std::complex<double> el) {
        matrix_[x][y] = el;
    }

    std::complex<double> Matrix::get(int x, int y) const {
        return matrix_[x][y];
    }
}


