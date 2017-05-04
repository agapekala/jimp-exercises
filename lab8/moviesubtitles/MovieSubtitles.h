//
// Created by DELL on 03.05.2017.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <iostream>
#include <regex>
#include <vector>

namespace moviesubs {
    class MicroDvdSubtitles {
    public:
        MicroDvdSubtitles();
        ~MicroDvdSubtitles();
        void ShiftAllSubtitlesBy(int num1, int num2, std::stringstream *in, std::stringstream *out);
    };
}


#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
