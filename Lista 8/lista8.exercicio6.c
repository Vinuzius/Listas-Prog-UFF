#include <stdio.h>
#include <stdlib.h>

void SomaPeca(int tabuleiro[8][8], int pecas[7]);
int main(void)
{
    //Inicializando as variaveis
    int tabuleiro[8][8]= {{1, 3, 0, 5, 4, 0, 2, 1} , {1, 0, 1, 0, 0, 1, 0, 0} , {0, 0, 0, 0, 1, 0, 6, 0} ,
                          {1, 0, 0, 1, 1, 0, 0, 1} , {0, 1, 0, 4, 0, 0, 1, 0} , {0, 0, 3, 1, 0, 0, 1, 1} ,
                          {1, 0, 6, 6, 0, 0, 1, 0} , {1, 0, 5, 0, 1, 1, 0, 6} };
    
    int pecas[7] = {0, 0, 0, 0, 0, 0, 0}, sumPB;
    char nome_peca[][10] = {"Peoes","Cavalos","Torres","Bispos","Reis","Rainhas"};

    // Somando o total individual de todas as pecas do tabuleiro.
    SomaPeca(tabuleiro,pecas);
        // Somando os Peões e Bispos separadamente
    sumPB = pecas[1] + pecas[4];

    //Printando os resutlados
    printf("A soma de Peao e Bispos = %d\n",sumPB);
    printf("O total de ausencias de pecas = %d\n",pecas[0]);
    printf("O total de cada peca no tabuleiro:\n");
    for(int i=1; i<7;i++)
    {
        printf("%s: %d\n",nome_peca[i-1],pecas[i]);
    }

    return 0;
}
void SomaPeca(int tabuleiro[8][8], int pecas[7])
{   for(int i=0; i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            int num_pec = tabuleiro[i][j];
            pecas[num_pec] +=1;
        }
    }
}