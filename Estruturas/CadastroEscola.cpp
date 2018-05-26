//Cadastro de funcionarios e professores - Utilizacao de estruturas
#include <stdio.h>
#include <iostream>

// Namespace
using namespace std;

//Estruturas
struct TEndereco{
	string rua;
	string numero;
	string complemento;
	string bairro;	
};

typedef struct{
	string nome;
	string doc;
	TEndereco Endereco;
	string sexo;
	string telefone;
	string email;
	string funcao;
}TPessoa;

TPessoa cadastro;

//Prototipo funcoes
void cadastroFuncionario();
void imprimirCadastro();

//Funcoes uteis
void cadastroFuncionario()
{
	cout << "\n\n -- CADASTRO -- ";
	cout << "\nNome: ";
	cin >> cadastro.nome;
	cout << "Documento: ";
	cin >> cadastro.doc;
	cout << "Endereco: ";
	cin >> cadastro.Endereco.rua;
	cout << "Numero: ";
	cin >> cadastro.Endereco.numero;
	cout << "Complemento: ";
	cin >> cadastro.Endereco.complemento;
	cout << "Bairro: ";
	cin >> cadastro.Endereco.bairro;
	cout << "Sexo (M/F): ";
	cin >> cadastro.sexo;
	cout << "E-mail: ";
	cin >> cadastro.email;
	cout << "Profissao: ";
	cin >> cadastro.funcao;
	cout << "\n\n";
	imprimirCadastro();
}
void imprimirCadastro()
{
	cout << "----------- CADASTRO -----------";
	cout << "\nNome: " << cadastro.nome;
	cout << "\nDocumento: " << cadastro.doc;
	cout << "\nEndereco: " << cadastro.Endereco.rua;
	cout << "\nNumero: " << cadastro.Endereco.numero;
	cout << "\nComplemento: " << cadastro.Endereco.complemento;
	cout << "\nBairro: " << cadastro.Endereco.bairro;
	cout << "\nSexo (M/F): " << cadastro.sexo;
	cout << "\nE-mail: " << cadastro.email;
	cout << "\nProfissao: " << cadastro.funcao;	
	cout << "\n--------------------------------\n\n";	
}

int main()
{
	int opc = 0;
	
	do
	{
		cout << "\n -- ESCOLA ZEH BIGODE -- ";
		cout << "\n1 - Cadastrar funcionario";
		cout << "\n2 - Imprimir cadastro";
		cout << "\n3 - Sair";
		cout << "\nDigite a opcao desejada: ";
		cin >> opc;
		
		if(opc == 1)	cadastroFuncionario();
		else if(opc == 2)	imprimirCadastro();
		else if(opc != 3)	cout << "\n\n ** ERRO: Opcao Invalida! ** \n\n";	
	}while(opc != 3);
}
