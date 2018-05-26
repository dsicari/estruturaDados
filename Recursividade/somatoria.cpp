#include <stdio.h>
#include <iostream>

// Namespace
using namespace std;


int somaR(int n) {

    if (n == 0)
        return 0;

    return (2*n*n + 2*(n) + 8) + somaR(n - 1);
}


// Main
int main()
{
	int n = 0;
	int soma = 0;

	cout << "n: ";
	cin >> n;

	cout << "\nResultado somatoria: " << somaR(n);

	return 0;
}
