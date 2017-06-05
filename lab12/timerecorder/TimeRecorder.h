//
// Created by DELL on 05.06.2017.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H
#include<iostream>
#include <chrono>
namespace profiling {


    template<class T>
    std::pair<T,double> TimeRecorder(T() ){
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
        T();
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::pair<T,double> pair_return=std::make_pair( T(),elapsed_seconds.count());
        return pair_return;
    };
}


#endif //JIMP_EXERCISES_TIMERECORDER_H
