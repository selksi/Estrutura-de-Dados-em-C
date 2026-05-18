#include <stdio.h>
#include <string.h>

struct Pessoa{
    char nome[50];
    int idade;
    float altura;
};

int main(){
    struct Pessoa pessoa1 = {"João", 25, 1.80};

    printf("Nome: %s\nIdade: %d\nAltura: %.02f\n", pessoa1.nome, pessoa1.idade, pessoa1.altura);
    
    pessoa1.idade = 26;
    pessoa1.altura = 1.81;
    
    printf("\n");
    printf("PARAMêTROS ATUALIZADOS:\n");
    printf("Nome: %s\nIdade: %d\nAltura: %.02f\n", pessoa1.nome, pessoa1.idade, pessoa1.altura);

    return 0;
}