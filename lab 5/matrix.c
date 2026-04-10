#include <stdlib.h>
#include "matrix.h"

double **matrix_add(double **A, double **B, int n)
{
    int i, j;
    double **C = (double **)malloc(n * sizeof(double *));
    for (i = 0; i < n; i++)
        C[i] = (double *)malloc(n * sizeof(double));

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];

    return C;
}

double **matrix_sub(double **A, double **B, int n)
{
    int i, j;
    double **C = (double **)malloc(n * sizeof(double *));
    for (i = 0; i < n; i++)
        C[i] = (double *)malloc(n * sizeof(double));

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];

    return C;
}

double **matrix_mul(double **A, double **B, int n)
{
    int i, j, k;
    double **C = (double **)malloc(n * sizeof(double *));
    for (i = 0; i < n; i++)
        C[i] = (double *)malloc(n * sizeof(double));

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            C[i][j] = 0.0;
            for (k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }

    return C;
}

void free_matrix(double **M, int n)
{
    int i;
    for (i = 0; i < n; i++)
        free(M[i]);
    free(M);
}
