#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <time.h>

// Namespace
using namespace std;

// Fibonacci recursive
long long int fibR(long long int x) {
    if (x == 0)
        return 0;

    if (x == 1)
        return 1;

    return fibR(x-1)+fibR(x-2);
}

// Fibonacci iterative
long long int fibI(long long int x)
{
	int first = 0, second = 1, next;
	for (long long int i = 0 ; i <= x ; i++ )
	{
      if ( i <= 1 )
         next = i;
      else
      {
        next = first + second;
        first = second;
        second = next;
      }
      //return next;
	}
	return next;
}	

// Main
int main()
{
	long long int f = 0;
	long long int before;
	cout << "Numero para calcular: ";
	cin >> f;
	cout << "\nFibonacci por recursividade\n------------------------";
	for(long long int i = 0; i <= f; i++)
	{
		//before = GetTickCount();
		clock_t start = clock();
		cout << "\nfib(" << i << ") = " << fibR(i);
		clock_t stop = clock();
		double elapsed = (double)(stop - start) * 1000 / CLOCKS_PER_SEC;
		printf(" Time elapsed in ms: %f", elapsed);
		//cout <<	" Elapsed: " << elapsed;//(GetTickCount() - before) << "ms";
	}
	cout << "\nFibonacci por iteratividade\n------------------------";
	//for(long long int i = 0; i <= f; i++)
	before = GetTickCount();
	cout << "\nfib(" << f << ") = " << fibI(f);
	cout <<	" Elapsed: " << (GetTickCount() - before) << "ms";	
	
	cin >> f;
	//system("pause"); 
	return 0;
}
