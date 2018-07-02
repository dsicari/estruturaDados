#include <iostream>
#include "lista.h"

using namespace std;

static LISTA head = NULL;
static LISTA tail = NULL;
static LISTA temp = NULL;

//---------------------------------------------------------------------
bool FREstaVazio(){
    return head == NULL;
}

//---------------------------------------------------------------------
void FRInserir(int x){
    temp = new NO;
    temp->valor = x;
    if(FREstaVazio()){
        temp->prox = NULL;
        tail = temp;
    } else {
        temp->prox = head;
    }
    head = temp;
}

//---------------------------------------------------------------------
void FRInserirNoFinal(int x){
    temp = new NO;
    temp->valor = x;
    temp->prox = NULL;
    if(FREstaVazio()){
        head = temp;
        tail = temp;
    } else {
        tail->prox = temp;
        tail = temp;
    }
}

//---------------------------------------------------------------------
void FRInserirPosicao(int posicao, int valor){
    LISTA temp2;
    int x = posicao ;
    if(FREstaVazio()){
        cout << "Lista vazia " << endl;
    } else {
        if(posicao == 0) {
            FRInserir(valor);
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

//---------------------------------------------------------------------
bool FRRemover(int x){
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

//---------------------------------------------------------------------
bool FREncontrar(int x){
    int i=1;
    temp = head;
    while (temp->prox != NULL && temp->valor != x) {
        temp = temp->prox;
        i++;
    }
    if(temp->valor == x)
    {
        return true;
    }
    else if(temp->prox == NULL)
    {
        return false;
    }
}

//---------------------------------------------------------------------
int FREncontrarPosicao(int x){
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

//---------------------------------------------------------------------
void FRMostrar(){
    if(!FREstaVazio()) {
        for(temp = head; temp != NULL; temp=temp->prox){
            cout << temp->valor << " ";
        }
        cout << endl;
    } else {
        cout << "Lista vazia !" << endl;
    }
}

//---------------------------------------------------------------------
bool FRSalvar(){
    FILE *file = fopen("repetidas.txt", "w");
    if(file != NULL) {
        if(!FREstaVazio()) {
            for(temp = head; temp != NULL; temp=temp->prox){
                fprintf(file, "%i\n", temp->valor);
            }
        } 
        fclose(file);
        return true;
    }
    return false;    
}

//---------------------------------------------------------------------
void FRLimparMemoria(){
    LISTA thanos;
    delete temp;
    delete tail;
    while (head->prox != NULL) {
        thanos = head;
        head = head->prox;
        thanos->prox = NULL;
        delete thanos;
    }
}
