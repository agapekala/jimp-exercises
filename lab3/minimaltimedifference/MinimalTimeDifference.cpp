//
// Created by DELL on 16.03.2017.
//

#include "MinimalTimeDifference.h"
#include<iostream>
#include<vector>
#include<sstream>
#include<regex>
#include<cmath>

namespace minimaltimedifference{
    using ::std::stringstream;

    unsigned int ToMinutes(std::string time_HH_MM){

        std::stringstream s;
        int a;
        std::string str;
        unsigned int minutes;
        std::regex hour{"((\\d{2})\\:(\\d{2}))"};
        std::smatch matches;
        if(regex_match(time_HH_MM, matches, hour)){
            //std::cout<< matches[0];
            str=matches[0];
            s<<str;
            s>>minutes;
        }
        std::regex minute("(/:/d{2})");
        if(regex_match(time_HH_MM,matches, minute)){
            std::cout<< matches[0];
            //str=bez :

        }

        return minutes;

}
/*
void MinimalTimeDifference(std::vector<std::string>times) {
    for (int i; i < times.size(); i++) {
        int minute_time = minimaltimedifference::ToMinutes(times[i]);
    }

}
 */
}

