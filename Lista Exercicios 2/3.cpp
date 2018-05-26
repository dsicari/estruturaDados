/*
*	Lista 2, exercicio 3
*	Danilo Sicari
*
*	Faça um programa para empilhar e desempilhar tarefas a serem feitas. Não há limite para as atividades que
*	você pode empilhar. Armazene o nome da tarefa, tempo necessário em horas (inteiro), código da pessoa
*	responsável pela tarefa, conforme tabela.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

typedef struct{
	char nomeTarefa[128];
	int tempo;
	int codigo;
	char responsavel[128];	
}TTarefa;

typedef struct node {
    TTarefa tarefa;
    struct node *next;
} Node;

typedef struct {
    Node *top;
    int size;
} Pilha;

Pilha* inicializar() {
    Pilha *s = (Pilha*)malloc(sizeof(Pilha));
    s->size = 0; 
    s->top = NULL; 
}

bool push(Pilha *s, TTarefa *task) {
	
	Node *np;  
	
    np = (Node*)malloc(sizeof(Node));  
    if (np == NULL) {
        return false;
    }

	//memcpy(np->tarefa, task, sizeof(TTarefa));
	np->tarefa = *task;
    np->next = s->top;
    s->top = np; 
    s->size++;
	    
    return true;
}

bool pop(Pilha *s) {

    Node *np;

    if (s->top == NULL) {
        return false;
    }

    np = s->top;
    s->top = np->next;
    s->size--;
    free(np);

    return true;
}

void destruir_pilha(Pilha *s) {
	while (s->top != NULL) {
        pop(s);
    }
    pop(s);
    free(s);
}

bool imprime_pilha(Pilha *s) {

	Node* temp;
	
    if (s->top == NULL) {
        return false;
    }
    
	temp = s->top;
    printf("\n\n# %d \n",s->size); 
	while(temp!=NULL){
		cout << "\nTAREFA: " << temp->tarefa.nomeTarefa << " - Tempo: " << temp->tarefa.tempo << " - Responsavel: " << temp->tarefa.responsavel << " - Codigo: " << temp->tarefa.codigo << endl;
		temp = temp->next;
	}
	printf("\n");
	
	return true;
}

int main() {
	
    Pilha *pilhaTarefas = inicializar();
    
    //o codigo do responsavel pela tarefa nao se repete!!
	static int codigoResponsavel = 0;
	
	int opt = 0;
	do{
		
		cout << "\n\nTAREFAS DA MAMAE" << endl;
		cout << "1 - Nova tarefa" << endl;
		cout << "2 - Deletar ultima tarefa" << endl;
		cout << "3 - Listar tarefas" << endl;	
		cout << "4 - Sair" << endl;
		cin >> opt;
		
		if(opt == 1){
			TTarefa TODO;
			cout << "\n\n -- NOVA TAREFA --" << endl;
			cout << "Insira descricao tarefa, sem acentos: ";
			cin >> TODO.nomeTarefa;
			cout << "Tempo necessario (H)?";
			cin >> TODO.tempo;
			cout << "Nome responsavel, sem acentos: ";
			cin >> TODO.responsavel;
			cout << "Codigo responsavel sera: 000" << ++codigoResponsavel;
			TODO.codigo = codigoResponsavel;
			push(pilhaTarefas, &TODO);			
		}
		else if(opt == 2){
			if(!pop(pilhaTarefas))
				cout << "\n\n -- -- -- -- Nao ha tarefas a retirar!! -- -- -- -- " << endl;
		}
		else if(opt == 3){
			if(!imprime_pilha(pilhaTarefas))
				cout << "\n\n -- -- -- -- Nao ha tarefas!! -- -- -- -- " << endl; 
		}
		else if(opt == 4){
			//sair programa
		}
		else{
			cout << "\n Aviso: Opcao Invalida!" << endl;
		}
	}while(opt!=4);

    return 0;
}
