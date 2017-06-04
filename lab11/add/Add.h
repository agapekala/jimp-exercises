//
// Created by DELL on 18.05.2017.
//

#ifndef JIMP_EXERCISES_ADD_H
#define JIMP_EXERCISES_ADD_H

#include <iostream>
#include <complex>
#include <memory>
template<class T>
T Add( const T &left, const T &right){
    return left+right;
}

template<class T>
auto Value(T pointer){
    return *pointer;
}

#endif //JIMP_EXERCISES_ADD_H
