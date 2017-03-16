//
// Created by Maria on 13.03.2017.
//

#ifndef JIMP_EXERCISES_XORCYPHERBREAKER_H
#define JIMP_EXERCISES_XORCYPHERBREAKER_H


#include<iostream>
#include "XorCypherBreaker.h"
#include <string>
#include <vector>
#include <fstream>
#include<algorithm>


using std::find;
using std::vector;
using std::string;

std::string XorCypherBreaker(const std::vector<char> &cryptogram, int key_length, const std::vector<std::string> &dictionary);



#endif //JIMP_EXERCISES_XORCYPHERBREAKER_H
