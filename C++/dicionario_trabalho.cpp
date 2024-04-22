// -----------------------------------------------------------------------------
// Universidade Federal do CearÃ¡, Centro de CiÃªncias, Departamento de ComputaÃ§Ã£o
// Disciplina: Estruturas de Dados - TI0140 2022.2 T02A
// Professor: Pablo Mayckon Silva Farias
// Trabalho 2
// Interface para ImplementaÃ§Ã£o de DicionÃ¡rio baseado em Ãrvore AVL.
// Autor: Pablo Mayckon Silva Farias, em 22/11/2022.
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// IDENTIFICAÃ‡ÃƒO DO(A) ESTUDANTE:
//
// NOME: GUILHERME SALES DE ANDRADE
// MATRÃCULA: 473995
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
    
        if(raiz == &sent)
        {
            raiz = h;
        }
        else
        {
            Noh *atual = raiz;
            for(;;)
            {
                if((atual)->chave > c)
                {
                    if(atual->esq == &sent)
                    {
                        atual->esq = h;
                        break;
                    }
                    atual = atual->esq;
                }
                else
                {
                    if(atual->dir == &sent)
                    {
                        atual->dir = h;
                        break;
                    }
                    atual = atual->dir;
                }
            }
        }
            nova_altura(raiz);
            raiz = balancear(raiz);
            nova_altura(raiz);
            return h;
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
        if(n == &sent)
        {
            return nullptr;
        }
        else
        {
            return n;
        }
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
        if(n == &sent)
        {
            return -1;
        }
        else
        {
            return n->altura;
        }
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

    //Redefine as alturas dos Nohs da arvore.
    void nova_altura (Noh* p)
        {
          if(p != &sent)
          {
            nova_altura (p->esq);
            nova_altura (p->dir);
            p->altura = maior_subarv(altura_noh(p->esq), altura_noh(p->dir)) + 1;
          }
        }

    //Rotacao simples a esquerda
    Noh* rot_esq(Noh* n)
        {
            Noh* aux = n;
            Noh* left = aux->esq;
            aux->esq = left->dir;
            left->dir = aux;
            return left;
        }

    //Rotacao simples a direita
    Noh* rot_dir(Noh* n)
        {
            Noh* aux = n;
            Noh* rig = aux->dir;
            aux->dir = rig->esq;
            rig->esq = aux;
            return rig;
        }

    //Rotacao esquerda e direita
    Noh* rot_esq_dir(Noh* n)
        {
            Noh* aux = n;
            Noh* left = aux->esq;
            Noh* rig = left->dir;
            aux->esq = rig->dir;
            left->dir = rig->esq;
            rig->esq = left;
            rig->dir = aux;
            return rig;
        }

    //Rotacao direita e esquerda
    Noh* rot_dir_esq(Noh* n)
        {
            Noh* aux = n;
            Noh* rig = aux->dir;
            Noh* left = rig->esq;
            aux->dir = left->esq;
            rig->esq = left->dir;
            left->dir = rig;
            left->esq = aux;
            return left;
        }

    //Funcao para tornar a arvore em AVL.
    Noh* balancear(Noh* h)
        {
          int fator = fator_balac(h);
          Noh* balance;
          
          if(h == &sent)
          {
            return &sent;
          }

          if(h->dir != &sent)
          {
            h->dir = balancear(h->dir);
          }

          if(h->esq != &sent)
          {
            h->esq = balancear(h->esq);
          }

          if(fator >= 2)
          {
            if(fator_balac(h->dir) <= -1)
            {
              balance = rot_esq_dir(h);
            }
            else
            {
              balance = rot_esq(h);
            }
          }

          else if(fator <= -2)
          {
            if(fator_balac(h->dir) >= 1)
            {
              balance = rot_dir_esq(h);
            }
            else
            {
              balance = rot_dir(h);
            }
          }

          else
          {
            balance = h;
          }

          return balance;
        } 
  }; // DicioAVL  --------------------------------------------------------------