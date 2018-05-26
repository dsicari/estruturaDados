/*	
*	Lista 2, exercicio 2
*	Danilo Sicari
*
*	Ao navegar na internet, a cada site acessado, o endereço é armazenado em uma pilha. Ao clicar em voltar,
*	pode-se acessar novamente o endereço anteriormente visitado.
*	Faça um programa que simule as funcionalidades de acessar um site e voltar. Ao empilhar, armazenar o
*	endereço http. Ao desempilhar, retornar o endereço http. Não há limite de sites que podem ser acessados.
*	Armazene o endereço http. A entrada de dados deve ocorrer dentro da função de empilhamento.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

typedef struct node {
    char item[128];
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

bool push(Pilha *s, char value[]) {
	
	Node *np;  
	
    np = (Node*)malloc(sizeof(Node));  
    if (np == NULL) {
        return false;
    }

	memcpy(np->item, value, 128);
    np->next = s->top;
    s->top = np; 
    s->size++;
	    
    return true;
}

bool pop(Pilha *s, char url[]) {

    Node *np;

    if (s->top == NULL) {
        return false;
    }

    np = s->top;
	memcpy(url, s->top->item, 128);
    s->top = np->next;
    s->size--;
    free(np);

    return true;
}

void destruir_pilha(Pilha *s) {
    char url[128] = {};
	while (s->top != NULL) {
        pop(s, url);
    }
    pop(s, url);
    free(s);
}

bool imprime_pilha(Pilha *s) {

	Node* temp;
	
    if (s->top == NULL) {
        return false;
    }
    
	temp = s->top;
    printf("# %d \n",s->size); 
	while(temp!=NULL){
		printf("%s\n",temp->item);
		temp = temp->next;
	}
	printf("\n");
	
	return true;
}

int main() {
	
	char url[128] = "";

	//inicializar retorna um apontar tipo Pilha, ou seja, o bloco de memoria que foi alocado para ela
    Pilha *minha_pilha = inicializar();
    
	int opt = 0;
	do{
		memset(url, 0, 128);
		
		cout << "\n\nBROWSER ROX" << endl;
		cout << "1 - Acessar URL" << endl;
		cout << "2 - Voltar" << endl;
		cout << "3 - Listar URLs" << endl;	
		cout << "4 - Sair" << endl;
		cin >> opt;
		
		if(opt == 1){
			cout << "Digite a URL: " << endl;
			cin >> url;
			push(minha_pilha, url);
		}
		else if(opt == 2){
			if(!pop(minha_pilha, url))
				cout << "Sem URL";			
			if (minha_pilha->top != NULL) {
				cout << "last page:" << url << endl;
				cout << "main page: " << minha_pilha->top->item << endl;	
			}
			
		}
		else if(opt == 3){
			if(!imprime_pilha(minha_pilha))
				cout << "Browser sem URLs" << endl;
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
