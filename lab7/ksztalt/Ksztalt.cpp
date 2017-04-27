//
// Created by DELL on 27.04.2017.
//

#include "Ksztalt.h"

namespace ksztalt{

    Kolo::Kolo() {}

    Kolo::~Kolo() {}

    void Kolo::rysuj() {
        std::string str="";
        int i=3;
        while(i<=7){
            str="";
            for(int j=0; j<(7-i)/2; j++) {
                str = str + " ";
            }
            for(int j=0; j<i; j++){
                str= str + "x";
            }
            i=i+2;
            for(int j=0; j<(7-i)/2; j++) {
                str = str + " ";
            }
            std::cout<<str<<std::endl;
        }
        i=5;
        while(i>=3){
            str="";
            for(int j=0; j<(7-i)/2; j++) {
                str = str + " ";
            }
            for(int j=0; j<i; j++){
                str= str + "x";
            }
            i=i-2;
            for(int j=0; j<(7-i)/2; j++) {
                str = str + " ";
            }
            std::cout<<str<<std::endl;

        }
    };


    Trojkat::Trojkat() {}

    Trojkat::~Trojkat() {}

    void Trojkat::rysuj() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < i; j++) {
                std::cout << "x";
            }
            std::cout << std::endl;
        }
    }


    Kwadrat::Kwadrat() {

    }

    Kwadrat::~Kwadrat() {

    }

    void Kwadrat::rysuj() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 10; j++) {
                std::cout << "x";
            }
            std::cout << std::endl;
        }
    }
}