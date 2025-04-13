#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

int main(void)
{
    char frase[6];
    unsigned int i;
    printf("Entre com a sua frase:\n");
    for (i=0;i<sizeof(frase);i++)
    {
        frase[i]= getch();
        if (frase[i]== '\r') {break;}
        printf("*");        
    }
    printf("\n");
    for (i=0; frase[i]!='\0' ;i++)
    {
        printf("%c",frase[i]);
        if (frase[i] == ' ') {printf("\n");}        
    }
    getch();
    return 0;
}