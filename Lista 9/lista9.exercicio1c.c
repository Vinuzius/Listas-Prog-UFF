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
void MudarEndereco(Candidato *candidatos,int n);
int main(void)
{
    int num=1,opcao=0;
    Candidato *lista; // Vetor de Candidatos

    //Alocando Candidato 1
    lista= (Candidato *) malloc(sizeof(Candidato) * num);
    if(lista==NULL) {printf("Sem memoria."); exit(1);}
    lista[num-1].loc= (Local *) malloc(sizeof(Local)); 
    if(lista[num-1].loc==NULL) {printf("Sem memoria."); exit(1);} 

    //Loop com Menu para o usuário decidir 
    while(1)
    {
        if(opcao ==4) break; // Caso for 4 ele vai parar o loop
        printf("\n===============================\n");
        printf("|1- Novo Candidato            |\n");
        printf("|2- Mostrar Todos Candidatos  |\n");
        printf("|3- Alterar Endereco Candidato|\n"); 
        printf("|4- Parar                     |\n");    
        printf("===============================\n");
        printf("Opcao: "); scanf("%d",&opcao);
        
        switch (opcao)
        {
            case 1:
                if(num>=2) // o candidato 1 já foi alocado no inicio do programa
                {   // Realocar com o novo candidato
                    lista = realloc(lista,sizeof(Candidato) * num); 
                    if(lista==NULL) {printf("Sem memoria."); exit(1);}

                    lista[num-1].loc= (Local *) malloc(sizeof(Local)); 
                    if(lista[num-1].loc==NULL) {printf("Sem memoria."); exit(1);} 
                }
                CadastroCandidato(lista, (num-1) ); // num-1 porque começa no 0
                num++;
                break;
        
            case 2:
                if(num==1)  { printf("Nao existe Candidato cadastrado.\n"); continue; }
                else  // Se for 1 o candidato nao foi preenchido, se não, existe pelo menos um candidato
                    { MostrarCandidato(lista, (num-1) );}               
                break;
            
            case 3:
                if(num==1)  { printf("Nao existe Candidato cadastrado.\n"); continue; } 
                else  // Se for 1 o candidato nao foi preenchido, se não, existe pelo menos um candidato
                {
                    int endereco;
                    printf("Qual o numero do candidato para mudar o endereco? "); scanf("%d",&endereco);
                    if(endereco <= (num-1) )
                        MudarEndereco(lista,(endereco-1) ); 
                    else // Se o endereco for maior que num então indice nao existe
                        printf("Numero de candidato nao existe.");
                }
                break;
                
            default:
                printf("Fim do programa.");
                break;
        }

    }
    printf("\n------------------------------------------");

    // Liberando a lista
    LiberarCandidato(lista, (num-1) );
    return 0;
}

void CadastroCandidato(Candidato *candidatos,int i)
{
        printf("\nInforme os dados do candidato %d.....\n",i+1);
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
void MostrarCandidato(Candidato *candidatos,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\n==============================\n");
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
void MudarEndereco(Candidato *candidatos,int n)
{
    while ((getchar()) != '\n');                                    
    printf("Entre com o novo endereco: "); scanf("%[^\n]%*c",candidatos[n].loc->ender);
    
    printf("Entre com a nova Sala    : "); scanf("%d",&candidatos[n].loc->sala);
}