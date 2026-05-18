#include <stdio.h>

void trocarValores(int *p1, int *p2){
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main(){
    int a, b;
    a = 5;
    b = 8;
    printf("Valores antes da troca: a = %d e b = %d\n",a, b);
    trocarValores(&a, &b);
    printf("Valores depois da troca: a = %d, b = %d\n", a, b);
    return 0;
}