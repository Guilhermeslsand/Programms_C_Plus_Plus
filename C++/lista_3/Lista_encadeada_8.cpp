*******************
***Questao_1_e_2***
*******************
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
    No* lixo = NULL;
    while(p!=NULL){
        lixo = p;
        p = p->prox;
        delete lixo;
    }
    p = NULL;
}

int main (){
    int n;
    No* c = NULL;
    c = nova_lista_encadeada(n);
    imprime_recursiva(c);
    desinicializar (c);
}

***************
***Questao_3***
***************
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

void imprimir_reverso(No* h, int cont, No*aux){
    No* ini = h;
    for(int i=0; i<cont; i++){
        while(h->prox!=NULL && aux!=h->prox){
            h = h->prox;
        }
        cout<<h->chave<<endl;
        aux = h;
        h = ini;
    }
}

void imprimir_recursivo (No*h, int cont, No*aux){
    No* ini = h;
    if(cont!=0){
        while(h->prox!=NULL && aux!=h->prox){
            h = h->prox;
        }
        cout<<h->chave<<endl;
        aux = h;
        h = ini;
        cont--;
        imprimir_recursivo (h,cont,aux);
    }
}


int main (){
    int n = 15;
    No* c = NULL;
    No* aux = NULL;
    c = nova_lista_encadeada(n);
    imprimir_recursivo (c, n, aux);
    imprimir_reverso (c, n, aux);
}

***************
***Questao_4***
***************
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

***************
***Questao_5***
***************
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

***************
***Questao_6***
***************
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
    cin>>n;
    NoMat* c = NULL;
    NoMat* ini = NULL;
    NoMat* aux = NULL;
    NoMat* h = NULL;
    ini = c;
    int cont = 0;
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
    h = c;
    matriz_linha (h);

}

***************
***Questao_7***
***************
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

nt main (){
    int cont = 1;
    int aux;
    int n;
    cin>>n;
    int m;
    cin>>m;
    NoMat* mat1 = NULL;
    NoMat* mat2 = NULL;
    mat1 = gerar_matriz(n,m,cont);
    cin>>n;
    cin>>m;
    mat2 = gerar_matriz(n,m,cont);
    custurar_matriz (mat1, mat2);
}

***************
***Questao_8***
***************

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
