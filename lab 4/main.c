#include <stdio.h>
#include "treug.h"

int main(void)
{
    double a, b, c;

    printf("Введите длины трёх сторон треугольника: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Ошибка ввода, вводите только 3 числа\n");
        return 1;
    }

    if (!is_valid_sides(a, b, c)) {
        printf("Ошибка: стороны должны быть положительными\n");
        return 1;
    }

    if (!is_triangle(a, b, c)) {
        printf("Ошибка: неравенство треугольника не выполняется\n");
        return 1;
    }

    printf("Периметр = %.4f\n", triangle_perimeter(a, b, c));
    printf("Площадь  = %.4f\n", triangle_area(a, b, c));

    return 0;
}
