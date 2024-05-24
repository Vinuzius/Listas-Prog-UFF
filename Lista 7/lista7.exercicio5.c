#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // ACREDITO QUE O EXEMPLO DA LISTA ESTA ERRADO :thumbs_up:
    char frase[81], *letra; int i,j=0,k=1,temp;
    printf("Entre com a sua frase:\n");
    scanf("%80[^\n]",frase);
    printf("\nFrase inicial: %s",frase);
    letra = (char *) malloc(strlen(frase)); // Preenchendo um tamanho menor para a segunda string

    for(i=0; i<=strlen(frase); i++) 
    { // Vai copiar sem os espaços em branco
        if (frase[i] != ' ')
        {            
            letra[j] = frase[i];
            j++;
        }        
    }
    printf("\nFrase apos retirada de espacos: %s",letra);

    for(i=0; i<strlen(letra); i++) 
    {
        if (k==6){k=1;}

        temp = (letra[i] + k);
        if (letra[i] <91) // Letras maiusculas
        {
            if ( temp <= 90 )
            {
                letra[i] = temp;
            }
            else if(temp > 90) // caso ele passe da letra Z
            {
                temp -= 26;
                letra[i] = temp;
            }
        }
        else if (letra[i] > 96) // letras minusculas
        {
            if ( temp <= 122 )
            {
                letra[i] = temp;
            }
            else if(temp > 122) // caso ele passe da letra Z
            {
                temp -= 26;
                letra[i] = temp;
            }
        }
        k++;      
    }
    printf("\nFrase depois de mudada: %s",letra);

    return 0;
}