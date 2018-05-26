//	Exercicio Structs 1 - Lista 1 - Estrutura de dados
//	Danilo de Nadai Sicari - Turma 1 - Fatec Araras
// 	24/03/18

/******************************************************
Escrever um programa que cadastre o nome, a matrícula e 
duas notas de vários alunos. Em seguida imprima a 
matrícula, o nome e a média de cada um deles.
******************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#define MAX_ALUNOS 3

using namespace std;

typedef struct TAluno{
	string nome;
	string matricula;
	float nota[2];
	float media;
};

TAluno Aluno[MAX_ALUNOS]; 
int idxAluno;

void CadastroAluno()
{
	char opt;
	if(idxAluno < MAX_ALUNOS)
	{
		do
		{
			cout << "\n\nCadastro Nota Aluno" << endl;
			cout << "Nome: ";
			cin >> Aluno[idxAluno].nome; 
			cout << "\nMatricula: ";
			cin >> Aluno[idxAluno].matricula;
			cout << "\nNota 1: ";
			cin >> Aluno[idxAluno].nota[0];
			cout << "\nNota 2: ";
			cin >> Aluno[idxAluno].nota[1];
			Aluno[idxAluno].media = (Aluno[idxAluno].nota[0] + Aluno[idxAluno].nota[1]) / 2;
			cout << "Deseja cadastrar novamente? (S)im/(N)ao : ";
			cin >> opt;
			idxAluno++;
		}while(opt == 'S' && idxAluno < MAX_ALUNOS);
		if(opt == 'S' && idxAluno >= MAX_ALUNOS)	cout << "\nAviso: Numero maximo de alunos cadastrados!!";
	}
	else
		cout << "\nAviso: Numero maximo de alunos cadastrados!!";
}

void ImprimeAluno()
{
	cout << "\n\nRelatorio Alunos" << endl;
	for(int i = 0; i < idxAluno; i++)	
		cout << "Aluno ["<<i+1<<"] Matricula["<<Aluno[i].matricula<<"]1: "<<Aluno[i].nome<<", Nota 1: "<<Aluno[i].nota[0]<<", Nota 2: "<<Aluno[i].nota[1]<<", Media: "<<Aluno[i].media<<endl;
}

int main(){
	int opt = 0;
	idxAluno = 0;
	do
	{
		cout << "\n\nMenu cadastro nota aluno" << endl;
		cout << "1 - Cadastrar nota" << endl;
		cout << "2 - Imprimir notas" << endl;
		cout << "3 - Sair" << endl;
		cout << "Escolha a opcao desejada: ";
		cin >> opt;
		
		if(opt == 1)	CadastroAluno();
		if(opt == 2)	ImprimeAluno();
	
	}while(opt != 3);
	
	return 0;
}
