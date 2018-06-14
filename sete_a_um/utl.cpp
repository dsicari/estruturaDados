#include "utl.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <stdio.h>
#include <cstring>
#include <iostream>

//---------------------------------------------------------------------
//			PACOTE FIGURAS
//---------------------------------------------------------------------
void AbrePacoteFigura(TPacote *pct)
{	
    memset(pct, 0, TOTAL_FIGURAS_PACOTE);    
    int i = 0;
    for(i = 0; i < TOTAL_FIGURAS_PACOTE; i++){
            pct->figura[i] = (rand() % TOTAL_FIGURAS_ALBUM);  
    }
}

//---------------------------------------------------------------------
void ImprimePacote(TPacote *pct)
{
    int i = 0;
    for(i = 0; i < TOTAL_FIGURAS_PACOTE; i++){
        printf(" %i ", pct->figura[i]);	
    }	
}

//---------------------------------------------------------------------
//			ALBUM
//---------------------------------------------------------------------
void InicializarAlbum(TAlbum *album){
    //Iniciar seed rand (numero aleatorio)
    srand(time(NULL));
    album->totalFiguras = 0;  
    int i;
    for(i = 0; i <= TOTAL_FIGURAS_ALBUM; i++){
        album->figura[i].contem = false;
        album->figura[i].numero = 0;
        album->figura[i].repetida = false;
        album->figura[i].qtdeRepetida = 0;
    }
    // _FIX_ memset(album, 0, sizeof(TAlbum) * TOTAL_FIGURAS_ALBUM);
}

//---------------------------------------------------------------------
int TamanhoAlbum(TAlbum *album){
    return album->totalFiguras;
}

//---------------------------------------------------------------------
            /* CODIGO ZUADO, DESCONSIDERAR */
//---------------------------------------------------------------------
/*bool ColarFigura(TAlbum *album, int figura){
    int pos = TamanhoAlbum(album);
    
    if(album->totalFiguras >= TOTAL_FIGURAS_ALBUM) {
        return false;
    }   
    
    int r = BuscaFigura(album, figura);
    if(r == NAO_ACHOU_FIGURA){
        while(pos > 0 && album->figura[pos-1].numero > figura) {
            album->figura[pos] = album->figura[pos-1];
            pos--;
        }
        album->figura[pos].numero = figura;    
        album->totalFiguras++;
    }
    /*while(pos > 0 && album->figura[pos-1].numero > figura) {
        album->figura[pos] = album->figura[pos-1];
        pos--;
    }
    
    int r = BuscaFigura(album, figura);
    if(r == NAO_ACHOU_FIGURA){
        album->figura[r].numero = figura;
        album->figura[r].contem = true;
        album->figura[r].qtdeRepetida = 0;
        album->totalFiguras++;
    }
    else{
        album->figura[r].repetida = true;
        album->figura[r].qtdeRepetida++;
    }
    return true;
}*/

//---------------------------------------------------------------------
bool ColarFigura(TAlbum *album, int pos){    
    if(!album->figura[pos].contem){
        album->figura[pos].numero = pos;
        album->figura[pos].contem = true;
        album->figura[pos].qtdeRepetida = 0;
        album->totalFiguras++;
    }
    else{
        album->figura[pos].repetida = true;
        album->figura[pos].qtdeRepetida++;
    }
    return true;
}
//---------------------------------------------------------------------
void ColarPacote(TAlbum *album, TPacote *pct){
    int i;
    for(i = 0; i < TOTAL_FIGURAS_PACOTE; i++){
        ColarFigura(album, pct->figura[i]);
    }
}

//---------------------------------------------------------------------
void ImprimirAlbum(TAlbum *album){
    //http://patorjk.com/software/taag/
    printf("\n");    
    printf("  /$$$$$$  /$$       /$$$$$$$  /$$   /$$ /$$      /$$        /$$$$$$   /$$$$$$  /$$$$$$$   /$$$$$$\n");
    printf(" /$$__  $$| $$      | $$__  $$| $$  | $$| $$$    /$$$       /$$__  $$ /$$__  $$| $$__  $$ /$$__  $$\n");
    printf("| $$  \\ $$| $$      | $$  \\ $$| $$  | $$| $$$$  /$$$$      | $$  \\__/| $$  \\ $$| $$  \\ $$| $$  \\ $$\n");
    printf("| $$$$$$$$| $$      | $$$$$$$ | $$  | $$| $$ $$/$$ $$      | $$      | $$  | $$| $$$$$$$/| $$$$$$$$\n");
    printf("| $$__  $$| $$      | $$__  $$| $$  | $$| $$  $$$| $$      | $$      | $$  | $$| $$____/ | $$__  $$\n");
    printf("| $$  | $$| $$      | $$  \\ $$| $$  | $$| $$\\  $ | $$      | $$    $$| $$  | $$| $$      | $$  | $$\n");
    printf("| $$  | $$| $$$$$$$$| $$$$$$$/|  $$$$$$/| $$ \\/  | $$      |  $$$$$$/|  $$$$$$/| $$      | $$  | $$\n");
    printf("|__/  |__/|________/|_______/  \\______/ |__/     |__/       \\______/  \\______/ |__/      |__/  |__/\n");                                                                                          
                                                                                                   
    int i;
    int count = 0;
    for(i = 0 ; i <= TOTAL_FIGURAS_ALBUM; i++) { 
        if(album->figura[i].contem){
            printf("\n\t\t--------------------------------------------------------\n");
            printf("\t\t|\tIDX\t|\tFIGURA\t|\tREPETIDAS\t|\n");
            printf("\t\t|\t%i\t|\t%i\t|\t%i\t\t|", ++count, album->figura[i].numero, album->figura[i].qtdeRepetida);
        }        
    }
    printf("\n\t\t--------------------------------------------------------\n");
}

//---------------------------------------------------------------------
int BuscaFigura(TAlbum* album, int figura){
    int esq, dir, meio;
    esq = 0;
    dir = album->totalFiguras;
    while(esq <= dir) {
        meio = ((esq + dir) / 2);
        if(figura == album->figura[meio].numero) {
            return meio;
        } else {
            if(album->figura[meio].numero < figura){
                esq = meio + 1;
            } else {
                dir = meio + 1;
            }
        }
    }
    return -1;
}
//---------------------------------------------------------------------
void IrABanca(TAlbum *album, TPacote *pct, int times){
    for(int i = 0; i < times; i++){
        AbrePacoteFigura(pct);
	printf("Figuras pacote: \n"); 
	ImprimePacote(pct);	
	ColarPacote(album, pct);
	printf("\nTamanho album: %i\n", TamanhoAlbum(album));
    }
}

