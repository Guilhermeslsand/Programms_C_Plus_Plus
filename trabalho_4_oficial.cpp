#include <iostream>
#include <exception>

using namespace std;

struct SimulAloc{
    struct Noh
    {
        int ini, tam;
        Noh* prox = nullptr;
    };

    Noh* prim;

    SimulAloc (): prim(nullptr){}

Noh* juntar(Noh* x, Noh* y){
        if(x==nullptr or y==nullptr) return nullptr;
        if(x->ini + x->tam >= y->ini)
        {
            x->tam = x->tam + y->tam;
            x->prox = y->prox;
            return y;
        }
        return nullptr;
    }

    bool inicializar (int ini, int tam){
        try{
            prim = new Noh;
            prim->ini = ini;
            prim->tam = tam;
        }
        catch (Noh &e){
            return true;
        }
        return false;
    }

    int alocar(int tam){
        if(tam != 0 and prim){
            int endereco;
            
            if(prim->tam >= tam){
                endereco = prim->ini + prim->tam - tam;
                prim->tam -= tam;

                
                if(prim->tam == 0){
                    Noh* des = prim;
                    prim = prim->prox;
                    delete des;
                }

                return endereco;
            }else{ 
                Noh* n = prim;
                while(n->prox!=nullptr && n->prox->tam < tam){
                    n = n->prox;
                }
                
                if(n->prox){
                    endereco = n->prox->ini + n->prox->tam - tam; 
                    n->prox->tam -= tam;

                    
                    if(n->prox->tam == 0){
                        Noh* des = n->prox;
                        n->prox = n->prox->prox;
                        delete des;
                    }

                    return endereco;
                }
            }
        }
        return -1;
    }
            

    bool desalocar (int ini, int tam){
        Noh* h;
        
         try
        {
            h = new Noh;
            h->ini = ini;
            h->tam = tam;
            h->prox = nullptr;
        }
        
         catch(Noh &e)
        {
            return true;
        }
        if(prim==nullptr || prim->ini > ini)
        {
            Noh* lixo;
            h->prox = prim;
            lixo = juntar(h,prim);
            delete lixo;
            prim = h;
        }
        else
        {
            Noh* n = prim;
            while(n->prox!=nullptr && h->ini+h->tam>n->prox->ini)
            {
                n = n->prox;
            }
            Noh* lixo;
            h->prox = n->prox;
            n->prox = h;
            if(h!=nullptr)
            {
                lixo = juntar(h,h->prox);
                delete lixo;
            }
            lixo = juntar (n, h);
            delete lixo;
        }
        return false;
    }
        
        void terminar () {
        Noh* n = prim;
        Noh* lixo;
        while(n!=nullptr){
            lixo = n;
             n = n->prox;
            delete lixo;  
        }
    }
        
};



int main(){
    SimulAloc l;
    l.inicializar(58,150);
    l.alocar(45);
    l.alocar(20);
    l.desalocar(143,20);
    l.alocar(17);
    l.desalocar(163, 45);
    l.alocar(24);
    l.desalocar(146,17);
    while(l.prim!=nullptr){
        cout<<l.prim->ini<< " "<<l.prim->tam<<"\n";
        l.prim = l.prim->prox;
    }
}