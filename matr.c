#include <stdio.h>
#include <stdlib.h>
#include "matr.h"

//Input: a - matrix (dim * dim), b - matrix (dim * dim) 
//Output: none
//stdout: result ('res' matrix);
void matr(double **a, double **b, int dim)
{
	//put your source code here
	//
	double **res;
	int i = 0;
	int j = 0;


	for(;i<dim;i++)
	{
		for (;j<dim;j++)
			printf("%lf ", res[i][j]);
		printf("\n");
	}

	return;
}
