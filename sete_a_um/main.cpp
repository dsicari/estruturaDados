#include <iostream>
#include <conio.h>
#include "utl.h"

using namespace std;

int main()
{
    TPacote Pacote;        
    TAlbum Album;

    InicializarAlbum(&Album);
    cout << "Tamanho album: " << TamanhoAlbum(&Album) << endl;

    AbrePacoteFigura(&Pacote);
    cout << "Figuras pacote: " << endl; 
    ImprimePacote(&Pacote);	
    ColarPacote(&Album, &Pacote);
    cout << endl << "Tamanho album: " << TamanhoAlbum(&Album) << endl; 

    do{
        IrABanca(&Album, &Pacote, 1);
    }while(TamanhoAlbum(&Album) < TOTAL_FIGURAS_ALBUM);

    ImprimirAlbum(&Album);
    //cout << "figura 4 : " << BuscaFigura(&Album, 4) << endl;

    return 0;
}


