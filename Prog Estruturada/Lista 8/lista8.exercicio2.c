#include <stdio.h>
#include <stdlib.h>

typedef struct Matriz // Sei que nao ta 100% legal mas pensei em fazer a validação após a conconlusão do programa, depois irei ajeitar
{
    int ROWS;
    int COLS;
}Matriz;

int main(void)
{
    Matriz mA,mB;
    int ROWS, COLS;
    int **matrizA, **matrizB, **matrizC;

    // Inicializando e Inserindo a matriz A
    printf("Defina suas Linhas e Colunas da Matriz A: ");
    scanf("%d %d",&ROWS,&COLS);
    mA.COLS = COLS; mA.ROWS=ROWS; 
    matrizA = (int **)  malloc(ROWS * sizeof(int *) );
    for(int i=0; i<ROWS;i++)
    {   matrizA[i] = (int *)  malloc(COLS * sizeof(int) );    }

    for(int i=0; i<ROWS;i++)
    {   for(int j=0; j<COLS; j++)
        {
            printf("Matriz[%d][%d]: ",i,j);
            scanf("%d",&matrizA[i][j]);
        }
    }

    // Inicializando e Inserindo a matriz B
    printf("Defina suas Linhas e Colunas da Matriz B: ");
    scanf("%d %d",&ROWS,&COLS);
    mB.COLS = COLS; mB.ROWS=ROWS;
    matrizB = (int **)  malloc(ROWS * sizeof(int *) );
    for(int i=0; i<ROWS;i++)
    {   matrizB[i] = (int *)  malloc(COLS * sizeof(int) );    }

    for(int i=0; i<ROWS;i++)
    {   for(int j=0; j<COLS; j++)
        {
            printf("Matriz[%d][%d]: ",i,j);
            scanf("%d",&matrizB[i][j]);
        }
    }

    //Mostrando as Matrizes antes da soma
    printf("Matriz A\n");
    for(int i=0; i<ROWS;i++)
    {
        for(int j=0; j<COLS; j++)
        {
            printf("%d ",matrizA[i][j]);
        }
        printf("\n");
    }   printf("\n");

    printf("Matriz B\n");
    for(int i=0; i<ROWS;i++)
    {
        for(int j=0; j<COLS; j++)
        {
            printf("%d ",matrizB[i][j]);
        }
        printf("\n");
    }   printf("\n");

    //Realizando a Soma
    if ( (mA.ROWS == mB.ROWS) && ((mA.COLS == mB.COLS)) )
    {   matrizC = (int **)  malloc(ROWS * sizeof(int *) );
        for(int i=0; i<ROWS;i++)
        {   matrizC[i] = (int *)  malloc(COLS * sizeof(int) );    }
        for(int i=0; i<ROWS;i++)
        {
            for(int j=0; j<COLS; j++)
            {
            matrizC[i][j] = matrizA[i][j] + matrizB[i][j]; 
            }
        }

        printf("Matriz C\n");
        for(int i=0; i<ROWS;i++)
        {
            for(int j=0; j<COLS; j++)
            {
                printf("%d ",matrizC[i][j]);
            }
            printf("\n");
        }
    }
    else { printf("Nao foi possivel realizar a soma poisa Ordem das matrizes sao diferentes\n"); }

    return 0;
}
