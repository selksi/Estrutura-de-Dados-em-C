#include <stdio.h>

int main(){
    int num;
    printf("DIGITE O NUMERO:\n");
    scanf("%d", &num);

    int *ptr;
    ptr = &num;

    printf("ENDEREÇO DO NUMERO: %p\n", ptr);

    printf("NUMERO OBTIDO A PARTIR DO ENDEREÇO: %d\n", *ptr);

    return 0;
}