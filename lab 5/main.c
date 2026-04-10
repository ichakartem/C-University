#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(void)
{
    int i, j, n;

    printf("Введите размерность матриц n: ");
    scanf("%d", &n);

    double **A = (double **)malloc(n * sizeof(double *));
    for (i = 0; i < n; i++)
        A[i] = (double *)malloc(n * sizeof(double));

    double **B = (double **)malloc(n * sizeof(double *));
    for (i = 0; i < n; i++)
        B[i] = (double *)malloc(n * sizeof(double));

    printf("Введите элементы матрицы A (%d x %d):\n", n, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%lf", &A[i][j]);

    printf("Введите элементы матрицы B (%d x %d):\n", n, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%lf", &B[i][j]);

    char op;
    printf("Введите операцию (+, - или *): ");
    scanf(" %c", &op);

    double **C = NULL;

    if (op == '+')
        C = matrix_add(A, B, n);
    else if (op == '-')
        C = matrix_sub(A, B, n);
    else if (op == '*')
        C = matrix_mul(A, B, n);
    else
    {
        printf("Неизвестная операция\n");
        free_matrix(A, n);
        free_matrix(B, n);
        return 1;
    }

    printf("Результат (матрица C = A %c B):\n", op);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%8.2f ", C[i][j]);
        printf("\n");
    }

    free_matrix(A, n);
    free_matrix(B, n);
    free_matrix(C, n);

    return 0;
}
