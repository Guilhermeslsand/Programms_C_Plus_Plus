#include <iostream>
using namespace std;

class NoDe{
    public:
    int chave;
    NoDe* prox = NULL;
    NoDe* ante = NULL;
};

class ListaDe{
    public:
    NoDe* cabeca = NULL;
    int cont = 0;
    
    void inserir (NoDe* no){
        if(cabeca == NULL){
        cabeca = new NoDe;
        cabeca->chave = no->chave;
        cont++;
        }
        else{
            int pos;
            cin>>pos;
            if(pos>cont){
            }
            else{
                if(pos == 0){
                    no->prox = new NoDe;
                    no->prox = cabeca;
                    cabeca = no;
                    no->prox->ante = new NoDe;
                    no->prox->ante = cabeca;

                }
                for(int i = 0; i<pos; i++){
                    no->prox = new NoDe;
                    no->ante = new Node;
                    no->ante = no;
                    no = no->prox
                }
            }
        }
    }
};

int main (){
    NoDe* c;
    NoDe* h;
    for(int i = 0; i < 8; i++){
        h->chave = i*5+1;
        if(i==0){
            h->prox = new NoDe;
            h = h-prox;
        }
        else if(i == 8-1){
            h->ante = new Node 
            h->ante = ;
        }
        else{
            h->ante = new Node;
            h->ante = c;
            c = h;
            h->prox = new Node;
            h = h->prox;
        }
    }
}
