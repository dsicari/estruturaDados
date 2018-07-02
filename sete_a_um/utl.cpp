#include "utl.h"

using namespace std;

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
    memset(album, 0, sizeof(TAlbum));
}

//---------------------------------------------------------------------
int TamanhoAlbum(TAlbum *album){
    return album->totalFiguras;
}

//---------------------------------------------------------------------
bool ColarFigura(TAlbum *album, int pos){  
    if(pos < 0 && pos > 681){
        return false;
    }
    if(album->figura[pos] == 0 && pos != 0){
        album->totalFigurasColadas++;        
    }
    else if(album->figura[pos] > 0 && pos != 0){
        FRInserir(pos);
		album->totalFigurasRepetidas++;
    }
    
    if(pos!=0){
        album->totalFiguras++;
    }
    
    album->figura[pos]++; 
    
      
    return true;
}

//---------------------------------------------------------------------
void ColarPacote(TAlbum *album, TPacote *pct){
    int i;
    for(i = 0; i < TOTAL_FIGURAS_PACOTE; i++){
        ColarFigura(album, pct->figura[i]);
    }
    album->pacotesAbertos++;
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
    for(i = 0 ; i < TOTAL_FIGURAS_ALBUM; i++) { 
        if(album->figura[i] > 0){
            printf("\n\t\t--------------------------------------------------------\n");
            printf("\t\t|\tIDX\t|\tFIGURA\t|\tREPETIDAS\t|\n");
            printf("\t\t|\t%i\t|\t%i\t|\t%i\t\t|", count++, i, (album->figura[i] - 1));
        }        
    }
    printf("\n\t\t--------------------------------------------------------\n");
}

//---------------------------------------------------------------------
void ImprimirFigura(TAlbum *album, int pos){
    printf(" figura %i qtde: %i\n", pos, album->figura[pos]);
}

//---------------------------------------------------------------------
bool SalvarAlbum(TAlbum *album){
    bool rslt = false;
    FILE * file = fopen("album.alb", "wb");
    if(file != NULL) {
        int r = fwrite(album, sizeof(TAlbum), 1, file);
        if(r != 0){
            printf("Album salvo com sucesso!\n");
            rslt = true;
        }
        else{
            printf("Erro ao salvar album!\n");  
        }        
        fclose(file);
    }  
    
    if(rslt == false) return rslt;
    
    file = fopen("faltantes.txt", "w");
    if(file != NULL) {
        for(int i = 1; i < TOTAL_FIGURAS_ALBUM; i++){
            if(album->figura[i] == 0){              
                fprintf(file, "%i\n", i);
            }
        }
        fclose(file);
        rslt = true;
    }
    
    if(rslt == false) return rslt;
    
    file = fopen("eu_tenho.txt", "w");
    if(file != NULL) {
        for(int i = 1; i < TOTAL_FIGURAS_ALBUM; i++){
            if(album->figura[i] > 0){              
                fprintf(file, "%i\n", i);
            }
        }
        fclose(file);
        rslt = true;
    }
    
    if(rslt == false) return rslt;
    
    rslt = FRSalvar();
    
    return rslt;
    
}

//---------------------------------------------------------------------
bool AbrirAlbum(TAlbum *album){
    bool rslt = false;
    FILE * file= fopen("album.alb", "rb");
    if (file != NULL) {
        std::cout << "arquivo album.alb aberto!" << std::endl;
        fread(album, sizeof(TAlbum), 1, file);
        int totalFiguras = 0;
        for(int i = 1; i < TOTAL_FIGURAS_ALBUM; i++){
            if(album->figura[i] > 0){
                totalFiguras = totalFiguras + album->figura[i];
            }
        }
        
        if(totalFiguras == album->totalFiguras){
            rslt = true;
            std::cout << "OK: Figuras contadas = " << totalFiguras << " x " << album->totalFiguras << std::endl;
        }
        else{
            std::cout << "ERROR: Diferenca figuras contadas = " << totalFiguras << " x " << " " << album->totalFiguras << std::endl;
        }
        fclose(file);
    }
    
    if(rslt == false) return rslt;
    
    // Abrir monte figuras repetidas
    int figura = 0;
    std::ifstream infile;
    infile.open("repetidas.txt");
    if(infile.is_open()){        
        while(infile >> figura){ 
			if(figura != 0){
				FRInserir(figura);
			}
        }
        rslt = true;
        infile.close();
    }
    
    return rslt;
}

//---------------------------------------------------------------------
bool BuscaFigura(TAlbum* album, int figura){
    if(figura < 0 || figura > 681){
    	return false;
	}
	if(album->figura[figura] > 0){
        return true;
    } 
    return false;
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

//---------------------------------------------------------------------
//  RELATORIO
//---------------------------------------------------------------------
void RelatorioAlbum(TAlbum *album, int tipo){
    // tipo 1: FIGURAS_COLADAS  Relatorio Figuras Coladas
    // tipo 2: FIGURAS_FALTANDO Relatorio Figuras Faltando
    printf("\nRelatorio Album");
    printf("\nCompleto: %i / 681", album->totalFigurasColadas);
    printf("\nTotal figuras: %i", album->totalFiguras);
    printf("\nTotal figuras repetidas: %i", album->totalFigurasRepetidas);
    printf("\nTotal pacotes abertos: %i", album->pacotesAbertos);
    if(tipo == FIGURAS_COLADAS){
        printf("\nFiguras Coladas: ");
        //Figura 0 -> Figura que faltou ao abrir pacote, nao vai para relatorio
        for(int i = 1; i < TOTAL_FIGURAS_ALBUM; i++){
            if(album->figura[i] > 0){                
                printf("%i ", i);
            }
        }
    }
    else if(tipo == FIGURAS_FALTANDO){
        printf("\nFiguras Faltando: ");
        //Figura 0 -> Figura que faltou ao abrir pacote, nao vai para relatorio
        for(int i = 1; i < TOTAL_FIGURAS_ALBUM; i++){
            if(album->figura[i] == 0){                
                printf("%i ", i);
            }
        }
    }
    else if(tipo == FIGURAS_REPETIDAS){
        std::cout << "\nFigurinhas repetidas: " << std::endl;
        FRMostrar();
    }
}
//---------------------------------------------------------------------
void dumpAlbum(TAlbum *album){
    for(int i = 0; i < TOTAL_FIGURAS_ALBUM; i++){
        printf("%i:%i\n", i, album->figura[i]);
    }
}
//---------------------------------------------------------------------
//  AUX LISTA
//---------------------------------------------------------------------
bool _FREncontrar(int figura){
	return FREncontrar(figura);
}

bool _FRRemover(int figura){
	return FRRemover(figura);
}

void _FRLimparMemoria(){
	FRLimparMemoria();
}

// ------------------------------------------ 
// GAME SHARK
// ------------------------------------------

void exodia(TAlbum *album, TPacote *pct){

printf("                  .xUHWH!! !!?M88WHX:.\n");
printf("                .X*#M@$!!  !X!M$$$$$$WWx:.\n");
printf("               :!!!!!!?H! :!$!$$$$$$$$$$8X:\n");
printf("              !!~  ~:~!! :~!$!#$$$$$$$$$$8X:\n");
printf("             :!~::!H!<   ~.U$X!?R$$$$$$$$MM!           _______  _______  __   __  _______  __   __  _______  ______    ___   _ \n");
printf("             ~!~!!!!~~ .:XW$$$U!!?$$$$$$RMM!          |       ||   _   ||  |_|  ||       ||  | |  ||   _   ||    _ |  |   | | |\n");
printf("               !:~~~ .:!M\"T#$$$$WX??#MRRMMM!          |    ___||  |_|  ||       ||  _____||  |_|  ||  |_|  ||   | ||  |   |_| |\n");
printf("               ~?WuxiW*`   `\"#$$$$8!!!!??!!!            |   | __ |       ||       || |_____ |       ||       ||   |_||_ |      _|\n");
printf("             :X- M$$$$       `\"T#$T~!8$WUXU~          |   ||  ||       ||       ||_____  ||       ||       ||    __  ||     |_ \n");
printf("            :%`  ~#$$$m:        ~!~ ?$$$$$$            |   |_| ||   _   || ||_|| | _____| ||   _   ||   _   ||   |  | ||    _  |\n");
printf("          :!`.-   ~T$$$$8xx.  .xWW- ~""##*\"             |_______||__| |__||_|   |_||_______||__| |__||__| |__||___|  |_||___| |_|\n");
printf(".....   -~~:<` !    ~?T#$$@@W@*?$$     /`\n");
printf("W$@@M!!! .!~~ !!     .:XUW$W!~ `\"~:   :\n");
printf("#\"~~`.:x%`!!  !H:   !WM$$$$Ti.: .!WUn+!`\n");
printf(":::~:!!`:X~ .: ?H.!u \"$$$B$$$!W:U!T$$M~\n");
printf(".~~   :X@!.-~   ?@WTWo(\"*$$$W$TH$! `\n");
printf("Wi.~!X$?!-~    : ?$$$B$Wu(\"**$RM!\n");
printf("$R@i.~~ !     :   ~$$$$$B$$en:``\n");
printf("?MXT@Wx.~    :     ~\"##*$$$$M~\n\n\n");

for(int i=0; i<TOTAL_FIGURAS_ALBUM; i++){
	if(album->figura[i] == 0){
		album->figura[i]++;
	}
}
printf(" _______  ___      _______  __   __  __   __    _______  _______  __   __  _______  ___      _______  _______  _______ \n");
printf("|   _   ||   |    |  _    ||  | |  ||  |_|  |  |       ||       ||  |_|  ||       ||   |    |       ||       ||       |\n");
printf("|  |_|  ||   |    | |_|   ||  | |  ||       |  |       ||   _   ||       ||    _  ||   |    |    ___||_     _||   _   |\n");
printf("|       ||   |    |       ||  |_|  ||       |  |       ||  | |  ||       ||   |_| ||   |    |   |___   |   |  |  | |  |\n");
printf("|       ||   |___ |  _   | |       ||       |  |      _||  |_|  ||       ||    ___||   |___ |    ___|  |   |  |  |_|  |\n");
printf("|   _   ||       || |_|   ||       || ||_|| |  |     |_ |       || ||_|| ||   |    |       ||   |___   |   |  |       |\n");
printf("|__| |__||_______||_______||_______||_|   |_|  |_______||_______||_|   |_||___|    |_______||_______|  |___|  |_______|\n\n\n");

system("pause");
}
	
	
	