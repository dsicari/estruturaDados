//Exemplo Estruturas
#include <stdio.h>
#include <iostream>
//Acerta acentos no codigo
#include <locale.h>>

// Namespace
using namespace std;

//Declarando estrutura, tipo I
struct TAluno{
	string nome;
	string endereco;
};

TAluno aluno2;

//Declarando estrutura, tipo II
struct TRecreio{
	int inicio;
	int fim;
}Manha, Tarde, Noite;

//Declarando estrutura, tipo III
typedef struct{
	string escola;
}TEscola;

TEscola teste;

main()
{
	
	aluno2.nome = "Ferdinando";
	aluno2.endereco = "Rua sem saida";
	
	Manha.inicio = 9;
	Manha.fim = 10;
	Tarde.inicio = 14;
	Tarde.fim = 15;
	Noite.inicio = 20;
	Noite.fim = 21;
	
	teste.escola = "Educare";
	
	cout << aluno2.nome << " que reside no endereco: " << aluno2.endereco << " estuda na escola: " << teste.escola;
	cout << "\nSeu recreio inicia as: " << Manha.inicio << " e encerra as: " << Tarde.fim;
	
}
