#include <iostream>
#include <cstdlib>
using namespace std;

class No{
    public:
    int chave;
    No* prox = NULL;
};

No* nova_lista_encadeada (int n){
    int i;
    No* c = NULL;
    if(n<=0){

    }
    else{
        No* h = NULL;
        for (i = 0; i<n; i++){
            h = new No;
            h->chave = i+1;
            h->prox = c;
            c = h;
        }
    }
    return c;
}

void imprimir_reverso(No* h, int cont, No*p){
    No* ini = h;
    for(int i=0; i<cont; i++){
        while(h->prox!=NULL && p!=h->prox){
            h = h->prox;
        }
        cout<<h->chave<<endl;
        p = h;
        h = ini;
    }
}

void imprimir_recursivo (No*h, int cont, No*p){
    No* ini = h;
    if(cont!=0){
        while(h->prox!=NULL && p!=h->prox){
            h = h->prox;
        }
        cout<<h->chave<<endl;
        p = h;
        h = ini;
        cont--;
        imprimir_recursivo (h,cont,p);
    }
}


int main (){
    int n = 15;
    No* c = NULL;
    No* p = NULL;
    c = nova_lista_encadeada(n);
    imprimir_recursivo (c, n, p);
    imprimir_reverso (c, n, p);
}