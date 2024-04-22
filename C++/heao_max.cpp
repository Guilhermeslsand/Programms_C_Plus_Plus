#include <iostream>
#include <stdexcept>
using namespace std;

class Monte
{
    public:

    double* vet;
    int num_elem; // quantos elementos tem no vetor.
    int tam;
    bool desalocar;

    Monte(int tam_max)
    {   
        vet = new double[tam_max];
        num_elem = 0;
        desalocar = true;
        tam = tam_max;
    }

    ~Monte()
    {
        if(desalocar==true)delete vet;
        else
        {
        }
    }

    int capacidade ()
    {
        return tam;
    }

    int num_elementos ()
    {
        return num_elem;
    }

    void inserir(double elem)
    {
        if(num_elem < tam)
        {
                int pos_atual = num_elem;
                vet[num_elem] = elem; 
                num_elem++;
                int pai;
                while(pos_atual != 0)
                {
                    pai = (pos_atual-1)/2;
                    if(vet[pos_atual] < vet[pai])
                    {
                        break;
                    }
                    else
                    {
                        int aux = vet[pai];
                        vet[pai] = vet[pos_atual];
                        vet[pos_atual] = aux;
                        pos_atual = pai;
                    }
                }
        }
        else
        {
            throw runtime_error ("Tentativa de inserção com monte cheio!");
        }
    }

    double consultar()
    {
        if(num_elem!=0)
        {
            return vet[0];
        }
        else
        {
            throw runtime_error ("Tentativa de consulta com monte cheio!");
        }
    }

    void remover()
    {
        int ult_elem = num_elem-1;
        int pos_atual = 0;
        vet[0] = vet[ult_elem];
        num_elem--;
        while(pos_atual < num_elem)
        {
            int esq = 2*pos_atual + 1;
            int dir = 2*pos_atual + 2;
            int maior;
            if(dir > num_elem)
            {
                break;
            }
            if(vet[esq] >= vet[dir])
            {
                maior = esq;
            }
            else
            {
                maior = dir;
            }
            if(vet[pos_atual] < vet[maior])
            {
                int aux = vet[pos_atual];
                vet[pos_atual] = vet[maior];
                vet[maior] = aux;
                pos_atual = maior;
            }
            else
            {
                break;
            }

        }
        for(int i=0; i<num_elem; i++)
        {
            cout<<"Vetor:"<<" "<<vet[i]<<" ";
        }
    }

    //estretegia para monte.
    /*void monte_est (double vet[], int index, int tam_max)
    {
        int maior = index;
        int esq = 2 * maior + 1;
        int dir = 2 * maior + 2;

        if(esq < tam_max && vet[esq]>vet[maior]) maior = esq;

        if(dir < tam_max && vet[dir]>vet[maior]) maior = dir;

        if(maior != index)
        {
            swap(vet[index],vet[maior]);
            monte_est (vet, maior, tam_max);
        }
    }*/

    /*
    void monte_construir (double vet[], int tam_max)
    {
        int ult_pai = (tam_max/2)-1; // ultimo noh que possui um filho.

        for(int index = ult_pai; index >= 0; index--)
        {
            monte_est(vet,index,tam_max);
        }
    }*/

};

int main ()
{
    Monte M(10);
    if(M.capacidade() != 10 || M.num_elementos() != 0) 
    {
        cout<<M.capacidade();
        return 1;
    }
    for(int i = 0; i<10; i++) M.inserir(i);

    //for(int i = 0; i<10; i++) 
    //{
       // cout<<M.vet[i]<<"\n";
    //}
    
    //cout<<M.consultar()<<"\n";
    while ((M.num_elementos()!= 0))
    {
        cout<<"Remoção de "<<M.consultar()<<"\n";
        M.remover();
        cout<<"\n";
    }
}

  // Array representation of Max-Heap
    //            0
    //          /  \
    //         4    9
    //        / \   / \
    //       6   1 2   5
    //      / \ /
    //     8  7 3 