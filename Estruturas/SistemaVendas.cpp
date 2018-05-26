//	Sistema vendas
//	Exercicio Estruturas de dados 
//	17/03/18
#include <iostream>
#include <stdio.h>
#include <string.h>

#define MAX_PRODUTO 10
#define MAX_CLIENTE 10

using namespace std;

int idxProduto = 0, idxCliente = 0, produto[MAX_PRODUTO], cliente = 0;

typedef struct{
	int id;
	string nome;
}TCliente;

typedef struct{
	int id;
	string descricao;
	float valor;
}TProduto;

typedef struct{
	int id;
	int quantidade[MAX_PRODUTO];
	TCliente Cliente[MAX_CLIENTE];
	TProduto Produto[MAX_PRODUTO];	
}TPedido;

TPedido Pedido;

void cadastroProduto()
{
	if(idxProduto <= MAX_PRODUTO)
	{
		idxProduto++;
		cout << "\n\n----- Cadastro Produto -----" << endl;
		Pedido.Produto[idxProduto].id = idxProduto;
		cout << "ID: " << Pedido.Produto[idxProduto].id << endl;
		cout << "Descricao produto: ";
		cin >> Pedido.Produto[idxProduto].descricao;
		cout << "Valor (R$): ";
		cin >> Pedido.Produto[idxProduto].valor;
	}
}

void cadastroCliente()
{
	if(idxCliente <= MAX_CLIENTE)
	{
		idxCliente++;	
		cout << "\n\n----- Cadastro Cliente -----" << endl;
		Pedido.Cliente[idxCliente].id = idxCliente;
		cout << "ID: " << Pedido.Cliente[idxCliente].id << endl;
		cout << "Nome: ";
		cin >> Pedido.Cliente[idxCliente].nome;
	}
}

void imprimirProdutos()
{
	cout << "\n\n----- Relatorio Produtos -----" << endl;
	for(int i = 1; i <= idxProduto; i++)
	{
		cout << "-------------------------------------" << endl;
		cout << "ID: " << Pedido.Produto[i].id << endl;
		cout << "Descricao produto: " << Pedido.Produto[i].descricao << endl;
		cout << "Valor (R$): " << Pedido.Produto[i].valor << endl;
	}
}

void imprimirClientes()
{
	cout << "\n\n----- Relatorio Clientes -----" << endl;
	for(int i = 1; i <= idxCliente; i++)
	{
		cout << "-------------------------------------" << endl;
		cout << "ID: " << Pedido.Cliente[i].id << endl;
		cout << "Nome: " << Pedido.Cliente[i].nome << endl;
	}
}

void pedidoVenda()
{
	int menuVenda = 0;
	cout << "\n\n----- Pedido de venda -----" << endl;
	do
	{
		cout << "..:: Digite a opcao desejada ::.." << endl;
		cout << "(1) Inserir Produto" << endl;
		cout << "(2) Inserir Cliente" << endl;
		cout << "(3) Efetuar Venda" << endl;
		cout << "(4) Retornar ao menu principal" << endl;
		cin >> menuVenda;
		
		if(menuVenda == 1)
		{
			for(int i = 0; i < MAX_PRODUTO; i++)
			{			
				cout << "Codigo do produto a inserir: ";
				cin >> produto[i];
				cout << "Quantidade: ";
				cin >> Pedido.quantidade[i];
				cout << "Inserir mais um produto? (S)im / (N)ao";
				char r;
				cin >> r;
				if(r =='n')	i = MAX_PRODUTO;
			}
		}
		
		if(menuVenda == 2)
		{		
			cout << "Codigo do cliente a inserir: ";
			cin >> cliente;
		}
		
		if(menuVenda == 3)
		{
			float valorTotal = 0;
			cout << "\n\nVenda realizada - Mercadinho Zeze" << endl;
			cout << "\n..:: ITENS ::.." << endl;
			for(int i = 0; i < MAX_PRODUTO; i++)
			{
				if(Pedido.Produto[produto[i]].id != 0)
				{
					valorTotal += (Pedido.quantidade[i]*Pedido.Produto[produto[i]].valor);
					cout << "ITEM [" << i+1 << "] - ID_PRODUTO: " << Pedido.Produto[produto[i]].id << " DESC_PRODUTO: ";
					cout << Pedido.Produto[produto[i]].descricao << " VALOR: R$" << Pedido.Produto[produto[i]].valor;
					cout << " QTDE: " << Pedido.quantidade[i] << " VALOR TOTAL: R$ "; 
					cout << (Pedido.quantidade[i]*Pedido.Produto[produto[i]].valor) << endl;
				}
			}
			cout << "Total venda: R$" << valorTotal;
			cout << "\n..:: CLIENTE ::.." << endl;
			cout << "ID_CLIENTE: " << Pedido.Cliente[cliente].id << " NOME: " << Pedido.Cliente[cliente].nome << endl << endl;
		}
		
	}while(menuVenda != 4);
}

main()
{
	int menu = 0;
	
	do
	{
		cout << "\n\nSistema vendas - Mercadinho Zeze" << endl;
		cout << "..:: Digite a opcao desejada ::.." << endl;
		cout << "(1) Cadastro Produto" << endl;
		cout << "(2) Cadastro Cliente" << endl;
		cout << "(3) Imprimir Produtos" << endl;
		cout << "(4) Imprimir Clientes" << endl;
		cout << "(5) Realizar Venda" << endl;
		cout << "(6) Sair do Sistema" << endl;
		cin >> menu;
		
		if (menu == 1)	cadastroProduto();
		if (menu == 2)	cadastroCliente();
		if (menu == 3)	imprimirProdutos();
		if (menu == 4)  imprimirClientes();
		if (menu == 5)  pedidoVenda();
		
	}while(menu != 6);
	
}








