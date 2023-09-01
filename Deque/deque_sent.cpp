#include <iostream>
using namespace std;

struct Noh {int elem; Noh* prox, *ante;};

class Deque 
{

    public:
    Noh sent;

    Deque ()
    {
        sent.elem = 0;
        sent.prox = nullptr;
        sent.ante = nullptr;
    }

    bool vazio ()
    {
        if(sent.prox==nullptr)
        {
            return true;
        }
        return false;
    }

    void inserir_dir (int e)
    {
        if(vazio())
        {
            sent.prox = new Noh {e,sent.ante,&sent};
            sent.ante = sent.prox;
        }
        else
        {
            sent.prox->prox = new Noh {e,sent.ante,sent.prox};
            sent.prox = sent.prox->prox;
        }
    }

    void inserir_esq (int e)
    {
        if(vazio())
        {
            sent.ante = new Noh {e,&sent,sent.prox};
            sent.ante = sent.prox;
        }
        else
        {
           sent.ante->ante = new Noh {e,sent.ante,sent.prox};
           sent.ante = sent.ante->ante;
        }
    }

    void remover_dir ()
    {
        if(vazio())
        {
            cout<<"funciona";
        }
        else
        {    
            if(sent.prox->ante == &sent)
            {
                cout<<"funciona";
            }
            Noh* aux = sent.prox;
            sent.prox = sent.prox->ante;
            sent.ante->ante = sent.prox;
            delete aux;
           
        }
    }

    void remover_esq ()
    {
        if(vazio())
        {}
        else
        {
            Noh* aux = sent.ante;
            sent.ante = sent.ante->prox;
            sent.prox->prox = sent.ante;
            delete aux;
        }
    }

    ~Deque()
    {
        if(vazio())
        {

        }
        else
        {
            if(sent.prox->elem == 0)
            {
                sent.prox = nullptr;
                sent.ante = nullptr;
            }
            else
            {
                
                while(vazio()){
                    Noh* aux = sent.ante;
                    sent.ante = sent.ante->prox;
                }
            }
        }
    }

};

int main (){
    Deque d;
    d.inserir_dir(1);
    cout<<d.sent.prox->elem<<"\n";
    cout<<d.sent.prox->ante->elem<<"\n";
    d.inserir_dir(2);
    cout<<d.sent.prox->elem<<"\n";
    d.inserir_dir(3);
    cout<<d.sent.prox->elem<<"\n";
    d.inserir_esq(4);
    d.inserir_esq(5);
    d.remover_dir();
    d.remover_dir();
    d.remover_dir();
    d.inserir_dir(1);
    d.remover_esq();
    d.remover_esq();
    cout<<d.sent.prox->elem<<"\n";
    cout<<d.sent.ante->elem<<"\n";
}