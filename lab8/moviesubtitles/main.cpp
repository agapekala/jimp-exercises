//
// Created by DELL on 03.05.2017.
//

#include "MovieSubtitles.h"

using::moviesubs::MicroDvdSubtitles;

int main(){
    auto subs = std::make_unique<MicroDvdSubtitles>();
    std::stringstream in {"{0}{100}{y:b}bold text\n{144}{299}{s:12}12 Font used\n{280}{350}{c:$0000FF}Hello!\n{1000}{1050}Multi|Line|Text\n"};
    std::stringstream out;
    subs->ShiftAllSubtitlesBy(1400, 10, &in, &out);
}