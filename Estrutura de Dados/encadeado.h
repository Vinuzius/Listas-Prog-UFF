#include <stdio.h>
#include <stdlib.h>

typedef struct lista 
{
    int info;
    struct lista *prox;
} TLista;

TLista *cria_lista(void)
{
  return NULL;
}

TLista* insere_inicio (TLista* li, int i)
{
  TLista* novo = (TLista*) malloc(sizeof(TLista));
  novo->info = i;
  novo->prox = li;
  return novo;
}

TLista* insere_fim (TLista* li, int i)
{
  TLista* novo = (TLista*) malloc(sizeof(TLista));
  novo->info = i;
  novo->prox = NULL;
  TLista* p = li; // auxiliar
  if( p == NULL ) //Caso a lista esteja vazia.
    li = novo;
  else
  {
    while(p->prox != NULL)
      p = p->prox; // Varrer ate achar o ultimo elemento
    
    p->prox = novo; // O ultimo elemento vai apontar para o novo.
  }
  return li;
}

TLista *insere_ordenado(TLista *li, int i) {
  TLista *novo = (TLista *)malloc(sizeof(TLista));
  novo->info = i;
  TLista *p = li; // Ponteiro auxiliar

  if (p == NULL) // Se a lista estiver vazia
  {
    novo->prox = NULL;
    li = novo;
  }

  else if (p->info > i) 
  { // Menor numero
    novo->prox = li;
    li = novo;
  } 
  
  else // Procura na lista
  {
    while (p->prox != NULL && p->prox->info < i)
      p = p->prox; // Verifica até o ultimo elemento enquanto o proximo for menor

    novo->prox = p->prox;
    p->prox = novo;
  }

  return li;
}

TLista *insere_ordenado_recursivo(TLista *li, int i) 
{
  if (li == NULL || li->info > i) { // Se a lista estiver vazia ou for o ultimo
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = NULL;

    if (li == NULL)
      li = novo;

    else {
      if (li->info > i) {
        novo->prox = li;
        li = novo;
      } else
        li->prox = novo;
    }
  }

  else
    li->prox = insere_ordenado_recursivo(li->prox, i);

  return li;
}

TLista* deleta_lista(TLista* li, int i) 
{
  TLista* p = li;
  TLista* aux = NULL; // Dois ponteiros para percorrer a lista

  if(p!=NULL) // Lista não vazia, nada para deletar
  {
  
    if(p->info == i) // O elemento a ser deletado é o primeiro
    {
      li = p->prox;
      free(p);
    }
  
    else
    {
      while(p->prox != NULL && p->info != i)
      { // Procura o elemento a ser deletado
        aux = p;
        p = p->prox;
      }
  
      if(p->info == i)
      { // Se o elemento existir
        aux->prox = p->prox;
        free(p);
      }
    }
  }
  return li;
}

void imprime_lista(TLista* li)
{
  TLista* p = li;
  while(p != NULL)
  {
    printf("info = %d\n", p->info);
    p = p->prox;
  }
}

