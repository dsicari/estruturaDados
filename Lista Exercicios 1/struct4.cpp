//	Exercicio Structs 4 - Lista 1 - Estrutura de dados
//	Danilo de Nadai Sicari - Turma 1 - Fatec Araras
// 	24/03/18

/*****************************************************************************
Escreva um programa que simule contas bancárias, com as seguintes especificações:
	- Ao iniciar o programa vamos criar contas bancárias para três clientes.
	- Cada conta terá o nome e o CPF do cliente associado a ela.
	- No ato da criação da conta o cliente precisará fazer um depósito
inicial.
	- Após as contas serem criadas, o sistema deverá possibilitar realizações
de saques ou depósitos nas contas.
	- Sempre que uma operação de saque ou depósito seja realizada, o
sistema deverá imprimir o nome do titular e o saldo final da conta

******************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#define MAX_CONTAS 3

using namespace std;

void AbrirConta();
int MovimentoConta(string cpf, int movimento, float valor);
void MovimentarConta();

typedef struct TConta{
	string nome;
	string cpf;
	float saldo;
};

TConta Conta[MAX_CONTAS]; 
int idxConta = 0;

void AbrirConta()
{
	char opt;
	if(idxConta < MAX_CONTAS)
	{
		do
		{
			cout << "\n\nAbrir nova conta" << endl;
			cout << "\nNome: ";
			cin >> Conta[idxConta].nome;
			cout << "\nCPF: ";
			cin >> Conta[idxConta].cpf;
			cout << "\nDeposito inicial (R$): ";
			cin >> Conta[idxConta].saldo; 

			cout << "Deseja cadastrar novamente? (S)im/(N)ao : ";
			cin >> opt;
			idxConta++;
		}while(opt == 'S' && idxConta < MAX_CONTAS);
		if(opt == 'S' && idxConta >= MAX_CONTAS)	cout << "\nAviso: Numero maximo de contas abertas!!";
	}
	else
		cout << "\nAviso: Numero maximo de contas abertas!!";
}

void MovimentarConta(){
	int mov = 0;
	string cpf = "";
	float valor;
	int rslt = 0;
	
	cout << "\n\nMovimentar Conta" << endl;
	cout << "1 - Saque" << endl;
	cout << "2 - Deposito" << endl;
	cout << "Escolha o tipo de movimento a ser realizado: ";
	cin >> mov;
	cout << "CPF do titular da conta: ";
	cin >> cpf;
	cout << "Valor (R$): ";
	cin >> valor;
	rslt = MovimentoConta(cpf, mov, valor);
	
	if (rslt == 0)
		cout << "\nOperacao concluida com sucesso" << endl;
	else if (rslt == 1)
		cout << "\nERROR: CPF invalido" << endl;	 
}

int MovimentoConta(string cpf, int movimento, float valor)
{
	//movimento
	//	1: SAQUE
	//	2: DEPOSITO
	
	//return
	//	0: SUCCESS
	//	1: CPF INVALIDO

	int rslt = 0;
	bool r = false;
	int index = 0;
	for(int i = 0; i < idxConta && r == false; i++)
	{
		if(cpf == Conta[i].cpf)
		{
			cout << "Conta ["<<idxConta<<"] Titular: "<<Conta[i].nome<<" CPF: "<<Conta[i].cpf<<" Saldo atual (R$): "<<Conta[i].saldo<<endl;
			index = i;
			//Se encontrar, sair do loop
			r = true;
		}	
	}
	//Encontrou conta?
	if(r == false)
		rslt = 1;
	else
	{
		if(movimento == 1)
		{
			cout << "\n Movimento solicitado: SAQUE, Valor (R$): " << valor << endl;
			Conta[index].saldo -= valor;
			cout << "Saldo atual (R$): " << Conta[index].saldo <<endl;
		}
		else if(movimento == 2)
		{
			cout << "\n Movimento solicitado: DEPOSITO, Valor (R$): " << valor << endl;
			Conta[index].saldo += valor;
			cout << "Saldo atual (R$): " << Conta[index].saldo <<endl;
		}	
	}
	return rslt;
}

int main(){
	int opt = 0;
	do
	{
		cout << "\n\nMenu Banco *DevoENaoNego*" << endl;
		cout << "1 - Abrir Conta" << endl;
		cout << "2 - Movimentar Conta" << endl;
		cout << "3 - Sair" << endl;
		cout << "Escolha a opcao desejada: ";
		cin >> opt;
		
		if(opt == 1)	AbrirConta();
		if(opt == 2)	MovimentarConta();
	
	}while(opt != 3);
	
	return 0;
}


