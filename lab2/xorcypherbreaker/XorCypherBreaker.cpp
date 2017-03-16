//
// Created by Maria on 13.03.2017.
//

#include<iostream>
#include<algorithm>
#include "XorCypherBreaker.h"
#include <string>
#include <vector>
#include<fstream>

std::string XorCypherBreaker(const std::vector<char> &cryptogram, int key_length, const std::vector<std::string> &dictionary);


std::string XorCypherBreaker(const std::vector<char> &cryptogram, int key_length, const std::vector<std::string> &dictionary){
    int number=0;
    int how_much=0;
    std::string found_key;
    std::string key="";
    std::string word="";
    std::vector < std::string > message;
    for(int i=97; i<123; i++){
        for(int j=97; j<123; j++){
            for(int k=97; k<123; k++){
                key.push_back(char(i));
                key.push_back(char(j));
                key.push_back(char(k));
                int help=0;
                for(int n: cryptogram){
                    if (int(n^key[help%3])<97 || int(n^key[help%3])>122){
                        message.push_back(word);
                        word="";
                        help++;
                    }
                    else{
                        word.push_back(char(n^key[help%3]));
                        help++;
                    }
                }
                for(string w :message){
                    if (find(dictionary.begin(),dictionary.end(), w) != dictionary.end()) {
                        number++;
                    }
                }
                if (number>how_much){
                    how_much=number;
                    number=0;
                    found_key="";
                    found_key=key;
                    key="";
                    message.clear();
                    }
                else{
                    number=0;
                    key="";
                    message.clear();
                }

            }




        }
    }
    return found_key;
}