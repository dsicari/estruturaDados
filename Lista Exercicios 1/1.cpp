//	Exercicio 1 - Lista 1 - Estrutura de dados
//	Danilo de Nadai Sicari - Turma 1 - Fatec Araras
// 	24/03/18

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(void)
{
	int x, y, *p;
	y = 0;	
	p = &y;
	x = *p; //x = 0
	x = 4; //x = 4
	(*p)++; //*p = 1
	--x; //x = 3
	(*p) += x; //*p = y = 4
	
	cout << "X: " << x << " Y: " << y << " *p: " << *p;
	return 0;
}
