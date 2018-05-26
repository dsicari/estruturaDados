//Recursividade - Exemplo fatorial
#include <iostream>

using namespace std;

int main (int argc, char** argv)
{
	int fat = 0;
	int fatorial = 1;
	cout << "Fatorial de? ";
	cin >> fat;
	
	for (int i = fat; i > 0; i--)
	{
		fatorial *= i;
	}
	
	cout << "Fatorial de " << fat << " : " << fatorial;
	
	return 0;
}
