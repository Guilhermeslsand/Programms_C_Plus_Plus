#include <iostream>
using namespace std;

struct Noh 
{
    int elem;
    int altura;
    Noh* dir, *esq;
};

struct arvore_AVL
{
    Noh* raiz;

    arvore_AVL ()
    {
        raiz = nullptr;
    }

    int altura (Noh* n)
    {
        int alt_esq = 0;
        int alt_dir = 0;

        if(n->esq)
        {
            alt_esq = altura (n->esq);
        }
        if(n->dir)
        {
            alt_dir = altura(n->dir);
        }
        return (alt_dir > alt_esq)? alt_dir: alt_esq + 1;
    }

    int altura_noh(Noh* n)
    {
        if(n == nullptr)
        {
            return -1;
        }
        return n->altura;
    }

    int fator_bal (Noh* n)
    {
        if(n != nullptr)
        {
            return (altura_noh(n->esq)-altura_noh(n->dir));
        }
        else
        {
            return 0;    
        }
    }

    int altura_arv (int a, int b)
    {
        return (a > b)? a: b;
    }

    Noh* rot_dir (Noh* h)
    {
        Noh *x, *y;
        x = h;
        y = x->dir;
        x->dir = y->esq;
        y->esq = x; 

        return y;
    }

    Noh* rot_esq (Noh* h)
    {
        Noh *x, *y;
        x = h;
        y = x->esq;
        x->esq = y->dir;
        y->dir = x;

        return y;
    }

    Noh* rot_esq_dir (Noh* h)
    {
        h->esq = rot_esq (h->esq);
        return rot_dir (h);
    }

    Noh* rot_dir_esq (Noh* h)
    {
        h->dir = rot_dir (h->dir);
        return rot_esq (h);
    }

    Noh* balancear_noh (Noh* n)
    {
        Noh* noh_bal= nullptr;
        if (n->esq )
        {
		    n->esq = balancear_noh ( n->esq );
        }
        if (n->dir )
        {
    	    n->dir = balancear_noh ( n->dir );
        }   
	    int fator = fator_bal (n);

        if(fator >= 2)
        {
            if(fator_bal(n->esq) <= -1)
            {
                noh_bal = rot_esq_dir(n);
            }
            else
            {
                noh_bal = rot_esq(n);
            }
        }

        else if(fator <= -2)
        {
            if(fator_bal(n->dir) >= 1)
            {
                noh_bal = rot_dir_esq(n);
            }
            else
            {
                noh_bal = rot_dir(n);
            }
        }
        else
        {
            noh_bal = n;
        }
        return noh_bal;
    }

    void mudar_altura (Noh* n, int i)
    {

        if(n!=nullptr)
        {
            mudar_altura(n->esq,i+1);
            n->altura = altura(n);
            mudar_altura(n->dir,i+1);
        }
    }

    Noh* inserir_arv(Noh* n, int e)
    {
        Noh* c = new Noh{e,0,nullptr,nullptr};
        if(n == nullptr)
        {
            n = c; 
        }
        else
        {
            if(e < n->elem)
            {
                n->esq = inserir_arv(n->esq, e);
            }
            else
            {
                n->dir = inserir_arv(n->dir, e);
            }
        }
        n->altura = altura_arv(altura_noh(n->esq), altura_noh(n->dir)) + 1;
        n = balancear_noh(n);
        return n;
    }

    Noh* inserir (int e)
    {
        raiz = inserir_arv(raiz,e);
        mudar_altura(raiz,0);
        return raiz;
    }

    void imprimi_arv (Noh* n)
    {
        if(n != nullptr)
        {   
            imprimi_arv(n->esq);
            cout<<n->elem<<" "<<n->altura<<" "<<fator_bal(n)<<"\n";
            imprimi_arv(n->dir);
        }
    }
};

int main () 
{
    arvore_AVL a;
    a.inserir(10);
    a.inserir(15);
    a.inserir(20);
    a.inserir(25);
    a.inserir(30);
    a.imprimi_arv(a.raiz);
}

 
