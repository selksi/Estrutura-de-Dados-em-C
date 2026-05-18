#include <stdio.h>

void Estoque(int produto[], int qtd){
    for(int i = 0; i < qtd; i++){
        printf("Digite a quantidade de produtos do produto de índice %d \n", i + 1);
        scanf("%d", &produto[i]);
    }
    char escolha;
    printf("Deseja comprar algum produto? (S para sim ou N para não)\n");
    scanf(" %c", &escolha);
    if(escolha == 'S' || escolha == 's'){
            do{
                int indice, quantidade;
                printf("Qual o índice do produto que deseja comprar?\n");
                scanf("%d", &indice);
                printf("Qual a quantidade de produtos que deseja comprar?\n");
                scanf("%d", &quantidade);
                produto[indice - 1] -= quantidade;
                printf("Compra registrada!\n");
                printf("Deseja comprar mais algum produto?(S ou N)\n");
                scanf(" %c", &escolha);
            }while(escolha == 'S' || escolha == 's');
        }
    else if (escolha == 'N' || escolha == 'n'){
        printf("Nenhuma compra realizada");
    }
    else{
        printf(" Escolha inválida, escolha Y ou N\n");
    }
    printf("Novo estado do estoque: \n");
    for(int i = 0; i < qtd; i++){
        printf("produto de indice %d com %d unidades\n", i + 1, produto[i]);
    }

    char decisao;
    printf("Deseja adicionar algum produto ao estoque?\n");
    scanf(" %c", &decisao);
    if(decisao == 'S' || 's'){
        do{
            int indice, quantidade;
            printf("Qual o indice do produto que deseja adicionar ao estoque?\n");
            scanf("%d", &indice);
            printf("Qual a quantidade de produtos que deseja adicionar ao estoque?\n");
            scanf("%d", &quantidade);
            produto[indice - 1] += quantidade;
            printf("Produto adicionado com sucesso!\n");
            printf("Deseja adicionar mais algum produto?\n");
            scanf(" %c", &decisao);
        }while(decisao == 'S' || decisao =='s');
    }
    else if(escolha == 'N' || escolha == 'n'){
        printf("Nenhuma comprar realizada");
    }
    else{
        printf("Escolha inválida, escolha Y ou N");
    }
    printf("Novo estado do estoque: \n");
    for(int i = 0; i < qtd; i++){
        printf("produto de indice %d com %d unidades\n", i + 1, produto[i]);
    }
};

int main(){

    int produtos[10];
    Estoque(produtos, 10);
    return 0;
}