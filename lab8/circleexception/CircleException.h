//
// Created by DELL on 27.04.2017.
//

#ifndef JIMP_EXERCISES_CIRCLEEXCEPTION_H
#define JIMP_EXERCISES_CIRCLEEXCEPTION_H

#include <iostream>
using namespace std;

class CircleException{
    // Oznacza ze nie mozna wyrysowac kola
};

class BallException : public CircleException{
    // Oznacza ze nie mozna wyrysowac kuli
};

void drawBall();


#endif //JIMP_EXERCISES_CIRCLEEXCEPTION_H
