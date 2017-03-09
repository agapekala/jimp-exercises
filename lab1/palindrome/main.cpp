#include <iostream>
#include<string>
#include "Palindrome.h"
using namespace std;
int main() {
    bool flag= true;
    while (flag) {
        cout << "If you want to check the word press 'c' or 'q' if you want to leave" << endl;
        char user_choice;
        cin >> user_choice;
        if (user_choice == 'c') {
            cout << "Give the word" << endl;
            string str;
            cin >> str;
            if (is_palindrome(str)) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
        if (user_choice == 'q') {
            flag=false;
        } else {
            flag=true;
        }

    }
    return 0;
}