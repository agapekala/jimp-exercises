//
// Created by DELL on 07.04.2017.
//

#include "Point.h"

namespace test{
    Point::Point(){};
    Point::~Point() {};
    Point::Point(int x, int y) {
        x_=x;
        y_=y;
    }
    std::ostream &operator<<(std::ostream &out, Point &point){
        return out<<point.x_<<", "<<point.y_;
    }

    std::istream &operator>>(std::istream &in, Point &point) {
        in>>point.x_;
        in>>point.y_;
        return in;
    }

};