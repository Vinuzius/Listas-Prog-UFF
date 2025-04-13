#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 struct aluno {
 int mat;       /* Matricula do aluno */
 char nome[81]; /* Nome do aluno */
 };
 typedef struct aluno Aluno;

 struct prova {
 Aluno a;              /* Aluno que fez a prova */
 float q1, q2, q3, q4; /* Nota em cada questao */
 };
 typedef struct prova Prova;
//----------------------------//
void ordena(int n, Prova** v);
int compara(Prova *p1,Prova *p2);
//void troca(Prova* p1,Prova* p2);
//----------------------------//
int main(void)
{
    //Inicializando alunos
    Aluno a1,a2,a3;   
    a1.mat= 10;   strcpy(a1.nome,"Maria");
    a2.mat = 23;  strcpy(a2.nome,"Ana");
    a3.mat = 85;  strcpy(a2.nome,"Sandra");

    //Alocando as provas e Inicializando elas
    Prova **provas;
    provas = (Prova **) malloc(sizeof(Prova *) * 3);
    for (int i = 0; i < 3; i++)
        provas[i] = (Prova *) malloc(sizeof(Prova ));
    
    provas[0]->a=a1; provas[0]->q1=1; provas[0]->q2=2;  provas[0]->q3=3;  provas[0]->q4=0;
    provas[1]->a=a2; provas[1]->q1=2; provas[1]->q2=1;  provas[1]->q3=0;  provas[1]->q4=3;
    provas[2]->a=a3; provas[2]->q1=2; provas[2]->q2=1;  provas[2]->q3=3;  provas[2]->q4=1;

    //Ordenando
    ordena(3,provas);
    //compara(provas[0],provas[1]);

    return 0;
}

int compara(Prova *p1,Prova *p2)
{
    float soma1 = p1->q1 + p1->q2 + p1->q3 + p1->q4;
    float soma2 = p2->q1 + p2->q1 + p2->q1 + p2->q1;
    
    if( (soma1 == soma2) && (strcmp(p1->a.nome,p2->a.nome)<0) )
        return 1>2;

    return soma1 < soma2;
}
void troca(Prova* p1, Prova* p2)
{
    Prova *a; a =(Prova *) malloc(sizeof(Prova));
    memcmp(&a,&p2,sizeof(p2));
    printf("nome %f\n",a->q4);
}


void ordena(int n, Prova** v)
{
    // ordena o vetor em ordem decrescente de nota da prova - que equivale à soma das notas das quatro questões -
    // desempate pela ordem alfabética do nome do aluno
    int fim,i;
    for(fim=n-1; fim>0; fim--)
    {
        for(i=0; i<fim; i++)
        {
            if( compara( v[i], v[i+1] ) )
            {
                troca(&v[i], &v[i+1]);
            }
            else printf("nao trocou\n");
        }
    }
}