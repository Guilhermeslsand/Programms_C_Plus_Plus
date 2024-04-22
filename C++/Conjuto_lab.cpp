#include <iostream>
using namespace std;

struct Noh {double elem; Noh* prox;};

class ConjuntoDouble
{
    public:
    Noh* prim;

    ConjuntoDouble (): prim(nullptr) {}

    Noh** localizar (double e)
    {
        Noh* n = prim;
        while(n && n->elem!=e)
        {
            n = n->prox;
        }
        Noh** p = &n;
        return p;
    }

    bool pertence (double e)
    {
        Noh** n = localizar(e);
        if((*n)!=nullptr && (*n)->elem == e)
        {
            return true;
        }
        return false;
    }

    void inserir_sem_testar (double e)
    {
        Noh* n = new Noh{e, nullptr};
        if(!prim)
        {
            prim = n;
        }
        else
        {
            Noh* aux = prim;
            while(aux->prox)
            {
                aux = aux->prox;
            }
            aux->prox = n;
        }
    }

    void inserir (double e)
    {
        if(!pertence(e))
        {
            inserir_sem_testar(e);
        }

    }

    void remover (double e)
    {
        if(pertence(e))
        {
            Noh* n = prim;
            Noh** p = &n;
            while(*p){
            if((*p)->prox->elem == e)
            {
                break;
            }
            (*p) = (*p)->prox;
            }
            (*p)->prox = (*p)->prox->prox;
        }
    }

};

int main ()
{
    ConjuntoDouble c;
    c.inserir(1);
    c.inserir(2);
    c.inserir(3);
    c.inserir(4);
    c.inserir(4);
    c.inserir(5);
    c.inserir(6);
    c.inserir(7);
    Noh* n = c.prim;
    while(n)
    {
        cout<<n->elem<<"\n";
        n = n->prox;
    }
}