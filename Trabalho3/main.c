#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"

void reset(TTemperaturas *temperaturas);
void inserirMedida(TTemperaturas *temperaturas);
void estatistica(TTemperaturas temperaturas);
void sair(TTemperaturas *temperaturas);

int main() {
    TTemperaturas temperaturas;
    int opcao;

    temperaturas.qtde_dias = 0;
    temperaturas.qtde_medidas = 0;
    temperaturas.medidas = NULL;

    do {
        printf("\n1 - Reset\n");
        printf("2 - Inserir medida\n");
        printf("3 - Estatistica\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                reset(&temperaturas);
                break;
            case 2:
                inserirMedida(&temperaturas);
                break;
            case 3:
                estatistica(temperaturas);
                break;
            case 4:
                sair(&temperaturas);
                break;
            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 4);

    return 0;
}

void reset(TTemperaturas *temperaturas) {
    if (temperaturas->medidas != NULL) {
        for (int i = 0; i < temperaturas->qtde_medidas; i++) {
            free(temperaturas->medidas[i].temperatura);
        }

        free(temperaturas->medidas);
    }

    printf("Digite a quantidade de dias: ");
    scanf("%d", &temperaturas->qtde_dias);

    while (temperaturas->qtde_dias <= 0) {
        printf("Quantidade invalida. Digite novamente: ");
        scanf("%d", &temperaturas->qtde_dias);
    }

    temperaturas->qtde_medidas = 0;

    temperaturas->medidas = calloc(temperaturas->qtde_dias, sizeof(TMedidas));

    if (temperaturas->medidas == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    printf("Reset realizado com sucesso.\n");
}

void inserirMedida(TTemperaturas *temperaturas) {
    if (temperaturas->medidas == NULL) {
        printf("Erro: execute o reset antes de inserir medidas.\n");
        return;
    }

    if (temperaturas->qtde_medidas >= temperaturas->qtde_dias) {
        printf("Nao ha espaco para inserir novas medidas.\n");
        return;
    }

    int posicao = temperaturas->qtde_medidas;

    printf("Digite o nome da cidade: ");
    scanf(" %19[^\n]", temperaturas->medidas[posicao].cidade);

    temperaturas->medidas[posicao].temperatura = malloc(sizeof(float));

    if (temperaturas->medidas[posicao].temperatura == NULL) {
        printf("Erro ao alocar memoria para temperatura.\n");
        exit(1);
    }

    printf("Digite a temperatura: ");
    scanf("%f", temperaturas->medidas[posicao].temperatura);

    temperaturas->qtde_medidas++;

    printf("Medida inserida com sucesso.\n");
}

void estatistica(TTemperaturas temperaturas) {
    if (temperaturas.medidas == NULL) {
        printf("Erro: execute o reset antes de ver as estatisticas.\n");
        return;
    }

    if (temperaturas.qtde_medidas == 0) {
        printf("Nenhuma medida cadastrada.\n");
        return;
    }

    float soma = 0;

    int indice_menor = 0;
    int indice_maior = 0;

    float menor = *(temperaturas.medidas[0].temperatura);
    float maior = *(temperaturas.medidas[0].temperatura);

    for (int i = 0; i < temperaturas.qtde_medidas; i++) {
        float temp_atual = *(temperaturas.medidas[i].temperatura);

        soma += temp_atual;

        if (temp_atual < menor) {
            menor = temp_atual;
            indice_menor = i;
        }

        if (temp_atual > maior) {
            maior = temp_atual;
            indice_maior = i;
        }
    }

    float media = soma / temperaturas.qtde_medidas;

    printf("\n===== Estatisticas =====\n");
    printf("Temperatura media: %.2f\n", media);

    printf("Menor temperatura: %.2f - Cidade: %s\n",
           menor,
           temperaturas.medidas[indice_menor].cidade);

    printf("Maior temperatura: %.2f - Cidade: %s\n",
           maior,
           temperaturas.medidas[indice_maior].cidade);
}

void sair(TTemperaturas *temperaturas) {
    if (temperaturas->medidas != NULL) {
        for (int i = 0; i < temperaturas->qtde_medidas; i++) {
            free(temperaturas->medidas[i].temperatura);
            temperaturas->medidas[i].temperatura = NULL;
        }

        free(temperaturas->medidas);
        temperaturas->medidas = NULL;
    }

    temperaturas->qtde_dias = 0;
    temperaturas->qtde_medidas = 0;

    printf("Memoria desalocada. Encerrando o programa...\n");
}

