//	Ponteiros e Vetores (C)
//	Exemplo 1 
//	24/03/2018

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


main(){
	int *ptrA;
	ptrA = malloc(sizeof(int));
	
	if (ptrA == NULL)
	{
		printf("Memoria insuficiente");
		exit(1);
	}
	else
	{
		printf("Endereco de ptrA: %p\n", ptrA);
		*ptrA = 90;
		printf("Conteudo de ptrA: %d\n", *ptrA);
		free(ptrA);
	}
}

