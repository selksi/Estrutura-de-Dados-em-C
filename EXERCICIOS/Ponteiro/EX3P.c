#include <stdio.h>

void mudarArray(int *array, int tamanho){
    for (int i = 0; i < tamanho; i++){
        *(array + i) = *(array + i) + 10;
    }
}

int main(){
    int numeros[5] = {0, 10, 20, 30, 40};
    printf("ARRAY ANTES DA MUDANÇA: \n");
    for(int i = 0; i < 5; i++){
        printf("Indice %d: %d\n", i, numeros[i]);
    }
    int *ptr = numeros;
    mudarArray(ptr, 5);
    printf("ARRAY DEPOIS DA MUDANÇA: \n");
    for(int i = 0; i < 5; i++){
        printf("Indice %d: %d\n", i, numeros[i]);
    }

    return 0;
}