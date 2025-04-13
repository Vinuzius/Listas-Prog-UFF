#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int testa_PA(int n, int* v);
int main(void)
{
    int *v, Pa, num;

    num = 5;
    v = (int *) malloc(sizeof(int) * num);
    v[0] = 2; v[1]= 10; v[2] = 18; v[3] = 26; v[4] = 34;

    if(num > 3)
    {
        Pa = testa_PA(num,v);
        if(Pa>0)
            printf("O valor da Pa k = %d",Pa);
        else
            printf("Funcao nao possui Pa.");
    }
    else
        printf("Funcao muito pequena para ser uma PA.");
    
    free(v);
    return 0;
}

int testa_PA(int n, int* v)
{
    //inteiro k tal que v[i]=v[0]+k*i.
    int aux,k = 0;
    do
    {   // Achar o K, somente em numeros Naturais
        aux = v[0] + k;
        if(aux == v[1])
            break;

        else if (aux > v[1])
        {
            return 0;
        }
        k++;            
    } while(1);

    for(int i=1;i<n;i++)
    {   // Testar se o K * i vai funcionar pra todos, caso algum seja diferente já cancela.
        aux = v[0] + k * i;
        if (aux != v[i])
            return 0;                
    }

    return k;
}
