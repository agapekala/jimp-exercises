//
// Created by DELL on 27.04.2017.
//

#include "Ksztalt.h"

using::ksztalt::Ksztalt;
using::ksztalt::Kolo;
using::ksztalt::Kwadrat;
using::ksztalt::Trojkat;

int main(){
    std::srand(std::time(0));
    std::vector<Ksztalt *> vec;
    int number= rand() % 100;
    for (int i=0; i<5; i++){
        int number= rand() % 100;
        if(number%3==0){
            vec.push_back(new Kolo);
        }else if(number%3==1){
            vec.push_back(new Kwadrat);
        }
        else{
            vec.push_back(new Trojkat);
        }
    }
    for( auto n: vec){
        n->rysuj();
        std::cout<< std::endl;
    }
    for (auto m: vec){
        delete m;
    }
}