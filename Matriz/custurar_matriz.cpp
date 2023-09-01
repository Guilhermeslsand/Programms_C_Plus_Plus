#include <iostream>
using namespace std;

class NoMat{
    public:
    int chave;
    NoMat* direita = NULL;
    NoMat* abaixo = NULL;
};

NoMat* gerar_matriz(int n, int m, int& cont){
    int j;
    int i;
    NoMat* c = NULL;
    NoMat* ini = NULL;
    NoMat* aux = NULL;
    NoMat* h = NULL;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(c==NULL){
                h = new NoMat;
                h->chave = cont;
                ini = h;
                c = h;
            }
            else{
                if(i==0){
                    h->direita = new NoMat;
                    h = h->direita;
                    h->chave = cont;
                }
                else{
                    if(j==0){
                        aux = ini;
                        h = new NoMat;
                        h->chave = cont;
                        aux->abaixo = h;   
                        ini = h;
                    }
                    else{
                        aux = aux->direita;
                        h->direita = new NoMat;
                        h = h->direita;
                        h->chave = cont;
                        aux->abaixo = h;
                    }    
                }
            }
        cont++;
        }

    }
    return c;
}

void imprimir_matriz (NoMat* m){
    NoMat* ini;
    ini = m;
    while(m!=NULL){
        while(m!=NULL){
            cout<<m->chave<<" ";
            m = m->direita;
        }
        m = ini;
        m = m->abaixo;
        ini = m;
        cout<<"\n";
    }    
}

void custurar_matriz (NoMat* m, NoMat* l){
    NoMat* ini = NULL;
    NoMat* aux = NULL;
    while(m != NULL){
        ini = m;     
        while(m->abaixo!=NULL){
            m = m->abaixo;
        } 
        m->abaixo = l;
        m = ini;
        m = m->direita;
        l = l->direita;   
    }
}

int posicao_mat (int l, int c, NoMat* m)
{
    for(int i=0; i<l; i++){
        m = m->abaixo;
    }
    for(int j=0; j<c; j++){
        m = m->direita;
    }
    int ele = m->chave;
    return ele;
}

int main (){
    int cont = 1;
    int aux;
    int n;
    cin>>n;
    int m;
    cin>>m;
    NoMat* mat1 = NULL;
    NoMat* mat2 = NULL; 
    NoMat* mat = NULL;
    mat1 = gerar_matriz(n,m,cont);
    imprimir_matriz (mat1);
    //cin>>n;
    //cin>>m;
    //mat2 = gerar_matriz(n,m,cont);
    //imprimir_matriz (mat2);
    //custurar_matriz (mat1, mat2);
    //imprimir_matriz (mat1);
    cin>>n;
    cin>>m;
    aux = posicao_mat(n,m,mat1);
    cout<<aux<<"\n";
}
