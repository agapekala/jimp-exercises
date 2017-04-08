//
// Created by DELL on 07.04.2017.
//
#include "Point.h"
using::test::Point;

int main(){
    Point point(10,10);
    std::cout<<point<<std::endl;
    std::cin>>point;
    std::cout<<point<<std::endl;
    std::stringstream s;
    s<<point;
    std::string napis=s.str();
    std::cout<<napis;
}