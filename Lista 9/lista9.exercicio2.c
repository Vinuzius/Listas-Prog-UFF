#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
	int dia;
	int mes;
	char nomeMes[12];
} Data;

/*
a) Possui um erro na linha 25 (20 sem os comentarios). Não é possivel fazer o Malloc sem ser com ponteiro.
b) Deveria ser mostrado 5, porem como não tem SetLocale, ele conta o caracter quebrado e vai mostrar 6.
*/

main()
{ 
	Data aniversarios[3] = { {5,1,"JANEIRO"}, {4,2,"FEVEREIRO"}, {10,3,"MAIO"} };
	int a;
	Data* p_dt;
	p_dt = &aniversarios[2];
	printf("Nome do mes %d: %s.", p_dt->mes, p_dt->nomeMes);
	strcpy(p_dt->nomeMes, "MARÇO");
	printf("\nNumero de letras : %d", strlen(p_dt->nomeMes));
	Data *p_dt2 = (Data*) malloc(sizeof(Data));
	p_dt2 = &aniversarios[0];
}
