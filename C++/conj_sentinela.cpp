#include <iostream>
using namespace std;

struct Noh {double elem; Noh* prox;};

class ConjuntoDouble
{
    public:
    Noh sent;

    ConjuntoDouble()
    {
        sent.prox = &sent;
    }

    bool pertence (double e)
    {
        if(vazio()){
            return false;
        }
        else{
            sent.elem = e;
            Noh* n = sent.prox;
            while(n->elem != e)
            {
                n = n->prox;
            } 
            if(n == &sent)
            {
                return false;
            }
            return true;
        }
    }

    void inserir_sem_testar (double e)
    {
        Noh* n  = new Noh{e,&sent};
        if(vazio())
        {
            sent.prox = n;
        }
        else
        {
            Noh* aux = sent.prox;
            while (aux->prox != &sent)
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
            Noh* n = sent.prox;
            while(n->prox->elem != e)
            {
                n = n->prox;
            }
            Noh* lixo = n->prox;
            n->prox = n->prox->prox;
        }
    }

    bool vazio ()
    {
        if(sent.prox == &sent)
        {
            return true;
        }
        return false;
    }

};

int main ()
{
    ConjuntoDouble c;
    c.inserir(1);
    c.inserir(2);
    c.inserir(3);
    c.inserir(4);
    c.inserir(5);
    c.inserir(6);
    c.inserir(7);
    c.remover(2);
    Noh* h = c.sent.prox;
    cout<<h->elem<<"\n";
    h = h->prox;
    cout<<h->elem<<"\n";
    h = h->prox;
    cout<<h->elem<<"\n";

}