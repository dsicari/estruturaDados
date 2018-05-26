#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <time.h>

// Namespace
using namespace std;


int eqR(int x) {

    if (x == 0)
        return 2;
	
    return 2 * eqR(x - 1) - 4;
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