#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Multiplica (int vet[],int num);
void Imprime (int vet[],int num);
int main(void)
{
    int *quintuplo, num;

    printf("Entre com um numero: "); scanf("%d",&num);
    quintuplo = (int *) malloc(sizeof(int));

    Multiplica(quintuplo,num);
    Imprime(quintuplo,num);
    return 0;
}
void Multiplica (int vet[],int num)
{   int i;
    for(i=0;i<num;i++)
    {
        vet[i] = 5 * (i+1);
    }
}
void Imprime (int vet[],int num)
{   int i;
    for(i=0;i<num;i++)
    {
        printf("%d ",vet[i]);
    }
}