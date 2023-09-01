// -----------------------------------------------------------------------------
// Universidade Federal do CearÃ¡, Centro de CiÃªncias, Departamento de ComputaÃ§Ã£o
// Disciplina: Estruturas de Dados - TI0140 2022.2 T02A
// Professor: Pablo Mayckon Silva Farias
// Trabalho 2
// Interface para ImplementaÃ§Ã£o de DicionÃ¡rio baseado em Ã rvore AVL.
// Autor: Pablo Mayckon Silva Farias, em 22/11/2022.
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// IDENTIFICAÃ‡ÃƒO DO(A) ESTUDANTE:
//
// NOME: GUILHERME SALES DE ANDRADE
// MATRÃ CULA: 473995
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Tudo o que estÃ¡ presente na interface abaixo deve ser mantido como estÃ¡,
// pois Ã© essa interface que serÃ¡ utilizada no programa do professor para a
// realizaÃ§Ã£o dos testes.
//
// A realizaÃ§Ã£o do trabalho consiste portanto em *completar* a implementaÃ§Ã£o
// abaixo, tornando-a funcional e atendendo aos requisitos deste trabalho.
// -----------------------------------------------------------------------------
#include <new>
#include <exception>
#include <iostream>
using namespace std;

struct DicioAVL
  {
   typedef double TC;  // Tipo das Chaves
   typedef float  TV;  // Tipo dos Valores

   struct Noh {  TC chave;  TV valor;  int altura;  Noh *esq, *dir;  };

   Noh sent, *raiz;  // "sent": Sentinela.

   // Conforme a declaraÃ§Ã£o acima, a implementaÃ§Ã£o deve usar um nÃ³ sentinela,
   // que representarÃ¡ as subÃ¡rvores varias. Assim, por exemplo, os campos
   // "esq" e "dir" das folhas, ao invÃ©s de serem ponteiros nulos, apontarÃ£o
   // para "sent"; idem para o ponteiro "raiz", quando a Ã¡rvore estiver vazia.
   // O campo "altura" da sentinela deve sempre valer zero.

   // --------------------------------------------------------------------------

   // Deve criar um dicionÃ¡rio vazio.

   DicioAVL ()
     {
        sent.altura = 0;
        raiz = &sent;
        raiz->dir = &sent;
        raiz->esq = &sent;
     }

   // --------------------------------------------------------------------------

   // Deve desalocar a Ã¡rvore AVL.

   ~DicioAVL ()
     {
        apagar_AVL(raiz);
        raiz->dir = &sent;
        raiz->esq = &sent;
        raiz = &sent;
     }

   // --------------------------------------------------------------------------

   // Deve inserir a chave "c" e o valor "v" no dicionÃ¡rio, partindo da
   // PRÃ‰-CONDIÃ‡ÃƒO de que a chave "c" nÃ£o existe no dicionÃ¡rio -- ou seja,
   // a funÃ§Ã£o nÃ£o precisa nem deve fazer esse teste.
   //
   // A funÃ§Ã£o deve retornar um ponteiro apontando para o novo nÃ³.
   // Em caso de falha de alocaÃ§Ã£o de memÃ³ria, a funÃ§Ã£o deve retornar nullptr.
   //
   // ATENÃ‡ÃƒO: a chave deve permanecer no mesmo nÃ³ enquanto nÃ£o for removida
   // -------  do dicionÃ¡rio. Isso significa que, antes de tal remoÃ§Ã£o,
   //          deve ser possÃ­vel acessar a chave e seu valor a partir do
   //          ponteiro retornado pela funÃ§Ã£o de inserÃ§Ã£o.

   Noh* inserir (TC c, TV v)
     {
        Noh *busca;
        raiz = arv_AVL(raiz,c,v);
        busca = buscar(c);
        return busca;
     }

   // --------------------------------------------------------------------------

   // Deve retornar um ponteiro para o nÃ³ de chave "c", caso essa chave exista
   // no dicionÃ¡rio; caso a chave nÃ£o esteja presente, deve retornar nullptr.

   Noh* buscar (TC c)
     {
        sent.chave = c;
        Noh* n = raiz;
        while (n->chave != c)
        {  
            if(n->chave > c)
            {
                n = n->esq;
            }
            else
            {
                n = n->dir;
            }
        }
        if(n == &sent || n == nullptr)
        {
            return nullptr;
        }
        return n;
     }

    Noh* criar_noh(TC c, TV v)
     {
        Noh* h;
        try
        {
            h = new Noh;
            h->chave = c;
            h->valor = v;
            h->altura = 0;
            h->dir = &sent;
            h->esq = &sent;
        }
        
        catch(Noh &e)
        {
            return nullptr;
        }
        return h;
     }

    Noh* arv_AVL(Noh *n, TC c, TV v)
    {
        Noh* aux;
        if(n == &sent) {// árvore vazia
            aux = criar_noh(c,v);
            aux->altura = maior_subarv(altura_noh(n->esq), altura_noh(n->dir)) + 1; 
            return aux;
        }
        else{ // inserção será à esquerda ou à direita
            if(c < n->chave)
            {
                n->esq = arv_AVL(n->esq, c, v);
            }
            else
            {
                n->dir = arv_AVL(n->dir, c, v);
            }
        }
        // Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
        n->altura = maior_subarv(altura_noh(n->esq), altura_noh(n->dir)) + 1;

        // verifica a necessidade de rebalancear a árvore
        n = balancear(n);

        return n;

    }


    //Funcoes auxiliares cridas para usar no programa.
    void apagar_AVL(Noh* h)
    {
        if(h!=&sent)
        {
            apagar_AVL(h->esq);
            apagar_AVL(h->dir);
            delete h;
        }
    }

    //Retornar a altura da maior sub-arvore
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

    //Retornar a altura de um Noh da arvore.
    int altura_noh(Noh* n)
    {
        return n->altura;
    }

    //Calcula o fator de balaceamento de um Noh.
    int fator_balac(Noh* n)
        {
          int fator;
          if(n == &sent)
          {
            fator = 0;
            return fator;
          }
          else
          {
            fator = altura_noh(n->esq) - altura_noh(n->dir);
            return fator;
          } 
        }

    //Rotacao simples a esquerda
    Noh* rot_esq(Noh* n)
        {
            Noh *aux, *h;
            aux = n->dir;
            h = aux->esq;
            aux->esq = n;
            n->dir = h;
            n->altura = maior_subarv(altura_noh(n->esq), altura_noh(n->dir)) + 1;
            aux->altura = maior_subarv(altura_noh(aux->esq), altura_noh(aux->dir)) + 1;

            return aux;
        }

    //Rotacao simples a direita
    Noh* rot_dir(Noh* n)
        {
            Noh *aux, *h;
            aux = n->esq;
            h = aux->dir;
            aux->dir = n;
            n->esq = h;
            n->altura = maior_subarv(altura_noh(n->esq), altura_noh(n->dir)) + 1;
            aux->altura = maior_subarv(altura_noh(aux->esq), altura_noh(aux->dir)) + 1;

            return aux;
        }

    //Rotacao esquerda e direita
    Noh* rot_esq_dir(Noh* n)
        {
            n->esq = rot_esq(n->esq);
            return rot_dir(n);
        }

    //Rotacao direita e esquerda
    Noh* rot_dir_esq(Noh* n)
        {
            n->dir = rot_dir(n->dir);
            return rot_esq(n);;
        }

    //Funcao para tornar a arvore em AVL.
    Noh* balancear(Noh* h)
        {
            int fator = fator_balac(h);
            if(fator < -1 && fator_balac(h->dir) <= 0)
            {
                h = rot_esq(h);
            }
            else if(fator > 1 && fator_balac(h->esq) >= 0)
            {
                h = rot_dir(h);
            }
            else if(fator > 1 && fator_balac(h->esq) < 0)
            {
                h = rot_esq_dir(h);
            }
            else if(fator < -1 && fator_balac(h->dir) > 0)
            {
                h = rot_dir_esq(h);
            }
            return h;
        } 

  }; // DicioAVL  --------------------------------------------------------------

  int testar ()
    {
        DicioAVL D; int i; DicioAVL::Noh* nohs[9];
        for (i = 0; i <= 8; ++i)
        {
            DicioAVL::Noh* n = D.inserir(i, i/4);
            if (n == nullptr or n->chave != i or n->valor != i/4) return 1;
            nohs[i] = n;
        }
        for (i = 0; i <= 8; ++i)
        {
            if (D.buscar(i) != nohs[i]) return 2;
        }
        if (D.raiz->chave != 3 or D.raiz->esq->valor != 1/4 or
            D.raiz->dir->altura != 3 or D.raiz->esq->esq->esq != &D.sent)
        {
            return 3;
        }
        return 0;
    }
    int main ()
    {
        DicioAVL D;
        D.inserir (-215, 21);
        D.inserir (-290, -51);
        D.inserir (-217.5, 60.5);
        cout<<D.raiz->chave<<"\n";
        cout<<D.raiz->dir->chave<<"\n";
        cout<<D.raiz->esq->chave;
        if(D.raiz->chave < D.raiz->dir->chave)
        {
            cout<<"esta correto"<<"\n";
        }
        if (testar() != 0) cout << "Erro nos testes b´asicos!\n";
        else cout << "Testes b´asicos realizados com sucesso.\n";
    }