#include <stdio.h>

void Teatro(int fileira, int assento, int reserva[fileira][assento]){
    printf("Disponibilidade dos assentos:\n");
    for(int i = 0; i < fileira; i++){
        printf("Fileira %02d: ", i + 1);
        for(int j = 0; j < assento; j++){
            reserva[i][j] = 0;
            printf("%02d[ ] ", j + 1);
        }
        printf("\n");
    }
    
    char decisao;
    printf("Deseja reservar algum assento?(Digite S para sim e N para nao)\n");
    scanf(" %c", &decisao);
    if(decisao == 'S' || decisao == 's' ){
            do{
                int Fu, Au;
                printf("Qual fileira você quer reservar?\n");
                scanf("%d", &Fu);
                printf("Qual assento da fileira %d você quer reservar?\n", Fu);
                scanf("%d", &Au);
                if(reserva[Fu - 1][Au - 1] == 0){
                    reserva[Fu - 1][Au - 1] = 1;
                }
                else{
                    printf("Reserva inválida, selecione outro assendo.\n");
                }
                printf("Deseja reservar outro assento?\n");
                scanf(" %c", &decisao);
            } while (decisao == 'S' || decisao == 's');
    }
    else if(decisao == 'N' || decisao == 'n'){
        printf("Nenhum assento reservado\n");
    }
    else{
        printf("Escolha inválida(apenas S ou N)\n");
    }
    for(int i = 0; i < fileira; i++){
        printf("Fileira %02d: ", i + 1);
        for(int j = 0; j < assento; j++){
            if(reserva[i][j] == 0){
                printf("%02d[ ] ", j + 1);
            }
            else{
                printf("%02d[X] ", j + 1);
            }
        }
        printf("\n");
    }
}

int main(){
    int reserva[15][20];
    Teatro(15, 20, reserva);
    return 0;
}