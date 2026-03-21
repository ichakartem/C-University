#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char s[81];
    scanf("%80[^\n]", s);
    char s2[35];
    scanf("%34s", s2);

    printf("длина строки %zu: \n ", strlen(s));
    for (int i = 0; i < strlen(s2); i++){
        for (int j = 0; j<strlen(s); j++){
            if (s2[i] == s[j]) {
                s[j] = toupper(s2[i]);
            }

            if (s[j] == '!') {
                s[j] = '?';
            }
        }
    }

    printf("%s \n", s);
    return 0;
}
