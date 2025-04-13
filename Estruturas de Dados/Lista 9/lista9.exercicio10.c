#include <stdio.h>
#include <stdlib.h>

//Faça as funções que são invocadas pela função main
int main (void) 
{
    struct aluno turma[MAX];
    le( turma );
    puts (" Imprimindo dados lidos da turma.");

    puts (" Digite qualquer coisa para continuar .");
    getchar ();

    imprime ( turma );
    ordena_medias ( turma );

    puts (" Imprimindo dados ordenados da turma.");
    puts (" Digite qualquer coisa para continuar .");
    getchar ();
    
    imprime ( turma );
    getchar ();
}