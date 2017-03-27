//
// Created by DELL on 16.03.2017.
//

#include "CCounter.h"

namespace ccounter{

    struct Counter{
        std::map <char, int> v;
    };
    std::unique_ptr<Counter> Init();
    void Inc(std::string key, std::unique_ptr<Counter>* counter){
    }
    int Counts(const std::unique_ptr<Counter> &counter, std::string key);
    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter);
}