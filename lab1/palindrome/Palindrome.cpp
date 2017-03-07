//
// Created by DELL on 06.03.2017.
//

#include "Palindrome.h"
#include <string>
using namespace std;
bool is_palindrome(string str){
    int size=str.size();
    int i, j;
    for (i = 0, j = size-1; i < j; i++, j--)
    {
        if (str[i] != str[j])
            break;
    }
    if (i<j){
        return false;
    }
    else {
        return true;
    }
}