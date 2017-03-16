//
// Created by DELL on 11.03.2017.
//

#include "Array2D.h"

void FillArray2D(int n_rows, int n_columns, int *const *array);

int **NewArray2D(int n_rows, int n_columns);

int **Array2D(int n_rows, int n_columns){
    return NewArray2D(n_rows, n_columns);
}

int **NewArray2D(int n_rows, int n_columns) {
    if(n_rows <= 0 || n_columns <= 0){
        int **array=nullptr;
        return array;
    }
    int **array=new int*[n_rows];
    for(int i=0; i<n_rows; i++){
        array[i]=new int[n_columns];
    }
    FillArray2D(n_rows, n_columns, array);
    return array;
}

void FillArray2D(int n_rows, int n_columns, int *const *array) {
    int c=1;
    for(int i=0; i<n_rows; i++){
        for(int j=0; j<n_columns; j++){
            array[i][j]=c;
            c++;
        }
    }
}

void DeleteArray2D(int **array, int n_rows, int n_columns){
    int i;
    for(i=0; i<n_rows; i++){
        delete [] array[i];
    }
    delete [] array;
}

void PrintArray2D(int n_rows,int n_columns,int **array){
    int i,j;
    for(i=0; i<n_rows; i++){
        for(j=0; j<n_columns; j++){
            cout<<array[i][j];
            cout<<" ";
        }
        cout<<endl;
    }
}