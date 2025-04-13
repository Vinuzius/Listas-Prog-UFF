#include <stdio.h>
#include <stdlib.h>

typedef struct Matriz
{
    int ROWS;
    int COLS;
    int **m;
}Matriz;

void PrintMatriz(Matriz *m);
void InputMatriz (Matriz *m);
void MallocMatriz(Matriz *m);
void Transposta(Matriz *mA, Matriz *mT);
void FreeMatriz(Matriz *m);
int Simetrica(Matriz *mA, Matriz *mT);
int main(void)
{
    Matriz *mA,*mT;
    mA = (Matriz*) malloc(sizeof(Matriz) );
    mT = (Matriz*) malloc(sizeof(Matriz) );

    // Inicializando e Inserindo a matriz A
    printf("Defina suas Linhas e Colunas da Matriz A: ");
    scanf("%d %d",&mA->ROWS,&mA->COLS);
    MallocMatriz(mA);
    InputMatriz(mA); printf("Matriz A: \n");   
    PrintMatriz(mA); printf("\n");

    //Inicializando Matriz Transposta 
    mT->ROWS = mA->COLS;    mT->COLS = mA->ROWS;
    MallocMatriz(mT);
    Transposta(mA,mT);
    printf("Transposta da Matriz A: \n"); PrintMatriz(mT);

    //Simetrica
    int Simetria = Simetrica(mA,mT);

    if(Simetria == 0) printf("\nEstas matrizes sao simetricas.");
    else printf("\nEstas matrizes nao sao simetricas.");

    //Liberando Matrizes
    FreeMatriz(mA); FreeMatriz(mT);    
    return 0;
}

int Simetrica(Matriz *mA, Matriz *mT)
{
    for (int i=0; i< (mA->ROWS); i++)
    {   for (int j=0; j< (mA->COLS);j++)
        {
            if ( (mA->m[i][j]) != mT->m[i][j] )
            {
                return 1;
            }            
        }
    }
    return 0;
}
void PrintMatriz(Matriz *m)
{   
    for(int i=0; i<(m->ROWS);i++)
    {   for(int j=0; j<(m->COLS); j++)
        {
            printf("%d ",(m->m[i][j]) );
        }printf("\n");
    }
}
void InputMatriz (Matriz *m)
{
    for(int i=0; i< (m->ROWS);i++)
    {   for(int j=0; j< (m->COLS); j++)
        {
            printf("Matriz[%d][%d]: ",i,j);
            scanf("%d",(&m->m[i][j]) );
        }
    }
}
void MallocMatriz(Matriz *m)
{    
    m->m = (int **)  malloc( (m->ROWS) * sizeof(int *) );
    if((m->m)==NULL) { exit(1); }
    for(int i=0; i< (m->ROWS);i++)
    {   (m->m[i]) = (int *)  malloc( (m->COLS) * sizeof(int) );
        if((m->m[i])==NULL) { exit(1); }}    
}
void FreeMatriz(Matriz *m)
{
    if ( (m->m) != NULL)
    {
        for (int i=0; i< (m->ROWS); i++)
            { if((m->m[i]) != NULL) {  free( (m->m[i]) );  }  }
    }
    free( (m->m) ); 
}
void Transposta(Matriz *mA, Matriz *mT)
{
    for (int i = 0; i < (mT->ROWS); i++)
    {
        for (int j = 0; j < (mT->COLS); j++)
        {
            mT->m[j][i] = mA->m[i][j];
            
        }     
    }
}