#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

int main(void)
{
    int a[] = {1,10,100,1000};
    int b =10;

    b = b > a[2] ? b : a[0];
    printf("numero b: %d",b);
    return 0;
}