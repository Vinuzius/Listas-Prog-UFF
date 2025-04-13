#include <stdio.h>
#include <stdlib.h>

int divs(int n, int *max, int *min);
int main(void)
{
	int num,max=0,min=0,teste;
	printf("Entre com um número: ");
	scanf("%d",&num);
	teste = divs(num,&max,&min);
	return 0;
}
int divs(int n, int *max, int *min)
{
	int cont=0,i;
    for (i=1;i<=n;i++)
    {
        if( (n%i)==0)
        {
            cont++;
        }
        if(cont>=3){break;}
    }
    if (cont==2){return 0;}
    else
	{
		for (i=2;i<=n/2;i++)
		{
			if( (n%i)==0)
			{
				*min = i;
				break;
			}			
		}
		for (i=(n/2) ; i>=*min ;i-=1)
		{
			if( (n%i)==0)
			{
				*max = i;
				break;
			}			
		}
        return 1;
    }
}