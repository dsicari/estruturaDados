//	Ponteiros e Vetores
//	Exemplo 1 
//	17/03/18

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

main(){
	int q = 1, w, e, r;	
	//& acessa o endereco da memoria
	cout << "Endereco q: " << &q << endl << "Endereco w: " << &w << endl << "Endereco e: " << &e << endl << "Endereco r: " << &r << endl ;
	//Declara variavel como ponteiro
	int *ptr;
	//Ponteiro recebe endereco da variavel
	ptr = &q;
	cout << "Ponteiro apontando para endereco q: " << ptr << endl;
	//*ptr acessa o valor da memoria para a qual foi apontado, no caso aponta para o valor de q, pois fizemos ptr = &q; 
	cout << "Ponteiro apontando para valor endereco " << ptr << ": " << *ptr << endl;
	//Alterando o valor de *ptr, vc estara alterando o valor de q, pois ptr->q
	cout << "Alterando valor: " << *ptr << " do endereco: " << ptr << " para 100 pelo ponteiro" << endl;
	*ptr = 100;
	cout << "Ponteiro apontando para valor endereco " << ptr << ": " << *ptr << endl; 
	
	
}

