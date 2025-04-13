#include <stdio.h>
#include <stdlib.h>

int main(void)
{    
    int ROWS, COLS, compara =0, aux=0, igual = 0;
    int **matriz;

    // Inicializando a matriz
    printf("Defina suas Linhas e Colunas: ");
    scanf("%d %d",&ROWS,&COLS);
    matriz = (int **)  malloc(ROWS * sizeof(int *) );
    for(int i=0; i<ROWS;i++)
    {   matriz[i] = (int *)  malloc(COLS * sizeof(int) );    }

    //Inserindo Valores na Matriz
    for(int i=0; i<ROWS;i++)
    {   for(int j=0; j<COLS; j++)
        {
            printf("Matriz[%d][%d]: ",i,j);
            scanf("%d",&matriz[i][j]);
        }
    }

    //Comparando as Linhas
    for(int j=0; j<COLS; j++) // Primeira Comparação
        {
            compara += matriz[0][j];
        }
    
    for(int i=0; i<ROWS;i++) // Restante das comparações
    {   
        for(int j=0; j<COLS; j++)
        {
            aux+= matriz[i][j];
        }
        
        if (aux != compara) 
        {
            igual = 1;
            break; // Se uma já for diferente pode acabar
        }
        aux = 0;    
    }

    //Resposta
    if(igual == 0) {printf("A soma de todas as linhas sao iguais");}
    else {printf("Nao tem as somas de linhas iguais");}
        
    //Liberando espaço dos ponteiros
    for(int i=0; i<ROWS;i++)
    {   free(matriz[i]);    }
    free(matriz);
    return 0;
}
