#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
    //Q3- Seja a seguinte seqüência de instruções em um programa C:
    int *pti;
    int veti[]={10,7,2,6,3};
    pti = veti;

    printf("%d", pti[1]);
    /* Qual afirmativa é falsa?
        a. *pti é igual a 10
        b. *(pti+2) é igual a 2
        c. pti[4] é igual a 3
        d. pti[1] é igual a 10
        e. *(veti+3) é igual a 6
        
        R: d é falso
    */
    return 0;
}