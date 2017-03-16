//
// Created by Maria on 11.03.2017.
//

#include "Array2D.h"

int main(){
    cout<<"Podaj szer"<<endl;
    int n_rows, n_columns;
    cin>>n_rows;
    cout<<"Podaj dl"<<endl;
    cin>>n_columns;
    Array2D(n_rows, n_columns);
    FillArray2D(n_rows, n_columns, Array2D(n_rows, n_columns) );
    PtintArray2D(Array2D(n_rows, n_columns), n_rows, n_columns);
    DeleteArray2D(Array2D(n_rows, n_columns), n_rows, n_columns);
    return 0;
    }
