#include <stdio.h>

struct Aluno{
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
};

int main(){
    struct Aluno turma[3] = {
        {"Julia Rosa", 10.0, 5.5, 8.7},
        {"Samuel Carvalho", 3.8, 7.6, 4.9},
        {"Julian Casablancas", 2.6, 4.4, 2.2}

    };

    for(int i = 0; i < 3; i++){
        float soma = turma[i].nota1 + turma[i].nota2 + turma[i].nota3;
        float media = soma / 3.0;
        printf("Media do aluno(a) %s: %.02f\n", turma[i].nome, media);
    }
    return 0;
}