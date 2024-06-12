#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
    int dia, mes, ano;
} Data;

typedef struct local {
    char ender[81]; /* endereço do local de provas */
    int sala;       /* numero sala */
} Local;

typedef struct notas {
    float geral;        /* prova de conhecimentos gerais */
    float especifica;   /* prova de conhecimentos especificos */
} Notas;

typedef struct candidato {
    int inscr;     /* numero de inscricao */
    char nome[81]; /* nome do candidato */
    Data nasc;     /* data de nascimento */
    Local *loc;    /* local de prova */
    Notas nt;      /* notas de prova */
} Candidato;

void CadastroCandidato(Candidato *candidatos,int n);
void MostrarCandidato(Candidato *candidatos,int n);
void LiberarCandidato(Candidato *candidatos,int n);                            
int main(void)
{
    int n;
    Candidato *lista; // Vetor de Candidatos

    //Alocando dinamicamente a lista com N candidatos. Tem que alocar o Local separadamente pois ele é um ponteiro.
    printf("Quantos candidatos? "); scanf("%d",&n);
    lista= (Candidato *) malloc(sizeof(Candidato) * n);
    if(lista==NULL) {printf("Sem memoria."); exit(1);}

    for(int i=0;i<n;i++)    
    { lista[i].loc= (Local *) malloc(sizeof(Local)); 
      if(lista[i].loc==NULL) {printf("Sem memoria."); exit(1);}  
    }    

    // ============================== //
    CadastroCandidato(lista,n);
    MostrarCandidato(lista,n);
    LiberarCandidato(lista,n);
    return 0;
}

void CadastroCandidato(Candidato *candidatos,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\nInforme os dados do candidato %d.....\n",i);
        printf("Numero da incricao  : "); scanf("%d",&candidatos[i].inscr);

        while ((getchar()) != '\n');
        printf("Nome do candidato   : "); scanf("%[^\n]%*c",candidatos[i].nome);

        printf("Data de nascimento  : "); scanf("%d %d %d", &candidatos[i].nasc.dia, 
                                            &candidatos[i].nasc.mes, &candidatos[i].nasc.ano);

        while ((getchar()) != '\n');                                    
        printf("    Local           : "); scanf("%[^\n]%*c",candidatos[i].loc->ender);
        printf("    Sala            : "); scanf("%d",&candidatos[i].loc->sala);
        printf("Nota Geral          : "); scanf("%f",&candidatos[i].nt.geral);
        printf("Nota Especifica     : "); scanf("%f",&candidatos[i].nt.especifica);
    }
}
void MostrarCandidato(Candidato *candidatos,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("==============================\n");
        printf("Dados do candidato %d...",i);
        printf("\nNumero da incricao     : %d",candidatos[i].inscr);
        printf("\nNome do candidato      : %s",candidatos[i].nome);
        printf("\nData de nascimento     : %d/%d/%d",candidatos[i].nasc.dia,candidatos[i].nasc.mes,candidatos[i].nasc.ano);
        printf("\nLocal e Sala           : %s, %d",candidatos[i].loc->ender,candidatos[i].loc->sala);
        printf("\nNota Geral e Especifica: %.1f | %.1f",candidatos[i].nt.geral,candidatos[i].nt.especifica);
    }    
}
void LiberarCandidato(Candidato *candidatos,int n)
{
    for(int i=0;i<n;i++)
        free(candidatos[i].loc);
    free(candidatos);
}