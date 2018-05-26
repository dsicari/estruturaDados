//
// 	DANILO DE NADAI SICARI
//	Teste pilha estatica
//

#include <iostream>

#define STACK_MAX 3

struct TPilha{
	int data[STACK_MAX];
	int size;
};

bool IniciarPilha(TPilha *pilha)
{
	pilha->size = 0;
}

bool Push(TPilha *pilha, int valor)
{
	bool rslt = false;
	if(pilha->size < STACK_MAX)
	{
		pilha->data[pilha->size++] = valor;
		rslt = true;
	}
	return rslt;
}

bool Pop(TPilha *pilha, int *valor)
{
	bool rslt = false;
	if(pilha->size > 0)
	{
		*valor = pilha->data[--pilha->size];
		rslt = true;
	}
	return rslt;
}

int main()
{
	TPilha pilha;
	int valor;
	valor = 9;
	
	printf("\nInserindo valor 10 na pilha...");
	if(Push(&pilha, 10))	printf("\nOK");
	else printf("\nFAIL");
	
	printf("\nInserindo valor -3 na pilha...");
	if(Push(&pilha, -3))	printf("\nOK");
	else printf("\nFAIL");
	
	printf("\nInserindo valor 0 na pilha...");
	if(Push(&pilha, 0))	printf("\nOK");
	else printf("\nFAIL");
	
	printf("\nInserindo valor 340 na pilha...");
	if(Push(&pilha, 340))	printf("\nOK");
	else printf("\nFAIL");
	
	printf("\nRetirando ultimo valor da pilha...");
	if(Pop(&pilha, &valor))	printf("\nOK, valor: %d", valor);
	else printf("\nFAIL");
	
	printf("\nRetirando ultimo valor da pilha...");
	if(Pop(&pilha, &valor))	printf("\nOK, valor: %d", valor);
	else printf("\nFAIL");
	
	printf("\nRetirando ultimo valor da pilha...");
	if(Pop(&pilha, &valor))	printf("\nOK, valor: %d", valor);
	else printf("\nFAIL");
	
	printf("\nRetirando ultimo valor da pilha...");
	if(Pop(&pilha, &valor))	printf("\nOK, valor: %d", valor);
	else printf("\nFAIL");
	return 0;
}
