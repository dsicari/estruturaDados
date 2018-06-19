#ifndef LISTA_H
#define LISTA_H

typedef struct NO {
   int valor;
   struct NO* prox;
}*LISTA;

static LISTA head;
static LISTA tail;
static LISTA temp;
    
class TFigurasRepetidas{
        
    public:
        void init();
        bool esta_vazio();
        void inserir(int x);
        void inserir_no_final(int x);
        void inserir_na_posicao(int posicao, int valor);
        bool remover(int x);
        bool encontrar(int x);
        void encontrarPosicao(int x, int *idx);
        void mostrar();
        bool salvarRepetidas();
        void limpar_memorias();
    protected:
    private:
};
#endif

