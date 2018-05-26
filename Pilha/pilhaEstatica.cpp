/*
 * Exemplo do uso de pilha com uso de vetor.
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 05/04/2018
 */
#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX 3

struct Pilha {
    int     data[STACK_MAX];
    int     size;
};

void inicializar(Pilha *S) {
    S->size = 0;
}

void push(Pilha *S, int d) {
    if (S->size < STACK_MAX)
    {
    	//Quando lista for vazia: sera guardado o dado em DATA[SIZE++]
    	//que em suma seria DATA[0] e somente apos o comando, SIZE incrementara e entao
    	// SIZE da PILHA = 1
    	S->data[S->size++] = d;
	}        
    else
        fprintf(stderr, "Erro: pilha cheia\n");
}

int pop(Pilha *S) {
    int retorno;
    if (S->size == 0) {
        fprintf(stderr, "Erro: pilha vazia\n");
        exit(-1);
    } else {
    	//Decrementa o tamanho da pilha pelo fato de o size estar 1 elemento a frente do
    	//indice de data e tambem por que 1 elemento da pilha sera descartado
        S->size--;
        //Retornar o valor de DATA[SIZE]
        //_TEST_ Poderiamos tentar, sem decrementar antes o size, com apenas: retorno = S->data[S->--size]; 
        retorno = S->data[S->size];
        //Zera o valor que estava na pilha
        S->data[S->size] = 0;
        return(retorno);
    }
}

void imprime_pilha(Pilha *S) {
    int x;
    printf("\n");
    //Do tamanho total da pilha, decrementar ate size 1
	for (x = S->size; x > 0 ; x--)
		//Defasagem de 1 com o index, pois nossa referencia aqui esta sendo o size
		printf("%d ",S->data[x-1]);
	printf("\n");
}

int main() {
    Pilha minhaPilha;
    int valor;

    inicializar(&minhaPilha);

	printf("\nPush pilha valor 7");
    push(&minhaPilha, 7);	imprime_pilha(&minhaPilha);
    printf("\nPush pilha valor 7");
    push(&minhaPilha, 7);	imprime_pilha(&minhaPilha);
    printf("\nPush pilha valor 7");
    push(&minhaPilha, 7);	imprime_pilha(&minhaPilha);
    printf("\nPush pilha valor 9");
    push(&minhaPilha, 9);	imprime_pilha(&minhaPilha);	
	printf("\ndata[0]:%d  sizePilha:%d", minhaPilha.data[0], minhaPilha.size);
	printf("\ndata[1]:%d  sizePilha:%d", minhaPilha.data[1], minhaPilha.size);
	printf("\ndata[2]:%d  sizePilha:%d", minhaPilha.data[2], minhaPilha.size);
	printf("\ndata[3]:%d  sizePilha:%d", minhaPilha.data[3], minhaPilha.size);
    
	/*imprime_pilha(&minhaPilha);
    push(&minhaPilha, 5);
    imprime_pilha(&minhaPilha);
    push(&minhaPilha, 1);
    imprime_pilha(&minhaPilha);

    valor = pop(&minhaPilha);
    printf("Valor desempilhado:\t %d\n", valor);
    valor = pop(&minhaPilha);
    printf("Valor desempilhado:\t %d\n", valor);
    valor = pop(&minhaPilha);
    printf("Valor desempilhado:\t %d\n", valor);*/

}
