#include <stdio.h>
#include <stdlib.h>
typedef struct Livro 
{
    int ano;
    char titulo[100];
    char autor[100];
    int nVolume; // Número de exemplares de um dado livro.
    float preco;
}Livro;

typedef struct Biblioteca 
{
    Livro **V; // Armazena a informação de n livros !!
    int nLivros // Número de livros existentes na biblioteca.
}Biblioteca;
int main(void)
{
    return 0;
}