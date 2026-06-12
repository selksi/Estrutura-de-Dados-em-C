#include <stdio.h>

int main(){

    int var = 1;

    int *pvar = &var;
    printf("Variável: %d\n", *pvar);

    *pvar = *pvar + 5;
    printf("Variavel apos a adição via ponteiro: %d\n", *pvar);
    *pvar = *pvar * 2;
    printf("Variável após a multiplicação via ponteiro: %d\n", *pvar);

    return 0;
}