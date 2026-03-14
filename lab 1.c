#include <stdio.h>
#include <math.h>

int main(void) {
    while (1 == 1) {
        double a, b, c;
        double d, x1, x2;
        scanf("%lf %lf %lf", &a, &b, &c);

        printf("a = %lf, b = %lf, c = %lf \n", a, b, c);
        d = pow(b, 2) - 4*a*c;

        if (d < 0) {
            printf("КОРНЕЙ НЕТ\n");
        } else {
            x1 = (-b + pow(d, 1.0/2)) / (2*a);
            x2 = (-b - pow(d, 1.0/2)) / (2*a);
            printf("x1 = %lf \n", x1);
            printf("x2 = %lf \n", x2);
        }

        printf("Продолжить? (y/n): ");
        char tester;
        scanf(" %c", &tester);
        if (tester == 'y' || tester == 'Y') {
            printf("Продолжаем\n");
        } else {
            break;
        }
    }
    return 0;
}
