//
// Created by DELL on 03.05.2017.
//

#include "MovieSubtitles.h"

namespace moviesubs{

    MicroDvdSubtitles::MicroDvdSubtitles(){}

    MicroDvdSubtitles::~MicroDvdSubtitles() {}

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int num1, int num2, std::stringstream *in, std::stringstream *out) {
        std::stringstream s;
        std::map<int, std::string> new_map;
        bool help=false;
        std::string str="",help_str;
        str=in->str();
        size_t size=str.size();
        for(int i=0; i<size; i++){
            if(str[i]=='{' and (str[i+1]>='0' or str[i+1]<='9')){
                help=true;
            }
            if(str[i]=='}' and str[i+1]!='{'){
                help=false;
            }
            if(help==true){
                help_str+=str[i];
            }
            if(help==false and help_str!=""){
                new_map.emplace(i-help_str.size(), help_str);
                help_str="";
            }
        }
        int change=((num1)/(1000/num2));

        for(auto &n:new_map) {
            std::string first_num="", second_num="";
            n.second.erase(0,1);
            int i=0;
            std::string tmp1=n.second;
            while(tmp1[i]!='}'){
                first_num+=tmp1[i];
                i++;
            }
            i+=2;

            while(tmp1[i]!='\0') {
                second_num += tmp1[i];
                i++;
            }
            double first, second;
            std::stringstream ss,s1,s2;
            ss << first_num;
            ss >> first;
            s2 << second_num;
            s2 >> second;

            std::string tmp="";
            first += change;
            second += change;
            s1 << '{' << first << '}' << '{' << second << '}';
            tmp=s1.str();
            int pos = n.first;
            int length = tmp.size();
            str.replace(pos, length, tmp);
        }
        std::cout<<str;
        //out->str(str);
    }
}