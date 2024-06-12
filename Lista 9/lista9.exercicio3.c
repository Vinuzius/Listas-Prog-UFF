#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * estado[27] =
{"AC","AL","AM","AP","BA","CE","DF","ES","GO","MA","MG","MS","MT","PA",
"PB","PE","PI","PR","RJ","RN","RO","RR","RS","SC","SE","SP","TO"};

typedef struct assalariados {
 char nome[51];
 char sexo;
 int idade;
 float salario;
 char estado[3];
} Assalariados;

Assalariados * cadastra(char *nome, char sexo, int idade, float salario, char *estado);
void imprime(Assalariados ** ptr, int numAssalariados);
void relatorio(Assalariados ** ptr, int numAssalariados);


int main(void) 
{
    Assalariados **pessoas;
    int numAssalariados=3;
    pessoas = (Assalariados **) malloc (numAssalariados *sizeof(Assalariados *));
    //a)
    pessoas[0] = cadastra("Fulano de tal", 'M',45,1500.00, "RJ");
    pessoas[1] = cadastra("Ciclano", 'M',50,2500.00, "RS");
    pessoas[2] = cadastra("Beltrano", 'M',42,500.00, "RS");
    //b)
    imprime(pessoas, numAssalariados);
    //c)
    printf("\nRelatorio de cada Estado...\n");
    relatorio(pessoas,numAssalariados);
}
Assalariados * cadastra(char *nome, char sexo, int idade, float salario, char *estado)
{
    Assalariados *pessoa;
    pessoa = (Assalariados *) malloc(sizeof(Assalariados));
    strcpy(pessoa->estado,estado); strcpy(pessoa->nome,nome);
    pessoa->idade= idade; pessoa->salario= salario; pessoa->sexo = sexo;
    return pessoa;
}

void imprime(Assalariados ** ptr, int numAssalariados)
{
    for(int i=0;i<numAssalariados;i++)
    {
        printf("\n|........Funcionario %d........|\n",(i+1));
        printf("|Nome: %s --- Sexo: %c\n",ptr[i]->nome, ptr[i]->sexo);
        printf("|Idade: %d --- Estado: %s\n",ptr[i]->idade,ptr[i]->estado);
        printf("|Salario: R$%.2f\n",ptr[i]->salario);
    }

}

void relatorio(Assalariados ** ptr, int numAssalariados)
{
    int estado_maior=0,comp;
    for(int i=0;i<27;i++)
    {   estado_maior=0;
        for(int j=0; j<numAssalariados;j++)
        {   comp = strcmp(ptr[j]->estado,estado[i]);
            if ( comp == 0 )  estado_maior++;
        }
        if(estado_maior > 0)
            printf("Estado=%s com %d homens maiores de 40 anos e salario maior que R$ 1000,00\n",estado[i],estado_maior);
    }

    
    
}