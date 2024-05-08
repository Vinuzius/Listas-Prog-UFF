#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(void)
{
    int *pti;
    int veti[]={10,7,2,6,3};
    pti = veti;
    printf("%d ", pti[1]); // Resultado = 7

    // Resposta: Alternativa D
    return 0;
}