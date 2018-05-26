#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <time.h>

// Namespace
using namespace std;


int eqR(int x) {

    if (x == 1)
        return 1;
	
    return 10 * eqR(x - 1) + 2;
}


// Main
int main()
{
	int x = 0;

	cout << "x: ";
	cin >> x;

	cout << "\nResultado: " << eqR(x);

	return 0;
}