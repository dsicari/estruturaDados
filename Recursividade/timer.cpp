#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;

// Fibonacci recursive
unsigned long long int fibR(unsigned long long int x) {
    if (x == 0)
        return 0;

    if (x == 1)
        return 1;

    return fibR(x-1)+fibR(x-2);
}

// Fibonacci iterative
unsigned long long int fibI(unsigned long long int x)
{
	int first = 0, second = 1, next;
	for (unsigned long long int i = 0 ; i <= x ; i++ )
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

int main()
{
  LARGE_INTEGER start, end, freq;
  
  QueryPerformanceFrequency(&freq);
  QueryPerformanceCounter(&start); 
  
  cout << fibI(200)  << "\n";
  
  QueryPerformanceCounter(&end);
    
  std::cout << "The resolution of this timer is: " << freq.QuadPart << " Hz." << std::endl;
  std::cout << "Time to calculate some_operation(): " 
            << (end.QuadPart - start.QuadPart) * 1000000 / freq.QuadPart 
            << " microSeconds" << std::endl;
			
			QueryPerformanceCounter(&start); 
  
  cout << fibI(250) << "\n";
  
  QueryPerformanceCounter(&end);
    
  std::cout << "The resolution of this timer is: " << freq.QuadPart << " Hz." << std::endl;
  std::cout << "Time to calculate some_operation(): " 
            << (end.QuadPart - start.QuadPart) * 1000000 / freq.QuadPart 
            << " microSeconds" << std::endl;
}