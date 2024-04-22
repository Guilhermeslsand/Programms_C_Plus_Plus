#include <iostream>
using namespace std;

class NoMat{
    public:
    int chave;
    NoMat* direita = NULL;
    NoMat* abaixo = NULL;
};

void matriz_linha (NoMat* m){
    NoMat* ini;
    ini = m;
    while(m->abaixo!=NULL){
        while(m->direita!=NULL){
            cout<<m->chave<<" ";
            m = m->direita;
        }
        m = ini;
        m = m->abaixo;
        ini = m;
        cout<<"\n";
    }    
}

int main (){
    int j;
    int i;
    int n;
    NoMat* c = new NoMat;
    NoMat* ini = NULL;
    NoMat* aux = NULL;
    NoMat* h = NULL;
    ini = c;
    int cont = 0;
    for(i=0; i<n; i++){
        h = ini;
        h->abaixo = new NoMat;
        for(j=0; j<n; j++){
            if(i==0){
                h->chave = cont;
                cont++;
                h->direita = new NoMat;
                h = h->direita;
            }
            else{
                if(j==0){
                    aux = ini;
                    h = h->abaixo;
                    ini = h;
                    h->abaixo = new NoMat;   
                }
                else{
                    aux = aux->direita;
                    aux->abaixo = new NoMat;
                    aux->abaixo = h;
                }
                h->chave = cont;
                cont++; 
                h->direita = new NoMat;
                h = h->direita;
            }
        }
    }
    h = c;
    matriz_linha (h);
    
}
