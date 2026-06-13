#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **alloc_matrix(int n) {
    int **m = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        m[i] = malloc(n * sizeof(int));
    return m;
}

void free_matrix(int **m, int n) {
    for (int i = 0; i < n; i++)
        free(m[i]);
    free(m);
}

void fill_random(int **m, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            m[i][j] = rand() % 10;
}

void write_matrix(FILE *f, int **m, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            fprintf(f, "%d ", m[i][j]);
        fprintf(f, "\n");
    }
}

void read_matrix(FILE *f, int **m, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(f, "%d", &m[i][j]);
}

int **mat_mul(int **a, int **b, int n) {
    int **c = alloc_matrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    return c;
}

int **mat_add(int **a, int **b, int n) {
    int **c = alloc_matrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = a[i][j] + b[i][j];
    return c;
}

int main(void) {
    int n;
    printf("Введите размер матриц: ");
    scanf("%d", &n);

    clock_t start = clock();
    srand(time(NULL));

    int **a = alloc_matrix(n);
    int **b = alloc_matrix(n);
    fill_random(a, n);
    fill_random(b, n);

    FILE *f = fopen("input.txt", "w");
    fprintf(f, "%d\n", n);
    write_matrix(f, a, n);
    write_matrix(f, b, n);
    fclose(f);

    free_matrix(a, n);
    free_matrix(b, n);

    f = fopen("input.txt", "r");
    fscanf(f, "%d", &n);
    a = alloc_matrix(n);
    b = alloc_matrix(n);
    read_matrix(f, a, n);
    read_matrix(f, b, n);
    fclose(f);

    int **mul = mat_mul(a, b, n);
    int **sum = mat_add(a, b, n);

    f = fopen("output.txt", "w");
    fprintf(f, "Умножение:\n");
    write_matrix(f, mul, n);
    fprintf(f, "Сложение:\n");
    write_matrix(f, sum, n);
    fclose(f);

    free_matrix(a, n);
    free_matrix(b, n);
    free_matrix(mul, n);
    free_matrix(sum, n);

    printf("Время работы: %.6f с\n", (double)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
