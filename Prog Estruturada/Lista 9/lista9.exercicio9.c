#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno
{
    char nome[81];
    float media;
}ALUNO;

void ordena (ALUNO turma[], int tam);
int main(void)
{
    //Criei Uma turma com 4 só para testar
    ALUNO turma[4];
    turma[0].media= 8.6; strcpy(turma[0].nome,"Rodrigo");   turma[1].media= 6.8; strcpy(turma[1].nome,"Luiza" );
    turma[2].media= 9.2; strcpy(turma[2].nome,"Julio"  );   turma[3].media= 2.5; strcpy(turma[3].nome,"Simone");

    //Usando a função e testando para ver se funcionou
    ordena(turma,4);
    printf("Turma ordenada por media: \n");
    for(int i=3;i>=0;i--)
        printf("|Aluno: %-7s ---- Media: %2.2f|\n",turma[i].nome,turma[i].media);
    return 0;
}

void ordena (ALUNO turma[], int tam) 
{
    int i, foraOrdem , jaOrdenados = 0;
    ALUNO temp;
    // Só ajustei i<4 para i<tam 
    do 
    {
        foraOrdem = 0;
        for (i = 0; i < tam - 1 - jaOrdenados ; i++) 
        {
            if (turma[i]. media > turma[i+1]. media) 
            {
                temp = turma[i];
                turma[i] = turma[i+1];
                turma[i+1] = temp ;
                foraOrdem = 1;
            }
        }
        jaOrdenados ++;
    } while ( foraOrdem );
}
