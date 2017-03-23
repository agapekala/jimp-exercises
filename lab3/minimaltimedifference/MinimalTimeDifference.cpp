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

        std::stringstream s1,s2;
        std::string str_hour, str_minutes;
        unsigned int minutes, hours, result;
        std::regex hour{R"((\d{1,2}):(\d{2}))"};
        std::smatch matches;
        if(regex_match(time_HH_MM, matches, hour)){
            //std::cout<< matches[0];
            str_minutes=matches[2];
            s1<<str_minutes;
            s1>>minutes;
            str_hour=matches[1];
            s2<<str_hour;
            s2>>hours;
            hours=hours*60;
        }
        result=hours+minutes;
        return result;

}

unsigned int MinimalTimeDifference(std::vector<std::string>times) {
    unsigned int minute_time;
    unsigned int shortest_time=1440;
    std::vector<unsigned int>minute_vector;
    for (std::string i:times ) {
        minute_time = minimaltimedifference::ToMinutes(i);
        minute_vector.push_back(minute_time);
    }
    for(unsigned int v: minute_vector){
        for(unsigned int w: minute_vector){
            unsigned int dif=abs(v-w);
            unsigned int fid=abs(w-v-1440);
            if (dif<fid){
                if(dif<shortest_time and dif!=0){
                    shortest_time=dif;
                }
            }
            else{
                if(fid<shortest_time and fid!=0){
                    shortest_time=fid;
                }
            }

        }
    }
    return shortest_time;
}
}

