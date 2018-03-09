//
// Created by jachfili on 09.03.18.
//

#include "Array2D.h"




int **Array2D(int n_rows, int n_columns)
{
    if (n_rows<1 || n_columns <1)
    {
        return nullptr;
    }
    int **result = NewArray2D(n_rows, n_columns);
    FillArray2D(n_rows, n_columns, result);
    return result;
}

void FillArray2D(int n_rows, int n_columns, int *const *result) {
    int k=1;
    for (int i = 0; i<n_rows; i++)
    {
        for (int j = 0; j < n_columns; j++)
        {
            result[i][j]=k;
            k++;
        }
    }
}

int **NewArray2D(int n_rows, int n_columns) {
    int**result = new int*[n_rows];
    for (int i = 0; i < n_rows;i++)
    {
        result[i] = new int[n_columns];
    }
    return result;
}

void DeleteArray2D(int **array, int n_rows, int n_columns)
{
    if (array == nullptr) return;
    for(int i =0; i<n_rows; i++)
    {
        delete [] array[i];
    }
    delete []  array;
}
