#include <iostream>
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
        c = new No;
        No* h = c;
        for (int i = 0; i<n; i++){
            c->chave = i;
            c->prox = new No;
            c = c->prox;
        }
        c = h;
    }
    return c;
}

void desinicializar (No*&p){
    No* h = p;
    while (h->prox != NULL){
        h = h->prox;
    }
    while()
    }

int main (){
    int n = 10;
    No* p;
    p = nova_lista_encadeada(n);
    desinicializar (p);
}
