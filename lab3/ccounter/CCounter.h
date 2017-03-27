#include <string>
#include <memory>
#include <map>//
// Created by DELL on 16.03.2017.
//

#ifndef JIMP_EXERCISES_CCOUNTER_H
#define JIMP_EXERCISES_CCOUNTER_H

#include <iostream>
#include <string>
#include <memory>
#include <map>

namespace ccounter{
    struct Counter;
    std::unique_ptr<Counter> Init();
    void Inc(std::string key, std::unique_ptr<Counter>* counter);
    int Counts(const std::unique_ptr<Counter> &counter, std::string key);
    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter);
}

#endif //JIMP_EXERCISES_CCOUNTER_H
