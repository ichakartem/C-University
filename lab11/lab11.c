#include <stdio.h>
#include "varfunc.h"

int main(void) {
    printf("Сумма 3 чисел: %g\n", sum(3, 1.0, 2.0, 3.0));

    printf("Максимум 4 чисел: %g\n", max(4, 7.0, 2.0, 9.0, 4.0));

    printf("Минимум 4 чисел: %g\n", min(4, 7.0, 2.0, 9.0, 4.0));

    printf("Среднее 3 чисел: %g\n", avg(3, 2.0, 4.0, 6.0));

    return 0;
}
