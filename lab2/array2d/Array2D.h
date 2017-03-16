//
// Created by DELL on 11.03.2017.
//

#ifndef JIMP_EXERCISES_ARRAY2D_H
#define JIMP_EXERCISES_ARRAY2D_H

#include <iostream>
using namespace std;
int **Array2D(int n_rows, int n_columns);
void DeleteArray2D(int **array, int n_rows, int n_columns);
void FillArray2D(int n_rows, int n_columns, int *const *array);
int **NewArray2D(int n_rows, int n_columns);
void PrintArray2D(int n_rows,int n_columns,int **array);

#endif //JIMP_EXERCISES_ARRAY2D_H
