#include <stdio.h>
#include <stdlib.h>

void DistCidade (int dist_cidades[5][5]);
void TotalPercorrido(int dist_cidades[5][5]);
void TabelaSemRepeticao (int dist_cidade[5][5]);
int main(void)
{
    int dist_cidades[5][5] = { {00, 15, 30, 05, 12} , {15, 00, 10, 17, 28} , {30, 10, 00, 03, 11} ,
                               {05, 17, 03, 00, 80} , {12, 28, 11, 80, 00}  };

    /* a)*/DistCidade(dist_cidades);
    /* b)*/TabelaSemRepeticao(dist_cidades);    
    /* c)*/TotalPercorrido(dist_cidades);
    return 0;
}

void DistCidade (int dist_cidades[5][5])
{   int cidade1,cidade2;
    while (!NULL)
    {
        printf("Entre com duas cidades: ");
        scanf("%d %d", &cidade1,&cidade2);

        // O usuario nao sabe que começa no 0, portanto decresci um para evitar erros;
        if ( (cidade1 ==0) && (cidade2==0)) break; // Se 0 0, acaba
        else if ( (cidade1 >5 ) || (cidade1 <= 0) ) printf("Cidade Invalida.\n"); // Se <5 ou >0 entao está inválido
        else if ( (cidade2 >5 ) || (cidade2 <= 0) ) printf("Cidade Invalida.\n");
        else  printf("A distancia entre as cidades %d e %d = %dkm\n",cidade1,cidade2,dist_cidades[cidade1-1][cidade2-1]);
    }   printf("Fim.\n");
}
void TotalPercorrido(int dist_cidades[5][5])
{
    int cidade1,cidade2,distTotal,aux;
    // Iniciando com as 2 primeiras cidades para evitar erro
    printf("Entre com as 2 primeiras cidades: ");
    scanf("%d %d",&cidade1,&cidade2);
    distTotal = dist_cidades[cidade1-1][cidade2-1];

    //Vai parar quando inputar 0
    while (cidade2 !=0)
    {
        aux = cidade2;
        printf("Entre com a proxima cidade: ");
        scanf("%d",&cidade2); 
        if(cidade2 ==0) break; 
        else distTotal += dist_cidades[aux-1][cidade2-1];   
    }
    printf("O percurso total vai ser %dkm",distTotal);
}
void TabelaSemRepeticao (int dist_cidades[5][5])
{
    printf("       C1    C2    C3    C4    C5\n");
    printf("    -----------------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("C%d |",i+1);
        for (int j = 0; j < 5; j++) { 
            if(j<i) printf("    - "); // Se o J for menor que o I, então essa distância já foi printada, então não irei printar
            else printf("%5d ",dist_cidades[i][j]); // o 4D e os espaços são apenas para deixar alinhado na visualização
        }printf("\n");
    }    
}