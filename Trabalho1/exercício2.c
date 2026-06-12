#include <stdio.h>

int main(){
    int A = 10, B = 20;
    int *p1, *p2;

    p1 = &A;
    p2 = &B;

    printf("Valor apontado por p1: %d\nValor apontado por p2: %d\n",*p1, *p2);

    int *pt = p1;
    p1 = p2;
    p2 = pt;

    printf("Valor apontado por p1 apos a troca: %d\nValor apontado por p2 apos a troca: %d\n",*p1, *p2);


    return 0;
}