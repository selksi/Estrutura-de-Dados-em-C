#include <stdio.h>

int compara(char *s1, char *s2) {
    while (*s1 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }

    if (*s1 == *s2) {
        return 0;
    } else if (*s1 < *s2) {
        return -1;
    } else {
        return 1;
    }
}
int main() {
    char a[] = "casa";
    char b[] = "caso";

    int resultado = compara(a, b);

    if (resultado == 0) {
        printf("Strings iguais\n");
    } else if (resultado < 0) {
        printf("s1 menor que s2\n");
    } else {
        printf("s1 maior que s2\n");
    }

    return 0;
}