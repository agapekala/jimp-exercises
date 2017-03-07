#include <iostream>
#include<string>
#include "Palindrome.h"
using namespace std;
int main(){
    string str;
    cin >>str;
    if (is_palindrome(str)){
        cout<<"tak"<<endl;
    }
    else{
        cout<<"nie"<<endl;
    }
}