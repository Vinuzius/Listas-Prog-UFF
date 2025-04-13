#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ContaVogal(char frase[],int *vogal);
int main(void)
{
    char greetings[] = "Emanuelle";
    int v = 0;
    ContaVogal(greetings,&v);

    printf("Total de vogal: %d",v);

    return 0;
}

void ContaVogal(char frase[],int *vogal)
{
    int numVogal[10] = {65,69,73,79,85,97,101,105,111,117};

    for(int i=0; i<strlen(frase); i++)
    {
        for(int j=0; j<10;j++)
        {
            int aux = frase[i];
            if (aux == numVogal[j])
                *vogal+=1;                           
        }
    }
}

