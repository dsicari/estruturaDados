#include <conio.h>
#include <iostream>
#include <fstream>
#include "utl.h"

using namespace std;

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
    int r = 0;
    TPacote Pacote;        
    TAlbum Album;
        
    InicializarAlbum(&Album);  
	//AbrirAlbum(&Album);
	
	IrABanca(&Album, &Pacote, 1000);
    system("pause");
	
	cout << "--> RELATORIO ALBUM FIGURINHAS REPETIDAS <--" << endl;
	RelatorioAlbum(&Album, FIGURAS_REPETIDAS);
	printf("\n"); system("pause");
			
	cout << "--> PESQUISAR FIGURINHA <--" << endl;
	int fig = 0;
	cout << "\nDigite a figurinha a ser pesquisada: ";
	cin >> fig;
	if(BuscaFigura(&Album, fig)){
		cout << "Figurinha " << fig << " encontrada! " << "Voce possui " << Album.figura[fig] - 1 << " repetidas" << endl; 
	}
	else{
		cout << "Figurinha não encontrada!" << endl;
	}   
	printf("\n"); system("pause");         
	
	cout << "--> REMOVER FIGURINHA FIGURINHA REPETIDA <--" << endl;
	int figura = 0;
	cout << "Qual figurinha deseja remover do monte de repetidas? Figurinha: ";
	cin >> figura;            
	if(_FRRemover(figura)){                	
		cout << "Figurinha removida com sucesso!";
		Album.totalFiguras--;
		Album.totalFigurasRepetidas--;
	}
	else{
		cout << "Erro ao tentar remover figurinha. Voce nao tem ela repetida!!";
	}            
	printf("\n"); system("pause");
	
	cout << "--> RELATORIO ALBUM FIGURINHAS REPETIDAS <--" << endl;
	RelatorioAlbum(&Album, FIGURAS_REPETIDAS);
	printf("\n"); system("pause");
	
	cout << "--> REMOVER FIGURINHA FIGURINHA REPETIDA <--" << endl;
	cout << "Qual figurinha deseja remover do monte de repetidas? Figurinha: ";
	cin >> figura;            
	if(_FRRemover(figura)){                	
		cout << "Figurinha removida com sucesso!";
		Album.totalFiguras--;
		Album.totalFigurasRepetidas--;
	}
	else{
		cout << "Erro ao tentar remover figurinha. Voce nao tem ela repetida!!";
	}            
	printf("\n"); system("pause");
	
	
	
    /*FRMostrar();
    
    FILE * file;    
    // Abrir monte figuras repetidas
    int figura = 0;
    std::ifstream infile;
    infile.open("repetidas.txt");
    if(infile.is_open()){        
        while(infile >> figura){      
            FRInserir(figura);
        }
        infile.close();
    }
	FRMostrar();
	cout << "--> REMOVER FIGURINHA FIGURINHA REPETIDA <--" << endl;
	cout << "Qual figurinha deseja remover do monte de repetidas? Figurinha: ";
	cin >> figura;            
	if(FRRemover(figura)){                	
		cout << "Figurinha removida com sucesso!";
	}
	else{
		cout << "Erro ao tentar remover figurinha. Voce nao tem ela repetida!!";
	}            
	FRMostrar();
	printf("\n"); system("pause");
/*
    FRInserirPosicao(9, 99);
    FRInserirPosicao(4, 77);
    if(FRRemover(9)){
    	cout << "REMOVER OK";
	}
	FRInserirPosicao(1, 88);
	if(FRRemover(88)){
    	cout << "REMOVER OK";
	}
    FRMostrar();
    /*sinserir_na_posicao(1, 66);
    mostrar();
    inserir_na_posicao(1, 88);
    mostrar();
    inserir_na_posicao(3, 77);
    mostrar();
    /*
    inserir(15);
    mostrar();
    inserir(25);
    mostrar();
    inserir(35);
    mostrar();
    inserir(45);
    mostrar();
    encontrar(15);
    remover(25);
    mostrar();
    remover(22);
    mostrar();
    inserir_na_posicao(2, 66);
    mostrar();
    inserir_no_final(55);
    inserir_no_final(65);*/
	cout << "Limpando memoria..." << endl;
    FRLimparMemoria();
	system("pause");
	return 0;
}