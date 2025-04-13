#include <stdio.h>
#include <math.h>

void Menu()
{
  printf("============================================\n");
  printf("1) a vista com 10%% de desconto\n");
  printf("2) em duas vezes sem juros\n");
  printf("3) de 3 ate 10 vezes com juros acima de 100$\n");
  printf("============================================");
}

void Opcao1(int valor)
{
  float aux= valor * 0.9;
  printf("\nValor total a vista: R$%.2f",aux);
}

void Opcao2(int valor)
{
  float aux= valor/2;
  printf("\nValor total a ser pago : R$%.2d\n",valor);
  printf("Valor de cada prestacao: R$%.2f",aux);
}

void Opcao3(int valor)
{
  int prestacao= 0;
  float aux2 = valor;

  
  printf("Quantas parcelas? ");
  scanf("%d",&prestacao);

  printf("\nValor total a ser pago : R$%.2d\n",valor);

  if(valor > 100)
  {
    for(int i = 1; i <= prestacao; i++)
      aux2 *= 1.03;
    
    printf("Valor de cada prestacao: R$%.2f\n",aux2/prestacao);
    printf("Total de Juros: %.2f\n", (aux2 - valor) );
  }
  else
  {
    aux2 /= prestacao;
    printf("Valor de cada prestacao: R$%.2f",aux2);
  }
}

int main(void)
{
  float valor;
  int opcao;
  printf("Entre com o gasto do Cliente: ");
  scanf("%f",&valor);

  Menu();

  printf("\nEntre com a opcao: ");
  scanf("%d",&opcao);

  switch (opcao)
  {
    case 1:
      Opcao1(valor);
      break;

    case 2:
      Opcao2(valor);
      break;
    
    case 3:
      Opcao3(valor);
      break;
    
    default:
      printf("Opcao Invalida.");
      break;
  }
  return 0;
}