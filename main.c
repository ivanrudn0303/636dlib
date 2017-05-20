#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>

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

int main(void)
{
    int n, i, j;
    double **a, **b, **c;
    scanf("%d", &n);
    a = (double**)malloc(n*sizeof(double*));
    b = (double**)malloc(n*sizeof(double*));
    for(i = 0; i < n; i ++)
    {
        a[i] = (double*)malloc(n*sizeof(double));
        for(j = 0; j < n; j ++)
           scanf("%lf", &(a[i][j]));
    }
    printf("\n");
    for(i = 0; i < n; i ++)
    {
        b[i] = (double*)malloc(n*sizeof(double));
        for(j = 0; j < n; j ++)
           scanf("%lf", &(b[i][j]));
    }
    c = matr(a, b, n);
    for(i = 0; i < n; i ++)
    {

        for(j = 0; j < n; j ++)
           printf("%lg ", c[i][j]);
        printf("\n");
        free(c[i]);
        free(a[i]);
        free(b[i]);
    }
    free(a);
    free(b);
    free(c);
    return 0;
}
