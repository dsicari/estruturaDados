//	Ponteiros e Vetores (CPP)
//	Exemplo 1 
//	24/03/2018

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

main(){
	int *ptrA;
	ptrA = new int;
	
	if (ptrA == NULL)
	{
		cout << "Memoria insuficiente";
		exit(1);
	}
	else
	{
		cout << "Endereco de ptrA: " << ptrA << endl;
		*ptrA = 90;
		cout << "Conteudo de ptrA: " << *ptrA;
		delete ptrA;
	}
}

