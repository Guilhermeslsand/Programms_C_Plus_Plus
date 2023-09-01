#include <iostream>
using namespace std;

struct Noh
{
    int elem;
    Noh* dir; Noh* esq;
};

class Fila  
{
    public:

    Noh** p;
    Noh** topo;

    Fila(){p = new Noh*; topo = p;}

    void empilhar(Noh* e)
    {
        topo = &e;
    }

    Noh* desempilhar ()
    {
        Noh* des = *topo;
        *topo = (*topo)->esq;
        delete des;
        return *topo;
    }

    bool vazia ()
    {   
        Noh* aux = (*topo)->esq;
        if(aux != nullptr){
            return true;
        }
            return false;
    }
};

struct ArvBB
{
    Noh* raiz;
    Fila f;

    ArvBB (): raiz(nullptr){}

    void inserir(int e)
    {
        Noh* n = new Noh{e,nullptr,nullptr};
        if(raiz == nullptr) raiz = n;
        else
        {
            Noh* atual = raiz;
            for(;;)
            {
                if(n->elem < atual->elem)
                {
                    if(atual->esq == nullptr)
                    {atual->esq = n; break;}
                    else 
                    {atual = atual->esq;}
                }
                else
                {
                    if(atual->dir == nullptr)
                    {atual->dir = n; break;}
                    else 
                    {atual = atual->dir;}
                }
            }
        }
    }

    bool pertence (int e)
    {
        Noh* n = raiz;
        while(n)
        {
            if(n->elem == e){cout<<"pertence"<<"\n";return true;}
            else if(n->elem < e){n = n->esq;}
            else {n = n->dir;}
        }
        cout<<"Nao pertence"<<"\n";
        return false;
    }

    void desalocar()
    {
        f.empilhar(raiz);
        Noh* lixo;
        while(f.vazia())
        {   
            lixo = f.desempilhar();
            if(lixo->esq)
            {
                f.empilhar(lixo->esq);
            }
            if(lixo->dir)
            {
                f.empilhar(lixo->dir);
            }
            delete lixo;
        }
    }

    void ordem_descresente ()
    {

    }
};


int main(){
    ArvBB b;
    b.inserir (5);
    b.inserir (10);
    b.inserir (4);
    b.pertence (5);
    b.desalocar();
    b.pertence(10);
    b.pertence(5);
}