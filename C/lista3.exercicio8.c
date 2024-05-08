#include <conio.h>
#include <stdio.h>
void main(){
float vet[5] = {1.1,2.2,3.3,4.4,5.5};
float *f;
int i;
f = vet;
printf("contador/valor/valor/endereco/endereco");
for(i = 0 ; i <= 4 ; i++)
{
    printf("\ni = %d",i);
    printf(" vet[%d] = %.1f",i, vet[i]);
    printf(" *(f + %d) = %.1f",i, *(f+i));
    printf(" &vet[%d] = %X",i, &vet[i]);
    printf(" (f + %d) = %X",i, f+i);
}
// A saida é o valor e o endereço escritos de 2 maneiras diferentes
/*
i = 0 vet[0] = 1.1  *(f + 0) = 1.1 &vet[0] = 62FDF0 (f + 0) = 62FDF0
i = 1 vet[1] = 2.2  *(f + 1) = 2.2 &vet[1] = 62FDF4 (f + 1) = 62FDF4
i = 2 vet[2] = 3.3  *(f + 2) = 3.3 &vet[2] = 62FDF8 (f + 2) = 62FDF8
i = 3 vet[3] = 4.4  *(f + 3) = 4.4 &vet[3] = 62FDFC (f + 3) = 62FDFC
i = 4 vet[4] = 5.5  *(f + 4) = 5.5 &vet[4] = 62FE00 (f + 4) = 62FE00 */
}