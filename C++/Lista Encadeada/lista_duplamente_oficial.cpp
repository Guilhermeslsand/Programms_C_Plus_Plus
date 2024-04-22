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

    void inserir(NoDe* no){
        NoDe* aux;
        int esc;
        cout<<"Esolha uma posicao"<<"\n";
        cin>>esc;
        //posicao escolhida maior do que a posicao final do vetor.
        if(esc>cont){
            cout<<"Posicao invalida";
        }
        else{
            //Caso a lista encadeada não tenha sido inicializada.
            if(cabeca == NULL){
                cabeca = new NoDe;
                cabeca->chave = cont;
                cont++;
            }
            else{
                //caso a posicao escolhida seja a primeira
                if(esc==0){
                    no = new NoDe;
                    no->chave = cont;
                    cabeca->ante = no;
                    no->prox = cabeca;
                    cabeca = no;
                    cont++;
                }
                //caso a posiscao escolhida seja no final do vetor.
                else if(esc==cont){
                    no = cabeca;
                    while(no!=NULL){
                        aux = no;
                        no = no->prox;
                    }
                    no = new NoDe;
                    no->chave = cont;
                    no->ante = aux;
                    aux->prox = no;
                    cont++;
                }
                else{//caso a posicao escolhida for entre a inicio e o fim da lista
                    aux = cabeca;
                    for(int i=0; i<esc; i++){
                        aux = aux->prox;
                    }
                    no = new NoDe;
                    no->chave = cont;
                    aux->ante->prox = no;
                    no->ante = aux->ante;
                    no->prox = aux;
                    aux->ante = no;
                    cont++;
                            
                }    
            }

        }
    }

    NoDe* remover (int chave){
        NoDe* h = cabeca;
        NoDe* lixo;
        if(h->chave == chave){
            lixo = h;
            h = h->prox;
            h->ante = NULL;
            cabeca = h;
        }
        else {
            while(h!= NULL){
                if(h->chave == chave){
                    break;
                }
                h = h->prox;
            }
            if(h->prox == NULL){
                lixo = h;
                h->ante->prox = NULL;
            }
            else{
                lixo = h;
                h->ante->prox = h->prox;
                h->prox->ante = h->ante;
            }
        }
        return lixo;


    }
};

int main (){
    ListaDe l;
    NoDe* h = NULL;
    NoDe* remove = NULL;
    int excluir = 6;
    for(int i = 0; i<7; i++){
        l.inserir(h);
    }
    h = l.cabeca;
    while(h!= NULL){
        cout<<h->chave<<"\n";
        h = h->prox;
    }
    remove = l.remover(excluir);
    cout<<endl;
    h = l.cabeca;
    while(h!= NULL){
        cout<<h->chave<<"\n";
        h = h->prox;
    }
}