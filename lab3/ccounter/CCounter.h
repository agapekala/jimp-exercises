//
// Created by Maria on 16.03.2017.
//

#ifndef JIMP_EXERCISES_CCOUNTER_H
#define JIMP_EXERCISES_CCOUNTER_H

#include <iostream>
#include <string>
#include <memory>
#include <map>

namespace ccounter{
    void Inc(std::string key, std::unique_ptr<Counter>* counter);
    int Counts(const std::unique_ptr<Counter> &counter, std::string key);

}


#endif //JIMP_EXERCISES_CCOUNTER_H
