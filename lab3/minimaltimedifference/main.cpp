//
// Created by DELL on 16.03.2017.
//
#include <iostream>
#include "MinimalTimeDifference.h"

int main(){
    std::string vec={"21:37"};
    std::cout<<minimaltimedifference::ToMinutes(vec);
    return 0;
}