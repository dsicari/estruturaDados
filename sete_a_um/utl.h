#ifndef UTL_H
#define UTL_H

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include "lista.h"

// ------------------------------------------ 
// DEFINES
// ------------------------------------------

#define TOTAL_FIGURAS_PACOTE 5
#define TOTAL_FIGURAS_ALBUM 682
#define NAO_ACHOU_FIGURA -1
#define FIGURAS_COLADAS 1
#define FIGURAS_FALTANDO 2
#define FIGURAS_REPETIDAS 3

// ------------------------------------------ 
// ESTRUTURAS
// ------------------------------------------

// PACOTE FIGURAS
typedef struct{
    int figura[TOTAL_FIGURAS_PACOTE];
}TPacote;

typedef struct{
    int figura[TOTAL_FIGURAS_ALBUM];  
    int totalFiguras; 
    int totalFigurasColadas;
    int totalFigurasRepetidas;
    int pacotesAbertos;
}TAlbum;

// ------------------------------------------ 
// FUNCOES PACOTE
// ------------------------------------------

void AbrePacoteFigura(TPacote *pct);
void ImprimePacote(TPacote *pct);

// ------------------------------------------ 
// FUNCOES ALBUM
// ------------------------------------------

void InicializarAlbum(TAlbum *album);
int TamanhoAlbum(TAlbum *album);
bool ColarFigura(TAlbum *album, int figura);
void ColarPacote(TAlbum *album, TPacote *pct);
void ImprimirAlbum(TAlbum *album);
void ImprimirFigura(TAlbum *album, int pos);
bool BuscaFigura(TAlbum* album, int figura);
void IrABanca(TAlbum *album, TPacote *pct,int times);
bool PesquisarFiguraRepetida(int figura);
void dumpAlbum(TAlbum *album);

// ------------------------------------------ 
// RELATORIO
// ------------------------------------------

void RelatorioAlbum(TAlbum *album, int tipo);

// ------------------------------------------ 
// ACESSO ARQUIVO
// ------------------------------------------

bool SalvarAlbum(TAlbum *album);
bool AbrirAlbum(TAlbum *album);

// ------------------------------------------ 
// AUX LISTA
// ------------------------------------------

bool _FREncontrar(int figura);
bool _FRRemover(int figura);
void _FRLimparMemoria();

// ------------------------------------------ 
// GAME SHARK
// ------------------------------------------

void exodia(TAlbum *album, TPacote *pct);

#endif
