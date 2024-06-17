#include <stdio.h>
#include <stdlib.h>

#define MAX 4
#define MAXNOME 31
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void atribui(char **nomes, int indice, char *nome);
char * get_sobrenome(char *nome);
int main(void)
{
    int i;
    char **nomes;
    char *sobrenome;
    nomes = (char **) malloc(MAX*sizeof(char *));
    for ( i=0 ; i<MAX ; i++) {
    nomes[i] = (char *) malloc(sizeof(char)*MAXNOME);
    }
    //------------------//
    atribui(nomes,0,"Fulano Silva"); atribui(nomes,1,"Maria do Carmo");
    atribui(nomes,2,"Beltrano Belmonte"); atribui(nomes,3,"Pedro dos Santos");
    //------------------//
    i=0;
LOOP:
{
        sobrenome = get_sobrenome(nomes[i]);
        
        printf("\n%s", sobrenome);
        printf(" %d",strlen(sobrenome)>5?i:0); // 2º printf
    if (i==0)
    {
        i++;
        goto LOOP;
    }
    else if (i<MAX)
    {
            i++;
            goto LOOP;
    }
}
    //------------------//

    //printf("\n%c", nomes[0][3]); // 3º printf

   /* 
    c)
    d)  
  */ 
}

void atribui(char **nomes, int indice, char *nome)
{   strcpy(nomes[indice],nome);   }

char * get_sobrenome(char *nome)
{
    char *aux;
    char teste[31];
    char teste2[31] = "";
    int i=strlen(nome);
    aux = (char *) malloc( sizeof(teste) );

    for(i=strlen(nome); i>0; i--)
    {
        if(nome[i] == ' ') break;
        strncat(teste,&nome[i],1);
    }

    for(i=strlen(teste)-1;i>=0 ;i--)
    {
        strncat(teste2,&teste[i],1);
    }
    strcpy(aux,teste2);
    return aux;
}