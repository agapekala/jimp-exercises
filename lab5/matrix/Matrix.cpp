//
// Created by DELL on 03.04.2017.
//

#include "Matrix.h"
namespace algebra{
    Matrix::Matrix(){};
    Matrix::Matrix(int width, int height){
        size_.second=width;
        size_.first=height;

        vec_.resize(height);
        for(int i=0; i<height; i++){
            vec_[i].resize(width);
        }
    }

    Matrix::Matrix(const Matrix &new_matrix){
        size_=new_matrix.Size();
        vec_=new_matrix.vec_;
        }
    std::pair<size_t, size_t> Matrix::Size()const{
        return size_;
    }
    std::complex<double> Matrix::Get(int width, int height)const{
        return vec_[height][width];
    };

    void Matrix::Set(int width,int height, std::complex<double> value){
        vec_[height][width]=value;
    }

    Matrix Matrix::Add(const Matrix &m)const{
        if(size_.second!=m.size_.second|| size_.first!=m.size_.first){
            return Matrix(0,0);
        }
        Matrix new_m(size_.second, size_.first);
        size_t r = size_.first, c = size_.second;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                new_m.Set(j,i,vec_[i][j]+m.vec_[i][j]);
            }
        }
        return new_m;
    }

    Matrix Matrix::Sub(const Matrix &m)const{
        if(size_.second!=m.size_.second || size_.first!=m.size_.first){
            return Matrix(0,0);
        }
        Matrix new_m(size_.second, size_.first);
        for(int i=0; i<size_.first; i++){
            for(int j=0; j<size_.second; j++){
                new_m.Set(j,i,vec_[i][j]-m.vec_[i][j]);
            }
        }
        return new_m;
    }

    Matrix Matrix::Mul(const Matrix &m)const{
        if(size_.second!=m.size_.first){
            return Matrix(0,0);
        }
        else {
            Matrix new_m(m.size_.second, size_.first);
            std::complex<double> sum=0.;
            for (int i = 0; i < size_.first; i++) {
                for (int j = 0; j < m.size_.second; j++) {
                    for (int k=0; k < size_.second; k++) {
                        sum += (vec_[i][k] * m.vec_[k][j]);
                    }
                    new_m.Set(j, i, sum);
                    sum = 0.;
                }
            }
            return new_m;
        }
    }

    Matrix Matrix::Div(const Matrix &m)const{
        return Matrix();
    }

    Matrix Matrix::Pow(int pow){
        Matrix new_m(size_.second, size_.first);
        if(size_.second!=size_.first){
            return Matrix(0,0);
        }
        if(pow==1 ){
            return *this;
        }
        else if(pow==0){
            for(int i=0; i<size_.first; i++){
                new_m.Set(i,i, 1.);
            }
            return new_m;
        }
        else{

            if(pow==2){
                new_m=this->Mul(*this);
                return new_m;
            }
            new_m = *this;
            for(int i=1; i<pow; i++){
                new_m=new_m.Mul(*this);
            }
        }
        return new_m;
    }

    std::string Matrix::Print() const{
        if (vec_.size()==0) {
            return "[]";
        }
        std::string tmp="[";

        for(int i=0; i<this->size_.first; i++){
            for(int j = 0; j < this->size_.second; j++){
                std::stringstream tmp1;
                tmp1<<vec_[i][j].real();
                tmp+=tmp1.str();
                tmp+="i";
                std::stringstream tmp2;
                tmp2<<vec_[i][j].imag();
                tmp+=tmp2.str();
                tmp+=", ";
            }
            tmp.erase(tmp.size()-2, 2);
            tmp+="; ";
        }
        tmp.erase(tmp.size()-2, 2);
        tmp+="]";
        return tmp;
    }
    Matrix::~Matrix() {};
}
