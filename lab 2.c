#include <stdio.h>
#include <math.h>

int main(void) {
    int N=2;
    double mass[N][N];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Введите значение для [%d][%d]: ", i, j);
            scanf("%lf", &mass[i][j]);
        }
    }
    printf("\n");
    
    double summaOsnova = 0.0;
    double summaPoboch = 0.0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                summaOsnova += mass[i][j];
            }
            if (i + j == N - 1) {
                summaPoboch += mass[i][j];
            }
        }
    }
    printf("Сумма основной диагонали: %lf \n", summaOsnova);
    printf("Сумма побочной диагонали: %lf \n\n", summaPoboch);
    
    int mass2[2][2];
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Введите значение для [%d][%d]: ", i, j);
            scanf("%d", &mass2[i][j]);
        }
    }
    
    double summaMass2 = 0.0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            summaMass2 += mass2[i][j];
        }
    }
    
    double kvadratMass2 = 0.0;
    double stepen = 2.0;
    kvadratMass2 = pow(summaMass2, stepen);
    printf("Квадрат Матрицы: %lf \n", kvadratMass2);
    
    return 0;
}
