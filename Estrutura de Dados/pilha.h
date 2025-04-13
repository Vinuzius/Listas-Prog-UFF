#include <stdio.h>
#include <stdlib.h>
#include "encadeado.h"

typedef struct pilha{
    TLista *topo;
} TPilha;

TPilha *inicializa_Pilha() 
{
    TPilha *pilha = (TPilha *)malloc(sizeof(TPilha));
    pilha->topo = NULL;
    return pilha;
}

void libera(TPilha *p) 
{
    TLista *q = p->topo;
    TLista *r;
    while(q != NULL){
        r = q;
        q=q->prox;
        free(r);
    }
    free(p);
}

int pilha_vazia(TPilha *pilha) 
{
    if (pilha->topo == NULL)
        return 1; //pilha vazia
    else
        return 0; //pilha tem pelo menos 1 elemento
}

void push(TPilha *pilha, int elem) 
{
    TLista *novo = (TLista*) malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

int pop(TPilha *pilha) 
{
    if (pilha_vazia(pilha)) {
        exit(1);
    }
    else {
        TLista *aux = pilha->topo;
        int info = aux->info;
        pilha->topo = aux->prox;
        free(aux);
        return info;
    }
}

int peek(TPilha *pilha) 
{
    if (pilha_vazia(pilha))
        exit(1);
    else {
        //faz consulta
        return pilha->topo->info;
    }
}

void imprime_pilha(TPilha *pilha) 
{
    printf("\nEstado atual da Pilha:\n");
    TPilha *aux = inicializa_Pilha();
    while (!pilha_vazia(pilha)) {
      push(aux, pilha->topo->info); //insere o elemento do topo na pilha auxiliar
      int i = pop(pilha);           //tira o topo da pilha
      printf("%d\n", i);            // imprime
    }
  
    while (!pilha_vazia(aux)) {
      push(pilha,aux->topo->info);
      int j = pop(aux);
    }
    libera(aux);
    printf("\n");
}