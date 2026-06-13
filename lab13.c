#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int n, m;
    printf("Введите N: ");
    scanf("%d", &n);
    printf("Введите число столбцов M: ");
    scanf("%d", &m);

    clock_t start = clock();
    srand(time(NULL));

    int *v = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        v[i] = rand() % 100 + 1;

    FILE *f = fopen("input.txt", "w");
    fprintf(f, "%d\n", n);
    for (int i = 0; i < n; i++)
        fprintf(f, "%d ", v[i]);
    fprintf(f, "\n");
    free(v);
    fclose(f);

    f = fopen("input.txt", "r");
    fscanf(f, "%d", &n);
    v = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        fscanf(f, "%d", &v[i]);
    fclose(f);

    FILE *out = fopen("output.txt", "w");
    for (int i = 0; i < n; i++) {
        if (v[i] % 35 == 0)
            fprintf(out, "ПЯТЬСЕМЬ ");
        else if (v[i] % 5 == 0)
            fprintf(out, "ПЯТЬ ");
        else if (v[i] % 7 == 0)
            fprintf(out, "СЕМЬ ");
        else
            fprintf(out, "%d ", v[i]);
    }
    fprintf(out, "\n");
    fclose(out);

    int rows = n / m;
    int **mat = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat[i] = malloc(m * sizeof(int));
        for (int j = 0; j < m; j++)
            mat[i][j] = v[i * m + j];
    }

    printf("Матрица %dx%d:\n", rows, m);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < m; j++)
            printf("%4d", mat[i][j]);
        printf("\n");
    }

    printf("Суммы строк: ");
    for (int i = 0; i < rows; i++) {
        int s = 0;
        for (int j = 0; j < m; j++)
            s += mat[i][j];
        printf("%d ", s);
    }
    printf("\n");

    printf("Суммы столбцов: ");
    for (int j = 0; j < m; j++) {
        int s = 0;
        for (int i = 0; i < rows; i++)
            s += mat[i][j];
        printf("%d ", s);
    }
    printf("\n");

    for (int i = 0; i < rows; i++)
        free(mat[i]);
    free(mat);
    free(v);

    printf("Время работы: %.6f с\n", (double)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
