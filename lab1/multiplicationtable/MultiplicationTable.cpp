//
// Created by DELL on 07.03.2017.
//
#include <iostream>
#include "MultiplicationTable.h"
using namespace std;
void MultiplicationTable(int tab[][10]){
    int i, j;
    for (i=1; i<=10; i++){
        for (j=1;j<=10; j++){
            tab[i-1][j-1]=i*j;
        }
    }
}

void PrintMultiplicationTable(int tab[][10]){
    int i, j;
    for(i=1; i<=10; i++){
        for(j=1; j<=10; j++){
            cout << tab[i-1][j-1];
        }
        cout<<endl;
    }
}