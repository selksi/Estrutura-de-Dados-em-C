#include <stdio.h>

int main(){
    int predio[5][10][24];
    for(int andar = 0; andar < 5; andar++) {
        for(int sala = 0; sala < 10; sala++) {
            for(int hora = 0; hora < 24; hora++) {
                int bagunca = (andar * 7) + (sala * 13) + (hora * 17);
                predio[andar][sala][hora] = (bagunca % 21) + 15; 
                
            }
        }
    }
    printf("Qual andar você deseja consultar?\n");
    int aU, sU;
    scanf("%d", &aU);
    printf("Qual sala você deseja consultar?\n");
    scanf("%d", &sU);

    if((aU >= 1 && aU <= 5) && (sU >=1 && sU <= 10)){
        for(int hora = 0; hora < 24; hora++){
            printf("Hora %02d:00 -> %d graus\n", hora, predio[aU - 1][sU - 1][hora]);
        }
    }
    else{
        printf("Andar ou Sala inválidos!\n");
    }
    printf("MEDIA DE TEMPERATUDA DE CADA ANDAR:\n");
    for(int andar = 0; andar < 5; andar++){
        int leituras = 10 * 24;
        int soma_andar = 0;
        for(int sala = 0; sala < 10; sala++){
            for(int hora = 0; hora < 24; hora++){
                soma_andar += predio[andar][sala][hora];
            }
        }
        float media = (float)soma_andar / leituras;
        printf("Andar %d: %.2f graus\n", andar + 1, media);
    }
    return 0;
}