#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int maiores(int n, int * vet, int x);
int main(void)
{
    srand(time(NULL)); //seed aleatoria
    int n, *vet,num,i,maior;

    printf("Entre com um número para o vetor, e um para a comparacao: ");
    scanf("%d %d",&n,&num);

    vet = (int *) malloc(n * sizeof(int) ); //alocação dinamica para o vetor
    printf("Numeros do vetor: \n");
    for (i=0;i<n;i++) // Criando numeros aleatorios para o vetor (até 100)
    {
        *(vet+i) = rand() % 100;  // *(v+i) = v[i]
        printf("%d\n",vet[i]);
    }
    maior= maiores(n,vet,num);
    printf("Quantidade dos números do vetor que são maiores do que X: %d",maior);
    free(vet); // liberando espaço de memoria do vetor dinamico
    return 0;
}
int maiores(int n, int * vet, int x)
{
    int i,maior=0;
    for (i=0; i<n ;i++)
    {
        if (vet[i] > x)
        {
            maior++;
        }    
    }
    return maior;
}
