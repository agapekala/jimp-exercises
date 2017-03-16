//
// Created by Maria on 11.03.2017.
//

#ifndef JIMP_EXERCISES_ARRAY2D_H
#define JIMP_EXERCISES_ARRAY2D_H


#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Array2D.h"
using namespace std;
int **NewArray2D(int n_rows, int n_cols);
int **Array2D(int n_rows, int n_cols);
void FillArray2D(int n_rows, int n_cols, int *const *array);
void PtintArray2D(int **array, int n_rows, int n_cols);
void DeleteArray2D(int **array, int n_rows, int n_cols);

#endif //JIMP_EXERCISES_ARRAY2D_H
