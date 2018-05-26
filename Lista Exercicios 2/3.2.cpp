 /*
*	Lista 2, exercicio 3.1
*	Danilo Sicari
*
*	Faça um programa para empilhar e desempilhar tarefas a serem feitas. Não há limite para as atividades que
*	você pode empilhar. Armazene o nome da tarefa, tempo necessário em horas (inteiro), código da pessoa
*	responsável pela tarefa, conforme tabela.
*
* 	3.1 - Crie uma função que crie e empilhe vinte tarefas de forma automática.
*	3.2 - Crie uma função que retorne a tarefa com maior tempo necessário para ser realizado.
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
		cout << "1 - Inserir nova tarefa" << endl;
		cout << "2 - Deletar ultima tarefa" << endl;
		cout << "3 - Listar tarefas" << endl;
		cout << "4 - Inserir 20 novas tarefas" << endl;	
		cout << "5 - Retirar 20 tarefas" << endl;
		cout << "6 - Tarefa com maior tempo execucao" << endl;
		cout << "7 - Sair" << endl;
		cout << "Digite a opcao desejada: ";
		cin >> opt;
		
		if(opt == 1){
			TTarefa TODO;
			cout << "\n\n -- NOVA TAREFA --" << endl;
			cout << "Insira descricao tarefa, sem espaco: ";
			cin >> TODO.nomeTarefa;
			cout << "Tempo necessario (H)?";
			cin >> TODO.tempo;
			cout << "Nome responsavel, sem espaco: ";
			cin >> TODO.responsavel;
			cout << "Codigo responsavel sera: " << ++codigoResponsavel;
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
			TTarefa TODO;
			for(char i = 0; i <= 20; i++)
			{			
				memcpy(&TODO.nomeTarefa, "tarefa", sizeof("tarefa"));
				TODO.tempo = i;
				memcpy(&TODO.responsavel, "Fulano", sizeof("Fulano"));
				TODO.codigo = ++codigoResponsavel;
				push(pilhaTarefas, &TODO);
				memset(&TODO, 0, sizeof(TTarefa));
			}
		}
		else if(opt == 5){
			for(int i = 0; i <= 20; i++)
			{
				if(!pop(pilhaTarefas))
					break;
			}
		}
		else if(opt == 6){			
			if(pilhaTarefas->top != NULL){
				
				TTarefa maxT;	
				maxT.tempo = 0;												
				Node* temp;
				temp = pilhaTarefas->top;						
										
				for(int i = 0; i <= pilhaTarefas->size; i++)
				{
					while(temp != NULL){
						if(temp->tarefa.tempo > maxT.tempo){
							maxT = pilhaTarefas->top->tarefa;		
						}
						temp = temp->next;
					}
				}	
				cout << "\nTAREFA COM MAIOR TEMPO: " << maxT.nomeTarefa << " - Tempo: " << maxT.tempo << " - Responsavel: " << maxT.responsavel << " - Codigo: " << maxT.codigo << endl;			
			}
			else
				cout << "\n\n -- -- -- -- Nao ha tarefas!! -- -- -- -- " << endl;						
		}
		else if(opt == 7){
			//sair programa
		}
		else{
			cout << "\n Aviso: Opcao Invalida!" << endl;
		}
	}while(opt!=7);

    return 0;
}
