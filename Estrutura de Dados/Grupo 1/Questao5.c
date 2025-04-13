#include <stdio.h>
#include <math.h>

int main(void)
{
  float n1,n2,aux;
  printf("Entre com dois numeros: ");
  scanf("%f %f",&n1,&n2);
  
  aux = n1 + n2;
  printf("\nSoma dos numeros = %.2f\n\n",aux);

  aux = n1 * pow(n2,2);
  printf("O produto do primeiro numero pelo quadrado do segundo = %.2f\n\n",aux);

  aux = pow(n1,2);
  printf("O quadrado do primeiro numero = %.2f\n\n",aux);

  aux = sqrt( ( pow(n2,2) + pow(n1,2) ) );
  printf("A raiz quadrada da soma dos quadrados = %.2f\n\n",aux);

  aux = fabs(n1);
  printf("O modulo do primeiro numero = %.2f\n\n",aux);
  
  return 0;
}