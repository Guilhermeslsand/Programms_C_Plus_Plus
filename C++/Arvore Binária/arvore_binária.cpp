#include <iostream>
#include <exception>

using namespace std;

struct Noh{ int elem, altura; Noh* esq, *dir;};

struct ArvBB{
Noh* raiz;
ArvBB(): raiz(nullptr){}
void inserir (int e)
{
Noh* n = new Noh {e,0, nullptr, nullptr};
        if(raiz == nullptr)
        {
            raiz = n;
        }
        else{
            Noh* atual = raiz;
            for(;;){
                if(atual->elem > n->elem)
                {
                        if(atual->esq == nullptr)
                        {
                            atual->esq = n;
                            break;
                        }
                        else{
                            atual = atual->esq;
                        }
                    }
                    else{
                        if(atual->dir == nullptr){
                            atual->dir = n;
                            break;
                        }
                        else{
                            atual = atual->dir;
                        }
                    }
                }
            }
        }

        bool pertence( int e){
            Noh* n = raiz;
            while(n != nullptr){
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

        void busca_cam (int e)
        {
            if(pertence(e)){
                Noh* n = raiz;
                while(n != nullptr){
                    if(n->elem == e)
                    {   
                        break;
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
            }
        }

        void remover_2 (int e){
            Noh ** cima = &raiz; Noh*n;

            for(;;){
                n = *cima;
                if(n==nullptr) return;
                if(e == n->elem) break;
                if(e<n->elem) cima = &n->esq;
                else cima = &n->dir;
            }
            if(n->esq == nullptr){
                *cima = n->dir;
            }
            else if(n->dir == nullptr){
                *cima = n->esq;
            }
            else{
                
            }
        }

        void remover (int e){
            Noh* n = raiz, *cima=nullptr;

            //Estou procurando o Noh que vai ser excluido.
            //Cima vai ficar apontanto para o Noh anterior.
            while(n!=nullptr){
                if(e == n->elem) break;
                if(e < n->elem){cima = n; n = n->esq;}
                else{cima = n; n = n->dir;}
            }
            if(n == nullptr) return; //Nao encontrado.
            //So tem o filho direito.
            if(n->esq == nullptr)
            {
                //o que vai ser excluido eh a raiz sem um fihlo esquerdo.
                if(cima==nullptr) raiz = n->dir;
                //Remover da sub-arvore esquerda do filho direito da raiz.
                else if(n == cima->esq) cima->esq = n->dir;
                else cima->dir = n->dir;
            }
            //So tem o filho esquerdo.
            else if(n->dir == nullptr){
                if(cima == nullptr) raiz = n->esq;
                else if(n == cima->esq) cima->esq = n->esq;
                else cima->dir = n->esq;
            }
            //procurar o sucessor com o menor da direita
            else{
                Noh* p = n->dir, *ap = n;
                while(p->esq != nullptr){
                    ap = p;
                    p = p->esq;
                }
                //o laco nao foi executado.
                if(p==ap->dir) ap->dir = p->dir;

                else ap->esq = p->dir;
                p->esq = n->esq;
                p->dir = n->dir;
                if(cima==nullptr) raiz = p;
                else if(n == cima->esq) cima->esq = p;
                cima->dir = p;
            }
            delete n;
            cout<<"\n"<<"Anterior:"<<cima->elem<<"\n";
        }

        void imprimir_crescente (Noh* n){
            if(n!=nullptr){
                imprimir_crescente(n->esq);
                cout<<n->elem<<"\n";
                imprimir_crescente(n->dir);
            }
        }

        void imprimir_altura(){
            imp_alt_sub(raiz,1);
        }

        void imp_alt_sub(Noh*n, int al){
            if(n!=nullptr){
                imp_alt_sub(n->esq,al+1);
                imp_alt_sub(n->dir,al+1);
                cout<<"Alt("<<n->elem<<")="<<al<<"\n";
            }
        }

        void imp_prof_sub (Noh*n, int pf){
            if(n!=nullptr){
                cout<<"Prof("<<n->elem<<")="<<pf<<"\n";
                imp_prof_sub(n->esq, pf+1);
                imp_prof_sub(n->dir, pf+1);
            }
        }

        void imprimir_profundidade(){
            imp_prof_sub(raiz,1);
        }

        void apagar (Noh* &raiz)
        {
            if(raiz!=nullptr){
                apagar(raiz->esq);
                apagar(raiz->dir);
                delete raiz;
            }
            raiz = nullptr;
        }

        ~ArvBB ()
        {
            apagar(raiz);
        }

        Noh* criar_noh(int e)
        {
            Noh* h;
            try
            {
                h = new Noh;
                h->elem = e;
                h->altura = 0;
                h->dir = nullptr;
                h->esq = nullptr;
            }
        
            catch(Noh &e)
            {
                return nullptr;
            }
            return h;
        }

        int maior_subarv(int a, int b)
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
            if(n == nullptr)
            {
                return -1;
            }
            else
            {
                return n->altura;
            }
        }

        int fator_balac(Noh* n)
        {
            int fator;
            if(n != nullptr)
            {
                fator = altura_noh(n->esq) - altura_noh(n->dir);
                return fator; 
            }
            else
            {
                fator = 0;
                return fator;
            }
        }

        Noh* rot_esq(Noh* n)
        {
            Noh* y, *x;
            y = n->dir;
            x = y->esq;
            y->esq = n;
            n->dir = y;

            n->altura = maior_subarv(altura_noh(n->esq),altura_noh(n->dir)) + 1;
            y->altura = maior_subarv(altura_noh(y->esq),altura_noh(y->dir)) + 1;

            return y;
        }

         Noh* rot_dir(Noh* n)
        {
            Noh* y, *x;
            y = n->esq;
            x = y->dir;
            y->dir = n;
            n->esq = y;

            n->altura = maior_subarv(altura_noh(n->esq),altura_noh(n->dir)) + 1;
            y->altura = maior_subarv(altura_noh(y->esq),altura_noh(y->dir)) + 1;
        
            return y;
        }

        Noh* rot_esq_dir(Noh* n)
        {
            n->esq = rot_esq(n->esq);
            return rot_dir(n);
        }

        Noh* rot_dir_esq(Noh* n)
        {
            n->dir = rot_dir(n->dir);
            return rot_esq(n);
        }

        Noh* inserir_avl (Noh* n, int e)
        {
            if(n == nullptr) // n == &sent
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
            n->altura = maior_subarv(altura_noh(n->esq),altura_noh(n->dir))+1;
            n = balancear(n);
            return n;
        }

        Noh* balancear(Noh* h)
        {
            int fator = fator_balac(h);

            if(fator <-1 && fator_balac(h->dir)<=0)
            {
                h = rot_esq(h);
            }

            else if(fator > 1 && fator_balac(h->esq) >=0)
            {
                h = rot_dir(h);
            }


            else if(fator <-1 && fator_balac(h->dir) > 0)
            {
                h = rot_dir_esq(h);
            }

            else if(fator > 1 && fator_balac(h->esq)<0)
            {
                h = rot_esq_dir(h);
            }
            return h;
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
        cout<<b.raiz->elem<<"\n";
    }
