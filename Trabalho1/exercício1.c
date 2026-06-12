#include <stdio.h>

int main(){
    int var = 3;
    float fvar = 3.14;

    int *pvar = &var;
    float *pfvar = &fvar;

    printf("Variável inteira a partir do ponteiro: %d\n", *pvar);
    printf("Variável float a partir do ponteiro: %.2f\n", *pfvar);


    return 0;
}