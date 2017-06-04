//
// Created by DELL on 18.05.2017.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <iostream>
namespace factoryMethod {

    class MyType{
    public:
        MyType();
        ~MyType();
        std::string SayHello();
    };
    template<class T>
    auto Create(){
        return T();
    }

}


#endif //JIMP_EXERCISES_FACTORYMETHOD_H
