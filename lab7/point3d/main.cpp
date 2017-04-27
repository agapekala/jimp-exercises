//
// Created by DELL on 20.04.2017.
//

#include "Point3D.h"
using::point3d::Point;
using::point3d::Point3D;
int main(){


    Point3D p1(3,5,7);
    /*
    Konstruktor parametrowy 2D - tworzy się obiekt bazowy typu Point
    Konstruktor param 3D - tworzony jest obiekt dziedziczący po klasie Point i jest wywoływany jego konstruktor
    Destruktor 3D - najpierw niszczony jest obiekt dziedziczący
    Destruktor 2D - na końcu jest niszczony obiekt bazowy
    */

    Point p2(1,1);
    /*
    Konstruktor parametrowy 2D
    Destruktor 2D
     */

    std::cout<<p2.Distance(p1)<<std::endl;
    /*
    Funkcja wywołuje się tylko z argumentami x i y, bo metoda Distance dla obiektów klasy Point wywołuje się tylko z 2 parametrami
     */
    std::cout<<p1;
    /*
     Wypisane zostaną tylko argumenty z obiektu bazowego(x i y), bo operator przyjmuje tylko argumenty typu Point
     */

    return 0;
}