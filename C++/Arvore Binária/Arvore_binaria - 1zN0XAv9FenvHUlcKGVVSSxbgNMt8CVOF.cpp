#include <iostream>
#include <exception>

using namespace std;

struct Noh{ int elem; Noh* esq, *dir;};

struct ArvBB
{
    Noh* raiz;

    ArvBB(): raiz(nullptr){}

    void inserir (int e)
    {
        Noh* n = new Noh {e,nullptr, nullptr};
        if(raiz == nullptr)
        {
            raiz = n;
        }
        else
        {
            Noh* atual = raiz;
            for(;;)
            {
                if(atual->elem > n->elem)
                {
                    if(atual->esq == nullptr)
                    {
                        atual->esq = n;
                        break;
                    }

                    else
                    {
                        atual = atual->esq;
                    }
                }

                else
                {
                    if(atual->dir == nullptr)
                    {
                        atual->dir = n;
                        break;
                    }

                    else
                    {
                        atual = atual->dir;
                    }
                }   
            }
        }
    }

    bool pertence( int e)
    {
        Noh* n = raiz;
        while(n != nullptr)
        {
            if(n->elem == e)
            {
                return true;
            }

            else if(n->elem > e)
            {
                n = n->esq;
            }

            else
            {
                n = n->dir;
            }
        }
        return false;
    }

    Noh* busca (int e)
    {
        if(pertence(e))
        {
            Noh* n = raiz;
            while(n != nullptr)
            {
                if(n->elem == e)
                {   
                    return n;
                }

                else if(n->elem > e)
                {
                    n = n->esq;
                }

                else
                {
                    n = n->dir;
                }
            }
            return nullptr;
        }
    }

    void remover_2 (int e)
    {
        Noh ** cima = &raiz; Noh*n;
        for(;;)
        {
            n = *cima;
            if(n==nullptr) return;
            if(e == n->elem) break;
            if(e<n->elem) cima = &n->esq;
            else cima = &n->dir;
        }
        if(n->esq == nullptr)
        {
            *cima = n->dir;
        }
        else if(n->dir == nullptr)
        {
            *cima = n->esq;
        }
        else
        {
            Noh* p = n->dir, *ap = n;
            while(p->esq != nullptr)
            {
                ap = p;
                p = p->esq;
            }
        
            if(p==ap->dir) {ap->dir = p->dir;} //o laco nao foi executado.

            else {ap->esq = p->dir;}
            p->esq = n->esq;
            p->dir = n->dir;
            *cima = p;
        }
        delete n;
    }

    void remover (int e)
    {
        Noh* n = raiz, *cima=nullptr;

        //Estou procurando o Noh que vai ser excluido.
        //Cima vai ficar apontanto para o Noh anterior.
        while(n!=nullptr)
        {
            if(e == n->elem) break;
            if(e < n->elem){cima = n; n = n->esq;}
            else{cima = n; n = n->dir;}
        }

        if(n == nullptr) return; //Nao encontrado.

        if(n->esq == nullptr) //So tem o filho direito.
        {
            if(cima==nullptr) raiz = n->dir; //o que vai ser excluido eh a raiz sem um fihlo esquerdo.
            else if(n == cima->esq) cima->esq = n->dir; //Remover da sub-arvore esquerda e o sucessor é o filho direito da raiz.
            else cima->dir = n->dir;
        }

        else if(n->dir == nullptr) //So tem o filho esquerdo.
        {
            if(cima == nullptr) raiz = n->esq;
            else if(n == cima->esq) cima->esq = n->esq;
            else cima->dir = n->esq;
        }

        else //procurar o sucessor com o menor da direita
        {
            //p é o sucessor e ap é o anterior ao sucessor.
            Noh* p = n->dir, *ap = n;
            while(p->esq != nullptr)
            {
                ap = p;
                p = p->esq;
            }
        
            if(p==ap->dir) ap->dir = p->dir; //o laco nao foi executado.

            else {ap->esq = p->dir;}
            p->esq = n->esq;
            p->dir = n->dir;
            if(cima==nullptr) {raiz = p;}
            else if(n == cima->esq) {cima->esq = p;}
            else if(n==cima->dir) {cima->dir = p;}
        }
        delete n;
    }

    void imprimir_crescente (Noh* n)//ordem
    {
        if(n!=nullptr)
        {
            imprimir_crescente(n->esq);
            cout<<n->elem<<"\n";
            imprimir_crescente(n->dir);
        }
    }


    void imprimir_altura()
    {
        imp_alt_sub(raiz,1);
    }

    void imp_alt_sub(Noh*n, int al)//pos-ordem;
    {
        if(n!=nullptr)
        {
            imp_alt_sub(n->esq,al+1);
            imp_alt_sub(n->dir,al+1);
            cout<<"Alt("<<n->elem<<")="<<al<<"\n";
        }
    }

    void imp_prof_sub (Noh*n, int pf) //pre-ordem;
    {
        if(n!=nullptr)
        {
            cout<<"Prof("<<n->elem<<")="<<pf<<"\n";
            imp_prof_sub(n->esq, pf+1);
           imp_prof_sub(n->dir, pf+1);
        }
    }

    void imprimir_profundidade()
    {
        imp_prof_sub(raiz,1);
    }

    void apagar (Noh* n)
    {
        if(n!=nullptr)
        {
            apagar(n->esq);
            apagar(n->dir);
            delete n;
        }
    }

    ~ArvBB ()
    {
        apagar(raiz);
        raiz = nullptr;
    }
};

    int main (){
        ArvBB b;
        b.inserir (20);
        b.inserir (10);
        b.inserir (8);
        b.inserir (6);
        b.inserir (9);
        b.inserir (15);
        b.inserir (14);
        b.inserir (18);
        b.inserir (30);
        b.inserir (33);
        b.inserir (25);
        b.imprimir_altura();
        b.imprimir_profundidade();
        /*
        b.remover_2(20);
        cout<<b.raiz->elem<<"\n";
        cout<<b.raiz->dir->elem<<"\n";
        cout<<b.raiz->esq->elem<<"\n";
        */
    }
