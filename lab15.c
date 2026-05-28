#include <stdio.h>

void forward(int n) {
    if (n >= 10) forward(n / 10);
    printf("%d ", n % 10);
}

void backward(int n) {
    printf("%d ", n % 10);
    if (n >= 10) backward(n / 10);
}

int main(void) {
    int n;
    printf("Введите натуральное число: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Это не натуральное число\n");
        return 1;
    }

    forward(n);
    printf("\n");
    backward(n);
    printf("\n");
    return 0;
}
