#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#define ROWS 2
#define COLS 3
#define MAX_NAME_SZ 256
void FazMatriz();

int main(void)
{   
    char *name = malloc(MAX_NAME_SZ);
    if (name == NULL) {
        printf("No memory\n");
        return 1;
    }

    /* Ask user for name. */

    printf("What is your name? ");

    /* Get the name, with size limit. */

    fgets(name, MAX_NAME_SZ, stdin);

    /* Remove trailing newline, if there. */

    if ((strlen(name) > 0) && (name[strlen (name) - 1] == '\n'))
        name[strlen (name) - 1] = '\0';

    /* Say hello. */

    printf("Hello %s. Nice to meet you.\n", name);

    /* Free memory and exit. */

    free (name);
    return 0;
}

void FazMatriz()
{
    int num=1;
    /* Fazendo a matriz:
       Cria um ponteiro de ponteiro com o tamanho de linhas,
       Depois dentro de cada linha, aloca o espaço dos elementos (colunas)  */
    int **matriz = (int **)  malloc(ROWS * sizeof(int *) );
    for(int i=0; i<ROWS;i++)
    {   matriz[i] = (int *)  malloc(COLS * sizeof(int) );    }

    /* Para adicionar os elementos dentro da matriz,
       For aninhados de Linha depois Coluna*/
    for(int i=0; i<ROWS;i++)
    {   for(int j=0; j<COLS; j++)
        {
            matriz[i][j] = num;
            num++;
        }
    }

    /* Para printar na tela é bem semelhante a inserir elementos,
       Desta vez é só usar o printf */
    for(int i=0; i<ROWS;i++)
    {
        for(int j=0; j<COLS; j++)
        {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
    

    /* No final temos que liberar o espaço alocado dos ponteiros,
       Primeiro liberar os ponteiros das linhas, depois o ponteiro da matriz  */
    for(int i=0; i<ROWS;i++)
    {   free(matriz[i]);    }
    free(matriz);

}

int random_number(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}