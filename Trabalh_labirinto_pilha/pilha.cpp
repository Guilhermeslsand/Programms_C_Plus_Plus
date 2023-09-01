***************
***Questao_1***
***************
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

***************
***Questao_2***
***************
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

class Posicao{
    public:
    int l;
    int c;
};

class PilhaPosicao{
    public:
    Posicao* v;
    int tam_max;
    int topo;
    int cont;

    PilhaPosicao (int tamanho){
        v = new Posicao[tamanho];
        tam_max = tamanho;
        topo = -1;
        cont = 0;
    }

    void empilhar (Posicao f){
        if(tam_max==cont){
            cout<<"Pilha cheia"<<endl;
        }
        else{
            v[cont] = f;
            topo++;
            cont++;
        }
    }

    Posicao desempilhar (){
        Posicao d;
        d = v[topo];
        topo--;
        cont--;
        return d;
    }

    int vazia (){
        if(cont == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
};

int main (){
    int l = 0;
    int j=0;
    char lab[41][42];
    char M;
    Posicao f;
    Posicao r;
    PilhaPosicao p (1000);
    FILE* arq;
    arq = fopen("labirinto05.txt", "rt");
    if(arq)
    {
     for(int i = 0; i<41; i++){
        for(int j=0; j<42; j++){
            fscanf(arq, "%c", &M);
            if(M == 'e'){
                f.l = i;
                f.c = j;
            }
            lab[i][j] = M;
        }
     }
        fclose(arq);
    }
    else
    {
      printf("Erro na abertura do arquivo\n");
    }

     p.empilhar (f);

     while(!p.vazia()){
        if(lab[f.l][f.c] == 's'){
            cout<<"Você chegou no final"<<endl;
            break;
        }
        else{
            lab[f.l][f.c] = '*';

                if(lab[f.l][f.c+1] != '#' && lab[f.l][f.c+1] != '*'){
                    f.c = f.c+1;
                    p.empilhar(f);
                }
                else if(lab[f.l+1][f.c] != '#' && lab[f.l+1][f.c] != '*'){
                    p.empilhar(f);
                    f.l = f.l+1;
                    p.empilhar(f);
                }
                else if(lab[f.l][f.c-1] != '#' && lab[f.l][f.c-1] != '*'){
                    p.empilhar(f);
                    f.c = f.c-1;
                    p.empilhar(f);
                }
                else if(lab[f.l-1][f.c] != '#' && lab[f.l-1][f.c] != '*'){
                    p.empilhar(f);
                    f.l = f.l-1;
                    p.empilhar(f);
                }
                else{
                    f = p.desempilhar();
                }
        }

     }

    arq = fopen("labirinto05.txt", "rt");
    if(arq)
    {
        for(int i = 0; i<41; i++){
            for(int j=0; j<42; j++){
                fscanf(arq, "%c", &M);
                lab[i][j] = M;
            }
        }
        fclose(arq);
    }

    while(!p.vazia()){
        f=p.desempilhar();
        lab[f.l][f.c] = '*';
    }

    for(int i = 0; i<41; i++){
        for(int j = 0; j<42; j++){
            cout<<" "<<lab[i][j];
        }
        cout<<endl;
    }
}
