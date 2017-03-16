//
// Created by Maria on 11.03.2017.
//

#include<iostream>
#include "Array2D.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

int **NewArray2D(int n_rows, int n_cols) {
    if (n_rows <= 0 || n_cols <= 0) {
        int **array = nullptr;
        return array;
    } else {
        int **array=new int* [n_rows];
        for (int i = 0; i < n_rows; i++) {
            int *array = new int[n_cols];
        }
        return array;
    }
}

int **Array2D(int n_rows, int n_cols){
    return NewArray2D(n_rows, n_cols);
}

void FillArray2D(int n_rows, int n_cols, int *const *array){
    int a=1;
    for (int i=0; i++; i<n_rows) {
        for (int j = 0; j++; j < n_cols) {
            array[i][j] = a;
            cin >> a;
            a++;
        }
    }
}

void PtintArray2D(int **array, int n_rows, int n_cols){
    for(int i=0; i<n_rows; i++){
        for(int j=0; j<n_cols; j++){
            cout<<array[i][j];
            cout<<" ";
            }
        cout<<endl;
    }
}

void DeleteArray2D(int **array, int n_rows, int n_cols){
    for(int i=0; i<n_rows; i++){
        delete [] array[i];
    }
    delete [] array;
}



