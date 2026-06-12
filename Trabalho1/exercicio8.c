#include <stdio.h>

int conta(char *str, char c){
    int quantidade = 0;

    while(*str != '\0'){
        if(*str == c){
            quantidade ++;
        }
        str++;
    }
    return quantidade;
}

int main() {
    char nome[] = "programacao";

    printf("Quantidade: %d\n", conta(nome, 'a'));

    return 0;
}