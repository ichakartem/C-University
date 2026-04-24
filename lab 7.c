#include <stdio.h>

struct humen {
    char name[50];
    char surname[50];
    int year;
};

int main(void) {

    struct humen people[4], sorted[4];

    for (int i = 0; i < 4; i++) {
        printf("Введите имя, фамилию и год рождения человека %d: ", i + 1);
        scanf("%49s %49s %d", people[i].name, people[i].surname, &people[i].year);
    }

    for (int i = 0; i < 4; i++) {
        sorted[i] = people[i];
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (sorted[j].year > sorted[j + 1].year) {
                struct humen tmp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = tmp;
            }
        }
    }

    printf("\nОтсортированный массив по году рождения:\n");
    printf("%-15s %-15s %s\n", "Имя", "Фамилия", "Год");
    for (int i = 0; i < 4; i++) {
        printf("%-15s %-15s %d\n", sorted[i].name, sorted[i].surname, sorted[i].year);
    }

    return 0;
}
