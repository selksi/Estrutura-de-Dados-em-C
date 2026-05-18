#include <stdio.h>
#include <string.h>

struct Produto{
    char nome[50];
    float preco;
    int quantidade;
};

void AtualizarProduto(struct Produto *p){
    p->preco += (p->preco * 0.10);
    p->quantidade -= 1;
}

int main(){
    struct Produto p1 = {"Sabonete", 5.5, 10};
    
    printf("Nome do produto: %s\n", p1.nome);
    printf("Preço do produto: %f\n", p1.preco);
    printf("Quantidade de produtos: %d\n", p1.quantidade);

    printf("\n");
    AtualizarProduto(&p1);

    printf("PRODUTOS ATUALIZADOS: ");

    printf("Nome do produto: %s\n", p1.nome);
    printf("Preço do produto: %f\n", p1.preco);
    printf("Quantidade de produtos: %d\n", p1.quantidade);

    return 0;
}

