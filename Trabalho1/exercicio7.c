#include <stdio.h>

int maior(int *v, int tamanho){
    int maior = *v;
    for(int i = 0; i < tamanho; i++){
        if(*(v + i) > maior){
            maior = *(v + i);
        }
    }
    return maior;
}

int main() {
    int v[5] = {10, 20, 30, 40, 50};

    printf("Maior valor: %d\n", maior(v, 5));

    return 0;
}