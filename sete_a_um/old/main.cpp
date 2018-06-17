#include <iostream>
#include <conio.h>
#include "utl.h"

using namespace std;

int main()
{
    int r = 0;
    TPacote Pacote;        
    TAlbum Album;

    InicializarAlbum(&Album);
    cout << "Tamanho album: " << TamanhoAlbum(&Album) << endl;

    AbrePacoteFigura(&Pacote);
    cout << "Figuras pacote: " << endl; 
    ImprimePacote(&Pacote);	
    ColarPacote(&Album, &Pacote);
    cout << endl << "Tamanho album: " << TamanhoAlbum(&Album) << endl; 
    
    /*do{
        IrABanca(&Album, &Pacote, 1);
        int x = TamanhoAlbum(&Album);
    }while(TamanhoAlbum(&Album) < TOTAL_FIGURAS_ALBUM - 550);*/
    
    ImprimirAlbum(&Album);
    
    r = BuscaFigura(&Album, Pacote.figura[0]);
    if(r != NAO_ACHOU_FIGURA){
        cout << "Album contem a figura: " << Album.figura[r].numero << " e " << Album.figura[r].qtdeRepetida << " repetidas." << endl;
    }
    else{
        cout << "Album nao contem a figura " << Pacote.figura[0] << endl;
    }
    
    RelatorioAlbum(&Album, FIGURAS_COLADAS);
    RelatorioAlbum(&Album, FIGURAS_FALTANDO);
    //cout << "figura 4 : " << BuscaFigura(&Album, 4) << endl;
    getchar();
    return 0;
}


