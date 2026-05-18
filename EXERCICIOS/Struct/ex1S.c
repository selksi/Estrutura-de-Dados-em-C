#include <stdio.h>
#include <string.h>

struct livro
{
    char titulo[100];
    char autor[50];
    int ano;
    int pag;
};

int main()
{
    struct livro lvr1 = {"A peste", "Albert Camus", 1920, 300};

    struct livro lvr2 = {"A Metamorfose", "Franz Kafka", 1910, 100};

    printf("O livro 1: %s, do autor %s do ano %d com %d paginas\n", lvr1.titulo, lvr1.autor, lvr1.ano, lvr1.pag);
    printf("O livro 2: %s, do autor %s do ano %d com %d paginas\n", lvr2.titulo, lvr2.autor, lvr2.ano, lvr2.pag);


    return 0;
}

