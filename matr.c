#include <stdio.h>
#include <stdlib.h>
#include "matr.h"

//Input: a - matrix (dim * dim), b - matrix (dim * dim) 
//Output: none
//stdout: result ('res' matrix);
void tran(double **a, int n)
{
    int i, j;
    double re;
    for(i = 0; i < n; i ++)
        for(j = 0; j < i; j ++)
        {
            re = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = re;
        }
}

double** matr(double **a, double **b, int n)
{
    double **res;
    int i, j, k, time = clock();
    res = (double**)malloc(n*sizeof(double*));
    tran(b, n);
    for(i = 0; i < n; i ++)
    {
        res[i] = (double*)malloc(n*sizeof(double));
        for(j = 0; j < n; j ++)
            for(k = 0; k < n; k ++)
                res[i][j] += a[i][k] * b[j][k];
    }
    tran(b, n);
    time -= clock();
    printf("%d\n", -time);
    return res;
}

double** low(double **a, double **b, int n)
{
    double **res;
    int i, j, k, time = clock();
    res = (double**)malloc(n*sizeof(double*));
    for(i = 0; i < n; i ++)
    {
        res[i] = (double*)malloc(n*sizeof(double));
        for(j = 0; j < n; j ++)
            for(k = 0; k < n; k ++)
                res[i][j] += a[i][k] * b[k][j];
    }
    time -= clock();
    printf("%d\n", -time);
    return res;
}