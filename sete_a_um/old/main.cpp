#include <locale.h>
#include <iostream>
#include <conio.h>
#include "utl.h"

using namespace std;

int MainMenu(){	
	system("cls"); //Clear tela ao voltar menu
    int opt = 0;
    cout << "\nMENU ALBUM COPA\n";
    cout << "1 - Ir a banca\n";
    cout << "2 - Abrir pacote figurinhas\n";
    cout << "3 - Colar pacote figurinhas\n";
    cout << "4 - Imprimir album\n";
    cout << "5 - Pesquisar figurinha\n";
    cout << "6 - Relatorio figurinhas coladas\n";
    cout << "7 - Relatorio figurinhas faltando\n";
    cout << "8 - Salvar album\n";
    cout << "9 - Abrir album\n";
    cout << "10 - Imprimir monte de figurinhas repetidas\n";
    cout << "11 - Pesquisar no monte de figurinhas repetidas\n";
    cout << "12 - Remover figurinha do monte\n";
    cout << "13 - Trocar figurinha\n";
    cout << "14 - Dump Album\n";
    cout << "0 - Sair\n";
    cout << "# Insira a opcao desejada: ";
    cin >> opt;
    return opt;
}

//---------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, "Portuguese");
	
    int r = 0;
    TPacote Pacote;        
    TAlbum Album;
        
    InicializarAlbum(&Album);    
    
    do{       
        r = MainMenu();
		system("cls"); // Clear tela ao escolher menu         
        if( r == 1){        	
            int num = 0;
            cout << "--> IR A BANCA <--" << endl;
            cout << "\nDigite a qtde de pacotes para comprar: ";
            cin >> num;
            IrABanca(&Album, &Pacote, num);
            system("pause");
        }
        else if(r == 2){
        	cout << "--> ABRIR PACOTE FIGURINHAS <--" << endl;
            AbrePacoteFigura(&Pacote); 
            cout << "Pacote contem: "; ImprimePacote(&Pacote); 
            printf("\n"); system("pause");
        }
        else if(r == 3){   
			cout << "--> COLAR PACOTE FIGURINHAS <--" << endl;       
            ColarPacote(&Album, &Pacote);
            system("pause");
        } 
        else if(r == 4){
            ImprimirAlbum(&Album);
            printf("\n"); system("pause");
        }
        else if(r == 5){
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
        }
        else if(r == 6){
        	cout << "--> RELATORIO ALBUM FIGURINHAS COLADAS <--" << endl;
            RelatorioAlbum(&Album, FIGURAS_COLADAS);
            printf("\n"); system("pause");
        }
        else if(r == 7){
        	cout << "--> RELATORIO ALBUM FIGURINHAS FALTANDO <--" << endl;
            RelatorioAlbum(&Album, FIGURAS_FALTANDO);
            printf("\n"); system("pause");
        }
        else if(r == 8){
        	cout << "--> SALVAR ALBUM COPA <--" << endl;
            SalvarAlbum(&Album);
            printf("\n"); system("pause");
        }
        else if(r == 9){
        	cout << "--> CARREGAR ALBUM COPA <--" << endl;
            if(AbrirAlbum(&Album)){
                cout << "Album carregado com sucesso!" << endl;
            }
            else{
                cout << "Falha ao carregar album" << endl;
            }
            printf("\n"); system("pause");
        }
        else if(r == 10){
        	cout << "--> RELATORIO ALBUM FIGURINHAS REPETIDAS <--" << endl;
            RelatorioAlbum(&Album, FIGURAS_REPETIDAS);
            printf("\n"); system("pause");
        }
        else if(r == 11){
        	cout << "--> PESQUISAR FIGURINHA REPETIDA <--" << endl;
            int figura = 0;
            cout << "Digite a figurinha a pesquisar no monte de repetidas: ";
            cin >> figura;
            if(FREncontrar(figura)){
                cout << "Figurinha encontrada!" << endl;
            }
            else{
                cout << "Figurinha nao encontrada!" << endl;
            }
            printf("\n"); system("pause");
        }
        else if(r == 12){
        	cout << "--> REMOVER FIGURINHA FIGURINHA REPETIDA <--" << endl;
            int figura = 0;
            cout << "Qual figurinha deseja remover do monte de repetidas? Figurinha: ";
            cin >> figura;
            if(FREncontrar(figura)){
                cout << "Figurinha encontrada!" << endl;
                if(FRRemover(figura)){                	
                    cout << "Figurinha removida com sucesso!";
                    Album.totalFiguras--;
                    Album.totalFigurasRepetidas--;
                }
                else{
                    cout << "Erro ao tentar remover figurinha!";
                }
            }
            else{
               cout << "Figurinha nao encontrada no monte de repetidas!" << endl;
            }
            printf("\n"); system("pause");
        }
        else if(r == 13){
        	cout << "--> TROCAR FIGURINHA <--" << endl;
            int figura = 0, repetida = 0;
            cout << "Qual figurinha voce vai receber? Figura: ";
            cin >> figura;
            if(BuscaFigura(&Album, figura) == false){
                cout << "Qual figurinha voce vai fornecer? Figura: ";
                cin >> repetida;
                if(FREncontrar(repetida)){
                    FRRemover(repetida);                    
                    ColarFigura(&Album, figura);
                    cout << "Parabens, agora voce possui a figurinha " << figura << endl;
                    printf("\nCompleto: %i / 681", Album.totalFigurasColadas);
                    printf("\nTotal figuras: %i", Album.totalFiguras);
                    printf("\nTotal figuras repetidas: %i", Album.totalFigurasRepetidas);
                }
                else{
                    cout << "ERRO: Voce nao tem esta figura repetida para fornecer!";
                }
            }
            else{
                cout << "ERRO: Voce ja tem esta figura colada!";
            }
            printf("\n"); system("pause");
        }
        else if(r == 14){
        	cout << "--> DUMP ALBUM <--" << endl;
            dumpAlbum(&Album);
            printf("\n"); system("pause");
        }
    }while(r != 0);
    
    // _FIX_ FigurasRepetidas->limpar_memorias();
    return 0;
}


