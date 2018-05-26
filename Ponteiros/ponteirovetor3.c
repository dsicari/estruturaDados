//	Ponteiros e Vetores (C)
//	Exemplo 2 
//	24/03/2018

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


main()
{
	int i = 0;
	int *ptr;
	
	//Alocaremos 10 x 4bytes para criar um array de 10 elementos tipo int
	ptr = malloc(sizeof(int)*10);
	
	if (ptr == NULL)
	{
		printf("Memoria insuficiente");
		exit(1);
	}
	else
	{
		int count = 99;
		for(i = 0; i < 10; i++)
		{
			ptr[i] = count--;
			printf("Conteudo ptr[%d]: %d\n", i, ptr[i]);
			printf("Endereco de ptr: %d\n", ptr);
			printf("-----------------------------------\n");
		}
		free(ptr);
	}
}

