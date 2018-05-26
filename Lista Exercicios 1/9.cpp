//	Exercicio 9 - Lista 1 - Estrutura de dados
//	Danilo de Nadai Sicari - Turma 1 - Fatec Araras
// 	24/03/18

/***************************************************
Escreva uma função que recebe como parâmetros um vetor
de inteiros v, o número de elementos dele N e ponteiros
para variáveis nas quais devem ser armazenados 
os valores maximo e minimo do vetor. Sua assinatura
deve ser: 
void maximoMinimo(int *v, int N, int *maximo, int *minimo);
***************************************************/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

void maximoMinimo(int *v, int N, int *maximo, int *minimo)
{
	*minimo = *maximo = v[0];
	
	for(int i = 0; i < N; i++)
	{
		if(*minimo >= v[i])
			*minimo = v[i];
		if(*maximo <= v[i])	
			*maximo = v[i];
	}
}

int main()
{
	int v[10] = {0};
	int vMin = 0, vMax = 0;
	
	cout << "Valores?" << endl;
	for(int i = 0; i < 10; i++)
	{
		cout << "Valor[" << i << "]: ";
		cin >> v[i];
		cout << endl;			
	}
	
	maximoMinimo(v, 10, &vMin, &vMax);
	printf("Valor maximo: %i minimo: %i", vMin, vMax);
	
	return 0;
}


