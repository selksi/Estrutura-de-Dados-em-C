#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//DADOS
typedef struct Cadastro{
    char CNPJ[15];
    char RazaoSocial[50];
    char Cidade[30];
    char Fone[12];
} TCadastro;

//LISTA INDUSTRIA
typedef struct NoI{
    TCadastro *Dados;
    struct No1 *Prox;
}TNoI;

//LISTA COMERCIO
typedef struct NoC{
    TCadastro *Dados;
    struct NoC *Ant;
    struct Noc *Prox;
}TNoC;

//LISTA SERVICOS
typedef struct NoS{
    TCadastro *Dados;
    struct NoS *Ant;
    struct Nos *Prox;
}TNoS;
typedef struct DescritorS{
    TNoS *inicio;
    int Tamanho;
    TNoS *Fim;
}TDescritorS;

//CADASTRO UNIFICADO E SUA LISTA

typedef struct CadastroU{
    char CNPJ[15];
    char RazaoSocial[50];
    char Cidade[30];
    char Fone[12];
    char Tipo;
}TCadastroU;

typedef struct NoU{
    TCadastroU *Dados;
    struct NoU *Ant;
    struct NoU * Prox;
}TNoU;
typedef struct DescritorU{
    TNoU *inicio;
    int tamanho;
    TNoU *Fim;
}TDescritorU;

void carregarDadosEntrada(TNoI **listaI, TNoC **listaC, TDescritorS *ListaS);
void gerarListaUnificada(TNoI *listaI, TNoC *listaC, TDescritorS *listaS, TDescritorU *listaU);
void relatorioIndustrias(TNoI *listaI);
void relatorioComercio(TNoC *listaC);
void relatorioComercioInvertido(TNoC *listaC);
void relatorioServicos(TDescritorS *listaS);
void relatorioServicosInvertido(TDescritorS *listaS);
void relatorioUnificada(TDescritorU *listaU);
void relatorioUnificadaInvertido(TDescritorU *listaU);

void apagarListas(TNoI **listaI, TNoC **listaC, TDescritorS *listaS, TDescritorU *listaU);

int main(){
    // 1. Inicializando as âncoras das listas vazias
    TNoI *inicioIndustria = NULL;
    TNoC *inicioComercio = NULL;

    // 2. Alocando a caixa do Descritor de Serviços na memória
    TDescritorS *descritorServicos = (TDescritorS*) malloc(sizeof(TDescritorS));
    descritorServicos->inicio = NULL;
    descritorServicos->Fim = NULL;
    descritorServicos->Tamanho = 0;

    // 3. Alocando a caixa do Descritor da Lista Unificada (Para usar depois)
    TDescritorU *listaUnificada = (TDescritorU*) malloc(sizeof(TDescritorU));
    listaUnificada->inicio = NULL;
    listaUnificada->Fim = NULL;
    listaUnificada->tamanho = 0;
    int opcao;

    do{
        printf("DIGITE O NUMERO EQUIVALENTE A SUA FUNCIONALIDADE:\n");
        printf("1. Carregar Dados de Entrada\n"
            "2. Gerar Lista Unificada\n" 
            "3. Relatório: Industrias\n"
            "4. Relatório: Comércio\n"
            "5. Relatório: Comércio Invertida\n" 
            "6. Relatório: Serviços\n" 
            "7. Relatório: Serviços Invertida\n" 
            "8. Relatório: Lista Unificada\n"
            "9. Relatório: Lista Unificada Invertida\n" 
            "10. Apagar Listas\n" 
            "0. Sair\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
            printf("Carregando arquivos de entrada\n");
            carregarDadosEntrada(&inicioIndustria, &inicioComercio, descritorServicos);
            break;

            case 2:
            printf("Gerando lista unificada\n");
            gerarListaUnificada(inicioIndustria, inicioComercio, descritorServicos, listaUnificada);
            break;

            case 3:
            printf("\n--- Relatorio: Industrias ---\n");
            relatorioIndustrias(inicioIndustria);
            break;

            case 4:
            printf("\n--- Relatorio: Comercio ---\n");
            relatorioComercio(inicioComercio);
            break;

           case 5:
            printf("\n--- Relatorio: Comercio Invertido ---\n");
            relatorioComercioInvertido(inicioComercio);
            break;

            case 6:
            printf("\n--- Relatorio: Servicos ---\n");
            relatorioServicos(descritorServicos);
            break;

            case 7:
            printf("\n--- Relatorio: Servicos Invertido ---\n");
            relatorioServicosInvertido(descritorServicos);
            break;

            case 8:
            printf("\n--- Relatorio: Lista Unificada ---\n");
            relatorioUnificada(listaUnificada);
            break;

            case 9:
            printf("\n--- Relatorio: Lista Unificada Invertida ---\n");
            relatorioUnificadaInvertido(listaUnificada);
            break;

            case 10:
            apagarListas(&inicioIndustria, &inicioComercio, descritorServicos, listaUnificada);
            printf("Apagando listas da memoria\n");
            break;

            case 0:
            printf("Saindo do programa\n");
            break;
        }
    }while(opcao != 0);

    return 0;
}

void carregarDadosEntrada(TNoI **listaI, TNoC **listaC, TDescritorS *ListaS){
    FILE *arqind = fopen("Industria.txt", "r");
    if(arqind == NULL){
        printf("NÃO FOI POSSIVEL ABRIR O ARQUIVO\n");
        return;
    }
    else{
        char cnpjTemp[15];
        char razaoTemp[50];
        char cidadeTemp[30];
        char foneTemp[12];

        while(fscanf(arqind, " %[^\n]", cnpjTemp) != EOF){
            fscanf(arqind, " %[^\n]", razaoTemp);
            fscanf(arqind, " %[^\n]", cidadeTemp);
            fscanf(arqind, " %[^\n]", foneTemp);

            TNoI *novoNo = (TNoI*) malloc(sizeof(TNoI));
            novoNo->Dados = (TCadastro*) malloc(sizeof(TCadastro)); 

            strcpy(novoNo->Dados->CNPJ, cnpjTemp);
            strcpy(novoNo->Dados->RazaoSocial, razaoTemp);
            strcpy(novoNo->Dados->Cidade, cidadeTemp);
            strcpy(novoNo->Dados->Fone, foneTemp);

            novoNo->Prox = NULL;

            if(*listaI == NULL){
                *listaI = novoNo;
            }
            else{
                TNoI *aux = *listaI;
                while(aux->Prox != NULL){
                    aux = aux->Prox;
                }
                aux->Prox = novoNo;
            }
        }
        fclose(arqind);
        printf("Lista de industria carregada com sucesso\n");
    }
    FILE *arqCom = fopen("Comercio.txt", "r");

    if(arqCom == NULL){
        printf("Nao foi possível abrir o arquiv0\n");
    }
    else{
        char cnpjTemp[15];
        char razaoTemp[50];
        char cidadeTemp[30];
        char foneTemp[12];

        while(fscanf(arqCom, " %[^\n]", cnpjTemp) != EOF){
            fscanf(arqCom, " %[^\n]", razaoTemp);
            fscanf(arqCom, " %[^\n]", cidadeTemp);
            fscanf(arqCom, " %[^\n]", foneTemp);

            TNoC *novoNo = (TNoC*) malloc(sizeof(TNoC));
            novoNo->Dados = (TCadastro*) malloc(sizeof(TCadastro));

            strcpy(novoNo->Dados->CNPJ, cnpjTemp);
            strcpy(novoNo->Dados->RazaoSocial, razaoTemp);
            strcpy(novoNo->Dados->Cidade, cidadeTemp);
            strcpy(novoNo->Dados->Fone, foneTemp);
            
            if(*listaC == NULL){
                novoNo->Prox = novoNo;
                novoNo->Ant = novoNo;
                *listaC = novoNo;
            }
            else{
                TNoC *primeiro = *listaC;
                TNoC *ultimo = primeiro->Ant;

                ultimo->Prox = novoNo;
                novoNo->Ant = ultimo;

                novoNo->Prox = primeiro;
                primeiro->Ant = novoNo;
            }
        }
        fclose(arqCom);
        printf("Lista do comercio carregada com sucesso\n");
    }

    FILE *arqSer = fopen("Servico.txt", "r");
    if(arqSer == NULL){
        printf("Nao foi possivel abrir o arquivo\n");
    }
    else{
        char cnpjTemp[15];
        char razaoTemp[50];
        char cidadeTemp[30];
        char foneTemp[12];

        while (fscanf(arqSer, " %[^\n]", cnpjTemp) != EOF){
            fscanf(arqSer, " %[^\n]", razaoTemp);
            fscanf(arqSer, " %[^\n]", cidadeTemp);
            fscanf(arqSer, " %[^\n]", foneTemp);

            TNoS *novoNo = (TNoS*) malloc(sizeof(TNoS));
            novoNo->Dados = (TCadastro*) malloc(sizeof(TCadastro));

            strcpy(novoNo->Dados->CNPJ, cnpjTemp);
            strcpy(novoNo->Dados->RazaoSocial, razaoTemp);
            strcpy(novoNo->Dados->Cidade, cidadeTemp);
            strcpy(novoNo->Dados->Fone, foneTemp);

            novoNo->Prox = NULL;
            if(ListaS->inicio == NULL){
                ListaS->inicio = novoNo;
                ListaS->Fim = novoNo;
                ListaS->Tamanho = 1;
            }
            else{
                novoNo->Ant = ListaS->Fim;
                ListaS->Fim->Prox = novoNo; 
                ListaS->Fim = novoNo;
                ListaS->Tamanho ++;
            }
        }
    fclose(arqSer);
    printf("Lista de serviço gerada com sucesso\n");
    }
}

void inserirNaUnificada(TDescritorU *listaU, TCadastro *dadosOriginais, char tipoEmpresa){
    TNoU *novoNo = (TNoU*) malloc(sizeof(TNoU));
    novoNo->Dados = (TCadastroU*) malloc(sizeof(TCadastroU));

    strcpy(novoNo->Dados->CNPJ, dadosOriginais->CNPJ);
    strcpy(novoNo->Dados->RazaoSocial, dadosOriginais->RazaoSocial);
    strcpy(novoNo->Dados->Cidade, dadosOriginais->Cidade);
    strcpy(novoNo->Dados->Fone, dadosOriginais->Fone);
    novoNo->Dados->Tipo = tipoEmpresa;

    novoNo->Prox = NULL;

    if(listaU->inicio == NULL){
        novoNo->Ant = NULL;
        listaU->inicio = novoNo;
        listaU->Fim = novoNo;
        listaU->tamanho = 1;
    }
    else{
        novoNo->Ant = listaU->Fim;
        listaU->Fim->Prox = novoNo;

        listaU->Fim = novoNo;
        listaU->tamanho++;
    }
}
void gerarListaUnificada(TNoI *listaI, TNoC *listaC, TDescritorS *listaS, TDescritorU *listaU){
    TNoI *auxI = listaI;
    TNoC *auxC = listaC;
    TNoS *auxS = listaS->inicio; 

    while (auxI != NULL) {
        inserirNaUnificada(listaU, auxI->Dados, 'I');
        auxI = auxI->Prox; 
    }

    if(auxC != NULL){
        do{
            inserirNaUnificada(listaU, auxC->Dados, 'C');
            auxC = auxC->Prox;
        }while (auxC != listaC);
    }

    while (auxS != NULL) {
        inserirNaUnificada(listaU, auxS->Dados, 'S');
        auxS = auxS->Prox; 
    }

}

void relatorioIndustrias(TNoI *listaI){
    if(listaI == NULL){
        printf("LISTA DE INDUSTRIA ESTA VAZIA\n");
        return;
    }

    TNoI *auxI = listaI;

    while(auxI != NULL){
        printf("CNPJ: %s | Nome: %s | Cidade: %s | Fone: %s\n", auxI->Dados->CNPJ, auxI->Dados->RazaoSocial, auxI->Dados->Cidade, auxI->Dados->Fone);
        auxI = auxI->Prox;
    }

    printf("Relatorio de industria impresso\n");
}

void relatorioComercio(TNoC *listaC){
    if(listaC == NULL){
        printf("LISTA DE COMERCIO ESTA VAZIA\n");
        return;
    }

    TNoC *auxC = listaC;

    do{
        printf("CNPJ: %s | Nome: %s | Cidade: %s | Fone: %s\n", auxC->Dados->CNPJ, auxC->Dados->RazaoSocial, auxC->Dados->Cidade, auxC->Dados->Fone);
        auxC = auxC->Prox;
    }while(auxC != listaC);
    printf("Relatorio gerado com sucesso\n");
}

void relatorioComercioInvertido(TNoC *listaC){
    if(listaC == NULL){
        printf("LISTA DE COMERCIO ESTA VAZIA\n");
        return;
    }

    TNoC *auxC = listaC->Ant;

    do{
        printf("CNPJ: %s | Nome: %s | Cidade: %s | Fone: %s\n", auxC->Dados->CNPJ, auxC->Dados->RazaoSocial, auxC->Dados->Cidade, auxC->Dados->Fone);
        auxC = auxC->Ant;
    }while(auxC != listaC->Ant);
    printf("Relatorio gerado com sucesso\n");
}

void relatorioServicos(TDescritorS *listaS){
    if(listaS == NULL){
        printf("LISTA DE SERVICOS VAZIA\n");
        return;
    }

    TNoS *auxS = listaS->inicio;

    while(auxS != NULL){
        printf("CNPJ: %s | Nome: %s | Cidade: %s | Fone: %s\n", auxS->Dados->CNPJ, auxS->Dados->RazaoSocial, auxS->Dados->Cidade, auxS->Dados->Fone);
        auxS = auxS->Prox;
    }
    printf("Relatorio gerado com sucesso\n");
}

void relatorioServicosInvertido(TDescritorS *listaS){
    if(listaS->inicio == NULL){
        printf("LISTA DE SERVICOS VAZIA\n");
        return;
    }

    TNoS *auxS = listaS->Fim;

    while(auxS != NULL){
        printf("CNPJ: %s | Nome: %s | Cidade: %s | Fone: %s\n", auxS->Dados->CNPJ, auxS->Dados->RazaoSocial, auxS->Dados->Cidade, auxS->Dados->Fone);
        auxS = auxS->Ant;
    }
    printf("Rlatorio gerado com sucesso\n");
}

void relatorioUnificada(TDescritorU *listaU){
    if(listaU->inicio == NULL){
        printf("LISTA DE UNIFICADA VAZIA\n");
        return;
    }

    TNoU *auxU = listaU->inicio;

    while(auxU != NULL){
        printf("CNPJ: %s | Nome: %s | Cidade: %s | Fone: %s | Tipo de empresa: %c\n", auxU->Dados->CNPJ, auxU->Dados->RazaoSocial, auxU->Dados->Cidade, auxU->Dados->Fone, auxU->Dados->Tipo);
        auxU = auxU->Prox;
    }
    printf("Rlatorio gerado com sucesso\n");
}
void relatorioUnificadaInvertido(TDescritorU *listaU){
    if(listaU->inicio == NULL){
        printf("LISTA UNIFICADA VAZIA\n");
        return;
    }

    TNoU *auxU = listaU->Fim;

    while(auxU != NULL){
        printf("CNPJ: %s | Nome: %s | Cidade: %s | Fone: %s | Tipo de empresa: %c\n", auxU->Dados->CNPJ, auxU->Dados->RazaoSocial, auxU->Dados->Cidade, auxU->Dados->Fone, auxU->Dados->Tipo);
        auxU = auxU->Ant;
    }
    printf("Rlatorio gerado com sucesso\n");
}

void apagarListas(TNoI **listaI, TNoC **listaC, TDescritorS *listaS, TDescritorU *listaU){
    TNoI *auxI = *listaI;
    TNoI *tempI;
    while(auxI != NULL){
        tempI = auxI->Prox;
        if(auxI->Dados != NULL) {
            free(auxI->Dados);
        }
        free(auxI); 
        auxI = tempI; 
    }

    TNoS *auxS = listaS->inicio;
    TNoS *tempS;
    while(auxS != NULL){
        tempS = auxS->Prox;
        if(auxS->Dados != NULL) {
            free(auxS->Dados);
        }
        free(auxS);
        auxS = tempS;
    }
    listaS->inicio = NULL;
    listaS->Fim = NULL;
    listaS->Tamanho = 0;

    TNoU *auxU = listaU->inicio;
    TNoU *tempU;
    while(auxU != NULL){
        tempU = auxU->Prox;
        if(auxU->Dados != NULL) {
            free(auxU->Dados);
        }
        free(auxU);
        auxU = tempU;
    }
    listaU->inicio = NULL;
    listaU->Fim = NULL;
    listaU->tamanho = 0;

    if(*listaC != NULL){
        TNoC *auxC = *listaC;
        TNoC *tempC;
        
        (*listaC)->Ant->Prox = NULL; 
        
        while(auxC != NULL){
            tempC = auxC->Prox;
            if(auxC->Dados != NULL) free(auxC->Dados);
            free(auxC);
            auxC = tempC;
        }
        *listaC = NULL; // Zera a âncora principal
    }

    printf("Todas as listas foram apagadas da memoria com sucesso!\n");
}