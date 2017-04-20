//
// Created by DELL on 08.04.2017.
//

#include "WordCounter.h"
#include <fstream>
using::datastructures::Word;
using::datastructures::WordCounter;
using::datastructures::Counts;

int main(){
    WordCounter s1{Word("a"), Word("p"), Word("a"), Word("a"), Word("hi"), Word("voltage")};
    std::cout<<s1.TotalWords();
    std::cout<<std::endl<<s1.DistinctWords();
    std::cout<<std::endl<<s1<<std::endl<<std::endl;

    std::ifstream is("C:\\Users\\DELL\\Desktop\\AGH\\myfile.txt");
    WordCounter wc = WordCounter::FromInputStream(*&is);
    int ilosc = wc["programowanie"];
    is.close();
    std::cout<<ilosc<<std::endl;
    std::cout<<wc;
}