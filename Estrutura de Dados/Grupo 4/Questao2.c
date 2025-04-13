#include <stdio.h>
#include <math.h>

int Fatorial_Recurssivo(int fat)
{
  if(fat == 0)
    return 1;  
    
  else
    return fat * Fatorial_Recurssivo(fat - 1);
}

int Fatorial_Loop(int num)
{
  int fat = 1;
  
  for(int i=1; i<=num; i++)
  {
    fat *= i;
  }
  return fat;
}

int main(void)
{
  int num, fat;
  printf("Entre com um numeros: ");
  scanf("%d",&num);

  //fat = Fatorial_Loop(num);
  fat = Fatorial_Recurssivo(num);
  printf("Fatorial: %d", fat);
  return 0;
}