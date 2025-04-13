#include <stdio.h>
#include "encadeado.h"

int main(void) 
{
  TLista *l1;
  /* Insere elementos no inicio da lista */
  l1 = cria_lista(); /* cria e inicializa lista como vazia */
  l1 = insere_ordenado(l1, 2);
  l1 = insere_ordenado(l1, 3);
  l1 = insere_ordenado(l1, 5);
  l1 = insere_ordenado(l1, 4);
  printf("Lista 1:\n");
  imprime_lista(l1);

  printf("\nNova Lista 1:\n");
  l1 = deleta_lista(l1,2);
  imprime_lista(l1);
  
  return 0;
}