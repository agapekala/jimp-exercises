//
// Created by DELL on 03.04.2017.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <iostream>
#include <string>
#include <string.h>
#include <complex>
#include <vector>
#include<sstream>
#include <initializer_list>

namespace algebra {
    class Matrix {
    public:
        Matrix();
        Matrix(const std::initializer_list<std::vector<std::complex<double>>> &vec): vec_(vec){
            size_.second=vec_[0].size();
            size_.first=vec_.size();
        };
        Matrix(int width, int height);
        Matrix(const Matrix &new_matrix);
        std::complex<double> Get(int width, int height)const;
        void Set(int, int, std::complex<double>);
        std::pair<size_t, size_t> Size()const;
        Matrix Add(const Matrix &m)const;
        Matrix Sub(const Matrix &m)const;
        Matrix Mul(const Matrix &m)const;
        Matrix Div(const Matrix &m)const;
        Matrix Pow(int pow);
        std::string Print()const;
        ~Matrix();
    private:
        std::vector<std::vector<std::complex<double>>> vec_;
        std::pair<size_t, size_t> size_;
    };
}


#endif //JIMP_EXERCISES_MATRIX_H
