/* main.c */
#include "matr.h"

int main(void)
{
    int n, i, j;
    FILE *in, *out, *lowout;
    double **a, **b, **c, **d;
    in = fopen("in.txt", "r");
    out = fopen("out.txt", "w");
    lowout = fopen("lowout.txt", "w");
    fscanf(in ,"%d", &n);
    a = (double**)malloc(n*sizeof(double*));
    b = (double**)malloc(n*sizeof(double*));
    for(i = 0; i < n; i ++)
    {
        a[i] = (double*)malloc(n*sizeof(double));
        for(j = 0; j < n; j ++)
           fscanf(in, "%lf", &(a[i][j]));
    }
    for(i = 0; i < n; i ++)
    {
        b[i] = (double*)malloc(n*sizeof(double));
        for(j = 0; j < n; j ++)
           fscanf(in, "%lf", &(b[i][j]));
    }
    c = matr(a, b, n);
    d = low(a, b, n);
    for(i = 0; i < n; i ++)
    {

        for(j = 0; j < n; j ++)
        {
           fprintf(out, "%lf ", c[i][j]);
           fprintf(lowout, "%lf ", c[i][j]);
        }
        fprintf(out, "\n");
        fprintf(lowout, "\n");
        free(c[i]);
        free(a[i]);
        free(b[i]);
        free(d[i]);
    }
    free(d);
    free(a);
    free(b);
    free(c);
    fclose(out);
    fclose(in);
    fclose(lowout);
    return 0;
}
