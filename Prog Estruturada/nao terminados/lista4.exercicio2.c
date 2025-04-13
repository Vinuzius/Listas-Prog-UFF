#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define S 10
#define R 5
int random_number(int min, int max); 
int Busca_Binaria_Recurssiva(int vetor[],int elem, int esquerda, int direita);

int main(void)
{   
    srand(time(NULL)); // Definir o tempo pro random

    int *vetor, *vetor2,*vetor3 ; //Iniciando um vetor com 10 elementos
    int cont=0,validador;
    vetor  = (int *) malloc(sizeof(int)* S);
    vetor2 = (int *) malloc(sizeof(int)* R);
    vetor3 = (int *) malloc(sizeof(int));

    for(int i=0; i<S;i++) // Inicializando vetor 1
        vetor[i]= random_number(0,10); // Randomizando para poupar tempo do teste

    for(int i=0; i<R;i++) // Inicializando vetor 2
        vetor2[i]= random_number(0,10); // Randomizando para poupar tempo do teste

    printf("....Vetor S: \n");
    for(int i=0; i<S;i++)
        printf("|n%.2d:  %.2d|\n",i+1,vetor[i]);
    printf("..........\n\n");

    printf("....Vetor R: \n");
    for(int i=0; i<R;i++)
        printf("|n%.2d:  %.2d|\n",i+1,vetor2[i]);
    printf("..........\n\n");

    for(int i=0; i<S; i++)
    {
        for(int j = 0; j < R; j++)
        {
            if(vetor[i]==vetor2[j])
            {
                validador = Busca_Binaria_Recurssiva(vetor3,vetor2[j],0,cont);
                if(cont == 0)
                {
                    vetor3[cont] = vetor2[j];
                    cont++;   
                }
                else if( (cont >=1) && (validador == -1) )
                {
                    vetor3 = realloc(vetor3, (sizeof(int) * (cont+1)) ); 
                    vetor3[cont] = vetor2[j];
                    cont++;
                }
            }
        }        
    }

    if(cont == 0)
        printf("Nao tem elemento em comum para formar o vetor X.\n\n");

    else
    {
        int k=0;
        printf("....Vetor X: \n");
        do
        {
            printf("|n%.2d:  %.2d|\n",k+1,vetor3[k]);
            k++;
        } while (k<(cont-1));
            
        printf("..........\n\n");
    }

    free(vetor);  free(vetor2);  free(vetor3);  
    return 0;
}

int random_number(int min, int max) 
{
    return (rand() % (max - min + 1)) + min;
}

int Busca_Binaria_Recurssiva(int vetor[],int elem, int esquerda, int direita)
{
    int meio = esquerda + ((direita  - esquerda) / 2);

    if(esquerda > direita)
        return -1;

    if(vetor[meio] == elem)
        return meio;
    
    else if(vetor[meio] > elem)
        return Busca_Binaria_Recurssiva(vetor, elem, esquerda, (meio-1) );
    
    else if(vetor[meio] < elem)
        return Busca_Binaria_Recurssiva(vetor, elem, (meio+1), direita);
}