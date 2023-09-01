# include <iostream>
using namespace std;

class Registro {
public :
int chave ;
int dado ;
};

class ListaOrdenada {
public :
Registro ** L ;
int tam_max ; 
int cont ; 

ListaOrdenada ( int tamanho ){
tam_max = tamanho ;
L = new Registro *[ tam_max ]();
cont = 0;
}

int inserir ( Registro * reg ){
    int pos = cont;
    if(cont == tam_max){
        return -1;
    }
    else{
        if(pos == 0){
            L[pos] = reg;
            cont++;
            return pos;
        }
        else{
            for(int i = 0; i<cont; i++){
                if(reg->chave < L[i]->chave){
                    for(int j = cont; j>i; j--){
                        L[j] = L[j-1]; 
                    }
                    L[i] = reg;
                    cont++;
                    return i;
                }
                else{
                    L[pos] = reg;
                    cont++;
                    return pos;
                }
            }
        }
    }
}

Registro buscar ( int chave ){
    int ini = 0;
    int fim = cont-1;
    while(ini<=fim){
        int meio = ini+fim/2;
        Registro busca = L[meio];
        if(chave == busca.chave){
            return busca;
        }
        else if(chave > busca.chave){
            ini = meio+1;
        }
        else{
            fim = meio;
        }
    }
    return NULL;
}

Registro remover (int chave){
    int ini = 0;
    int fim = cont-1;
    while(ini<=fim){
        int meio = ini+fim/2;
        if(chave == L[meio]->chave){
            Registro aux = L[meio];
            for(int i = meio; i<cont-1; i++){
                L[i] = L[i+1]
            }
            cont--;
            return aux;
        }
        else if(chave > L[meio]->chave){
            ini = meio+1;
        }
        else{
            fim = meio;
        }
    }
    return NULL;
}

};