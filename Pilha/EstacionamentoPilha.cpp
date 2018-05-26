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
    int     data[STACK_MAX];
    int     size;
};

void inicializar(Pilha *S) {
    S->size = 0;
}

void push(Pilha *S, int d) {
    if (S->size < STACK_MAX)
        S->data[S->size++] = d;
    else
        fprintf(stderr, "Erro: pilha cheia\n");
}

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
}

void imprime_pilha(Pilha *S) {
    int x;
	for (x = S->size; x > 0 ; x--)
		printf("%d ",S->data[x-1]);
	printf("\n");
}

// ---------- FUNCOES ESTACIONAMENTO

void EstacionarCarro(Pilha *pilha, TCarro *car){
	char opt;
	if(idxCarro < STACK_MAX)
	{
		do
		{
			//Informacoes carro
			cout << "\n\nESTACIONAR CARRO" << endl;
			cout << "\nPlaca: ";
			cin >> car[idxCarro].placa;
			cout << "\nModelo: ";
			cin >> car[idxCarro].modelo;
			cout << "\nAno: ";
			cin >> car[idxCarro].ano;
			//Inserir na pilha
			push(pilha, idxCarro);
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

void ListarCarros(Pilha *pilha, TCarro *car){
	if(pilha->size > 0)
	{
		for (int x = pilha->size; x > 0 ; x--)
		{
			int i = pilha->data[x-1];
			cout << "Vaga[" << x << "]: " << car[i].placa << " " << car[i].modelo << " " << car[i].ano << endl;
		}
	}
	else
		cout << "Aviso: Estacionamento Vazio!" << endl;
}

int main(){
	
	Pilha parkLot;
	TCarro Carro[STACK_MAX];
	
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
		
		if(opt == 1)		EstacionarCarro(&parkLot, &Carro[0]);
		else if(opt == 2)	CheckOutCarro(&parkLot, &Carro[0]);
		else if(opt == 3)	ListarCarros(&parkLot, &Carro[0]);
		else 				cout << "\n Aviso: Opcao Invalida!" << endl;
		
	}while(opt != 4);
	
	return 0;
	
}


