#include <stdio.h>

struct Carro{
    char modelo[50];
    int ano;
    char cor[30];
};

void imprimirCarro(struct Carro c){
    printf("INFORMAÇÕES DO VEÍCULO:\n");
    printf("MODELO: %s\nANO: %d\nCOR: %s\n", c.modelo, c.ano, c.cor);
}

int main(){
    struct Carro car1 = {"Fusca", 1950, "Branco"};
    imprimirCarro(car1);
    return 0;
}