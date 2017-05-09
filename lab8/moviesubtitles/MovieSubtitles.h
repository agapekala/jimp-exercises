//
// Created by DELL on 03.05.2017.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <string>
#include <memory>
#include <stdexcept>
#include <iostream>
#include <string>
#include <regex>
#include <sstream>

namespace moviesubs {
    class MovieSubtitles {
    public:
        virtual void ShiftAllSubtitlesBy(int m_seconds, int frames, std::stringstream *in, std::stringstream *out)=0;
    };

    //MicroDvd
    class MicroDvdSubtitles:public MovieSubtitles{
    public:
        MicroDvdSubtitles();
        ~MicroDvdSubtitles();
        void ShiftAllSubtitlesBy(int m_seconds, int frames, std::stringstream *in, std::stringstream *out) override ;
    };

    class NegativeFrameAfterShift{
    public:
        NegativeFrameAfterShift();
        ~NegativeFrameAfterShift();
    };

    class SubtitleEndBeforeStart:public std::runtime_error{
    public:
        SubtitleEndBeforeStart(std::string in, int line):runtime_error("At line "+std::to_string(line)+": "+SubstractLine(in, line)){
            line_=line;
        };
        int LineAt() const;
        std::string SubstractLine(std::string in, int line)const;
        ~SubtitleEndBeforeStart();
    private:
        int line_;
    };
    class InvalidSubtitleLineFormat{
    public:
        InvalidSubtitleLineFormat();
        ~InvalidSubtitleLineFormat();
    };

    class NegativeFrameRateThrowsIlegalArgument{
    public:
        NegativeFrameRateThrowsIlegalArgument();
        ~NegativeFrameRateThrowsIlegalArgument();
    };

    class MissingTimeSpecification{
    public:
        MissingTimeSpecification();
        ~MissingTimeSpecification();
    };

    class OutOfOrderFrames{
    public:
        OutOfOrderFrames();
        ~OutOfOrderFrames();
    };

    //Subrip
    class SubRipSubtitles:public MovieSubtitles{
    public:
        SubRipSubtitles();
        ~SubRipSubtitles();
        void ShiftAllSubtitlesBy(int m_seconds, int frames, std::stringstream *in, std::stringstream *out) override ;

    };

}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
