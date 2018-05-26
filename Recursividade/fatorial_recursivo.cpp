//Recursividade - Exemplo fatorial
#include <iostream>

using namespace std;

int fat_rec = 0;

int fatorial(int f)
{
	int fatorial = 1;
	for (int i = f; i > 0; i--)
	{
		fatorial *= i;
	}
	return fatorial;
}

int fatorial_rec(int n)
{
	int f = 1;
	if(n > 1)
	{
		f = n * fatorial_rec(n - 1);
	}
	else
	{
		f = 1;
	}
	return f;
}

int main (int argc, char** argv)
{
	int fat = 0;

	cout << "Fatorial de? ";
	cin >> fat;
	
	cout << "Fatorial de " << fat << " : " << fatorial(fat);
	
	fat_rec = fat;
	
	cout << "Fatorial de " << fat << " : " << fatorial_rec(fat);
	return 0;
}
