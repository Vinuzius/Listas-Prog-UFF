#include <stdio.h>
#include <math.h>

float Func_eX(int valor, int casa)
{
  float aux = 1;
  for(int i=1; i<=casa;i++)
  {
    aux += (pow(valor,i)/i);
  }
  return aux;
}

float Func_eX_Recurssivo(int valor, int casa)
{
  if(casa == 0)
    return 1;
  
  else
    return (pow(valor,casa)/casa) + Func_eX_Recurssivo(valor, casa - 1);  
}

int main(void)
{
  int num,precisao;
  float valor;
  printf("Entre com um numero: ");
  scanf("%d",&num);

  printf("Entre com o tamanho da precisao: ");
  scanf("%d",&precisao);

  valor = Func_eX_Recurssivo(num,precisao);
  printf("Fatorial: %.2f", valor);
  return 0;
}