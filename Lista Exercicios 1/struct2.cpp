//	Exercicio Structs 2 - Lista 1 - Estrutura de dados
//	Danilo de Nadai Sicari - Turma 1 - Fatec Araras
// 	24/03/18

/****************************************************
Escrever um programa que cadastre o nome, a altura, 
o peso, o cpf e sexo de algumas pessoas. Com os 
dados cadastrados, em seguida localizar uma pessoas 
através do seu CPF e imprimir o seu IMC.
****************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#define MAX_PESSOAS 3

using namespace std;

typedef struct TPessoa{
	string nome;
	float altura;
	float peso;
	float imc;
	string cpf;
	string sexo;
};

TPessoa Pessoa[MAX_PESSOAS]; 
int idxPessoa;

void CadastroPessoa()
{
	char opt;
	if(idxPessoa < MAX_PESSOAS)
	{
		do
		{
			cout << "\n\nCadastro IMC Pessoa" << endl;
			cout << "\nNome: ";
			cin >> Pessoa[idxPessoa].nome;
			cout << "\nCPF: ";
			cin >> Pessoa[idxPessoa].cpf;
			cout << "\nSexo (M)asculino/(F)eminino: ";
			cin >> Pessoa[idxPessoa].sexo;
			cout << "\nAltura (m): ";
			cin >> Pessoa[idxPessoa].altura;
			cout << "\nPeso (kg): ";
			cin >> Pessoa[idxPessoa].peso;
			Pessoa[idxPessoa].imc = Pessoa[idxPessoa].peso / (Pessoa[idxPessoa].altura * Pessoa[idxPessoa].altura);
			cout << "\nIMC calculado: " << Pessoa[idxPessoa].imc << endl;
			
			cout << "Deseja cadastrar novamente? (S)im/(N)ao : ";
			cin >> opt;
			idxPessoa++;
		}while(opt == 'S' && idxPessoa < MAX_PESSOAS);
		if(opt == 'S' && idxPessoa >= MAX_PESSOAS)	cout << "\nAviso: Numero maximo de pessoas cadastradas!!";
	}
	else
		cout << "\nAviso: Numero maximo de pessoas cadastrados!!";
}

void ImprimePessoa()
{
	cout << "\n\nRelatorio Pessoas" << endl;
	for(int i = 0; i < idxPessoa; i++)	
		cout << "Pessoa ["<<i+1<<"] Nome: "<<Pessoa[i].nome<<" CPF: "<<Pessoa[i].cpf<<" Altura (m): "<<Pessoa[i].altura<<" Peso (kg)"<<Pessoa[i].peso<<" IMC: "<<Pessoa[i].imc<<" Sexo: "<<Pessoa[i].sexo<<endl;
}

void PesquisaPessoa()
{
	string cpf;
	bool r = false;
	cout << "\n\nPesquisar pessoas" << endl;
	cout << "\nCPF: ";
	cin >> cpf;
	cout << "\nResultado: " << endl;
	for(int i = 0; i < idxPessoa; i++)
	{
		if(cpf == Pessoa[i].cpf)
		{
			cout << "Pessoa ["<<i+1<<"] Nome: "<<Pessoa[i].nome<<" CPF: "<<Pessoa[i].cpf<<" Altura (m): "<<Pessoa[i].altura<<" Peso (kg): "<<Pessoa[i].peso<<" IMC: "<<Pessoa[i].imc<<" Sexo: "<<Pessoa[i].sexo<<endl;
			//Se encontrar, sair do loop
			i = idxPessoa;
			r = true;
		}	
	}
	if(r == false)
		cout << "\nCPF nao encontrado!";
}

int main(){
	int opt = 0;
	idxPessoa = 0;
	do
	{
		cout << "\n\nMenu cadastro IMC Pessoa" << endl;
		cout << "1 - Cadastrar Pessoa" << endl;
		cout << "2 - Imprimir Pessoas" << endl;
		cout << "3 - Pesquisar Pessoas" << endl;
		cout << "4 - Sair" << endl;
		cout << "Escolha a opcao desejada: ";
		cin >> opt;
		
		if(opt == 1)	CadastroPessoa();
		if(opt == 2)	ImprimePessoa();
		if(opt == 3)	PesquisaPessoa();
	
	}while(opt != 4);
	
	return 0;
}
