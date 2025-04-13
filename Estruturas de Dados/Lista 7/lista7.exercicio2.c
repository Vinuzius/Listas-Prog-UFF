#include <stdio.h>
#include <string.h>

int main (void) {
 char *frase = "Otimo teste";
 char *p , misterio[80];
 int i = 0;
 int j = 0;
 p = frase + (strlen(frase) - 1); // Vai pegar o último caractere de Frase

 while (*p != ' ') { // Vai parar quando for espaço em branco
 misterio[i] = *p;
 i ++; p --; // Diminui o P para pegar a letra anterior da frase
 } // No final misterio = 'etset'

 
 misterio[i] = ' '; i ++; // Adiciona um espaço em branco após o 'etset', entao misterio = 'etset '
 while ( frase[j] != ' ') {
 misterio [i] = frase[j];
 j ++; i ++; //Aumenta o J para pegar a próxima letra para colocar na string Misterio
 }
 misterio[i] = '\0';
 puts (misterio); // Vai printar ('etset Otimo) 
 return 0;
}