//
// Created by DELL on 03.05.2017.
//

#include "MovieSubtitles.h"

using::moviesubs::MicroDvdSubtitles;

int main(){
    auto subs = std::make_unique<MicroDvdSubtitles>();
    std::stringstream in {"{0}{250}TEXT TEXT\n{260}{300}NEWLINE\n"};
    std::stringstream out;
    subs->ShiftAllSubtitlesBy(1400, 10, &in, &out);
}