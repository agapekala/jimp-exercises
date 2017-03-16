//
// Created by Maria on 13.03.2017.
//

#include "Polybius.h"
#include<iostream>
#include <string>
#include <map>
#include <w32api/wsman.h>

std::string PolybiusCrypt(std::string message);
std::string PolybiusDecrypt(std::string crypted);
using namespace std;

map<char, string> MakeAlphabet(){
    char tab[4][4];
    int number=65;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            tab[i][j]=(char)number;
        }
    }
    map<char, string> alfabet;
    int c=65;
    for (int i=0; i<5; i++){
        for (int j =0; j<5; j++){
            string kluczyk = to_string(i)+to_string(j);
            char z=(char)c;
            if(c==73){
                alfabet[z]=kluczyk;
                c++;
                char z=(char)c;
                alfabet[z]=kluczyk;
                c++;
            }
            else{
                alfabet[z]=kluczyk;
                c++;
            }

        }
    }
    return alfabet;
}

string PolybiusCrypt(string message){
    int i=0;
    string hidden_message="";
    while(!file.eof()){
        if(int(message[i])>=65 || int(message[i])<=90){
            hidden_message=hidden_message+MakeAlphabet()[message[i]];
        }
        else{
            hidden_message=hidden_message+message[i];
        }
        i++;
    }
    return hidden_message;
}

string PolybiusDecrypt(string crypted){
    int i=0;
    string message="";
    while(!file.eof()){
        map<char, string> alfabet=MakeAlphabet();
        if(int(crypted[i])>=65 || int(crypted[i])<=90){
            message=message+alfabet.find(crypted[i]);
        }
        else{
            message=message+crypted[i];
        }
        i++;
    }
    return message;
}