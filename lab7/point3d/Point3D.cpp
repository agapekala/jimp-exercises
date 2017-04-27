//
// Created by DELL on 20.04.2017.
//

#include "Point3D.h"
#include <cmath>
#include <ostream>
#include "Point3D.h"
namespace point3d {
    using ::std::ostream;
    using ::std::endl;
    using ::std::pow;
    using ::std::sqrt;


    Point::Point() : x_(0), y_(0) {
        std::cout << "Konstruktor bezparametrowy 2D" << endl;
    }

    Point::Point(double x, double y) {
        std::cout << "Konstruktor parametrowy 2D" << endl;
        x_ = x;
        y_ = y;
    }

    Point::~Point() {
        std::cout << "Destruktor 2D";
        std::cout << endl;
    }

    double Point::Distance(const Point &other) const {
        return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2));
    }

    void Point::ToString(ostream *out) const {
        (*out) << "(" << GetX() << ";" << GetY() << ")";
    }

    double Point::GetX() const {
        return x_;
    }

    double Point::GetY() const {
        return y_;
    }

    void Point::SetX(double x) {
        x_=x;
    }

    void Point::SetY(double y) {
        y_=y;
    }

    Point3D::Point3D() :z_(0){
        std::cout<<"Konstruktor bezparam 3D"<<endl;
    }

    double Point3D::Distance(const Point3D &other) const {
        return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2)+pow(GetZ()-other.GetZ(),2));
    }

    double Point3D::GetZ() const {
        return z_;
    }

    Point3D::Point3D(double x_, double y_, double z):Point(x_, y_) {
        z_=z;
        std::cout<<"Konstruktor param 3D"<<endl;
    }

    Point3D::~Point3D() {
        std::cout<<"Destruktor 3D"<<endl;
    }
    std::ostream &operator<<(std::ostream &out, Point &point){
        return out<<point.GetX()<<", "<<point.GetY();
    }
}