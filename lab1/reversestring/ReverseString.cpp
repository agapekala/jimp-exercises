#include <iostream>
#include "ReverseString.h"
#include<string>

using namespace std;

string reverse(string str){
    const char *characters = str.c_str();
    size_t size = str.size();
    char first;
    first=characters[0];
    if (size<=1){
        return str;
    }
    else {
        str.erase(str.begin());
        if (size == 2) {
            return str + first;
        }
        return reverse(str)+first;
    }
}
