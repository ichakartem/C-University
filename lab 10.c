#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIND_MAX(arr, n, res)              \
    do {                                   \
        res = arr[0];                      \
        for (int i = 1; i < n; i++)        \
            if (arr[i] > res)              \
                res = arr[i];              \
    } while (0)

#define FIND_AVG(arr, n, res)              \
    do {                                   \
        res = 0;                           \
        for (int i = 0; i < n; i++)        \
            res += arr[i];                 \
        res /= n;                          \
    } while (0)

int main(void) {
    char line[1000];
    double arr[100];
    int n = 0;
    double max;
    double avg;

    printf("Введите числа через пробел: ");
    if (fgets(line, 1000, stdin) == NULL) return 1;

    char *token = strtok(line, " \n");
    while (token != NULL && n < 100) {
        arr[n] = atof(token);
        n++;
        token = strtok(NULL, " \n");
    }

    if (n == 0) {
        printf("Не введено ни одно число\n");
        return 1;
    }

    FIND_MAX(arr, n, max);
    FIND_AVG(arr, n, avg);

    printf("Максимум: %g\n", max);
    printf("Среднее: %g\n", avg);
    return 0;
}
