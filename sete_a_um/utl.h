#ifndef UTL_H
#define UTL_H
// ------------------------------------------ 
// DEFINES
// ------------------------------------------

#define TOTAL_FIGURAS_PACOTE 5
#define TOTAL_FIGURAS_ALBUM 681
#define NAO_ACHOU_FIGURA -1

// ------------------------------------------ 
// ESTRUTURAS
// ------------------------------------------

typedef struct{
    int figura[TOTAL_FIGURAS_PACOTE];
}TPacote;

typedef struct{
    int numero;
    bool contem;
    bool repetida;
    int qtdeRepetida;
}TFigura;

typedef struct{
    TFigura figura[TOTAL_FIGURAS_ALBUM];  
    int totalFiguras; 
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
int BuscaFigura(TAlbum* album, int figura);
void IrABanca(TAlbum *album, TPacote *pct,int times);

#endif
