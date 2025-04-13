#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 10
int random_number(int min, int max); 
int main(void)
{   
    srand(time(NULL)); // Definir o tempo pro random

    int *vetor, *vetor2; //Iniciando um vetor com 10 elementos
    vetor = (int *) malloc(sizeof(int)* S);
    vetor2 = (int *) malloc(sizeof(int)* S);

    for(int i=0; i<S;i++) // Inicializando vetor 1
        vetor[i]= random_number(0,50); // Randomizando para poupar tempo do teste

    for(int j=0; j<=S; j++)
        vetor2[j] = vetor[S-1-j]; // o Max sempre será 1 valor a mais que o vetor ent tem que subtrair 1

    printf("....Vetor 1: \n");
    for(int i=0; i<S;i++)
        printf("|n%.2d:  %.2d|\n",i+1,vetor[i]);
    printf("..........\n\n");

    printf("....Vetor 2: \n");
    for(int i=0; i<S;i++)
    printf("|n%.2d:  %.2d|\n",i+1,vetor2[i]);
    printf("..........");

    free(vetor);  free(vetor2);  
    return 0;
}

int random_number(int min, int max) 
{
    return (rand() % (max - min + 1)) + min;
}