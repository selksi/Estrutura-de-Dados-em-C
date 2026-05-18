#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[20];
    float preco;
} Produto;

int main(){
    Produto *p;

    strcpy(p->nome, "Detergente");
    p->preco = 2.5;

    printf("Nome do produto: %s\n", p->nome);
    printf("Preco do produto: %.2f\n", p->preco);

    return 0;
}