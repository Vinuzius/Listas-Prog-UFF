#include <stdio.h>

void Hexa(int num)
{
  int hex = num%16;
  int aux = num/16;
  if(aux != 0)
  {
    Hexa(aux); // Preguiça de fazer comparador pra escrever do A ao F.
    printf("%d.",hex);
  }
  else
    printf("%d.",hex);
}

void Octal(int num)
{
  int oct = num%8;
  int aux = num/8;
  if(aux != 0)
  {
    Octal(aux);
    printf("%d",oct);
  }
  else
    printf("%d",oct);
}

int main(void) 
{
  int num = 0;
  printf("Entre com um numero: ");
  scanf("%d", &num);
  printf("Hex: "); Hexa(num);
  printf("\n=========\n");
  printf("Octal: "); Octal(num);
  return 0;
}