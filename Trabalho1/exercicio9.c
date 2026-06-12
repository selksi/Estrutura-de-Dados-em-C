#include <stdio.h>

void inverte(int *v, int tamanho){
    int *inicio = v;
    int *fim = v + tamanho - 1;

    while(inicio < fim){
        int temp = *inicio;
        *inicio = *fim;
        *fim = temp;

        inicio++;
        fim--;
    }
}

int main() {
    int v[4] = {1, 2, 3, 4};

    inverte(v, 4);

    for (int *p = v; p < v + 4; p++) {
        printf("%d \n", *p);
    }

    return 0;
}