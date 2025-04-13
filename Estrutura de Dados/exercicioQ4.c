#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
    //Q4- Se i e j são variáveis inteiras e pi e pj são ponteiros para inteiro, qual atribuição é ilegal?

    int i = 0, j=-1;
    int *pi, *pj;

    *pj = j;
    printf("%d", *pj);

    /* 
        a. pi = &i;  C
        b. *pj = &j;  C
        c. *pj = j;  E
        d. *pi = *pj;  C
        e. i = (*pi)+*pj;  C
        
        R: C
    */
    return 0;
}