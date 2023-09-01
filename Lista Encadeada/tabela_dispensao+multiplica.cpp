# include <iostream>
#include <cmath>
using namespace std;

class NoRegistro {
public :
int chave ;
NoRegistro * prox = NULL;
};

class TabelaDispersao_EE_Multi {
public :
NoRegistro ** tabela ;
int m ;
int cont ;

TabelaDispersao_EE_Multi (int tamanho ){
    m = tamanho ;
    tabela = new NoRegistro *[ m ]();
    for(int i =0; i<m; i++){
    tabela[i] = NULL;
}
    cont = 0;
}

int metodo_multi (int c ){
    float partint;
    float partfrac;

    float A = 0.6180339887;

    partfrac = modf(c*A, &partint);
    
    return (int) (m*partfrac);
}
// m é todo inserir
int inserir ( NoRegistro * reg ){
    int pos = metodo_multi( reg.chave);
    
    if(tabela[pos]==NULL){
        tabela[pos] = reg;
    }
    else{
        reg->prox = tabela[pos];
        tabela[pos] = reg;
    }
    return pos;
}

NoRegistro * buscar ( int chave ){
    int pos = metodo_multi (chave);

    NoRegistro* aux = tabela[pos];
    while(aux != NULL){
        if(aux->chave = chave){
            return aux;
        }
        aux = aux->prox;
    }
    return NULL
}

NoRegistro * remover ( int chave ){
    int pos = metodo_multi(chave);

    if(tabela[pos]==NULL){
        return NULL
    }

    else{
        if(tabela[pos]->chave = chave){
            NoRegistro* h = tabela[pos];
            tabela[pos] = tabela[pos]->prox;
            return h
        }
        else{
            NoRegistro* aux = tabela[pos];
            while(aux->prox != NULL){
                if(aux->prox->chave == chave){
                    NoRegistro* h = aux->prox;
                    aux->prox = aux->prox->prox;
                    return h;
                }
                aux = aux->prox;
            }
        }
    }
}

void eliminar ( int chave ){
    int pos = metodo_multi(chave);

    if(tabela[pos]==NULL){
    }

    else{
        if(tabela[pos]->chave = chave){
            NoRegistro* h = tabela[pos];
            tabela[pos] = tabela[pos]->prox;
            delete h;
        }
        else{
            NoRegistro* aux = tabela[pos];
            while(aux->prox != NULL){
                if(aux->prox->chave == chave){
                    NoRegistro* h = aux->prox;
                    aux->prox = aux->prox->prox;
                    delete h;
                    break;
                }
                aux = aux->prox;
            }
        }
    }
}

NoRegistro* destrutor_tabela (int chave){
    int pos = metodo_multi(chave);
    if(tabela[pos]==NULL){
        return NULL
    }
    else{
        NoRegistro* h = tabela[pos];
        delete tabela[pos];
        return h;
    }

}
};