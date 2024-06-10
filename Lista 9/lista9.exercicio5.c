#include <stdio.h>
#include <stdlib.h>

typedef struct endereco {
 char rua[100]; /* Nome da rua */
 int numero; /* Numero do imovel */
} Endereco;

typedef struct notas {
 float p1, p2, p3; /* Notas nas provas */
} Notas;

typedef struct aluno {
 int mat; /* Matricula do aluno */
 char nome[81]; /* Nome do aluno */
 Notas nota; /* Notas nas provas */
 Endereco *end; /* Endereco do aluno */
} Aluno;

main()
{
 Aluno **alunos;
 alunos = alocaAlunos(3);
 atribui(alunos,0,10,"Um",1,1,1,"Getulio Vargas",100);
 atribui(alunos,1,20,"Dois",8,8,8,"Amaral Peixoto",200);
 atribui(alunos,2,30,"Tres",9,9,9,"Ouro Verde",300);
}