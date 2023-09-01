#include <iostream>

struct SilmulAloc{
    struct Noh
    {
        int ini, tam;
        Noh* prox = NULL;
    };

    Noh* prim;
    int mem_disp;

    SilmulAloc(): prim(nullptr){}

    bool inicializar (int ini, int tam){
        prim = new Noh;
        if(prim == NULL){
            return true;
        }
        else{
            prim->ini = ini;
            prim->tam = tam;
            return false;
        }
    }

    int alocar (int tam){
        if(inicializar()){
            cout<<"Sem memoria para alocar";
            return -1;
        }
        else{
            if(tam <= prim->tam){
                prim->tam = prim->tam - tam;
                if(prim->tam == 0){
                    Noh* lixo = prim;
                    int c = prim->ini;
                    prim = prim->prox;
                    delete lixo;
                    return c;
                } 
                else{
                    return prim->tam;
                }
            }
            else{
                Noh* aux = prim;
                while (aux->prox=!NULL){
                    if(aux->prox->tam <= tam){
                        aux->prox->tam = aux->prox->tam - tam;
                        if(aux->prox->tam == 0){
                            Noh* lixo = aux->prox;
                            int c = aux->prox->ini;
                            aux->prox = aux->prox->prox;
                            delete lixo;
                            return c;
                        } 
                        else{
                            return aux->prox->tam
                        }
                    }
                    aux = aux->prox;
                }
                cout<<"Sem memoria para alocar";
                return -1;
                }
        }
    }

};  