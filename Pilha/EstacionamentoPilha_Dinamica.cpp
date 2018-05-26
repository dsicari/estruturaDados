//	
//	Programa Estacionamento - Utilizando pilha estatica
//	Danilo Sicari - 14 / 04 / 2018
//

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#define STACK_MAX 3

using namespace std;

// ---------- CARRO

struct TCarro{
	string placa;
	string modelo;
	string ano;
};

int idxCarro;

// ---------- PILHA

struct Pilha {
    TCarro  carro[STACK_MAX];
    int     size;
};

void inicializar(Pilha *S) {
    S->size = 0;
}

void push(Pilha *S, string placa, string  ano, string modelo) {
    if (S->size < STACK_MAX)
    {
    	S->size++;
       	S->carro[S->size].placa = placa;
       	S->carro[S->size].ano = ano;
       	S->carro[S->size].modelo = modelo;
	}
    else
        fprintf(stderr, "Erro: pilha cheia\n");
}
/*
int pop(Pilha *S) {
    int retorno;
    if (S->size == 0) {
        fprintf(stderr, "Erro: pilha vazia\n");
        exit(-1);
    } else {
        S->size--;
        retorno = S->data[S->size];
        S->data[S->size] = 0;
        return(retorno);
    }
}*/
/*
void imprime_pilha(Pilha *S) {
    int x;
	for (x = S->size; x > 0 ; x--)
		printf("%d ",S->data[x-1]);
	printf("\n");
}*/

// ---------- FUNCOES ESTACIONAMENTO

void EstacionarCarro(Pilha *pilha){
	char opt;
	if(idxCarro < STACK_MAX)
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
			idxCarro++;
		}while(opt == 'S' && idxCarro < STACK_MAX);
		if(opt == 'S' && idxCarro >= STACK_MAX)	cout << "\nAviso: Nao ha mais vagas!!";
	}
	else
		cout << "\nAviso: Nao ha mais vagas!!";
}
/*
void CheckOutCarro(Pilha *pilha, TCarro *car) {
	if(idxCarro > 0)
	{
		int i = pop(pilha);
		idxCarro--;
		cout << "\n\nCHECKOUT ULTIMO CARRO" << endl;
		cout << "\nPlaca: " << car[i].placa << " Modelo: " << car[i].modelo << " Ano:" << car[i].ano << endl; 
	}
	else
		cout << "\nAviso: Nao ha mais carros estacionados!";
}
*/
void ListarCarros(Pilha *pilha){
	if(pilha->size > 0)
	{
		for (int i = pilha->size; i > 0 ; i--)
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
		//else if(opt == 2)	CheckOutCarro(&parkLot);
		else if(opt == 3)	ListarCarros(&parkLot);
		else 				cout << "\n Aviso: Opcao Invalida!" << endl;
		
	}while(opt != 4);
	
	return 0;
	
}


