#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AlfabetoMin (char frase[]);
int main(void)
{
    char frase[26];
    AlfabetoMin(frase);

    return 0;
}

void AlfabetoMin (char frase[])
{   int i;
    for(i=0;i<26;i++)
    {
        frase[i] = i + 97; // Atribuir um char com numero vai relacionar ao simbolo na tabela ASCII
    }

    for(i=0;i<26;i++)
    {   printf("%c ",frase[i]);    }
}
