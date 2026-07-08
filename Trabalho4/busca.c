#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    long codigoIbge;
    int linha;
} IndiceIbge;

IndiceIbge* indices = NULL;
int totalRegistros = 0;

void carregarDados(const char* nomeArquivo);
int buscaBinaria(long ibgeProcurado);
int buscaSequencial(long ibgeProcurado);
void exibirDetalhes(const char* nomeArquivo, int linhaAlvo);
void liberarMemoria();

int main(){
    int opcao;
    long ibgeProcurado;
    const char* arquivo = "ibge.csv";

    do{
        printf("\n========MENU========\n");
        printf("1. Carregar dados\n");
        printf("2. Consultar municipio\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao:\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                carregarDados(arquivo);
            case 2:
                if(totalRegistros == 0){
                    printf("Carregue os dados primeiros!(opcao 1)\n");
                    break;
                }
                printf("Digite o codigo do IBGE:\n");
                scanf("%ld", &ibgeProcurado);

                //medindo busca binaria
                clock_t inicioBin = clock();
                int linhaBin = buscaBinaria(ibgeProcurado);
                clock_t fimBin = clock();
                double tempoBin = ((double)(fimBin - inicioBin)) / CLOCKS_PER_SEC;

                //busca binaria
                clock_t inicioSeq = clock();
                int linhaSeq = buscaSequencial(ibgeProcurado);
                clock_t fimSeq = clock();
                double tempoSeq = ((double)(fimSeq - inicioSeq)) / CLOCKS_PER_SEC;
                if (linhaBin != -1) {
                    exibirDetalhes(arquivo, linhaBin);
                    printf("\nTempo Busca Binaria: %f segundos\n", tempoBin);
                    printf("Tempo Busca Sequencial: %f segundos\n", tempoSeq);
                } else {
                    printf("Municipio nao encontrado.\n");
                }
                break;
                case 3:
                    liberarMemoria();
                    printf("Saindo e limpando a memoria...\n");
                    break;
                default:
                    printf("Opcao invalida!\n");
        }
    }while(opcao != 3);
    return 0;
}

void carregarDados(const char* nomeArquivo) {
    FILE *file = fopen(nomeArquivo, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    liberarMemoria();

    indices = (IndiceIbge*) malloc(6000 * sizeof(IndiceIbge));
    totalRegistros = 0;

    char linhaBuffer[1024];
    int numeroLinha = 0;

    while (fgets(linhaBuffer, sizeof(linhaBuffer), file) != NULL) {
        if (numeroLinha == 0) {
            numeroLinha++;
            continue;
        }

        char linhaCopia[1024];
        strcpy(linhaCopia, linhaBuffer);

        char* token = strtok(linhaCopia, ";");
        
        if (token != NULL) {
            token = strtok(NULL, ";");
            if (token != NULL) {
                long ibgeExtraido = atol(token);
                
                indices[totalRegistros].codigoIbge = ibgeExtraido;
                indices[totalRegistros].linha = numeroLinha;
                
                totalRegistros++; 
            }
        }
        numeroLinha++;
    }
    fclose(file); 
    printf("Dados carregados com sucesso! %d municipios registrados na memoria.\n", totalRegistros);
}