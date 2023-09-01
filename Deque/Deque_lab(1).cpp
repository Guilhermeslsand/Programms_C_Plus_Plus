#include <iostream>
using namespace std;

class DequeInt
{
    public:
    struct Noh { int elem; Noh *ant, *prox;};
    Noh *esq, *dir;
    DequeInt (): esq(nullptr), dir(nullptr) {}

    int consultar_dir () 
    { 
        if(vazio())
        {
            return 0;
        }
        else
        {
            return dir->elem;
        }
    }
    int consultar_esq () 
    { 
        if(vazio())
        {
            return 0;
        }
        else
        {
            return esq->elem;
        }
    }

    void inserir_dir (int e) 
    {
        if(vazio())
        {
            dir = new Noh;
            dir->elem = e;
            esq = dir;
        }
        else
        {
            dir->prox = new Noh;
            dir->prox->ant = dir;
            dir = dir->prox;
            dir->elem = e;
        }
    }

    void inserir_esq (int e) 
    { 
        if(vazio())
        {
            esq = new Noh;
            esq->elem = e;
            dir = esq;
        }
        else
        {
            esq->ant = new Noh;
            esq->ant->prox = esq;
            esq = esq->ant;
            esq->elem = e;
        }
    }

    void remover_dir () 
    {
        if(vazio())
        {
            cout<<"Deque vazio";
        }
        else
        {
            if(esq == dir)
            {   
                esq = nullptr;
                delete dir;
            }
            else
            {
                Noh* lixo = dir;
                dir = dir->ant;
                dir->prox->ant = nullptr;
                delete lixo;  
            }
        }
    }

    void remover_esq () 
    {
        if(vazio())
        {
            cout<<"Deque vazio";
        }
        else
        {
            if(esq == dir)
            {
                dir = nullptr;
                delete esq;
            }
            else
            {
                Noh* lixo = esq;
                esq = esq->prox;
                esq->ant->prox = nullptr;
                delete lixo;  
            }
        }
    }

    bool vazio () 
    {
        if (esq == nullptr && dir == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    ~DequeInt () 
    {
        while(esq != dir)
        {
            Noh* lixo = esq;
            esq = esq->prox;
            delete lixo;
        }
        delete esq;
    }

};

int main (){
    DequeInt d;
    for(int i = 1; i<=5; i++)
    {
        d.inserir_dir(i);
    }
    int h = d.consultar_dir();
    cout<<h<<"\n";
    d.remover_dir();
    h = d.consultar_dir();
    cout<<h<<"\n";
    for(int i = 6; i<=10; i++)
    {
        d.inserir_esq(i);
    }
    h = d.consultar_esq();
    cout<<h<<"\n";
}