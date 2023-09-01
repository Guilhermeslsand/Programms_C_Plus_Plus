#include <iostream>
#include <stdexcept>
using namespace std;

class Monte
{
    public:

    double* vet;
    double monte;
    int num_elem; // quantos elementos tem no vetor.
    int tam;
    bool desalocar;

    Monte(int tam_max)
    {   
        vet = new double[tam_max];
        for(int i = 0; i < tam_max; i++)
        {
            vet[i] = -1;
        }
        num_elem = 0;
        desalocar = true;
        tam = tam_max;
    }

    Monte(double vet[], int tam_max)
    {
        double monte[tam_max];
        tam = tam_max;
        num_elem = tam_max;
        desalocar = false;
        int j = 0;
        for(int i = tam-1; i>=0; i--)
        {
            int pai = (i-1)/2;
            int maior = pai;
            int esq = 2 * i +1;
            int dir = 2 * i + 2;
            if(esq < tam && vet[esq]>vet[maior])
            {
                maior = esq;
            }
            if(dir < tam && vet[dir]>vet[maior])
            {
                maior = dir;
            }
            monte[j] = maior;
            j++;
        }
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
                vet[num_elem] = elem; 
                num_elem++;
                for(int i = tam; i>=0; i--)
                {
                    int maior = i;
                    int esq = 2 * maior +1;
                    int dir = 2 * maior + 2;
                    if(esq < tam && vet[esq]>vet[maior])
                    {
                        maior = esq;
                    }
                    if(dir < tam && vet[dir]>vet[maior])
                    {
                        maior = dir;
                    }
                    if(maior != i)
                    {
                        swap(vet[i],vet[maior]);
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
        vet[0] = vet[ult_elem];
        vet[ult_elem] = -1;
        num_elem--;
        for(int i = tam; i>=0; i--)
        {
            int maior = i;
            int esq = 2 * maior +1;
            int dir = 2 * maior + 2;
            if(esq < tam && vet[esq]>vet[maior])
            {
                maior = esq;
            }
            if(dir < tam && vet[dir]>vet[maior])
            {
                maior = dir;
            }
            if(maior != i)
            {
                swap(vet[i],vet[maior]);
            }           
        }
    }

    void monte_est (double vet[], int index, int tam_max)
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
    }

    void monte_construir (double vet[], int tam_max)
    {
        int ult_pai = (tam_max/2)-1;

        for(int index = ult_pai; index >= 0; index--)
        {
            monte_est(vet,index,tam_max);
        }
    }

};

/*int main ()
{
    Monte M(10);
    if(M.capacidade() != 10 || M.num_elementos() != 0) 
    {
        cout<<M.capacidade();
        return 1;
    }
    for(int i = 0; i<10; i++) M.inserir(i);
    cout<<M.consultar()<<"\n";
    while ((M.num_elementos()!= 0))
    {
        cout<<"Remoção de "<<M.consultar()<<"\n";
        M.remover();
    }
    
}*/

int main ()
{
    double v[10] = {0, 4, 9, 6, 1, 2, 5, 8, 7, 3}; Monte M(v,10);

    cout<< "Máximo: "<<M.consultar()<<"\n";

    while(M.num_elementos()!=0)
    {
        cout<<"Remoção de "<<M.consultar()<<"\n";
        M.remover();
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