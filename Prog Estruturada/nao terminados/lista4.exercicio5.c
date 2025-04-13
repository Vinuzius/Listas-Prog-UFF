#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void calcula_corrida(float dist, float *b1, float *b2);
int main(void)
{   
    int distancia, bandeira1[100], bandeira2[100];
    printf("**Digite 0 para terminar**\n\n")
    do
    {
        printf("Qual a distancia? ");
        scanf("%d",distancia);
        if(distancia == 0)
            break;
        else
            calcula_corrida();

    } while (1);
    
    
    
    return 0;
}

void calcula_corrida(float dist, float *b1, float *b2)
{   //distancia em Km
    float corrida,bandeira;
    printf("Qual a bandeira? ");
    scanf("%d",bandeira);

    if (bandeira == 1)
        corrida = 4.95 + floor(dist) * 2.5;
    else if(bandeira == 2)
        corrida = 4.95 + floor(dist) * 3.0;
    
    
}
