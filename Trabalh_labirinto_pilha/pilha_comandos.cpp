#include <iostream>
using namespace std;

class Posicao{
    public:
    int l;
    int c;
};

class PilhaPosicao{
    public:
    Posicao* v;
    int topo;
    int tam_max;
    int cont; // numero de elementos da pilha

    //metodo inicializar da pilha
    PilhaPosicao (int tamanho){
        tam_max = tamanho;
        v = new Posicao[tamanho];
        topo = -1;
        cont = 0;
    }

    // metodo empilhar
    void empilhar ( Posicao p ){
        if(cont<tam_max){
            v[cont] = p;
            topo++;
            cont++;
        }
        else{
            cout<<"Pilha esta cheia"<<endl;
        }
 
    }
    // metodo desempilhar
    Posicao desempilhar (){
        Posicao d;
        d = v[topo];
        topo--;
        cont--;
        return d;
    }
    // metodo pilha vazia
    int vazia (){
        if(cont == 0){
            return 1;
        }
        return 0;
    }
};

int main(){
    PilhaPosicao f (10); 
    Posicao p ;
    for (int i = 0; i < 10; i ++){
        p.l = i * i ;
        p.c = i * i * i ;
        f.empilhar (p);
    }
    for ( int i = 0; i < 5; i ++){
        p = f.desempilhar ();
        printf ( " linha %d , coluna % d \n " , p.l , p.c );
    }
    printf ( " \n " );
    for ( int i = 5; i < 10; i ++){
        p.l = i * i ;
        p.c = i * i * i ;
        f.empilhar ( p );
    }
    while (! f.vazia ()){
        p = f.desempilhar ();
        printf ( " linha %d , coluna % d \n " , p.l , p.c );
    }
}

