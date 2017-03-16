
#include "Array2D.h"

int main(){
    int n_rows, n_columns;
    cin>>n_rows;
    cin>>n_columns;
    Array2D(n_rows, n_columns);
    PrintArray2D(n_rows,n_columns,Array2D(n_rows, n_columns));
    DeleteArray2D(Array2D(n_rows, n_columns), n_rows, n_columns);
    return 0;
}