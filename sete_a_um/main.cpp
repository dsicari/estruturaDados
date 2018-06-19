#include <iostream>
#include <conio.h>
#include "utl.h"


using namespace std;



using namespace std;

int MainMenu(){
    //system("cls");
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


int main()
{
    int r = 0;
    TPacote Pacote;        
    TAlbum Album;
        
    InicializarAlbum(&Album);    
    
    do{       
        r = MainMenu(); 
        if( r == 1){
            int num = 0;
            cout << "\nDigite a qtde de pacotes para comprar: ";
            cin >> num;
            IrABanca(&Album, &Pacote, num);
        }
        else if(r == 2){
            AbrePacoteFigura(&Pacote); 
            cout << "Pacote contem: "; ImprimePacote(&Pacote); 
        }
        else if(r == 3){          
            ColarPacote(&Album, &Pacote);
        } 
        else if(r == 4){
            ImprimirAlbum(&Album);
        }
        else if(r == 5){
            int fig = 0;
            cout << "\nDigite a figurinha a ser pesquisada: ";
            cin >> fig;
            if(BuscaFigura(&Album, fig)){
                cout << "Figurinha " << fig << " encontrada! " << "Voce possui " << Album.figura[fig] - 1 << " repetidas" << endl; 
            }
            else{
                cout << "Figurinha não encontrada!" << endl;
            }                
        }
        else if(r == 6){
            RelatorioAlbum(&Album, FIGURAS_COLADAS);
        }
        else if(r == 7){
            RelatorioAlbum(&Album, FIGURAS_FALTANDO);
        }
        else if(r == 8){
            SalvarAlbum(&Album);
        }
        else if(r == 9){
            if(AbrirAlbum(&Album)){
                cout << "Album carregado com sucesso!" << endl;
            }
            else{
                cout << "Falha ao carregar album" << endl;
            }
        }
        else if(r == 10){
            RelatorioAlbum(&Album, FIGURAS_REPETIDAS);
        }
        else if(r == 11){
            int figura = 0;
            cout << "Digite a figurinha a pesquisar no monte de repetidas: ";
            cin >> figura;
            if(FigurasRepetidas->encontrar(figura)){
                cout << "Figurinha encontrada!" << endl;
            }
            else{
                cout << "Figurinha nao encontrada!" << endl;
            }
        }
        else if(r == 12){
            int figura = 0;
            cout << "Qual figurinha deseja remover do monte de repetidas? Figurinha: ";
            cin >> figura;
            if(FigurasRepetidas->encontrar(figura)){
                cout << "Figurinha encontrada!" << endl;
                if(FigurasRepetidas->remover(figura)){
                    cout << "Figurinha removida com sucesso!";
                }
                else{
                    cout << "Erro ao tentar remover figurinha!";
                }
            }
            else{
               cout << "Figurinha nao encontrada no monte de repetidas!" << endl;
            }
        }
        else if(r == 13){
            int figura = 0, repetida = 0;
            cout << "Qual figurinha voce vai receber? Figura: ";
            cin >> figura;
            if(BuscaFigura(&Album, figura) == false){
                cout << "Qual figurinha voce vai fornecer? Figura: ";
                cin >> repetida;
                if(FigurasRepetidas->encontrar(repetida)){
                    FigurasRepetidas->remover(repetida);
                    
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
                
        }
        else if(r == 14){
            dumpAlbum(&Album);
        }
    }while(r != 0);
    
    // _FIX_ FigurasRepetidas->limpar_memorias();
    return 0;
}


