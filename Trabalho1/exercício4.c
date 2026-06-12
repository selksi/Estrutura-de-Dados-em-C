#include <stdio.h>

int main(){
    int a = 10, b = 20;

    int *pa = &a, *pb = &b;
    printf("Variaveis antes do swap: a = %d | b = %d\n", *pa, *pb);

    //Swap feito sem variavel auxiliar
    //*pa guarda temporariamente a soma de dois valores
    //depois recuperamos com subtrações
    *pa = *pa + *pb;
    *pb = *pa - *pb;
    *pa = *pa - *pb; 
    printf("Variaveis apos o swap: a = %d | b = %d\n", *pa, *pb);

    return 0;
}