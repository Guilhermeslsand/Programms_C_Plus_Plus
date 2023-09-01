#include <iostream>
using namespace std;

struct Noh
{
    int elem;
    Noh* dir, *esq;
};


void heapify (int vetor[], int tam, int raiz_index)
{
    int maior = raiz_index;
    int esq = 2*raiz_index+1;
    int dir = 2*raiz_index+2;

    if(esq < tam && vetor[esq] > vetor[maior])
    {
        maior = esq;
    }
    
    if(dir < tam && vetor[dir] > vetor[maior])
    {
        maior = dir;
    }

    if(maior != raiz_index)
    {
        int aux = vetor[raiz_index];
        vetor[raiz_index] = vetor[maior];
        vetor[maior] = aux;
        heapify(vetor, tam, maior);
    }
}

void construir_heap(int vetor[], int tam)
{
    int ultimo_pai = (tam/2)-1; // Ultimo noh da arvore que tem um filho.

    for(int raiz_index = ultimo_pai; raiz_index >= 0; raiz_index--)
    {
        heapify(vetor, tam, raiz_index);
    }
}

int main ()
{
    int tam;
    int vetor[] = {3,5,8,10,17,11,13,19,22,24,29};
    tam = sizeof(vetor)/sizeof(vetor[0]);
    construir_heap(vetor, tam);
    for(int i = 0; i<tam; i++)
    {
        cout<<vetor[i]<<"\n";
    }
}