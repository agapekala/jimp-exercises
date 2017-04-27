//
// Created by DELL on 20.04.2017.
//

#ifndef JIMP_EXERCISES_POINT3D_H
#define JIMP_EXERCISES_POINT3D_H

#include <iostream>
#include <ostream>
namespace point3d {
    class Point {
    public:
        Point();

        Point(double x, double y);

        virtual ~Point();

        void ToString(std::ostream *out) const;

        double Distance(const Point &other) const;


        double GetX() const;

        double GetY() const;


        void SetX(double x);

        void SetY(double y);

    private:
        double x_, y_;
    };

    class Point3D:public Point{
    public:
        Point3D();
        Point3D(double x_, double y_, double z);
        virtual ~Point3D();
        double Distance(const Point3D &other) const;
        double GetZ()const;
    private:
        double z_;
    };
    std::ostream &operator<<(std::ostream &out, Point &point);
}


#endif //JIMP_EXERCISES_POINT3D_H
