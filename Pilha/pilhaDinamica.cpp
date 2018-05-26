/*
 * Exemplo do uso de pilha.
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 05/04/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>


using namespace std;

typedef struct node {
    int item;
    struct node *next;
} Node;

typedef struct {
    Node *top;
    int size;
} Pilha;

Pilha* inicializar() {
	//Alocar memoria para tipo Pilha
	//como malloc retorna um void*, fazemos cast para Pilha e entao alocamos em um apontador tipo Pilha
    Pilha *s = (Pilha*)malloc(sizeof(Pilha));
    s->size = 0;  // Setar o tamanho da pilha como zero.
    //top eh um apontador para estrutura node
    s->top = NULL; // topo pilha eh nulo
}

bool push(Pilha *s, int value) {
	// Criar um ponteiro de Node, pois necessitamos de um novo node na pilha
    Node *np;  
	
	// Como foi criado um ponteiro, alocar Node na memoria e apontar para o node criado np
    np = (Node*)malloc(sizeof(Node));  
    if (np == NULL) {
        return false;
    }

	// Setar o valor do Node (informacao a ser guardada na pilha)
    np->item = value; 
    // Copiar o ultimo node que estava no topo da pilha, para saber qual era o node anterior
    np->next = s->top;
	// O novo node criado (np) agora esta no topo da pilha 
    s->top = np; 
 	// Incrementar o tamanho do contador de pilha
    s->size++;
    
    return true;
}

int pop(Pilha *s) {	

    //Criar no temporario
    Node *np;

	//Se top for nulo, nao temos o que retirar da pilha
    if (s->top == NULL) {
        return false;
    }

    np = s->top; // Um ponteiro de node esta apontando para o topo da pilha, que tambem ้ um node.
    //Vamos retornar verdadeiro ou falso, e por referencia retornar o valor do node topo que sera feito o pop ** a ser feito **
    /*temp = s->top->item; // armazenar em temp o valor corrente do topo da pilha.*/ // Somente necessario se quiser retornar um inteiro. 
    s->top = np->next; // fazer o topo da pilha apontar para o nรณ abaixo
    s->size--; // decrementar o tamanho da pilha
    free(np); // desalocar o node temporario

    return true;
}

void destruir_pilha(Pilha *s) {
	//enquanto top nao for diferente de nulo, ou seja nao for vazio, fazer o pop da pilha
    while (s->top != NULL) {
        pop(s);
    }
    //Por que pop() aqui?
    pop(s);
    free(s);
}

bool imprime_pilha(Pilha *s) {
	//Cria um node temporario
	Node* temp;

	//Se top for nulo, ou seja se nao houver um node nos elementos da pilha, retornar
    if (s->top == NULL) {
        return false;
    }
    
    //node temporario recebe o node que esta no topo da lista
	temp = s->top;
	//imprime tamanho da pilha
    printf("# %d \n",s->size);
    //Enquanto node temp nao for nulo, ou seja, enquanto nao esvaziar a pilha
	while(temp!=NULL){
		//Imprima o item (um tipo inteiro) da pilha
		printf("%d ",temp->item);
		//node temp recebe o proximo node apontado pelo temp anterior 
		temp = temp->next;
	}

	printf("\n");
	
	return true;
}

int main() {
    int valor;

	//inicializar retorna um apontar tipo Pilha, ou seja, o bloco de memoria que foi alocado para ela
    Pilha *minha_pilha = inicializar();
    
    if(!imprime_pilha(minha_pilha))
    	cout << "Pilha vazia" << endl;
    
    push(minha_pilha, 7);
    
    if(!imprime_pilha(minha_pilha))
    	cout << "Pilha vazia" << endl;
    	
    push(minha_pilha, 9);
    push(minha_pilha, 3);
    push(minha_pilha, 6);
    push(minha_pilha, 2);
    push(minha_pilha, 1);
    
    if(!imprime_pilha(minha_pilha))
    	cout << "Pilha vazia" << endl;

    valor = pop(minha_pilha);
    printf("Valor desempilhado:\t %d\n", valor);
    valor = pop(minha_pilha);
    printf("Valor desempilhado:\t %d\n", valor);

    if(!imprime_pilha(minha_pilha))
    	cout << "Pilha vazia" << endl;

    valor = pop(minha_pilha);
    printf("Valor desempilhado:\t %d\n", valor);

    valor = pop(minha_pilha);
    printf("Valor desempilhado:\t %d\n", valor);

    destruir_pilha(minha_pilha);
    return 0;
}
