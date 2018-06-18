#include <iostream>
#include "lista.h"

using namespace std;

void TFigurasRepetidas::init(){
    head = NULL;
    tail = NULL;
    temp = NULL;
}

bool TFigurasRepetidas::esta_vazio(){
    return head == NULL;
}
void TFigurasRepetidas::inserir(int x){
    temp = new NO;
    temp->valor = x;
    if(esta_vazio()){
        temp->prox = NULL;
        tail = temp;
    } else {
        temp->prox = head;
    }
    head = temp;
}
void TFigurasRepetidas::inserir_no_final(int x){
    temp = new NO;
    temp->valor = x;
    temp->prox = NULL;
    if(esta_vazio()){
        head = temp;
        tail = temp;
    } else {
        tail->prox = temp;
        tail = temp;
    }
}
void TFigurasRepetidas::inserir_na_posicao(int posicao, int valor){
    LISTA temp2;
    int x = posicao ;
    if(esta_vazio()){
        cout << "Lista vazia " << endl;
    } else {
        if(posicao == 0) {
            inserir(valor);
        }
        temp = head;
        x--;
        while (temp->prox != NULL && x != 0) {
            x--;
            temp = temp->prox;

        }
        //cout << temp->valor << endl<< endl;
        if(temp->prox != NULL) {
            temp2 = new NO;
            temp2->valor = valor;
            temp2->prox = temp->prox;
            temp->prox = temp2;
        }
    }
}
bool TFigurasRepetidas::remover(int x){
    temp = head;
    NO *prev;
    while(temp->prox != NULL && temp->valor != x){
        prev = temp;
        temp = temp->prox;
    }
    
    if(temp->valor == x) {
        prev->prox = temp->prox;
        delete temp;
        return true;
    }
    else if(temp->prox == NULL)
    {
        return false;
    }
    
}
int TFigurasRepetidas::encontrar(int x){
    int i=1;
    temp = head;
    while (temp->prox != NULL && temp->valor != x) {
        temp = temp->prox;
        i++;
    }
    if(temp->valor == x)
    {
        return i;
    }
    else if(temp->prox == NULL)
    {
        return -1;
    }
}
void TFigurasRepetidas::mostrar(){
    //FILE *file = fopen("repetidas.txt", "w");
    //if(file != NULL) {
        if(!esta_vazio()) {
            for(temp = head; temp != NULL; temp=temp->prox){
                cout << temp->valor << " ";
                //fprintf(file, "%i\n", temp->valor);
            }
            cout << endl;
        } else {
            cout << "Lista vazia !" << endl;
        }
        //fclose(file);
    //}
}
bool TFigurasRepetidas::salvarRepetidas(){
    FILE *file = fopen("repetidas.txt", "w");
    if(file != NULL) {
        if(!esta_vazio()) {
            for(temp = head; temp != NULL; temp=temp->prox){
                fprintf(file, "%i\n", temp->valor);
            }
        } 
        fclose(file);
        return true;
    }
    return false;    
}

void TFigurasRepetidas::limpar_memorias(){
    LISTA thanos;
    delete temp;
    delete tail;
    while (head->prox != NULL) {
        thanos = head;
        head = head->prox;
        // cout << thanos->valor << " -- " << head->valor << endl<< endl;
        thanos->prox = NULL;
        delete thanos;
    }
}