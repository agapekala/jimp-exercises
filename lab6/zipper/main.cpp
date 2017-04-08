//
// Created by DELL on 07.04.2017.
//

#include "Zipper.h"
using::datastructures::Zipper;
using::datastructures::Iterator;
using::std::endl;

int main(){
    std::vector<std::string> one {"abc","elo","koks","oks"};
    std::vector<int> two {34,78,98,13};
    /*
    for(auto p:Zipper::zip(one,two)){
        std::cout<<p.first<<", "<<p.second<<endl;
    }
    */
    std::cout<<datastructures::Foo(one,two);
    return 0;
}