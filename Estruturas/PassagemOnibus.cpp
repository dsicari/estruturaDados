//Venda de passagens de onibus - Utilizacao de estruturas
#include <stdio.h>
#include <iostream>

// Namespace
using namespace std;

//Estrutura
struct TOnibus{
	string nome;
	string doc;
	string hPartida;
	string hChegada;
	string cPartida;
	string cDestino;
	string valor;	
};

TOnibus cometa;

//Prototipo funcoes
void vendaPassagem();
void imprimirPassagem();

//Funcoes uteis
void vendaPassagem()
{
	cout << "\n\n -- VENDA DE PASSAGEM -- ";
	cout << "\nNome passageiro: ";
	cin >> cometa.nome;
	cout << "Documento passageiro: ";
	cin >> cometa.doc;
	cout << "Cidade partida: ";
	cin >> cometa.cPartida;
	cout << "Cidade destino: ";
	cin >> cometa.cDestino;
	cout << "Horario partida (HH:MM): ";	
	cin >> cometa.hPartida;
	cout << "Horario previsto chegada (HH:MM): ";	
	cin >> cometa.hChegada;
	cout << "Valor: ";
	cin >> cometa.valor;
	cout << "\n\n";
	imprimirPassagem();
}
void imprimirPassagem()
{
	cout << "----------- PASSAGEM -----------";
	cout << "\nPassageiro: " << cometa.nome;
	cout << "\nDocumento: " << cometa.doc;
	cout << "\nCidade partida: " << cometa.cPartida;
	cout << "\nCidade destino: " << cometa.cDestino;
	cout << "\nHorario partida: " << cometa.hPartida;
	cout << "\nHorario previsto chegada: " << cometa.hChegada;
	cout << "\nValor: R$ " << cometa.valor;
	cout << "\n--------------------------------\n\n";	
}

int main()
{
	int opc = 0;
	
	do
	{
		cout << "\n -- CIA COMETA DE ONIBUS ARARENSE -- ";
		cout << "\n1 - Venda de passagem";
		cout << "\n2 - Impressao passagem";
		cout << "\n3 - Sair";
		cout << "\nDigite a opcao desejada: ";
		cin >> opc;
		
		if(opc == 1)	vendaPassagem();
		else if(opc == 2)	imprimirPassagem();
		else if(opc != 3)	cout << "\n\n ** ERRO: Opcao Invalida! ** \n\n";	
	}while(opc != 3);
}
