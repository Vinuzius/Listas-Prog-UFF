#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>

#define ROWS 2
#define COLS 3
#define MAX_NAME_SZ 256

void FazMatriz();
char *GetName(char *name);
void bubble_sort(int a[],int length);
int Busca_Binaria(int n, int* vet, int elem);
int Busca_Binaria_Recurssiva(int vetor[],int elem, int esquerda, int direita);

int main(void)
{   
    //char *name; name = GetName(name);
    //int lista[13]= {12,1,3,7,13,2,4,10,9,5,8,6,11}, tamanho = 13; 
    //bubble_sort(lista,tamanho);
    //int num = Busca_Binaria_Recurssiva(lista,3,0,12);

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

char *GetName(char *name)
{
    name = malloc(MAX_NAME_SZ);
    if (name == NULL) {
        printf("No memory\n");
        exit(1);
    }
    
    printf("What is your name? ");
    fgets(name, MAX_NAME_SZ, stdin); /* Get the name, with size limit. */

    /* Remove trailing newline, if there. */
    if ((strlen(name) > 0) && (name[strlen (name) - 1] == '\n'))
        name[strlen (name) - 1] = '\0';
    /* Free memory and exit. */
    //free (name);
    return name;
}

void bubble_sort(int a[],int length)
{
    //Vai passar pela lista e trocar os numeros que estiverem fora de ordem
    
    int i=0,teste=1;
    do 
    {
        teste = 1;
        /* Ao final da passada o ultimo membro já vai estar alocado no lugar certo.
           Então diminui o tamanho da passada. */
        for (int j = 0; j < (length - 1 - i); j++)
        {
        // Pode ser descendente ou crescente dependendo do < >;.
            if (a[j] > a[j + 1])
            {   //Vai trocar os elementos com ajuda de um auxiliar.
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                teste = 0;
            } 
        }
        i++;
    } while ( teste == 0 );
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



int Busca_Binaria(int n, int* vet, int elem)
{
    // Primeira Loop vai ver o vetor todo (vetor ordenado)
    int ini = 0;
    int fim = n-1;

    while (ini <= fim) 
    {
        int meio = (ini + fim) / 2;
        if (elem < vet[meio]) // Se o meio do vetor for maior, então ajusta a posição da direita
            fim = meio - 1;
        else if (elem > vet[meio]) // Se for menor, então ajusta a posição da esquerda
            ini = meio + 1;
        else
            return meio; // Caso seja igual retorna o Índice do elemento.
    }
    
    //Caso passe por todo vetor e não encontre, irá retornar -1
    return -1;
}

