#include <stdio.h>
#include <string.h>
#define MAX 50

int main (void) 
{
    char texto[MAX +2], temp ;
    int tam , i;
    gets( texto ); // pegar texto inserido (Vinicius)
    tam = strlen ( texto ); // tam = 8

    for (i = 0; i < tam ; i ++) { // Vai inverter a posição de duas letras da palavra
    temp = texto[i]; // Se i = 0, logo temp = V
    texto[i] = texto[ tam -1 - i ]; // texto[0] = s
    texto[strlen(texto) -1 - i] = temp ; // texto[7] = V
    }
    puts ( texto ); // No final a palavra vai voltar ao original (Vinicius)
    return 0;
}