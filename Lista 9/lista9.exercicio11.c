#include <stdio.h>
#include <stdlib.h>
typedef struct Aluno 
{
    int matricula;
    float *vNotas; // Armazena as 5 notas de um aluno ao longo de um ano.
    char nome[100];
}Aluno;

typedef struct Matéria 
{
    Aluno *V; // Armazena a informação de n alunos !!
    float media[5]; // Armazena as 5 médias do ano.
    int nAlunos // Número de alunos matriculados no curso.
}Materia;
//=================//

int main(void)
{
    return 0;
}