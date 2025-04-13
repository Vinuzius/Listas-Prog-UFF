#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

float media(int n, float *v);
int main(void)
{
    srand(time(NULL)); // seed aleatoria
    int n,i;
    float *vet,m;

    printf("Entre com o tamanho do vetor: ");
    scanf("%d",&n);
    vet = (float *) malloc(n * sizeof(float) );

    for (i=0;i<n;i++) // Criando numeros aleatorios para o vetor, poderia ter um input mas isso serviu para agilizar os testes
    {
        *(vet+i) = rand() % 1000;  // *(v+i) = v[i]
        printf("%f\n",vet[i]);
    }
    m = media(n,vet);
    printf("A média = %.3f",m);
    return 0;
}
float media(int n, float *v)
{
    int i;
    float soma,m;
    for (i =0; i<n;i++)
    {
        soma+= v[i]; //Vai somar os numeros do vetor
    }
    m = (soma/n); // Divide pela quantidade de numeros
    return m;
}