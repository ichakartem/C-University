#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *f1, *f2;
    char line[256];
    char *pos;
    char letter[10];
    int year, len_letter;

    printf("Введите первую букву фамилии: ");
    scanf("%s", letter);
    len_letter = strlen(letter);

    f1 = fopen("input.txt", "rt");
    if (f1 == NULL)
    {
        printf("Не удалось открыть input.txt\n");
        return 1;
    }

    f2 = fopen("output.txt", "wt");
    if (f2 == NULL)
    {
        printf("Не удалось создать output.txt\n");
        fclose(f1);
        return 1;
    }

    while (fgets(line, 256, f1) != NULL)
    {
        pos = strrchr(line, ' ');
        if (pos != NULL)
        {
            year = atoi(pos + 1);

            if (year > 1980 && strncmp(line, letter, len_letter) == 0)
            {
                fprintf(f2, "%s", line);
            }
        }
    }

    fclose(f1);
    fclose(f2);

    printf("Готово! Результат записан в output.txt\n");

    return 0;
}
