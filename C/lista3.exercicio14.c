#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

void Percent_BomReg(int b, int r, int total);
int main(void)
{
    //int capacidade[100]
    int pessoas,i,opcao,idade,id_pessimo=0,id_otimo=0,id_ruim=0,diferenca;
    float media_ruim=0.0F, porc_pessimo=0.0F;
    int gosto[5] = {0,0,0,0,0};
    printf("Quantas pessoas assistiram o filme hoje? "); 
    scanf("%d",&pessoas);
    for (i=0;i<pessoas;i++)
    {
        Menu(&idade,&opcao); //Está faltando validações, mas nao é necessario agora.
        switch (opcao)
        {
        case 1:  // Otimo
        gosto[0]++; 
        id_otimo = (idade > id_otimo) ? idade : id_otimo;
        break;
        //
        case 2: gosto[1]++; break; // Bom
        case 3: gosto[2]++; break; // Regular
        //
        case 4: // Ruim
        gosto[3]++; 
        media_ruim += idade; 
        id_ruim = (idade > id_ruim) ? idade : id_ruim; 
        break; 
        //
        case 5: // Pessimo 
        gosto[4]++;
        id_pessimo = (idade > id_pessimo) ? idade : id_pessimo;      
        break;   
        //    
        default: printf("Opcao Errada."); break;
        }
    }
    porc_pessimo = ( (100*gosto[4]) / pessoas );
    diferenca = (id_otimo-id_ruim); diferenca = diferenca < 0 ? (diferenca*(-1)) : diferenca;

    printf("Quantidade que acharam o filme otimo: %d\n",gosto[0]); // quantidade de respostas ótimo;
    Percent_BomReg(gosto[1], gosto[2],pessoas); // diferença percentual entre respostas bom e regular;
    printf("A media de idade do publico que achou ruim: %.2f \n", (media_ruim/gosto[3]) ); // média de idade das pessoas que responderam ruim;
    printf("A porcentagem de pessimos: %.2f e a maior idade da opcao foi: %d\n",porc_pessimo,id_pessimo); //porcentagem de respostas péssimo e a maior idade que utilizou esta opção
    printf("A diferenca entre a maior idade da opcao Otimo com Ruim foi: %d",diferenca); //diferença de idade entre a maior idade que respondeu ótimo e a maior idade que respondeu ruim.
    return 0;
}

void Menu(int *id, int*op)
{
    printf("\nQual sua opiniao sobre o filme?\n");
    printf("1.Otimo\n");
    printf("2.Bom\n");
    printf("3.Regular\n");
    printf("4.Ruim\n");
    printf("5.Pessimo\n");
    scanf("%d", op);
    printf("Qual sua idade?\n");
    scanf("%d",id);
    printf("====================\n");
}
void Percent_BomReg(int b, int r, int total)
{
    printf("bom = %d, ruim=%d \n",b,r);
    int pr = ((100*r) / total); // Percentual Regular
    int pb = ((100*b) / total); // Percentual Bom
    int diff = pr - pb;
    diff = diff < 0 ? (diff*(-1)) : diff;
    printf("A diferenca percentual entre Bom e Regular foi de %d%%\n", diff);
}