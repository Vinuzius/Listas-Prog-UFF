#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 struct data 
 {
 int dd, mm, aa; /* Dia, mes e ano */
 };
 typedef struct data Data;

 struct compromisso 
 {
 char descricao[81]; /* Descricao do compromisso */
 Data dta;           /* Data do compromisso */
 };
 typedef struct compromisso Compromisso;
//========================================//

Compromisso* busca(int n, Compromisso** vet, int d, int m, int a);

int main(void)
{
    //Inicializando e Alocando o calendario de compromissos. Colocando uns exemplos para teste. 
    Compromisso **calendario;
    calendario = (Compromisso **) malloc(5* sizeof(Compromisso *));
    for(int i=0;i<5;i++)
        calendario[i]= (Compromisso *) malloc(sizeof(Compromisso));
    calendario[0]->dta.dd= 1;  calendario[0]->dta.mm = 3;  calendario[0]->dta.aa= 2024;
    calendario[1]->dta.dd= 10; calendario[1]->dta.mm = 9;  calendario[1]->dta.aa= 2024;
    calendario[2]->dta.dd= 27; calendario[2]->dta.mm = 7;  calendario[2]->dta.aa= 2025;
    calendario[3]->dta.dd= 31; calendario[3]->dta.mm = 8;  calendario[3]->dta.aa= 2025;
    calendario[4]->dta.dd= 9;  calendario[4]->dta.mm = 2;  calendario[4]->dta.aa= 2026;
    //==========================//
    // Teste da Função Busca
    Compromisso *teste;
    teste = busca(5, calendario, 1,3,2024);
    if(teste != NULL)
        printf("Compromisso buscado: %02d/%02d/%d, existe no seu calendario.", teste->dta.dd,teste->dta.mm,teste->dta.aa);

    else printf("Compromisso buscado nao existe!");
    return 0;
}

Compromisso* busca(int n, Compromisso** vet, int d, int m, int a)
{ 
    int ini = 0,meio;
    int fim = n-1;

    //Adicionei 0.5 nos loops porque ele arredonda para baixo e as vezes causava erros de pular algum índice.
    //Desse jeito ele funcionou em todos os 20 testes que eu fiz.

    while(ini <= fim) // Loop para delimitar o ano
    {   meio = (ini + fim + 0.5) / 2 ;
        if(a < vet[meio]->dta.aa)
            fim = meio - 1;

        else if(a > vet[meio]->dta.aa)
            ini = meio + 1;

        else if(a == vet[meio]->dta.aa) break; // Se existir já manda para o próximo loop,
        else return NULL;                       // caso não exista já quebra a função
    } 

    //Como o ini e fim estarão mantidos na "parte do vetor desejado", preferi manter eles
    //Provavelmente os whiles do mes e dia poderiam estar no Else do primeiro while
    //Mas assim, eu acho que fica mais legível.

    while(ini <= fim) // Loop para delimitar o mês
    {   meio = (ini + fim + 0.5) / 2 ;
        if(m < vet[meio]->dta.mm)
            fim = meio - 1;

        else if(m > vet[meio]->dta.mm)
            ini = meio + 1; 

        else if(m == vet[meio]->dta.mm) break;
        else return NULL;
    } 

    while(ini <= fim) // Loop para delimitar o mês
    {   meio =(ini + fim + 0.5) / 2 ;     
        if(d < vet[meio]->dta.dd)
            fim = meio - 1;

        else if(d > vet[meio]->dta.dd)
            ini = meio + 1;

        else if(d == vet[meio]->dta.dd) return vet[meio];
        else break;
    } 
    return NULL;    
}