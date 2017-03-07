//
// Created by DELL on 06.03.2017.
//

#include "DoubleBasePalindromes.h"
using namespace std;
bool is_palindrome(string);
string convert(int);

uint64_t DoubleBasePalindromes(int max_vaule_exculsive){
    string number_str;
    int i;
    uint64_t suma;
    for(i=0; i<=max_vaule_exculsive; i++){
        number_str=to_string(i);
        if(is_palindrome(number_str)==1){
            if (is_palindrome(convert(i))){
                suma+=i;
            }
        }
    }
    return suma;
}

string convert(int number){
    int a=number,r;
    string str="";
    while(a>=1){
        r=a%2;
        a=(a-r)/2;
        str=to_string(r)+str;
    }
    return str;
}

bool is_palindrome(string string1){
    int size=string1.size();
    int i, j;
    for (i = 0, j = size-1; i < j; i++, j--)
    {
        if (string1[i] != string1[j])
            break;
    }
    if (i<j){
        return false;
    }
    else {
        return true;
    }
}

