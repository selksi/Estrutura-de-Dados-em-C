#include <stdio.h>

int main(){

    int v[5] = {10, 20, 30, 40, 50};

    int *p = v;
    int soma = 0;

   while(p < v + 5){
        printf("indice atual: %d\n", *p);
        soma += *p;
        p++;
   }
   printf("Soma: %d\n", soma);

    return 0;
}