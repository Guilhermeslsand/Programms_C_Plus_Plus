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
            h->chave = i;
            h->prox = c;
            c = h;
        }
    }
    return c;
}

void imprime_recursiva (No* h) {
   if (h!= NULL) {
      cout<<"\n"<<h->chave;
      imprime_recursiva (h->prox);
   }
}

void desinicializar (No* p){
    No* l = NULL;
    while(p!=NULL){
        l = p;
        p = p->prox;
        delete l;
    }
    p = NULL;
}

int main (){
    int n;
    No* p = NULL;
    p = nova_lista_encadeada(n);
    imprime_recursiva(p);
    desinicializar (p);
    p = NULL;
}
