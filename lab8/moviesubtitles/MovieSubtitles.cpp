//
// Created by DELL on 03.05.2017.
//

#include "MovieSubtitles.h"

namespace moviesubs{
    MicroDvdSubtitles::MicroDvdSubtitles() {}
    MicroDvdSubtitles::~MicroDvdSubtitles() {}
    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int num1, int num2, std::stringstream *in, std::stringstream *out) {
        int frames = num1 * num2 / 1000;
        int left = 0;
        int right = 0;
        int left_brucket = 0, right_brucket = 0, ramki=0;
        int prev=0, enter_num=0;
        std::string helper = "";
        std::string in2 = "";
        std::string out2 = "";
        in2 = in->str();
        if (in2[in2.size() - 1] != '\n') {
            in2 += '\n';
        }
        if(num2<=0){
            throw std::invalid_argument("received negative value");
        }
        for(int j=0; j<in2.size(); j++){
            if(in2[j]=='{'){
                left_brucket++;
            }
            else if(in2[j]=='}'){
                right_brucket++;
            }
        }
        if(left_brucket!=right_brucket){
            throw InvalidSubtitleLineFormat();
        }
        for (int i = 0; i < in2.size(); i++) {
            if(in2[i]=='\n'){
                enter_num++;
            }
            if (in2[i] == '{') {
                left++;
                out2 += in2[i];
            } else if (in2[i] == '}') {
                right++;
                int digits = 0;
                for (int j = 0; j < helper.size(); j++) {
                    if (helper[j] >= 48 && helper[j] <= 57) {
                        digits++;
                    }
                }
                if (digits == helper.size()) {
                    if(helper==""){
                        throw InvalidSubtitleLineFormat();
                    }
                    ramki++;
                    int first_seconds = std::stoi(helper);

                    if(ramki==2*(enter_num+1) and prev>first_seconds){
                        throw SubtitleEndBeforeStart(in2, enter_num+1);
                    }
                    prev=first_seconds;
                    first_seconds = first_seconds + frames;
                    if (first_seconds < 0) {
                        throw NegativeFrameAfterShift();
                    }
                    std::string add = std::to_string(first_seconds);
                    out2 = out2 + add + "}";

                } else {
                    if(ramki%2!=0){
                        throw InvalidSubtitleLineFormat();
                    }
                    out2 = out2 + helper + "}";
                }
                helper = "";
            } else if (left > right && in2[i] != '{' && in2[i] != '}') {
                helper = helper + in2[i];
            } else if (in2[i] != '{' && in2[i] != '}') {
                out2 += in2[i];
            }
        }
        if(2*enter_num!=ramki){
            throw InvalidSubtitleLineFormat();
        }
        out->str(out2);
    }

    NegativeFrameAfterShift::NegativeFrameAfterShift() {}

    NegativeFrameAfterShift::~NegativeFrameAfterShift() {}

    SubtitleEndBeforeStart::~SubtitleEndBeforeStart() {}

    int SubtitleEndBeforeStart::LineAt() const {
        return line_;
    }

    std::string SubtitleEndBeforeStart::SubstractLine(std::string in, int line) const{
        std::string out_str="";
        int iter=0;
        if(in[0]=='{'){
            int first=line-1;
            for(int i=0; i<in.size(); i++){
                if(in[i]=='\n'){
                    iter++;
                }
                if(iter==first and in[i]!='\n'){
                    out_str+=in[i];
                }
            }
            return out_str;}
        else{
            std::regex Sub{R"((\d{2}):(\d{2}):(\d{2}),(\d{3}) --> (\d{2}):(\d{2}):(\d{2}),(\d{3}))"};
            int how_many_reg=0;
            for(int i=0; i<in.size(); i++){
                if (in[i]=='\n'){
                    iter++;
                }
            }
            int i=0;
            for(int j=0; j<iter; j++){
                std::string helper="";
                while(in[i]!='\n'){
                    helper=helper+in[i];
                    i++;
                }
                i++;
                std::smatch matches;
                if(regex_match(helper, matches, Sub)){
                    how_many_reg++;
                    if(how_many_reg==line){
                        return helper;
                    }}
            }}
    }

    InvalidSubtitleLineFormat::~InvalidSubtitleLineFormat() {}

    InvalidSubtitleLineFormat::InvalidSubtitleLineFormat() {}


    //Subrip
    SubRipSubtitles::SubRipSubtitles() {}

    SubRipSubtitles::~SubRipSubtitles() {}

    void SubRipSubtitles::ShiftAllSubtitlesBy(int m_seconds, int frames, std::stringstream *in, std::stringstream *out) {
        std::string helper="";
        std::string helper2="";
        int colon=0;
        std::string in2="";
        std::string out2="";
        std::string final1="";
        std::string final2="";
        int cols=0;
        std::regex Sub{R"((\d{2}):(\d{2}):(\d{2}),(\d{3}) --> (\d{2}):(\d{2}):(\d{2}),(\d{3}))"};
        int how_many_reg=0;
        in2=in->str();
        if(frames<0){
            throw std::invalid_argument("received negative value");
        }

        int lines=0;
        for(int i=0; i<in2.size(); i++){
            if (in2[i]=='\n'){
                lines++;
            }
        }
        int i=0;
        for(int j=0; j<lines; j++){
            helper="";
            int digits=0;
            while(in2[i]!='\n'){
                helper=helper+in2[i];
                if(in2[i]>=48 && in2[i]<=57){digits++;}
                i++;
            }
            i++;
            /*if(helper.size()==digits){
                int frames_number=stoi(helper);
                if(frames_number-how_many_reg>1){
                    throw OutOfOrderFrames();
                }
            }*/
            std::smatch matches;

            if(helper=="4"){
                throw OutOfOrderFrames();
            }
            if(helper[5]==':'){
                cols++;
                if(regex_match(helper, matches, Sub)){
                    how_many_reg++;
                    int first_seconds=stoi(matches[3]);
                    int first_miliseconds=stoi(matches[4]);
                    int first_minutes=stoi(matches[2]);
                    int second_seconds=stoi(matches[7]);
                    int second_miliseconds=stoi(matches[8]);
                    int second_minutes=stoi(matches[6]);
                    if(first_minutes>second_minutes || (first_minutes==second_minutes && first_seconds>second_seconds) || (first_minutes==second_minutes && first_seconds==second_seconds && first_miliseconds>second_miliseconds)){
                        throw SubtitleEndBeforeStart(in2, how_many_reg);
                    }
                    std::string first_miliseconds_string="";
                    std::string second_miliseconds_string="";
                    if((first_miliseconds+m_seconds)>1000){
                        first_miliseconds=first_miliseconds+m_seconds-1000;
                        first_seconds++;
                    }
                    else if((first_miliseconds+m_seconds)<0){
                        first_miliseconds=first_miliseconds+m_seconds;
                        int mili=first_miliseconds/1000;
                        if(mili>=0){
                            mili=mili*(-1);
                        }
                        first_seconds=first_seconds+mili;
                        if(first_seconds<0){
                            throw NegativeFrameAfterShift();
                        }
                        first_miliseconds=first_miliseconds-1000*mili;
                        if(first_miliseconds<0){
                            first_miliseconds=first_miliseconds*(-1);
                        }
                        first_seconds=first_seconds+mili;
                    }
                    else{
                        first_miliseconds=first_miliseconds+m_seconds;
                    }
                    std::string first_seconds_string=std::to_string(first_seconds);
                    if(first_seconds<10 && first_seconds>=0) {
                        first_seconds_string = '0'+std::to_string(first_seconds);
                    }

                    else{
                        first_seconds_string = std::to_string(first_seconds);
                    }
                    first_miliseconds_string=std::to_string(first_miliseconds);
                    if(first_miliseconds_string.size()==1){
                        first_miliseconds_string="00"+first_miliseconds_string;
                    }
                    if(first_miliseconds_string.size()==2){
                        first_miliseconds_string="0"+first_miliseconds_string;
                    }



                    if((second_miliseconds+m_seconds)>1000){
                        second_miliseconds=second_miliseconds+m_seconds-1000;
                        second_seconds++;
                    }
                    else if((second_miliseconds+m_seconds)<0){
                        second_miliseconds=second_miliseconds+m_seconds;
                        int mili=first_miliseconds/1000;
                        second_seconds=second_seconds-mili;
                        second_miliseconds=second_miliseconds+1000*mili;
                        if(second_miliseconds<0){
                            second_miliseconds=second_miliseconds*(-1);
                        }
                        second_seconds=second_seconds-mili;
                    }

                    else{
                        second_miliseconds=second_miliseconds+m_seconds;
                    }
                    std::string second_seconds_string=std::to_string(second_seconds);
                    if(second_seconds<10) {
                        second_seconds_string = '0'+std::to_string(second_seconds);
                    }
                    else{
                        second_seconds_string = std::to_string(second_seconds);
                    }
                    second_miliseconds_string=std::to_string(second_miliseconds);
                    if(second_miliseconds_string.size()==1){
                        second_miliseconds_string="00"+second_miliseconds_string;
                    }
                    else if(second_miliseconds_string.size()==2){
                        second_miliseconds_string='0'+second_miliseconds_string;
                    }

                    std::string matches1=matches[1];
                    std::string matches2=matches[2];
                    std::string matches5=matches[5];
                    std::string matches6=matches[6];

                    out2=out2+matches1+':'+matches2+':'+first_seconds_string+','+first_miliseconds_string+" --> "+matches5+':'+matches6+':'+second_seconds_string+','+second_miliseconds_string+"\n";
                }}
            else{
                out2=out2+helper+"\n";
            }
        }
        if(how_many_reg!=cols){
            throw InvalidSubtitleLineFormat();
        }


        out->str(out2);
    }


    NegativeFrameRateThrowsIlegalArgument::NegativeFrameRateThrowsIlegalArgument() {}

    NegativeFrameRateThrowsIlegalArgument::~NegativeFrameRateThrowsIlegalArgument() {}

    OutOfOrderFrames::OutOfOrderFrames() {}

    OutOfOrderFrames::~OutOfOrderFrames() {}

    MissingTimeSpecification::MissingTimeSpecification() {}

    MissingTimeSpecification::~MissingTimeSpecification() {}

}