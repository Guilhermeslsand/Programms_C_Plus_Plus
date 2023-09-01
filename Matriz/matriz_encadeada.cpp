#include <iostream>
using namespace std;

class NoMat{
    public:
    int chave;
    NoMat* direita = NULL;
    NoMat* abaixo = NULL;
};

NoMat* matriz_linha (int n){
    NoMat* c = NULL;
    NoMat* h = NULL;
    for(int i=n; i>0; i--){
        h = new NoMat;
        h->chave = (i+1)*4;
        h->direita = c;
        c = h;
    }
    return c;
}


int main (){
    NoMat* mat = NULL;
    int n;
    cin>>n;
    mat = matriz_linha(n);
    while (mat!=NULL){
        cout<<mat->chave<<"\n";
        mat = mat->direita;
    }
}
