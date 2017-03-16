//
// Created by DELL on 11.03.2017.
//

#include "Polybius.h"
#include <string>


std::string PolybiusCrypt(std::string message){
    std::string str="";
    int n_first, n_second;
    std::string l_first, l_second;
    for(int i=0; i<message.length(); i++){
        if(message[i]==' '){
            i++;
        }
        if(message[i]>=97 && (message[i])<=122){
           message[i]=(message[i]-32);
        }
        if(message[i]>73){
            if((message[i]-65)%5==0){
                n_first=(message[i]-65)/5;
            }
            else{
                n_first =(((message[i]) - 65)/5)+1;
            }
            if((message[i]-65)%5==0){
                n_second=5;
            }
            else{
                n_second = (((message[i]) - 65)%5);
            }
        }
        else{
            if((message[i]-64)%5==0){
                n_first=(message[i]-64)/5;
            }
            else{
                n_first =(((message[i]) - 64)/5)+1;
            }
            if((message[i]-64)%5==0){
                n_second=5;
            }
            else{
                n_second = (((message[i]) - 64)%5);
            }
        }
        l_first = std::to_string( n_first );
        l_second= std::to_string( n_second );
        str +=l_first;
        str +=l_second;
    }
    return str;
}


std::string PolybiusDecrypt(std::string crypted){
    std::string str="";
    int n_first, n_second;
    char letter;
    for(int i=0; i<crypted.length(); i+=2){
        n_first=crypted[i]-48;
        n_second=crypted[i+1]-48;
        letter=n_second+(n_first-1)*5;
        if(letter>9){
            letter+=97;
        }
        else {
            letter += 96;
        }
        str+=letter;
    }
    return str;
}
