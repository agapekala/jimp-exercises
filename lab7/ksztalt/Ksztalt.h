//
// Created by DELL on 27.04.2017.
//

#ifndef JIMP_EXERCISES_KSZTALT_H
#define JIMP_EXERCISES_KSZTALT_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>

namespace ksztalt {
    class Ksztalt {
    public:
        virtual void rysuj()=0;
    };

    class Kolo:public Ksztalt{
    public:
        Kolo();
        ~Kolo();
        void rysuj() override ;

    };

    class Trojkat:public Ksztalt{
    public:
        Trojkat();
        ~Trojkat();
        void rysuj() override ;
    };

    class Kwadrat:public Ksztalt{
    public:
        Kwadrat();
        ~Kwadrat();
        void rysuj() override ;
    };
}


#endif //JIMP_EXERCISES_KSZTALT_H
