#include <stdio.h>
#include <stdlib.h>
#include "encadeado.h"

int main(void)
{
    //Q5 - Escreva uma função que receba duas Listas (L1 e L2), intercale-as gerando uma terceira Lista, L3

    TLista *lista1; //*lista2,*lista3;
    lista1 = cria_lista(); //lista2 = cria_lista(); lista3 = cria_lista();

    insere_ordenado(lista1,1);
    insere_ordenado(lista1,5);
    insere_ordenado(lista1,3);

    imprime_lista(lista1);
    printf("\n");

    return 0;
}