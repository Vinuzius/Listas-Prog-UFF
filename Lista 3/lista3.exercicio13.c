#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int a=1,b=2,c=3,d=4;
    float e=5.5,f=6.6,g=7.7,h=8.8;
    char v[10]= {'a','b','c','d','e','f','g','h'};
    int x = 10;

    float *p;
    p = &h;
    //p++;
    printf("valor de p = %d", p );
    return 0;
}