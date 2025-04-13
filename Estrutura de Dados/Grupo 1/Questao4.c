#include <stdio.h>

float ConverteFahCel(float fahre)
{
  float cel =(fahre-32.0) * (5.0/9.0);
  return cel;
}

int main(void) 
{
  float celsius = 0.0, aux = 0.0;
  printf("Entre com a temperatura em Fahrenheit: ");
  scanf("%f",&aux);
  celsius = ConverteFahCel(aux);
  printf("\n Fahrenheit: %.2fF ... Celsius: %.2fC",aux,celsius);
  
  return 0;
}