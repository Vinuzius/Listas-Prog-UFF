#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

float Variancia (int n, float *v);
int main(void)
{
    int idade,n,cont=0,homem=0,mulher=0;
    float altura, *varia,v_alt;
    char sexo;
    printf("Entre com o numero de pessoas: ");
    scanf("%d",&n);
    varia = (float *) malloc(n * sizeof(float) );
    do
    {
        printf("Entre com idade, altura, sexo(H ou M): "); //nao é a melhor forma a ser feita, mas para quesitos praticos de testes fiz assim
        scanf("%d %f %c",&idade,&altura,&sexo); // Fingiremos que o usuario irá inputar tudo certo sempre
        varia[cont] = altura;
        if ((altura >= 1.8) && (sexo=='H') )
        {
            homem++; //se homem e 1.8+, entao aumenta contador
        }
        if ( (idade >= 20) && (idade <= 35) && (sexo=='M') )
        {
            mulher++; //se mulher e entre 20 e 35, entao aumenta contador
        }  
        cont++;
    } while (cont<n);
    v_alt= Variancia(n,varia);
    printf("Homens com mais de 1.8 de altura: %d \n",homem);
    printf("Mulheres entre 20 e 35 anos: %d \n",mulher);
    printf("A variancia da altura foi: %.3f",v_alt);
    
    return 0;
}
float Variancia (int n, float *v)
{
    // Var. amostral = ( (x1 – x)² + (x2 – x)² + (x3 – x)² + ... + (xn – x)² ) / N-1 , onde x= media aritmetica
    int i;
    float media=0,var=0;
    for (i=0;i<n;i++)
    {
        media+= *(v+i);
    }
    media /= n; //Calculo de Media

    for (i=0;i<n;i++)
    {
        var += ( (v[i]-media)*(v[i]-media) ); 
    } 
    var /= (n-1); //Calculo variância

    return var;
}