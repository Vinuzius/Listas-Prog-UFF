#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa {
 int codigo;
 char nome[81];
 };
typedef struct pessoa Pessoa;

Pessoa* busca(int n, Pessoa** vet, int codigo);
int main(void)
{
    //Inicializando uma lista de 3 pessoas
    Pessoa **pessoas;
    pessoas = (Pessoa **) malloc(sizeof(Pessoa *) * 3);
    for(int i=0;i<3;i++)
        pessoas[i]= (Pessoa *) malloc(sizeof(Pessoa) * 3);


    //Inserindo pessoas para testar a Busca
    pessoas[0]->codigo = 10; strcpy(pessoas[0]->nome,"Gustavo");
    pessoas[1]->codigo = 26; strcpy(pessoas[1]->nome,"Rodrigo");
    pessoas[2]->codigo = 37; strcpy(pessoas[2]->nome,"Pedro");


    // Fazendo o teste da Busca
    int cod; 
    printf("Qual codigo quer testar? "); scanf("%d",&cod);
    Pessoa *teste = busca(3,pessoas,cod);
    if(teste == NULL)
        printf("O Codigo inserido nao existe");
    else
        printf("O codigo %d existe e pertence a pessoa %s", teste->codigo,teste->nome);

    return 0;
}

Pessoa* busca(int n, Pessoa** vet, int codigo)
{    
    int ini = 0, fim = n-1;

    while (ini <= fim) 
    {
        int meio = (ini + fim) / 2;
        if (codigo < vet[meio]->codigo)
            fim = meio - 1;

        else if (codigo > vet[meio]->codigo)
            ini = meio + 1;

        else
            return vet[meio];
    }

    return NULL;
}