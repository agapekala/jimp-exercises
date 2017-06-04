//
// Created by DELL on 18.05.2017.
//

#include "FactoryMethod.h"

factoryMethod::MyType::MyType() {}

std::string factoryMethod::MyType::SayHello() {
    return "hello";
}

factoryMethod::MyType::~MyType() {}
