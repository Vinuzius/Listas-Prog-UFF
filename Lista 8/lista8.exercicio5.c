#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Matriz
{
    int ROWS;
    int COLS;
    int **matriz;
}Matriz;

void SomaMatriz(Matriz *mA, Matriz*mB);
void MultiplicaMatriz(Matriz *mA,Matriz *mB,Matriz *mC);
void SomaDiagonal(Matriz *m, int *diagonal);
void InputMatriz (Matriz *m);
void PrintMatriz(Matriz *m);
void MallocMatriz(Matriz *m);
void FreeMatriz(Matriz *m);
int main(void)
{
    srand(time(NULL));
    int diagonal = 0;
    Matriz *mA, *mB,*mC;
    mA = (Matriz*) malloc(sizeof(Matriz) );
    mB = (Matriz*) malloc(sizeof(Matriz) );
    mC = (Matriz*) malloc(sizeof(Matriz) );

    //Inicializando matriz A e B
    printf("Defina as Linhas e Colunas da Matriz A: ");
    scanf("%d %d",&mA->ROWS,&mA->COLS);
    MallocMatriz(mA);
    InputMatriz(mA);

    printf("Defina as Linhas e Colunas da Matriz B: ");
    scanf("%d %d",&mB->ROWS,&mB->COLS);
    MallocMatriz(mB);
    InputMatriz(mB);

    //Operações
    PrintMatriz(mA); PrintMatriz(mB);

        // a) soma destas duas matrizes
    if ( (mA->COLS != mB->COLS) || (mA->ROWS != mB->ROWS)  ) // A soma só é possível se as duas matrizes forem da mesma ordem
    {   printf("Nao foi possivel realizar a soma pois, as ordens das matrizes sao diferentes.\n");    }
    else SomaMatriz(mA,mB); 
    ///////////////////////////
        //b) soma das diagonais de cada matriz
    if (mA->ROWS != mA->COLS)
    {   printf("Nao foi possivel realizar a soma das diagonais da Matriz A pois, a matriz não é Quadrada.\n");  }
    else 
    { SomaDiagonal(mA,&diagonal); printf("Soma das Diagonais de A: %d\n",diagonal);  }
    
    if (mB->ROWS != mB->COLS)
    {   printf("Nao foi possivel realizar a soma das diagonais da Matriz B pois, a matriz não é Quadrada.\n");  }
    else 
    { SomaDiagonal(mB,&diagonal); printf("Soma das Diagonais de B: %d\n",diagonal);  }
    ///////////////////////////
        //c) multiplicação das duas matrizes
    if (mA->COLS != mB->ROWS) // Para a multiplicacao acontecer precisa da coluna de A ser igual a linha de B.
    {   printf("Nao foi possivel realizar a multiplicacao pois, numero de colunas de A e diferente de linhas de B.\n"); }
    else 
    {
        mC->ROWS = mA->ROWS;    mC->COLS= mB->COLS; 
        MallocMatriz(mC);
        MultiplicaMatriz(mA,mB,mC);
        PrintMatriz(mC);
        FreeMatriz(mC);
    }  
    ///////////////////////////
    // Liberando as Matrizes.
    FreeMatriz(mA); FreeMatriz(mB);
    return 0;
}

void MallocMatriz(Matriz *m)
{    
    m->matriz = (int **)  malloc( (m->ROWS) * sizeof(int *) );
    if((m->matriz)==NULL) { exit(1); }
    for(int i=0; i< (m->ROWS);i++)
    {   (m->matriz[i]) = (int *)  malloc( (m->COLS) * sizeof(int) );
        if((m->matriz[i])==NULL) { exit(1); }}    
}
void FreeMatriz(Matriz *m)
{
    if ( (m->matriz) != NULL)
    {
        for (int i=0; i< (m->ROWS); i++)
            { if((m->matriz[i]) != NULL) {  free( (m->matriz[i]) );  }  }
    }
    free( (m->matriz) ); 
}
void InputMatriz (Matriz *m)
{
    srand(time(NULL));
    for(int i=0; i< (m->ROWS);i++)
    {   for(int j=0; j< (m->COLS); j++)
        {
            //m->matriz[i][j] = ((rand() % 10));
            printf("Matriz[%d][%d]: ",i,j);
            scanf("%d",(&m->matriz[i][j]) );
        }
    }
}
void PrintMatriz(Matriz *m)
{   
    for(int i=0; i<(m->ROWS);i++)
    {   for(int j=0; j<(m->COLS); j++)
        {
            printf("%d ",(m->matriz[i][j]) );
        }printf("\n");
    }printf("\n");
}
void SomaMatriz(Matriz *mA, Matriz*mB)
{
    printf("Soma Matriz A + Matriz B: \n");
    for(int i=0; i<(mA->ROWS);i++)
    {   for(int j=0; j<(mA->COLS); j++)
        {
            int soma = (mA->matriz[i][j]) + (mB->matriz[i][j] );
            printf("%d ",soma );
        }printf("\n");
    }
}
void MultiplicaMatriz(Matriz *mA,Matriz *mB,Matriz *mC)
{
    int soma =0;
    printf("\nMultiplicacao A x B\n");
    for(int i=0; i< mA->ROWS; i++)
    {
        for(int j=0; j< mB->COLS; j++)
        {
            for(int k=0; k < mA->COLS; k++)
            {
               soma += ( mA->matriz[i][k] * mB->matriz[k][j] );
            }
            mC->matriz[i][j] = soma;
            soma = 0;
        }
    }
}
void SomaDiagonal(Matriz *m, int *diagonal)
{
    *diagonal=0;
    for(int i=0;i< m->ROWS; i++)
    {
        *diagonal += m->matriz[i][i];        
    }
}