//
// Created by DELL on 07.04.2017.
//

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H

#include <iostream>
#include <sstream>
namespace test {
    class Point {
    public:
        Point();

        ~Point();

        Point(int x, int y);

        friend std::ostream &operator<<(std::ostream &out, Point &point);
        friend std::istream &operator>>(std::istream &in, Point &point);

    private:
        int x_;
        int y_;
    };
}