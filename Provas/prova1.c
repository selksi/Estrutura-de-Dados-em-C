#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

int fatorial(int n) {
    if (n <= 1) {
        return 1;
    }

    return n * fatorial(n - 1);
}

int soma_vetor(int v[], int tam) {
    if (tam <= 0) {
        return 0;
    }

    return v[tam - 1] + soma_vetor(v, tam - 1);
}

int main(void) {
    int i, j;

//---------------------QUESTAO 1:--------------
    printf("QUESTAO 1\n");

    int vetor[10] = {0};

    printf("Vetor: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    int matriz[3][3] = {0};

    for (i = 0; i < 3; i++) {
        matriz[i][i] = 1;
    }

    printf("Matriz 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

//---------------------QUESTAO 2:--------------
    printf("\nQUESTAO 2\n");

    Produto p1;
    strcpy(p1.nome, "Arroz");
    p1.preco = 25.90;
    p1.quantidade = 10;

    printf("Nome: %s\n", p1.nome);
    printf("Preco: %.2f\n", p1.preco);
    printf("Quantidade: %d\n", p1.quantidade);


//---------------------QUESTAO 3:--------------
    printf("\nQUESTAO 3\n");

    Produto *ptr = &p1;

    printf("Nome pelo ponteiro: %s\n", ptr->nome);
    printf("Preco pelo ponteiro: %.2f\n", ptr->preco);

    /*
        ptr->preco e (*ptr).preco acessam o mesmo campo.

        ptr->preco é uma forma abreviada de escrever (*ptr).preco.

        Ou seja:
        - ptr é um ponteiro para Produto;
        - *ptr acessa o conteúdo apontado;
        - (*ptr).preco acessa o campo preco desse conteúdo.
    */


//---------------------QUESTAO 4:--------------
    printf("\nQUESTAO 4\n");

    int n;
    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &n);

    Produto *produtos = malloc(n * sizeof(Produto));

    if (produtos == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nProduto %d\n", i + 1);

        printf("Nome: ");
        scanf("%49s", produtos[i].nome);

        printf("Preco: ");
        scanf("%f", &produtos[i].preco);

        printf("Quantidade: ");
        scanf("%d", &produtos[i].quantidade);
    }

    printf("\nProdutos cadastrados:\n");
    for (i = 0; i < n; i++) {
        printf("%s - R$ %.2f - qtd: %d\n",
               produtos[i].nome,
               produtos[i].preco,
               produtos[i].quantidade);
    }

    /*
        O free é importante porque devolve ao sistema a memória
        que foi alocada dinamicamente com malloc.

        Se não usarmos free, pode ocorrer vazamento de memória.
    */
    free(produtos);


//---------------------QUESTAO 5:--------------
    printf("\nQUESTAO 5\n");

    printf("Fatorial de 5: %d\n", fatorial(5));

    int v_soma[] = {1, 2, 3, 4, 5};
    printf("Soma do vetor: %d\n", soma_vetor(v_soma, 5));

    /*
        A complexidade de soma_vetor é O(n),
        pois a função faz uma chamada recursiva para cada elemento do vetor.
    */


//---------------------QUESTAO 6:--------------
    printf("\nQUESTAO 6\n");

    Produto p2;
    strcpy(p2.nome, "Feijao");
    p2.preco = 8.50;
    p2.quantidade = 20;

    FILE *arq = fopen("produtos.txt", "w");

    if (arq == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    fprintf(arq, "%s %.2f %d\n", p1.nome, p1.preco, p1.quantidade);
    fprintf(arq, "%s %.2f %d\n", p2.nome, p2.preco, p2.quantidade);

    fclose(arq);

    arq = fopen("produtos.txt", "r");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1;
    }

    Produto lido;

    printf("Dados lidos do arquivo:\n");
    while (fscanf(arq, "%49s %f %d", lido.nome, &lido.preco, &lido.quantidade) == 3) {
        printf("%s - R$ %.2f - qtd: %d\n",
               lido.nome,
               lido.preco,
               lido.quantidade);
    }

    fclose(arq);

    return 0;
}