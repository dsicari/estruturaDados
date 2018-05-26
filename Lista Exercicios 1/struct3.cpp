//	Exercicio Structs 3 - Lista 1 - Estrutura de dados
//	Danilo de Nadai Sicari - Turma 1 - Fatec Araras
// 	24/03/18

/*****************************************************
Escrever um programa que cadastre vários produtos. 
Em seguida, imprima uma lista com o código e nome da 
cada produto. Por último, consulte o preço de um 
produto através de seu código.
*****************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#define MAX_PRODUTOS 3

using namespace std;

typedef struct TProduto{
	int cdg;
	string nome;
};

TProduto Produto[MAX_PRODUTOS]; 
int idxProduto = 0;

void CadastroProduto()
{
	char opt;
	if(idxProduto < MAX_PRODUTOS)
	{
		do
		{
			cout << "\n\nCadastro Produto" << endl;
			cout << "\nNome: ";
			cin >> Produto[idxProduto].nome;
			Produto[idxProduto].cdg = idxProduto + 1;
			cout << "\nCodigo associado: " << Produto[idxProduto].cdg << endl;

			cout << "Deseja cadastrar novamente? (S)im/(N)ao : ";
			cin >> opt;
			idxProduto++;
		}while(opt == 'S' && idxProduto < MAX_PRODUTOS);
		if(opt == 'S' && idxProduto >= MAX_PRODUTOS)	cout << "\nAviso: Numero maximo de produtos cadastrados!!";
	}
	else
		cout << "\nAviso: Numero maximo de produtos cadastrados!!";
}

void ImprimeProduto()
{
	cout << "\n\nRelatorio Produtos" << endl;
	for(int i = 0; i < idxProduto; i++)	
		cout << "Produto CODIGO["<<Produto[i].cdg<<"]: "<<Produto[i].nome<<endl;
}

void PesquisaProduto()
{
	int cdg;
	bool r = false;
	cout << "\n\nPesquisar produto"<< endl;
	cout << "\nCODIGO: ";
	cin >> cdg;
	cout << "\nResultado: " << endl;
	for(int i = 0; i < idxProduto && r == false; i++)
	{
		if(cdg == Produto[i].cdg)
		{
			cout << "Produto CODIGO["<<Produto[i].cdg<<"]: "<<Produto[i].nome<<endl;
			//Se encontrar, sair do loop
			r = true;
		}	
	}
	if(r == false)
		cout << "\nCODIGO nao encontrado!";
}

int main(){
	int opt = 0;
	do
	{
		cout << "\n\nMenu cadastro produto" << endl;
		cout << "1 - Cadastrar Produto" << endl;
		cout << "2 - Imprimir Produtos" << endl;
		cout << "3 - Pesquisar Produto" << endl;
		cout << "4 - Sair" << endl;
		cout << "Escolha a opcao desejada: ";
		cin >> opt;
		
		if(opt == 1)	CadastroProduto();
		if(opt == 2)	ImprimeProduto();
		if(opt == 3)	PesquisaProduto();
	
	}while(opt != 4);
	
	return 0;
}


