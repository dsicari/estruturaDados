/*	
*	Lista 2, exercicio 1 - Utilizando pilha estatica
*	Danilo Sicari
*	
*	Um estacionamento possui uma única entrada/saída e a capacidade máxima para guardar dez carros. Faça um
*	programa que simule a entrada ( empilhar ) e saída ( desempilhar) de carros deste estacionamento. Armazene
*	a placa, modelo e ano de cada carro estacionado. A entrada de dados deve ocorrer dentro da função de
*	empilhamento.
*
*	Funções esperadas:
*	• Estacionar carro
*	• Chek-out de carro
*	• Listar carros estacionados
*
*/


#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

// ---------- CARRO

struct TCarro{
	string placa;
	string modelo;
	string ano;
};

// ---------- PILHA

struct Pilha {
    TCarro  carro[STACK_MAX];
    int     size;
};

void inicializar(Pilha *S) {
    S->size = 0;
}

bool push(Pilha *S, string placa, string  ano, string modelo) {
    if (S->size < STACK_MAX)
    {    	
       	S->carro[S->size].placa = placa;
       	S->carro[S->size].ano = ano;
       	S->carro[S->size].modelo = modelo;
       	S->size++;
       	return true;
	}
    else
        return false;
}

bool pop(Pilha *S) {
    if (S->size == 0) {
        return false;
    } else {
        S->size--;
        memset(&S->carro[S->size], 0, sizeof(S->carro[S->size]));
        return true;
    }
}

// ---------- FUNCOES ESTACIONAMENTO

void EstacionarCarro(Pilha *pilha){
	char opt;
	if(pilha->size < STACK_MAX)
	{
		do
		{
			string placa, modelo, ano;
			//Informacoes carro
			cout << "\n\nESTACIONAR CARRO" << endl;
			cout << "\nPlaca: ";
			cin >> placa;
			cout << "\nModelo: ";
			cin >> modelo;
			cout << "\nAno: ";
			cin >> ano;
			//Inserir na pilha
			push(pilha, placa, modelo, ano);
			//Quanto carros estacionados?
			cout << "\nHa " << pilha->size << " de " << STACK_MAX << " carros estacionados.";
			cout << "\nDeseja cadastrar novamente? (S)im/(N)ao : ";
			cin >> opt;
		}while(opt == 'S' && pilha->size < STACK_MAX);
		if(opt == 'S' && pilha->size >= STACK_MAX)	cout << "\nAviso: Nao ha mais vagas!!";
	}
	else
		cout << "\nAviso: Nao ha mais vagas!!";
}

void CheckOutCarro(Pilha *pilha) {
	if(pilha->size > 0)
	{		
		cout << "\n\nCHECKOUT ULTIMO CARRO" << endl;
		cout << "\nPlaca: " << pilha->carro[pilha->size-1].placa << " Modelo: " << pilha->carro[pilha->size-1].modelo << " Ano:" << pilha->carro[pilha->size-1].ano << endl; 
		if(!pop(pilha))
		{
			cout << "!---- FALHOU ----!" << endl;
		}
	}
	else
		cout << "\nAviso: Nao ha mais carros estacionados!";
}

void ListarCarros(Pilha *pilha){
	if(pilha->size > 0)
	{
		for (int i = pilha->size - 1; i >= 0 ; i--)
		{
			cout << "Vaga[" << i << "]: " << pilha->carro[i].placa << " " << pilha->carro[i].ano  << " " << pilha->carro[i].modelo << endl;
		}
	}
	else
		cout << "Aviso: Estacionamento Vazio!" << endl;
}

int main(){
	
	Pilha parkLot;
	
	inicializar(&parkLot);	

	int opt = 0;
	do
	{	
		cout << "\n\nESTACIONAMENTO PARKLOT" << endl;
		cout << "1 - Estacionar carro" << endl;
		cout << "2 - Check-Out ultimo carro" << endl;
		cout << "3 - Listar carros estacionados" << endl;
		cout << "4 - Sair" << endl;
		cout << "Digite a opcao desejada: ";
		cin >> opt;
		
		if(opt == 1)		EstacionarCarro(&parkLot);
		else if(opt == 2)	CheckOutCarro(&parkLot);
		else if(opt == 3)	ListarCarros(&parkLot);
		else if(opt == 4)
		else 				cout << "\n Aviso: Opcao Invalida!" << endl;
		
	}while(opt != 4);
	
	return 0;
	
}


