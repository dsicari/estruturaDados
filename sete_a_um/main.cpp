#include <iostream>
#include <conio.h>
#include "utl.h"


using namespace std;

int MainMenu(){
    //system("cls");
    int opt = 0;
    cout << "MENU ALBUM COPA\n";
    cout << "1 - Abrir pacote\n";
    cout << "2 - Colar pacote figuras\n";
    cout << "3 - Imprimir album\n";
    cout << "4 - Relatorio figuras coladas\n";
    cout << "5 - Relatorio figuras faltando\n";
    cout << "0 - Sair\n";
    cout << "# Insira a opcao desejada: ";
    cin >> opt ;
    cout << "voce digitou: " << opt;
    return opt;
}


int main()
{
    int r = 0;
    TPacote Pacote;        
    TAlbum Album;

    InicializarAlbum(&Album);
    
    
    do{       
        r = MainMenu();
        if(r == 1){
            AbrePacoteFigura(&Pacote); 
            ImprimePacote(&Pacote); 
        }
        else if(r == 2){
            ColarPacote(&Album, &Pacote);
        } 
        else if(r == 3){
            ImprimirAlbum(&Album);
        }
        else if(r == 4){
            RelatorioAlbum(&Album, FIGURAS_COLADAS);
        }
        else if(r == 5){
            RelatorioAlbum(&Album, FIGURAS_FALTANDO);
        }
    }while(r != 0);
    /*
     *     ColarFigura(&Album, 10);
    cout << "Figuras album: " << TamanhoAlbum(&Album) << endl;

    AbrePacoteFigura(&Pacote);
    cout << "Figuras pacote: " << endl; 
    ImprimePacote(&Pacote);
    
    ColarPacote(&Album, &Pacote);
    cout << "apos colar pacote: "; ImprimirFigura(&Album, 681);
    cout << endl << "Figuras album: " << TamanhoAlbum(&Album) << endl; 
    ImprimirAlbum(&Album);    
    SalvarAlbum(&Album);
    InicializarAlbum(&Album);
    cout << "Figuras album: " << TamanhoAlbum(&Album) << endl;
    if(AbrirAlbum(&Album)){
        
    }
    ImprimirAlbum(&Album);   
    cout << "Figuras album: " << TamanhoAlbum(&Album) << endl;
    if(BuscaFigura(&Album, 10)){
        cout << "Figura encontrada";
    }
    else{
        cout << "Figura nao encotnrada";
    }
    RelatorioAlbum(&Album, FIGURAS_COLADAS);
    RelatorioAlbum(&Album, FIGURAS_FALTANDO);
    MainMenu(&Album, &Pacote);
     * */
    return 0;
}


