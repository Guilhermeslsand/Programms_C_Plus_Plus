#include <iostream>
using namespace std;

struct Noh
{
    int elem;
    int altura;
    Noh *esq, *dir;
};

struct Arvore_AVL
{
    Noh* raiz;

    Arvore_AVL(){
        raiz = nullptr;
    }

    Noh* criar_noh (int e)
    {
        Noh* n = new Noh{e,0,nullptr,nullptr};
        return n;
    }

    int maior (int a, int b)
    {
        if(a > b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }

    int altura_noh(Noh* n)
    {
        if(n==nullptr)
        {
            return -1;
        }
        else
        {
            return n->altura;
        }
    }

    int fator_balac(Noh*n)
    {
        if(n==nullptr)
        {
            return 0;
        }
        else
        {
            return altura_noh(n->esq) - altura_noh(n->dir);
        }
    }

    Noh* rotacionar_esq(Noh* h)
    {
        Noh *x, *y;
        x = h->dir;
        y = x->esq;
        x->esq = h; 
        h->dir = y;

        h->altura = maior(altura_noh(h->esq),altura_noh(h->dir))+1;
        x->altura =  maior(altura_noh(x->esq),altura_noh(x->dir))+1;

        return x;
    }

    Noh* rotacionar_dir(Noh* h)
    {
        Noh *x, *y;
        x = h->esq;
        y = x->dir;
        x->dir = h; 
        h->esq = y;

        h->altura = maior(altura_noh(h->esq),altura_noh(h->dir))+1;
        x->altura =  maior(altura_noh(x->esq),altura_noh(x->dir))+1;

        return x;
    }

    Noh* rotacionar_esq_dir(Noh* h)
    {
        h->esq = rotacionar_esq(h->esq);
        return rotacionar_dir(h);
    }

    Noh* rotacionar_dir_esq(Noh* h)
    {
        h->dir = rotacionar_esq(h->dir);
        return rotacionar_dir(h);
    }

    Noh* balancear (Noh* h)
    {
        int fator = fator_balac(h);

        if(fator > 1 && fator_balac(h) >= 0)
        {
            h = rotacionar_dir(h);
        }

        else if(fator > 1 && fator_balac(h) < 0)
        {
            h = rotacionar_esq_dir(h);
        }
        
        else if(fator < -1 && fator_balac(h) > 0)
        {
            h = rotacionar_dir_esq(h);
        }
        else if(fator < -1 && fator_balac(h) <=0)
        {
            h = rotacionar_esq(h);
        }

        return h;
    }

    void inserir(int e)
    {
        if(raiz==nullptr)
        {
            raiz = new Noh {e,0,nullptr,nullptr};
        }
        else
        {
            raiz = inserir_avl(raiz,e);
        }
    }


    Noh* inserir_avl (Noh* n, int e)
    {
        if(n = nullptr)
        {
            n = criar_noh(e);
            return n;
        }
        else
        {
            if(n->elem > e)
            {
                n->esq = inserir_avl(n->esq,e);
            }
            else
            {
                n->dir = inserir_avl(n->dir,e);
            }
        }
        n->altura = maior(altura_noh(n->dir),altura_noh(n->esq))+1;

        n = balancear(n);

        return n;
    }

    void imprimi_ordem (Noh* n)
    {
        if(n!=nullptr){
            imprimi_ordem(n->esq);
            cout<<"Altura("<<n->altura<<"):"<<n->altura<<"\n";
            imprimi_ordem(n->dir);
        }
    }
};

int main ()
{
    Arvore_AVL D;
    for(int i=1; i<=10; i++)
    {
        D.inserir(i);
    }
    D.imprimi_ordem(D.raiz);
}